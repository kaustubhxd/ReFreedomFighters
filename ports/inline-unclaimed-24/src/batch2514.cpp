// batch2514.cpp - decomp area 24, batch 2514. 0x60b6f0 (GUESS renderer per-frame state setup + per-element pass), thiscall, no args.
// Device calls go through COM-style slots (stdcall, `this` first): SetTransform 0x94 (state, matrix), SetRenderState 0xc8, 0xf4 (stage
// texture), and the exe's own 0x60ff30 / 0x60feb0 (fastcall: ecx, edx, two stack dwords; they cache render state in globals and call
// device slot 0xfc). The loop over six passes iterates the table returned by slot 0x18 of the object at this+0x94 (slots 0x4c begin,
// 0x64 next) and, for elements whose mask at +0x1d9 has its lowest set bit equal to the pass number, walks 50 sample slots. The
// accumulated samples (local array), the 0x633c60 int64-to-double conversions and the later pshufd/stack stores only touch dead locals
// in the original; only their memory reads (which can fault) are reproduced, as volatile reads.
// Stack cookie check (0x633654) not reproduced.
#include "ff.h"

extern "C" void FASTCALL ext_60ff30(u32 ecx, u32 edx, u32 a, u32 b);
extern "C" void FASTCALL ext_60feb0(u32 ecx, u32 edx, u32 a, u32 b);

typedef u32(THISCALL *vf0)(void *);
typedef void(THISCALL *vf4)(void *, u32, u32, float, float);
typedef u32(THISCALL *vf1p)(void *, void *);
typedef u32(STDCALL *dev3)(void *, u32, u32);
typedef u32(STDCALL *dev3p)(void *, u32, const float *);

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
#define RD(T, p) (*(volatile T *)(p))

static void THISCALL renderSetup(u8 *self) {
  void *emb = self + 0x94;
  u8 *tbl = (u8 *)VT(emb, vf0, 0x18)(emb);
  if (!tbl) return;
  float w = (float)(s32)VT(self, vf0, 0xd8)(self);
  float h = (float)(s32)VT(self, vf0, 0xdc)(self);
  VT(self, vf4, 0x134)(self, 0, 0, w, h);
  u8 *d2 = *(u8 **)(self + 0x1377);
  float m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  VT(d2, dev3p, 0x94)(d2, 3, m);
  d2 = *(u8 **)(self + 0x1377);
  VT(d2, dev3p, 0x94)(d2, 2, m);
  d2 = *(u8 **)(self + 0x1377);
  VT(d2, dev3p, 0x94)(d2, 0x100, m);
  d2 = *(u8 **)(self + 0x1377);
  VT(d2, dev3p, 0x94)(d2, 0x10, m);
  u32 tex = G(u32, 0x724a48);
  if (G(u32, 0x724848) != tex) {
    u8 *dv = G(u8 *, 0x724a00);
    G(u32, 0x724848) = tex;
    VT(dv, dev3, 0xf4)(dv, 0, tex);
  }
  ext_60ff30(0, 3, 2, 0);
  ext_60feb0(0, 3, 2, 0);
  if (G(u32, 0x724a08) > 1) {
    ext_60ff30(1, 1, 2, 1);
    ext_60feb0(1, 1, 2, 1);
  }
  if (G(u32, 0x724928) != 5) {
    u8 *dv = G(u8 *, 0x724a00);
    G(u32, 0x724928) = 5;
    VT(dv, dev3, 0xc8)(dv, 0x13, 5);
  }
  if (G(u32, 0x72492c) != 6) {
    u8 *dv = G(u8 *, 0x724a00);
    G(u32, 0x72492c) = 6;
    VT(dv, dev3, 0xc8)(dv, 0x14, 6);
  }
  if (G(u32, 0x724934) != 1) {
    u8 *dv = G(u8 *, 0x724a00);
    G(u32, 0x724934) = 1;
    VT(dv, dev3, 0xc8)(dv, 0x1b, 1);
  }
  if (G(u32, 0x72493c) != 0) {
    u8 *dv = G(u8 *, 0x724a00);
    G(u32, 0x72493c) = 0;
    VT(dv, dev3, 0xc8)(dv, 0xe, 0);
  }
  d2 = *(u8 **)(self + 0x1377);
  VT(d2, dev3, 0xc8)(d2, 0x17, 8);
  for (s32 pass = 0; pass < 6; pass++) {
    bool hit = false;
    u32 iter[2];
    VT(tbl, vf1p, 0x4c)(tbl, iter);
    u8 *el = (u8 *)VT(tbl, vf1p, 0x64)(tbl, iter);
    while (el) {
      s32 mask = *(s32 *)(el + 0x1d9);
      if (mask != 0) {
        s32 bit = 0;
        s32 mk = mask;
        while (!(mk & 1)) {
          mk >>= 1;
          bit++;
        }
        if (bit == pass) {
          hit = true;
          s32 idx = (s32)VT(emb, vf0, 0x14)(emb);
          (void)RD(float, G(u8 *, 0x70039c) + 0x58);
          for (s32 j = 0; j < 0x32; j++) {
            (void)RD(u32, el + idx * 8 + 0x2c);
            (void)RD(u32, el + idx * 8 + 0x28);
            idx = (idx + 1 == 0x32) ? 0 : idx + 1;
          }
        }
      }
      el = (u8 *)VT(tbl, vf1p, 0x64)(tbl, iter);
    }
    if (hit) (void)RD(u32, self + pass * 4 + 0x116c);
  }
  d2 = *(u8 **)(self + 0x1377);
  VT(d2, dev3, 0xc8)(d2, 0x17, 4);
}
PCREG(60b6f0, renderSetup);
