// batch307.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): six small forwarders and setters with exe helpers.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *S1_307)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *S5_307)(u8 *, u32, u32, u32, u32, u32);
typedef void (__attribute__((cdecl)) *Free1_307)(u32);

// Exe helpers (run as original code, or recorded in the spec): 0x41e2c0 (cdecl free, one argument), 0x61be80 (cdecl, four
// arguments), 0x61bb20 (thiscall, no arguments).
extern "C" void ext_41e2c0(u32 p);
extern "C" u32 ext_61be80(u32 a, u32 b, u32 c, u32 d);
extern "C" void THISCALL ext_61bb20(u8 *self);

// 0x601570(p) (ret 4): if p is non-null, free it (cdecl call to 0x41e2c0). GUESS.
static void STDCALL freeIf_601570(u32 p) {
    if (p != 0u) ext_41e2c0(p);
}
PCREG(601570, freeIf_601570);

// 0x61bbf0(this, a, b, c) (ret 0xc): returns ext_61be80([this+4], a, b, c) (cdecl, four arguments; the eax of the callee is kept).
static u32 THISCALL forward4_61bbf0(u8 *self, u32 a, u32 b, u32 c) {
    return ext_61be80(*(u32 *)(self + 4), a, b, c);
}
PCREG(61bbf0, forward4_61bbf0);

// 0x61bd00(obj, a, b, c, d, e) (plain ret, cdecl): returns obj.vtbl[0x1c](a, b, c, d, e) (thiscall, five arguments; the callee pops).
static u32 __attribute__((cdecl)) forward5_61bd00(u32 obj, u32 a, u32 b, u32 c, u32 d, u32 e) {
    u8 *o = (u8 *)obj;
    return ((S5_307)(*(void ***)o)[0x1c / 4])(o, a, b, c, d, e);
}
PCREG(61bd00, forward5_61bd00);

// 0x6044f0(this, a) (ret 4): w = obj.vtbl[0](a), where obj = [[0x724278] + 0x3c]; [this+0x24] = low word of w. GUESS.
static void THISCALL storeWordFromEngine_6044f0(u8 *self, u32 a) {
    u8 *eng = G(u8 *, 0x724278);
    u8 *obj = *(u8 **)(eng + 0x3c);
    u16 w = (u16)((S1_307)(*(void ***)obj)[0])(obj, a);
    *(u16 *)(self + 0x24) = w;
}
PCREG(6044f0, storeWordFromEngine_6044f0);

// 0x604540(this, a, unused) (ret 8): w = obj.vtbl[0](a) (obj as in 0x6044f0); [[this+8] + 4*(u16)w] = 0. GUESS.
static void THISCALL clearSlot_604540(u8 *self, u32 a, u32 unused) {
    (void)unused;
    u8 *eng = G(u8 *, 0x724278);
    u8 *obj = *(u8 **)(eng + 0x3c);
    u16 w = (u16)((S1_307)(*(void ***)obj)[0])(obj, a);
    u8 *table = *(u8 **)(self + 8);
    *(u32 *)(table + 4u * (u32)w) = 0u;
}
PCREG(604540, clearSlot_604540);

// 0x61ba30(this, flag) (ret 4): vtable 0x6be264, [this+4] = 0; if flag (byte) is set, ext_61bb20(this). Returns this. GUESS.
static u32 THISCALL initObj_61ba30(u8 *self, u32 flag) {
    *(u32 *)self = 0x6be264u;
    *(u32 *)(self + 4) = 0u;
    if ((u8)flag != 0u) ext_61bb20(self);
    return (u32)self;
}
PCREG(61ba30, initObj_61ba30);
