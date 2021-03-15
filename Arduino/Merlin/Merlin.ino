//definicoin de las librerias del sistema
#include <SoftwareSerial.h>  //Cambiamos RX pin 9 TX pin 10 del bluetooth
SoftwareSerial BT(9, 10);     //Para que no interfieran en la carga del sketch con el USB
// incluir la libreria de la comunicacion
#include "Comunicacion.h"
#include "Motores.h"
int dimension=4;
Comunicacion fer("",'/',dimension);
float* dato;

//definicon de que acccion se debe realizar
int estado;
void setup() {
  //BT.begin(9600);      //Comunicacion serial para el bluetooth
  Serial.begin(115200);  //Comunicacion serial para el monitor serial

  //Configuramos los pines de salida:
  setupMotores();

  // Velocidad de los motores al iniciar
  velmotor(0, 0);
  
}

void loop() {
 
dato=fer.lectura();

  for(int i=0;i<dimension;i++)
  {
      Serial.print(i);
      Serial.print(",");
      Serial.println(dato[i]);
  }
 
  // AVANCE:
  if (estado == 'F') {
    velmotor(100, 100);
    Serial.println("Avance");
  }

  // IZQUIERDA
  else if (estado == 'L') {
    velmotor(-100, 100);
    Serial.println("Izq");
  }

  // PARADO
  else if (estado == 'S' ) {
    velmotor(0, 0);
    freno(true, true);
    Serial.println("Parar");
  }

  // DERECHA
  else if (estado == 'R') {
    velmotor(100, -100);
    Serial.println("Der");
  }
  
  // REVERSA
  else if (estado == 'B') {
    velmotor(-100, -100);
    Serial.println("Reversa");
  }
}
