// batch260.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice floor(addr/16) mod 20 == 5.
#include "ff.h"

// Exe helper 0x4e7be0 (thiscall, one stack argument, ret 4). Runs as original code; its residue is not 5.
extern "C" void THISCALL ext_4e7be0(u8 *self, u32 arg);

typedef u32 (__attribute__((thiscall)) *SlotU_4a5dd0)(u8 *, u32);
typedef u32 (__attribute__((thiscall)) *SlotF_4a5dd0)(u8 *, float);

// Calls obj->vtbl[slot](obj, arg) with one stack argument. Slot numbers are byte offsets, as in the exe.
static void callU_4a5dd0(u8 *obj, u32 slot, u32 arg) {
    void **vt = *(void ***)obj;
    ((SlotU_4a5dd0)vt[slot / 4])(obj, arg);
}
static void callF_4a5dd0(u8 *obj, u32 slot, float arg) {
    void **vt = *(void ***)obj;
    ((SlotF_4a5dd0)vt[slot / 4])(obj, arg);
}

// 0x4a5dd0: clears bit 6 of this+4, then makes a fixed sequence of vtable calls on the object B (stack argument),
// passing field values of this (pointers, bytes, a word, dwords and floats), then calls ext 0x4e7be0 on this+0x48
// with B. Returns true (mov al, 1). GUESS: an apply-settings routine that pushes fields into a control object.
static u8 THISCALL applyFields_4a5dd0(u8 *self, u32 b) {
    u8 *esi = (u8 *)b;
    *(u32 *)(self + 4) &= 0xffffffbfu;
    callU_4a5dd0(esi, 0x68, (u32)(self + 0x5f));
    callU_4a5dd0(esi, 0x70, (u32)(self + 0x6b));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0x8f));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0x90));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0x91));
    callU_4a5dd0(esi, 0x40, *(u16 *)(self + 0x5d));
    callU_4a5dd0(esi, 0x70, (u32)(self + 0x93));
    callU_4a5dd0(esi, 0x54, *(u32 *)(self + 0xb7));
    callF_4a5dd0(esi, 0x4c, *(float *)(self + 0xbb));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0x92));
    callF_4a5dd0(esi, 0x4c, *(float *)(self + 0xc0));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0xc4));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0xc5));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0xc6));
    callF_4a5dd0(esi, 0x4c, *(float *)(self + 0xc7));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0xcb));
    callU_4a5dd0(esi, 0x44, *(u32 *)(self + 0xcc));
    callU_4a5dd0(esi, 0x44, *(u32 *)(self + 0xd0));
    callU_4a5dd0(esi, 0x60, *(u8 *)(self + 0xbf));
    ext_4e7be0(self + 0x48, b);
    return 1;
}
PCREG(4a5dd0, applyFields_4a5dd0);
