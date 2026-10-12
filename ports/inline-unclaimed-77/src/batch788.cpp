// batch788.cpp - unclaimed-77 claim 18 (docs/20-unclaimed-77.md): ZSysInterface::SetOption(const char*, const char*) (high). Thiscall,
// two stack arguments, ret 8. The callee 0x4d3a00 is stubbed in the harness (GUESS): three stack arguments, ret 12.
#include "ff.h"

extern "C" void THISCALL ext_4d3a00(void *self, const char *a, const char *b, u32 c);   // stubbed (GUESS), ret 12

// 0x42fb40, ZSysInterface::SetOption(const char*, const char*) (high): forwards both arguments and the constant 0xc to 0x4d3a00 with
// this = 0x6ff938.
static void THISCALL sysInterfaceSetOption(u8 *self, const char *a, const char *b) {
  (void)self;
  ext_4d3a00((void *)0x6ff938, a, b, 0xcu);
}
PCREG(42fb40, sysInterfaceSetOption);
