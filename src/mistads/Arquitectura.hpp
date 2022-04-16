/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADARQUITECTURA_
#define _TADARQUITECTURA_

#include "../biblioteca/funciones/strings.hpp"
#include <iostream>
using namespace std;

double parteMantisa(double num)
{
   int a = num;
   return num-a;
}

bool convertirABinario(double num, Coll<int>& cPEnteraR, Coll<int>& cPMantisa)
{
   bool signo = num<0?true:false;
   num = signo?0-num:num;
   double mantisa = parteMantisa(num);
   int pEntera = num;

   Coll<int> cPEntera = collCreate<int>();

   int div = pEntera;

   int resto = 0;
   int cont = 0;

   if( pEntera>0 )
   {

      cout<<"--------------- Pasaje de Parte Entera a Binario ------------------"<<endl<<endl;
      cout<<div;

      while( div>0 )
      {
         resto = div%2;
         div = div/2;
         cout<<"\t/2"<<"\tResto: "<<resto<<endl<<div;
         collAdd(cPEntera,resto,intToString);
         cont++;
      }

      for( int i = collSize(cPEntera)-1; i>=0; i-- )
      {
         collAdd(cPEnteraR,collGetAt(cPEntera,i,stringToInt),intToString);
      }

      cout<<endl;
   }

   if( mantisa>0 )
   {
      cout<<endl;
      cout<<"--------------- Pasaje de Mantisa a Binario ------------------"<<endl<<endl;
      if( collSize(cPEntera)>0 )
      {
         for( int i = 24-collSize(cPEntera); (i>0)&&(mantisa!=0); i-- )
         {
            cout<<mantisa<<"\t\t\t*2";
            mantisa = mantisa*2;

            if( mantisa>=1 )
            {
               mantisa = mantisa-1;
               cout<<"\t1"<<endl;
               collAdd(cPMantisa,1,intToString);
            }
            else
            {
               cout<<"\t0"<<endl;
               collAdd(cPMantisa,0,intToString);
            }
         }
      }
      else
      {
         bool primerUno = false;
         for( int i = 127; (i>0)&&(mantisa!=0)&&!primerUno; i-- )
         {
            cout<<mantisa<<"\t\t\t*2";
            mantisa = mantisa*2;

            if( mantisa>=1 )
            {
               primerUno = true;
               mantisa = mantisa-1;
               cout<<"\t1"<<endl;
               collAdd(cPMantisa,1,intToString);
            }
            else
            {
               cout<<"\t0"<<endl;
               collAdd(cPMantisa,0,intToString);
            }
         }
         if( primerUno )
         {
            for( int i = 23; (i>0)&&(mantisa!=0); i-- )
            {
               cout<<mantisa<<"\t\t\t*2";
               mantisa = mantisa*2;

               if( mantisa>=1 )
               {
                  primerUno = true;
                  mantisa = mantisa-1;
                  cout<<"\t1"<<endl;
                  collAdd(cPMantisa,1,intToString);
               }
               else
               {
                  cout<<"\t0"<<endl;
                  collAdd(cPMantisa,0,intToString);
               }
            }
         }
      }

      cout<<mantisa<<endl;
   }

   return signo;

}

bool convertirABinario(double num, Coll<int>& cPEnteraR)
{
   bool signo = num<0?true:false;
   num = signo?0-num:num;
   int pEntera = num;

   Coll<int> cPEntera = collCreate<int>();

   int div = pEntera;

   int resto = 0;
   int cont = 0;

   cout<<"---------------Pasaje a Binario-----------------"<<endl<<endl;
   cout<<div;

   while( div>0 )
   {
      resto = div%2;
      div = div/2;
      cout<<"\t/2"<<"\tResto: "<<resto<<endl<<div;
      collAdd(cPEntera,resto,intToString);
      cont++;
   }

   for( int i = collSize(cPEntera)-1; i>=0; i-- )
   {
      collAdd(cPEnteraR,collGetAt(cPEntera,i,stringToInt),intToString);
   }

   cout<<endl;

   return signo;

}

