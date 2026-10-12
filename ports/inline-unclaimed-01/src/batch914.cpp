#include "ff.h"
// batch914.cpp - unclaimed-01 claim 13 (docs/20-unclaimed-01.md). CCivilianPathList::Init2() (0x5be780, high).

// Calls vtable +0x134 of the global's sub-object (returns an object), then slot +0x90 of that object with the constant
// 0x68a9d4 and a pointer to a local flag byte. If the flag stays zero, calls slot +0x138 of the sub-object (returns an
// object), slot +0x88 of that object with the constant 0x681320 and a pointer to a local dword, then slot +0x58 of the
// sub-object with that dword, and stores the result at this+0x91a. thiscall, no arguments, void.
// Reads vtable slot `off` of object `o` as a raw address (the slot's function pointer).
static u32 slotOf(u8 *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}

static void THISCALL civilianPathListInit2(u8 *self) {
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u8 *(THISCALL * ret_fn)(u8 *);
  typedef void(THISCALL * arg2_fn)(u8 *, u32, u8 *);
  typedef u32(THISCALL * arg1_fn)(u8 *, u32);
  u8 *a = ((ret_fn)slotOf(m, 0x134))(m);
  u8 flag = 0;
  ((arg2_fn)slotOf(a, 0x90))(a, 0x68a9d4u, &flag);
  if (flag != 0)
    return;
  m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *b = ((ret_fn)slotOf(m, 0x138))(m);
  u32 id = 0;
  ((arg2_fn)slotOf(b, 0x88))(b, 0x681320u, (u8 *)&id);
  m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x91a) = ((arg1_fn)slotOf(m, 0x58))(m, id);
}
PCREG(5be780, civilianPathListInit2);
