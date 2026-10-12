// batch1015.cpp - unclaimed-07 batch 15 (docs/20-unclaimed-07.md, slice 6): CCheckInsideBox::DoCheck.
// Name from the GC name map (high). Body from the PC bytes. The security cookie check (0x633654) is not reproduced: it
// is a no-op when the cookie matches, which it does on every normal return.
#include "ff.h"

// 0x4daf90: copies the three dwords at src+0x30 to the out array (thiscall with ECX = src, one argument; original code).
extern "C" void THISCALL ext_4daf90(u8 *src, u32 *out);
// 0x5b8270 and 0x5b8200: list walks over this+0x54 (original code, called with ECX = this, no arguments).
extern "C" void THISCALL ext_5b8270(u8 *self);
extern "C" void THISCALL ext_5b8200(u8 *self);

// 0x5b8020, CCheckInsideBox::DoCheck() (high): esi = 0. obj = (this+0x50)->+0x18. When obj is non-null: slot +0x4c(&local),
// item = slot +0x5c(&local); while local is non-zero: r = engine slot +0xcc(item) (engine at 0x70038c); when r is
// non-null: vec = copy of [r+8] (0x4daf90), r slot +0x84(&vec), (this+0x44) slot +0x8c(&vec), and when (this+0x44) slot
// +0x180(&vec, -10.0f) is true, esi++; then item = slot +0x5c(&local). Afterwards: when esi is non-zero, when this+0x5c is 0
// the walk 0x5b8270(this) runs; when esi is zero, when this+0x5c is non-zero the walk 0x5b8200(this) runs. Then
// this+0x5c = esi.
static void THISCALL checkInsideBoxDoCheck(u8 *self) {
  u32 esi = 0;
  u8 *holder = *(u8 **)(self + 0x50);
  u8 *obj = *(u8 **)(holder + 0x18);
  if (obj) {
    u32 local = 0;
    vcall<void>(obj, 0x4c, &local);
    u32 item = vcall<u32>(obj, 0x5c, &local);
    if (local != 0) {
      do {
        void *engine = G(void *, 0x70038c);
        u32 r = vcall<u32>(engine, 0xcc, item);
        if (r) {
          u32 vec[3];
          ext_4daf90(*(u8 **)(r + 8), vec);
          vcall<void>((void *)r, 0x84, (u32)vec);
          void *obj44 = *(void **)(self + 0x44);
          vcall<void>(obj44, 0x8c, (u32)vec);
          if ((u8)vcall<u32>(*(void **)(self + 0x44), 0x180, (u32)vec, 0xc1200000u))
            esi++;
          (void)obj44;
        }
        item = vcall<u32>(obj, 0x5c, &local);
      } while (local != 0);
    }
  }
  if (esi != 0) {
    if (*(u32 *)(self + 0x5c) == 0)
      ext_5b8270(self);
  } else {
    if (*(u32 *)(self + 0x5c) != 0)
      ext_5b8200(self);
  }
  *(u32 *)(self + 0x5c) = esi;
}
PCREG(5b8020, checkInsideBoxDoCheck);