void mostrarResultadoBinario(Coll<int> cPEntera, Coll<int> cPMantisa, bool signo)
{
   if( signo )
   {
      cout<<"-";
   }
   if( collSize(cPEntera)>0 )
   {
      while( collHasNext(cPEntera) )
      {
         cout<<collNext(cPEntera,stringToInt);
      }
   }
   else
   {
      cout<<"0";
   }
   if( collSize(cPMantisa)>0 )
   {
      cout<<".";
      while( collHasNext(cPMantisa) )
      {
         cout<<collNext(cPMantisa,stringToInt);
      }
   }
}

void mostrarResultadoBinario(Coll<int> cPEntera, bool signo)
{
   if( signo )
   {
      cout<<"-";
   }
   if( collSize(cPEntera)>0 )
   {
      while( collHasNext(cPEntera) )
      {
         cout<<collNext(cPEntera,stringToInt);
      }
   }
   else
   {
      cout<<"0";
   }
}

void DecimalAIEEE754()
{
   cout<<"Ingrese numero a convertir a IEEE 754"<<endl;
   double num;
   cin>>num;
   Coll<int> cPEntera = collCreate<int>();
   Coll<int> cPMantisa = collCreate<int>();
   bool signo = convertirABinario(num,cPEntera,cPMantisa);
   cout<<endl;
   cout<<"Resultado: ";
   mostrarResultadoBinario(cPEntera,cPMantisa,signo);

   cout<<" = ";
   if( signo )
   {
      cout<<"-";
   }
   int exponente;
   cout<<"1.";
   if( collSize(cPEntera)>0 )
   {
      collRemoveAt(cPEntera,0);
      mostrarResultadoBinario(cPEntera,false);
      if( collSize(cPMantisa)>0 )
      {
         mostrarResultadoBinario(cPMantisa,false);
      }
      exponente = collSize(cPEntera);
   }
   else
   {
      for( exponente = 0; collGetAt(cPMantisa,0,stringToInt)==0&&collSize(cPMantisa)>0; exponente-- )
      {
         collRemoveAt(cPMantisa,0);
      }
      collRemoveAt(cPMantisa,0);
      exponente--;
      mostrarResultadoBinario(cPMantisa,false);
   }
   cout<<" * 2 ^ "<<exponente;
   cout<<endl<<endl;

   cout<<"Signo = ";
   if( signo )
   {
      cout<<"Negativo = 1";
   }
   else
   {
      cout<<"Positivo = 0";
   }
   cout<<endl<<endl;

   cout<<"Mantisa = ";
   while( collSize(cPEntera)+collSize(cPMantisa)<23 )
   {
      collAdd(cPMantisa,0,intToString);
   }
   mostrarResultadoBinario(cPEntera,false);
   mostrarResultadoBinario(cPMantisa,false);
   cout<<endl<<endl;

   cout<<"Exponente = "<<exponente<<endl<<endl;
   cout<<"Caracteristica = "<<exponente<<" + 127 = ";

   exponente = exponente+127;
   cout<<exponente<<endl<<endl;

   Coll<int> cExponente = collCreate<int>();
   convertirABinario(exponente,cExponente);
   cout<<endl;

   cout<<"Signo |\tCaracteristica |         Mantisa"<<endl;
   cout<<"  "<<signo<<"   |    ";
   while( collSize(cExponente)<8 )
   {
      collAddAt(cExponente,0,intToString,0);
   }
   mostrarResultadoBinario(cExponente,false);
   cout<<"    | ";

   mostrarResultadoBinario(cPEntera,false);
   mostrarResultadoBinario(cPMantisa,false);
}

