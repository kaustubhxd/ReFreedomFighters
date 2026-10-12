// batch780.cpp - unclaimed-77 claim 10 (docs/20-unclaimed-77.md): ZMoveOnSplineIf::FindSplineVal(OpaqueCallParameters_t&) (medium).
// Thiscall, one argument, ret 4. H (0x5003d0) and the virtual slot 0x2fc are stubbed in the harness (GUESS). The assert paths
// (a zero dword at p1; a byte at p4+4 other than 0 or 2) are excluded, as are the null-hook traps they reach.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);   // stubbed (GUESS): indexed accessor, one argument, ret 4

// 0x5194c0 (medium).
static void THISCALL zMoveOnSplineFindSplineVal(u8 *self, u8 *arg) {
  u8 *p1 = ext_5003d0(*(void **)(arg + 4), 0);
  (void)p1;   // the exe checks *p1 != 0 here; the assert path for zero is excluded (the harness keeps it nonzero)
  u8 *p2 = ext_5003d0(*(void **)(arg + 4), 1);
  u8 *p3 = ext_5003d0(*(void **)(arg + 4), 0);
  float v = *(float *)p2;
  void *obj = *(void **)(self + 0x14);
  void **vt = *(void ***)obj;
  float r = ((float (THISCALL *)(void *, u32, float))(*(void **)((u8 *)vt + 0x2fc)))(obj, *(u32 *)p3, v);
  u8 *p4 = ext_5003d0(*(void **)(arg + 8), 0);
  // the exe checks byte p4+4 against 0 and 2 here; the other value is the excluded assert path
  p4[4] = 2;
  *(float *)p4 = r;
}
PCREG(5194c0, zMoveOnSplineFindSplineVal);
