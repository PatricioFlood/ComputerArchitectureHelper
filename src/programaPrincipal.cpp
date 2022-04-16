#include <iostream>
#include <string.h>
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/files.hpp"   
#include "mistads/Arquitectura.hpp"
using namespace std;

int main()
{
  int volver = 1;
  cout<<"-------------------------- Bienvenido --------------------------"<<endl<<endl;
  while( volver==1 )
  {

     cout<<"Seleccione una opcion:"<<endl;
     cout<<"1- Pasaje de Decimal a Binario."<<endl;
     cout<<"2- Pasaje de Enteros de Base \"n\" a Base \"m\"."<<endl;
     cout<<"3- Pasaje de Decimal a IEEE 754 precision simple."<<endl;
     cout<<"4- Sumas y Restas en BCD"<<endl;
     int opcion;
     cin>>opcion;
     while( opcion<1||opcion>4 )
     {
        cout<<"Opcion incorrecta, por favor ingrese de nuevo:"<<endl;
        cin>>opcion;
     }
     if( opcion==1 )
     {
        cout<<"Ingrese numero a convertir a Binario"<<endl;
        double num;
        cin>>num;
        Coll<int> cPEntera = collCreate<int>();
        Coll<int> cPMantisa = collCreate<int>();
        bool signo = convertirABinario(num,cPEntera,cPMantisa);
        cout<<endl;
        cout<<"Resultado: ";
        mostrarResultadoBinario(cPEntera,cPMantisa,signo);
        cout<<endl;
     }
     if( opcion==2 )
     {
        cout<<"Ingrese numero a convertir"<<endl;
        string num;
        cin>>num;
        cout<<"Ingrese la Base \"n\" (base del numero a convertir)"<<endl;
                 int baseN;
                 cin>>baseN;
        cout<<"Ingrese la Base \"m\" (base a la cual se desea convertir)"<<endl;
        int baseM;
        cin>>baseM;

        baseNaBaseM(num,baseN,baseM);
     }
     if( opcion==3 )
     {
        DecimalAIEEE754();
        cout<<endl;
     }

     if( opcion==4 )
     {
        cout<<"Ingrese Numero 1"<<endl;
        int n1;
        cin>>n1;
        cout<<"Ingrese Numero 2 (Ingresar valor negativo para restar)"<<endl;
        int n2;
        cin>>n2;

        sumaBCD(n1,n2);
        cout<<endl;
     }

     cout<<"-------------------------------"<<endl;
     cout<<"1- Volver al Menu Principal"<<endl;
     cout<<"0- Finalizar"<<endl;
     cin>>volver;
     cout<<"-------------------------------"<<endl<<endl;
  }

  return 0;
}
