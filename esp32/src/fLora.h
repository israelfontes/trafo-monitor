#ifndef SENDER_LORA_H
#define SENDER_LORA_H

byte out[16];

byte * encrypt(String plain){
  if(sizeof(plain) > 16){ // Verifica se o payload é maior que 16 bytes
     //Serial.println("Payload é meior que 16 bytes");
    return nullptr;
  } 

  AES aes;
  byte key[16], inp[32];
  
  const char password[] = "1234567890123456"; // Chave 128 bits
  
  //Serial.print("Chave: ");
  for(byte i = 0; i < strlen(password); i++){ 
    key[i] = password[i];
    //Serial.print(key[i],DEC);
  }

  for(byte i = strlen(password); i < 16; i++)
    key[i] = 0;

  //Serial.println();
  for(byte i = 0; i < sizeof(plain); i++) 
    inp[i] = plain[i];

  for(byte i = sizeof(plain); i < 16; i++)
    inp[i] = 0;

  //Serial.print("String: ");
  //Serial.println(plain);

  if( aes.set_key(key, 16) ){
    //Serial.println("Erro na atribuição da key");
    aes.clean();
    return nullptr;
  }

  /*Serial.print("INP: ");
  for(byte i = 0; i < 16; i++){
    Serial.print(inp[i]);
    Serial.print(" ");
  }*/
  
 // Serial.println();

  if( aes.encrypt(inp, out) ){
   // Serial.println("Erro na encriptação");
    aes.clean();
    return nullptr;
  }

 // Serial.print("AES: ");
  String retorno = "";
  for (byte i = 0; i < 16; i++)
  {
   // Serial.print(out[i]);
    retorno[i] = out[i];
    //Serial.print(" ");
  }
 // Serial.println();

  aes.clean();
  
  return out;
}

void initialConfig( void ){
  int parse = 0;
  LoRa.receive();

  while( !parse ){

    while( !parse ){
      parse = LoRa.parsePacket();

      if( isSending() && !parse ){
        LoRa.beginPacket();
        LoRa.write('C');
        LoRa.endPacket();
      }
    }

    char packet[parse];
  
    for(int i = 0; i < parse; i++){ 
      packet[i] = LoRa.read();
    }
    Serial.println();

    // Broadcast/MAX_VOLT/MIN_VOLT/MAX_TEMP/MAX_AMPER/INTERVALO_ENTRE_ENVIOS
    if(packet[0] == 'B'){
      int param[5];
      byte i_param = 0;

      for(int i = 2; i < parse; i++){
        String temp = "";

        while(packet[i] != '/' && !(i > (parse-1))){
          temp.concat(packet[i]);
          i++;
        }
        
        param[i_param] = temp.toInt();
        i_param++;  
      }
    
      MAX_VOLT = param[0];
      MIN_VOLT = param[1];
      MAX_TEMPERATURA = param[2];
      MAX_AMPER = param[3];
      INTERVALO_ENTRE_ENVIOS = param[4];

      parse = 1;

    }else parse = 0;
  }
}

bool senderLora(bool b_encrypt, char flagAlarme){
  
  char c_tensao = tensaoAtual;
  char c_temp = temperaturaAtual;

  String payload = "";
  payload.concat((String)tensaoAtual);
  payload.concat("/");
  payload.concat((String)temperaturaAtual);
  payload.concat("/");
  payload.concat((String)correnteAtual); 
  payload.concat("/");
  payload.concat((String)energiaTotal);
  payload.concat("/");
  payload.concat((String)flagAlarme);

  LoRa.beginPacket();
  //LoRa.write(ADDRESS);
  
  if(!b_encrypt){
    for(int i = 0; i < payload.length(); i++)  LoRa.write(payload[i]);
  }
  else{
    byte * c_encrypt = encrypt(payload);
    for(int i = 0; i < 16; i++) LoRa.write(c_encrypt[i]);
  }

  LoRa.endPacket();

  return 1;
}

#endif