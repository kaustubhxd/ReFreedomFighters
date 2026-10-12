// batch6317.cpp - unclaimed-63 batch 17 (docs/20-unclaimed-63.md): two parked functions, now ported. 0x5002f0 is ret 4 (one stack
// word), and 0x5003d0 is ret 4 (one stack word), per docs/20-area 20. The second pushed word of each call site is therefore the
// argument of the next call (or a leftover that the next call pops), which explains the push counts.
//   0x51b1e0 (GUESS, no GC name; thiscall, one argument P, ret 4): r = [this+0x1c]->vtbl[+0x374]() (no arguments);
//     f = 0x5003d0(ECX = [P+8], 0); 0x5002f0(ECX = f, r) (r is the leftover pushed before the 0 and popped by 0x5002f0).
//   0x559ee0 (GUESS, no GC name; thiscall, one argument P, ret 4): t = [[this+0x1c]+0x54]+8; if t == 2 flag = 0, if t == 3
//     flag = 1, otherwise return. B = [[0x7003b8]+0x2c15]; r = 0x59d130(ECX = B; flag) (one stack argument); f = 0x5003d0(ECX =
//     [P+8], 0); 0x5002f0(ECX = f, r). Returns with ret 4.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);         // ret 4, original, stubbed by the spec
extern "C" void THISCALL ext_5002f0(void *self, u32 a);        // ret 4, original, stubbed by the spec
extern "C" u32 THISCALL ext_59d130(void *self, u32 flag);      // one stack argument, original, stubbed by the spec

typedef u32(THISCALL * call0_fn)(void *);

// 0x51b1e0 (GUESS).
static void THISCALL unnamed51b1e0(u8 *self, u8 *p) {
  u32 o = *(u32 *)(self + 0x1c);
  u32 r = ((call0_fn)(*(u32 *)(*(u32 *)o + 0x374)))((void *)o);
  u32 f = ext_5003d0((void *)*(u32 *)(p + 8), 0);
  ext_5002f0((void *)f, r);
}
PCREG(51b1e0, unnamed51b1e0);

// 0x559ee0 (GUESS).
static void THISCALL unnamed559ee0(u8 *self, u8 *p) {
  u32 t = *(u32 *)(*(u32 *)(*(u32 *)(self + 0x1c) + 0x54) + 8);
  if (t != 2 && t != 3)
    return;
  u32 flag = (t == 2) ? 0u : 1u;
  u32 a = G(u32, 0x7003b8);
  u32 b = *(u32 *)(a + 0x2c15);
  u32 r = ext_59d130((void *)b, flag);
  u32 f = ext_5003d0((void *)*(u32 *)(p + 8), 0);
  ext_5002f0((void *)f, r);
}
PCREG(559ee0, unnamed559ee0);
