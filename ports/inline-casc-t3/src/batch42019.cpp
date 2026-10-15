// batch42019.cpp - Sonnet t3: object copy after a dynamic cast.
#include "ff.h"

extern "C" u8 *ext_634d2e(u32 v, u32 a, u32 b, u32 c, u32 d);  // RTDynamicCast-style thunk, cdecl, 5 args
extern "C" void THISCALL ext_4c3070(u8 *self);                  // plain ret
typedef u32 __attribute__((aligned(1))) u32u;
typedef u16 __attribute__((aligned(1))) u16u;
typedef struct { u32 w[4]; } v128 __attribute__((aligned(1)));

static inline void c4(u8 *d, const u8 *s, u32 off) { *(u32u *)(d + off) = *(const u32u *)(s + off); }

// 0x4bf3e0, thiscall(v) ret 4: r = 0x634d2e(v, 0, 0x6f6df8, 0x6f7f08, 0); copy fields from r: bytes 0x51, 0x71, 0x73, 0x50, 0x52, words 0x4c/0x4e, dwords 0x6d, 0x59, 0x5d, 0x65, 0x69, 0x48,
// 32 bytes at 0x180, 0x40 dwords at 0x80; when [[0x70039c]+0x1a9f] is set, 0x4c3070(this).
static void THISCALL fn4bf3e0(u8 *self, u32 v) {
  u8 *r = ext_634d2e(v, 0, 0x6f6df8, 0x6f7f08, 0);
  self[0x51] = r[0x51];
  *(u16u *)(self + 0x4c) = *(u16u *)(r + 0x4c);
  *(u16u *)(self + 0x4e) = *(u16u *)(r + 0x4e);
  c4(self, r, 0x6d);
  self[0x71] = r[0x71];
  *(v128 *)(self + 0x180) = *(v128 *)(r + 0x180);
  *(v128 *)(self + 0x190) = *(v128 *)(r + 0x190);
  self[0x71] = r[0x71];
  self[0x73] = r[0x73];
  for (u32 i = 0; i < 0x40; i++) ((u32 *)(self + 0x80))[i] = ((u32 *)(r + 0x80))[i];
  c4(self, r, 0x59);
  c4(self, r, 0x5d);
  c4(self, r, 0x65);
  c4(self, r, 0x69);
  c4(self, r, 0x48);
  self[0x50] = r[0x50];
  self[0x52] = r[0x52];
  if (*(u32 *)(*(u8 **)0x70039c + 0x1a9f)) ext_4c3070(self);
}
PCREG(4bf3e0, fn4bf3e0);
