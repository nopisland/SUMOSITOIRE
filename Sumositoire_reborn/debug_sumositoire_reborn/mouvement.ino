#include "mouvement.h"

byte mouvement(int direction)
{
  Serial.print("mouvement(");
  Serial.print(direction);
  switch (direction)
  {
    case MARCHE_ARRIERE: // Marche-arrière.
      //Avant();
      analogWrite(moteur_gauche[0], 255);
      digitalWrite(moteur_gauche[1], HIGH);

      analogWrite(moteur_droite[0], 255);
      digitalWrite(moteur_droite[1], HIGH);
      break;

    case TOUT_DROIT:  // Tout droit.
      analogWrite(moteur_gauche[0], 255);
      digitalWrite(moteur_gauche[1], LOW);

      analogWrite(moteur_droite[0], 255);
      digitalWrite(moteur_droite[1], LOW);
      break;

    case  DROITE: // Droite.
      analogWrite(moteur_gauche[0], 255);
      digitalWrite(moteur_gauche[1], LOW);

      analogWrite(moteur_droite[0], 255);
      digitalWrite(moteur_droite[1], HIGH);
      break;

    case GAUCHE: // Gauche.
      analogWrite(moteur_gauche[0], 255);
      digitalWrite(moteur_gauche[1], HIGH);

      analogWrite(moteur_droite[0], 255);
      digitalWrite(moteur_droite[1], LOW);
      break;

    case STOP: // Stop
      analogWrite(moteur_gauche[0], 0);
      digitalWrite(moteur_gauche[1], LOW);

      analogWrite(moteur_droite[0], 0);
      digitalWrite(moteur_droite[1], LOW);
      break;
  }
}


byte aquisition()
{
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH, 10000);
  cm = lecture_echo / 58;
  if (cm < 1)
  {
    cm = 150;
  }
  if (cm <= sueil_ultrason)
  {
    return (1);
  }
  return (0);
}
