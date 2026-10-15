// batch508.cpp - weapons thread, batch 508: ZItemWeapon::ClassFrameUpdate (0x46bae0), the per-frame fire loop that
// FireStart enables (class call 0x10). Globals: 0x6ff98c frame id seen last, 0x6ff990 rounds fired this frame by all
// weapons together, 0x6ff998 reset with them (not used here).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef long double(THISCALL *vLD0)(void *self);

// One round per frame at most, when the trigger pull has rounds left (+0xc4), a bullet is chambered and the time
// between shots has passed since the last shot (+0xd1). Each round: ScopeFire (slot 0x370), FireRound (slot 0x390),
// count it in the frame total, take it from the magazine and the pull, and in weapon operation 0 empty the chamber
// (so mode 0 needs a chamber action per shot: pump/bolt; guess). Weapons of owners that are not IsDerivedFrom
// 0x80200014 (guess: the player class) stop once 3 rounds were fired in this frame by anyone. The muzzle flash
// (handle +0xed) is deactivated (slot 0x28) once the last shot is older than [0x70039c]+0x44 (guess: the previous
// frame's time), and with the pull finished the frame update switches itself off (slot 0x114(0x10)).
static void THISCALL classFrameUpdate(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 frame = *(u32 *)(sys + 0x3c);
  if (G(u32, 0x6ff98c) != frame) {
    G(u32, 0x6ff98c) = frame;
    G(u32, 0x6ff990) = 0;
    G(u32, 0x6ff998) = 0;
  }
  u8 player = 0;
  u8 *o = (u8 *)((vU0)VT(self, 0x2f4))(self);
  if (o && ((vBU)VT(o, 0x1e0))(o, 0x80200014))
    player = 1;
  if (G(u32, 0x6ff990) > 2 && !player)
    return;
  if (*(u32 *)(self + 0xc4) && self[0xbf]) {
    u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
    u8 *s = G(u8 *, 0x70039c);
    long double x = ((vLD0)VT(t, 0x338))(t);
    x += *(float *)(self + 0xd1);
    x *= 1024.0f;
    float f = (float)x;
    if (_mm_cvttss_si32(_mm_set_ss(f)) <= *(s32 *)(s + 0x40)) {
      ((vU0)VT(self, 0x370))(self);
      ((vU0)VT(self, 0x390))(self);
      G(u32, 0x6ff990)++;
      (*(u32 *)(self + 0xba))--;
      (*(u32 *)(self + 0xc4))--;
      if (*(u32 *)(self + 0xd5) == 0)
        self[0xbf] = 0;
      *(float *)(self + 0xd1) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;
    }
  } else if (*(u32 *)(self + 0xba) == 0) {
    self[0xbf] = 0;
  }
  sys = G(u8 *, 0x70039c);
  if (_mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0xd1) * 1024.0f)) < *(s32 *)(sys + 0x44)) {
    u8 *rm = *(u8 **)(sys + 0x9b);
    u8 *g = (u8 *)((vUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0xed));
    if (g && !((*(u32 *)(*(u8 **)(g + 8) + 0x3c) >> 10) & 1))
      ((vU0)VT(g, 0x28))(g);
    sys = G(u8 *, 0x70039c);
  }
  if (*(u32 *)(self + 0xc4) == 0 &&
      _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0xd1) * 1024.0f)) < *(s32 *)(sys + 0x44))
    ((vUU)VT(self, 0x114))(self, 0x10);
}
PCREG(46bae0, classFrameUpdate);
