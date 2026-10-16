// batch3409.cpp - area 73 batch 9 (residue 12): ZActorIf::addMethodDefinitions(OpaqueMethodList_t&) (0x508680).
// Same shape as ZFFHeroIf::addMethodDefinitions (batch 3905 of area 07, batch1019): 53 blocks, each adding one function
// address to the table at 0x701050 (count at 0x701048, limit 0x35). The error path calls slot +0x44(0x69cfe4) and the assert at
// 0x7003b0. The tail is 0x505a00(list) on this, after clearing the list byte at +0xc.
#include "ff.h"

// 0x505a00: thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_505a00(u8 *self, u8 *list);

// 0x508680, ZActorIf::addMethodDefinitions(OpaqueMethodList_t&) (high), thiscall, ret 4.
static void THISCALL actorIfAddMethodDefinitions(u8 *self, u8 *list) {
  static const u32 fns[53] = {
    0x508640, 0x508290, 0x506a80, 0x507e40, 0x6368b0, 0x507c60,
    0x508100, 0x507e50, 0x507370, 0x507420, 0x507630, 0x507510,
    0x507710, 0x507810, 0x506960, 0x5063d0, 0x5066e0, 0x5081f0,
    0x5083d0, 0x508180, 0x508220, 0x508260, 0x508070, 0x5079b0,
    0x5083a0, 0x508620, 0x508560, 0x5085e0, 0x508530, 0x506e80,
    0x506be0, 0x5081c0, 0x506b70, 0x506b60, 0x5072c0, 0x5072f0,
    0x507f10, 0x506500, 0x5064a0, 0x506ee0, 0x506b80, 0x506bb0,
    0x5063a0, 0x5084a0, 0x508410, 0x5080a0, 0x5079c0, 0x507b40,
    0x507240, 0x5080d0, 0x5082c0, 0x507ee0, 0x610100};
  for (u32 k = 0; k < 53; k++) {
    if (list[0xc] == 0)
      break;
    u32 count = G(u32, 0x701048);
    if (count < 0x35) {
      G(u32, 0x701050 + 4 * count) = fns[k];
      G(u32, 0x701048) = count + 1;
    } else {
      vcall<void>(self, 0x44, 0x69cfe4u);
      void *assertp = G(void *, 0x7003b0);
      if (assertp)
        ((void(__attribute__((cdecl)) *)(void))assertp)();
    }
  }
  list[0xc] = 0;
  ext_505a00(self, list);
}
PCREG(508680, actorIfAddMethodDefinitions);
