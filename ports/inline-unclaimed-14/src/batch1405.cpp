// batch1405.cpp - unclaimed-14 batch 5 (slice 13): CMsgForward::Init().
#include "ff.h"

// 0x49ef10, CMsgForward::Init() (high): if bit 0x2 of the byte at +4 is set, calls vtable slot +0x20 of the object at
// +0x44 (no arguments, eax result), then calls vtable slot +0x4c of the global object (`[0x70039c]+0x9b`) with that result
// as its one stack argument; stores the callee's eax at +0x48 and zeroes the word at +0x4c. Plain ret (no arguments).
static void THISCALL msgForwardInit(u8 *self) {
  if (self[4] & 2) {
    u8 *p = *(u8 **)(self + 0x44);
    u32 v = ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u32 *)p + 0x20)))(p);
    u8 *g = G(u8 *, 0x70039c);
    u8 *b = *(u8 **)(g + 0x9b);
    typedef u32(THISCALL * slot_fn)(u8 *, u32);
    slot_fn f = *(slot_fn *)(*(u32 *)b + 0x4c);
    *(u32 *)(self + 0x48) = f(b, v);
    *(u16 *)(self + 0x4c) = 0;
  }
}
PCREG(49ef10, msgForwardInit);
