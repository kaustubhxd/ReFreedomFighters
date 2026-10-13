// batch280.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch280"): CRigidBody::
// SetVelocity, which moves a rigid body's four constraint particles by a transform step so the next physics frame gives
// the body that velocity. Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_545c80(u8 *sys, int i, float *out);          // GetParticlePos (GUESS: hooked)
extern "C" void THISCALL ext_547730(u8 *sys, int i, float *p);            // SetParticleOldPos (unclaimed-62; hooked)
extern "C" void THISCALL ext_634e90(u8 *self, u32 ev);                    // ZEventBase::Activate (GUESS: hooked)
extern "C" void FASTCALL ext_43e960(float *v, const float *a);            // v -= a (inline-batch45)
extern "C" void FASTCALL ext_459fc0(float *out, const float *v, const float *m); // vmtmul (inline-collision)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);            // vmmul (inline-batch45)
extern "C" void FASTCALL ext_441940(float *v, const float *a);            // PSVECAdd (inline-batch45)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b); // PSVECSubtract (inline-batch45)

// 0x5409d0 CRigidBody::SetVelocity(transform *t) (thiscall, ret 4). For particles 1..4 of the particle system +0xcf:
// p = GetParticlePos(i) - centre +0x111; q = vmtmul(p, t), then vmmul(q, t + 0x24); p += centre (unused after). The
// step d = (t + 0x48) - (t + 0x54) + centre is added to each q, which becomes the particle's old position
// (SetParticleOldPos(i, q)). Then byte +0x10f = 1, +0xf7 = 1000, +0xfb = 3200.0, +0xff = 400.0, +0x13d = +0x141, and
// event 0x10 is activated (0x634e90). Stack cookie not reproduced.
void THISCALL rigidBodySetVelocity_5409d0(u8 *self, const float *t) {
  float p[4][3], q[4][3], d[3];
  for (int i = 0; i < 4; i++) ext_545c80(*(u8 **)(self + 0xcf), i + 1, p[i]);
  float *c = (float *)(self + 0x111);
  for (int i = 0; i < 4; i++) ext_43e960(p[i], c);
  for (int i = 0; i < 4; i++) ext_459fc0(q[i], p[i], t);
  for (int i = 0; i < 4; i++) ext_4419f0(q[i], t + 9);
  for (int i = 0; i < 4; i++) ext_441940(p[i], c);
  ext_43e920(d, t + 0x12, t + 0x15);
  ext_441940(d, c);
  for (int i = 0; i < 4; i++) ext_441940(q[i], d);
  for (int i = 0; i < 4; i++) ext_547730(*(u8 **)(self + 0xcf), i + 1, q[i]);
  u32 v = *(u32 *)(self + 0x141);
  self[0x10f] = 1;
  *(u32 *)(self + 0xf7) = 1000;
  *(u32 *)(self + 0xfb) = 0x45480000u;
  *(u32 *)(self + 0xff) = 0x43c80000u;
  *(u32 *)(self + 0x13d) = v;
  ext_634e90(self, 0x10);
}
PCREG(5409d0, rigidBodySetVelocity_5409d0);

// One REFTAB copy as the exe inlines it: src list vt 0x4c(&it) starts, vt 0x5c(&it) returns the next item; while the
// iterator's first word is not 0 the item goes to the destination list vt 4(item). A null source list is skipped; the
// destination is not checked. The 12-byte iterator is shared by all lists of one call, as in the exe.
static void copyList(u8 *dst, u8 *src, u32 off, u32 *it) {
  if (!*(u8 **)(src + off)) return;
  vcall<u32>(*(u8 **)(src + off), 0x4c, (u32)it);
  u32 x = vcall<u32>(*(u8 **)(src + off), 0x5c, (u32)it);
  while (it[0]) {
    vcall<void>(*(u8 **)(dst + off), 4, x);
    x = vcall<u32>(*(u8 **)(src + off), 0x5c, (u32)it);
  }
}

// 0x4c4c90 ZAnimSequence::CopyData(ZAnimSequence *src) (thiscall, ret 4). Copies words +0x48 and +0x4a, the lists +0x4c,
// +0x50 and +0x54 item by item, dwords +0x58, +0x5c, +0x60, byte +0x64, dword +0x65, byte +0x69 and the list +0x6a.
void THISCALL animSequenceCopyData_4c4c90(u8 *self, u8 *src) {
  u32 it[3];
  *(u16 *)(self + 0x48) = *(u16 *)(src + 0x48);
  *(u16 *)(self + 0x4a) = *(u16 *)(src + 0x4a);
  copyList(self, src, 0x4c, it);
  copyList(self, src, 0x50, it);
  copyList(self, src, 0x54, it);
  *(u32 *)(self + 0x58) = *(u32 *)(src + 0x58);
  *(u32 *)(self + 0x5c) = *(u32 *)(src + 0x5c);
  *(u32 *)(self + 0x60) = *(u32 *)(src + 0x60);
  self[0x64] = src[0x64];
  if (self + 0x65 != src + 0x65) *(u32 *)(self + 0x65) = *(u32 *)(src + 0x65);
  self[0x69] = src[0x69];
  copyList(self, src, 0x6a, it);
}
PCREG(4c4c90, animSequenceCopyData_4c4c90);
