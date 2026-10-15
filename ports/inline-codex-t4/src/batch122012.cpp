#include "ff.h"
static void THISCALL fn499fb0(u8* dst,u8* src){
 vcall<void>(dst,0xc,vcall<u32>(src,0x14));
 u32 it[3];vcall<void>(src,0x4c,it);
 u8* p=vcall<u8*>(src,0x64,it);
 while(p){
  float value=vcall<float>(src,0x9c,p);
  vcall<void>(dst,0x3c,*(u32*)p);
  vcall<void>(dst,0x4c,value);
  p=vcall<u8*>(src,0x64,it);
 }
}
PCREG(499fb0,fn499fb0);
