#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string>
using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;

    public:
    Fecha()
{
        this->dia = 0;
        this->mes = 0;
        this->anio = 0;
}
    Fecha(int d, int m, int a)
{
        this->dia = d;
        this->mes = m;
        this->anio = a;
}
void mostrarFecha()
{
    cout << this->dia << "/" << this->mes << "/" << this->anio;
}
};


#endif // FECHA_H_INCLUDED
