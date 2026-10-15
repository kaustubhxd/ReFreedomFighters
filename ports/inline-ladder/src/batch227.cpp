// batch227.cpp - ZIKLNKOBJ::UpdateFacing (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" long double FASTCALL ext_44c840(float *v);   // vnorm (old length in ST0)

// 0x467d00 ZIKLNKOBJ::UpdateFacing() [high]. With flag 0x200000 in +0x136 and a facing target geom ref
// +0x1a6 that resolves (database slot 0x58): unless own slot 0x324(0) is true and slot 0x320(0) lacks bit 0x200 (the
// actor is busy with something else, inference), take the target's origin (slot 0x84) into the actor's local space
// (own slot 0x8c), flatten (y = 0) and normalise (vnorm). With z' = -z and x' = -x of that direction:
// z' < -0.5 (target behind) picks "Turn_180_*_Quick", else z' < 0.5 picks "Turn_90_*_Quick", else nothing;
// "Left" when x' < 0 (ordered), else "Right". The clip comes from own slot 0x21c (FindBestAnim) and plays with own
// slot 0x230(anim, 1); a missing clip logs "<debug message>" through the debug logger
// at 0x700390 (slot 0x20(file, 0x2d4) gives the printer, its slot 0x30 is cdecl (printer, fmt, name, clip)).
static void THISCALL ikUpdateFacing(u8 *self) {
  if (!(U32(self, 0x136) & 0x200000))
    return;
  u32 h = U32(self, 0x1a6);
  if (!h)
    return;
  void *t = vcall<void *>((void *)U32(G(u32, 0x70039c), 0x9b), 0x58, h);
  if (!t)
    return;
  if ((u8)vcall<u32>(self, 0x324, 0u)) {
    if (!(vcall<u32>(self, 0x320, 0u) & 0x200))
      return;
  }
  float p[3] = {0.0f, 0.0f, 0.0f};
  vcall<void>(t, 0x84, p);
  vcall<void>(self, 0x8c, p);
  p[1] = 0.0f;
  (void)ext_44c840(p);
  float z = bitsf(fbits(p[2]) ^ 0x80000000u);
  const char *left, *right;
  if (-0.5f > z) {
    left = (const char *)0x685f74;    // "Turn_180_Left_Quick"
    right = (const char *)0x685f88;   // "Turn_180_Right_Quick"
  } else if (0.5f > z) {
    left = (const char *)0x685fa0;    // "Turn_90_Left_Quick"
    right = (const char *)0x685fb4;   // "Turn_90_Right_Quick"
  } else {
    return;
  }
  float x = bitsf(fbits(p[0]) ^ 0x80000000u);
  const char *name = (0.0f > x) ? left : right;
  u32 anim = vcall<u32>(self, 0x21c, name);
  if (anim) {
    vcall<void>(self, 0x230, anim, 1u);
    return;
  }
  void *pr = vcall<void *>((void *)G(u32, 0x700390), 0x20, (const char *)0x685ee0, 0x2d4u);
  u8 *o = vcall<u8 *>(self, 0x20);
  const char *nm = U32(o, 4) ? (const char *)U32(o, 4) : (const char *)0x67c8e8;
  typedef void (*printf_t)(void *, const char *, const char *, const char *);
  (*(printf_t *)(*(u8 **)pr + 0x30))(pr, (const char *)0x685fc8, nm, name);
}
PCREG(467d00, ikUpdateFacing);
