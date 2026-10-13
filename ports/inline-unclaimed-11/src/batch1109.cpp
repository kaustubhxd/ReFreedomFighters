// batch1109.cpp - unclaimed-11 batch 9 (core-todo residue-10): ZRepositionCharacter::CopyData(ZEventBase*) (0x5c40e0, high).
// Thiscall, one argument (ret 4). Copies +0x4c and +0x50 from the source. If the source's +0x48 object is set: it calls that
// object's slot 0x4c with an out pointer (tmp), then loops while tmp is nonzero: this's +0x48 object slot 0x04 gets the last
// return value, and the source's slot 0x5c is called again with the out pointer.
#include "ff.h"

typedef void(THISCALL *outFn)(void *self, u32 *out);
typedef u32(THISCALL *retOutFn)(void *self, u32 *out);
typedef void(THISCALL *oneFn)(void *self, u32 value);

// 0x5c40e0, ZRepositionCharacter::CopyData(ZEventBase*) (high).
static void THISCALL repositionCharacterCopyData(u8 *self, u8 *src) {
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x50) = *(u32 *)(src + 0x50);
  void *obj = *(void **)(src + 0x48);
  if (!obj) return;
  u32 tmp;
  ((outFn)(*(void ***)obj)[0x4c / 4])(obj, &tmp);
  u32 x = ((retOutFn)(*(void ***)obj)[0x5c / 4])(obj, &tmp);
  while (tmp != 0) {
    void *dst = *(void **)(self + 0x48);
    ((oneFn)(*(void ***)dst)[0x04 / 4])(dst, x);
    x = ((retOutFn)(*(void ***)*(void **)(src + 0x48))[0x5c / 4])(*(void **)(src + 0x48), &tmp);
  }
}
PCREG(5c40e0, repositionCharacterCopyData);
