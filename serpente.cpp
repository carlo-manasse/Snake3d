#include "serpente.h"

bool mangiato=true;


serpente::serpente(int n,int n2,int posx,int posy,char left,char right,char up,char down){
     /*
         moveleft='A';
         moveright='D';
         moveup='W';
         movedown='S';
     */
         moveleft=left;
         moveright=right;
         moveup=up;
         movedown=down;
     
     scontro=false;
     testa=0;
     coda=0;
     this->n=n;
     this->n2=n2;
     direzione='n';
     int i;
     for (i=posx;i>posx-10;i--){
           ins_dopo(testa,coda,i,posy);
           }
           }


void serpente::snake(){
    pnodo pp=testa;
    int indicex,indicey;
    
    
    do{
                                                      
    indicex=traduciindicex(pp->p.x,n);
    indicey=traduciindicey(pp->p.y,n);
    glPushMatrix (); 
    
    glBegin (GL_QUADS);
    
            
    if(pp==testa
    //||pp==coda
    )     
            glColor3f (0.4f, 0.5f, 0.0f);
     else
            glColor3f (0.0f, 0.5f, 0.0f);
            
            //faccia sotto
            		glNormal3f( 0.0f,-1.0f, 0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)indicey/n,0.0f);
            glVertex3f ((float) indicex/n,(float)indicey/n,0.0f);
            glVertex3f ((float) indicex/n,(float)(indicey-1)/n,0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)(indicey-1)/n,0.0f);
            
            //faccia sopra
            glNormal3f( 0.0f, 1.0f, 0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)indicey/n,(float)1/n);
            glVertex3f ((float) indicex/n,(float)indicey/n,(float)1/n);
            glVertex3f ((float) indicex/n,(float)(indicey-1)/n,(float)1/n);
            glVertex3f ((float)(indicex-1)/n,(float)(indicey-1)/n,(float)1/n);
            
            //faccie laterali
            //faccia posteriore
            glNormal3f( 0.0f, 0.0f,-1.0f);
            glVertex3f ((float)(indicex-1)/n,(float)indicey/n,0.0f);
            glVertex3f ((float) indicex/n,(float)indicey/n,0.0f);
            glVertex3f ((float) indicex/n,(float)indicey/n,(float)1/n);
            glVertex3f ((float)(indicex-1)/n,(float)indicey/n,(float)1/n);
            
            //faccia dx
            glNormal3f( 1.0f, 0.0f, 0.0f);
            glVertex3f ((float) indicex/n,(float)indicey/n,0.0f);
            glVertex3f ((float) indicex/n,(float)(indicey-1)/n,0.0f);
            glVertex3f ((float) indicex/n,(float)(indicey-1)/n,(float)1/n);
            glVertex3f ((float) indicex/n,(float)indicey/n,(float)1/n);
            
            //faccia anteriore
            glNormal3f( 0.0f, 0.0f, 1.0f);           
            glVertex3f ((float) indicex/n,(float)(indicey-1)/n,0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)(indicey-1)/n,0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)(indicey-1)/n,(float)1/n);
            glVertex3f ((float) indicex/n,(float)(indicey-1)/n,(float)1/n);
            
            //faccia sx
            glNormal3f(-1.0f, 0.0f, 0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)indicey/n,0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)(indicey-1)/n,0.0f);
            glVertex3f ((float)(indicex-1)/n,(float)(indicey-1)/n,(float)1/n);
            glVertex3f ((float)(indicex-1)/n,(float)indicey/n,(float)1/n);
            
     glEnd ();
     
     
     
     glPopMatrix ();
                 
                 pp=pp->next;
                 }while(pp!=testa);     
                 
                 
     }
     
     
void serpente::updatesnake(int cibox,int ciboy,bool &mangiato,serpente *sn[],int numgioc){
     
     int i;
     
     //scontri
     if(!(testa->p.x+1>0&&testa->p.x+1<n2+1&&testa->p.y+1>0&&testa->p.y+1<n2+1))         
         scontro=true;
         
     
     for(i=0;i<numgioc;i++)
     if(controllalista(sn[i]->testa,testa->p.x,testa->p.y))
         scontro=true;
     
     //controlli sul cibo
    
     if(traduciindicex(testa->p.x,n)==cibox&&traduciindicey(testa->p.y,n)==ciboy){
     mangiato=true;
     ins_dopo(testa,coda,coda->p.x,coda->p.y);
     }
     
     
     
     if (!scontro)
     {
     switch (direzione) {
     //cambi direzione
     case 'r':{
     updatelista(testa,coda,testa->p.x+1,testa->p.y);
     break;
     }
     
     case 'l':{
     updatelista(testa,coda,testa->p.x-1,testa->p.y);
     break;
     }


     case 'u':{
     updatelista(testa,coda,testa->p.x,testa->p.y-1);
     break;
     }
     
     case 'd':{
     updatelista(testa,coda,testa->p.x,testa->p.y+1);
     break;
           }
     
         }//chiusura switch
     
     }//chiusura if
     
     }
