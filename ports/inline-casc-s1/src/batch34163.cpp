// batch34163.cpp - cascade tier H, batch 34163: 0x563490 (configure a slot chain), 0x650e00 (resolve two handles and forward a float), 0x532850 (Manhattan distance of two word triples), 0x4f6e90 (read two ints as floats and an id).
#include "ff.h"

extern "C" void THISCALL ext_4f9c90(void *self, void *s);              // ret 4
extern "C" void THISCALL ext_4e11e0(void *s, void *p, u32 n);          // ret 8 (writes through p)
extern "C" void THISCALL ext_4e12e0(void *s, void *p, u32 n);          // thunk to 0x4e11e0
extern "C" void THISCALL ext_4e1b30(void *s);                           // plain ret

// 0x563490, thiscall(s) ret 4, returns true: [this+4] &= ~0x40; r = s->slot0x3c([this+0x48]); o = r->slot0x4c(float [this+0x64]); o = o->slot0x60(byte [this+0x84]); o->slot0x60(byte [this+0x85]); s->slot0x44([this+0xf0]); s->slot0x44([this+0xdc]).
static u32 THISCALL fn563490(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  u8 *r = vcall<u8 *>(s, 0x3c, *(u32 *)(self + 0x48));
  u8 *o = vcall<u8 *>(r, 0x4c, *(u32 *)(self + 0x64));
  o = vcall<u8 *>(o, 0x60, (u32)self[0x84]);
  vcall<void>(o, 0x60, (u32)self[0x85]);
  vcall<void>(s, 0x44, *(u32 *)(self + 0xf0));
  vcall<void>(s, 0x44, *(u32 *)(self + 0xdc));
  return 1;
}
PCREG(563490, fn563490);

// 0x650e00, thiscall(a, f) ret 8: o = [this+0x8c]; h = [[0x70039c]+0x9b]->slot0x4c(a); r = o->slot0x28(h); when r: h2 = table->slot0x4c(a) again; r2 = o->slot0x2c(h2); when r2: o->slot0xa0(r2, f).
static void THISCALL fn650e00(u8 *self, u32 a, u32 f) {
  u8 *o = *(u8 **)(self + 0x8c);
  u32 h = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, a);
  typedef u32 (THISCALL *f1)(void *, u32);
  u32 r = (*(f1 *)(*(u8 **)o + 0x28))(o, h);
  if (!r) return;
  o = *(u8 **)(self + 0x8c);
  u32 h2 = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, a);
  u32 r2 = (*(f1 *)(*(u8 **)o + 0x2c))(o, h2);
  if (!r2) return;
  o = *(u8 **)(self + 0x8c);
  vcall<void>(o, 0xa0, r2, f);
}
PCREG(650e00, fn650e00);

// 0x532850, ecx = A (3 words), edx = B (3 words), returns a float in st0: (float)(|A.z - B.z| + |A.y - B.y| + |A.x - B.x|) with the words as unsigned 16-bit values.
static float FASTCALL fn532850(u16 *A, u16 *B) {
  s32 dx = (s32)A[0] - (s32)B[0];
  s32 dy = (s32)A[1] - (s32)B[1];
  s32 dz = (s32)A[2] - (s32)B[2];
  s32 sum = (dz < 0 ? -dz : dz) + (dy < 0 ? -dy : dy) + (dx < 0 ? -dx : dx);
  return (float)sum;
}
PCREG(532850, fn532850);

// 0x4f6e90, thiscall(s) ret 4: ext_4f9c90(this, s); ext_4e11e0(s, &v, 1) -> float [this+0x9b] = (float)v; again -> [this+0x9f]; ext_4e12e0(s, &w, 1); [this+0x8f] = [0x70038c]->slot0xcc(w); ext_4e1b30(s).
static void THISCALL fn4f6e90(u8 *self, u8 *s) {
  s32 v = (s32)(u32)s;
  s32 w;
  ext_4f9c90(self, s);
  ext_4e11e0(s, &v, 1);
  *(float *)(self + 0x9b) = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(v)));
  ext_4e11e0(s, &v, 1);
  *(float *)(self + 0x9f) = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(v)));
  ext_4e12e0(s, &w, 1);
  u32 r = vcall<u32>(G(u8 *, 0x70038c), 0xcc, (u32)w);
  self[0x8f] = r; self[0x90] = r >> 8; self[0x91] = r >> 16; self[0x92] = r >> 24;
  ext_4e1b30(s);
}
PCREG(4f6e90, fn4f6e90);
