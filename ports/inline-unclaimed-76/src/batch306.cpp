// batch306.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): six cdecl (plain ret) accessors and forwarders.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *S1_306)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *S2_306)(u8 *, u32, u32);
typedef u32 (__attribute__((thiscall)) *S4_306)(u8 *, u32, u32, u32, u32);

// 0x61c5e0(a, b, c) (plain ret, cdecl): [a+0x64] = b; [a+0x68] = c.
static void __attribute__((cdecl)) setPair_61c5e0(u32 a, u32 b, u32 c) {
    *(u32 *)(a + 0x64) = b;
    *(u32 *)(a + 0x68) = c;
}
PCREG(61c5e0, setPair_61c5e0);

// 0x61c640(a, b) (plain ret, cdecl): if [a+4] equals the old [a], [a+4] = b; then [a] = b. The compare uses the value before the
// store to [a]. GUESS.
static void __attribute__((cdecl)) setIfSame_61c640(u32 a, u32 b) {
    u32 old = *(u32 *)a;
    bool same = *(u32 *)(a + 4) == old;
    *(u32 *)a = b;
    if (same) *(u32 *)(a + 4) = b;
}
PCREG(61c640, setIfSame_61c640);

// 0x61bc10(obj, a, b) (plain ret, cdecl): returns obj.vtbl[0xc](a, b) (thiscall, two arguments; the callee pops them).
static u32 __attribute__((cdecl)) fwd2slot0c_61bc10(u32 obj, u32 a, u32 b) {
    u8 *o = (u8 *)obj;
    return ((S2_306)(*(void ***)o)[0xc / 4])(o, a, b);
}
PCREG(61bc10, fwd2slot0c_61bc10);

// 0x61bca0(obj, a, b) (plain ret, cdecl): returns obj.vtbl[0x10](a, b).
static u32 __attribute__((cdecl)) fwd2slot10_61bca0(u32 obj, u32 a, u32 b) {
    u8 *o = (u8 *)obj;
    return ((S2_306)(*(void ***)o)[0x10 / 4])(o, a, b);
}
PCREG(61bca0, fwd2slot10_61bca0);

// 0x61bcc0(obj, a, b) (plain ret, cdecl): returns obj.vtbl[4](a, b).
static u32 __attribute__((cdecl)) fwd2slot4_61bcc0(u32 obj, u32 a, u32 b) {
    u8 *o = (u8 *)obj;
    return ((S2_306)(*(void ***)o)[4 / 4])(o, a, b);
}
PCREG(61bcc0, fwd2slot4_61bcc0);

// 0x61bc80(obj, a, b, c, d) (plain ret, cdecl): returns obj.vtbl[0x20](a, b, c, d) (thiscall, four arguments).
static u32 __attribute__((cdecl)) fwd4slot20_61bc80(u32 obj, u32 a, u32 b, u32 c, u32 d) {
    u8 *o = (u8 *)obj;
    return ((S4_306)(*(void ***)o)[0x20 / 4])(o, a, b, c, d);
}
PCREG(61bc80, fwd4slot20_61bc80);
