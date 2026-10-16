// batch210070.cpp - Sonnet-w3a: two thin wrappers (clear a global table; forward the second argument)
#include "ff.h"

extern "C" u32 ext_634d10(u32 dst, u32 val, u32 n);
extern "C" u32 ext_63a700(u32 a);

static u32 fn6038e0() {
  u32 r = ext_634d10(0x7246a0, 0, 0xc8);  // @6038e0_a
  G(u32, 0x724698) = 0;  // @6038e0_b
  return r;
}
PCREG(6038e0, fn6038e0);

static u32 fn631840(u32 a, u32 b) {
  (void)a;
  return ext_63a700(b);  // @631840_a
}
PCREG(631840, fn631840);
