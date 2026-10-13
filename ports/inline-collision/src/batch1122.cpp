// batch1122.cpp - collision thread, batch 1122: strip-output callback 0x4ec660 (GUESS names from the body).
#include "ff.h"

// 0x4ec660 (unnamed; guessed StripOutCallback), fastcall (ECX = pointer to the ref word, EDX = query record), al.
// Query record: +0x5c out begin pointer (its base is added to the ref), +0x60 out end pointer, +0x64 out limit,
// +0x68 flags word, +0x6c entry count, +0x70 / +0x94 / +0xa0 pointer-sized inputs, +0xac word copied to the entry,
// +0xb0 pointer to a helper object (vtable slot 0x88).
// 1. Fails (returns 0) unless limit - end >= 0xe4 bytes of room.
// 2. Writes the new entry at end: [end+0x14] = ref, [end+0x10] = +0xac.
// 3. end = helper->slot 0x88(end, begin + [ref], +0x68, &+0x70, &+0x94, &+0xa0), +0x6c += 1, returns 1.
static u8 FASTCALL stripOutCallback(u32 *ref, u8 *q) {
  u8 *begin = *(u8 **)(q + 0x5c) + *(u32 *)ref;
  u8 *end = *(u8 **)(q + 0x60);
  if (*(u8 **)(q + 0x64) - end < 0xe4)
    return 0;
  *(u32 *)(end + 0x14) = (u32)(unsigned long)ref;   // the pointer itself (ECX is stored, not its pointee)
  *(u32 *)(end + 0x10) = *(u32 *)(q + 0xac);
  u8 *helper = *(u8 **)(q + 0xb0);
  // helper slot 0x88, thiscall (ECX = helper). The exe pushes, last to first: &+0xa0, &+0x94, &+0x70, +0x68,
  // begin+ref, end. So the callee sees (end, begin+ref, +0x68, &+0x70, &+0x94, &+0xa0) in that order.
  typedef u8 *(THISCALL *slot88)(void *self, u8 *end, u8 *bref, u32 flags, void *p70, void *p94, void *pa0);
  u8 *next = ((slot88)((*(void ***)helper)[0x88 / 4]))(helper, end, begin, *(u32 *)(q + 0x68), q + 0x70, q + 0x94,
                                                     q + 0xa0);
  *(u8 **)(q + 0x60) = next;
  *(u32 *)(q + 0x6c) += 1;
  return 1;
}
PCREG(4ec660, stripOutCallback);
