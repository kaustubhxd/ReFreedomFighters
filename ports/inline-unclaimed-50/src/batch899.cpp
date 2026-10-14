// batch899.cpp - gap band slice: three wrappers of the same shape around helper calls (thiscall, one stack arg, ret 4).
// Each calls the object's slot +0xec (no args), then the helper with the argument (ECX = this), then slot +0xe8 (no args), and
// returns the helper's result. 0x41f510 ZSysMemGC::NewWithRef returns the helper's byte (al); 0x41f7c0 ZSysMem::ExgRefs and
// 0x41f8c0 ZSysMemGC::New return the helper's dword (eax). The helpers (0x41e8a0, 0x41ee20, 0x41eee0) are stood in.
#include "ff.h"

extern "C" u8 THISCALL ext_41e8a0(void *self, u32 n);     // helper (stood in); ret 4, returns al
extern "C" u32 THISCALL ext_41ee20(void *self, u32 n);    // helper (stood in); ret 4, returns eax
extern "C" u32 THISCALL ext_41eee0(void *self, u32 n);    // helper (stood in); ret 4, returns eax

// 0x41f510 (name map: ZSysMemGC::NewWithRef(unsigned int)).
static u8 THISCALL NewWithRef41f510(u8 *self, u32 n) {
  vcall<void>(self, 0xec);
  u8 bl = ext_41e8a0(self, n);
  vcall<void>(self, 0xe8);
  return bl;
}
PCREG(41f510, NewWithRef41f510);

// 0x41f7c0 (name map: ZSysMem::ExgRefs(void*, void*)): one stack word in the exe.
static u32 THISCALL ExgRefs41f7c0(u8 *self, u32 n) {
  vcall<void>(self, 0xec);
  u32 r = ext_41ee20(self, n);
  vcall<void>(self, 0xe8);
  return r;
}
PCREG(41f7c0, ExgRefs41f7c0);

// 0x41f8c0 (name map: ZSysMemGC::New(unsigned int)).
static u32 THISCALL New41f8c0(u8 *self, u32 n) {
  vcall<void>(self, 0xec);
  u32 r = ext_41eee0(self, n);
  vcall<void>(self, 0xe8);
  return r;
}
PCREG(41f8c0, New41f8c0);
