// batch261.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice floor(addr/16) mod 20 == 5.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot114Fn_4fd5d0)(u8 *, u32, u32, u32, u32);

// One query: engine = [0x70039c]; o = [engine+0x9b]; returns the low word of o->vtbl[0x114](o, ptr, 0, 0x69c54c, key).
// Argument order matches the exe's pushes (key first, ptr last, so ptr is the first stack argument).
static u16 query_4fd5d0(u32 key, u32 ptr) {
    u8 *engine = G(u8 *, 0x70039c);
    u8 *o = *(u8 **)(engine + 0x9b);
    void **vt = *(void ***)o;
    return (u16)((Slot114Fn_4fd5d0)vt[0x114 / 4])(o, ptr, 0u, 0x69c54cu, key);
}

// 0x4fd5d0: thirteen word queries from the engine's object at +0x9b, each stored as a word at this+OFF (ret).
// Keys 0x412..0x41f (no 0x41c) and the pointer constants are the exe's own. GUESS: loads thirteen engine values by key.
static void THISCALL loadQueries_4fd5d0(u8 *self) {
    *(u16 *)(self + 0x66) = query_4fd5d0(0x412u, 0x6903d8u);
    *(u16 *)(self + 0x62) = query_4fd5d0(0x413u, 0x69c288u);
    *(u16 *)(self + 0x64) = query_4fd5d0(0x414u, 0x69c2acu);
    *(u16 *)(self + 0x8e) = query_4fd5d0(0x415u, 0x690ec8u);
    *(u16 *)(self + 0x90) = query_4fd5d0(0x416u, 0x692000u);
    *(u16 *)(self + 0x92) = query_4fd5d0(0x417u, 0x692024u);
    *(u16 *)(self + 0x72) = query_4fd5d0(0x418u, 0x690278u);
    *(u16 *)(self + 0x14c) = query_4fd5d0(0x419u, 0x6859f4u);
    *(u16 *)(self + 0x94) = query_4fd5d0(0x41au, 0x69c2f0u);
    *(u16 *)(self + 0x96) = query_4fd5d0(0x41bu, 0x69c594u);
    *(u16 *)(self + 0x88) = query_4fd5d0(0x41du, 0x6903a4u);
    *(u16 *)(self + 0x8a) = query_4fd5d0(0x41eu, 0x69c5a8u);
    *(u16 *)(self + 0x8c) = query_4fd5d0(0x41fu, 0x69c5c0u);
}
PCREG(4fd5d0, loadQueries_4fd5d0);
