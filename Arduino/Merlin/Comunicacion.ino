String str = ""; //Valores de labview
const char separator = '/'; //simbolo para separar
const int dataLength = 18; //datos que estan llegando
float data[dataLength]; //almacenando los datos

void Recive() {
  // para labview
  if (Serial.available())
  {
    str = Serial.readStringUntil('\n');
    Serial.println(str);
    for (int i = 0; i < dataLength ; i++)
    {
      int index = str.indexOf(separator); //propia de la libreria serial de arduino
      data[i] = str.substring(0, index).toFloat(); //vector para guardar el mensaje por separado
      str = str.substring(index + 1); //guardar toda la cadena
    }
  }
}
