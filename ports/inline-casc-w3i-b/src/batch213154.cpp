#include "ff.h"

typedef void(THISCALL *V2)(void *, void *, void *);
typedef void(THISCALL *V1)(void *, void *);
typedef void(THISCALL *V4)(void *, void *, void *, void *, u32);

extern "C" void THISCALL ext_4daf90(void *node, void *out);
extern "C" void THISCALL ext_4db7c0(void *node, void *out);
extern "C" void THISCALL ext_4db600(void *node, void *m, void *v);
extern "C" void THISCALL ext_4de7a0(void *m);
extern "C" void THISCALL ext_4e0d00(void *v, float s);
extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);
extern "C" void FASTCALL ext_43e8e0(void *out, void *a, void *b);
extern "C" void FASTCALL ext_43e960(void *out, void *a);
extern "C" void FASTCALL ext_441940(void *out, void *a);
extern "C" void FASTCALL ext_4e2c60(void *m, void *v);
extern "C" void FASTCALL ext_4e0900(void *a, void *b);
extern "C" void FASTCALL ext_4e08d0(void *a, void *b);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32(const u8 *p) { return *(const u32 *)p; }

// 0x443080: thiscall(a) ret 4 -> float in st0, /GS. Gathers the bounding vectors of every node in the list this[8] (iterator: this slot 0x50(&node)): v34 / v40 start
// as a - pos and a - size of this[8], and each node whose property flags (default 0x200002) contain 0x800000, or whose flags [node+0x3c] contain 0x80000, contributes its
// position / size transformed by its matrix (0x4db600, this slot 0x94 and, for the second kind, node-item slot 0x64) through 0x4e0900 / 0x4e08d0. Finally the 0.1-scaled
// vectors are combined (0x43e960, 0x441940, 0x43e920, 0x4e0d00(0.5)), 0x43e8e0 writes the result into a, and the largest component of v28 is returned.
// The locals keep the original frame layout (the real helpers write to them): ebp = fr + 0xa8.
extern "C" float THISCALL fn_443080(u8 *self, u8 *a);
static float body_443080(u8 *self, u8 *a) {
  u8 fr[0xc0];
  u8 *ebp = fr + 0xa8;
#define L(x) ((void *)(ebp - (x)))
  ext_4daf90(*(void **)(self + 8), a);
  ext_4db7c0(*(void **)(self + 8), L(0x28));
  ext_43e920(L(0x34), a, L(0x28));
  ext_43e8e0(L(0x40), a, L(0x28));
  u8 *node = *(u8 **)(self + 8);
  *(u8 **)L(0x98) = node;
  while (node) {
    u8 *item = (u8 *)rd32(node + 0x54);
    u32 flags = item ? rd32((u8 *)rd32(item + 0xc) + 0x23) : 0x200002;
    if (flags & 0x800000) {
      ext_4daf90(node, L(0x10));
      ext_4db7c0(node, L(0x1c));
      ext_4de7a0(L(0x64));
      ext_4db600(node, L(0x64), L(0x10));
      (*(V2 *)(*(u8 **)self + 0x94))(self, L(0x64), L(0x10));
      ext_4e2c60(L(0x64), L(0x1c));
      ext_43e920(L(0x70), L(0x10), L(0x1c));
      ext_43e8e0(L(0x7c), L(0x10), L(0x1c));
      ext_4e0900(L(0x34), L(0x70));
      ext_4e08d0(L(0x40), L(0x7c));
      node = *(u8 **)L(0x98);
    }
    if (rd32(node + 0x3c) & 0x80000) {
      ext_4daf90(node, L(0x10));
      ext_4db7c0(node, L(0x1c));
      ext_4de7a0(L(0x64));
      ext_4db600(node, L(0x64), L(0x10));
      u8 *it2 = (u8 *)rd32(node + 0x54);
      if (it2) (*(V4 *)(*(u8 **)it2 + 0x64))(it2, L(0x64), L(0x10), L(0x1c), 0);
      (*(V2 *)(*(u8 **)self + 0x94))(self, L(0x64), L(0x10));
      ext_4e2c60(L(0x64), L(0x1c));
      ext_43e920(L(0x88), L(0x10), L(0x1c));
      ext_43e8e0(L(0x94), L(0x10), L(0x1c));
      ext_4e0900(L(0x34), L(0x88));
      ext_4e08d0(L(0x40), L(0x94));
    }
    (*(V1 *)(*(u8 **)self + 0x50))(self, L(0x98));
    node = *(u8 **)L(0x98);
  }
  float *sc = (float *)L(0xa4);
  sc[0] = 0.1f;
  sc[1] = 0.1f;
  sc[2] = 0.1f;
  ext_43e960(L(0x34), sc);
  ext_441940(L(0x40), sc);
  ext_43e920(L(0x28), L(0x40), L(0x34));
  ext_4e0d00(L(0x28), 0.5f);
  ext_43e8e0(a, L(0x34), L(0x28));
  float x = *(float *)L(0x28), y = *(float *)L(0x24), z = *(float *)L(0x20);
  float m1 = y > x ? y : x;
  return z > m1 ? z : m1;
}
extern "C" float THISCALL fn_443080(u8 *self, u8 *a) {
  float r = body_443080(self, a);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(443080, fn_443080);
