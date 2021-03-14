

void Recive() {
  // para labview
  if (Serial.available())
  {
    str = Serial.readStringUntil('\n');

    for (int i = 0; i < dataLength ; i++)
    {
      int index = str.indexOf(separator); //propia de la libreria serial de arduino
      data[i] = str.substring(0, index); //vector para guardar el mensaje por separado
      str = str.substring(index + 1); //guardar toda la cadena
    }
  }
}
