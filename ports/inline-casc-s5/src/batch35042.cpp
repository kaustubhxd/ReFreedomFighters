// batch35042.cpp - cascade s5 batch 35042: 0x617360 (GUESS first-use hook of a counted resource: copy its table into the owner's buffer).
#include "ff.h"

extern "C" void THISCALL ext_659330(u8 *self, u32 a, u32 b);   // thiscall, ret 8
extern "C" void ext_634d22(void *dst, const void *src, u32 n);  // cdecl memcpy
typedef u32(THISCALL *g2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x617360, thiscall, no arguments. c = [this+0x30]++ ; only the first call (c == 0) acts. R = [[this+4]+8], s = [this+8]. 0x659330(this + 0x24, word R[0xe], [s+0xb9a8]); base = [[engine+0x1aa3]+0x20]
// (unaligned); t = unaligned dword [[s+0xb9a4]+0x13fa]. When [this+0x28] is non-zero: [t+0x30] is created with t slot 4(0, 0) when it is zero, then memcpy([t+0x30] + 36 * [this+0x28],
// R[0x14] + base, 36 * word R[0xe]).
static void THISCALL fn617360(u8 *self) {
  u32 c = *(u32 *)(self + 0x30);
  *(u32 *)(self + 0x30) = c + 1;
  if (c != 0) return;
  u8 *R = *(u8 **)(*(u8 **)(self + 4) + 8);
  u8 *s = *(u8 **)(self + 8);
  u32 w = *(u16 *)(R + 0xe);
  ext_659330(self + 0x24, w, *(u32 *)(s + 0xb9a8));
  u32 nz = *(u32 *)(self + 0x28);
  u8 *q = *(u8 **)(s + 0xb9a4);
  u8 *t = (u8 *)rd32u(q + 0x13fa);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *b1 = (u8 *)rd32u(eng + 0x1aa3);
  u32 base = *(u32 *)(b1 + 0x20);
  if (nz) {
    if (*(u32 *)(t + 0x30) == 0) *(u32 *)(t + 0x30) = (*(g2_t **)t)[4 / 4](t, 0, 0);
    ext_634d22((void *)(*(u32 *)(t + 0x30) + nz * 36), (void *)(*(u32 *)(R + 0x14) + base), w * 36);
  }
}
PCREG(617360, fn617360);
