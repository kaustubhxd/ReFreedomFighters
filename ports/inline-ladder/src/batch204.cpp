// batch204.cpp - ladder tree (inline-ladder thread, 2026-10-11): ZFFHeroMovementGuide::WantControl (the ladder grab test).
#include "ff.h"

extern "C" const float *THISCALL ext_44ad50(void *shape, float t, float *frac);                 // ZSHAPE::GetSegment
extern "C" float THISCALL ext_44ace0(void *shape, float *out, const float *pts, const float *p); // GetDistToSegment (b203)
extern "C" void FASTCALL ext_43e960(float *a, const float *b);                                   // a -= b (x87)
extern "C" void THISCALL ext_460b60(void *basicShape, float *out, float t);                     // BasicShape::GetSplineVelocity
extern "C" void THISCALL ext_4e09b0(float *v);                                                   // vneg
extern "C" void THISCALL ext_5950c0(void *hero, u32 action, float v, u32 name);                 // ZFFHERO::SetUseAction

#define F32(p, off) (*(float *)((u8 *)(p) + (off)))
#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x5e7f20, ZFFHeroMovementGuide::WantControl(const float *dir, const float *pos, const float *unused)
// [, medium; vtable slot 3], thiscall, ret 0xc, returns AL.
// Fields of this (PC, packed): +4 the hero (float +0x43d subtracted from pos.y), +0x36d the ZFFHERO (SetUseAction,
// its +0x9d3 use action and byte +0x66c), +0x54c the ladder list (+0x18 an iterator object: slot 0x4c begin, slot 0x5c
// next, which writes the "valid" dword of the 12-byte iterator), +0x550 the grabbed ladder (shape), +0x579 grabbed at
// the top end.
// 1. Already holding a ladder (+0x550 non-zero): return 1. No list or no iterator: return 0.
// 2. p = pos with y lowered by hero+0x43d. For each ladder item: shape = slot 0x58 of [engine+0x9b] (item);
//    q = p with y + 110.0 (the float at 0x6b4fc0, chest height) taken to the shape's local space (slot 0x8c);
//    skip the shape when its slot 0x190(q) (bound distance) is above 50 (0x680a84; NaN does not skip).
// 3. For the two ends t = 0 and 1: GetSegment(t), GetDistToSegment(closest[t], segment, q); end t is in reach when
//    50 > distance. None in reach: next item.
// 4. top = (closest[1] in world, slot 0x84).y > (closest[0] in world).y. For each end in reach: d = world(closest) - p
//    (0x43e960), d.y = 0; v = BasicShape(shape+0x1c) velocity at t, rotated by slot 0x88, negated for t = 0, and
//    normalised in x87 unless it is exactly (0, 0, 0). The end is taken when it is the top end, or dot(dir, v) > 0
//    (the hero walks toward the ladder; from the top there is no facing test).
// 5. Taken: +0x550 = shape; SetUseAction(0x10, |d| * 0.1 (0x67a284), 0). If the hero's use action is then 0x10 and
//    byte +0x66c is set: +0x579 = (end == top), return 1. Otherwise +0x550 = 0, return 0.
static bool THISCALL wantControl(u8 *self, const float *dir, const float *pos, const float *unused) {
  (void)unused;
  if (U32(self, 0x550))
    return true;
  u8 *list = (u8 *)U32(self, 0x54c);
  if (!list)
    return false;
  float p[3];
  p[0] = pos[0];
  p[1] = pos[1] - F32(U32(self, 4), 0x43d);
  p[2] = pos[2];
  void *it = (void *)U32(list, 0x18);
  if (!it)
    return false;
  u32 st[3];
  vcall<void>(it, 0x4c, st);
  u32 item = vcall<u32>((void *)U32(U32(self, 0x54c), 0x18), 0x5c, st);
  while (st[0]) {
    u8 *shape = vcall<u8 *>((void *)U32(G(u32, 0x70039c), 0x9b), 0x58, item);
    float q[3];
    q[0] = p[0];
    q[1] = p[1] + G(float, 0x6b4fc0);
    q[2] = p[2];
    vcall<void>(shape, 0x8c, q);
    float bd = vcall<float>(shape, 0x190, q);
    if (!(bd > 50.0f)) {
      u32 mask = 0;
      float cl[2][3];
      for (u32 i = 0; i < 2; i++) {
        const float *seg = ext_44ad50(shape, (float)i, 0);
        float out[3];
        float dist = ext_44ace0(shape, out, seg, q);
        cl[i][0] = out[0];
        cl[i][1] = out[1];
        cl[i][2] = out[2];
        if (50.0f > dist)
          mask |= 1u << i;
      }
      if (mask) {
        float w0[3] = {cl[0][0], cl[0][1], cl[0][2]};
        float w1[3] = {cl[1][0], cl[1][1], cl[1][2]};
        vcall<void>(shape, 0x84, w0);
        vcall<void>(shape, 0x84, w1);
        u32 top = w1[1] > w0[1] ? 1 : 0;
        for (u32 i = 0; i < 2; i++) {
          if (!(mask & (1u << i)))
            continue;
          float d[3] = {cl[i][0], cl[i][1], cl[i][2]};
          vcall<void>(shape, 0x84, d);
          ext_43e960(d, p);
          d[1] = 0.0f;
          float v[3];
          ext_460b60(shape + 0x1c, v, (float)i);
          vcall<void>(shape, 0x88, v);
          if (i == 0)
            ext_4e09b0(v);
          if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)) {
            long double s = (long double)v[0] * v[0];
            s = s + (long double)v[1] * v[1];
            s = s + (long double)v[2] * v[2];
            long double inv = 1.0L / fsqrt_x87(s);
            v[0] = (float)(v[0] * inv);
            v[1] = (float)(v[1] * inv);
            v[2] = (float)(v[2] * inv);
          }
          if (top == i || (dir[1] * v[1] + dir[0] * v[0]) + dir[2] * v[2] > 0.0f) {
            float len2 = d[1] * d[1] + d[0] * d[0];
            len2 = len2 + d[2] * d[2];
            U32(self, 0x550) = (u32)shape;
            float len = (float)crt::sqrt((double)len2);
            ext_5950c0((void *)U32(self, 0x36d), 0x10, len * 0.1f, 0);
            u8 *hero = (u8 *)U32(self, 0x36d);
            if (U32(hero, 0x9d3) == 0x10 && hero[0x66c]) {
              U32(self, 0x579) = (top == i) ? 1 : 0;
              return true;
            }
            U32(self, 0x550) = 0;
            return false;
          }
        }
      }
    }
    item = vcall<u32>((void *)U32(U32(self, 0x54c), 0x18), 0x5c, st);
  }
  return false;
}
PCREG(5e7f20, wantControl);
