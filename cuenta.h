#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "Cliente.h"
#include "abono.h"
#define CONS 5
#include <stdlib.h>
#include <iostream>
using namespace std;

class Cuenta
{
    private:
        int numeroCuenta;
        Cliente *cliente;

        Abono *lstAbonos[CONS];
        float saldoPendiente;
        int contadorAbonos;
    public:
        Cuenta()
{
            this->numeroCuenta = 0;
            this->saldoPendiente = 0;
            this->contadorAbonos = 0;
}

        Cuenta(int np, Cliente *cli, Fecha *fa, float ma)
{
            this->numeroCuenta = np;
            this->cliente = cli;
            this->saldoPendiente = ma;
            this->contadorAbonos = 0;
}

int getNumeroCuenta()
{
    return this->numeroCuenta;
}


void setNumeroCuenta(int np)
{
    this->numeroCuenta = np;
}

Cliente *getCliente()
{
    return this->cliente;
}

void setCliente(Cliente *cli)
{
    this->cliente = cli;
}



bool hacerAbono(Abono *pg){
    bool retorno = false;
        if (this->contadorAbonos < CONS){
                    this->lstAbonos[this->contadorAbonos] = pg;
                    this->contadorAbonos++;
                    this->saldoPendiente += pg->getMontoAbono();
                retorno = true;
    }
    return retorno;
}


Abono **getLstAbonos()
{
    return this->lstAbonos;
}

float getSaldoPendiente()
{
    return this->saldoPendiente;
}

int getContadorAbonos()
{
    return this->contadorAbonos;
}

void setSaldoPendiente(float ma)
{
    this->saldoPendiente = ma;
}

};


#endif // Cuenta_H_INCLUDED
