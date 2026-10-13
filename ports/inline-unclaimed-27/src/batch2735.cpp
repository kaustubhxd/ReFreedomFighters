#include "ff.h"
// batch2735.cpp - unclaimed-27 batch 37 (docs/20-unclaimed-27.md). FUN_584c30, name unknown (GUESS). No SEH frame in the exe.
// The assert hook at 0x7003b0 is always set non-null in the spec (the exe traps on a null hook; not reproduced).

// 0x584c30 (GUESS): thiscall, one argument (v), ret 4, void. Removes the first element equal to v from the list at this+0x750
// (count dword, then dwords), shifting later elements down, and sets this+0xa54 to the new end. If v is not found, calls the hook.
static void THISCALL funcRemoveFromList(u8 *self, u32 v) {
  u32 *list = (u32 *)(self + 0x750);
  u32 *p = list + 1;
  u32 *endp = list + 1 + list[0];
  for (; p != endp; ++p) {
    if (*p == v) break;
  }
  if (p == endp) {
    void (*hook)(void) = (void (*)(void))(unsigned long)G(u32, 0x7003b0);
    if (hook) hook();
    return;
  }
  u32 cnt = list[0];
  u32 i = (u32)(p - (list + 1));
  if (i < cnt - 1) {
    for (u32 k = i; k < cnt - 1; k++) list[1 + k] = list[2 + k];
  }
  list[0] = cnt - 1;
  *(u32 *)(self + 0xa54) = (u32)(unsigned long)(list + 1 + list[0]);
}
PCREG(584c30, funcRemoveFromList);
