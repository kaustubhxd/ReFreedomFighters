// batch808.cpp - unclaimed-08 batch 8: CEntityTracker::GetEntity(int&, unsigned int) (high). Slice: floor(addr/16) mod 20 = 7.
// The tracker holds an array at this+0x50 of 23-byte entries (first dword = object pointer) and a count at this+0x54.
// Each object's type at +0x54 gives a shift count at +4; the bit (1 << count, count masked to 5 bits) is tested against
// the mask. A matching object is asked for its owner through vtable +0x20; when bit 10 of the owner's flags (owner+0x3c,
// reached through the returned object's +8) is clear, the object pointer is returned and *index keeps its value.
// Otherwise the index goes on; at the end *index = -1 and the result is null. The index starts one past its value.
#include "ff.h"

// 0x5c00f0, CEntityTracker::GetEntity(int&, unsigned int) (high). Thiscall, two stack arguments, ret 8.
static u8 *THISCALL entityTrackerGetEntity(u8 *self, s32 *index, u32 mask) {
  ++*index;
  while (*index < *(s32 *)(self + 0x54)) {
    u8 *entry = *(u8 **)(self + 0x50) + *index * 0x17;
    u8 *obj = *(u8 **)entry;
    u32 bit = 1u << (*(u32 *)(*(u8 **)(obj + 0x54) + 4) & 31);
    if (mask & bit) {
      u8 *owner = vcall<u8 *>(obj, 0x20);
      u32 flags = *(u32 *)(*(u8 **)(owner + 8) + 0x3c);
      if (((flags >> 10) & 1) == 0) return *(u8 **)entry;
    }
    ++*index;
  }
  *index = -1;
  return nullptr;
}
PCREG(5c00f0, entityTrackerGetEntity);
