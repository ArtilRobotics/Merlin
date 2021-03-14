#ifndef Comunicacion_h
#define Comunicacion_h

class Comunicacion
{
    public:
        Comunicacion(char *str, char separator, int dataLength);
        float *lectura();

    private:
        char *_str;
        char _separator;
        int _dataLength;
        
};

#endif
