// batch1019.cpp - unclaimed-07 batch 19 (residue-07): ZFFHeroIf::addMethodDefinitions(OpaqueMethodList_t&).
// Name from the name map. Body from the PC bytes: six blocks, each adding one function address to the global table
// at 0x7140d0 (count at 0x7140c8, at most 0x32 entries). When the count is full, the object's slot +0x44(0x6a5ea4) is called
// and the assert pointer at 0x7003b0 is called (no arguments). Each block first checks the list's byte at +0xc: when
// it is zero, the function clears it and calls 0x505a00(list) on this. The same tail runs after the last block.
#include "ff.h"

// 0x505a00: thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_505a00(u8 *self, u8 *list);

// 0x55f6b0, ZFFHeroIf::addMethodDefinitions(OpaqueMethodList_t&) (high), thiscall, ret 4.
static void THISCALL heroIfAddMethodDefinitions(u8 *self, u8 *list) {
  static const u32 fns[6] = {0x55f5e0, 0x55f6a0, 0x55ef10, 0x55ee30, 0x55f670, 0x55f640};
  for (u32 k = 0; k < 6; k++) {
    if (list[0xc] == 0)
      break;
    u32 count = G(u32, 0x7140c8);
    if (count < 0x32) {
      G(u32, 0x7140d0 + 4 * count) = fns[k];
      G(u32, 0x7140c8) = count + 1;
    } else {
      vcall<void>(self, 0x44, 0x6a5ea4u);
      void *assertp = G(void *, 0x7003b0);
      if (assertp)
        ((void(__attribute__((cdecl)) *)(void))assertp)();
    }
  }
  list[0xc] = 0;
  ext_505a00(self, list);
}
PCREG(55f6b0, heroIfAddMethodDefinitions);
