// batch4014.cpp - area 70 (residue 9), batch 4014: 0x558a10, takes the first two entries of a list (names GUESS).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 idx);            // exe: bounded element accessor, 8-byte entries
extern "C" void THISCALL ext_59e690(void *self, u32 a, u32 b);        // exe: stubbed by address in the spec (ret 8)

// 0x558a10 (name GUESS): thiscall (ECX = self), one stack argument (src), ret 4. The list at [src+4] gives element 0 (e0)
// and element 1 (e1); the body calls 0x59e690 with ECX = [self+0x1c], e0[0] and e1[0].
static void THISCALL takeTwo(u8 *self, u8 *src) {
  void *list = *(void **)(src + 4);
  u32 *e0 = ext_5003d0(list, 0);
  u32 a = e0[0];
  u32 *e1 = ext_5003d0(list, 1);
  ext_59e690(*(void **)(self + 0x1c), a, e1[0]);   // ecx = the object pointer stored at +0x1c
}
PCREG(558a10, takeTwo);
