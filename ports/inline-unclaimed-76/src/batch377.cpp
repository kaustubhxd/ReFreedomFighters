// batch377.cpp - area 76, residue 17 (out/functions.jsonl). Two chained accessors; both return eax of their tail-jump target.
// 0x54c3d0 (thiscall, no arguments, plain ret; GUESS): obj = [this+0x63ec]; if obj: obj.vtbl[0x48] called with ECX = this and one word obj;
//   then 0x54ab70(this) (exe, thiscall, plain; hooked here? no: runs as exe code, its own tail jump goes to a vtable slot). Returns eax.
// 0x561f50 (cdecl, no arguments, plain ret; GUESS): x = E.vtbl[0xbc](E) with E = [0x70039c] (thiscall, no arguments); return x.vtbl[0xa4](x).
#include "ff.h"

extern "C" u32 THISCALL ext_54ab70(u8 *self);

static u32 THISCALL f54c3d0(u8 *selfp) {
    u32 self = (u32)selfp;
    u32 obj = *(u32 *)(self + 0x63ecu);
    if (obj != 0u) ((void(THISCALL *)(u32, u32))(*(u32 *)(*(u32 *)obj + 0x48u)))(self, obj);
    return ext_54ab70(selfp);
}
PCREG(54c3d0, f54c3d0);

static u32 __attribute__((cdecl)) f561f50(void) {
    u32 E = G(u32, 0x70039cu);
    u32 x = ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)E + 0xbcu)))(E);
    return ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)x + 0xa4u)))(x);
}
PCREG(561f50, f561f50);
