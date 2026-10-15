// batch103.cpp - the climb-out-of-the-sewer action (climb thread, batch 103).
#include "ff.h"

extern "C" void *THISCALL ext_59b3c0(void *levelController);   // ZFFLevelController::GetStartingSewerLid (batch 102)

// 0x5e0100, ZFFActionClimbSewer::Execute() (GC map high). thiscall, no args, returns a bool in AL.
// this+8 = the hero, this+0xc = the climb animation (AnimHeader*, "Climb_Up_Sewer" in ZFFHERO::CalcAnimRemapNames).
//  - No animation: returns 1 (done at once).
//  - The level controller is the game data's +0x2c15 (unaligned). None, or no starting lid: returns 0.
//  - The hero's start point is the lid geom's child matching "MO_Sewer_HeroPos_*" (lid->slot 0x20()->slot 0x20(), then
//    slot 0x25c(pattern, 0): find a child by wildcard name), else the child matching "MO_Sewer_Manhole_*", else the lid.
//    Its matrix and position come from its slot 0x80(mat, pos).
//  - The hero plays the animation: hero slot 0x228(anim, 1, then three floats by value: 0, -1, 1), and is placed there:
//    hero->slot 0x20()->slot 0x74(mat, pos). Returns 0 (the action keeps running until the animation ends).
static bool THISCALL climbSewerExecute(u8 *self) {
  void *anim = *(void **)(self + 0xc);
  if (!anim)
    return true;
  void *lc = *(void **)(G(u8 *, 0x7003b8) + 0x2c15);
  if (!lc)
    return false;
  void *lid = ext_59b3c0(lc);
  if (!lid)
    return false;
  void *a = vcall<void *>(vcall<void *>(lid, 0x20), 0x20);
  void *g = vcall<void *>(a, 0x25c, (const char *)0x6b74e8, 0u);   // "MO_Sewer_HeroPos_*"
  if (!g) {
    a = vcall<void *>(vcall<void *>(lid, 0x20), 0x20);
    g = vcall<void *>(a, 0x25c, (const char *)0x6b74fc, 0u);       // "MO_Sewer_Manhole_*"
    if (!g)
      g = lid;
  }
  float mat[9], pos[3];
  vcall<void>(g, 0x80, mat, pos);
  void *hero = *(void **)(self + 8);
  vcall<void>(hero, 0x228, anim, 1u, 0.0f, -1.0f, 1.0f);
  void *h = vcall<void *>(*(void **)(self + 8), 0x20);
  vcall<void>(h, 0x74, mat, pos);
  return false;
}
PCREG(5e0100, climbSewerExecute);
