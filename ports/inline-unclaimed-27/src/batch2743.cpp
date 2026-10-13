#include "ff.h"
// batch2743.cpp - unclaimed-27 batch 45 (residue 6). Three copies of the splice in batch 44 with their own globals. Names unknown (GUESS).
template <u32 CG, u32 AG>
static void funcSpliceAt() {
  u32 c = G(u32, CG);
  u32 a = G(u32, AG);
  if (c != 0) {
    *(u32 *)(unsigned long)(c + 0x14) = a;
    a = G(u32, AG);
    c = G(u32, CG);
  } else {
    G(u32, 0x7003bc) = a;
  }
  if (a != 0) {
    *(u32 *)(unsigned long)(a + 0x10) = c;
  } else {
    G(u32, 0x7003c0) = c;
  }
  G(u32, CG) = 0;
  G(u32, AG) = 0;
}

static void funcSplice670120() { funcSpliceAt<0x6e5b00u, 0x6e5b04u>(); }
PCREG(670120, funcSplice670120);
static void funcSplice670260() { funcSpliceAt<0x6e5b9cu, 0x6e5ba0u>(); }
PCREG(670260, funcSplice670260);
static void funcSplice6703a0() { funcSpliceAt<0x6e5df0u, 0x6e5df4u>(); }
PCREG(6703a0, funcSplice6703a0);
