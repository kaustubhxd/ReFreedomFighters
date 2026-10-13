// batch13020.cpp - fresh slice 13, batch 20 (docs/20-fresh-13.md), 2026-10-12.
// 0x5c5010 GUESS timed-object updater (no name map entry; called directly): thiscall (const float* pos, const float*
// planes), ret 8. Records of 0x19 bytes at this+0x4c (count +0x50): +0 start time, +4 object, +8 id, +0xc velocity,
// +0x18 done byte. Returns the index of the last record that is (or becomes) done, -1 when none.
//  - Done records are skipped. A record older than 0x1400 ticks (sys+0x40 > start + 0x1400, signed) is killed:
//    object->vtbl[+0x28]() when there is an object, done = 1.
//  - Otherwise: holder = db[+0x58]((this+0x44)->+0x18 ->vtbl[+0x30](id)); object->vtbl[+0x80](&m, &p);
//    p += velocity * sys+0x48 (0x451890, fastcall, x87 code run as exe code); object->vtbl[+0x7c](&m, &p).
//  - Only the record numbered this+0x54 (one per call, round robin) is then checked: when this+0x60 is 0, or p - pos
//    (0x43e920) is in front of both planes (dot > 0), the start time is refreshed from sys+0x40; then q = p goes
//    through holder->vtbl[+0x8c](&q) and the record is killed when |q.x|, |q.y| or |q.z| (as double) exceeds the
//    holder geom's half size (+0x40 / +0x44 / +0x48) + 200.0f (0x67da2c).
//  - Afterwards this+0x54 advances and wraps to 0 at the count.
// The /GS cookie check is not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_451890[], ext_43e920[];
typedef void(THISCALL *P0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef void(THISCALL *P2)(void *self, float *a, float *b);
typedef void(THISCALL *PV)(void *self, float *a);
typedef void(FASTCALL *AddScaled)(float *dst, const float *src, float s);
typedef void(FASTCALL *Sub)(float *out, const float *a, const float *b);

static void kill(u8 *rec) {
  u8 *o = AT(u8 *, rec, 4);
  if (o)
    ((P0)VT(o, 0x28))(o);
  AT(u8, rec, 0x18) = 1;
}

static s32 THISCALL fn5c5010(u8 *self, const float *pos, const float *pl) {
  s32 last = -1;
  for (s32 i = 0; i < AT(s32, self, 0x50); i++) {
    u8 *rec = AT(u8 *, self, 0x4c) + i * 0x19;
    if (AT(u8, rec, 0x18)) {
      last = i;
      continue;
    }
    u8 *sys = G(u8 *, 0x70039c);
    if (AT(s32, sys, 0x40) > (s32)(AT(u32, rec, 0) + 0x1400)) {
      kill(rec);
      last = i;
      continue;
    }
    u8 *t = AT(u8 *, AT(u8 *, self, 0x44), 0x18);
    u32 h = ((R1)VT(t, 0x30))(t, AT(u32, rec, 8));
    u8 *db = AT(u8 *, sys, 0x9b);
    u8 *holder = (u8 *)((R1)VT(db, 0x58))(db, h);
    u8 *o = AT(u8 *, rec, 4);
    float m[12], p[3];
    ((P2)VT(o, 0x80))(o, m, p);
    ((AddScaled)(void *)ext_451890)(p, (float *)(rec + 0xc), AT(float, G(u8 *, 0x70039c), 0x48));
    ((P2)VT(AT(u8 *, rec, 4), 0x7c))(AT(u8 *, rec, 4), m, p);
    if (AT(s32, self, 0x54) != i)
      continue;
    bool refresh = true;
    if (AT(u32, self, 0x60)) {
      float d[3];
      ((Sub)(void *)ext_43e920)(d, p, pos);
      float a = pl[1] * d[1];
      a = a + pl[0] * d[0];
      a = a + pl[2] * d[2];
      refresh = false;
      if (a > 0.0f) {
        float b = pl[4] * d[1];
        b = b + pl[3] * d[0];
        b = b + pl[5] * d[2];
        refresh = b > 0.0f;
      }
    }
    if (refresh) {
      u8 *now = G(u8 *, 0x70039c) + 0x40;
      if (rec != now)
        AT(u32, rec, 0) = AT(u32, now, 0);
    }
    float q[3] = {p[0], p[1], p[2]};
    ((PV)VT(holder, 0x8c))(holder, q);
    u8 *g = AT(u8 *, holder, 8);
    float k = G(float, 0x67da2c);
    if ((double)__builtin_fabsf(q[0]) > (double)(AT(float, g, 0x40) + k) ||
        (double)__builtin_fabsf(q[1]) > (double)(AT(float, g, 0x44) + k) ||
        (double)__builtin_fabsf(q[2]) > (double)(AT(float, g, 0x48) + k)) {
      kill(AT(u8 *, self, 0x4c) + i * 0x19);
      last = i;
    }
  }
  AT(s32, self, 0x54)++;
  if (AT(s32, self, 0x54) >= AT(s32, self, 0x50))
    AT(s32, self, 0x54) = 0;
  return last;
}
PCREG(5c5010, fn5c5010);
