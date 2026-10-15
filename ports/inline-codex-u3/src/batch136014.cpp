#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static void THISCALL fn502ba0(u8*s,u8*arg){
 void*list=*(void**)(arg+4);u32 id=*(u32*)ext_5003d0(list,0);u8*value=ext_5003d0(list,1);void*resource=0;
 if(value[4]==3)resource=*(void**)value;
 else if(value[4]==4)resource=vcall<void*>(*(void**)value,0x34);
 else{
  void*log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);typedef void(*Print)(void*,u32,u32);(*(Print*)(*(u8**)log+0x2c))(log,0x69c6b0u,0x69c9b0u);
  typedef void(*Assert)();G(Assert,0x7003b0)();
 }
 u32 values[4];for(u32 i=0;i<4;i++)values[i]=*(u32*)ext_5003d0(list,i+2);
 void*target=*(void**)(s+0xc);u32 result=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x114,resource,0u,0x69ca10u,0x127u,values);
 vcall<void>(target,0x12c,id,result&0xffffu);
}
PCREG(502ba0,fn502ba0);
