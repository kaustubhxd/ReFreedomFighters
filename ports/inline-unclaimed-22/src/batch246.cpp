// batch246.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch246"): CFireController::Load,
// CRigidBody::Load. Names from the GameCube name map (high); behaviour from the PC bytes. ZLoadGame slots as called:
// 0x40, 0x48, 0x50, 0x58, 0x68, 0x6c, 0x74 each take one field pointer.
#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);   // original (ret 4): writes a name handle (0 when +0x38 is 0)
extern "C" void THISCALL ext_546040(u8 *self, u8 *load);   // original (ret 4): loads the sub-object at +0xcf

// 0x5848a0 CFireController::Load(ZLoadGame*) ret 4, returns al = 1. Clears bit 6 of +4; name = 0; 0x6352f0(this, &name);
// this->vt[4](&name); n = slot 0x40; n records of 7 dwords appended at +0x50 + 28 * count (+0x4c): each read as slot 0x50
// (word 5), 0x40 (word 0), 0x40 (word 1), 0x40 (word 6), slot 0x6c (words 2..4). Stack cookie not reproduced.
static bool THISCALL fireControllerLoad_5848a0(u8 *self, u8 *l) {
  u32 name = 0;
  *(u32 *)(self + 4) &= ~0x40u;
  ext_6352f0(self, &name);
  vcall<void>(self, 4, (u32)&name);
  u32 n;
  vcall<void>(l, 0x40, (u32)&n);
  for (u32 i = 0; i < n; i++) {
    u32 w5, w0, w1, w6, v[3];
    vcall<void>(l, 0x50, (u32)&w5);
    vcall<void>(l, 0x40, (u32)&w0);
    vcall<void>(l, 0x40, (u32)&w1);
    vcall<void>(l, 0x40, (u32)&w6);
    vcall<void>(l, 0x6c, (u32)v);
    u32 *rec = (u32 *)(self + 0x50 + *(u32 *)(self + 0x4c) * 28);
    rec[0] = w0;
    rec[1] = w1;
    rec[2] = v[0];
    rec[3] = v[1];
    rec[4] = v[2];
    rec[5] = w5;
    rec[6] = w6;
    *(u32 *)(self + 0x4c) += 1;
  }
  return true;
}
PCREG(5848a0, fireControllerLoad_5848a0);

// 0x53fc40 CRigidBody::Load(ZLoadGame*) ret 4, returns al = 1. 0x546040(+0xcf, l); clears bit 6 of +4 (after reading
// +0xcf, as the exe does); then fields +0xd3 (0x74), +0xf7 (0x48), +0xff (0x50), +0x103 (0x6c), +0x10f, +0x110 (0x68),
// +0x145, +0x139 (0x40), +0x13d, +0x141 (0x48), +0x14a (0x58), +0x149 (0x68).
static bool THISCALL rigidBodyLoad_53fc40(u8 *self, u8 *l) {
  u8 *sub = *(u8 **)(self + 0xcf);
  *(u32 *)(self + 4) &= ~0x40u;
  ext_546040(sub, l);
  vcall<void>(l, 0x74, (u32)(self + 0xd3));
  vcall<void>(l, 0x48, (u32)(self + 0xf7));
  vcall<void>(l, 0x50, (u32)(self + 0xff));
  vcall<void>(l, 0x6c, (u32)(self + 0x103));
  vcall<void>(l, 0x68, (u32)(self + 0x10f));
  vcall<void>(l, 0x68, (u32)(self + 0x110));
  vcall<void>(l, 0x40, (u32)(self + 0x145));
  vcall<void>(l, 0x40, (u32)(self + 0x139));
  vcall<void>(l, 0x48, (u32)(self + 0x13d));
  vcall<void>(l, 0x48, (u32)(self + 0x141));
  vcall<void>(l, 0x58, (u32)(self + 0x14a));
  vcall<void>(l, 0x68, (u32)(self + 0x149));
  return true;
}
PCREG(53fc40, rigidBodyLoad_53fc40);
