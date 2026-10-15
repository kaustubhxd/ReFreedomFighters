// batch67567.cpp - cascade s6 batch 67567: 0x482370.
#include "ff.h"

extern "C" void THISCALL ext_465fb0(u8 *self);   // plain
extern "C" void THISCALL ext_482b80(u8 *self);   // plain
extern "C" void THISCALL ext_441730(u8 *g);      // plain
extern "C" void THISCALL ext_440530(u8 *g);      // plain

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x482370, thiscall() plain ret (eax unused): per-frame update of a camera-like object. The lock flag (+0x5fe) hands over to 0x465fb0. Otherwise, with the active flag (+0x412) and the current object's
// (slot 0x20) record not marked 0x800 in +0x3c, it runs 0x482b80, brackets slot 0x5ec (update) with 0x441730 / 0x440530 on the global at 0x68c018, runs slots 0x604 and 0x348, derives a 9-dword matrix, a
// 3-dword vector and two more records through slots 0x59c / 0x61c / 0x600 and finally applies them with slot 0x5f0. Inactive objects only run slot 0x5ec.
static void THISCALL fn482370(u8 *self) {
  u32 a[9], b[3], c[9], d[3];
  if (self[0x5fe]) {
    ext_465fb0(self);
    return;
  }
  if (self[0x412]) {
    u8 *o = vcall<u8 *>(self, 0x20);
    if (!(D32(*(u8 **)(o + 8), 0x3c) & 0x800)) {
      ext_482b80(self);
      ext_441730((u8 *)0x68c018);
      vcall<void>(self, 0x5ec);
      ext_440530((u8 *)0x68c018);
      vcall<void>(self, 0x604);
      vcall<void>(self, 0x348);
      vcall<void>(self, 0x59c, (u32)a, (u32)b);
      vcall<void>(self, 0x61c, (u32)a, (u32)b, (u32)c, (u32)d);
      vcall<void>(self, 0x600, (u32)a, (u32)b, (u32)c, (u32)d);
      vcall<void>(self, 0x5f0, (u32)c, (u32)d);
      return;
    }
  }
  vcall<void>(self, 0x5ec);
}
PCREG(482370, fn482370);
