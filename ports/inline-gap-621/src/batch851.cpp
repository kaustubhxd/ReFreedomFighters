// batch851.cpp - gap band zlib stream teardown (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef void (__attribute__((cdecl)) *zfree_t)(u32 opaque, u32 ptr);

// 0x62ee40: stdcall(z) ret 4 - zlib-style stream end. -2 when z or z[0x1c] (the state) is null, or the state's kind (state[4]) is not 0x2a,
// 0x71 or 0x29a. Otherwise frees state[8], state[0x3c], state[0x38], state[0x30] (each when nonzero) and the state itself through
// z[0x24](z[0x28], ptr), clears z[0x1c], and returns -3 for kind 0x71 else 0
static s32 STDCALL streamEnd_62ee40(u8 *z) {
#define ZFREE(p) (*(zfree_t *)(z + 0x24))(*(u32 *)(z + 0x28), (u32)(p))
  if (!z) return -2;
  u8 *st = *(u8 **)(z + 0x1c);
  if (!st) return -2;
  u32 kind = *(u32 *)(st + 4);
  if (kind != 0x2a && kind != 0x71 && kind != 0x29a) return -2;
  u32 p = *(u32 *)(st + 8);
  if (p) ZFREE(p);
  p = *(u32 *)(*(u8 **)(z + 0x1c) + 0x3c);
  if (p) ZFREE(p);
  p = *(u32 *)(*(u8 **)(z + 0x1c) + 0x38);
  if (p) ZFREE(p);
  p = *(u32 *)(*(u8 **)(z + 0x1c) + 0x30);
  if (p) ZFREE(p);
  ZFREE(*(u32 *)(z + 0x1c));
  *(u32 *)(z + 0x1c) = 0;
  return kind == 0x71 ? -3 : 0;
#undef ZFREE
}
PCREG(62ee40, streamEnd_62ee40);

extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 n);                      // hooked (GUESS): new
extern "C" u32 THISCALL ext_63a800(u8 *obj, u32 a, u32 b);                    // hooked (GUESS): constructor, ret 8
extern "C" void __attribute__((cdecl)) ext_634d10(void *p, u32 v, u32 n);     // hooked (GUESS): memset
typedef u32 (THISCALL *vg1_t)(u8 *self, u32 a);

// 0x63ed60: thiscall() - first-use setup of the object's buffers, once (this[0x60] == 0): g = [0x70038c]; h = g->vt[0x48](0x8040f0);
// this[0x60] = a new 0x340c-byte object built by 0x63a800(0, this[0x10]) (0 when the allocation fails); this[0x64] = g->vt[0x0c](this[0x10]),
// memset to 0xaa; this[0x25c] = this, this[0x260] = (this[0x254] << 12) + 0x1010, this[0x264] = 1; this[0x68] = this->vt[0x20](0x4000), zeroed;
// finally g->vt[0x48](h)
static void THISCALL initBuffers_63ed60(u8 *self) {
  if (*(u32 *)(self + 0x60) != 0) return;
  u8 *g = G(u8 *, 0x70038c);
  u32 h = (*(vg1_t *)(*(u8 **)g + 0x48))(g, 0x8040f0);
  u8 *p = ext_41e290(0x340c);
  u32 r = 0;
  if (p) r = ext_63a800(p, 0, *(u32 *)(self + 0x10));
  *(u32 *)(self + 0x60) = r;
  g = G(u8 *, 0x70038c);
  u32 q = (*(vg1_t *)(*(u8 **)g + 0xc))(g, *(u32 *)(self + 0x10));
  *(u32 *)(self + 0x64) = q;
  ext_634d10((void *)q, 0xaa, *(u32 *)(self + 0x10));
  u32 sz = (*(u32 *)(self + 0x254) << 12) + 0x1010;
  *(u8 **)(self + 0x25c) = self;
  *(u32 *)(self + 0x260) = sz;
  *(u32 *)(self + 0x264) = 1;
  u32 v = (*(vg1_t *)(*(u8 **)self + 0x20))(self, 0x4000);
  *(u32 *)(self + 0x68) = v;
  ext_634d10((void *)v, 0, 0x4000);
  g = G(u8 *, 0x70038c);
  (*(vg1_t *)(*(u8 **)g + 0x48))(g, h);
}
PCREG(63ed60, initBuffers_63ed60);
