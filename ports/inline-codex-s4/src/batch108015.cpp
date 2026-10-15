#include "s4_mem.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void* THISCALL ext_5002f0(void*,u32);
static u32 ref15(void* source){
 u8 type=*((u8*)source+4);
 if(type==3)return s4r(source,0);
 if(type==4)return vcall<u32>(s4p(source,0),0x34);
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);
 typedef void(*Print)(void*,u32,u32);((Print)s4r(s4p(log,0),0x2c))(log,0x69c6b0u,0x69c9b0u);
 typedef void(*Assert)();((Assert)G(u32,0x7003b0))();return 0;
}
static void* manager15(){return vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x138);}
extern "C" void STDCALL f50d9e0(void* input){
 u32 ref=ref15(ext_5003d0(s4p(input,4),0)),old=0;
 vcall<void>(manager15(),0x88,ref,&old);
 void* manager=manager15();
 void* delta=ext_5003d0(s4p(input,4),1);
 vcall<void>(manager,0x5c,ref,s4r(delta,0)+old,2u);
 void* dest=ext_5003d0(s4p(input,8),0);ext_5002f0(dest,old);
}
PCREG(50d9e0,f50d9e0);
extern "C" void STDCALL f50f4d0(void* input){
 void* wrapper=vcall<void*>(s4p(input,0xc),0,0x67a14cu,0u);
 u32 ref=ref15(ext_5003d0(s4p(input,4),0));
 u32 object=vcall<u32>(manager15(),0x9c,ref,2u);
 vcall<void>(wrapper,0x30,object);
 void* dest=ext_5003d0(s4p(input,8),0);u8 type=*((u8*)dest+4);
 if(type==0||type==4){
  if(type==4)vcall<void>(s4p(dest,0),0x28);
  s4w(dest,0,vcall<u32>(wrapper,0x24));*((u8*)dest+4)=4;
 }
 vcall<void>(wrapper,0x28);
}
PCREG(50f4d0,f50f4d0);
