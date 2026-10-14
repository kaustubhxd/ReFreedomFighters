// batch34115.cpp - cascade tier E, batch 34115: 0x497070 (register a node with the engine log).
#include "ff.h"

extern "C" u32 THISCALL ext_497160(void *self, void *a);              // thiscall ret 4
extern "C" u32 THISCALL ext_4dc630(void *self, u32 a, u32 b);         // thiscall ret 8
extern "C" u32 THISCALL ext_4ce1c0(void *self, u32 a, u32 b);         // thiscall ret 8

// 0x497070, thiscall(a) ret 4: ext_497160(this, a). When [a+0x3c] has 0x8000000: ext_4dc630(a, 0x4000000, 0), done. Else with p = [this+0x14]: ext_4ce1c0([p], a - [p+4], 0x70); when the engine object at [0x70038c]
// is set its slot 0x30 is called with (0x68e344, a - [[this+0x14]+4], 0x70); finally slot 0x50 of [0x70038c] (re-read, must be set) with (a, 0x70, 0x7f007f); returns its eax.
static u32 THISCALL fn497070(u8 *self, u8 *a) {
  ext_497160(self, a);
  if (*(u32 *)(a + 0x3c) & 0x8000000) return ext_4dc630(a, 0x4000000, 0);
  u8 *p = *(u8 **)(self + 0x14);
  ext_4ce1c0(*(u8 **)p, (u32)a - *(u32 *)(p + 4), 0x70);
  u8 *g = G(u8 *, 0x70038c);
  if (g) {
    p = *(u8 **)(self + 0x14);
    vcall<void>(g, 0x30, 0x68e344u, (u32)a - *(u32 *)(p + 4), 0x70u);
  }
  return vcall<u32>(G(u8 *, 0x70038c), 0x50, (u32)a, 0x70u, 0x7f007fu);
}
PCREG(497070, fn497070);
