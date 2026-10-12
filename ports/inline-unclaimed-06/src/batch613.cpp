// batch613.cpp - unclaimed-06 claim 13 (docs/20-unclaimed-06.md): ZRunParamAnim::~ZRunParamAnim (medium name). Thiscall, one
// argument (the deleting flags byte), ret 4. The base destructor 0x4e6ce0 and the CRT delete 0x634273 (cdecl) are stubbed
// (GUESS); the function itself only calls them and returns this.
#include "ff.h"

extern "C" void THISCALL ext_4e6ce0(u8 *self);     // base destructor, stubbed in the harness (GUESS), ecx = this
extern "C" void ext_634273(void *p, u32 n);        // CRT operator delete, cdecl, stubbed in the harness (GUESS)

// 0x49e490, ZRunParamAnim::~ZRunParamAnim() (medium): calls the base destructor on this, then if bit 0 of the flags
// argument is set, calls ext_634273(this, 0xc1) (delete with size 0xc1). Returns this.
static u8 *THISCALL runParamAnimDtor(u8 *self, u32 flags) {
  ext_4e6ce0(self);
  if ((u8)flags & 1) {
    ext_634273(self, 0xc1);
  }
  return self;
}
PCREG(49e490, runParamAnimDtor);
