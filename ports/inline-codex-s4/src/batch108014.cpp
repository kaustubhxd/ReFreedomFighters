#include "s4_mem.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void* THISCALL ext_5002f0(void*,u32);
extern "C" void THISCALL ext_50d7b0(void*,const u32*);
static void bad14(){
 void* log=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0u,0x111u);
 typedef void(*Print)(void*,u32,u32);
 ((Print)s4r(s4p(log,0),0x2c))(log,0x69c6b0u,0x69c9b0u);
 typedef void(*Assert)();((Assert)G(u32,0x7003b0))();
}
extern "C" void STDCALL f50a860(void* input){
 void* wrapper=vcall<void*>(s4p(input,0xc),0,0x67a14cu,0u);
 void* source=ext_5003d0(s4p(input,4),0);
 u32 ref=0;u8 type=*((u8*)source+4);
 if(type==3)ref=s4r(source,0);
 else if(type==4)ref=vcall<u32>(s4p(source,0),0x34);
 else bad14();
 void* service=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x134);
 u32 object=vcall<u32>(service,0x9c,ref,2u);
 vcall<void>(wrapper,0x30,object);
 void* dest=ext_5003d0(s4p(input,8),0);
 type=*((u8*)dest+4);
 if(type==0||type==4){
  if(type==4)vcall<void>(s4p(dest,0),0x28);
  s4w(dest,0,vcall<u32>(wrapper,0x24));*((u8*)dest+4)=4;
 }
 vcall<void>(wrapper,0x28);
}
PCREG(50a860,f50a860);
extern "C" void STDCALL f50c450(void* input){
 void* value=ext_5003d0(s4p(input,8),0);ext_5002f0(value,0);
 value=ext_5003d0(s4p(input,4),0);
 void* item=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,s4r(value,0));
 if(!item){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69d420u,0x217u);
  typedef void(*Print)(void*,u32);((Print)s4r(s4p(log,0),0x2c))(log,0x69d754u);
  return;
 }
 if(!(u8)vcall<u32>(item,0x1e0,0x1007d1u)){
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x69d420u,0x21cu);
  typedef void(*Print)(void*,u32,u32);((Print)s4r(s4p(log,0),0x2c))(log,0x69d5fcu,s4r(item,4));
  return;
 }
 void* table=s4p(G(void*,0x70039c),0x9b);
 typedef u32(THISCALL *OwnerLookup)(void*,u32);
 void* methods=s4p(table,0);
 u32 owner=vcall<u32>(item,0x2f4);
 OwnerLookup lookup=(OwnerLookup)s4r(methods,0x4c);
 u32 id=lookup(s4p(G(void*,0x70039c),0x9b),owner);
 value=ext_5003d0(s4p(input,8),0);ext_50d7b0(value,&id);
}
PCREG(50c450,f50c450);
