// batch35171.cpp - cascade s5 batch 35171: 0x428100 (GUESS format a message into a local buffer, run it through the console object and compare the result).
#include "ff.h"

typedef void(THISCALL *f3_t)(void *, u8 *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *p4_t)(void *, u8 *, u32, u32, u32);
typedef u32(THISCALL *g2_t)(void *, u8 *, u32);

// 0x428100, thiscall(a, b, c, d) ret 0x10, returns al = (r == b) (the stack cookie is not reproduced). buf[0x400]; this slot 0x144(buf, c, d); L = [0x700394]: L slot 0x4c([this+0xc]) (vtable read first);
// L slot 0x64(buf, a, b, 0); r = L slot 0x30(buf, 0); returns r == b.
static u8 THISCALL fn428100(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u8 buf[0x400];
  (*(f3_t **)self)[0x144 / 4](self, buf, c, d);
  u8 *L = G(u8 *, 0x700394);
  u32 *vt = *(u32 **)L;
  u32 w = *(u32 *)(self + 0xc);
  L = G(u8 *, 0x700394);
  ((v1_t)vt[0x4c / 4])(L, w);
  L = G(u8 *, 0x700394);
  (*(p4_t **)L)[0x64 / 4](L, buf, a, b, 0);
  L = G(u8 *, 0x700394);
  u32 r = (*(g2_t **)L)[0x30 / 4](L, buf, 0);
  return r == b;
}
PCREG(428100, fn428100);
