int modo = 0;
int dir = 1;  //1 derecha -1 izquierda
int vel = 4; 
int rango = 4;
bool homing=false; 

void UduinoSetUP()
{
  //Serial.begin(9600); //1382400 115200 Abrimos la comunicación serie con el PC y establecemos velocidad
  uduino.addCommand("az", Altura);
  uduino.addCommand("ax", Ancho);
  uduino.addCommand("ay", Largo);
  uduino.addCommand("l", Gp);
  uduino.addCommand("m", SelecionaModoNew);
}

void Gp()
{
  delay(10);
  Serial.print("Gp");

}

bool Power = 1;
void EncenderMaquina() {
  Power = !Power;
  //digitalWrite(verde, Power);
}

void EnableMotors() {
  //v1 = !v1;
  //Write_to_HERO();
}

void SelecionaModoNew()
{
  int numberOfParameters = uduino.getNumberOfParameters();
  if (numberOfParameters == 4) {
    int val1 = uduino.charToInt(uduino.getParameter(0));
    int val2 = uduino.charToInt(uduino.getParameter(1));
    int val3 = uduino.charToInt(uduino.getParameter(2));
    int val4 = uduino.charToInt(uduino.getParameter(3));
    modo = val1;
    dir = val2;
    vel = val3;
    rango = val4;
    delay(10);
  }
  if (vel == 4)
    vel = 1000000;
  if (vel == 3)
    vel = 10000;
  if (vel == 2)
    vel = 1000;
  if (vel == 1)
    vel = 10;
  //feedrate(vel);
  //ControladoR = !ControladoR;
  delay(10);
}

void Altura()
{
  int numberOfParameters = uduino.getNumberOfParameters();
  if (numberOfParameters == 1) {
    int val1 = uduino.charToInt(uduino.getParameter(0));
    //line(px, py, (mode_abs ? val1 : 0) + (mode_abs ? 0 : val1), pe);
    //Write_to_HERO();
    delay(10);
  }
}

void Ancho()
{
  int numberOfParameters = uduino.getNumberOfParameters();
  if (numberOfParameters == 1) {
    int val1 = uduino.charToInt(uduino.getParameter(0));
    //line((mode_abs ? val1 : 0) + (mode_abs ? 0 : val1), py, pz, pe);
    //Write_to_HERO();
    delay(10);
  }
}

void Largo()
{
  int numberOfParameters = uduino.getNumberOfParameters();
  if (numberOfParameters == 1) {
    int val1 = uduino.charToInt(uduino.getParameter(0));
    //line(px, (mode_abs ? val1 : 0) + (mode_abs ? 0 : val1), pz, pe);
    //Write_to_HERO();
    delay(10);
  }
}
