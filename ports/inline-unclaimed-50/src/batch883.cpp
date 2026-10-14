// batch883.cpp - area 50 (SEH row): 0x482a50 [SEH frame; GUESS "Make482a50": allocate 0x125 bytes (cdecl, 0x41e290) and, when the
// allocation is not null, run the constructor-like routine 0x487820 on it with this and 2 (thiscall, ret 8)]. The SEH frame is not
// reproduced (fs:[0] writes not compared). The frame's cookie check is not reproduced either.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                                 // allocator (stood in), cdecl
extern "C" void THISCALL ext_487820(void *obj, void *owner, u32 n);    // constructor-like routine (stood in), ret 8

// 0x482a50 (name GUESS).
static void THISCALL Make482a50(u8 *self) {
  void *p = ext_41e290(0x125u);
  if (p) ext_487820(p, self, 2u);
}
PCREG(482a50, Make482a50);
