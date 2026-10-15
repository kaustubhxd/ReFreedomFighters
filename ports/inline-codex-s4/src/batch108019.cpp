#include "s4_mem.h"
extern "C" void THISCALL f4732a0(void* self,u32 ref){
 void* target=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,ref);
 void* current=vcall<void*>(self,0x504);void* other=vcall<void*>(self,0x500);
 if(target==current)return;
 if(target&&target==other){vcall<void>(self,0x45c,11u,0u);return;}
 if(current){
  void* state=vcall<void*>(current,0x2e8);
  u32 command;
  if(!vcall<u32>(state,0x308))command=6;
  else{state=vcall<void*>(current,0x2e8);command=(vcall<u32>(state,0x300)==2||other)?10:11;}
  vcall<void>(self,0x45c,command,0u);
 }
 if(ref)vcall<void>(self,0x45c,8u,ref);
}
PCREG(4732a0,f4732a0);
extern "C" void THISCALL f4afb50(void* self,u32 arg){
 void* target=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,s4r(self,0x4c));
 if(!target)return;
 u32 sender=vcall<u32>(s4p(G(void*,0x70039c),0x9b),0x4c,s4r(self,0x44));
 if(*((u8*)self+0x56)&&(u8)vcall<u32>(target,0x1e0,0x800001au)){
  if(!s4p(target,0x18))return;
  u32 it[3];vcall<void>(s4p(target,0x18),0x4c,it);
  u32 id=vcall<u32>(s4p(target,0x18),0x5c,it);
  while(it[0]){
   u32 from=*((u8*)self+0x57)?sender:id;
   vcall<void>(s4p(self,0x44),0x12c,id,arg,from);
   id=vcall<u32>(s4p(target,0x18),0x5c,it);
  }
 }else{
  if(!*((u8*)self+0x57))sender=s4r(self,0x48);
  vcall<void>(s4p(self,0x44),0x12c,s4r(self,0x4c),arg,sender);
 }
}
PCREG(4afb50,f4afb50);
