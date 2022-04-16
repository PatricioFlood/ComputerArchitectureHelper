#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"
int tokenCount(string s, char sep) // ok
{
   if( s=="" )
   {
      return 0;
   }
   else
   {
      return charCount(s,sep)+1;
   }
}

// pablo|juan|pedro|carlos
string getTokenAt(string s, char sep, int p)  // ok
{
   string r;
   int c,c1 = 0;
   int tot = tokenCount(s,sep);
   for( int i = 0; i<(p+1); i++ )
   {

      if( i==(tot-1) )
      {
         r = substring(s,c1);
      }
      else
      {
         c = c1+indexOf(s,sep,c1);
         r = substring(s,c1,c);
         c1 = c+1;
      }
   }
   return r;
}

void addToken(string& s, char sep, string t) // ok
{
   if( tokenCount(s,sep)>0 )
   {
      s = s+sep+t;
   }
   else
   {
      s = s+t;
   }
}

void addTokenAt(string& s, char sep, string t, int pos) // ok
{
   string r;
   int tot = tokenCount(s,sep);
   if( length(s)==0 )
   {
      s = t;
   }
   else
   {
      if( pos==0 )
      {
         s = t+sep+substring(s,0);
      }
      else
         if( pos==(tot-1) )
         {
            s = s+sep+t;
         }
         else
         {

            int c = -1,c1;
            for( int i = 0; i<(pos+1); i++ )
            {
               c1 = c+1;
               c = c1+indexOf(s,sep,c1);

            }

            s = substring(s,0,c1)+t+sep+substring(s,c1);

         }
   }
}

void removeTokenAt(string& s, char sep, int p)
{
   if( (tokenCount(s,sep)==1)&&(p==0) )
   {
      s = "";
   }
   else
   {
      string sub1 = p==0?"":substring(s,0,indexOfN(s,sep,(p)));
      string sub2 = p==0?substring(s,indexOfN(s,sep,1)+1):p==(tokenCount(s,sep)-1)?"":substring(s,indexOfN(s,sep,(p+1)));
      s = sub1+sub2;
   }
}

void setTokenAt(string& s, char sep, string t, int p) // ok
{
   string r;
   int c = -1,c1;
   int tot = tokenCount(s,sep);
   for( int i = 0; i<(p+1); i++ )
   {
      c1 = c+1;
      c = c1+indexOf(s,sep,c1);

   }
   if( p!=(tot-1) )
   {
      s = substring(s,0,c1)+t+substring(s,c);
   }
   else
   {
      s = substring(s,0,c1)+t;
   }

}

int findToken(string s, char sep, string t)
{
   bool next = true;
   int tot = tokenCount(s,sep);
   int i;
   string comparar;
   for( i = 0; (i<tot)&&next; i++ )
   {
      comparar = s;
      setTokenAt(comparar,sep,t,i);
      if( comparar==s )
      {
         next = false;
         i = i-1;
      }
   }
   return next?-1:i;
}

// --[/Funciones Token]--

#endif
