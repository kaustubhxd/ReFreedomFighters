#include "ff.h"

extern "C" u32 THISCALL ext_591ae0(u8 *self);

// 0x5b3e10, thiscall() plain ret: lazily fills subobject+0x85a through slot
// 0x100, copies subobject fields, calls 0x591ae0, then tail-dispatches slot 0xc.
static u32 THISCALL fn5b3e10(u8 *self) {
  u8 *sub = *(u8 **)(self + 0x5f);
  u32 id = *(u32 *)(sub + 0x85a);
  if (!id) {
    id = vcall<u32>(sub, 0x100, 0x6a6e88u);
    *(u32 *)(sub + 0x85a) = id;
  }
  *(u32 *)(self + 0x63) = id;
  *(u32 *)(self + 0x5b) = *(u32 *)(sub + 0x852);
  *(u32 *)(self + 0x51) = ext_591ae0(sub);
  return vcall<u32>(self, 0xc);
}

PCREG(5b3e10, fn5b3e10);
