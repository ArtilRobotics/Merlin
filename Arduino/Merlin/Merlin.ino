#include <SoftwareSerial.h>
SoftwareSerial BT(9,10);
Uduino uduino(BT,"Merlin");

#define Led1 11
#define Led2 12

int estado;
String str = ""; //Valores de labview
const char separator = '/'; //simbolo para separar
const int dataLength = 18; //datos que estan llegando
String data[dataLength]; //almacenando los datos

void setup() {
  BT.begin(9600);      //Comunicacion serial para el bluetooth
  Serial.begin(9600); 
  UduinoSetUP();
  //BT.begin(115200);  //Comunicacion serial para el monitor serial
  //Configuramos los pines de salida:
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  setupMotores();
  // Velocidad de los motores al iniciar
  velmotor(0, 0);
}

void loop() {
  BT.println(0);
  uduino.update();
  uduino.println("uduino");
  delay(100);
  if (uduino.isConnected())
  {
      uduino.println("conectadoooooo");
      digitalWrite(Led1, HIGH);
      delay(500);
  }
      digitalWrite(Led2, HIGH);
      delay(500);
      digitalWrite(Led2, LOW);
      delay(500);
  //  if (BT.available() > 0) {
  //    estado = BT.read();
  //
  //    //BT.println(estado);
  //  }
//  estado=data[0].toInt();
//  
//  // ENCENDIDO
//  if (estado == 1) {
//    digitalWrite(Led1, HIGH);
//    delay(500);
//  }
//  // APAGADO
//  if (estado == 0) {
//    digitalWrite(Led1, LOW);
//    delay(500);
//  }
//  // AVANCE:
//  if (estado == 'F') {
//    velmotor(100, 100);
//    BT.println("Avance");
//  }
//  // IZQUIERDA
//  else if (estado == 'L') {
//    velmotor(-100, 100);
//    BT.println("Izq");
//  }
//  // PARADO
//  else if (estado == 'S' ) {
//    velmotor(0, 0);
//    freno(true, true);
//    BT.println("Parar");
//  }
//  // DERECHA
//  else if (estado == 'R') {
//    velmotor(100, -100);
//    BT.println("Der");
//  }
//  // REVERSA
//  else if (estado == 'B') {
//    velmotor(-100, -100);
//    BT.println("Reversa");
//  }
}
