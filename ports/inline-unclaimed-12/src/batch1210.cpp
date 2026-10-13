// batch1210.cpp - unclaimed-12: batch 10 (docs/20-unclaimed-12.md, claim 10, in slice). Thiscall, one stack argument (the
// OpaqueCallParameters_t reference). Name is medium confidence (GUESS).
#include "ff.h"

// 0x51ad90, ZVehicleIf::opaqueCall (original code here, reached by the tail jump; ported in another folder).
extern "C" u32 THISCALL ext_51ad90(u8 *self, u8 *params);

typedef u32(THISCALL *OpaqueSlotFn)(u8 *self, u8 *params);

// 0x522cf0, ZTankIf::opaqueCall(OpaqueCallParameters_t&): the word at params+0x10 is the index. An index below the count at
// 0x701a78 calls the table entry at 0x701a80+4*index with this and params (the entry's result is returned). Otherwise the
// count is subtracted from the index, the word is stored back at params+0x10, and the call tail-jumps to ext_51ad90.
static u32 THISCALL tankOpaqueCall(u8 *self, u8 *params) {
  const u32 index = *(const u16 *)(params + 0x10);
  const u32 count = G(u32, 0x701a78);
  if (index < count) {
    OpaqueSlotFn fn = (OpaqueSlotFn)G(u32, 0x701a80 + index * 4);
    return fn(self, params);
  }
  *(u16 *)(params + 0x10) = (u16)(index - count);
  return ext_51ad90(self, params);
}
PCREG(522cf0, tankOpaqueCall);
