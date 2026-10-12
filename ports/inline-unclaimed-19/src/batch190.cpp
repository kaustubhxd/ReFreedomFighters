// batch190.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
// Leaf thiscall functions with no calls out: constant returns, vtable-slot writes and fixed field stores.
#include "ff.h"

// 0x42acaf: returns the address of a static string (mov eax, imm; ret). GUESS: a getTypeName-style getter.
static u32 THISCALL getStr_42acaf(u8 *) { return 0x6ff948u; }
PCREG(42acaf, getStr_42acaf);

// 0x4609e0: stores a vtable pointer into the first dword of the object. GUESS: vtable setter, no other effect.
static void THISCALL setVtbl_4609e0(u8 *self) { *(u32 *)self = 0x685288u; }
PCREG(4609e0, setVtbl_4609e0);

// 0x504720: increments the dword at +4 and returns this (inc dword ptr [ecx+4]; mov eax, ecx; ret). GUESS: a counter bump.
static u8 *THISCALL bump_504720(u8 *self) { *(u32 *)(self + 4) += 1u; return self; }
PCREG(504720, bump_504720);

// 0x4e64a0: sets two floats to 1.0 (+4 first, then +0) and returns this. GUESS: a reset to unit scale.
static u8 *THISCALL unitFloats_4e64a0(u8 *self) {
    *(float *)(self + 4) = 1.0f;
    *(float *)(self + 0) = 1.0f;
    return self;
}
PCREG(4e64a0, unitFloats_4e64a0);

// 0x52a1a0: writes three 32-bit words at +0x29, +0x2d and +0x31 (unaligned, so memcpy). The words are
// 200.0f, -400.0f and -4.0f as bit patterns. GUESS: a default range or bounds triple.
static void THISCALL bounds_52a1a0(u8 *self) {
    const u32 a = 0x43480000u, b = 0xc3c80000u, c = 0xc0800000u;
    __builtin_memcpy(self + 0x29, &a, 4);
    __builtin_memcpy(self + 0x2d, &b, 4);
    __builtin_memcpy(self + 0x31, &c, 4);
}
PCREG(52a1a0, bounds_52a1a0);

// 0x5ec660: stores the stack argument at +0x5e (unaligned dword). Callee pops 4 bytes (ret 4). GUESS: a setter.
static void THISCALL setField5e_5ec660(u8 *self, u32 v) { __builtin_memcpy(self + 0x5e, &v, 4); }
PCREG(5ec660, setField5e_5ec660);
