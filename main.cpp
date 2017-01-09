#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct sarpe
{
    int x,y;

}componente[100];
char harta[100][100];
int n=20,lungime_sarpe;
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

       harta[4][4]='o';
       harta[4][5]='o';
       harta[4][6]='o';

       lungime_sarpe=3;

       componente[1].x=4;
       componente[1].y=4;
       componente[2].x=4;
       componente[2].y=5;
       componente[3].x=4;
       componente[3].y=6;
}
void muta_componentele(int x,int y)
{
    int i;
    for(i=n;i>1;i--)
    {
        componente[i].x=componente[i-1].x;
        componente[i].y=componente[i-1].y;
    }
    componente[1].x=x;
    componente[1].y=y;
}
void harta_update()
{
    int i,j;
    for(i=2;i<n;i++)
        for(j=2;j<n;j++)
       harta[i][j]=' ';
       for(i=1;i<=lungime_sarpe;i++)
        harta[componente[i].x][componente[i].y]='o';
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
int main()
{
    char joc_nou[10]="JOC NOU",tabel[10]="TABEL",iesire[10]="IESIRE";
    unsigned short pozitie=0,directie=0;
    bool joc_in_desfasurare;
    cout<<"  >"<<joc_nou<<"<  "<<endl;
    cout<<"   "<<tabel<<"   "<<endl;
    cout<<"   "<<iesire<<"   ";

while(1)
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

