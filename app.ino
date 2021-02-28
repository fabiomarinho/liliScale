#include "HX711.h"
#include "beep.h"
#define DELTA -53597
#define DELTA_GRAMAS -212.5
#define ZERO -805713
#define TEMPO_ENTRE_LEITURAS 5000

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void setup() {
  Serial.begin(9600);
  pinMode(PORTA_BEEP,OUTPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  taraBalanca();
  
}
long tara = ZERO;
float count = 0;
long val = 0;

//Zero: Count 500.00. Val -805713
//212,5 g: Count 500.00. Val -859310
//Delta: -53597


void loop() {
  /*if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(abs(reading));
  }
  */
  
  if (scale.is_ready()) {
    delay(TEMPO_ENTRE_LEITURAS);
    //count= count+1;
    //Serial.print ("Count");
    //Serial.print (count);
    beepNumero(getPesoEmGramas());
    
    //long reading = scale.read();
    //Serial.println(getPesoEmGramas());
    //Serial.print ("Reading");
    //Serial.print (reading);
    //val = ((count-1)/count) * val + (1/count) * reading;
    //Serial.print ("Count ");
    //Serial.print (count);
    //Serial.print (". Val ");
    //Serial.println(val);
  }
  
  
}
void taraBalanca(){
    delay(6000);
    if (scale.is_ready()) {
      beepTara();
      tara = scale.read();
      //Serial.print (". Tara ");
      //Serial.println(tara);
    }else{
      //Serial.print ("Erro Tara *************************");
    }  
}
int getPesoEmGramas(){
  long peso = scale.read();
  peso = peso - tara;
  float gramas = peso * DELTA_GRAMAS / DELTA;
  return -round(gramas);
}
