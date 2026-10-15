#include "ff.h"
static void THISCALL fn449a00(u8* s,float time){
 u8* list=*(u8**)(s+0x1c);u32 it[3];
 if(list){vcall<void>(list,0x4c,it);u32 id=vcall<u32>(*(u8**)(s+0x1c),0x5c,it);
  while(it[0]){u8* target=vcall<u8*>(*(u8**)(G(u8*,0x70039c)+0x9b),0x58,id);if(target)vcall<void>(target,0x230,time);id=vcall<u32>(*(u8**)(s+0x1c),0x5c,it);}}
 vcall<void>(s,0x238);
 u8 payload[60];u8* cb=*(u8**)(*(u8**)(G(u8*,0x70039c)+0x1aa3)+0x18);
 vcall<void>(cb,0x88,*(u32*)(*(u8**)(s+8)+0x6c),payload);
 *(float*)(payload+20)=time;
 cb=*(u8**)(*(u8**)(G(u8*,0x70039c)+0x1aa3)+0x18);
 vcall<void>(cb,0xa8,*(u32*)(*(u8**)(s+8)+0x6c),payload);
 vcall<void>(s,0x220,(u32)1);
}
PCREG(449a00,fn449a00);
