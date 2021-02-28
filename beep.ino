

#define TEMPO_BEEP_NUMERO 250
#define TEMPO_BEEP_ZERO 500
#define TEMPO_ESPERA 1500
#define TEMPO_AVISO 40
#define RESOLUCAO_ERRO 1
void acionaBeep(bool circuito_acionado){
  digitalWrite(PORTA_BEEP,circuito_acionado ? HIGH:LOW);
}

void beepNumero(long numero){
    if (numero<=1) return;
    bool ja_bipou = false;
    beepInicio();
    for (long divisor=100000;divisor>0;divisor /= 10){
        long resultado = numero / divisor;
        if (resultado || ja_bipou){
            algarismoToBeep(resultado);
            delay(TEMPO_ESPERA);
            ja_bipou = true;
        }
        numero %= divisor;
    }    
    beepFim();

}

void algarismoToBeep(int algarismo){
  //Serial.println(algarismo);
  if (algarismo){
      for (int i=1;i<=algarismo;i++){
          digitalWrite(PORTA_BEEP,HIGH);
          delay(TEMPO_BEEP_NUMERO);
          digitalWrite(PORTA_BEEP,LOW);
          delay(TEMPO_BEEP_NUMERO);
      }
  }else{
      digitalWrite(PORTA_BEEP,HIGH);
      delay(TEMPO_BEEP_ZERO);
      digitalWrite(PORTA_BEEP,LOW);
  }
  
}
void beepInicio(){
    beepAviso();
    delay(TEMPO_ESPERA);
}

void beepFim(){
    for (int i=0;i<4;i++){
        digitalWrite(PORTA_BEEP, i % 2 == 0 ? HIGH:LOW);
        delay(TEMPO_AVISO);    
    }
}

void beepTara(){
    for (int i=0;i<24;i++){
        digitalWrite(PORTA_BEEP, i % 2 == 0 ? HIGH:LOW);
        delay(TEMPO_AVISO);    
    }
}

void beepAviso(){
    for (int i=0;i<6;i++){
        digitalWrite(PORTA_BEEP, i % 2 == 0 ? HIGH:LOW);
        delay(TEMPO_AVISO);    
    }
}