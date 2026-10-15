#include "ff.h"
static void THISCALL fn4c3070(u8* s){
 if(s[0x51]){
  float random=vcall<float>(G(u8*,0x70039c),0x1c0,(u32)0x693c40,(u32)0xaf6);
  if(!(*(float*)(s+0x6d)>=random)){
   u8* parent=*(u8**)(s+0x44);if(parent)vcall<void>(parent,0x210,(u32)1);return;
  }
  float v=*(float*)(s+0x59)*G(float,0x67d164);v=v*G(float,0x67d9fc);
  u8* data=*(u8**)(*(u8**)(s+0x44)+0x18);*(float*)(data+0x78)=v;s[0x52]=1;
  if(*(float*)(s+0x59)==0.f)*(u32*)(data+0x84)=0;
 }else{
  vcall<void>(s,0x84);s[0x50]=0;vcall<void>(s,0x68,(u32)0x10,(u32)0);
 }
 if(*(float*)(s+0x65)!=0.f){u8* parent=*(u8**)(s+0x44);if(parent)*(u32*)(*(u8**)(parent+0x18)+0x84)=0;}
}
PCREG(4c3070,fn4c3070);
