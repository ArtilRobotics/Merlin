#include <Arduino.h>

//Definimos los pines

//motor izquierdo
#define M2A 7
#define M2B 8
#define pwm2 5
//motor derecho
#define M1A 3
#define M1B 4
#define pwm1 6

void setupMotores () {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

//motor velocidad izquierda
void velizq(int value)
{
  if (value >= 0)
  {
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
  }
  else
  {
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    value *= -1;
  }
  analogWrite(pwm1, value);
}

//motor velocidad derecha
void velder(int value)
{
  if (value >= 0)
  {
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
  }
  else
  {
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
    value *= -1;
  }
  analogWrite(pwm2, value);
}

//velocidad motores
void velmotor(int izq, int der)
{
  velizq(izq);
  velder(der);
}

//funcion freno
void freno(boolean izq, boolean der)
{
  if (izq)
  {
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, HIGH);
  }
  if (der)
  {
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, HIGH);
  }
}
