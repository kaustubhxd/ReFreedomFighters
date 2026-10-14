// batch35157.cpp - cascade s5 batch 35157: 0x51c3d0 (GUESS create a child object from this, place it and apply a transform).
#include "ff.h"

extern "C" void THISCALL ext_4db670(u8 *self, u32 *out);          // thiscall, ret 4
extern "C" void THISCALL ext_4de7a0(u8 *self);                    // thiscall, plain ret (constructs 0x24 bytes)
extern "C" void THISCALL ext_4dcb50(u8 *self, u8 *a, u32 *b);     // thiscall, ret 8
typedef u8 *(THISCALL *c3_t)(void *, u32, void *, u32);
typedef void(THISCALL *v1p_t)(void *, u32 *);
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x51c3d0, thiscall(a) ret 4, returns the child (the stack cookie is not reproduced). ch = this slot 0x328([this+0x451] (unaligned), this, 0x484c5732); v = {0, -85.0f, 0} (dwords 0, 0xc2aa0000, 0);
// 0x4db670(a, v); this slot 0x8c(v); 0x4de7a0(local); 0x4dcb50([ch+8], local, v); ch slot 0xbc(1). Returns ch.
static u8 *THISCALL fn51c3d0(u8 *self, u8 *a) {
  u32 v[3];
  u8 local[0x24];
  u8 *ch = (*(c3_t **)self)[0x328 / 4](self, rd32u(self + 0x451), self, 0x484c5732);
  v[2] = 0;
  v[0] = 0;
  v[1] = 0xc2aa0000;
  ext_4db670(a, v);
  (*(v1p_t **)self)[0x8c / 4](self, v);
  ext_4de7a0(local);
  ext_4dcb50(*(u8 **)(ch + 8), local, v);
  (*(v1_t **)ch)[0xbc / 4](ch, 1);
  return ch;
}
PCREG(51c3d0, fn51c3d0);
