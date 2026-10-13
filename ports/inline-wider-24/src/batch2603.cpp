// batch2603.cpp - wider batch 2603. 0x43e700 (ZHELPER::ModifyBox, GUESS args), thiscall(a1, a2, p, a4), ret 0x10. If byte this+0x18 has bit 8: slot 0x74 of this
// with (a1, a2) (thiscall, callee pops 8); copy three dwords from *p to this+0x28/0x2c/0x30; then 0x4690b0 (a bare `ret`, thiscall, no stack args)
// on ECX = [this+8]. a4 is unused (popped by ret 0x10).
#include "ff.h"

extern "C" void THISCALL ext_4690b0(void *self);
typedef void(THISCALL *vs74_t)(void *, u32, u32);

static void THISCALL modifyBox(u8 *self, u32 a1, u32 a2, u32 *p, u32 a4) {
  (void)a4;
  if (!(self[0x18] & 8)) return;
  (*(vs74_t **)self)[0x74 / 4](self, a1, a2);
  *(u32 *)(self + 0x28) = p[0];
  *(u32 *)(self + 0x2c) = p[1];
  *(u32 *)(self + 0x30) = p[2];
  ext_4690b0(*(void **)(self + 8));
}
PCREG(43e700, modifyBox);
