// batch329.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x605100 (ret 8; GUESS). The body pushes the incoming ECX (kept as
// the first stack word of the callee) and calls 0x603e40 with ECX = [ebp+0xc] (exe, thiscall, one stack argument, ret 4), then returns its
// eax. In C the incoming ECX is the first (fastcall) parameter; EDX is unused. Stack words: a = [ebp+8] is not read; b = [ebp+0xc] is the
// object. So the port: 0x603e40(ECX = b, arg = incoming ECX).
#include "ff.h"

extern "C" u32 THISCALL ext_603e40(u32 self, u32 arg);

static u32 FASTCALL fwd_605100(u32 incomingEcx, u32 unusedEdx, u32 a, u32 b) {
    (void)unusedEdx;
    (void)a;
    return ext_603e40(b, incomingEcx);
}
PCREG(605100, fwd_605100);
