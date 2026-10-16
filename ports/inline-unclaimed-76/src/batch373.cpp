// batch373.cpp - area 76, residue 18 (out/functions.jsonl). Two functions.
// 0x671fe0 (cdecl, no arguments, plain ret; GUESS): moves the pending pair (globals 0x6e7590 = a, 0x6e7594 = b) into the list:
//   if a != 0 { a.+0x14 = b; b = [0x6e7594]; a = [0x6e7590]; } else [0x7003bc] = b.
//   if b != 0 { b.+0x10 = a } else [0x7003c0] = a.   Then 0x6e7590 = 0 and 0x6e7594 = 0.
// 0x4d93e0 (thiscall, no arguments, plain ret, returns this; GUESS): memset(this, 0, 0x70) (import thunk 0x634d10); then
//   dat = [[0x70039c]+0x9b]; obj = [dat+8]; obj.vtbl[0x34](obj, this) (thiscall, one word); 0x4de7a0(this) (thiscall; hooked in the
//   fixture); [this+0x3c] |= 0x1000000; word [this+0x5a] = 0; byte [this+0x58] = 0; dword [this+0x54] = 0; dword [this+0x68] = 0.
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634d10(u32 dst, u32 val, u32 n);

static void __attribute__((cdecl)) f671fe0(void) {
    u32 a = *(u32 *)0x6e7590u;
    u32 b = *(u32 *)0x6e7594u;
    if (a != 0u) {
        *(u32 *)(a + 0x14u) = b;
        b = *(u32 *)0x6e7594u;
        a = *(u32 *)0x6e7590u;
    } else {
        *(u32 *)0x7003bcu = b;
    }
    if (b != 0u) {
        *(u32 *)(b + 0x10u) = a;
    } else {
        *(u32 *)0x7003c0u = a;
    }
    *(u32 *)0x6e7590u = 0u;
    *(u32 *)0x6e7594u = 0u;
}
PCREG(671fe0, f671fe0);

static u8 *THISCALL f4d93e0(u8 *selfp) {
    u32 self = (u32)selfp;
    ext_634d10(self, 0u, 0x70u);
    u32 dat = *(u32 *)(G(u32, 0x70039cu) + 0x9bu);
    u32 obj = *(u32 *)(dat + 8u);
    ((void(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)obj + 0x34u)))(obj, self);
    ext_4de7a0(selfp);
    *(u32 *)(self + 0x3cu) |= 0x1000000u;
    *(u16 *)(self + 0x5au) = 0u;
    *(u8 *)(self + 0x58u) = 0u;
    *(u32 *)(self + 0x54u) = 0u;
    *(u32 *)(self + 0x68u) = 0u;
    return selfp;
}
PCREG(4d93e0, f4d93e0);
