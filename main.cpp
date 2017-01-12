#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <fstream>
using namespace std;

fstream tabel_scoruri("tabel_scoruri.txt");
void seteaza_culoarea(unsigned short culoare)
{
    HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,culoare);
}
struct sarpe
{
    int x,y;

}componente[100];
char harta[100][100];
int n=22,lungime_sarpe,coord_fruct1,coord_fruct2,scor;
bool joc_in_desfasurare;
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

       harta[4][4]='O';
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
    if(harta[x][y]=='o')joc_in_desfasurare=false;
    int i;
    for(i=lungime_sarpe;i>1;i--)
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
       harta[componente[1].x][componente[1].y]='O';
       for(i=2;i<=lungime_sarpe;i++)
        harta[componente[i].x][componente[i].y]='o';
        harta[coord_fruct1][coord_fruct2]='$';
}
void harta_afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            switch(harta[i][j])
            {
                default:
                seteaza_culoarea(15); break;

                case 'O':
                seteaza_culoarea(34); break;

                case 'o':
                seteaza_culoarea(6); break;

                case '$':
                seteaza_culoarea(10); break;

                case '*':
                seteaza_culoarea(102); break;
            }
            cout<<harta[i][j];
        }
        cout<<endl;
    }
    seteaza_culoarea(15);
    cout<<"scor:"<<scor<<" || "<<"lungime:"<<lungime_sarpe;

}
int main()
{
    tabel_scoruri.open("tabel_scoruri.txt");
tabel_scoruri.close();

    char joc_nou[10]="JOC NOU",tabel[10]="TABEL",iesire[10]="IESIRE";
    unsigned short pozitie=0,directie=0;
    cout<<"  >"<<joc_nou<<"<  "<<endl;
    cout<<"   "<<tabel<<"   "<<endl;
    cout<<"   "<<iesire<<"   ";

while(1)if(kbhit())
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
               system("cls");
            switch(pozitie)
            {

        case 0:
          {
            joc_in_desfasurare=true;

            directie=0;

            scor=0;

            bool fruct_mancat=false;

            srand(unsigned(time(0)));

            coord_fruct1=rand()%(n-2)+2;
            coord_fruct2=rand()%(n-2)+2;

            harta_init();

            while(joc_in_desfasurare)
            {
                int aux1=componente[lungime_sarpe].x,aux2=componente[lungime_sarpe].y;
                //system("cls");
                HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);

                if(kbhit())
                switch(getch())
                {
               case 119:
                if(directie==0||directie==1)directie=2;break;

               case 115:
                if(directie==0||directie==1)directie=3;break;

               case 97:
                if(directie==2||directie==3)directie=0;break;

               case 100:
                if(directie==2||directie==3)directie=1;break;
                }
                    switch(directie)
                {
                case 0:

                    if(componente[1].y==2)muta_componentele(componente[1].x,n-1);
                    else muta_componentele(componente[1].x,componente[1].y-1);
                    break;

                case 1:

                    if(componente[1].y==n-1)muta_componentele(componente[1].x,2);
                    else muta_componentele(componente[1].x,componente[1].y+1);
                    break;

                case 2:

                    if(componente[1].x==2)muta_componentele(n-1,componente[1].y);
                    else muta_componentele(componente[1].x-1,componente[1].y);
                    break;

                case 3:

                    if(componente[1].x==n-1)muta_componentele(2,componente[1].y);
                    else muta_componentele(componente[1].x+1,componente[1].y);
                    break;
                }
            if(componente[1].x==coord_fruct1&&componente[1].y==coord_fruct2)
            {
                lungime_sarpe++;

                scor++;

                componente[lungime_sarpe].x=aux1;
                componente[lungime_sarpe].y=aux2;

                coord_fruct1=rand()%(n-2)+2;
                coord_fruct2=rand()%(n-2)+2;
            }
             harta_update();
             harta_afisare();
             Sleep(50);
            }

            bool salveaza=true;

            tabel_scoruri.open("tabel_scoruri.txt",ios::app);

            system("cls");

            cout<<"Doresti sa salvezi scorul?:"<<endl;
            cout<<">DA<   NU";

            bool ok=true;

            while(ok)
            {
            switch(getch())
            {
                case 97:
                    {
                    system("cls");

                cout<<"Doresti sa salvezi scorul?:"<<endl;
                cout<<">DA<   NU";

                salveaza=true;

                break;
            }
                case 100:
                    {

                    system("cls");

                cout<<"Doresti sa salvezi scorul?:"<<endl;
                cout<<"DA   >NU<";

                salveaza=false;

                break;
            }
                case 122:
                    ok=false;
                    break;
            }
            }
             system("cls");

            if(salveaza)
            {

                cout<<"Nume jucator:";
                char nume[20];
                cin>>nume;

                tabel_scoruri<<nume<<":"<<scor<<endl;

                tabel_scoruri.close();

            }

            system("cls");
            cout<<"  >"<<joc_nou<<"<  "<<endl;
            cout<<"   "<<tabel<<"   "<<endl;
            cout<<"   "<<iesire<<"   ";

            break;
            }

     case 1:
         char nume_scor[40];
         tabel_scoruri.open("tabel_scoruri.txt");
         while(tabel_scoruri>>nume_scor)
         {
             cout<<nume_scor<<endl;
             strcpy(nume_scor,"");
             tabel_scoruri.get();
         }
         tabel_scoruri.close();
         cout<<">MENIU<";
         if(getch()==122)
            break;
case 2:return 0;
break;
}
            }
//return 0;
}

