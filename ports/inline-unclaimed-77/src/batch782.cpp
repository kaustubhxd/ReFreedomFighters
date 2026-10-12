// batch782.cpp - unclaimed-77 claim 12 (docs/20-unclaimed-77.md): ZActorIf::BeamToNearestPathfinderPoint(OpaqueCallParameters_t&)
// (medium). Thiscall, one argument, ret 4. The helper 0x5003d0, the virtual slots, and the bool callee are stubbed in the harness
// (GUESS); 0x5002f0 is the original code. The assert paths and the null-hook traps are excluded; the CRT cookie check is not reproduced.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);     // stubbed (GUESS): indexed accessor, one argument, ret 4
extern "C" void THISCALL ext_5002f0(u8 *p, u32 flag);       // original code: sets p[0] = flag and p[4] = 1 (byte in 0 or 1)

// 0x506500, ZActorIf::BeamToNearestPathfinderPoint(OpaqueCallParameters_t&) (medium).
static void THISCALL actorIfBeamToNearestPathfinderPoint(u8 *self, u8 *P) {
  u8 *p = ext_5003d0(*(void **)(P + 4), 0);
  float L0 = *(float *)p;
  p = ext_5003d0(*(void **)(P + 4), 1);
  float L1 = *(float *)p;
  p = ext_5003d0(*(void **)(P + 4), 2);
  float L2 = *(float *)p;
  p = ext_5003d0(*(void **)(P + 8), 0);
  ext_5002f0(p, 1);

  float out1[3];   // the exe's local at ebp-0x10: x, y, z
  u32 out2[3];     // the exe's local at ebp-0x34
  void *O = *(void **)(self + 0x18);
  void **vt = *(void ***)O;
  ((void (THISCALL *)(void *, void *, void *))(*(void **)((u8 *)vt + 0x57c)))(O, out2, out1);
  void *Q = ((void *(THISCALL *)(void *))(*(void **)((u8 *)vt + 0x5d0)))(O);
  if (Q != 0) {
    // addss xmm0, [0x67da24] (30.0) on out1.y
    out1[1] = out1[1] + 30.0f;
    void **vtq = *(void ***)Q;
    u8 r = ((u8 (THISCALL *)(void *, void *, float, float, float))(*(void **)((u8 *)vtq + 0x218)))(Q, out1, L0, L1, L2);
    u32 flag = 0;
    if (r != 0) {
      ((void (THISCALL *)(void *, void *, void *))(*(void **)((u8 *)vt + 0x370)))(O, out2, out1);
      flag = 1;
    }
    p = ext_5003d0(*(void **)(P + 8), 0);
    ext_5002f0(p, flag);
  }
  // (the CRT security-cookie check at 0x633654 is not reproduced)
}
PCREG(506500, actorIfBeamToNearestPathfinderPoint);
