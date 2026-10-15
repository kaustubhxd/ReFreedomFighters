#include "ff.h"
extern "C" void THISCALL ext_6352f0(u8*, u32*);
extern "C" float THISCALL ext_4e5e80(u32*);
extern "C" u16 THISCALL ext_4e5e40(u32*);
extern "C" u32 THISCALL ext_4e5e60(u32*);
static u8 THISCALL read_entity_fields(u8* self, u8* stream) {
  u32 value = 0;
  G(u32,self+4) &= ~0x40u;
  ext_6352f0(self,&value);
  G(float,self+0x4a) = ext_4e5e80(&value);
  G(u16,self+0x52) = ext_4e5e40(&value);
  G(u8,self+0x54) = ext_4e5e60(&value) != 0;
  G(float,self+0x4e) = ext_4e5e80(&value);
  vcall<u32>(stream,0x40,&value);
  u8* table = G(u8*,(u8*)g_pSysInterface+0x9b);
  G(u32,self+0x55) = vcall<u32>(table,0x58,value);
  vcall<u32>(stream,0x40,&value);
  G(u32,self+0x59) = vcall<u32>(table,0x58,value);
  vcall<u32>(stream,0x40,&value);
  G(u32,self+0x5d) = vcall<u32>(table,0x58,value);
  vcall<u32>(stream,0x40,&value);
  G(u32,self+0x61) = vcall<u32>(table,0x58,value);
  return 1;
}
PCREG(5d3660,read_entity_fields);
