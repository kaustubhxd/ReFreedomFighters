#include "ff.h"
extern "C" void FASTCALL ext_430910(u8*,u8**);
extern "C" void FASTCALL ext_430960(u8*,u8**);
static inline u8*&p13(u8*p,u32 o){return *(u8**)(p+o);}
static void rot13(u8*x,u8**root,bool left){
 u32 a=left?9:5,b=left?5:9;u8*y=p13(x,a);p13(x,a)=p13(y,b);if(p13(y,b))p13(p13(y,b),1)=x;
 p13(y,1)=p13(x,1);if(x==*root)*root=y;else if(x==p13(p13(x,1),left?5:9))p13(p13(x,1),left?5:9)=y;else p13(p13(x,1),left?9:5)=y;
 p13(y,b)=x;p13(x,1)=y;
}
static u8* FASTCALL erase13(u8*z,u8**root,u8**minimum,u8**maximum){
 u8*y=z,*x,*xp;
 if(!p13(y,5))x=p13(y,9);else if(!p13(y,9))x=p13(y,5);else{y=p13(y,9);while(p13(y,5))y=p13(y,5);x=p13(y,9);}
 if(y!=z){
  p13(p13(z,5),1)=y;p13(y,5)=p13(z,5);
  if(y!=p13(z,9)){xp=p13(y,1);if(x)p13(x,1)=p13(y,1);p13(p13(y,1),5)=x;p13(y,9)=p13(z,9);p13(p13(z,9),1)=y;}else xp=y;
  if(*root==z)*root=y;else if(p13(p13(z,1),5)==z)p13(p13(z,1),5)=y;else p13(p13(z,1),9)=y;
  p13(y,1)=p13(z,1);u8 color=*y;*y=*z;*z=color;y=z;
 }else{
  xp=p13(y,1);if(x)p13(x,1)=p13(y,1);
  if(*root==z)*root=x;else if(p13(p13(z,1),5)==z)p13(p13(z,1),5)=x;else p13(p13(z,1),9)=x;
  if(*minimum==z){if(!p13(z,9))*minimum=p13(z,1);else{u8*t=x;while(p13(t,5))t=p13(t,5);*minimum=t;}}
  if(*maximum==z){if(!p13(z,5))*maximum=p13(z,1);else{u8*t=x;while(p13(t,9))t=p13(t,9);*maximum=t;}}
 }
 if(*y!=0){
  while(x!=*root && (!x || *x==1)){
   if(x==p13(xp,5)){
    u8*w=p13(xp,9);
    if(*w==0){*w=1;*xp=0;rot13(xp,root,true);w=p13(xp,9);}
    if((!p13(w,5)||*p13(w,5)==1)&&(!p13(w,9)||*p13(w,9)==1)){*w=0;x=xp;xp=p13(xp,1);}
    else{
     if(!p13(w,9)||*p13(w,9)==1){if(p13(w,5))*p13(w,5)=1;*w=0;ext_430960(w,root);w=p13(xp,9);}
     *w=*xp;*xp=1;if(p13(w,9))*p13(w,9)=1;ext_430910(xp,root);break;
    }
   }else{
    u8*w=p13(xp,5);
    if(*w==0){*w=1;*xp=0;rot13(xp,root,false);w=p13(xp,5);}
    if((!p13(w,9)||*p13(w,9)==1)&&(!p13(w,5)||*p13(w,5)==1)){*w=0;x=xp;xp=p13(xp,1);}
    else{
     if(!p13(w,5)||*p13(w,5)==1){if(p13(w,9))*p13(w,9)=1;*w=0;ext_430910(w,root);w=p13(xp,5);}
     *w=*xp;*xp=1;if(p13(w,5))*p13(w,5)=1;ext_430960(xp,root);break;
    }
   }
  }
  if(x)*x=1;
 }
 return y;
}
PCREG(430620,erase13);
