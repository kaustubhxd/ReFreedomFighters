#include "s4_mem.h"
extern "C" void ext_634273(void*,u32);
extern "C" void THISCALL f4cb720(void* self){
 if(s4p(self,0x54)){
  u32 it[3];vcall<void>(s4p(self,0x54),0x4c,it);
  void* entry=vcall<void*>(s4p(self,0x54),0x64,it);
  while(entry){
   if(*((u8*)entry+4)){
    void* actor=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,s4r(entry,0));
    if(actor)vcall<void>(actor,0x130,actor,(u32)s4r16(self,0x52),s4r(self,0x44));
   }
   entry=vcall<void*>(s4p(self,0x54),0x64,it);
  }
 }
 if(s4p(self,0x54))vcall<void>(s4p(self,0x54),0,1u);
 if(s4p(self,0x68)){
  u32 i=0;
  while(i!=s4r(self,0x64)){ext_634273(s4p(s4p(self,0x68),4*i),0x20);i++;}
  ext_634273(s4p(self,0x68),4);
 }
 if(s4p(self,0x6c))ext_634273(s4p(self,0x6c),4);
}
PCREG(4cb720,f4cb720);
extern "C" u32 FASTCALL f4dac50(void* self,u32* output){
 u32 count=0;
 void* node=self;
 bool special=(s4r(node,0x3c)&0x40040000)!=0;
 if(special){
  while(!(s4r(node,0x3c)&0x40000)){
   node=s4p(node,0x50);void* actor=s4p(node,0x54);
   u32 flags=vcall<u32>(actor,0x2a8);
   if(!(flags&0x2000000)){output[count]= (u32)actor;return count+1;}
   if(!(flags&0x1000000))output[count++]=(u32)actor;
  }
  u32 handle=s4r16(node,0x5c);
  if(handle){
   void* table=s4p(G(void*,0x70039c),0x9b);
   void* record=vcall<void*>(s4p(table,8),0x5c,handle);
   if(record&&*((u8*)record+0x1c))output[count++]=s4r(record,0);
  }
  return count;
 }
 node=s4p(node,0x50);
 for(;;){
  void* actor=s4p(node,0x54);u32 flags=vcall<u32>(actor,0x2a8);
  if(!(flags&0x2000000)){output[count]=(u32)actor;return count+1;}
  if(!(flags&0x1000000))output[count++]=(u32)actor;
  node=s4p(node,0x50);if(!node)return count;
 }
}
PCREG(4dac50,f4dac50);
