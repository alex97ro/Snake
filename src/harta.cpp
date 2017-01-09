#include "harta.h"

harta::harta()
{
    lungime=30;
    latime=30;
    for(unsigned short i=0;i<lungime;i++)
        for(unsigned short j=0;j<latime;j++)
        if(i==0||i==lungime-1||j==0||j==latime-1)
            matrice[i][j]='*';
        else matrice[i][j]=' ';
}

harta::~harta()
{
    //dtor
}
