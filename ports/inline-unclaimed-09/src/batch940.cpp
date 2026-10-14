// batch940.cpp - unclaimed-09 batch 32: ZFFHeroMovementCloseCombat::GetAnims() (core list; docs/20-unclaimed-09.md, claim 34).
// thiscall, no arguments, plain ret. this.vt[0x58](K) is an unverified callee (GUESS recording stub in the spec).
#include "ff.h"

typedef u32(THISCALL *Get58)(u8 *self, u32 k);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// The 18 stores, in order: this+off = this.vt[0x58](K).
static const u32 kStoreK[18] = {
  0x6ae84c, 0x6b7cc8, 0x6b7cdc, 0x6b7cf0, 0x6b7d08, 0x6b7cdc, 0x6b7d24, 0x6b7d3c, 0x6b7d50,
  0x6b7d64, 0x6b7d7c, 0x6b7d50, 0x6b7cdc, 0x6b7d3c, 0x6b7d50, 0x6b7d64, 0x6b7d7c, 0x6b7d50,
};
static const u32 kStoreOff[18] = {
  0x54c, 0x550, 0x554, 0x558, 0x55c, 0x560, 0x564, 0x568, 0x56c,
  0x570, 0x574, 0x578, 0x57c, 0x580, 0x584, 0x588, 0x58c, 0x590,
};
// The six fill-if-zero copies, in order: if this+dst == 0 then this+dst = this+src.
static const u32 kFillDst[6] = {0x564, 0x568, 0x56c, 0x570, 0x574, 0x578};
static const u32 kFillSrc[6] = {0x54c, 0x550, 0x554, 0x558, 0x55c, 0x560};

// 0x5e4400, ZFFHeroMovementCloseCombat::GetAnims() (core list name): fills the 18 offsets from the vtable, then the fill pass.
static void THISCALL closeCombatGetAnims(u8 *self) {
  for (int i = 0; i < 18; i++) {
    u32 v = ((Get58)slot(self, 0x58))(self, kStoreK[i]);
    *(u32 *)(self + kStoreOff[i]) = v;
  }
  for (int i = 0; i < 6; i++) {
    if (*(u32 *)(self + kFillDst[i]) == 0) *(u32 *)(self + kFillDst[i]) = *(u32 *)(self + kFillSrc[i]);
  }
}
PCREG(5e4400, closeCombatGetAnims);
