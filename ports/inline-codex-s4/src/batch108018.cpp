#include "s4_mem.h"
extern "C" void THISCALL ext_4e3180(void*);
extern "C" void FASTCALL ext_43e8e0(void*,u32,u32);
extern "C" void THISCALL ext_4e4520(void*,void*,u32,void*);
extern "C" u8 FASTCALL ext_442420(u32,u32,u32,u32,u32,u32,u32);
extern "C" u8 THISCALL f4426a0(void* self,u32 receiver,u32 unused,u32 a,u32 b,u32 c,u32 d,u32 e){
 if(s4r(s4p(self,8),0x3c)&0x400)return 0;
 void* source=vcall<void*>(self,0x314);if(!source)return 0;
 u8 context[0x6c];u32 entries[2048],transform[3];
 ext_4e3180(context);
 s4w(context,4,0x4e32e0);s4w(context,0x5c,(u32)entries);s4w(context,0x60,(u32)transform);s4w(context,0x64,0);s4w(context,0x68,d);
 ext_43e8e0(transform,a,b);
 ext_4e4520(source,context,a,transform);
 u8 result=0;
 for(u32 i=0;i<s4r(context,0x64);i++)result|=ext_442420(receiver,entries[i],a,b,d,e,c);
 return result;
}
PCREG(4426a0,f4426a0);
extern "C" void THISCALL f4569b0(void* self){
 void* log=vcall<void*>(G(void*,0x70039c),0x190);
 typedef void(*Print3)(void*,u32,u32);
 ((Print3)s4r(s4p(log,0),0x188))(log,0x682e94,0x95);
 for(u32 i=0;i<256;i++){
  u32 ref=s4r(self,0x1d+8*i);if(!ref)return;
  void* actor=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,ref);
  if(s4r(actor,0x51)){
   u32 index=s4r(self,0x21+8*i),total=0,bytes=0;
   if(index){
    u32 base=s4r(self,0x81d),record=base+(index-1)*0x94c;
    while(record){total+=s4r((void*)record,4);bytes+=0x40;index=s4r((void*)record,0);if(!index)break;record=base+(index-1)*0x94c;}
   }
   log=vcall<void*>(G(void*,0x70039c),0x190);
   u32 name=s4r(actor,4);if(!name)name=0x67c8e8;
   typedef void(*Print5)(void*,u32,u32,u32,u32);
   ((Print5)s4r(s4p(log,0),0x188))(log,0x682ea8,bytes,total,name);
  }
 }
}
PCREG(4569b0,f4569b0);
