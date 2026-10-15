#include "ff.h"
static void THISCALL fn538340(u8* s){
 if(!vcall<u8>(s,0x1a8))return;
 u8* p=vcall<u8*>(s,0x190);if(!p)return;
 while(G(u32,p)!=0x10000){
  u32 op=G(u32,p);
  if(op==0x1100)G(u8,0x711b70)=1;
  else if(op==0x1001||op==0x1002){
   u8* e=vcall<u8*>(G(void*,G(u8*,0x70039c)+0x9b),0x60,G(u32,p+8));
   if(e){
    if(op==0x1001){u32 dt=G(u32,G(u8*,0x70039c)+0x1c)-G(u32,e+0x6c);float t=float((s32)dt)*G(float,0x6785e4);G(float,e+0x74)=t;G(float,e+0x70)=(G(float,e+0x70)+t)-G(float,e+0x78);}
    else if(!(G(u8,e+0x40)&8)&&G(u32,e+0x2c)!=1&&G(u32,e+4)!=7)G(u32,e+4)=11;
   }
  }else if(!vcall<u8>(s,0x198,p)){
   void* log=vcall<void*>(G(void*,0x700390),0x20,0x6a1e2cu,0xba4u);
   typedef void(*Print)(void*,u32,u32,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x6a2440u,G(u32,p),G(u32,p+4));
   typedef void(*Assert)();G(Assert,0x7003b0)();
  }
  p+=G(u32,p+4);
 }
 p=vcall<u8*>(s,0x190);if(p)G(u32,p)=0x10000;
 vcall<void>(s,0x1a4);
}
PCREG(538340,fn538340);