void baseNaBaseM(string num, int baseN, int baseM)
{
   //Comprobacion de numero negativo
   bool signo = num[0]=='-'?true:false;
   if( signo )
   {
      num = substring(num,1);
   }

   unsigned int resB10 = 0;
   //Pasaje a base 10
   if( baseN!=10 )
   {
      cout<<"------------- Pasaje a Decimal (Base 10) -------------"<<endl<<endl;
      int tamanio = length(num);
      unsigned int multiplicador = intPow(baseN,tamanio-1);
      for( int i = tamanio-1; i>=0; i-- )
      {
         char ch = num[tamanio-i-1];
         int digito = charToInt(ch);
         if( digito>=0 )
         {
            cout<<ch<<" * ";
            cout<<baseN<<" ^ "<<i<<" = ";
            resB10 = resB10+(digito*multiplicador);
            cout<<digito*multiplicador<<endl;

            multiplicador = multiplicador/baseN;

            if( i!=0 )
            {
               cout<<"              +"<<endl;
            }
         }
         else
         {
            cout<<"Error: Digito Invalido. (Solo son validos digitos de \'0\' a \'9\' y de \'A\' a \'Z\'."<<endl;
         }
      }

      cout<<endl<<"Resultado = ";
      if( signo )
      {
         cout<<"-";
      }
      cout<<resB10<<" (Base 10)";
      cout<<endl;
   }
   else
   {
      resB10 = stringToInt(num);
   }

   //Pasaje a base M
   if( baseM!=10 )
   {
      cout<<endl;
      cout<<"------------- Pasaje de Decimal (Base 10) a Base "<<baseM<<" -------------"<<endl<<endl;

      Coll<char> digitos = collCreate<char>();
      int resto = 0;
      int cont = 0;

      unsigned int div = resB10;
      cout<<div;

      while( div>0 )
      {
         resto = div%baseM;
         div = div/baseM;
         cout<<"\t/"<<baseM<<"\tResto: "<<resto;
         char res = intToChar(resto);
         if( res>64 )
         {
            cout<<" = "<<res;
         }
         cout<<endl<<div;
         collAdd(digitos,res,charToString);
         cont++;
      }
      cout<<endl<<"Resultado: ";
      if( signo )
      {
         cout<<"-";
      }
      for( int i = collSize(digitos)-1; i>=0; i-- )
      {
         cout<<collGetAt(digitos,i,stringToChar);
      }
      cout<<" (Base "<<baseM<<")"<<endl;
   }

}

string digitoToBCD(int digito)
{
   if( digito==0 )
   {
      return "0000";
   }
   else
      if( digito==1 )
      {
         return "0001";
      }
      else
         if( digito==2 )
         {
            return "0010";
         }
         else
            if( digito==3 )
            {
               return "0011";
            }
            else
               if( digito==4 )
               {
                  return "0100";
               }
               else
                  if( digito==5 )
                  {
                     return "0101";
                  }
                  else
                     if( digito==6 )
                     {
                        return "0110";
                     }
                     else
                        if( digito==7 )
                        {
                           return "0111";
                        }
                        else
                           if( digito==8 )
                           {
                              return "1000";
                           }
                           else
                           {
                              return "1001";
                           }
}

int bcdToDigito(string bcd)
{
   if( bcd=="0000" )
   {
      return 0;
   }
   else
      if( bcd=="0001" )
      {
         return 1;
      }
      else
         if( bcd=="0010" )
         {
            return 2;
         }
         else
            if( bcd=="0011" )
            {
               return 3;
            }
            else
               if( bcd=="0100" )
               {
                  return 4;
               }
               else
                  if( bcd=="0101" )
                  {
                     return 5;
                  }
                  else
                     if( bcd=="0110" )
                     {
                        return 6;
                     }
                     else
                        if( bcd=="0111" )
                        {
                           return 7;
                        }
                        else
                           if( bcd=="1000" )
                           {
                              return 8;
                           }
                           else
                              if( bcd=="1001" )
                              {
                                 return 9;
                              }
                              else
                              {
                                 return -1;
                              }

}

void mostrarBCD(Coll<string> bcd)
{
   while( collHasNext(bcd) )
   {
      cout<<collNext(bcd,stringToString);
      if( collHasNext(bcd) )
      {
         cout<<" ";
      }
   }
}

