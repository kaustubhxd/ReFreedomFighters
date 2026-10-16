// batch635.cpp - band 0x421000-0x441000, batch 635: one destructor.
//   0x435bc0 (~ZInputDeviceBase, thiscall one byte flag; ret 4): sets vtable 0x67a630;
//     optionally calls exe 0x634273 with (member, 1) or (this, 0xd) based on flags.
#include "ff.h"

typedef void(STDCALL *ext_634273_t)(void *arg1, u32 arg2);

static void THISCALL destructor_435bc0(u8 *self, u32 flag) {
  // Set vtable
  *(void ***)self = (void **)0x67a630;

  // Get member at offset 0x8
  void *member = *(void **)(self + 0x8);
  if (member != 0) {
    ext_634273_t ext_fn = (ext_634273_t)G(void *, 0x634273);
    ext_fn(member, 1);
  }

  // Test flag byte (lower byte only)
  if ((flag & 1) != 0) {
    ext_634273_t ext_fn = (ext_634273_t)G(void *, 0x634273);
    ext_fn(self, 0xd);
  }
}
PCREG(435bc0, destructor_435bc0);
