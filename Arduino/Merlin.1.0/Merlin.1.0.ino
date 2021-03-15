// importar las librerias necesarias
/*#include "Arduino.h"*/
/*#include "Comunicacion.h"*/

// defininicion de las constantes de comunicacion
// int dimension = 3;// dimension del dato a recibir
// float* dato; // vector donde se va a almacenar los datos por serial
// Comunicacion fer("",'/',dimension); // crear el objeto pen cargado de la comunicacion

// variables para la comunicacion usando funcion
String str = ""; 
const char separator = '/';
const int dataLength = 3;
float dato[dataLength];
// Definicion de la bandera de estados del sistema
int estado = 0;
void Recive() {
  // para labview
  if (Serial.available())
  {
    str = Serial.readStringUntil('\n');
    Serial.println(str);
    for (int i = 0; i < dataLength ; i++)
    {
      int index = str.indexOf(separator); //propia de la libreria serial de arduino
      dato[i] = str.substring(0, index).toFloat(); //vector para guardar el mensaje por separado
      str = str.substring(index + 1); //guardar toda la cadena
    }
  }
}
void delante(int tiempo)
{
  for (int k=0;k<tiempo;k++)
  { 
    // dato=fer.lectura();
    Recive();
    if (dato[0]==0)
    {
      break;
    }
    // Colocar aqui la funcion respectiva del movimiento
    Serial.print("Ejecutando delante");
    Serial.print(" ,");
    Serial.println(k);
  }
}
void atras(int tiempo)
{
  for (int k=0;k<tiempo;k++)
  { 
    // dato=fer.lectura();
    Recive();
    if (dato[0]==0)
    {
      break;
    }
    // Colocar aqui la funcion respectiva del movimiento
    Serial.print("Ejecutando atras");
    Serial.print(" ,");
    Serial.println(k);
  }
}
void derecha(int tiempo)
{
  for (int k=0;k<tiempo;k++)
  { 
    // dato=fer.lectura();
    Recive();
    if (dato[0]==0)
    {
      break;
    }
    // Colocar aqui la funcion respectiva del movimiento
    Serial.print("Ejecutando derecha");
    Serial.print(" ,");
    Serial.println(k);
  }
}
void izquierda(int tiempo)
{
  for (int k=0;k<tiempo;k++)
  { 
    // dato=fer.lectura();
    Recive();
    if (dato[0]==0)
    {
      break;
    }
    // Colocar aqui la funcion respectiva del movimiento
    Serial.print("Ejecutando izquierda");
    Serial.print(" ,");
    Serial.println(k);
  }
}
void movimientos(int i, int tiempo)
{
  switch (i)
  {
    case 0:// quizas sea movimiento hacia delante
      delante(tiempo);
      break;

    case 1: // quizas sea girar hacia la derecha
      atras(tiempo);
      break;

    case 2: // quizas sea girar hacia la izquierda
      derecha(tiempo);
      break;
      
    case 3: // quizas sea movimiento hacia delante 
      izquierda(tiempo);
      break;
    
  }
}
void setup() {
  // put your setup code here, to run once:
  // dato = fer.vacio(); // inicializacion del vector a llenar con ceros
  pinMode(13, 1); // pin a utilizar para ver el comportamiento del sistema
  Serial.begin(115200); // Inicializar el puerto serial
}
void loop() {
  // lectura de los datos del serial y almacenados en dato
  // dato=fer.lectura();
  Recive();
  // Generacion del switch case para elegir entre manual, detener y bloques
  switch ((int)dato[0])
  {
    case 0:
      // El sistema se detiene completamente
      Serial.println("Detener sistema");
      break;
    case 1:
      Serial.println("Sistema bloques");
      for (int i=1;i<dataLength;i++)
      {
        // dato=fer.lectura();
        Recive();
        // Aqui se pone la funcione de movimientos en la cual dependiendo de cual sea selecciona que realiza el carrrito
        if(dato[0]==0)
        {
          break;
        }
        movimientos((int)dato[i],1000);
      }
      dato[0]=0;
      break;
    case 2:
      // colocar movimientos pero en cada instante
      Serial.println("Sistema teleoperado");
      break;
  }
}
