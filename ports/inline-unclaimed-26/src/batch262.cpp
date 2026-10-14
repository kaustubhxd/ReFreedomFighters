// batch262.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), slice floor(addr/16) mod 20 == 5.
#include "ff.h"

typedef u32 (__attribute__((thiscall)) *SlotArg_513510)(u8 *, u32);

// obj->vtbl[slot](obj, arg), one stack argument.
static void callArg_513510(u8 *obj, u32 slot, u32 arg) {
    void **vt = *(void ***)obj;
    ((SlotArg_513510)vt[slot / 4])(obj, arg);
}

// engine = [0x70039c]; o = [engine+0x9b]; returns o->vtbl[0x58](o, arg).
static u32 queryEngine_513510(u32 arg) {
    u8 *engine = G(u8 *, 0x70039c);
    u8 *o = *(u8 **)(engine + 0x9b);
    void **vt = *(void ***)o;
    return ((SlotArg_513510)vt[0x58 / 4])(o, arg);
}

// 0x513510: A = the stack argument, the object A is also the this of its own vtable calls. The sequence is:
// A.vt[0x40](out); A.vt[0x40](&A); out+4 = query(A); A.vt[0x40](&A); out+8 = query(A); A.vt[0x50](out+0xc);
// A.vt[0x50](out+0x10); A.vt[0x50](out+0x14); A.vt[0x6c](out+0x18); A.vt[0x6c](out+0x24); A.vt[0x50](out+0x30);
// A.vt[0x50](out+0x34). Returns true (ret 4). &A is the address of the stack slot, as in the exe. GUESS.
static u8 THISCALL fillRecord_513510(u8 *out, u32 a) {
    u8 *edi = (u8 *)a;
    callArg_513510(edi, 0x40, (u32)out);
    callArg_513510(edi, 0x40, (u32)&a);
    *(u32 *)(out + 4) = queryEngine_513510(a);
    callArg_513510(edi, 0x40, (u32)&a);
    *(u32 *)(out + 8) = queryEngine_513510(a);
    callArg_513510(edi, 0x50, (u32)(out + 0xc));
    callArg_513510(edi, 0x50, (u32)(out + 0x10));
    callArg_513510(edi, 0x50, (u32)(out + 0x14));
    callArg_513510(edi, 0x6c, (u32)(out + 0x18));
    callArg_513510(edi, 0x6c, (u32)(out + 0x24));
    callArg_513510(edi, 0x50, (u32)(out + 0x30));
    callArg_513510(edi, 0x50, (u32)(out + 0x34));
    return 1;
}
PCREG(513510, fillRecord_513510);
