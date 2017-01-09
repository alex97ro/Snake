#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
<<<<<<< HEAD
using namespace std;

char harta[100][100];
int n=30;
void harta_init()
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        harta[1][i]='*';
        harta[i][1]='*';
        harta[n][i]='*';
        harta[i][n]='*';
    }
    for(i=2;i<n;i++)
        for(j=2;j<n;j++)
       harta[i][j]=' ';
}
void harta_afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<harta[i][j];
        cout<<endl;
    }

}
struct sarpe
        {
            unsigned short x,y;
            sarpe *urm;
        }*cap;

int main()
{
    char joc_nou[10]="JOC NOU",tabel[10]="TABEL",iesire[10]="IESIRE";
    unsigned pozitie=0;
    bool joc_in_desfasurare;
=======
#include "harta.h"
using namespace std;

int main()
{


    char joc_nou[10]="JOC NOU",tabel[10]="TABEL",iesire[10]="IESIRE";
>>>>>>> 8aff7149edb324fbc60012cfadac250b6805a98a
    cout<<"  >"<<joc_nou<<"<  "<<endl;
    cout<<"   "<<tabel<<"   "<<endl;
    cout<<"   "<<iesire<<"   ";

<<<<<<< HEAD
while(1)
=======
    unsigned short pozitie=0,viteza_joc;

    bool joc_in_desfasurare;

    harta harta1;

while(1){
>>>>>>> 8aff7149edb324fbc60012cfadac250b6805a98a
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

<<<<<<< HEAD
           case 122:
            switch(pozitie)
            {

        case 0:

            joc_in_desfasurare=true;

            harta_init();

            while(joc_in_desfasurare)
            {
             harta_afisare();
             system("cls");
            }
            break;

}
            }
return 0;
}

=======
           case 104:
            if(pozitie==0)harta1.afisare();
            break;

    }
}

}
>>>>>>> 8aff7149edb324fbc60012cfadac250b6805a98a
