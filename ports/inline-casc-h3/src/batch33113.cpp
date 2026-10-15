// batch33113.cpp - h3 (Sonnet) batch 33113: tier H float/SSE functions
#include "ff.h"

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_5165d0(u8 *self, u32 a, u32 c, u32 b, u32 d);     // ret 0x10

// 0x529130: thiscall no args: [0x40] = ([0x40]+1) % [0x8d]; [0x44] = ([0x44]+1) % [0x91] (signed); for i < [0x8d]: 0x5165d0(this+0x95+0xde*i, [0x68], [0x40]==i, [0x64], 0); for j < [0x91]: 0x5165d0(this+0x785+0xde*j, [0x68], [0x44]==j, [0x64], 0)
static void THISCALL fn529130(u8 *self) {
  s32 a = *(s32 *)(self + 0x8d);
  s32 x = (s32)(*(u32 *)(self + 0x40) + 1u);
  s32 y = (s32)(*(u32 *)(self + 0x44) + 1u);
  *(s32 *)(self + 0x40) = x % a;
  *(s32 *)(self + 0x44) = y % *(s32 *)(self + 0x91);
  if (a > 0) {
    s32 i = 0;
    u8 *e = self + 0x95;
    do {
      u32 fl = *(s32 *)(self + 0x40) == i;
      ext_5165d0(e, R32(self + 0x68), fl, R32(self + 0x64), 0);
      i++;
      e += 0xde;
    } while (i < *(s32 *)(self + 0x8d));
  }
  if (*(s32 *)(self + 0x91) > 0) {
    s32 j = 0;
    u8 *e = self + 0x785;
    do {
      u32 fl = *(s32 *)(self + 0x44) == j;
      ext_5165d0(e, R32(self + 0x68), fl, R32(self + 0x64), 0);
      j++;
      e += 0xde;
    } while (j < *(s32 *)(self + 0x91));
  }
}
PCREG(529130, fn529130);

// 0x4f7330: thiscall(byte flag) ret 4: [0xa7]==0 return; this->slot 0x80(l34, l10); l10[1] += [0xa3]; [0x93]->slot 0x7c(l34, l10); flag && [0x8f]: k=(int)[0x9f]; n=this->slot 0x388(); n <= k: return; [0x8f]->slot 0x370([0xa3] / (float)(this->slot 0x388() - (int)[0x9f]))
static void THISCALL fn4f7330(u8 *self, u32 flag) {
  if (self[0xa7] == 0) return;
  u32 l34[9];
  float l10[3];
  vcall<u32>(self, 0x80, (u32)l34, (u32)l10);
  float a3 = bitsf(R32(self + 0xa3));
  l10[1] = a3 + l10[1];
  u8 *o = (u8 *)R32(self + 0x93);
  vcall<u32>(o, 0x7c, (u32)l34, (u32)l10);
  if ((u8)flag == 0) return;
  if (R32(self + 0x8f) == 0) return;
  s32 k = _mm_cvttss_si32(_mm_set_ss(bitsf(R32(self + 0x9f))));
  s32 n = (s32)vcall<u32>(self, 0x388);
  if (n <= k) return;
  u8 *t = (u8 *)R32(self + 0x8f);
  u8 *vt = *(u8 **)t;
  s32 k2 = _mm_cvttss_si32(_mm_set_ss(bitsf(R32(self + 0x9f))));
  s32 n2 = (s32)vcall<u32>(self, 0x388);
  float d = (float)(s32)((u32)n2 - (u32)k2);
  float f = bitsf(R32(self + 0xa3)) / d;
  typedef u32(THISCALL * fn_t)(u8 *, u32);
  (*(fn_t *)(vt + 0x370))((u8 *)R32(self + 0x8f), fbits(f));
}
PCREG(4f7330, fn4f7330);
