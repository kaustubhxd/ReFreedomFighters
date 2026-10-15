#include "ff.h"
static u8 THISCALL serialize_extended_fields(u8* self,u8* stream) {
  G(u32,self+4)&=~0x40u;
  vcall<u32>(stream,0x40,(u32)G(u16,self+0x58));
  vcall<u32>(stream,0x40,(u32)G(u16,self+0x5a));
  vcall<u32>(stream,0x4c,G(float,self+0x1b4));
  vcall<u32>(stream,0x4c,G(float,self+0x1b8));
  vcall<u32>(stream,0x4c,G(float,self+0x1bc));
  vcall<u32>(stream,0x60,(u32)G(u8,self+0x1d8));
  vcall<u32>(stream,0x60,(u32)G(u8,self+0x1da));
  vcall<u32>(stream,0x60,(u32)G(u8,self+0x1d9));
  vcall<u32>(stream,0x60,(u32)G(u8,self+0x1db));
  vcall<u32>(stream,0x60,(u32)G(u8,self+0x1dc));
  vcall<u32>(stream,0x4c,G(float,self+0x1c0));
  vcall<u32>(stream,0x4c,G(float,self+0x1c4));
  vcall<u32>(stream,0x6c,(u32)(self+0x5c));
  vcall<u32>(stream,0x6c,(u32)(self+0x108));
  return 1;
}
PCREG(4a4600,serialize_extended_fields);
