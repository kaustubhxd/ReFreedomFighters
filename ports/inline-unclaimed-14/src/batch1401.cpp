// batch1401.cpp - unclaimed-14 batch 1 (docs/20-unclaimed-14.md): ZOctree origin copies, ZFFActor close-combat flag
// setters, ZCollisionBase::UnlockCollisionBox. Thiscall throughout; the bool setters test only the low byte of the
// argument (the PC code does `cmp byte ptr [ebp+8], 0`).
#include "ff.h"

// 0x4e3340, ZOctree::GetOrigin(float*) (high): copies the three dwords at this+4 to the out pointer.
static void THISCALL octreeGetOrigin(u8 *self, u32 out) {
  u32 *src = (u32 *)(self + 4);
  u32 *dst = (u32 *)out;
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
}
PCREG(4e3340, octreeGetOrigin);

// 0x4e3360, ZOctree::SetOrigin(float*) (high): copies the three dwords at the argument to this+4.
static void THISCALL octreeSetOrigin(u8 *self, u32 in) {
  u32 *src = (u32 *)in;
  u32 *dst = (u32 *)(self + 4);
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
}
PCREG(4e3360, octreeSetOrigin);

// 0x5a2c30, ZFFActor::SetCloseCombatAttack(bool) (high): if the low byte of the argument is nonzero, ORs 0x2 into the
// dword at this+0x7a6; if it is zero, ANDs the dword with ~0x2 (PC: `and dword ptr [ecx+0x7a6], 0xfffffffd` at 0x5a2c44).
static void THISCALL ffActorSetCloseCombatAttack(u8 *self, u32 a1) {
  if ((u8)a1)
    *(u32 *)(self + 0x7a6) |= 2u;
  else
    *(u32 *)(self + 0x7a6) &= ~2u;
}
PCREG(5a2c30, ffActorSetCloseCombatAttack);

// 0x5a2c50, ZFFActor::SetCloseCombatEnable(bool) (high): same test; bit 0x1 at this+0x7a6 (clear path at 0x5a2c64).
static void THISCALL ffActorSetCloseCombatEnable(u8 *self, u32 a1) {
  if ((u8)a1)
    *(u32 *)(self + 0x7a6) |= 1u;
  else
    *(u32 *)(self + 0x7a6) &= ~1u;
}
PCREG(5a2c50, ffActorSetCloseCombatEnable);

// 0x5a2c70, ZFFActor::SetCloseCombatEvade(bool) (high): same test; bit 0x4 at this+0x7a6 (clear path at 0x5a2c84).
static void THISCALL ffActorSetCloseCombatEvade(u8 *self, u32 a1) {
  if ((u8)a1)
    *(u32 *)(self + 0x7a6) |= 4u;
  else
    *(u32 *)(self + 0x7a6) &= ~4u;
}
PCREG(5a2c70, ffActorSetCloseCombatEvade);

// 0x4eb340, original code (not lifted): thiscall-style helper that clears the byte at +0xa5 of its ecx and returns.
extern "C" void THISCALL ext_4eb340(u8 *self);

// 0x4ede70, ZCollisionBase::UnlockCollisionBox(ZCollisionBox*) (medium, GUESS name): adds 4 to this, calls 0x4eb340 with
// that pointer in ecx, returns. The argument is popped by this function's ret 4; the PC bytes never read it.
static void THISCALL collisionUnlockCollisionBox(u8 *self, u32 box) {
  (void)box;
  ext_4eb340(self + 4);
}
PCREG(4ede70, collisionUnlockCollisionBox);
