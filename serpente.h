#include	<windows.h>					// Header File For Windows
#include	<gl\gl.h>					// Header File For The OpenGL32 Library
#include	<gl\glu.h>					// Header File For The GLu32 Library
#include	<gl\glaux.h>
#include 	<time.h>
#include <stdio.h>

struct punto{
       int x;
       int y;
       };

struct nodo{
       punto p;
       nodo* next;
       };

typedef nodo* pnodo;       



class serpente{
      public:
            serpente(int n,int n2,int posx,int posy,char left,char ,char up,char down);
             
             char moveleft;
             char moveright;
             char moveup;
             char movedown;
             
              bool scontro;
             pnodo testa;
             pnodo coda;
             char direzione;
             int n,n2;
                          
             void initialize(int n,int n2,int posx,int posy);
             void snake();
             void updatesnake(int cibox,int ciboy,bool &mangiato,serpente *sn[],int numgioc);
      };




void cibo();
void griglia();
void griglia1();

float random(float a,float b);
int traduciindicex(int i,int n);
int traduciindicey(int i,int n);

void ins_dopo(pnodo &testa,pnodo &coda,int x,int y);
void updatelista(pnodo &testa,pnodo &coda,int x,int y);
bool controllalista(pnodo &testa,int x,int y);
void reset(serpente sn);

