// batch2433.cpp - decomp area 24, batch 2433.
#include "ff.h"

// 0x420570 ZSysInterfaceGC::CloseAllWindows(), thiscall, plain ret. While the head at +0x190f is set, slot 0 of the head
// is called with 1; the callee unlinks its node, so the head is read again each time.
static void THISCALL closeAllWindows(u8 *self) {
  u8 *n = *(u8 **)(self + 0x190f);
  while (n) {
    vcall<void>(n, 0, 1u);
    n = *(u8 **)(self + 0x190f);
  }
}
PCREG(420570, closeAllWindows);

// 0x44b8b0 (unnamed), thiscall, ret 4. The object at (0x70039c)+0x1a9f gets slot 0x12c with (this+0x38, argument); the
// result is stored at this+0x38.
static u32 THISCALL slot12cCaller(u8 *self, u32 arg) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x1a9f);
  u32 r = vcall<u32>(tab, 0x12c, *(u32 *)(self + 0x38), arg);
  *(u32 *)(self + 0x38) = r;
  return r;
}
PCREG(44b8b0, slot12cCaller);
