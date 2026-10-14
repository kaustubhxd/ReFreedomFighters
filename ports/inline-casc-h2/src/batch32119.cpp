// batch32119.cpp - cascade h2 (): one tier H (SSE block copy) function.
#include "ff.h"

extern "C" u32 THISCALL ext_596ce0(u8 *self);                 // thiscall, plain ret
extern "C" u32 THISCALL ext_596cf0(u8 *self);                 // thiscall, plain ret
extern "C" u8 *THISCALL ext_5a83c0(u8 *self, u8 *out);        // thiscall ret 4, returns a pointer to a 32-byte record
extern "C" u32 THISCALL ext_59b6d0(u8 *self);                 // thiscall, plain ret
extern "C" void THISCALL ext_5ade90(u8 *self);                // thiscall, plain ret
extern "C" void THISCALL ext_5ae680(u8 *self);                // thiscall, plain ret

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x5718b0, thiscall no args: g = [this+0x90] != 0 and e = unaligned [g+0x852] != 0 -> [[this+0x1ac]+0x3c4] = 0x596ce0(e); [[this+0x1ac]+0x3c8] = 0x596cf0(e);
// rec = 0x5a83c0(unaligned [e+0x1d0f], &tmp) (32 bytes copied to the stack); i = 0x59b6d0([this+0x94]); the 32 bytes go to [[this+0x1ac]] + i*32 + 0x418 (unaligned);
// then always 0x5ade90([this+0x1ac]) and 0x5ae680([this+0x1ac]).
static void THISCALL fn5718b0(u8 *self) {
  u8 tmp[0x40];
  u8 keep[0x20];
  u8 *g = *(u8 **)(self + 0x90);
  if (g) {
    u8 *e = (u8 *)rd32(g + 0x852);
    if (e) {
      u32 a = ext_596ce0(e);
      *(u32 *)(*(u8 **)(self + 0x1ac) + 0x3c4) = a;
      u32 b = ext_596cf0(e);
      *(u32 *)(*(u8 **)(self + 0x1ac) + 0x3c8) = b;
      u8 *rec = ext_5a83c0((u8 *)rd32(e + 0x1d0f), tmp);
      for (int i = 0; i < 0x20; i++) keep[i] = rec[i];
      u32 idx = ext_59b6d0(*(u8 **)(self + 0x94));
      u8 *dst = *(u8 **)(self + 0x1ac) + (idx << 5) + 0x418;
      for (int i = 0; i < 0x20; i++) dst[i] = keep[i];
    }
  }
  ext_5ade90(*(u8 **)(self + 0x1ac));
  ext_5ae680(*(u8 **)(self + 0x1ac));
}
PCREG(5718b0, fn5718b0);
