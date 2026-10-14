// batch32074.cpp - cascade h2 (): 0x5d82a0 (copy fields from a dynamic-cast object), 0x5c2c10 (register an index in a looked-up record).
#include "ff.h"

extern "C" u8 *ext_634d2e(u32 v, u32 a, u32 b, u32 c, u32 d);   // RTDynamicCast-style thunk, cdecl, 5 args
extern "C" u8 *THISCALL ext_5c2e10(u8 *self, u8 *key);          // thiscall ret 4

static inline void cp4(u8 *d, const u8 *s, u32 off) {
  for (int i = 0; i < 4; i++) d[off + i] = s[off + i];
}

// 0x5d82a0, thiscall(v) ret 4: r = 0x634d2e(v, 0, 0x6f6df8, 0x6fac3c, 0); copy words 0x48/0x4a/0x4c, 25 dwords at 0x4e, byte 0xb2, dwords 0xb3 and
// 0xb7 (skipped when r == this), byte 0xbb, dword 0xbc; returns [r+0xbc] (eax).
static u32 THISCALL fn5d82a0(u8 *self, u32 v) {
  u8 *r = ext_634d2e(v, 0, 0x6f6df8, 0x6fac3c, 0);
  *(u16 *)(self + 0x48) = *(u16 *)(r + 0x48);
  *(u16 *)(self + 0x4a) = *(u16 *)(r + 0x4a);
  *(u16 *)(self + 0x4c) = *(u16 *)(r + 0x4c);
  for (int i = 0; i < 25; i++) *(u32 *)(self + 0x4e + 4 * i) = *(u32 *)(r + 0x4e + 4 * i);
  self[0xb2] = r[0xb2];
  if (self + 0xb3 != r + 0xb3) cp4(self, r, 0xb3);
  if (self + 0xb7 != r + 0xb7) cp4(self, r, 0xb7);
  self[0xbb] = r[0xbb];
  u32 e = *(u32 *)(r + 0xbc);
  *(u32 *)(self + 0xbc) = e;
  return e;
}
PCREG(5d82a0, fn5d82a0);

// 0x5c2c10, thiscall(idx) ret 4: when idx < [this+0x2c0] (signed): s = *(char**)(this + idx*14 + 8); r = 0x5c2e10(this, s + strlen(s) - 2); r != 0 ->
// unless idx is among the first [r+0x44] dwords at r+4 and while [r+0x44] < 16: append idx.
static void THISCALL fn5c2c10(u8 *self, int idx) {
  if (idx >= *(int *)(self + 0x2c0)) return;
  const u8 *s = *(const u8 **)(self + idx * 14 + 8);
  const u8 *e = s;
  while (*e++) {}
  u32 len = (u32)(e - s) - 1;
  u8 *r = ext_5c2e10(self, (u8 *)(s - 2 + len));
  if (!r) return;
  int n = *(int *)(r + 0x44);
  for (int i = 0; i < n; i++)
    if (idx == *(int *)(r + 4 + 4 * i)) return;
  if (n >= 0x10) return;
  *(int *)(r + 4 + n * 4) = idx;
  *(int *)(r + 0x44) += 1;
}
PCREG(5c2c10, fn5c2c10);
