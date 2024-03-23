#ifndef ABONO_H_INCLUDED
#define ABONO_H_INCLUDED
#include "Fecha.h"
#include <string.h>
using namespace std;

class Abono
{
    private:
        Fecha *fechaAbono;
        float montoAbono;
    public:
    Abono(Fecha *fp, float mp)
{
        this->fechaAbono=fp;
        this->montoAbono=mp;
}


Fecha *getFechaAbono()
{
    return this->fechaAbono;
}

float getMontoAbono()
{
    return this->montoAbono;
}

};



#endif // Abono_H_INCLUDED
