#include "s4_mem.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
static void err20(u32 line,u32 message){
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x69db34u,line);
 typedef void(*Print)(void*,u32);((Print)s4r(s4p(log,0),0x2c))(log,message);
}
static void* resolve20(u32 ref){return vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,ref);}
extern "C" void STDCALL f50dc60(void* input){
 void* dest=resolve20(s4r(ext_5003d0(s4p(input,4),0),0));
 void* source=resolve20(s4r(ext_5003d0(s4p(input,4),1),0));
 if(dest&&source){
  u32 matrix[9],pos[3];vcall<void>(source,0x80,matrix,pos);vcall<void>(dest,0x7c,matrix,pos);
 }else{
  if(!dest)err20(0x197,0x69dbbc);
  if(!source)err20(0x198,0x69dbe0);
 }
}
PCREG(50dc60,f50dc60);
extern "C" void THISCALL f558d90(void* self,void* input){
 u32 targetpos[3]={0,0x42c80000,0};
 void* target=resolve20(s4r(ext_5003d0(s4p(input,4),0),0));
 if(!target){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x6a5eb0u,0x215u);
  u32 name=s4r(s4p(self,0x1c),4);if(!name)name=0x67c8e8;
  typedef void(*Print)(void*,u32,u32);((Print)s4r(s4p(log,0),0x2c))(log,0x6a5f2cu,name);return;
 }
 vcall<void>(target,0x84,targetpos);
 u32 start[3]={0,0,0};vcall<void>(s4p(self,0x1c),0x84,start);
 void* sys=G(void*,0x70039c);void* renderer=s4p(s4p(sys,0x9b),0xadc);void* methods=s4p(renderer,0);
 u32 value=vcall<u32>(sys,0x1bc,0x6a5eb0u,0x22au);
 typedef void(THISCALL *Draw)(void*,void*,void*,u32);
 ((Draw)s4r(methods,0x218))(s4p(s4p(G(void*,0x70039c),0x9b),0xadc),start,targetpos,0u-value);
}
PCREG(558d90,f558d90);
