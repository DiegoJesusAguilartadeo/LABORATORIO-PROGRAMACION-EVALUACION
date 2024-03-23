#include <iostream>
#include <stdlib.h>
#include "Fecha.h"
#include "abono.h"
#include "Cliente.h"
#include "cuenta.h"
#define CONSTA 10
using namespace std;

int menu()
{
    int op;


        cout<< "AT23I04002 - GUIA 3 EVALUACION LAB PROGII Diego Jesus Aguilar Tadeo"<<endl;
        cout<< "Menu de Opciones"<<endl;
        cout<< "1. Agregar clientes."<<endl;
        cout<< "2. Agregar Cuenta."<<endl;
        cout<< "3. Hacer Abonos."<<endl;
        cout<< "4. Mostrar lista de clientes."<<endl;
        cout<< "5. Mostrar lista de Cuentas."<<endl;
        cout<< "6. Mostrar detalles de Cuentas."<<endl;
        cout<< "7. Salir."<<endl;
        cout<< "Digite una opcion: "<<endl;
        cin>>op;

    return op;
}
    Cliente *agregarCliente()
{
int id;
            string n,a;
            Cliente *cli;
            cout<< "Ingrese el id del cliente: ";
            cin>>id;
            cout<< "Ingrese el nombre del cliente: ";
            cin>>n;
            cout<< "Ingrese el apellido del cliente: ";
            cin>>a;
            cli=new Cliente(id, n, a);
    return cli;
}
Cliente *BuscarCliente(Cliente *lst[],int cont,int db)
{
    bool Encontrado = false;
    int contador=0;
    Cliente *cli = NULL;
    while(contador < cont && !Encontrado){
        if (lst[contador]->getIdCliente() == db){
            Encontrado = true;
            cli=lst[contador];
                }
        else{

    contador++;

    }
}
    return cli;
}


Cuenta *agregarCuenta(Cliente *cli){
int np;
int d, m, a;
Fecha *fa;
float ma=0;

Cuenta *ptmo;
        cout <<  "digite el numero de la cuenta : ";
        cin >>np;
        ptmo = new Cuenta(np, cli, fa, ma);
    return ptmo;
}

void registrarAbono(Cuenta *ptmo)
{
int d,m,a;
Fecha *fp;
float mp;
Abono *pg;
        cout << "Digite la fecha del Abono (DD/MM/AA) : ";
        cin >> d;
        cin >> m;
        cin >> a;
        cout << "Digite el monto abonar a la cuenta : ";
        cin >> mp;
        fp = new Fecha(d,m,a);
        pg = new Abono(fp, mp);
        ptmo->hacerAbono(pg);
}


void verDetalles(Cuenta *ptmo)
{
        cout << "Numero de Cuenta : " << ptmo->getNumeroCuenta()<<endl;
        cout << "Cliente : " << ptmo->getCliente()->getNombre()<< "" << ptmo->getCliente()->getApellido()<<endl;

        cout << "Saldo : " << ptmo->getSaldoPendiente() << endl;
    if (ptmo->getContadorAbonos() == 0)
        {
            cout << "No existen Abonos en el registro\n";
        }
    else
        {
        Abono **lista = ptmo->getLstAbonos();
            cout << "no\tFECHA\tMONTO\n";
                for (int i=0;i<ptmo->getContadorAbonos();i++)
                    {
                        cout << (i+1) << "\t";
                        lista[i]->getFechaAbono()->mostrarFecha();
                        cout << "\t" << lista[i]->getMontoAbono() << endl;
        }
    }
}
Cuenta *BuscarCuenta(Cuenta *lst[],int cont,int db){
        bool encontrado = false;
        int contador=0;
        Cuenta *ptmo = NULL;
        while(contador < cont && !encontrado){
            if(lst[contador]->getNumeroCuenta()==db){
                    encontrado = true;
                    ptmo=lst[contador];
                    }
                else{
            contador++;
        }
    }
    return ptmo;
}



int main(){
        Cliente *lstCliente[CONSTA];
        Cuenta *lstCuenta[CONSTA];
        Cliente *cli=NULL;
        Cuenta *ptmo = NULL;
        int contCli=0, contPtmo=0, idCli, idPtmo;
        int opc;
    do
    {
    system("cls");
    opc=menu();
    switch(opc)
{
    case 1: /// ag clientes esta terminado
        if(contCli < CONSTA)
        {
                lstCliente[contCli]=agregarCliente();
                contCli++;
                cout << "el cliente se agrego correctamente" <<endl;
            }
                else
                {
                    cout<< "la lista de clientes esta llena."<<endl;
                }
break;

    case 2:///ag Cuentas
        if (contPtmo < CONSTA)
            {
                cout << "digite el codigo del cliente : ";
                cin >> idCli;
                    cli = BuscarCliente(lstCliente, contCli, idCli);
                        if (cli)
                            {
                                lstCuenta[contPtmo] = agregarCuenta(cli);
                                contPtmo++;
                                    cout << "la Cuenta se registro con exito\n";
                                    }
                                        else
                                        {
                                            cout<< "el cliente no existe,  no se puede agregar el Cuenta.";
                                                }
}
break;

        case 3: ///hacer Abonos
            cout << "digite el numero de Cuenta: ";
            cin >> idPtmo;
                ptmo = BuscarCuenta(lstCuenta, contPtmo, idPtmo);
                    if (ptmo){
                        registrarAbono(ptmo);
                            cout << "el Abono se registro con exito\n";
                                }
                                    else{
                                        cout << "el Cuenta no existe, no se puede registrar el Abono";
                                        }
break;

        case 4: /// mostar lista de clientes
            if(contCli == 0)
            {
            cout<< "la lista esta vacia\n";
            }
            else{
                    cout << "ID\tNOMBRE\tAPELLIDO\n";
                        for (int i=0;i<contCli;i++){
                            cout << lstCliente[i]->getIdCliente() << "\t";
                            cout << lstCliente[i]->getNombre() << "\t";
                            cout << lstCliente[i]->getApellido() << "\t";
                }
            }
break;


        case 5: /// mostrar lista de Cuentas
            if(contPtmo == 0)
            {
                cout << "la lista esta vacia\n";
            }
            else
            {
                cout << "NO\tCLIENTE\tFECHA\tSALDO\n";
                    for (int i=0;i<contPtmo;i++){
                            cout << lstCuenta[i]->getNumeroCuenta() << "\t";
                            cout << lstCuenta[i]->getCliente()->getNombre() << " " <<lstCuenta[i]->getCliente()->getApellido()<< "\t";


                            cout << lstCuenta[i]->getSaldoPendiente() << endl;
                        }
                    }
break;

        case 6:  /// mostrar detalle del Cuenta
            cout << "digite el codigo del Cuenta: ";
            cin >> idPtmo;
            ptmo = BuscarCuenta(lstCuenta, contPtmo, idPtmo);
                if(ptmo)
                {
                    verDetalles(ptmo);
                }
                    else
                        {
                            cout << "el prestano no existe, no se pueden visualizar los detalles";
                        }
break;

        case 7: ///salir del programa
            cout << "usted saliendo del programa..." << endl;
break;
default:
            cout<< "opcion invalida."<<endl;
break;
    }
    system("pause");
    }

    while(opc!=7);
return 0;
}
