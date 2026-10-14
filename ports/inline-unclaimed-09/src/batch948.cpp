// batch948.cpp - area 56 residue 15, claim A7: ZFFActor::Load2() (0x5a0af0). thiscall, no arguments, plain ret. Every call is
// an unverified callee (GUESS recording stubs in the spec).
#include "ff.h"

extern "C" void THISCALL ext_4790e0(u8 *self);
extern "C" void THISCALL ext_5a04f0(u8 *self);
extern "C" void THISCALL ext_5a0290(u8 *self);
extern "C" u32 THISCALL ext_589fd0(u8 *self, u32 a);

typedef u32(THISCALL *Get678)(u8 *self);
typedef u8 *(THISCALL *GetR)(u8 *self, u32 v);
typedef u32(THISCALL *Get100)(u8 *self, u32 k);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5a0af0, ZFFActor::Load2() (high): see docs/20-unclaimed-56.md claim A7.
static void THISCALL ffActorLoad2(u8 *self) {
  ext_4790e0(self);
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = ((Get678)slot(self, 0x678))(self);
  u8 *r = ((GetR)slot(m, 0x58))(m, v);
  *(u32 *)(self + 0x8ee) = ((Get100)slot(r, 0x100))(r, 0x690428);
  *(u32 *)(self + 0x913) = ((Get100)slot(r, 0x100))(r, 0x6a5cf0);
  ext_5a04f0(self);
  ext_5a0290(self);
  *(u32 *)(self + 0x921) = ext_589fd0(G(u8 *, 0x7003b8), *(u32 *)(self + 0x925));
}
PCREG(5a0af0, ffActorLoad2);
