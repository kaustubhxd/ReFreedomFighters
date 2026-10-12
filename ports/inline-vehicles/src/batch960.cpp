// batch960.cpp - residue-04 (core todo), batch 960: ZMoveOnSpline::ClassInit2, 0x5124c0 (thiscall, no args): calls 0x45d3a0
// (exe, 145 instructions with an exception frame, stood in by the checker) and then tail-jumps to the body 0x5124d0
// (batch 959, exact).
#include "ff.h"

extern "C" void THISCALL ext_45d3a0(void *self);   // exe (stood in by the checker)

extern "C" void THISCALL ext_5124d0(void *self);   // body (batch 959, exact)

// 0x5124c0 ZMoveOnSpline::ClassInit2().
static void THISCALL zmosClassInit2(u8 *t) {
  ext_45d3a0(t);
  ext_5124d0(t);
}
PCREG(5124c0, zmosClassInit2);
