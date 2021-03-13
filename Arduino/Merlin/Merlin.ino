#include <SoftwareSerial.h>  //Cambiamos RX pin 9 TX pin 10 del bluetooth
 SoftwareSerial BT(9,10);      //Para que no interfieran en la carga del sketch con el USB
 
int motor11 = 7; // 
int motor12 = 8; // 
int enable1 = 5; // 

int motor21 = 3; // 
int motor22 = 4; // 
int enable2 = 6; // 



int selecrc=10;
int selecau=11;


int estado;


void setup() {
    //Configuramos los pines de salida:
    pinMode(motor11, OUTPUT);
    pinMode(motor12, OUTPUT);
    pinMode(enable1, OUTPUT);
    pinMode(motor21, OUTPUT);
    pinMode(motor22, OUTPUT);
    pinMode(enable2, OUTPUT);


    // Velocidad de los motores al iniciar
        digitalWrite(enable1, HIGH);//derecha
        digitalWrite(enable2, HIGH);//izquiera


  
    BT.begin(9600);      //Comunicacion serial para el bluetooth
    Serial.begin(9600);  //Comunicacion serial para el monitor serial

}

void loop() {


//        digitalWrite(motor11, LOW); 
//        digitalWrite(motor12, HIGH);
//        digitalWrite(motor21, LOW);
//        digitalWrite(motor22, HIGH);

    if(BT.available() > 0){     
      estado = BT.read();   
      Serial.println(estado);
    }   


   // AVANCE:
    if (estado == 'F') {
        digitalWrite(motor11, HIGH);
        digitalWrite(motor12, LOW); 
        digitalWrite(motor21, HIGH);
        digitalWrite(motor22, LOW);
    }
    
    // IZQUIERDA
    else if (estado == 'L') {
        digitalWrite(motor11, LOW); 
        digitalWrite(motor12, HIGH); 
        digitalWrite(motor21, HIGH);
        digitalWrite(motor22, LOW);
    }
    // PARADO
    else if (estado == 'S' ) {
        digitalWrite(motor11, LOW); 
        digitalWrite(motor12, LOW); 
        digitalWrite(motor21, LOW);
        digitalWrite(motor22, LOW);
    }
    // DERECHA
    else if (estado == 'R') {
        digitalWrite(motor11, HIGH); 
        digitalWrite(motor12, LOW); 
        digitalWrite(motor21, LOW);
        digitalWrite(motor22, HIGH);
    }
    // REVERSA
    else if (estado == 'B') {
        digitalWrite(motor11, LOW); 
        digitalWrite(motor12, HIGH);
        digitalWrite(motor21, LOW);
        digitalWrite(motor22, HIGH);
    }


}
