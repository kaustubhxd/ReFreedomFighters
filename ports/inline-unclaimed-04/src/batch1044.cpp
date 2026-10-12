// batch1044.cpp - unclaimed-04 batch 44 (docs/20-unclaimed-04.md): 0x451a30, thiscall, one flag argument (ret 4), returns this.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);                     // base, hooked by address in the spec (GUESS)
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);  // free (hooked; GUESS)
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);          // helper (hooked; GUESS)
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 n);   // helper (hooked; GUESS)

// 0x451a30
static u8 *THISCALL unk451a30(u8 *self, u32 flags) {
  *(u32 *)self = 0x6813c0;
  u32 field = *(u32 *)(self + 0x3c);
  if (field != 0) ext_634273((void *)field, 0x7c);
  ext_43de70(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x44);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(451a30, unk451a30);
