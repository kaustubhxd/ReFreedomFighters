#include "ff.h"
extern "C" void THISCALL ext_516620(u8*,u32*);
static void THISCALL fn529020(u8* s){
 for(s32 i=0;i<*(s32*)(s+0x8d);++i){
  u32 v[3];for(u32 j=0;j<3;++j)v[j]=*(u32*)(s+0xe91+307*i+4*j);
  vcall<void>(*(u8**)(s+0x89),0x84,v);ext_516620(s+0x95+222*i,v);
 }
 for(s32 i=0;i<*(s32*)(s+0x91);++i){
  u32 v[3];for(u32 j=0;j<3;++j)v[j]=*(u32*)(s+0x1829+307*i+4*j);
  vcall<void>(*(u8**)(s+0x89),0x84,v);ext_516620(s+0x785+222*i,v);
 }
}
PCREG(529020,fn529020);
