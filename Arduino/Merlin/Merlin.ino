#include <SoftwareSerial.h>  //Cambiamos RX pin 9 TX pin 10 del bluetooth
 SoftwareSerial BT(9,10);      //Para que no interfieran en la carga del sketch con el USB

//motor izquierdo
int M2A=7;
int M2B=8;
int pwm2=5;
//motor derecho
int M1A=3;
int M1B=4;
int pwm1=6;

int selecrc=10;
int selecau=11;

int estado;

void setup() {
   BT.begin(9600);      //Comunicacion serial para el bluetooth
   Serial.begin(9600);  //Comunicacion serial para el monitor serial
    //Configuramos los pines de salida:
   setupMotores();
    // Velocidad de los motores al iniciar
   velmotor(0,0);
}

void loop() {
      //Bluetooth
      //if(BT.available() > 0){     
      //estado = BT.read();
      //Serial
      if(Serial.available() > 0){     
      estado = Serial.read();   
      Serial.println(estado);
    }   
   // AVANCE:
    if (estado == 'F') {
        velmotor(100,100);
        Serial.println("Avance");
    }  
    // IZQUIERDA
    else if (estado == 'L') {
        velmotor(-100,100);
        Serial.println("Izq");
    }
    // PARADO
    else if (estado == 'S' ) {
        velmotor(0,0);
        freno(true,true);
        Serial.println("Parar");
    }
    // DERECHA
    else if (estado == 'R') {
        velmotor(100,-100);
        Serial.println("Der");
    }
    // REVERSA
    else if (estado == 'B') {
        velmotor(-100,-100);
        Serial.println("Reversa");
    }
}
