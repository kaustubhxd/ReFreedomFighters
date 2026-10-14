// batch2901.cpp - unclaimed-29: batch 1 (docs/20-unclaimed-29.md, claim 1). Thiscall, one stack argument (the save object or
// the OpaqueCallParameters_t reference). ZCarIf::opaqueCall's name is medium confidence (GUESS).
#include "ff.h"

// 0x51ad90, the tail-jump target of ZCarIf::opaqueCall (original code here).
extern "C" u32 THISCALL ext_51ad90(u8 *self, u8 *params);

// a save-object call: the vtable slot +0x60 takes one dword argument and returns an object (used as the next this)
typedef u8 *(THISCALL *SaveByteFn)(u8 *self, u32 v);
// the vtable slot +0x3c takes one dword argument
typedef void(THISCALL *SaveDwordFn)(u8 *self, u32 v);

// 0x5c2900, ZFenceGate::Save(ZSaveGame*) (high): clears bit 0x40 of the dword at +4; saves the byte at +0x25a, then the byte at
// +0x25b (each call on the object the previous one returned), then the dword at +0x50 on that object. Returns true.
static bool THISCALL fenceGateSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u8 *obj = save;
  obj = ((SaveByteFn)(*(const u32 *)(*(const u32 *)obj + 0x60)))(obj, self[0x25a]);
  obj = ((SaveByteFn)(*(const u32 *)(*(const u32 *)obj + 0x60)))(obj, self[0x25b]);
  ((SaveDwordFn)(*(const u32 *)(*(const u32 *)obj + 0x3c)))(obj, *(const u32 *)(self + 0x50));
  return true;
}
PCREG(5c2900, fenceGateSave);

// 0x51b600, ZCarIf::opaqueCall(OpaqueCallParameters_t&) (medium): the word at params+0x10 is the index. Below the count at
// 0x701800 the table entry 0x701808+4*index is called with this and params; otherwise the count is subtracted, the word is
// stored back, and the call tail-jumps to ext_51ad90.
typedef u32(THISCALL *CarSlotFn)(u8 *self, u8 *params);
static u32 THISCALL carOpaqueCall(u8 *self, u8 *params) {
  const u32 index = *(const u16 *)(params + 0x10);
  const u32 count = G(u32, 0x701800);
  if (index < count) {
    CarSlotFn fn = (CarSlotFn)G(u32, 0x701808 + index * 4);
    return fn(self, params);
  }
  *(u16 *)(params + 0x10) = (u16)(index - count);
  return ext_51ad90(self, params);
}
PCREG(51b600, carOpaqueCall);
