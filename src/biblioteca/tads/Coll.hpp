#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template <typename T>
struct Coll
{
   string s;
   char sep;
   int next;
};

template <typename T>
bool collHasNext(Coll<T> c);
template <typename T>
T collNext(Coll<T>& c, T tFromString(string));

// collCreate
template <typename T>
Coll<T> collCreate()
{
   Coll<T> x;
   x.s = "";
   x.sep = '|';
   x.next = 0;
   return x;
}

template <typename T>
Coll<T> collCreate(char c)
{
   Coll<T> x;
   x.s = "";
   x.sep = c;
   x.next = 0;
   return x;
}

template <typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s,c.sep);
}

template <typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s = "";
   c.next = 0;
}

template <typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   if(collSize(c)>0){
      removeTokenAt(c.s,c.sep,p);
      }
}

// -- [GENERICAS] --

template <typename T>
int collAdd(Coll<T>& c, T t, string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   return collSize(c)-1;
}

template <typename T>
void collAddAt(Coll<T>& c, T t, string tToString(T), int pos)
{
   addTokenAt(c.s,c.sep,tToString(t),pos);
}

template <typename T>
void collSetAt(Coll<T>& c, T t, int p, string tToString(T))
{
   setTokenAt(c.s,c.sep,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   return tFromString(getTokenAt(c.s,c.sep,p));
}

template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   c.next = 0;
   while( collHasNext(c) )
   {
      if( cmpTK(collNext(c,tFromString),k)==0 )
      {
         return c.next-1;
      }
   }
   return -1;
}
template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string), int num)
{
   c.next = num;
   while( collHasNext(c) )
   {
      if( cmpTK(collNext(c,tFromString),k)==0 )
      {
         return c.next-1;
      }
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c, int cmpTT(T, T), T tFromString(string))
{
   int i,j = collSize(c)-1;
   string s;
   while( j>0 )
   {
      i = 0;
      while(i<j)
      {
         if( cmpTT(collGetAt(c,i,tFromString),collGetAt(c,(i+1),tFromString))>0 )
         {
            s = getTokenAt(c.s,c.sep,i);
            setTokenAt(c.s,c.sep,getTokenAt(c.s,c.sep,i+1),i);
            setTokenAt(c.s,c.sep,s,i+1);
         }
         i = i+1;
      }
      j = j-1;
   }

}

template <typename T>
void collSort(Coll<T>& c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   int i,j = collSize(c)-1;
   string s;
   while( j>0 )
   {
      i = 0;
      while(i<j)
      {
         if( cmpTT(collGetAt(c,i,tFromString),collGetAt(c,(i+1),tFromString))>0 )
         {
            s = getTokenAt(c.s,c.sep,i);
            setTokenAt(c.s,c.sep,getTokenAt(c.s,c.sep,i+1),i);
            setTokenAt(c.s,c.sep,s,i+1);
         }
         i = i+1;
      }
      j = j-1;
   }

}

template <typename T>
bool collHasNext(Coll<T> c)
{
   return c.next<(collSize(c))?true:false;
}

template <typename T>
T collNext(Coll<T>& c, T tFromString(string))
{
   T t = collGetAt(c,c.next,tFromString);
   c.next = c.next+1;
   return t;
}

template <typename T>
void collReset(Coll<T>& c)
{
   c.next = 0;
}

template <typename T>
int collPos(Coll<T>& c)
{
   return c.next;
}

template <typename T>
string collToString(Coll<T> c){

   return  c.sep + c.s;
}

template <typename T>
Coll<T> collFromString(string s){
  Coll<T> c;
  c.s = substring(s,1);
  c.sep = s[0];
  c.next=0;
  return c;
}


#endif
