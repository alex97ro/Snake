#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "harta.h"
using namespace std;

int main()
{


    char joc_nou[10]="JOC NOU",tabel[10]="TABEL",iesire[10]="IESIRE";
    cout<<"  >"<<joc_nou<<"<  "<<endl;
    cout<<"   "<<tabel<<"   "<<endl;
    cout<<"   "<<iesire<<"   ";

    unsigned short pozitie=0,viteza_joc;

    bool joc_in_desfasurare;

    harta harta1;
int i=getch();
cout<<i;
while(1){
        switch (getch())
            {

           case 119:

            if(pozitie==0)
            {
                system("cls");
                cout<<"   "<<joc_nou<<"   "<<endl;
                cout<<"   "<<tabel<<"   "<<endl;
                cout<<"  >"<<iesire<<"<  ";
                pozitie=2;
            }
            else if(pozitie==1)
            {
                system("cls");
                cout<<"  >"<<joc_nou<<"<  "<<endl;
                cout<<"   "<<tabel<<"   "<<endl;
                cout<<"   "<<iesire<<"   ";
                pozitie=0;
            }
           else if(pozitie==2)
            {
                system("cls");
                cout<<"   "<<joc_nou<<"   "<<endl;
                cout<<"  >"<<tabel<<"<  "<<endl;
                cout<<"   "<<iesire<<"   ";
                pozitie=1;
            }
            break;

           case 115:

            if(pozitie==0)
            {
                system("cls");
                cout<<"   "<<joc_nou<<"   "<<endl;
                cout<<"  >"<<tabel<<"<  "<<endl;
                cout<<"   "<<iesire<<"   ";
                pozitie=1;
            }
        else if(pozitie==1)
            {
                system("cls");
                cout<<"   "<<joc_nou<<"   "<<endl;
                cout<<"   "<<tabel<<"   "<<endl;
                cout<<"  >"<<iesire<<"<  ";
                pozitie=2;
            }
            else if(pozitie==2)
            {
                system("cls");
                cout<<"  >"<<joc_nou<<"<  "<<endl;
                cout<<"   "<<tabel<<"   "<<endl;
                cout<<"   "<<iesire<<"   ";
                pozitie=0;
            }
            break;

           case 104:
            if(pozitie==0)harta1.afisare();
            break;

    }
}

}
