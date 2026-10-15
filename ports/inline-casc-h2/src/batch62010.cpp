#include "ff.h"

extern "C" void THISCALL ext_43cfb0(u8 *object);
extern "C" void ext_634273(u32 pointer, u32 tag); // cdecl, caller pops 8

// 0x435b50, thiscall() plain ret: run the optional member destructor/free,
// switch this object's vtable, then free its optional +8 allocation.
static void THISCALL fn435b50(u8 *self) {
  u8 *member = *(u8 **)(self + 0x65);
  *(u32 *)self = 0x67a65c;
  if (member) {
    ext_43cfb0(member);
    ext_634273((u32)member, 0x34a);
  }
  u32 allocation = *(u32 *)(self + 8);
  *(u32 *)self = 0x67a630;
  if (allocation) ext_634273(allocation, 1);
}

PCREG(435b50, fn435b50);
