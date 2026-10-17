// batch937.cpp - unclaimed-09 batch 29: CRigidBody::Setup2() (core list name, GUESS; docs/20-unclaimed-09.md, claim 31).
// thiscall, no arguments, plain ret. Every call is an unverified callee (original code or a GUESS recording stub in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_53eaa0(u8 *self, u8 *big);
extern "C" void THISCALL ext_53f630(u8 *self);
extern "C" void THISCALL ext_4db500(u8 *self, u8 *out);
extern "C" void FASTCALL ext_43e960(u8 *ecx, u8 *edx);
extern "C" void THISCALL ext_53f770(u8 *self);
extern "C" void THISCALL ext_53f980(u8 *self);
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a0, u32 a1);

// 0x540bc0, CRigidBody::Setup2() (GUESS name): a 0x2ef0-byte local; stores the result of 0x53eaa0 at this+0x152 and the
// local's address at this+0x14e; calls 0x53f630; fills a 12-byte local through 0x4db500 on the sub-object [this+0x44]+8,
// copies three dwords from this+0x111 to this+0x129 and passes them to 0x43e960 (fastcall); calls 0x53f770 and 0x53f980;
// finally 0x4dc630 on the same sub-object with (0, 0x20).
static void THISCALL rigidSetup2(u8 *self) {
  u8 big[0x2ef0];
  u8 l10[12];
  *(u32 *)(self + 0x152) = ext_53eaa0(self, big);
  *(u32 *)(self + 0x14e) = (u32)big;
  ext_53f630(self);
  u8 *sub = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  ext_4db500(sub, l10);
  *(u32 *)(self + 0x129) = *(u32 *)(self + 0x111);
  *(u32 *)(self + 0x12d) = *(u32 *)(self + 0x115);
  *(u32 *)(self + 0x131) = *(u32 *)(self + 0x119);
  ext_43e960(self + 0x129, l10);
  ext_53f770(self);
  ext_53f980(self);
  ext_4dc630(*(u8 **)(*(u8 **)(self + 0x44) + 8), 0, 0x20);
}
PCREG(540bc0, rigidSetup2);
