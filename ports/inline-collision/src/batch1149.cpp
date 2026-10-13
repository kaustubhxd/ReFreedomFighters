// batch1149.cpp - collision thread, batch 1149 (name GUESS: ZOctreeCompiled::GetEverything): 0x4e3cc0 is a thunk. It loads ECX
// from the argument's +0xc and jumps to the octree node walk 0x4e3ce0 (batch 1123) with the argument as its stack argument, so
// its result is that walk's EAX. Thiscall (ECX unused), one stack argument, ret 4. The walk runs as exe code.
#include "ff.h"

extern "C" u32 THISCALL ext_4e3ce0(void *node, u32 info);   // exe: node walk (batch 1123 port exists), ret 4

static u32 THISCALL getEverything4e3cc0(void *ecxUnused, u8 *x) {   // ECX is unused: the argument is the stack word
  (void)ecxUnused;
  return ext_4e3ce0(*(void **)(x + 0xc), (u32)x);
}
PCREG(4e3cc0, getEverything4e3cc0);
