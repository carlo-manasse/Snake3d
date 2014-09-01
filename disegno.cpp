#include "serpente.h"
#include 	<math.h>

float random(float a,float b){
      return (b-a)*(float)rand()/RAND_MAX+a;
      }



int traduciindicex(int i,int n){
    return i-n+1;
    
    }

int traduciindicey(int i,int n){
    return n-i;
    
    }



extern bool mangiato;
int count=0;
int maxcount=200;
int cibox;
int ciboy;

extern int n;
extern int n2;

void cibo(){
     count++;
     if (mangiato||count==maxcount)
     {
                  cibox=traduciindicex((int)random(0,n2-1),n);
                  ciboy=traduciindicey((int)random(0,n2-1),n);
                  mangiato=false;
                  count=0;
     }
     
     glPushMatrix ();
      glBegin (GL_QUADS);     
            glColor3f (1.0f, 0.0f, 0.0f);   
            
            //faccia sotto
            glVertex3f ((float)(cibox-1)/n,(float)ciboy/n,0.0f);
            glVertex3f ((float)(cibox)/n,(float)ciboy/n,0.0f);
            glVertex3f ((float)(cibox)/n,(float)(ciboy-1)/n,0.0f);
            glVertex3f ((float)(cibox-1)/n,(float)(ciboy-1)/n,0.0f);
            
            //faccia sopra
            glVertex3f ((float)(cibox-1)/n,(float)ciboy/n,(float)1/n);
            glVertex3f ((float)(cibox)/n,(float)ciboy/n,(float)1/n);
            glVertex3f ((float)(cibox)/n,(float)(ciboy-1)/n,(float)1/n);
            glVertex3f ((float)(cibox-1)/n,(float)(ciboy-1)/n,(float)1/n);
            
            //faccie laterali
            
            glVertex3f ((float)(cibox-1)/n,(float)ciboy/n,0.0f);
            glVertex3f ((float)(cibox)/n,(float)ciboy/n,0.0f);
            glVertex3f ((float)(cibox)/n,(float)ciboy/n,(float)1/n);
            glVertex3f ((float)(cibox-1)/n,(float)ciboy/n,(float)1/n);
            
            
            glVertex3f ((float)(cibox)/n,(float)ciboy/n,0.0f);
            glVertex3f ((float)(cibox)/n,(float)(ciboy-1)/n,0.0f);
            glVertex3f ((float)(cibox)/n,(float)(ciboy-1)/n,(float)1/n);
            glVertex3f ((float)(cibox)/n,(float)ciboy/n,(float)1/n);
            
            
            glVertex3f ((float)(cibox)/n,(float)(ciboy-1)/n,0.0f);
            glVertex3f ((float)(cibox-1)/n,(float)(ciboy-1)/n,0.0f);
            glVertex3f ((float)(cibox-1)/n,(float)(ciboy-1)/n,(float)1/n);
            glVertex3f ((float)(cibox)/n,(float)(ciboy-1)/n,(float)1/n);
            
            
            glVertex3f ((float)(cibox-1)/n,(float)ciboy/n,0.0f);
            glVertex3f ((float)(cibox-1)/n,(float)(ciboy-1)/n,0.0f);
            glVertex3f ((float)(cibox-1)/n,(float)(ciboy-1)/n,(float)1/n);
            glVertex3f ((float)(cibox-1)/n,(float)ciboy/n,(float)1/n);
            
            
     glEnd ();
     glPopMatrix ();
     
     
     }


void griglia1(){
               glPushMatrix ();

                        glBegin (GL_QUADS);     
            glColor3f (0.1f, 0.1f, 0.1f);   
            glVertex2f (-1,-1);
            glVertex2f (1,-1);
            glVertex2f (1,1);
            glVertex2f (-1,1);

     glEnd ();
            glPopMatrix ();
     
     }

void griglia(){

               glPushMatrix ();

     int i;
     
     for(i=-n;i<n+1;i++){
                        glBegin (GL_LINES);     
            glColor3f (0.1f, 0.1f, 0.1f);   glVertex2f ((float)i/n,1);
               glVertex2f ((float)i/n,-1);
              glVertex2f (-1,(float)i/n);
              glVertex2f (1,(float)i/n);
            }
     glEnd ();
            glPopMatrix ();
     }

