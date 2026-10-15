#include "ff.h"
static void THISCALL notify_children(u8* me,float value){
 void* list=*(void**)(me+0x1c);
 if(list){
  u32 it[3];vcall<void>(list,0x4c,it);u32 id=vcall<u32>(*(void**)(me+0x1c),0x5c,it);
  while(it[0]){
   void* obj=vcall<void*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,id);
   if(obj)vcall<void>(obj,0x230,value);
   id=vcall<u32>(*(void**)(me+0x1c),0x5c,it);
  }
 }
 vcall<void>(me,0x238);
 u32 state[15];
 void* manager=*(void**)(*(u8**)(G(u8*,0x70039c)+0x1aa3)+0x18);
 vcall<void>(manager,0x88,*(u32*)(*(u8**)(me+8)+0x6c),state);
 state[5]=fbits(value);
 manager=*(void**)(*(u8**)(G(u8*,0x70039c)+0x1aa3)+0x18);
 vcall<void>(manager,0xa8,*(u32*)(*(u8**)(me+8)+0x6c),state);
 vcall<void>(me,0x220,1);
}
PCREG(449a00,notify_children);
