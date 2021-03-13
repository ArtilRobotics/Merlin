void setupMotores () {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

//motores velocidad izquierda
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


//motores velocidad derecha
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
