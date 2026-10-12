// batch218.cpp - unclaimed area 21 (docs/20-unclaimed-21.md). A stdcall glue: two float vectors on the stack (v = (10,10,10),
// w = (0,0,0)), a lookup 0x5003d0 on p->[4] with a read of its dword, calls on the render-manager child (vtable 0x58 then
// the result's 0x84 with &w), the original 0x4de7a0 on a 0x30-byte stack block, and vtable 0x238 on child->[0xadc] with
// five stack words. Names GUESS.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);     // original, thiscall, one stack word (stubbed in the harness)
extern "C" void THISCALL ext_4de7a0(u8 *self);               // original, thiscall, no stack words, fills its stack block

typedef u32(THISCALL *SlotArgRet)(u8 *, u32);                // vtable slot, one stack word, eax result
typedef void(THISCALL *SlotPtrVoid)(u8 *, u8 *);             // vtable slot, one stack word (pointer), no result used
typedef void(THISCALL *SlotFive)(u8 *, u8 *, u8 *, u8 *, u32, u32);   // vtable slot, five stack words

static u32 vslot6(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x558c00, stdcall(p) (ret 4). Name GUESS.
static void STDCALL vecLookup_558c00(u8 *p) {
  u32 v[3] = {0x41200000u, 0x41200000u, 0x41200000u};   // (10, 10, 10) as floats
  u32 w[3] = {0, 0, 0};
  u8 block[0x30];
  u8 *t = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *rm = G(u8 *, 0x70039c);
  u8 *child = *(u8 **)(rm + 0x9b);
  u8 *x = (u8 *)(u32)((SlotArgRet)vslot6(child, 0x58))(child, *(u32 *)t);
  ((SlotPtrVoid)vslot6(x, 0x84))(x, (u8 *)w);
  ext_4de7a0(block);
  u8 *obj2 = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  ((SlotFive)vslot6(obj2, 0x238))(obj2, block, (u8 *)w, (u8 *)v, 0x7f7f8fu, 0u);
}
PCREG(558c00, vecLookup_558c00);
