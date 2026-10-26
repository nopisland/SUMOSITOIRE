/* -------------------------------------------------------------
       Auteur : Jérémy
      DUT : GEII.
      Date : 26/10/2026
  --------------------------------------------------------------*/
#include "Sumositoire_Constantes.h"
#include "data_debug.h"
#include "mouvement.h"
#define IR_SMALLD_NECx
#include <IRsmallDecoder.h>

IRsmallDecoder irDecoder(2);
irSmallD_t irData;

void setup() {
  Serial.begin(115200);
  //LED Setup
  pinMode(led_b, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  //Ligne Setup
  pinMode(input_ligne_ar, INPUT);
  pinMode(input_ligne_av_G, INPUT);
  pinMode(input_ligne_av_D, INPUT);

  //US Setup
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);

  //sharp
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);

  //Motor Setup
  int i;
  for (i = 0; i < 2; i++) {
    pinMode(moteur_gauche[i], OUTPUT);           // moteur gauche.
    pinMode(moteur_droite[i], OUTPUT);           // moteur droit.

  }
  digitalWrite(led_g, HIGH);

  //plot debug capteurs

  while (digitalRead(button) == HIGH) {
  

    for (int i = 0; i < 3; i++) {
      sharp[i] = analogRead(sharp_pin[i]);
      Serial.print(sharp_name[i]);
      Serial.print(" ");
      Serial.print(sharp[i]);
      Serial.print("  ");
    }

    Serial.print("Ultrason ");
    Serial.println(aquisition());
    delay(200);
  }
  for(int i = 0; i<2; i ++){
  digitalWrite(led_b,HIGH); 
  delay(250); 
  digitalWrite(led_b,LOW); 
  delay(250); 
  }
  while(digitalRead(button) == HIGH){
    
  
  
  
   for (int i = 0; i < 3; i++) {
      CNY[i] = analogRead(CNY_pin[i]);
      Serial.print(CNY_name[i]);
      Serial.print(" ");
      Serial.print(CNY[i]);
      Serial.print("  ");
    }
    Serial.println(""); 
    
    delay(200);

  }

 

}


void loop() {

  // put your main code here, to run repeatedly:



  while (irDecoder.dataAvailable(irData) == false);

  Serial.println(irData.cmd);
  switch (irData.cmd) {
    case 5: //forward
      mouvement(TOUT_DROIT);
      delay(100);
      mouvement(STOP);
      break;
    case 8: //left
      mouvement(GAUCHE);
      delay(100);
      mouvement(STOP);
      break;
    case 13: //down
      mouvement(MARCHE_ARRIERE);
      delay(100);
      mouvement(STOP);
      break;
    case 10: //right
      mouvement(DROITE);
      delay(100);
      mouvement(STOP);
      break;


  }
  delay(200);
}
