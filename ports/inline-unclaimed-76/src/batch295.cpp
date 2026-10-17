// batch295.cpp - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x5aac30 (long vtable call sequence).
#include "ff.h"

typedef void (__attribute__((thiscall)) *VU_5aac30)(u8 *, u32);
typedef void (__attribute__((thiscall)) *VU2_5aac30)(u8 *, u32, u32);
typedef void (__attribute__((thiscall)) *VF_5aac30)(u8 *, float);

// Exe helpers (run as original code): 0x45f960 (thiscall, one argument, returns al; see batch197) and 0x5aabe0 (thiscall, one argument).
extern "C" u8 THISCALL ext_45f960(u8 *self, u32 obj);
extern "C" void THISCALL ext_5aabe0(u8 *self, u32 obj);

static void vcall_d(u32 o, u32 slot, u32 a) { ((VU_5aac30)(*(void ***)o)[slot / 4])((u8 *)o, a); }
static void vcall_dd(u32 o, u32 slot, u32 a, u32 b) { ((VU2_5aac30)(*(void ***)o)[slot / 4])((u8 *)o, a, b); }
static void vcall_f(u32 o, u32 slot, float a) { ((VF_5aac30)(*(void ***)o)[slot / 4])((u8 *)o, a); }


// 0x5aac30(this, obj) (ret 4). If ext_45f960(this, obj) is false, returns 0. Otherwise a fixed sequence of calls on obj: 0x3c,
// 0x4c (floats), 0x60, 0x64, 0x44 and 0x10 slots with fields of this, three array walks calling slot 0x10 with obj, two
// ext_5aabe0 calls, and returns 1. Transliterated from the exe. GUESS.
static u8 THISCALL f_5aac30(u8 *self, u32 obj) {
    if (!ext_45f960(self, obj)) return 0;
    u32 o = obj;
    vcall_d(o, 0x3c, *(u32 *)(self + 0x69d));
    vcall_f(o, 0x4c, *(float *)(self + 0x2fc));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x354));
    vcall_f(o, 0x4c, *(float *)(self + 0x358));
    vcall_f(o, 0x4c, *(float *)(self + 0x35c));
    vcall_f(o, 0x4c, *(float *)(self + 0x42c));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3d4));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3d8));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3dc));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3e0));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3e4));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3e8));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3ec));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3f0));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3f4));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3f8));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3fc));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x400));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x404));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x408));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x40c));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x410));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x414));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x418));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3c2));
    vcall_d(o, 0x60, *(u8 *)(self + 0x3c6));
    vcall_d(o, 0x60, *(u8 *)(self + 0x3c7));
    vcall_f(o, 0x4c, *(float *)(self + 0x3c8));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x3cc));
    vcall_f(o, 0x4c, *(float *)(self + 0x3d0));
    vcall_f(o, 0x4c, *(float *)(self + 0x374));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x378));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x370));
    vcall_d(o, 0x64, *(u32 *)(self + 0x364));
    vcall_d(o, 0x44, *(u32 *)(self + 0x360));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x348));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x34c));
    vcall_d(o, 0x3c, *(u32 *)(self + 0x300));
    vcall_d(o, 0x64, *(u32 *)(self + 0x89e));
    vcall_d(o, 0x64, *(u32 *)(self + 0x89a));
    vcall_d(o, 0x60, *(u8 *)(*(u8 **)(G(u8 *, 0x70039c) + 0x190f) + 0x81));
    vcall_dd(o, 0x10, (u32)(self + 0x18), 0x2b8u);
    vcall_dd(o, 0x10, (u32)(self + 0x37d), 0x45u);
    for (u32 p = *(u32 *)(self + 0x659); p != *(u32 *)(self + 0x65d); p += 4) vcall_d(*(u32 *)p, 0x10, obj);
    for (u32 p = *(u32 *)(self + 0x665); p != *(u32 *)(self + 0x669); p += 4) vcall_d(*(u32 *)p, 0x10, obj);
    for (u32 p = *(u32 *)(self + 0x671); p != *(u32 *)(self + 0x675); p += 4) vcall_d(*(u32 *)p, 0x10, obj);
    ext_5aabe0(self + 0x53c, obj);
    ext_5aabe0(self + 0x54a, obj);

    return 1;
}
PCREG(5aac30, f_5aac30);
