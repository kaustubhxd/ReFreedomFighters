// batch6245 - unclaimed-62 claim 38 (gap band 0x561000-0x581000): 0x56caf0 [thiscall, one stack argument, ret 4]. Calls this's vtable slot 0xc8
// (thiscall, the argument), then 0x561180 (thiscall, the argument) and 0x56c950 (thiscall, the argument); GUESS stubs by address in the spec.
#include "ff.h"

extern "C" void THISCALL ext_561180(void *self, u32 a);   // exe: thiscall, one stack argument
extern "C" void THISCALL ext_56c950(void *self, u32 a);   // exe: thiscall, one stack argument

static void THISCALL fn56caf0(u8 *self, u32 a) {
  vcall<void>(self, 0xc8, a);
  ext_561180(self, a);
  ext_56c950(self, a);
}

PCREG(56caf0, fn56caf0);
