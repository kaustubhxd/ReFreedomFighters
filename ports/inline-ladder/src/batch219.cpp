// batch219.cpp - hero action bodies (inline-ladder thread, 2026-10-11): ZFFActionSwingBat::Execute and
// ZFFActionUseKnife::Execute (melee).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4614d0(void *boneAnim, float t, u32 fn, u32 data);   // ZBoneAnim::AddCallBack
extern "C" u32 THISCALL ext_466f60(void *actor, u32 sound);                       // ZIKLNKOBJ::PlaySound

// Play anim through hero slot 0x228(anim, 1, 0.0, 10.0, 1.0) and hang the action callback 0x465710 at t = 7.0.
static inline void playMelee(void *hero, u32 anim) {
  void *ba = vcall<void *>(hero, 0x228, anim, 1u, 0u, 0x41200000u, 0x3f800000u);
  ext_4614d0(ba, 7.0f, 0x465710, 0);
}

// 0x5e0410 ZFFActionSwingBat::Execute() [GameCube reference, medium ("*Swing*")], slot 2, AL = 1. +8 hero, +0xc animation.
// Plays the swing, then the hero's "*Swing*" sound: hero slot 0x578("*Swing*") gives a name, the sound manager
// ([engine+0x1a9f], its vtable read first) slot 0x60 turns it into an id, ZIKLNKOBJ::PlaySound plays it and the
// database (slot 0x60) gives the sound object. On it: +0x78 = 0.16, +0x88 = 100.0, and a random pitch/offset:
// v = (float)(engine slot 0x1c0(file, 0x238) * -300.0) (x87; slot 0x1c0 is the engine's debug random float),
// i = trunc(v); +0x60 = i - old +0x64; +0x64 = i.
static bool THISCALL swingBatExecute(u8 *self) {
  playMelee((void *)U32(self, 8), U32(self, 0xc));
  u8 *snd = (u8 *)U32(G(u32, 0x70039c), 0x1a9f);
  u8 *svt = *(u8 **)snd;
  u32 name = vcall<u32>((void *)U32(self, 8), 0x578, (const char *)0x6b749c);
  typedef u32(THISCALL * fn)(void *, u32);
  u32 id = (*(fn *)(svt + 0x60))((void *)U32(G(u32, 0x70039c), 0x1a9f), name);
  u32 h = ext_466f60((void *)U32(self, 8), id);
  u8 *o = vcall<u8 *>((void *)U32(G(u32, 0x70039c), 0x9b), 0x60, h);
  if (o) {
    U32(o, 0x78) = 0x3e23d70b;
    long double r = vcall<long double>((void *)G(u32, 0x70039c), 0x1c0, (const char *)0x6b74a4, 0x238u);
    r = r * (long double)-300.0f;
    U32(o, 0x88) = 0x42c80000;
    float v = (float)r;
    s32 i = _mm_cvttss_si32(_mm_set_ss(v));
    U32(o, 0x60) = (u32)i - U32(o, 0x64);
    U32(o, 0x64) = (u32)i;
  }
  return true;
}
PCREG(5e0410, swingBatExecute);

// 0x5e05a0 ZFFActionUseKnife::Execute() [GameCube reference, medium], slot 2, AL. +8 hero, +0xc the knife animation set
// (a pointer to the hero's +0x77c; its first word is the stab animation). With an animation: plays it as SwingBat does
// and returns true; without: tail-calls its own CallBack (slot 0xc).
static u32 THISCALL useKnifeExecute(u8 *self) {
  u32 anim = U32(U32(self, 0xc), 0);
  if (!anim)
    return vcall<u32>(self, 0xc);
  playMelee((void *)U32(self, 8), anim);
  return 1;
}
PCREG(5e05a0, useKnifeExecute);
