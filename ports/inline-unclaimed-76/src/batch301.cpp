// batch301.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x502030 (ret 4; table lookups, a dispatch, two
// engine calls, and a final call on this+0xc). The exe's int3 assert when the dispatch callback is null is not ported.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *Slot0_502030)(u8 *);
typedef u32 (__attribute__((thiscall)) *Slot2_502030)(u8 *, u32, u32);
typedef u32 (__attribute__((thiscall)) *Slot4_502030)(u8 *, u32, u32, u32, u32);
typedef void (__attribute__((thiscall)) *Slot3v_502030)(u8 *, u32, u32, u32);
typedef void (__attribute__((cdecl)) *Log3c_502030)(u8 *, u32, u32);
typedef void (__attribute__((cdecl)) *Cb_502030)(void);

// Exe helper 0x5003d0 (table lookup; see batch195). Runs as original code.
extern "C" u32 THISCALL ext_5003d0(u8 *table, u32 index);

// 0x502030(arg) (ret 4). p = table(arg+4)[1]; b = byte p+4. If b == 3: v = [p]. If b == 4: o = [p]; v = o.vtbl[0x34](). Else:
// the logger (0x700390).vtbl[0x20](0x69c8e0, 0x111) gives an object whose slot 0x2c is reported (cdecl, 0x69c6b0, 0x69c9b0);
// the dispatch callback at 0x7003b0 is called; v = 0. Then w = low word of (engine+0x9b).vtbl[0x114](v, 0, 0x69ca10, 0x28a);
// p2 = table(arg+4)[2], p3 = table(arg+4)[0]; obj = [this+0xc]; obj.vtbl[0x134]([p3], w, [p2]). GUESS.
static void THISCALL dispatch_502030(u8 *self, u32 arg) {
    u8 *p = (u8 *)ext_5003d0(*(u8 **)(arg + 4), 1u);
    u8 b = p[4];
    u32 v;
    if (b == 3) {
        v = *(u32 *)p;
    } else if (b == 4) {
        u8 *o = *(u8 **)p;
        v = ((Slot0_502030)(*(void ***)o)[0x34 / 4])(o);
    } else {
        u8 *lg = G(u8 *, 0x700390);
        u8 *obj = (u8 *)((Slot2_502030)(*(void ***)lg)[0x20 / 4])(lg, 0x69c8e0u, 0x111u);
        ((Log3c_502030)(*(void ***)obj)[0x2c / 4])(obj, 0x69c6b0u, 0x69c9b0u);
        Cb_502030 cb = G(Cb_502030, 0x7003b0);
        cb();
        v = 0u;
    }
    u8 *eng9b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u16 w = (u16)((Slot4_502030)(*(void ***)eng9b)[0x114 / 4])(eng9b, v, 0u, 0x69ca10u, 0x28au);
    u8 *p2 = (u8 *)ext_5003d0(*(u8 **)(arg + 4), 2u);
    u8 *p3 = (u8 *)ext_5003d0(*(u8 **)(arg + 4), 0u);
    u8 *obj = *(u8 **)(self + 0xc);
    ((Slot3v_502030)(*(void ***)obj)[0x134 / 4])(obj, *(u32 *)p3, (u32)w, *(u32 *)p2);
}
PCREG(502030, dispatch_502030);
