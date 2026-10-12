// batch233.cpp - area 59 (residue 18), docs/20-unclaimed-59.md. A serializer: one-argument vtable calls on the object in the
// stack argument (slots 0x60, 0x3c, 0x3c, 0x44, 0x44; each argument read from this), then slot 0x10 on this's three
// sub-objects with that object as the argument. Name GUESS.
#include "ff.h"

// 0x5eefa0, thiscall(obj) ret 4: ecx = this; obj = [ebp+8].
static void THISCALL serialize_5eefa0(u8 *self, u8 *obj) {
  vcall<void>(obj, 0x60, (u32)*(u8 *)(self + 0x10));
  vcall<void>(obj, 0x3c, *(u32 *)(self + 0x11));
  vcall<void>(obj, 0x3c, *(u32 *)(self + 0x15));
  vcall<void>(obj, 0x44, *(u32 *)(self + 0x19));
  vcall<void>(obj, 0x44, *(u32 *)(self + 0x1d));
  vcall<void>(*(u8 **)(self + 4), 0x10, (u32)obj);
  vcall<void>(*(u8 **)(self + 8), 0x10, (u32)obj);
  vcall<void>(*(u8 **)(self + 0xc), 0x10, (u32)obj);
}
PCREG(5eefa0, serialize_5eefa0);
