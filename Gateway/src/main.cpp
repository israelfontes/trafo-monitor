#include <Arduino.h>

#include <SPI.h>
#include "../lib/LoRa/src/LoRa.h"
#include <Wire.h>  
#include "../lib/OLED/src/SSD1306.h" 
#include <WiFiServer.h>
#include <WiFi.h>

// Pin definetion of WIFI LoRa 32
// HelTec AutoMation 2017 support@heltec.cn 
#define SCK     5    // GPIO5  -- SX127x's SCK
#define MISO    19   // GPIO19 -- SX127x's MISO
#define MOSI    27   // GPIO27 -- SX127x's MOSI
#define SS      18   // GPIO18 -- SX127x's CS
#define RST     14   // GPIO14 -- SX127x's RESET
#define DI00    26   // GPIO26 -- SX127x's IRQ(Interrupt Request)

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6
#define PABOOST false

const char* ssid = "LULA_2018";
const char* pass = "170915020997130897";

WiFiServer server(5045);


SSD1306 display(0x3c, 4, 15);
String rssi = "RSSI --";
String packSize = "--";
String initialConfig = "B/500/200/40/100/10";

String packet = "";

void loraData(){
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0 , 15 , "Received "+ packSize + " bytes");
  display.drawStringMaxWidth(0 , 26 , 128, "packet");
  display.drawString(0, 0, rssi);  
  display.display();
}



void cbk(int packetSize) {
  String ppacket = "";
  packSize = String(packetSize,DEC);
  //Serial.print("Tamanho do pacote: ");
  //Serial.println(packetSize);
  for (int i = 0; i < packetSize; i++) { ppacket.concat((char)LoRa.read()); }  
  rssi = "RSSI " + String(LoRa.packetRssi(), DEC) ;
  
  if(packet[0] == 'C'){
      LoRa.beginPacket();
      for(byte i = 0; i < initialConfig.length(); i++){
          LoRa.write(initialConfig[i]);
      }
      LoRa.endPacket();
  }
  packet = ppacket;
  loraData();

}

WiFiClient client;

void setup() {
  pinMode(16,OUTPUT);
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 in high、
  display.init();
  display.flipScreenVertically();  
  display.setFont(ArialMT_Plain_10);
  delay(1500);
  display.clear();
  
  Serial.begin(9600);

  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    display.drawString(0,0,"Conectando ao Wi-FI");
    display.display();
  }

  display.clear();
  display.drawString(0,0,"Conectado. IP: ");
  display.drawString(0,10, WiFi.localIP().toString());
  display.display();
  delay(4000);

  server.begin();

  SPI.begin(SCK,MISO,MOSI,SS);
  LoRa.setPins(SS,RST,DI00);
  
  display.clear();
  if (!LoRa.begin(BAND,PABOOST)) {
    display.drawString(0, 0, "Iniciando LoRa!");
    display.display();
    while (1);
  }

  display.clear();
  display.drawString(0, 0, "LoRa iniciado!");
  display.display();
  delay(1000);
  
  LoRa.receive();
  display.clear();
  while(!client){
      display.drawString(0,0,"Aguardando conexao TCP");
      display.display();
      client = server.available();
  }

  display.clear();
  display.drawString(0,0,"Conectado TCP");
  display.display();
  delay(2000);  
}

void TCPsender(int packetSize){
    if(client){
        if(client.connected()){
            Serial.println("Cliente conectado");
            for(int i = 0; i < packetSize; i++){
                client.write(packet[i]);    
                Serial.print(packet[i]);
                Serial.print(" ");
            }
            Serial.println();    

            Serial.print("Pacote enviado: ");
            Serial.println(); 
        }
    }else{
        Serial.println("Cliente nao conectado");
    }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.println("Recebi Lora");
    cbk(packetSize);
    Serial.println("Passou CBK");
    TCPsender(packetSize);
    Serial.println("Passou Sender");  
  }
}
