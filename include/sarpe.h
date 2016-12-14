#ifndef SARPE_H
#define SARPE_H


class sarpe
{
    public:
        sarpe(unsigned short lungime,unsigned short latime);
        virtual ~sarpe();

    protected:

    private:
        struct nod_sarpe
        {
            unsigned short x,y;
            nod_sarpe *urm;
        };

        unsigned short lungime_corp;

        nod_sarpe *cap;

};

#endif // SARPE_H
