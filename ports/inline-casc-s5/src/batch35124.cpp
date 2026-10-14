// batch35124.cpp - cascade s5 batch 35124: 0x5eef20 (GUESS read a record from stream s into this, then let three children read from s too).
#include "ff.h"

extern "C" void THISCALL ext_5eecd0(u8 *self);   // plain ret
typedef void(THISCALL *v1p_t)(void *, void *);
typedef void(THISCALL *v1_t)(void *, void *);

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5eef20, thiscall(s) ret 4. s slot 0x68(this + 0x10); s slot 0x40(&v) twice (v a stack dword the slot fills): unaligned dwords +0x11 and +0x15 take the two values; s slot 0x48(this + 0x19) and s slot 0x48(this + 0x1d);
// 0x5eecd0(this); the objects at [this+4], [this+8] and [this+0xc] are each asked slot 0xc(s).
static void THISCALL fn5eef20(u8 *self, u8 *s) {
  u32 v = 0;
  (*(v1p_t **)s)[0x68 / 4](s, self + 0x10);
  (*(v1p_t **)s)[0x40 / 4](s, &v);
  wr32u(self + 0x11, v);
  (*(v1p_t **)s)[0x40 / 4](s, &v);
  wr32u(self + 0x15, v);
  (*(v1p_t **)s)[0x48 / 4](s, self + 0x19);
  (*(v1p_t **)s)[0x48 / 4](s, self + 0x1d);
  ext_5eecd0(self);
  for (int off = 4; off <= 0xc; off += 4) {
    u8 *c = *(u8 **)(self + off);
    (*(v1_t **)c)[0xc / 4](c, s);
  }
}
PCREG(5eef20, fn5eef20);
