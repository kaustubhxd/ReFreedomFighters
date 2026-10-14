// u69_69.cpp - area 69, group 69 (slice 8). Three scalar deleting destructors of one shape. Base destructors 0x43de70 and 0x43ea20 and the delete helper 0x45c510 are
// other areas' functions (GUESS stubs in the spec). The empty helper 0x4690b0 (cdecl, two args, just ret) runs as real code.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);    // base dtor, thiscall, no args (GUESS stub)
extern "C" void THISCALL ext_43ea20(void *self);    // base dtor, thiscall, no args (GUESS stub)
extern "C" void ext_45c510(void *p);                // delete helper, cdecl, one arg (GUESS stub)
extern "C" void ext_4690b0(void *self, u32 code);   // empty cdecl (real)

// 0x45b580, ZBulletMarks::~ZBulletMarks(), thiscall one stack arg (flags, ret 4), returns this. Sets the vtable 0x684358, calls the base dtor 0x43de70; with bit 0 of flags:
// bit 2 set -> 0x4690b0(self, 0x958); otherwise 0x45c510(self).
static u8 *THISCALL dtorBulletMarks45b580(u8 *self, u32 flags) {
  *(u32 *)self = 0x684358;
  ext_43de70(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x958);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(45b580, dtorBulletMarks45b580);

// 0x44ca80, ZBloodSpray::~ZBloodSpray(): vtable 0x6801a4, base 0x43de70, size 0xeac.
static u8 *THISCALL dtorBloodSpray44ca80(u8 *self, u32 flags) {
  *(u32 *)self = 0x6801a4;
  ext_43de70(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0xeac);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(44ca80, dtorBloodSpray44ca80);

// 0x4f3c40, ZWINDOW::~ZWINDOW(): vtable 0x69909c, base 0x43ea20, size 0x68.
static u8 *THISCALL dtorWindow4f3c40(u8 *self, u32 flags) {
  *(u32 *)self = 0x69909c;
  ext_43ea20(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x68);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4f3c40, dtorWindow4f3c40);
