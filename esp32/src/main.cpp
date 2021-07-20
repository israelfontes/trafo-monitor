#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <EmonLib.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <SSD1306.h>
#include "../lib/AES/AES.h"

// Config pinagem LoRa
#define SCK     5    // GPIO5  -- SX127x's SCK
#define MISO    19   // GPIO19 -- SX127x's MISO
#define MOSI    27   // GPIO27 -- SX127x's MOSI
#define SS      18   // GPIO18 -- SX127x's CS
#define RST     14   // GPIO14 -- SX127x's RESET
#define DI0     26   // GPIO26 -- SX127x's IRQ(Interrupt Request)

#define BAND    915125000  //Frequência de transmissão LoRa
#define PABOOST false

#define ADDRESS 10 //Endereço do device

#define ADC_TENSAO 25    // Porta analogica do sensor de tensao
#define ADC_CORRENTE 2   // Porta analogica do sensor de corrente
#define ADC_TEMP 13      // Porta analogica do sensor de temperatura

#define AMOSTRAGEM 10       
#define CALIBRAGEM 11.65

unsigned int INTERVALO_ENTRE_ENVIOS = 2; // Intervalo entre envios informações em segundos 

unsigned int MAX_TEMPERATURA; // Temperatura maxima para emitir alerta
unsigned int MAX_VOLT;        // Voltagem maxima para emitir alerta
unsigned int MIN_VOLT;        // Voltagem minima para emitir alerta
unsigned int MAX_AMPER;       // Corrente maxima para emitir alerta

unsigned long microSegundos;
unsigned int tempoDeEnvio;

double temperaturaAtual;
double tensaoAtual;
double correnteAtual;
double potenciaAtual;
double potenciaAnterior;
double energiaTotal;

EnergyMonitor emon;                  // Instancia do objeto EnergyMonitor responsavel pelo calculo de corrente
SSD1306 display(0x3c, 4, 15);        // Instancia do Display OLED 
OneWire oneWire(ADC_TEMP);           // Instancia comunicação OneWire do sensor de temperatura  
DallasTemperature sensors(&oneWire);  
DeviceAddress sensorTemp;              

void Display(){
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0 , 0 , "Tensão: "+ (String)tensaoAtual+ "Vac");  
  display.drawString(0, 15, "Corrrente: "+ (String)correnteAtual + "A");
  display.drawString(0, 30, "Temp: " + (String)temperaturaAtual + "ºC");
  display.drawString(0, 47, " " + (String)energiaTotal + "Kw/h");
  display.display();
}


void loop2(void*param);
bool isSending( void );
void initialConfig( void );

void setup() {
  pinMode(ADC_TEMP, INPUT);
  pinMode(ADC_TENSAO, INPUT);
  pinMode(ADC_CORRENTE, INPUT);
  
  Serial.begin(9600);

  // ===================LoRa config===================
  SPI.begin(SCK,MISO,MOSI,SS);
  LoRa.setPins(SS,RST,DI0);

  if(!LoRa.begin(BAND,PABOOST)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  //==================================================

  //===================Config OLED====================
  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);
  pinMode(16,OUTPUT);
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 in high、
  display.init();
  display.flipScreenVertically();  
  display.setFont(ArialMT_Plain_10);
  delay(1500);
  display.clear();
  //==================================================
  
  //===============Config DS18B20 temp================
  sensors.begin();
  if(sensors.getDeviceCount()){
    display.drawString(0, 0, "Sensor de temp encontrado");
    display.display();
  }

  if (!sensors.getAddress(sensorTemp, 0)){
    display.drawString(0,0, "Sensor de temp");
    display.drawString(0, 10, "não encontrado");
    display.display();
  }
  //==================================================
 
  //=============Config sensor corrente===============
  emon.current(ADC_CORRENTE, 60);
  //==================================================

  tempoDeEnvio = millis();
  microSegundos = micros();
  
  delay(2000);
  display.clear();
  display.drawString(0, 0, "Aguardando pacote");
  display.drawString(0, 10, " de configuração");
  display.display();
  initialConfig();

  //=====Cria tarefa que vai rodar com prioridade 1 no core 0======
  xTaskCreatePinnedToCore(loop2, "loop2", 10000, NULL, 1, NULL, 0);
  delay(100); 

}

#include "energia.h"
#include "fLora.h"

// Retorna
bool isSending( void ){
  if( (millis() - tempoDeEnvio)/1000 >= INTERVALO_ENTRE_ENVIOS){
    tempoDeEnvio = millis();
    return true;
  }
  return false;
}

void displayAlerta(String parametro, String tipo, String codigo, String valor, String unidade){
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(0,0,"Alerta! " + parametro);
  display.drawString(0,15,tipo);
  display.drawString(0,30,"Código: " + codigo);
  display.drawString(0,45,valor+unidade);
  display.display();
}

void loop2(void*param){
 
  delay(300);
  char codigoAlarme = '0';
  unsigned int tempINTERVALO = INTERVALO_ENTRE_ENVIOS;
  while(1){

    if( isSending() )senderLora(false, codigoAlarme);

    if( tensaoAtual > MAX_VOLT ){
      INTERVALO_ENTRE_ENVIOS = 2;
      codigoAlarme = '1';
      displayAlerta("Tensão", "alta.", "1", (String)tensaoAtual,"Vac");
    }
    else if( tensaoAtual < MIN_VOLT ){
      INTERVALO_ENTRE_ENVIOS = 2;
      codigoAlarme = '2';
      displayAlerta("Tensão", "baixa.", "2", (String)tensaoAtual,"Vac");
    }
    else if(temperaturaAtual > MAX_TEMPERATURA){
      INTERVALO_ENTRE_ENVIOS = 2;
      codigoAlarme = '3';
      displayAlerta("Temperatura", "alta.", "3", (String)temperaturaAtual,"Cº");
    }
    else if(correnteAtual > MAX_AMPER){
      INTERVALO_ENTRE_ENVIOS = 2;
      codigoAlarme = '4';
      displayAlerta("Corrente", "alta.", "4", (String)correnteAtual,"A");
    }else{
      if(codigoAlarme != '0'){
        codigoAlarme = '0';
        senderLora(false, codigoAlarme);
        INTERVALO_ENTRE_ENVIOS = tempINTERVALO;
      }
      Display();
    }
  }   
}

void loop() {

  getTemperatura();
  potenciaAtual = getPotencia();
  double tempo = getTime();        //Pega o tempo desde a ultima leitura e reinicia o temporizador

  energiaTotal = energiaTotal + calcularEnergia(potenciaAnterior, potenciaAtual, tempo)/3600000;//Retorna a energia consumida entre a ultima leitura e a atual e acumula na variavel global
  potenciaAnterior = potenciaAtual;//A potência atual se torna a anterior para o próximo calculo de potência

}