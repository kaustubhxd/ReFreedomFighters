// batch171.cpp - unclaimed area 17, player-mechanics slice (floor(addr/16) mod 20 == 16).
#include "ff.h"

extern "C" void THISCALL ext_635490(u8 *self);            // CRigidBody member teardown, original code
extern "C" void ext_634273(u8 *p, u32 n);                 // free-style release of a block, original code (cdecl)
extern "C" void THISCALL ext_6352a0(u8 *self, u32 a, u32 b);  // base-class cleanup, original code (callee pops 8)

// 0x53e900, thiscall (no stack args): CRigidBody::Disable. If the pointer at +0x62 is set, tears it down
// (ext_635490 on it, then ext_634273 with size 0x93), clears the pointer and the byte at +0x10f, then calls the base
// cleanup ext_6352a0(this, 0x10, 0). Map name CRigidBody::Disable, not checked against any string.
static void THISCALL rigidBodyDisable(u8 *self) {
  u8 *obj = *(u8 **)(self + 0x62);
  if (obj) {
    ext_635490(obj);
    ext_634273(obj, 0x93);
  }
  *(u8 **)(self + 0x62) = nullptr;
  self[0x10f] = 0;
  ext_6352a0(self, 0x10, 0);
}
PCREG(53e900, rigidBodyDisable);
