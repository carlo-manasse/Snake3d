
#include "serpente.h"

void ins_dopo(pnodo &testa,pnodo &coda,int x,int y){
        
     pnodo nuovo;
     nuovo=new nodo;
     nuovo->next=0;
     nuovo->p.x=x;
     nuovo->p.y=y;
     
     if(testa==0){
     testa=nuovo;
     coda=nuovo;
     }
     
     else{
     coda->next=nuovo;
     coda=nuovo;
     nuovo->next=testa;
     }
     
     }     
     

bool controllalista(pnodo &testa,int x,int y)
{
     bool esiste=false;
     pnodo pp=testa->next;
     do{
           if(pp->p.x==x&&pp->p.y==y)
           esiste=true;
           pp=pp->next;
           }while(pp!=testa);
           
     return esiste;
     }
       

void updatelista(pnodo &testa,pnodo &coda,int x,int y){
     
     coda->p.x=x;
     coda->p.y=y;
     testa=coda;
     
     do
     coda=coda->next;
     while(coda->next!=testa);
     
     }

void reset(serpente sn){
     do{
                 pnodo pp=sn.testa;
                 sn.testa=sn.testa->next;
                 delete(pp);      
                 }  while(sn.testa!=sn.coda);
     
     delete(sn.coda);
     sn.testa=0;
     sn.coda=0;
     }
