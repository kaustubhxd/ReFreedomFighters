#include "ff.h"
static void THISCALL read_resolved_environment(u8* self) {
  u8* table=G(u8*,(u8*)g_pSysInterface+0x9b);
  u8* reader=(u8*)vcall<u32>(table,0x138);
  u32 id=0;
  vcall<void>(reader,0x88,0x681320,(u32)&id);
  u8* resolved=(u8*)vcall<u32>(table,0x58,id);
  G(u32,self+0x114)=(u32)resolved;
  reader=(u8*)vcall<u32>(table,0x138);
  u32 value=0; vcall<void>(reader,0x84,0x6954e8,(u32)&value);
  G(float,self+0x118)=bitsf(value);
  reader=(u8*)vcall<u32>(table,0x138);
  value=0; vcall<void>(reader,0x84,0x6954f8,(u32)&value);
  G(float,self+0x11c)=bitsf(value);
  reader=(u8*)vcall<u32>(table,0x138);
  u32* xyz=(u32*)vcall<u32>(reader,0x9c,0x69c218,4u);
  float scale=G(float,0x697890);
  for(u32 j=0;j<3;j++) G(float,self+0x120+4*j)=(float)(s32)xyz[j]*scale;
  u32 mapped=G(u32,G(u8*,self+0x114)+0x676);
  u8* resource=(u8*)vcall<u32>(table,0x58,mapped);
  G(u32,self+0x130)=vcall<u32>(resource,0x100,0x67d9e8);
}
PCREG(5de260,read_resolved_environment);
