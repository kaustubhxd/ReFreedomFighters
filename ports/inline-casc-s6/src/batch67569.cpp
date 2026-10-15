// batch67569.cpp - cascade s6 batch 67569: 0x4ad3a0.
#include "ff.h"

extern "C" u8 *THISCALL ext_4acf30(u8 *self, u32 id);       // ret 4
extern "C" void STDCALL ext_4dc630(u32 a, u32 b);           // ret 8

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef u32 (THISCALL *tab3_t)(u8 *, u32, u32, u32);

// 0x4ad3a0, thiscall(list) ret 4, no return value: walks a list object (slot 0x14 must be non-zero; iterator via slots 0x4c / 0x5c) and for every id that 0x4acf30 resolves to an object: when its
// record's flag 0x400 (+0x3c) is clear it sets state 0x800000 (0x4dc630), runs slot 0x158, gives the object the handle from the table's slot 0x4c(this[0x44], 0, 0) through slot 0x2f0 and runs slot
// 0x2d0(1, 0); then, if slot 0x2e8 returns a helper whose slot 0x300 reports 2, this[0x44] slot 0x548(object, 0) is called.
static void THISCALL fn4ad3a0(u8 *self, u8 *list) {
  if (!list) return;
  if (!vcall<u32>(list, 0x14)) return;
  u32 it;
  vcall<void>(list, 0x4c, (u32)&it);
  u32 r = vcall<u32>(list, 0x5c, (u32)&it);
  if (it == 0) return;
  do {
    u8 *o = ext_4acf30(self, r);
    if (o) {
      u8 *rec = *(u8 **)(o + 8);
      if (!((D32(rec, 0x3c) >> 10) & 1)) {
        ext_4dc630(0x800000, 0);
        vcall<void>(o, 0x158);
        u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
        u32 m = (*(tab3_t *)(*(u8 **)tab + 0x4c))(tab, D32(self, 0x44), 0, 0);
        vcall<void>(o, 0x2f0, m);
        vcall<void>(o, 0x2d0, 1u, 0u);
      }
      u8 *x = vcall<u8 *>(o, 0x2e8);
      if (x) {
        if (vcall<u32>(x, 0x300) == 2) vcall<void>(*(u8 **)(self + 0x44), 0x548, (u32)o, 0u);
      }
    }
    r = vcall<u32>(list, 0x5c, (u32)&it);
  } while (it != 0);
}
PCREG(4ad3a0, fn4ad3a0);
