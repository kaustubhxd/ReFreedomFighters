// batch43005.cpp - t4 (Sonnet) batch 43005: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_5168b0(u8 *self);                 // thiscall, plain ret
extern "C" void ext_42ac56(u8 *buf, u32 fmt, u32 n);           // cdecl sprintf-style

// 0x526c60, thiscall no args: s = A (0x681dc4); [this+0x68] > T (0x67cd40): s = B (0x679544) / [this+0x68]; e = float at 0x69c69c;
// [this+0x6c] > D (0x680a84): s = e; m = max(e, s) (maxss: NaN gives s); for i < (int)[this+0x12f7] (unaligned, re-read each pass):
// p = this + 0x1205 + i * 0x79: [p+0x10] = m; 0x5168b0(p)
static void THISCALL fn526c60(u8 *self) {
  float s = G(float, 0x681dc4);
  float x = *(float *)(self + 0x68);
  if (x > G(float, 0x67cd40)) s = G(float, 0x679544) / x;
  float e = G(float, 0x69c69c);
  if (*(float *)(self + 0x6c) > G(float, 0x680a84)) s = e;
  float m = e > s ? e : s;
  for (s32 i = 0; i < *(s32 *)(self + 0x12f7); i++) {
    u8 *p = self + 0x1205 + i * 0x79;
    *(float *)(p + 0x10) = m;
    ext_5168b0(p);
  }
}
PCREG(526c60, fn526c60);

// 0x6528a0, thiscall(hinst) plain ret: once ([0x7f6410] == 0): 16 bytes 0x6c3a18 -> 0x7f5a10, 8 bytes 0x6c3a28 -> 0x7f5a20, [0x7f6410] = 1;
// for n = 0..999: sprintf(0x7f5a1c, 0x6c3a30, n); stop when the import at 0x67618c (stdcall 3: hinst, 0x7f5a10, &wc{cbSize 0x30}) returns 0 (GetClassInfoEx style)
typedef u32(STDCALL *gci_t)(u8 *, u32, void *);
static void THISCALL fn6528a0(u8 *self) {
  u32 wc[12];
  wc[0] = 0x30;
  if (G(u32, 0x7f6410) != 0) return;
  for (int i = 0; i < 16; i++) ((u8 *)0x7f5a10)[i] = ((u8 *)0x6c3a18)[i];
  for (int i = 0; i < 8; i++) ((u8 *)0x7f5a20)[i] = ((u8 *)0x6c3a28)[i];
  G(u32, 0x7f6410) = 1;
  for (u32 n = 0; n != 0x3e8; n++) {
    ext_42ac56((u8 *)0x7f5a1c, 0x6c3a30, n);
    if (!(*(gci_t *)0x67618c)(self, 0x7f5a10, wc)) break;
  }
}
PCREG(6528a0, fn6528a0);

// 0x563490, thiscall(a) ret 4, returns true: [this+4] &= ~0x40; o1 = a->slot 0x3c([this+0x48]); o2 = o1->slot 0x4c(float [this+0x64]);
// o3 = o2->slot 0x60(byte [this+0x84]); o3->slot 0x60(byte [this+0x85]); a->slot 0x44([this+0xf0]); a->slot 0x44([this+0xdc])
static bool THISCALL fn563490(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  u8 *o1 = vcall<u8 *>(a, 0x3c, *(u32 *)(self + 0x48));
  u8 *o2 = vcall<u8 *>(o1, 0x4c, *(float *)(self + 0x64));
  u8 *o3 = vcall<u8 *>(o2, 0x60, (u32)self[0x84]);
  vcall<u8 *>(o3, 0x60, (u32)self[0x85]);
  vcall<void>(a, 0x44, *(u32 *)(self + 0xf0));
  vcall<void>(a, 0x44, *(u32 *)(self + 0xdc));
  return true;
}
PCREG(563490, fn563490);
