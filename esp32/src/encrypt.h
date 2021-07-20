byte out[16];

byte * encrypt(String plain){
  if(sizeof(plain) > 16){ // Verifica se o payload é maior que 16 bytes
     Serial.println("Payload é meior que 16 bytes");
      return nullptr;
  } 

  AES aes;
  byte key[16], inp[32];
  
  const char password[] = "1001256344israel"; // Chave
  
  Serial.print("Chave: ");
  for(byte i = 0; i < strlen(password); i++){ 
    key[i] = password[i];
    Serial.print(key[i],DEC);
  }

  for(byte i = strlen(password); i < 16; i++)
    key[i] = 0;

  Serial.println();
  for(byte i = 0; i < sizeof(plain); i++) 
    inp[i] = plain[i];

  for(byte i = sizeof(plain); i < 16; i++)
    inp[i] = 0;

  Serial.print("String: ");
  Serial.println(plain);

  if( aes.set_key(key, 16) ){
    Serial.println("Erro na atribuição da key");
    aes.clean();
    return nullptr;
  }

  Serial.print("INP: ");
  for(byte i = 0; i < 16; i++){
    Serial.print(inp[i]);
    Serial.print(" ");
  }
  
  Serial.println();

  if( aes.encrypt(inp, out) ){
    Serial.println("Erro na encriptação");
    aes.clean();
    return nullptr;
  }

  Serial.print("AES: ");
  String retorno = "";
  for (byte i = 0; i < 16; i++)
  {
    Serial.print(out[i]);
    retorno[i] = out[i];
    Serial.print(" ");
  }
  Serial.println();

  aes.clean();
  
  return out;
}