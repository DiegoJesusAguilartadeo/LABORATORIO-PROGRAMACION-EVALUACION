#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
using namespace std;

class Cliente
{
    private:
        int idCliente;//atributos privados
        string nombre;
        string apellido;

    public:
    Cliente(int id, string n, string a) //constructor con parametros
{
        this->idCliente = id;
        this->nombre = n;
        this->apellido = a;
}

int getIdCliente()
{
    return this->idCliente;
}

string getNombre()
{
    return this->nombre;
}
string getApellido()
{
    return this->apellido;
}
};



#endif // CLIENTE_H_INCLUDED
