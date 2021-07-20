#ifndef _ENERGIA_H_
#define _ENERGIA_H_

double getCorrente(void){
  correnteAtual = 10;
  return correnteAtual;
}

double getTemperatura(void){
  sensors.requestTemperatures();
  temperaturaAtual = 34;//sensors.getTempC(sensor1);
  return temperaturaAtual;
}

double getTensao(void){
  tensaoAtual = analogRead(ADC_TENSAO);  
  return tensaoAtual;
}

double getPotencia(void){
  potenciaAtual = getTensao() * getCorrente(); 
  return potenciaAtual;
}

double calcularEnergia(double potenciaInicial, double potenciaFinal, double tempo){
  return tempo * (potenciaFinal + potenciaFinal) / 2;
}

double getTime(void){ //retorna o tempo que se passou desde a ultima chamada desta função, e inicia o contador novamente.(Obs: A cada 70 horas, a função micros() passa a retornar zero, o que deve ser tratado)
  unsigned long microsAtual =  micros();
  double  tempo = microsAtual - microSegundos;
  microSegundos = microsAtual;
  if(tempo < 0.0){
    tempo =  0.0;
  }
  tempo = tempo / 1000000.0;//Converte tempo em ms para s  
  return tempo;
}

#endif