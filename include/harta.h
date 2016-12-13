#ifndef HARTA_H
#define HARTA_H
#include <iostream>
#include <stdlib.h>
using namespace std;
class harta
{
    public:

        harta();

        virtual ~harta();

        void afisare()
        {
            system("cls");
          for(unsigned short i=0;i<lungime;i++)
          {
           for(unsigned short j=0;j<latime;j++)
             cout<<matrice[i][j]<<"";

            cout<<endl;
           }
        }

    protected:

    private:
        unsigned short lungime,latime;
        char matrice[100][100]={""};

};

#endif // HARTA_H
