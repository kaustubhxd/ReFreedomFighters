// batch963.cpp - residue-05 (core todo), batch 963.
//   0x5e7590: mov al,1; ret 0xc (thiscall, three ignored stack args). Returns true.
//   0x46ba90: push ebp; mov ebp,esp; pop ebp; jmp 0x46b800 (tail to the thiscall(this, a, b) of ret 8; stood in by the
//             checker). The port forwards this, a, b and returns the target's EAX.
//   0x514410: ZMoveOnSpline::SetNextPath(unsigned int, float): calls 0x523b90 (thiscall(child, idx, float), ret 8; stood in)
//             on the child at [this+0x5c].
#include "ff.h"

extern "C" u32 THISCALL ext_46b800(void *self, u32 a, u32 b);      // stood in by the checker
extern "C" void THISCALL ext_523b90(void *self, u32 idx, float d);  // stood in by the checker

// 0x5e7590 (GUESS FUN_5e7590).
static u8 THISCALL trivialTrue5e7590(u8 *t, u32 a, u32 b, u32 c) {
  (void)t; (void)a; (void)b; (void)c;
  return 1;
}
PCREG(5e7590, trivialTrue5e7590);

// 0x46ba90 (GUESS FUN_46ba90), a tail to 0x46b800.
static u32 THISCALL fwd46ba90(u8 *t, u32 a, u32 b) {
  return ext_46b800(t, a, b);
}
PCREG(46ba90, fwd46ba90);

// 0x514410 ZMoveOnSpline::SetNextPath(unsigned int, float).
static void THISCALL setNextPath(u8 *t, u32 idx, float d) {
  u8 *child = *(u8 **)(t + 0x5c);
  ext_523b90(child, idx, d);
}
PCREG(514410, setNextPath);
