// variables serial computadora
char *strtok(char *str1,const char *str2);
char *resultado=NULL;
char str[100];
String cadena;
char c;
float variable_1=0;
float variable_2=0;
float arreglo_1=0;
float arreglo_2=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void serialEvent() {


if(Serial.available()>0)
  {
    c=Serial.read();
    cadena+=c;
    if(c=='\n')
    {
      cadena.toCharArray(str,101);
      char delimitadores[]=",";
      char *resultado=NULL;
      resultado=strtok(str,delimitadores);
      
      while(resultado!=NULL)
      {        
         arreglo_2=arreglo_1;
         arreglo_1=atof(resultado);
         resultado=strtok(NULL,delimitadores); 
       }
      
       variable_1=arreglo_2;
       variable_2=arreglo_1;
       Serial.println(variable_1);
       Serial.println(variable_2);
       cadena="";
      } 
     
}
}
