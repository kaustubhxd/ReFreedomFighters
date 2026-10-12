// batch604.cpp - unclaimed-06 claim 4 (docs/20-unclaimed-06.md): ZCollisionBase::LockCollisionBox. Thiscall, two arguments, ret 8.
// Names are from the GC name map (naming only). Callees 0x4ea380 and 0x4eb060 are original code (not lifted here).
#include "ff.h"

extern "C" void THISCALL ext_4ea380(u8 *self);                       // original code, called with ecx = this+4 and no arguments
extern "C" void THISCALL ext_4eb060(u8 *self, u32 a0, u32 a1);       // original code, called with ecx = this+4, pushed a1 then a0

// 0x4edd10, ZCollisionBase::LockCollisionBox(char*, unsigned int) (medium name): calls ext_4ea380(this+4), then
// ext_4eb060(this+4, a0, a1), clears the dword at this+0xc and returns this+4 (lea eax, [edi+4]).
static u8 *THISCALL collisionLockBox(u8 *self, u32 a0, u32 a1) {
  ext_4ea380(self + 4);
  ext_4eb060(self + 4, a0, a1);
  *(u32 *)(self + 0xc) = 0;
  return self + 4;
}
PCREG(4edd10, collisionLockBox);
