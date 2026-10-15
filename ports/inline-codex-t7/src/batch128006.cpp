#include "ff.h"
extern "C" void THISCALL ext_49da90(void*);
extern "C" void THISCALL ext_49db30(void*);
extern "C" void *ext_634d22(void*,const void*,u32);
static inline u32 &w6(u8*p,u32 o){return *(u32*)(p+o);}
static inline u8* lookup6(u32 id){return vcall<u8*>(G(void*,0x70038c),0xcc,id);}
static u32 key6(u8*p){
 if(!p)return 0;
 u32 kind=0;
 if(w6(p,0x1c)){
  u8*entry=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,w6(p,0x1c));
  if(entry)kind=*(u16*)(*(u8**)(entry+0xc)+0x1d);
 }else kind=*(u16*)(*(u8**)(p+0x40)+0x1d);
 return (kind<<20)|w6(p,0x20);
}
static bool append6(u8*self,u32 id,u32 &count){
 u8*p=lookup6(id);
 if((p[0x18]&0x10)&&!(w6(p,0x3c)&0x10)){
  w6(p,0x3c)|=0x10;((u32*)w6(self,4))[count++]=id;return true;
 }return false;
}
static void THISCALL merge6(u8*self){
 ext_49da90(self);ext_49db30(self);
 if(!w6(self,0x14))return;
 u32 n=w6(self,0x10);u32 *old=(u32*)__builtin_alloca(n*4);
 ext_634d22(old,(void*)w6(self,4),n*4);
 u32 oi=0,ni=0,out=0;
 if(n){
  u8*pn=lookup6(((u32*)w6(self,8))[0]);u8*po=lookup6(old[0]);
  u32 rn=vcall<u32>(self,0xc,pn),ro=vcall<u32>(self,0xc,po);
  u32 kn=key6(pn),ko=key6(po);
  while(ni!=w6(self,0x14)){
   if(out==w6(self,0x1c))return;
   if(rn<ro || (rn==ro && kn<ko)){
    u32 id=((u32*)w6(self,8))[ni++];
    if(ni<w6(self,0x14)){
     pn=lookup6(((u32*)w6(self,8))[ni]);rn=vcall<u32>(self,0xc,pn);kn=key6(pn);
    }
    append6(self,id,out);
   }else{
    ((u32*)w6(self,4))[out++]=old[oi++];
    if(oi==w6(self,0x10))ro=0xffffffff;
    else{po=lookup6(old[oi]);ro=vcall<u32>(self,0xc,po);ko=key6(po);}
   }
  }
  u32 remain=w6(self,0x10)-oi;
  if(remain){ext_634d22((u32*)w6(self,4)+out,old+oi,remain*4);out+=remain;}
 }
 while(ni!=w6(self,0x14)){u32 id=((u32*)w6(self,8))[ni++];append6(self,id,out);}
 n=w6(self,0x10);
 if(out>n){if(G(void*,0x70038c))vcall<void>(G(void*,0x70038c),0x2c,0x68ee90u,n*4,(out-n)*4);}
 else if(out<n){if(G(void*,0x70038c))vcall<void>(G(void*,0x70038c),0x30,0x68ee90u,out*4,(n-out)*4);}
 w6(self,0x10)=out;w6(self,0x14)=0;
}
PCREG(49d6c0,merge6);
