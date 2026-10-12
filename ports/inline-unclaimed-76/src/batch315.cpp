// batch315.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x61f2c0, a parser-state initializer (cdecl, plain ret, GUESS).
// init(this, base): p = base + 0xc; [this+0x64] = p; [this+0x10] = p; [0x24] = p; [0x38] = p; [0x4c] = p; [0x80] = p; every other field
// listed in the body is set to 0, except [this+0x68] = 1. Returns 1 (eax). The dispatcher at 0x61f400 is a separate function.
#include "ff.h"

static u32 __attribute__((cdecl)) init_61f2c0(u32 self, u32 base) {
    u32 p = base + 0xcu;
    *(u32 *)(self + 0x64u) = p;
    *(u32 *)(self + 0x50u) = 0u;
    *(u32 *)(self + 0x54u) = 0u;
    *(u32 *)(self + 0x60u) = 0u;
    *(u32 *)(self + 0x5cu) = 0u;
    *(u32 *)(self + 0x58u) = 0u;
    *(u32 *)(self + 0x10u) = p;
    *(u32 *)(self + 0x4u) = 0u;
    *(u32 *)(self + 0xcu) = 0u;
    *(u32 *)(self + 0x8u) = 0u;
    *(u32 *)(self + 0x0u) = 0u;
    *(u32 *)(self + 0x24u) = p;
    *(u32 *)(self + 0x18u) = 0u;
    *(u32 *)(self + 0x20u) = 0u;
    *(u32 *)(self + 0x1cu) = 0u;
    *(u32 *)(self + 0x14u) = 0u;
    *(u32 *)(self + 0x38u) = p;
    *(u32 *)(self + 0x2cu) = 0u;
    *(u32 *)(self + 0x34u) = 0u;
    *(u32 *)(self + 0x30u) = 0u;
    *(u32 *)(self + 0x28u) = 0u;
    *(u32 *)(self + 0x4cu) = p;
    *(u32 *)(self + 0x40u) = 0u;
    *(u32 *)(self + 0x48u) = 0u;
    *(u32 *)(self + 0x44u) = 0u;
    *(u32 *)(self + 0x3cu) = 0u;
    *(u32 *)(self + 0x68u) = 1u;
    *(u32 *)(self + 0x6cu) = 0u;
    *(u32 *)(self + 0x80u) = p;
    *(u32 *)(self + 0x74u) = 0u;
    *(u32 *)(self + 0x7cu) = 0u;
    *(u32 *)(self + 0x78u) = 0u;
    *(u32 *)(self + 0x70u) = 0u;
    *(u32 *)(self + 0x84u) = 0u;
    *(u32 *)(self + 0x88u) = 0u;
    *(u32 *)(self + 0x8cu) = 0u;
    *(u32 *)(self + 0xa4u) = 0u;
    *(u32 *)(self + 0xa0u) = 0u;
    *(u32 *)(self + 0x90u) = 0u;
    *(u32 *)(self + 0x94u) = 0u;
    *(u32 *)(self + 0x98u) = 0u;
    *(u32 *)(self + 0x9cu) = 0u;
    return 1u;
}
PCREG(61f2c0, init_61f2c0);
