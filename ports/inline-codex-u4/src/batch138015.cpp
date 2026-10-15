#include "ff.h"
extern "C" void THISCALL ext_572850(void*,u32,float);
static void resetTransition(u8* s){*(u32*)(s+0x872)=*(u32*)(s+0x44);*(u32*)(s+0x86e)=0;*(u32*)(s+0x864)=*(u32*)(s+0x868);}
static u32 THISCALL dispatchTransition(u8* s,u16 key,u8* value){
 if(key==*(u16*)(s+0x48)){
  if(value){resetTransition(s);ext_572850(s,*(u32*)(value+4),*(float*)value);}
  return 1;
 }
 if(key==*(u16*)(s+0x4a)){
  resetTransition(s);float duration=(float)*(s32*)value/G(float,0x685270);
  void* strings=*(void**)(*(u8**)(G(u8*,0x70039c)+0x9b)+0xae4);
  u32 id=vcall<u32>(strings,0,0x677b5au,*(u32*)(value+4));
  ext_572850(s,id,duration);return 0;
 }
 if(key==*(u16*)(s+0x4c)){
  s[0x86c]=0;void* actor=*(void**)(s+0x872);if(actor)vcall<void>(actor,0xbc,1u);
 }else if(key==*(u16*)(s+0x4e)){
  if(*(u32*)(value+8) && *(u32*)(value+0xc)){
   *(u32*)(s+0x872)=*(u32*)(value+8);*(u32*)(s+0x86e)=*(u32*)(value+0xc);*(u32*)(s+0x864)=*(u32*)(value+0x10);
   ext_572850(s,*(u32*)(value+4),*(float*)value);
  }
 }
 return 0;
}
PCREG(5725b0,dispatchTransition);
