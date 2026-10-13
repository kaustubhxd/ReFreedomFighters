// batch282.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch282"): CExplodeMolotov::
// UpdateInAir, the flying molotov's tick (the bottle follows its carrier and drops trail particles along the path since
// the last emit). Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_456b70(u8 *tpl, u32 *ctl, u32 *arg);   // ZParticleTemplate::GetController (GUESS: hooked)
extern "C" void FASTCALL ext_4e0a10(float *v);                      // vrand (GUESS: hooked)
extern "C" void FASTCALL ext_4e0980(float *v, const float *s);      // vmul (GUESS: hooked)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);      // vmmul (inline-batch45)
extern "C" void FASTCALL ext_441940(float *v, const float *a);      // PSVECAdd (inline-batch45)

#define RM (*(u8 **)0x70039cu)
#define DB (*(u8 **)(RM + 0x9b))
#define F(o) (*(float *)(self + (o)))

// 0x584f90 CExplodeMolotov::UpdateInAir() (thiscall). The bottle object db vt 0x58(+0x362) is moved to the carrier
// +0x44's position (vt 0x84, then bottle vt 0x78). The emit timer +0x99 counts down by the frame time; when it goes
// below 0 and the particle template db vt 0x58(+0x4c) exists: GetController gives the emitter id and an argument, the
// emitter is db vt 0x58(id); carrier vt 0x80 gives its matrix and position p. While the timer is negative a particle is
// emitted at the point lerped from the last emit position +0x8d to p by (dt + timer) / dt, offset by a random vector
// scaled by 10 and turned by the matrix, with zero velocity and the time (int)((clock - (int)(timer * -1024)) / 1024 *
// 1024) (emitter vt 0x218(arg, pos, vel, time)); the timer then grows by 0x67da00. p becomes the last emit position.
// Stack cookie not reproduced.
void THISCALL molotovUpdateInAir_584f90(u8 *self) {
  u8 *bottle = (u8 *)vcall<u32>(DB, 0x58, *(u32 *)(self + 0x362));
  float pos[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(*(u8 **)(self + 0x44), 0x84, (u32)pos);
  if (bottle) vcall<void>(bottle, 0x78, (u32)pos);
  float dt = *(float *)(RM + 0x48);
  float t = F(0x99) - dt;
  F(0x99) = t;
  if (t >= *(float *)0x6785d0u) return;
  u8 *tpl = (u8 *)vcall<u32>(DB, 0x58, *(u32 *)(self + 0x4c));
  if (!tpl) return;
  u32 id, arg;
  ext_456b70(tpl, &id, &arg);
  u8 *em = (u8 *)vcall<u32>(DB, 0x58, id);
  float m[12], p[3];
  vcall<void>(*(u8 **)(self + 0x44), 0x80, (u32)m, (u32)p);
  float s[3] = {10.0f, 10.0f, 10.0f};
  if (0.0f > F(0x99)) {
    do {
      float k = (dt + F(0x99)) / dt;
      float w[3], r[3], z[3];
      w[0] = (p[0] - F(0x8d)) * k + F(0x8d);
      w[1] = (p[1] - F(0x91)) * k + F(0x91);
      w[2] = (p[2] - F(0x95)) * k + F(0x95);
      ext_4e0a10(r);
      ext_4e0980(r, s);
      ext_4419f0(r, m);
      ext_441940(w, r);
      z[0] = z[1] = z[2] = 0.0f;
      int tt = *(int *)(RM + 0x40) - (int)(F(0x99) * *(float *)0x67862cu);
      int when = (int)((float)tt * *(float *)0x6785e4u * *(float *)0x678620u);
      vcall<void>(em, 0x218, arg, (u32)w, (u32)z, (u32)when);
      F(0x99) = F(0x99) + *(float *)0x67da00u;
    } while (0.0f > F(0x99));
  }
  F(0x8d) = p[0];
  F(0x91) = p[1];
  F(0x95) = p[2];
}
PCREG(584f90, molotovUpdateInAir_584f90);
#undef F
#undef DB
#undef RM
