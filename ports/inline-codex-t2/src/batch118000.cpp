#include "ff.h"
extern "C" void THISCALL update_children(u8* self, float dt) {
 u32 it[3];
 void* list=*(void**)(self+0x1c);
 if(list) {
  vcall<void>(list,0x4c,it);
  u32 id=vcall<u32>(*(void**)(self+0x1c),0x5c,it);
  while(it[0]) {
   u8* sys=G(u8*,0x70039c);
   void* child=vcall<void*>(*(void**)(sys+0x9b),0x58,id);
   if(child) vcall<void>(child,0x230,dt);
   id=vcall<u32>(*(void**)(self+0x1c),0x5c,it);
  }
 }
 vcall<void>(self,0x238);
 u32 state[9];
 u8* sys=G(u8*,0x70039c);
 void* mgr=*(void**)(*(u8**)(sys+0x1aa3)+0x18);
 vcall<void>(mgr,0x80,*(u32*)(*(u8**)(self+8)+0x6c),state);
 state[5]=fbits(dt);
 sys=G(u8*,0x70039c);
 mgr=*(void**)(*(u8**)(sys+0x1aa3)+0x18);
 vcall<void>(mgr,0x98,*(u32*)(*(u8**)(self+8)+0x6c),state);
 vcall<void>(self,0x220,1u);
}
PCREG(449840,update_children);
