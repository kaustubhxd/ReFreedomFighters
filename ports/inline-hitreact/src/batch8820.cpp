// batch8820.cpp - wire-hit-parts thread (2026-10-15), batch 8820: ZLNKOBJ::GetBoneFromPoint (0x462d80), the nearest-bone lookup under
// ZIKLNKOBJ::GetBoneCollision (slot 0x2b8).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" u8 *THISCALL ext_463010(u8 *self);                                      // [this+0x6c] slot 0x58(this): the pose array (0x30 bytes a bone)
extern "C" void FASTCALL ext_460e20(float *d, const float *s);                    // d = s (3 floats)
extern "C" void FASTCALL ext_441970(float *out, const float *in, const float *m);  // vmmul
extern "C" void FASTCALL ext_441940(float *d, const float *s);                     // PSVECAdd d += s
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul
extern "C" float FASTCALL ext_465470(float *v);                                    // squared length, in ST0

typedef u8 *(THISCALL *vP0)(void *self);

// 0x462d80 ZLNKOBJ::GetBoneFromPoint(const float* p) const (GC 80181974), returns a bone index (0 when none is picked).
// pose = 0x463010 (this); table = own slot 0x2cc (48-byte records: centre +0, half extents +0x10). Bones 2 .. (+0x20 count, tested for
// equality): w = pose[i] * centre + pose[i].pos (+0x24); q = p - w; q = pose[i]^T q; inside the box (each half > |q_k|) -> best = 0 and
// pick = i; then (the same bone, or any other) when best >= |q|^2 (0x465470) -> best = |q|^2, pick = i. Initial best = float at 0x67cd44.
static s32 THISCALL getBoneFromPoint(u8 *self, const float *p) {
  u8 *pose = ext_463010(self);
  u8 *tab = ((vP0)VT(self, 0x2cc))(self);
  s32 pick = 0;
  float best = G(float, 0x67cd44);
  for (s32 i = 2; i != *(s32 *)(self + 0x20); i++) {
    float c[3], w[3], h[3], q[3];
    ext_460e20(c, (const float *)(tab + i * 0x30));
    ext_460e20(h, (const float *)(tab + i * 0x30 + 0x10));
    ext_441970(w, c, (const float *)(pose + i * 0x30));
    ext_441940(w, (const float *)(pose + i * 0x30 + 0x24));
    ext_43e920(q, p, w);
    ext_441a60(q, (const float *)(pose + i * 0x30));
    if ((double)h[0] > __builtin_fabs((double)q[0]) && (double)h[1] > __builtin_fabs((double)q[1]) && (double)h[2] > __builtin_fabs((double)q[2])) {
      best = 0.0f;
      pick = i;
    }
    float len = ext_465470(q);
    if (best >= len) {
      best = len;
      pick = i;
    }
  }
  return pick;
}
PCREG(462d80, getBoneFromPoint);
