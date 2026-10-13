// batch117.cpp - ZPlayer::CalcAnimRemapNames (climb thread, batch 117). Names from the GC map (high).
#include "ff.h"

extern "C" void THISCALL ext_472460(void *lnkHands);  // ZLNKWHANDS::CalcAnimRemapNames (not lifted; original code)

// 0x481530, thiscall, void. First the hands' remap names (ZLNKWHANDS::CalcAnimRemapNames). Then the list of count (+0x459)
// objects in the slots at +0x45d (last slot first): each non-null object gets its slot 0x20 call (the object's own
// remap, inferred: animation names are re-derived for each attached item).
static void THISCALL playerCalcAnimRemapNames(u8 *self) {
  ext_472460(self);
  u32 n = *(u32 *)(self + 0x459);
  if (!n)
    return;
  u8 *p = self + 0x45d + n * 4;
  do {
    void *o = *(void **)p;
    if (o)
      vcall<void>(o, 0x20);
    p -= 4;
    n--;
  } while (n);
}
PCREG(481530, playerCalcAnimRemapNames);
