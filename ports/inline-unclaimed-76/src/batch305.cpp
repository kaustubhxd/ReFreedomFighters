// batch305.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): thirteen small field accessors (setters, getters and
// indexed reads of a few words). Thiscall functions take the object in ECX; the cdecl ones (plain ret) take their arguments on the stack.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot1_305)(u8 *, u32);

// 0x601560(this, v): [this+0x18] = byte v (ret 4).
static void THISCALL setByte18_601560(u8 *self, u32 v) { *(u8 *)(self + 0x18) = (u8)v; }
PCREG(601560, setByte18_601560);

// 0x6044e0(this, v): [this+0x24] = word v (ret 4).
static void THISCALL setWord24_6044e0(u8 *self, u32 v) { *(u16 *)(self + 0x24) = (u16)v; }
PCREG(6044e0, setWord24_6044e0);

// 0x6106c0(this, v): [this+0x118a] = dword v (ret 4).
static void THISCALL setDword118a_6106c0(u8 *self, u32 v) { *(u32 *)(self + 0x118a) = v; }
PCREG(6106c0, setDword118a_6106c0);

// 0x6106d0(this, v): [this+0x20] = dword v (ret 4).
static void THISCALL setDword20_6106d0(u8 *self, u32 v) { *(u32 *)(self + 0x20) = v; }
PCREG(6106d0, setDword20_6106d0);

// 0x606d90(this, idx): eax = dword at ([this+0x17] + 4*idx - 4) (ret 4; idx is a word).
static u32 THISCALL dwordAt17_606d90(u8 *self, u32 idx) {
    u32 base = *(u32 *)(self + 0x17);
    return *(u32 *)(base + 4u * (u16)idx - 4u);
}
PCREG(606d90, dwordAt17_606d90);

// 0x606d40(this, idx): the low word of eax is the word at ([this+0x23] + 2*idx - 2); the high word is kept from [this+0x23]
// (mov eax, [this+0x23] then mov ax, ...) (ret 4).
static u32 THISCALL wordAt23_606d40(u8 *self, u32 idx) {
    u32 p = *(u32 *)(self + 0x23);
    u16 w = *(u16 *)(p + 2u * (u16)idx - 2u);
    return p ^ ((p ^ (u32)w) & 0xffffu);   // mov ax, word: only the low half of eax changes; the high half comes from P
}
PCREG(606d40, wordAt23_606d40);

// 0x606e80(this, idx, v): word at ([this+0x23] + 2*idx - 2) = v (ret 8).
static void THISCALL setWordAt23_606e80(u8 *self, u32 idx, u32 v) {
    u32 p = *(u32 *)(self + 0x23);
    *(u16 *)(p + 2u * (u16)idx - 2u) = (u16)v;
}
PCREG(606e80, setWordAt23_606e80);

// 0x604d50(this, a) (ret 4): a.vtbl[0](a, [this+0xc]) (the first slot called with the stored pointer).
static void THISCALL callSlot0_604d50(u8 *self, u32 a) {
    u8 *o = (u8 *)a;
    ((Slot1_305)(*(void ***)o)[0])(o, *(u32 *)(self + 0xc));
}
PCREG(604d50, callSlot0_604d50);

// 0x61f590(a) (plain ret; cdecl): returns the dword at [a+0x114].
static u32 __attribute__((cdecl)) readAt114_61f590(u32 a) { return *(u32 *)(a + 0x114); }
PCREG(61f590, readAt114_61f590);

// 0x61c590(a, b) (plain ret; cdecl): [a+0x3c] = b.
static void __attribute__((cdecl)) setAt3c_61c590(u32 a, u32 b) { *(u32 *)(a + 0x3c) = b; }
PCREG(61c590, setAt3c_61c590);

// 0x61c600(a, b): [a+0x6c] = b.
static void __attribute__((cdecl)) setAt6c_61c600(u32 a, u32 b) { *(u32 *)(a + 0x6c) = b; }
PCREG(61c600, setAt6c_61c600);

// 0x61c610(a, b): [a+0x60] = b.
static void __attribute__((cdecl)) setAt60_61c610(u32 a, u32 b) { *(u32 *)(a + 0x60) = b; }
PCREG(61c610, setAt60_61c610);

// 0x61c620(a, b): [a+0x40] = b.
static void __attribute__((cdecl)) setAt40_61c620(u32 a, u32 b) { *(u32 *)(a + 0x40) = b; }
PCREG(61c620, setAt40_61c620);
