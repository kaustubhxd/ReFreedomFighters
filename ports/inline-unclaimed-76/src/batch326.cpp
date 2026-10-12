// batch326.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x615090 (stdcall, one argument, ret 4; GUESS).
// obj = arg; 0x610100(obj) (exe, stdcall, one argument, ret 4); 0x60f040 (exe, fastcall: ECX = obj+0x4c, EDX = obj+8, stack = obj+0x2c;
// ret 4) builds the record at obj+0x4c from obj+8 and obj+0x2c.
#include "ff.h"

extern "C" void STDCALL ext_610100(u32 obj);
extern "C" void FASTCALL ext_60f040(u32 dst, u32 src, u32 extra);

static void STDCALL build_615090(u32 obj) {
    ext_610100(obj);
    ext_60f040(obj + 0x4cu, obj + 8u, obj + 0x2cu);
}
PCREG(615090, build_615090);
