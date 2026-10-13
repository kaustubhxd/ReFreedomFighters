// batch1140.cpp - collision thread, batch 1140 (hard-row lane, mid-size row, name GUESS): 0x5ef730. Three slot-0x10 calls on
// the objects at [this+0xa9], [this+0xa1] and [this+0xa5] (argument: the object o), then a chain of calls on o with fields of
// this (slot 0x10 with (this+8, 0x80), slot 0x3c, slots 0x44, 0x4c (three floats), 0x60 (bytes and a bool), 0x48 (words)),
// and when [this+0xb1] is set, slot 0x10 of o with ([this+0xc3], 0xc) and slot 0x10 of [this+0xb1] with o. Thiscall, one
// stack argument o, ret 4.
#include "ff.h"

static void THISCALL serialize5ef730(u8 *self, u8 *o) {
  vcall<void>(*(void **)(self + 0xa9), 0x10, o);
  vcall<void>(*(void **)(self + 0xa1), 0x10, o);
  vcall<void>(*(void **)(self + 0xa5), 0x10, o);
  vcall<void>(o, 0x10, (u32)(self + 8), 0x80u);
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x88));
  vcall<void>(o, 0x44, *(u32 *)(self + 0x8c));
  vcall<void>(o, 0x44, *(u32 *)(self + 0x90));
  vcall<void>(o, 0x4c, *(float *)(self + 0x94));
  vcall<void>(o, 0x4c, *(float *)(self + 0x98));
  vcall<void>(o, 0x4c, *(float *)(self + 0x9c));
  vcall<void>(o, 0x60, (u32)self[0xa0]);
  vcall<void>(o, 0x48, (u32)*(u16 *)(self + 0xb7));
  vcall<void>(o, 0x48, (u32)*(u16 *)(self + 0xb9));
  vcall<void>(o, 0x60, (u32)self[0xb5]);
  vcall<void>(o, 0x44, *(u32 *)(self + 0xbb));
  vcall<void>(o, 0x44, *(u32 *)(self + 0xbf));
  vcall<void>(o, 0x60, (u32)self[0xb6]);
  vcall<void>(o, 0x60, *(u32 *)(self + 0xb1) != 0 ? 1u : 0u);
  if (*(u32 *)(self + 0xb1) != 0) {
    vcall<void>(o, 0x10, *(u32 *)(self + 0xc3), 0xcu);
    vcall<void>(*(void **)(self + 0xb1), 0x10, o);
  }
}
PCREG(5ef730, serialize5ef730);
