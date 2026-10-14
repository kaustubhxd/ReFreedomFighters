// batch34106.cpp - escalation batch 34106: constructors 0x5bdb00 / 0x5d38a0 / 0x5d6a40 and scalar deleting destructors 0x5df7f0 / 0x5eaf50 / 0x636470 / 0x4286b0.
#include "ff.h"

extern "C" u32 THISCALL ext_469870(void *self);    // thiscall, plain ret
extern "C" u32 THISCALL ext_6363a0(void *self);    // thiscall, plain ret
extern "C" u32 THISCALL ext_435b50(void *self);    // thiscall, plain ret
extern "C" void ext_634273(void *p, u32 n);        // cdecl free

// Constructors, thiscall plain, return this: ext_469870(this); [this+4] |= 0x20; [this+0x44] = 0; [this] = vtable (0x6b34b4, 0x6b5108 or 0x6b5ae4).
#define CTOR(addr, vt) \
  static u32 THISCALL fn##addr(u8 *self) { \
    ext_469870(self); \
    *(u32 *)(self + 4) |= 0x20; \
    *(u32 *)(self + 0x44) = 0; \
    *(u32 *)self = vt; \
    return (u32)self; \
  } \
  PCREG(addr, fn##addr)
CTOR(5bdb00, 0x6b34b4);
CTOR(5d38a0, 0x6b5108);
CTOR(5d6a40, 0x6b5ae4);

// 0x5df7f0 / 0x5eaf50, thiscall(flags) ret 4, return this: [this] = 0x685294; free the object (size 0x10 / 0x21) when bit 0 of flags is set.
static u32 THISCALL fn5df7f0(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x10);
  return (u32)self;
}
PCREG(5df7f0, fn5df7f0);
static u32 THISCALL fn5eaf50(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x21);
  return (u32)self;
}
PCREG(5eaf50, fn5eaf50);

// 0x636470, thiscall(flags) ret 4, returns this: ext_6363a0(this); frees the object (size 0x2d) when bit 0 of flags is set.
static u32 THISCALL fn636470(u8 *self, u32 flags) {
  ext_6363a0(self);
  if (flags & 1) ext_634273(self, 0x2d);
  return (u32)self;
}
PCREG(636470, fn636470);

// 0x4286b0, thiscall(flags) ret 4, returns this: [this] = 0x678df4; ext_435b50(this); frees the object (size 0xb2) when bit 0 of flags is set.
static u32 THISCALL fn4286b0(u8 *self, u32 flags) {
  *(u32 *)self = 0x678df4;
  ext_435b50(self);
  if (flags & 1) ext_634273(self, 0xb2);
  return (u32)self;
}
PCREG(4286b0, fn4286b0);