string sumarDigitoBCD(string bcd1, string bcd2, string& carry)
{
   string res = "0000";
   bool carrySum = false;
   if( carry[0]=='1' )
   {
      carrySum = true;
   }
   carry = "0000";

   char ch1 = bcd1[3];
   char ch2 = bcd2[3];
   char ch3;
   int sum = charToInt(ch1)+charToInt(ch2)+carrySum;
   if( sum>1 )
   {
      carry[3] = '1';
      sum = sum-2;
   }
   res[3] = sum+48;

   for( int i = 2; i>=0; i-- )
   {
      ch1 = bcd1[i];
      ch2 = bcd2[i];
      ch3 = carry[i+1];
      sum = charToInt(ch1)+charToInt(ch2)+charToInt(ch3);
      if( sum>1 )
      {
         carry[i] = '1';
         sum = sum-2;
      }
      res[i] = sum+48;
   }
   return res;

}

Coll<string> sumarCollLiteralBCD(Coll<string> bcd1, Coll<string> bcd2, Coll<string>& collCarry)
{

   Coll<string> resultado = collCreate<string>();

   string carry = "0000";

   for( int i = collSize(bcd1)-1; i>=0; i-- )
   {
      collAddAt(resultado,sumarDigitoBCD(collGetAt(bcd1,i,stringToString),collGetAt(bcd2,i,stringToString),carry),stringToString,0);
      collAddAt(collCarry,carry,stringToString,0);
   }

   return resultado;

}

Coll<string> sumarCollBCD(Coll<string> bcd1, Coll<string> bcd2, Coll<string>& collCarry, Coll<string>& collCarry2, Coll<string>& suma6, Coll<string>& resParcial)
{

   Coll<string> resultado = collCreate<string>();

   collRemoveAll(collCarry);
   collRemoveAll(collCarry2);
   collRemoveAll(suma6);
   collRemoveAll(resParcial);

   string carry = "0000";
   string carry2 = "0000";

   for( int i = collSize(bcd1)-1; i>=0; i-- )
   {
      carry = carry2;
      carry2 = "0000";
      string res = sumarDigitoBCD(collGetAt(bcd1,i,stringToString),collGetAt(bcd2,i,stringToString),carry);
      collAddAt(resParcial,res,stringToString,0);
      collAddAt(collCarry,carry,stringToString,0);
      if( bcdToDigito(res)<0||carry[0]=='1' )
      {
         string seis = "0110";
         collAddAt(suma6,seis,stringToString,0);
         res = sumarDigitoBCD(res,"0110",carry2);
         collAddAt(collCarry2,carry2,stringToString,0);
         carry2 = "1111";
      }
      else
      {
         string cero = "0000";
         collAddAt(suma6,cero,stringToString,0);
         carry2 = "0000";
         collAddAt(collCarry2,carry2,stringToString,0);
      }
      collAddAt(resultado,res,stringToString,0);

   }

   return resultado;

}

Coll<string> invertirBCD(Coll<string> bcd)
{

   for( int i = 0; i<(collSize(bcd)); i++ )
   {
      string sGet = collGetAt(bcd,i,stringToString);
      for( int j = 0; j<4; j++ )
      {
         if( sGet[j]==49 )
         {
            sGet[j] = 48;
         }
         else
         {
            sGet[j] = 49;
         }
      }
      collSetAt(bcd,sGet,i,stringToString);
   }

   return bcd;
}

