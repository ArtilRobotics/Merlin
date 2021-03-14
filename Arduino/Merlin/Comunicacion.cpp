#include "Comunicacion.h"
#include "Arduino.h"

Comunicacion::Comunicacion(char *str,char separator,int dataLength)
{
    _str=str;
    _separator=separator;
    _dataLength=dataLength;
    
}
float *Comunicacion::lectura()
{
   static float data[4];
    // para labview
  if (Serial.available())
  {
    String str = Serial.readStringUntil('\n');
    for (int i = 0; i < _dataLength ; i++)
    {
      int index = str.indexOf(_separator); //propia de la libreria serial de arduino
      data[i] = str.substring(0, index).toFloat(); //vector para guardar el mensaje por separado
      str = str.substring(index + 1); //guardar toda la cadena
    }
    return data;
  }
  
}
