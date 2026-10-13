// batch6545.cpp - unclaimed-65: batch 45 (docs/20-unclaimed-65.md, claim 25): 0x4daa70, thiscall with five stack arguments (ret 0x14).
#include "ff.h"

typedef u32(THISCALL *F4)(u8 *self, u32 a, u32 b, u32 c, u32 d);
static u32 vc4(u8 *o, u32 s, u32 a, u32 b, u32 c, u32 d) { return ((F4)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c, d); }

extern "C" void THISCALL ext_4daaf0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);  // thiscall, five arguments (ret 0x14)

// 0x4daa70. See docs/20-unclaimed-65.md (claim 25).
static void THISCALL classCall4daa70(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  if ((a5 & 0xff) == 0) {
    u8 *c = *(u8 **)(self + 0x54);
    if (c != nullptr) {
      vc4(c, 0xdc, a1, a2, a3, a4);
      return;
    }
  }
  bool b = *(const u32 *)(self + 0x6c) != 0;
  if (!b) {
    u8 *c = *(u8 **)(self + 0x54);
    const u32 flags = c != nullptr ? *(const u32 *)(c + 0x14) : 0;
    b = (flags & 1) != 0;
  }
  if (!b) return;
  if (*(const u32 *)(self + 0x6c) != 0) vc4((u8 *)a1, 0x30, (u32)self, a3, a4, 0xff);
  ext_4daaf0(self, a1, a2, a3, a4, 0);
}

PCREG(4daa70, classCall4daa70);