Coll<string> complementoBCD(Coll<string> collN1, int n1)
{
   cout<<"-----------------C1 de "<<n1<<"---------------------"<<endl;
   Coll<string> collCarry = collCreate<string>();
   Coll<string> coll6 = collCreate<string>();
   for( int i = 0; i<collSize(collN1); i++ )
   {
      string seis = "0110";
      collAdd(coll6,seis,stringToString);
   }

   Coll<string> collResultado = sumarCollLiteralBCD(collN1,coll6,collCarry);

   cout<<"Carry: \t\t\t";
   mostrarBCD(collCarry);
   cout<<endl<<"Numero en BCD: \t\t ";
   mostrarBCD(collN1);
   cout<<" ("<<n1<<")"<<endl<<"\t\t\t";
   for( int i = 0; i<collSize(collN1); i++ )
   {
      cout<<"+    ";
   }

   cout<<endl<<"\t\t\t ";
   mostrarBCD(coll6);
   cout<<endl<<"\t\t\t ";
   for( int i = 0; i<collSize(collN1); i++ )
   {
      cout<<"---- ";
   }
   cout<<endl<<"Resultado:\t\t ";
   mostrarBCD(collResultado);
   cout<<endl<<"\t\t\t ";
   for( int i = 0; i<collSize(collN1); i++ )
   {
      cout<<"---- ";
   }
   cout<<endl<<"Invertir:\t\t ";
   collResultado = invertirBCD(collResultado);
   mostrarBCD(collResultado);
   cout<<endl;

   return collResultado;
}

unsigned int collBCDtoInt(Coll<string> bcd)
{
   unsigned int res = 0;
   unsigned int mult = 1;
   for( int i = collSize(bcd)-1; i>=0; i-- )
   {
      res = res+(bcdToDigito(collGetAt(bcd,i,stringToString))*mult);
      mult = mult*10;
   }
   return res;
}

