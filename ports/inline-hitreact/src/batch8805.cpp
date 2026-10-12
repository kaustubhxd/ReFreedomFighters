// batch8805.cpp - hit-reaction thread, batch 8805: a soldier's own close-combat attack (ZFFActorActionCloseCombat).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);   // |a - b| (ST0)

typedef void(THISCALL *vVP)(void *self, float *p);
typedef void(THISCALL *vCmd)(void *self, u32 msg, void *data, u32 z);

// 0x5eb7e0 ZFFActorActionCloseCombat::Update() (GC 80075428). Once (+0x20 armed by Execute), when the engine clock
// ([0x70039c]+0x40, 1/1024 s) reaches the hit time +0x1c (s, truncated after x 1024): disarm; attacker (+8) and target (+0xc)
// root points (slot 0x84); the attacker's height is replaced by the target's (a horizontal distance); within 170 (0x6b7f84)
// the target gets the "DamageInfo" message (id [0x7143a8], registered in the ctor) with the SDamageInfo Execute built at +0x21.
// Returns true.
static u8 THISCALL ccUpdate(u8 *self) {
  if (self[0x20]) {
    s32 t = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x1c) * G(float, 0x678620)));
    if (!(*(s32 *)(G(u8 *, 0x70039c) + 0x40) < t)) {
      self[0x20] = 0;
      float a[3], b[3];
      a[0] = 0.0f; a[1] = 0.0f; a[2] = 0.0f;
      b[0] = 0.0f; b[1] = 0.0f; b[2] = 0.0f;
      void *at = *(void **)(self + 8);
      ((vVP)VT(at, 0x84))(at, a);
      void *tg = *(void **)(self + 0xc);
      ((vVP)VT(tg, 0x84))(tg, b);
      a[1] = b[1];
      float d = ext_4e0870(a, b);
      if (G(float, 0x6b7f84) > d) {
        tg = *(void **)(self + 0xc);
        ((vCmd)VT(tg, 0x128))(tg, *(u16 *)0x7143a8, self + 0x21, 0);
      }
    }
  }
  return 1;
}
PCREG(5eb7e0, ccUpdate);
