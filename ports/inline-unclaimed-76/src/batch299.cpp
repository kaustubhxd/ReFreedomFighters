// batch299.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x5eaab0 (ret 8; thiscall with two arguments).
#include "ff.h"

// Exe allocator 0x41e290 (cdecl, one argument, returns the block). The spec stubs it (fills with 0xA5).
extern "C" u8 *ext_41e290(u32 size);

// 0x5eaab0(this, a, count) (ret 8): [this] = a; [this+0x48] = count; [this+0x44] = 0; for count times: [this+4+4*i] = a new
// 0x15-byte block. Returns this. GUESS: a table of blocks.
static u32 THISCALL initBlocks_5eaab0(u8 *self, u32 a, u32 count) {
    *(u32 *)self = a;
    *(u32 *)(self + 0x48) = count;
    *(u32 *)(self + 0x44) = 0u;
    for (u32 i = 0; i < count; i++) {
        *(u32 *)(self + 4 + 4 * i) = (u32)ext_41e290(0x15u);
    }
    return (u32)self;
}
PCREG(5eaab0, initBlocks_5eaab0);
