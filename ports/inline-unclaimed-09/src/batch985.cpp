// batch985.cpp - area 56 band, claim A51 (0x532ed0): bump-allocates a record; one register-argument call.
#include "ff.h"

extern "C" void FASTCALL ext_4de420(u8 *ecx, u8 *edx);  // original exe helper (register arguments; hooked in the spec, GUESS)

// A51 0x532ed0: esi = this->51a9; write the record header and copies of this's fields; then advance this->51a9 by esi->4.
static void THISCALL bump532ed0(u8 *self) {
  u8 *esi = *(u8 **)(self + 0x51a9);
  *(u32 *)(esi + 4) = 0x44;
  *(u32 *)esi = 0x20;
  ext_4de420(esi + 8, self + 0x4a);
  *(u32 *)(esi + 0x2c) = *(u32 *)(self + 0x6e);
  *(u32 *)(esi + 0x30) = *(u32 *)(self + 0x72);
  *(u32 *)(esi + 0x34) = *(u32 *)(self + 0x76);
  *(u32 *)(esi + 0x40) = 0;
  *(u32 *)(esi + 0x3c) = 0;
  *(u32 *)(esi + 0x38) = 0;
  u8 *eax = *(u8 **)(self + 0x51a9);
  *(u32 *)(self + 0x51a9) = (u32)(eax + *(u32 *)(eax + 4));
}
PCREG(532ed0, bump532ed0);
