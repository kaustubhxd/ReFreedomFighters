// batch35086.cpp - cascade s5 batch 35086: 0x6060a0 (GUESS write a header and one converted value per entry to a stream).
#include "ff.h"

extern "C" u32 ext_602d30();                                   // returns a singleton (plain ret)
extern "C" u32 THISCALL ext_602d80(u32 self, u32 v, u32 x);    // thiscall, ret 8
typedef void(THISCALL *v1_t)(void *, u32);

// 0x6060a0, thiscall(s, x) ret 8. s slot 0x40(this + 0xc), s slot 0x2c([this+0x18]), s slot 0x30([this+8]); then for i < [this+8] (re-read each round): s slot 0x30(0x602d80(0x602d30(), [[this]+4*i], x)).
// (The exe's check i < n before the first round, with the assert hook otherwise, cannot fail when n != 0.)
static void THISCALL fn6060a0(u8 *self, u8 *s, u32 x) {
  (*(v1_t **)s)[0x40 / 4](s, (u32)(self + 0xc));
  (*(v1_t **)s)[0x2c / 4](s, *(u32 *)(self + 0x18));
  (*(v1_t **)s)[0x30 / 4](s, *(u32 *)(self + 8));
  u32 n = *(u32 *)(self + 8);
  if (n == 0) return;
  u32 i = 0;
  do {
    u32 v = ((u32 *)*(u32 *)self)[i];
    u32 f = (*(u32 **)s)[0x30 / 4];
    u32 r1 = ext_602d30();
    u32 r2 = ext_602d80(r1, v, x);
    ((v1_t)f)(s, r2);
    i++;
    n = *(u32 *)(self + 8);
  } while (i < n);
}
PCREG(6060a0, fn6060a0);
