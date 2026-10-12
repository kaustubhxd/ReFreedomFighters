// batch288.cpp - unclaimed area 76 (docs/20-unclaimed-76.md): 0x561cb0, the word-keyed branch with four 0x114 queries.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0_561cb0)(u8 *);
typedef u32 (__attribute__((thiscall)) *Slot1_561cb0)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *Slot4_561cb0)(u8 *, u32, u32, u32, u32);

// Exe helpers (run as original code): 0x4f21f0 (thiscall, one byte argument, ret 4) and 0x4f1520 (thiscall, two arguments, ret 8).
extern "C" void THISCALL ext_4f21f0(u8 *self, u32 flag);
extern "C" u32 THISCALL ext_4f1520(u8 *self, u32 w, u32 p);

// engine+0x9b ->vtbl[0x114](key, 0, 0x6a64b4, count): four arguments, returns the word the caller compares.
static u32 query_561cb0(u32 key, u32 count) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *o = *(u8 **)(eng + 0x9b);
    return ((Slot4_561cb0)(*(void ***)o)[0x114 / 4])(o, key, 0u, 0x6a64b4u, count);
}

// 0x561cb0(this, w, p) (ret 8). Returns 0 except where noted.
//  1. (u16)w == word [this+0x74]: [this+0xdc] = *(u32*)p; return 0.
//  2. q1 = query(0x6a6684, 0x488). If (u16)w == q1: if [this+0x85] is zero, set it, set [this+0x64] = (float)[eng+0x30] *
//     0x6785e4, [this+0xdc] = 7, X = this.vtbl[0x84]() with the flag 0 pushed for ext_4f21f0(X, 0). Then this.vtbl[0xe0]().
//  3. q2 = query(0x6a6698, 0x492). If (u16)w == q2: X = this.vtbl[0x84](); X.vtbl[0x2fc]([this+0x44]); return 0.
//  4. q3 = query(0x6a66a8, 0x497). If (u16)w == q3: if p, *(u8*)p = [this+0x85]; return 0.
//  5. q4 = query(0x6a66b8, 0x49c). If (u16)w == q4: if p, *(u8*)p = [this+0x87]; return 0.
//  6. Otherwise return ext_4f1520(this, w, p). GUESS.
static u32 THISCALL branchy_561cb0(u8 *self, u32 w, u32 p) {
    u16 word = (u16)w;
    if (word == *(u16 *)(self + 0x74)) {
        *(u32 *)(self + 0xdc) = *(u32 *)p;
        return 0u;
    }
    if (word == (u16)query_561cb0(0x6a6684u, 0x488u)) {
        if (*(u8 *)(self + 0x85) == 0u) {
            *(u8 *)(self + 0x85) = 1;
            float v = (float)(s32)*(u32 *)(G(u8 *, 0x70039c) + 0x30) * G(float, 0x6785e4);
            *(float *)(self + 0x64) = v;
            *(u32 *)(self + 0xdc) = 7u;
            u8 *x = (u8 *)((Slot0_561cb0)(*(void ***)self)[0x84 / 4])(self);
            ext_4f21f0(x, 0u);
        }
        ((Slot0_561cb0)(*(void ***)self)[0xe0 / 4])(self);
        return 0u;
    }
    if (word == (u16)query_561cb0(0x6a6698u, 0x492u)) {
        u8 *x = (u8 *)((Slot0_561cb0)(*(void ***)self)[0x84 / 4])(self);
        ((Slot1_561cb0)(*(void ***)x)[0x2fc / 4])(x, *(u32 *)(self + 0x44));
        return 0u;
    }
    if (word == (u16)query_561cb0(0x6a66a8u, 0x497u)) {
        if (p != 0u) *(u8 *)p = *(u8 *)(self + 0x85);
        return 0u;
    }
    if (word == (u16)query_561cb0(0x6a66b8u, 0x49cu)) {
        if (p != 0u) *(u8 *)p = *(u8 *)(self + 0x87);
        return 0u;
    }
    return ext_4f1520(self, w, p);
}
PCREG(561cb0, branchy_561cb0);
