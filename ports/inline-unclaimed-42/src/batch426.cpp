// batch426.cpp - unclaimed-42 batch 6 (claim 6, residue-01 queue). Names from the GC name map (naming only, never committed).
#include "ff.h"

// Original callees, thiscall. 0x4dc630 takes two stack arguments (0, 1); 0x4db7c0 one out pointer; 0x6352a0 (0x10, 0).
extern "C" void THISCALL ext_4dc630(u8 *self, u32 a, u32 b);
extern "C" void THISCALL ext_4db7c0(u8 *self, u32 *out);
extern "C" void THISCALL ext_6352a0(u8 *self, u32 a, u32 b);

// Virtual slot +0x40 of the sub-object (thiscall, no arguments).
typedef void(THISCALL *VSub40)(u8 *self);

// 0x53f5d0, CRigidBody::Setup() (high): clears the byte at this+0x110, calls 0x4dc630(0, 1) and 0x4db7c0(&local) on the
// sub-object's +8 block (the sub-object is at this+0x44), calls the sub-object's slot +0x40, then 0x6352a0(0x10, 0) on this.
static void THISCALL rigidBodySetup(u8 *self) {
  self[0x110] = 0;
  ext_4dc630(*(u8 **)(*(u8 **)(self + 0x44) + 8), 0, 1);
  u32 local = 0;
  ext_4db7c0(*(u8 **)(*(u8 **)(self + 0x44) + 8), &local);
  u8 *sub = *(u8 **)(self + 0x44);
  ((VSub40)*(u32 *)(*(u8 **)sub + 0x40))(sub);
  ext_6352a0(self, 0x10, 0);
}
PCREG(53f5d0, rigidBodySetup);
