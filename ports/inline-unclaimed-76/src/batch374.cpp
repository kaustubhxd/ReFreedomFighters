// batch374.cpp - area 76, residue 18 (out/functions.jsonl): 0x43bbe0 (thiscall, one stack argument a, ret 4; GUESS).
// a: byte [+0xa0] = 0; dword [+0xa1] = 0; word [+0xa5] = 0; dwords [+0x80], [+0x84], [+0x88], [+0x8c], [+0x90], [+0x94], [+0x98],
//    [+0x9c] = 0xffffffff; dword [+0xa7] = 0; dword [+0xab] = 0.   this (ECX): dword [+0x247] = 0; dword [+0x243] = 0.
#include "ff.h"

static void THISCALL f43bbe0(u8 *selfp, u32 a) {
    u32 self = (u32)selfp;
    *(u8 *)(a + 0xa0u) = 0u;
    *(u32 *)(a + 0xa1u) = 0u;
    *(u16 *)(a + 0xa5u) = 0u;
    *(u32 *)(a + 0x80u) = 0xffffffffu;
    *(u32 *)(a + 0x90u) = 0xffffffffu;
    *(u32 *)(a + 0x84u) = 0xffffffffu;
    *(u32 *)(a + 0x94u) = 0xffffffffu;
    *(u32 *)(a + 0x88u) = 0xffffffffu;
    *(u32 *)(a + 0x98u) = 0xffffffffu;
    *(u32 *)(a + 0x8cu) = 0xffffffffu;
    *(u32 *)(a + 0x9cu) = 0xffffffffu;
    *(u32 *)(self + 0x247u) = 0u;
    *(u32 *)(self + 0x243u) = 0u;
    *(u32 *)(a + 0xa7u) = 0u;
    *(u32 *)(a + 0xabu) = 0u;
}
PCREG(43bbe0, f43bbe0);