void sumaBCD(int n1, int n2)
{

   bool compN1 = n1<0?true:false;
   bool compN2 = n2<0?true:false;
   bool resta = false;
   if( compN1 )
   {
      n1 = 0-n1;
   }
   if( compN2 )
   {
      n2 = 0-n2;
   }

   if( compN1||compN2 )
   {
      resta = true;
   }

   Coll<string> collN1 = collCreate<string>();
   Coll<string> collN2 = collCreate<string>();

   // Pasaje de decimal a BCD
   for( int i = 0; i<digitCount(n1); i++ )
   {
      int digito = getDigit(n1,i);
      collAddAt(collN1,digitoToBCD(digito),stringToString,0);
   }

   for( int i = 0; i<digitCount(n2); i++ )
   {
      int digito = getDigit(n2,i);
      collAddAt(collN2,digitoToBCD(digito),stringToString,0);
   }

   // Completar con 0000 si es mas grande
   while( collSize(collN1)>collSize(collN2) )
   {
      string s = "0000";
      collAddAt(collN2,s,stringToString,0);
   }

   while( collSize(collN1)<collSize(collN2) )
   {
      string s = "0000";
      collAddAt(collN1,s,stringToString,0);
   }

   // Complemento si es negativo
   if( compN1 )
   {
      collN1 = complementoBCD(collN1,n1);
   }
   if( compN2 )
   {
      collN2 = complementoBCD(collN2,n2);
   }

   cout<<endl<<endl;

   Coll<string> carry = collCreate<string>();
   Coll<string> carry2 = collCreate<string>();
   Coll<string> suma6 = collCreate<string>();
   Coll<string> resParcial = collCreate<string>();
   Coll<string> resultado = sumarCollBCD(collN1,collN2,carry,carry2,suma6,resParcial);

   cout<<"----------------Suma-------------------"<<endl;

   cout<<"Carry: \t\t\t";
   mostrarBCD(carry);
   cout<<endl<<"Numero 1 en BCD: \t ";
   mostrarBCD(collN1);
   cout<<" (";
   if( compN1 )
   {
      cout<<"C1 de ";
   }
   cout<<n1<<")"<<endl<<"\t\t\t";
   for( int i = 0; i<collSize(collN1); i++ )
   {
      cout<<"+    ";
   }

   cout<<endl<<"Numero 2 en BCD: \t ";
   mostrarBCD(collN2);
   cout<<" (";
   if( compN2 )
   {
      cout<<"C1 de ";
   }
   cout<<n2<<")"<<endl;
   cout<<"\t\t\t ";
   for( int i = 0; i<collSize(collN1); i++ )
   {
      cout<<"---- ";
   }

   // ------------------------
   int paso = 1;
   if( collBCDtoInt(suma6)>0 )
   {
      paso = 2;
      cout<<endl<<"Carry "<<paso<<": \t\t";
      mostrarBCD(carry2);
      cout<<endl<<"Resultado Parcial:\t ";
      mostrarBCD(resParcial);

      cout<<endl<<"\t\t\t";
      for( int i = 0; i<collSize(resParcial); i++ )
      {
         cout<<"+    ";
      }
      cout<<endl<<"\t\t\t ";
      mostrarBCD(suma6);
      cout<<endl<<"\t\t\t ";
      for( int i = 0; i<collSize(resParcial); i++ )
      {
         cout<<"---- ";
      }
   }
   else
   {
      resultado = resParcial;
   }

   // Resta
   if( resta )
   {
      paso = paso+1;
      Coll<string> resParcial0 = resultado;

      Coll<string> suma1 = collCreate<string>();
      collAddAt(suma1,(string)"0001",stringToString,0);
      for( int i = 1; i<collSize(resultado); i++ )
      {
         collAddAt(suma1,(string)"0000",stringToString,0);
      }

      resultado = sumarCollBCD(resultado,suma1,carry,carry2,suma6,resParcial);

      cout<<endl<<"Carry "<<paso<<": \t\t";
      mostrarBCD(carry);
      cout<<endl<<"Resultado Parcial "<<paso-1<<":\t ";
      mostrarBCD(resParcial0);
      cout<<endl;

      cout<<"\t\t\t";
      for( int i = 0; i<collSize(resultado); i++ )
      {
         cout<<"+    ";
      }

      cout<<endl<<"\t\t\t ";
      mostrarBCD(suma1);
      cout<<endl<<"\t\t\t ";
      for( int i = 0; i<collSize(resultado); i++ )
      {
         cout<<"---- ";
      }

      // ------------------------
      if( collBCDtoInt(suma6)>0 )
      {
         paso++;
         cout<<endl<<"Carry "<<paso<<": \t\t";
         mostrarBCD(carry2);
         cout<<endl<<"Resultado Parcial "<<paso-1<<":\t ";
         mostrarBCD(resParcial);

         cout<<endl<<"\t\t\t";
         for( int i = 0; i<collSize(resParcial); i++ )
         {
            cout<<"+    ";
         }
         cout<<endl<<"\t\t\t ";
         mostrarBCD(suma6);
         cout<<endl<<"\t\t\t ";
         for( int i = 0; i<collSize(resParcial); i++ )
         {
            cout<<"---- ";
         }
      }
      else
      {
         resultado = resParcial;
      }

      cout<<endl<<"Resultado Final:\t ";
      mostrarBCD(resultado);
      cout<<" ("<<collBCDtoInt(resultado)<<")"<<endl;

      // Suma
   }
   else
   {
      // Si sobra 1
      cout<<endl;
      string s = collGetAt(carry2,0,stringToString);
      if( s[0]=='1' )
      {
         cout<<"Resultado Final:    0001 ";
         mostrarBCD(resultado);
         collAddAt(resultado,(string)"0001",stringToString,0);
         cout<<" ("<<collBCDtoInt(resultado)<<")"<<endl;
      }
      //Si no sobra 1
      else
      {
         cout<<"Resultado Final:\t ";
         mostrarBCD(resultado);
         cout<<" ("<<collBCDtoInt(resultado)<<")"<<endl;
      }
   }

   cout<<endl<<"Comprobacion:"<<endl;
   n1 = compN1?0-n1:n1;
   n2 = compN2?0-n2:n2;

   if( n1+n2==(int)collBCDtoInt(resultado) )
   {
      cout<<"("<<n1<<")"<<" + "<<"("<<n2<<") = "<<"("<<n1+n2<<") ---> Comprobado"<<endl;
   }
   else
   {
      cout<<"("<<n1<<")"<<" + "<<"("<<n2<<") = "<<"("<<n1+n2<<") ---> Ocurrio un error en el calculo."<<endl;
   }
}

#endif
