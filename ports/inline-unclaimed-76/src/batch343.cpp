// batch343.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x604170 (thiscall, one argument, ret 4; GUESS). A constructor:
// [this] = vtable 0x6b9b6c; [this+4] = arg; buf = 0x41e290(0x320) (exe allocator, cdecl); [this+8] = buf; the 0x320 bytes at buf are zeroed
// (the exe does this with a dword loop or rep stosd; both zero the same bytes). Returns this.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 size);

static u32 THISCALL ctor_604170(u8 *self, u32 arg) {
    *(u32 *)self = 0x6b9b6cu;
    *(u32 *)(self + 4u) = arg;
    u32 buf = ext_41e290(0x320u);
    *(u32 *)(self + 8u) = buf;
    for (u32 i = 0; i < 0x320u; i += 4u) *(u32 *)(buf + i) = 0u;
    return (u32)self;
}
PCREG(604170, ctor_604170);
