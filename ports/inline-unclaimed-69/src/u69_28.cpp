// u69_28.cpp - area 69, group 28 (slice 8). No callees.
#include "ff.h"

// 0x4e6680, ZSoundDllBase::ZSoundDllBase() (GC map high). thiscall, no args, returns this. Stores the vtable 0x6974d0 at self and zeroes self+4 and self+8.
static u8 *THISCALL ctorVt6974d0(u8 *self) {
  *(u32 *)self = 0x6974d0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  return self;
}
PCREG(4e6680, ctorVt6974d0);

// 0x65f5c0. The GC name here is ZDrawBuffer::DrawUniformPrim, but the body is a getter: returns dword [self+0xc] + 0x18229 (the name does not match the body, so it is recorded as read).
static u32 THISCALL getPlus18229(u8 *self) {
  return *(u32 *)(self + 0xc) + 0x18229;
}
PCREG(65f5c0, getPlus18229);
