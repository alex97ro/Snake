#include "sarpe.h"
#include <stdlib.h>


sarpe::sarpe(unsigned short lungime,unsigned short latime)
{
    lungime_corp=3;
    unsigned short coord_1,coord_2;

        coord_1=rand()%lungime;
        coord_2=rand()%latime;

    while(coord_1==0||coord_1==lungime||coord_2==0||coord_2>=latime-3)
    {
        coord_1=rand()%lungime;
        coord_2=rand()%latime;
    }
    nod_sarpe *nod = new nod_sarpe,*it;
    nod->x=coord_1;
    nod->y=coord_2;
    cap = nod;
    it=nod;
    for(unsigned short i=2;i<=lungime_corp;i++)
    {
    nod_sarpe *nod_nou= new nod_sarpe;
    nod_nou->x=it->x;
    nod_nou->y=it->y+1;
    it->urm=nod_nou;
    it=nod_nou;

    }
    it->urm=NULL;
}
sarpe::~sarpe()
{
    //dtor
}
