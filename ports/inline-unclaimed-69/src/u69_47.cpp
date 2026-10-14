// u69_47.cpp - area 69, group 47 (slice 8). SEH tag: the original sets up and tears down an fs:[0] frame, which the port does not reproduce.
#include "ff.h"

extern "C" void ext_4690b0(void *self, u32 code);  // empty cdecl (the caller pops both args)

// 0x4c3350, thiscall one stack arg (flags, ret 4), returns this. Sets vtable 0x693e3c; if the member at self+0x48 is non-null, calls its slot 0 with arg 1;
// clears self+0x44 and self+0x30; sets vtable 0x686874; calls slot 0x34 of the object at global 0x70039c -> +0x9b with self as the arg.
// If flags bit 0 is set: with bit 2 set, calls 0x4690b0(self, 0x60); otherwise calls the pointer at global 0x7003b0 (the original traps when it is null).
// SEH frame not reproduced.
static u8 *THISCALL dtor4c3350(u8 *self, u32 flags) {
  u8 *member = *(u8 **)(self + 0x48);
  *(u32 *)self = 0x693e3c;
  if (member)
    vcall<void>(member, 0, 1u);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *g = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(g + 0x9b);
  vcall<void>(obj, 0x34, (void *)self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x60);
    } else {
      void (*fp)(void) = *(void (**)(void))0x7003b0;
      if (fp)
        fp();
    }
  }
  return self;
}
PCREG(4c3350, dtor4c3350);
