#include "ff.h"
extern "C" u8 THISCALL ext_4db9a0(void*,u32);
static void THISCALL propagateTransform(u8* s){
 float matrix[9],pos[3];
 vcall<void>(*(void**)(s+0x44),0x80,matrix,pos);
 if(matrix[6]!=G(float,0x678858)||matrix[4]!=G(float,0x678858)||matrix[2]!=G(float,0x678858)||pos[0]!=0.f||pos[1]!=0.f||pos[2]!=0.f)return;
 u32 iter[2];void* tab=s+0x48;
 vcall<void>(tab,0x4c,iter);
 u32 id=vcall<u32>(tab,0x5c,iter);
 while(iter[0]){
  u8* actor=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x9b),0x58,id);
  if(vcall<u8>(actor,0x1e0,0x100001u)){
   u8* node=*(u8**)(actor+8);
   while(node){
    if(ext_4db9a0(node,0x100021))vcall<void>(*(void**)(node+0x54),0x34c,*(u32*)(*(u8**)(s+0x44)+8));
    vcall<void>(actor,0x29c,&node);
   }
  }
  id=vcall<u32>(tab,0x5c,iter);
 }
 vcall<void>(s,0x58);
}
PCREG(4c5a10,propagateTransform);
