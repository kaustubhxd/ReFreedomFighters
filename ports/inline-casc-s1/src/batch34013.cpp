// batch34013.cpp - cascade tier E, batch 34013: two scalar deleting destructors (thiscall(flags) ret 4, return this): set the vtable, free two
// members (cdecl 0x634273(ptr, size)), run the base body, then by flags: bit 0 clear -> nothing; bit 0 set -> bit 2 clear: 0x45c510(this) (delete),
// bit 2 set: 0x4690b0(this, size) (empty cdecl stub).
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);          // cdecl, free(ptr, size)
extern "C" void THISCALL ext_43de70(u8 *self);      // base body (sets vtable 0x67c3a4, tail 0x45c3e0)
extern "C" void THISCALL ext_43ea20(u8 *self);      // base body 2
extern "C" void ext_45c510(u8 *self);               // cdecl delete, plain ret
extern "C" void ext_4690b0(u8 *self, u32 n);        // cdecl empty stub

// 0x4573a0
static u8 *THISCALL fn4573a0(u8 *self, u32 flags) {
  u8 *a = *(u8 **)(self + 0xd0);
  *(u32 *)self = 0x6832f8;
  if (a) ext_634273(a, 0x10);
  a = *(u8 **)(self + 0xcc);
  if (a) ext_634273(a, 0x18);
  ext_43de70(self);
  if (flags & 1) {
    if (!(flags & 4)) ext_45c510(self);
    else ext_4690b0(self, 0x354);
  }
  return self;
}
PCREG(4573a0, fn4573a0);

// 0x476560
static u8 *THISCALL fn476560(u8 *self, u32 flags) {
  u8 *a = *(u8 **)(self + 0x64);
  *(u32 *)self = 0x689de4;
  if (a) ext_634273(a, 4);
  a = *(u8 **)(self + 0x68);
  if (a) ext_634273(a, 4);
  ext_43ea20(self);
  if (flags & 1) {
    if (!(flags & 4)) ext_45c510(self);
    else ext_4690b0(self, 0x77);
  }
  return self;
}
PCREG(476560, fn476560);
