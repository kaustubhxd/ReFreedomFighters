// batch339.cpp - decomp area 64 (docs/20-unclaimed-64.md), slice floor(addr/16) mod 20 == 3.
#include "ff.h"

// Exe allocator 0x41e290 (cdecl, one stack word = size; the caller pops it). Runs as original code.
extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 size);
// Exe constructor 0x4ccbe0 (thiscall, ecx = block, two stack words (a, b), ret 8); returns eax = block.
extern "C" u32 THISCALL ext_4ccbe0(u8 *block, u32 a, u32 b);

// Virtual calls on the object: slot 0x28 (true for the non-null path) and slot 4, thiscall with one stack word.
typedef u32(__attribute__((thiscall)) * Slot1WordFn)(u8 *, u32);

// 0x440d70: thiscall (ecx = self, one stack word arg, ret 4). The SEH frame in the exe (fs:[0]) has no effect on the
// result and is not modelled. If self[+0x44] is null: p = alloc(0x1c); o = ext 0x4ccbe0(p, 0x20, 0); self[+0x44] = o;
// return o->vtbl[4](o, arg). Otherwise r = obj->vtbl[0x28](obj, arg); if r != 0 return r; else return
// self[+0x44]->vtbl[4](obj, arg). GUESS: a lazily created child with a try-then-fallback call.
static u32 THISCALL lazyCall_440d70(u8 *self, u32 arg) {
    u8 *obj = *(u8 **)(self + 0x44);
    if (obj == 0) {
        u32 p = ext_41e290(0x1cu);
        u32 o = ext_4ccbe0((u8 *)p, 0x20u, 0u);
        *(u32 *)(self + 0x44) = o;
        obj = (u8 *)o;
        void **vt = *(void ***)obj;
        return ((Slot1WordFn)vt[0x4 / 4])(obj, arg);
    }
    void **vt = *(void ***)obj;
    u32 r = ((Slot1WordFn)vt[0x28 / 4])(obj, arg);
    if (r != 0) return r;
    obj = *(u8 **)(self + 0x44);
    vt = *(void ***)obj;
    return ((Slot1WordFn)vt[0x4 / 4])(obj, arg);
}
PCREG(440d70, lazyCall_440d70);
