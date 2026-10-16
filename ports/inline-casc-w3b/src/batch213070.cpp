#include "ff.h"

extern "C" float FASTCALL ext_4e0830(void *a, void *p);
extern "C" void THISCALL ext_662cf0(void *self);
extern "C" u32 THISCALL ext_6627c0(void *self, float *ref);
extern "C" void FASTCALL ext_443ef0(void *p, void *q, void *r, float f);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x662c50: thiscall(a) ret 4 -> bool in AL: a is a 3-float vector, this+4 the current vector. When 0x4e0830(a, this+4) (a float distance) is above the
// exe constant 0.1f [0x67a284] (an unordered result does not count) the current vector is replaced by a and 0x662cf0(this) runs. Then the float at this+0x34 goes through
// 0x6627c0(this+0x34, &f) (which may change f, returns the AL result), 0x443ef0(this+4, this+0x1c, this+0x28, f) updates the current vector and it is copied back to a.
extern "C" u8 THISCALL fn_662c50(u8 *self, u8 *a) {
  u8 *p = self + 4;
  float d = ext_4e0830(a, p);
  if (d > G(float, 0x67a284)) {
    wr32u(p, rd32u(a));
    wr32u(p + 4, rd32u(a + 4));
    wr32u(p + 8, rd32u(a + 8));
    ext_662cf0(self);
  }
  float f;
  __builtin_memcpy(&f, self + 0x34, 4);
  u8 r = (u8)ext_6627c0(self + 0x34, &f);
  ext_443ef0(p, self + 0x1c, self + 0x28, f);
  wr32u(a, rd32u(p));
  wr32u(a + 4, rd32u(p + 4));
  wr32u(a + 8, rd32u(p + 8));
  return r;
}
PCREG(662c50, fn_662c50);
