// batch1912.cpp - unclaimed-66 batch 12: GUESS FUN_00434a90. The one stack argument is the object: the PC code copies it
// into ECX for two virtual calls, vtable +0x38 (no argument) and vtable +0x30 (argument 1). Stdcall, ret 4.
#include "ff.h"

// 0x434a90, GUESS FUN_00434a90.
static void STDCALL objCallsThenFlag(u8 *obj) {
  vcall<void>(obj, 0x38);
  vcall<void>(obj, 0x30, (u32)1);
}
PCREG(434a90, objCallsThenFlag);
