// batch6546.cpp - unclaimed-65: batch 46 (docs/20-unclaimed-65.md, claim 26): 0x4daaf0, thiscall, five stack arguments (ret 0x14).
// The /GS cookie check is not reproduced (tagged in the doc).
#include "ff.h"

typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *F4)(u8 *self, u32 a, u32 b, u32 c, u32 d);
static u32 vc3(u8 *o, u32 s, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c); }
static u32 vc4(u8 *o, u32 s, u32 a, u32 b, u32 c, u32 d) { return ((F4)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c, d); }

extern "C" void FASTCALL ext_441970(u8 *out, u8 *in, u32 mat);   // fastcall, one stack argument (ret 4)
extern "C" void FASTCALL ext_441940(u8 *out, u8 *in);            // fastcall (ret 0)

// 0x4daaf0. See docs/20-unclaimed-65.md (claim 26).
static void THISCALL classCallWide4daaf0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  if ((a5 & 0xff) == 0) {
    u8 *c = *(u8 **)(self + 0x54);
    if (c != nullptr) {
      vc4(c, 0xe0, a1, a2, a3, a4);
      return;
    }
  }
  u8 *c = *(u8 **)(self + 0x54);
  const u32 flags = c != nullptr ? *(const u32 *)(c + 0x14) : 0;
  if ((flags & 1) == 0) return;

  u8 L1c[12];
  u8 L10[12];
  ext_441970(L1c, self + 0x30, a3);
  ext_441940(L1c, (u8 *)a4);
  if (flags & 0xc) {
    *(u32 *)(L10 + 0) = 0x3f800000;
    *(u32 *)(L10 + 4) = 0x3f800000;
    *(u32 *)(L10 + 8) = 0x3f800000;
    ext_441940(L10, self + 0x40);
    vc3((u8 *)a1, 0xdc, a3, (u32)L1c, (u32)L10);
  }
  if (flags & 2) vc3((u8 *)a1, 0x80, a3, (u32)L1c, a2);
}

PCREG(4daaf0, classCallWide4daaf0);
