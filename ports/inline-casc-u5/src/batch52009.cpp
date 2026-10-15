// batch52009.cpp - cascade tier H, batch 52009: 0x43f730 (is a point inside a box and hit by one of the listed objects).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // ret 4: out = a - b (x87)
extern "C" void FASTCALL ext_441a60(float *v, void *m);                            // plain: transforms v by the matrix m
extern "C" void FASTCALL ext_633654(u32 cookie);                                   // /GS check

static inline bool outside(float v, float lim) {
  u64 b = __builtin_bit_cast(u64, (double)v) & G(u64, 0x67cd50);
  return __builtin_bit_cast(double, b) > (double)lim;
}

// 0x43f730, thiscall(p, r) ret 8, returns bool (al), /GS. p: vec3, r: float. V = this[0x24..] - p (0x43e920); any |V[i]| (as double) > (double)(this[0x18 + 4i] - r): return 0.
// this[0x44] == 0: return 1. Else it = [this+0x44]: it->slot0x4c(&L); key = it->slot0x5c(&L); while L[0] != 0: o = table([0x70039c]+0x9b)->slot0x58(key);
// o: V = p - (o[8] + 0x24) (0x43e920), 0x441a60(&V, o[8]), when o->slot0x180(&V, r) is nonzero (al): return 1; no o: it->slot0x44(&L); then key = it->slot0x5c(&L) again. Return 0.
static u8 THISCALL fn43f730(u8 *self, float *p, float r) {
  float V[3];
  u32 L[3];
  ext_43e920(V, (float *)(self + 0x24), p);
  if (outside(V[0], *(float *)(self + 0x18) - r) || outside(V[1], *(float *)(self + 0x1c) - r) || outside(V[2], *(float *)(self + 0x20) - r)) {
    ext_633654(0);
    return 0;
  }
  u8 *it = *(u8 **)(self + 0x44);
  if (!it) {
    ext_633654(0);
    return 1;
  }
  vcall<void>(it, 0x4c, (u32)L);
  u32 key = vcall<u32>(*(u8 **)(self + 0x44), 0x5c, (u32)L);
  while (L[0] != 0) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = vcall<u8 *>(tab, 0x58, key);
    if (o) {
      u8 *m = *(u8 **)(o + 8);
      ext_43e920(V, p, (float *)(m + 0x24));
      ext_441a60(V, *(u8 **)(o + 8));
      if (vcall<u8>(o, 0x180, (u32)V, r)) {
        ext_633654(0);
        return 1;
      }
    } else {
      vcall<void>(*(u8 **)(self + 0x44), 0x44, (u32)L);
    }
    key = vcall<u32>(*(u8 **)(self + 0x44), 0x5c, (u32)L);
  }
  ext_633654(0);
  return 0;
}
PCREG(43f730, fn43f730);
