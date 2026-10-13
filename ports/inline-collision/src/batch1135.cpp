// batch1135.cpp - collision thread, batch 1135 (gap-list row, name GUESS): 0x55ec00. A stdcall with one argument o: if o is
// null it returns (ret 4); otherwise it overwrites its argument with 1 and tail-jumps to slot 0 of o (ECX = o, one stack
// argument 1; the callee pops it), so the result is slot 0's EAX.
#include "ff.h"

// 0x55ec00 (name GUESS): stdcall, one stack argument o, ret 4 (the callee of the tail jump pops it).
static u32 STDCALL tailSlot0_55ec00(u8 *o) {
  if (o == 0) return 0;
  return vcall<u32>(o, 0, 1u);
}
PCREG(55ec00, tailSlot0_55ec00);
