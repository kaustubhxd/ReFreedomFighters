// u69_98.cpp - area 69, residue-8 (batch 98).
// 0x66d30b (6 insns): calls 0x634273 (sized delete).
// Very short function, likely pattern: load pointer from self, sized delete with size parameter.
// Following pattern from similar functions like 0x64fe40.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);  // operator delete (cdecl, sized)

// 0x66d30b: thiscall, no args. Calls sized delete with size 0x33 (51 bytes).
// Maybe passes self+offset directly (not dereferenced)?
static void THISCALL freeSlot66d30b(u8 *self) {
  ext_634273(self + 0x40, 0x33);
}
PCREG(66d30b, freeSlot66d30b);
