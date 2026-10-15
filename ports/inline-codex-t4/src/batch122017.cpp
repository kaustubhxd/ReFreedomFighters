#include "ff.h"
extern "C" void THISCALL ext_4c3740(u8*,u8*);
static void THISCALL fn4c3510(u8* s){
 float elapsed=*(float*)(G(u8*,0x70039c)+0x48)+*(float*)(s+0x4c);*(float*)(s+0x4c)=elapsed;
 if(elapsed>*(float*)(s+0x50)){
  *(u32*)(s+0x54)=*(u32*)(s+0x5c);
  *(float*)(s+0x5c)=vcall<float>(G(u8*,0x70039c),0x1c0,(u32)0x693ec0,(u32)0xd4);
  *(u32*)(s+0x4c)=0;
 }
 float fraction=*(float*)(s+0x4c)/(*(float*)(s+0x50));
 float delta=*(float*)(s+0x5c)-*(float*)(s+0x54);delta=delta*fraction;delta=delta+*(float*)(s+0x54);*(float*)(s+0x58)=delta;
 u8* list=*(u8**)(s+0x48);if(!list)return;
 u32 it[3];vcall<void>(list,0x4c,it);
 u32 id=vcall<u32>(*(u8**)(s+0x48),0x5c,it);
 while(it[0]){
  u8* sys=G(u8*,0x70039c);u8* obj=vcall<u8*>(*(u8**)(sys+0x9b),0x58,id);
  u8* node=*(u8**)(obj+8);if(*(u32*)(node+0x3c)&0x1000)ext_4c3740(s,node);
  id=vcall<u32>(*(u8**)(s+0x48),0x5c,it);
 }
}
PCREG(4c3510,fn4c3510);
