// batch278.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch278"): the CRigidBody
// deleting destructor and CExplodeMolotov::FrameUpdate (the burning molotov's tick: flame particle fade, light fade-out,
// cleanup after 5 s). Names from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_53cfa0(u8 *self);                 // CRigidBody::~CRigidBody body (GUESS: hooked)
extern "C" void ext_4690b0(u8 *p, u32 size);              // sized free (audit/inline-ladder; hooked)
extern "C" void THISCALL ext_584f90(u8 *self);                 // CExplodeMolotov::UpdateInAir (GUESS: hooked)
extern "C" void THISCALL ext_581c10(u8 *self);                 // CExplodeMolotov::CollideParticles (GUESS: hooked)
extern "C" void THISCALL ext_582e20(u8 *self);                 // molotov flame update (GUESS: hooked)
extern "C" void THISCALL ext_584c30(u8 *mgr, u8 *slot);        // particle manager release (unclaimed-27; hooked)
extern "C" void THISCALL ext_44b610(u8 *snd);                  // sound stop (unclaimed-62; hooked)
extern "C" void ext_44b740(u8 *snd);                     // sound free (inline-soundtimers; hooked)

#define RM (*(u8 **)0x70039cu)
#define C(a) (*(float *)(a##u))

// 0x53d050 CRigidBody scalar deleting destructor (thiscall, flags). Runs the destructor body 0x53cfa0; with flag 1 the
// object is freed through 0x4690b0(this, 0x157) when flag 4 is set, else the assert hook 0x7003b0 fires (int3 when there
// is none). Returns this. SEH frame not reproduced.
u8 *THISCALL rigidBodyDelete_53d050(u8 *self, u32 flags) {
  ext_53cfa0(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x157);
    } else {
      void (*a)() = *(void (**)())0x7003b0u;
      if (!a) __builtin_debugtrap();
      else a();
    }
  }
  return self;
}
PCREG(53d050, rigidBodyDelete_53d050);

// 0x583a10 CExplodeMolotov::FrameUpdate() (thiscall). In the air (byte +0x8c) it is UpdateInAir 0x584f90. Else particle
// collision 0x581c10 and flame update 0x582e20, then the five flame slots (+0x24a, stride 0x44) get the time left,
// (0x1400 - (int)(start +0x5c * -1024) - clock) / 1024. Past start + 4.8 s the light +0x36e loses a third of +0x84 per
// frame; past start + 5 s: this->vt 0x68(0x10, 0), each slot released from the particle manager [0x7003b8]+0x2c51
// (0x584c30 on slot - 0x40) and zeroed, +0x44 vt 0x28(), the object db vt 0x58(+0x362) gets vt 0x28(), a playing sound
// +0x36e (word +0x10) is stopped (0x44b610) and freed (0x44b740), and +0x36e cleared.
void THISCALL molotovFrameUpdate_583a10(u8 *self) {
  if (self[0x8c]) {
    ext_584f90(self);
    return;
  }
  ext_581c10(self);
  ext_582e20(self);
  u8 *slots = self + 0x24a;
  for (int i = 0; i < 5; i++) {
    int left = 0x1400 - (int)(*(float *)(self + 0x5c) * C(0x67862c)) - *(int *)(RM + 0x40);
    *(float *)(slots + i * 0x44) = (float)left * C(0x6785e4);
  }
  u8 *rm = RM;
  float st = *(float *)(self + 0x5c);
  if ((int)((st + C(0x679544) - C(0x67c194)) * C(0x678620)) < *(int *)(rm + 0x40)) {
    u8 *l = *(u8 **)(self + 0x36e);
    if (l) *(float *)(l + 0x84) = *(float *)(l + 0x84) / C(0x680a5c);
  }
  if ((int)((*(float *)(self + 0x5c) + C(0x679544)) * C(0x678620)) >= *(int *)(rm + 0x40)) return;
  vcall<void>(self, 0x68, 0x10u, 0u);
  for (int i = 0; i < 5; i++) {
    ext_584c30(*(u8 **)(*(u8 **)0x7003b8u + 0x2c51), slots + i * 0x44 - 0x40);
    *(u32 *)(slots + i * 0x44) = 0;
  }
  vcall<void>(*(u8 **)(self + 0x44), 0x28);
  u8 *o = (u8 *)vcall<u32>(*(u8 **)(RM + 0x9b), 0x58, *(u32 *)(self + 0x362));
  if (o) vcall<void>(o, 0x28);
  u8 *s = *(u8 **)(self + 0x36e);
  if (s && *(u32 *)(s + 0x10)) {
    ext_44b610(s);
    ext_44b740(s);
  }
  *(u32 *)(self + 0x36e) = 0;
}
PCREG(583a10, molotovFrameUpdate_583a10);
#undef C
#undef RM
