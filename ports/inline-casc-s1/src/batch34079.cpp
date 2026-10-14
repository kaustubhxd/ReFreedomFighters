// batch34079.cpp - cascade tier E, batch 34079: 0x61bb20 (re-create a handle and register callbacks), 0x620b30 (probe a table then dispatch), 0x405690 (free a nested record and clear it).
#include "ff.h"

extern "C" void ext_61c3d0(u32 h);
extern "C" u32 ext_61bfa0(u32 a, u32 b, u32 c, u32 d);
extern "C" void ext_61c640(u32 h, void *ctx);
extern "C" void ext_61c5c0(u32 h, u32 a, u32 b);
extern "C" void ext_61c590(u32 h, u32 a);
extern "C" void ext_61c620(u32 h, u32 a);
extern "C" void ext_61c5a0(u32 h, u32 a);
extern "C" void ext_61c630(u32 h, u32 a);
extern "C" void ext_61c610(u32 h, u32 a);
extern "C" void ext_61c600(u32 h, u32 a);
extern "C" u32 ext_61c5e0(u32 h, u32 a, u32 b);
extern "C" u32 ext_61fbc0(void *a, u32 b);
extern "C" u32 ext_61dcd0(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern "C" void ext_634d52(void *p);

// 0x61bb20, thiscall, plain ret: when [this+4] is set ext_61c3d0([this+4]); h = ext_61bfa0(0, 0x63a720, 0x63a770, 0x63a700); [this+4] = h; ext_61c640(h, this); then the callbacks are registered on [this+4]
// with exe code addresses (0x61c5c0: 0x61bcc0, 0x61bc50; 0x61c590: 0x61bc10; 0x61c620: 0x61bca0; 0x61c5a0: 0x61bc30; 0x61c630: 0x61bd00; 0x61c610: 0x61bc80; 0x61c600: 0x61bc70; 0x61c5e0: 0x61bce0, 0x61bc60);
// returns the result of the last call.
static u32 THISCALL fn61bb20(u8 *self) {
  if (*(u32 *)(self + 4)) ext_61c3d0(*(u32 *)(self + 4));
  u32 h = ext_61bfa0(0, 0x63a720, 0x63a770, 0x63a700);
  *(u32 *)(self + 4) = h;
  ext_61c640(h, self);
  ext_61c5c0(*(u32 *)(self + 4), 0x61bcc0, 0x61bc50);
  ext_61c590(*(u32 *)(self + 4), 0x61bc10);
  ext_61c620(*(u32 *)(self + 4), 0x61bca0);
  ext_61c5a0(*(u32 *)(self + 4), 0x61bc30);
  ext_61c630(*(u32 *)(self + 4), 0x61bd00);
  ext_61c610(*(u32 *)(self + 4), 0x61bc80);
  ext_61c600(*(u32 *)(self + 4), 0x61bc70);
  return ext_61c5e0(*(u32 *)(self + 4), 0x61bce0, 0x61bc60);
}
PCREG(61bb20, fn61bb20);

typedef u32 (*pf3)(u32, u32, u32);
typedef u32 (*pfobj)(u32, u32, u32, u32 *);

// 0x620b30, cdecl(a, b, c, d): r = f(a+0x90, a+0x8c, [a+0xe4]) with f = 0x626ac0 when [a+0xe8] is non-zero, else 0x626a80. When r is zero: z = ext_61fbc0(a, [a+0xe4]); non-zero z is returned.
// Then [a+0x110] = 0x620bc0; x = (*(u32 *)P)(P, b, c, &aa) with P = [a+0x8c] and aa a stack copy of a (the callee may change it); returns ext_61dcd0(a, [a+0x8c], b, c, x, aa, d).
static u32 fn620b30(u8 *a, u32 b, u32 c, u32 d) {
  u32 aa = (u32)a;
  pf3 f = *(u32 *)(a + 0xe8) != 0 ? (pf3)0x626ac0 : (pf3)0x626a80;
  u32 r = f((u32)(a + 0x90), (u32)(a + 0x8c), *(u32 *)(a + 0xe4));
  if (r == 0) {
    u32 z = ext_61fbc0(a, *(u32 *)(a + 0xe4));
    if (z != 0) return z;
  }
  u32 P = *(u32 *)(a + 0x8c);
  *(u32 *)(a + 0x110) = 0x620bc0;
  u32 x = (*(pfobj *)P)(P, b, c, &aa);
  return ext_61dcd0(a, *(u32 *)(a + 0x8c), b, c, x, aa, d);
}
PCREG(620b30, fn620b30);

// 0x405690, cdecl(p), returns 0: when q = [p+0x14] is set: frees [q], [q+4], [q+0xc], [q+0x10] (reading q each time), zeroes 6 dwords at [p+0x14], frees [p+0x14]. Frees [p+0xc] and [p+0x10] when set, then zeroes 7 dwords at p.
static u32 fn405690(u32 *p) {
  if (p[5]) {
    ext_634d52((void *)*(u32 *)p[5]);
    ext_634d52((void *)((u32 *)p[5])[1]);
    ext_634d52((void *)((u32 *)p[5])[3]);
    ext_634d52((void *)((u32 *)p[5])[4]);
    u32 *z = (u32 *)p[5];
    for (int i = 0; i < 6; i++) z[i] = 0;
    ext_634d52((void *)p[5]);
  }
  if (p[3]) ext_634d52((void *)p[3]);
  if (p[4]) ext_634d52((void *)p[4]);
  for (int i = 0; i < 7; i++) p[i] = 0;
  return 0;
}
PCREG(405690, fn405690);
