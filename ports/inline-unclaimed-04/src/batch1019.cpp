// batch1019.cpp - unclaimed-04 batch 20 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
#include "ff.h"

extern "C" void THISCALL ext_4db7c0(void *obj, u8 *out);  // copies three dwords from obj+0x40..+0x48 to out; original code
extern "C" void __attribute__((cdecl)) ext_41e2c0(void *p);  // release helper; original code (hooked by the spec)

// 0x45b170: copy the three dwords of the object at this+8 (from +0x40) into this+0x18.
static void THISCALL unk45b170CopyFrom8(u8 *self) {
  u8 *obj = *(u8 **)(self + 8);
  ext_4db7c0(obj, self + 0x18);
}
PCREG(45b170, unk45b170CopyFrom8);

// 0x5f3af0: release the pointer stored at the first dword of this.
static void THISCALL unk5f3af0ReleaseFirst(u8 *self) {
  ext_41e2c0(*(void **)self);
}
PCREG(5f3af0, unk5f3af0ReleaseFirst);
