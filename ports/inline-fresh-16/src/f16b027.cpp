// f16b027.cpp - fresh slice 16, batch 27 (2026-10-12).
// 0x4e7240 ZParamParticle::GetPosVel(pos, vel, t): dt = t - f+0x28; drag k = f+0xc. k >= 0.001f: e = (float)exp(-(k * dt));
//           pos = +0x10 + e * +0x1c (vaddscalar 0x443ef0), pos += dt * +0 (0x451890), vel = +0 + (-(e * k)) * +0x1c. Else:
//           pos = +0x10 + dt * +0x1c, pos += dt*dt * +0, vel = +0x1c + (dt+dt) * +0. The vector helpers run as exe code; exp
//           is the CRT import (stubbed). Ret 0xc.
// 0x443b40 ZTreeGroup::RemoveDynamicChildTreeGroup(child): as 0x443c80 with the dynamic list (word count at +2, entries
//           at +0x404, capacity word at +0) and slot 0x30c in place of 0x308.
// 0x630200 build_bl_tree(s) (zlib): scan_tree(s, dyn_ltree, l_desc.max_code); scan_tree(s, dyn_dtree, d_desc.max_code);
//           build_tree(s, &bl_desc); max = 18..3 while bl_tree[bl_order[max]].Len == 0; opt_len += 3 * (max + 1) + 14.
//           Returns max.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_443ef0[], ext_451890[], ext_634db8[], ext_4db7e0[], ext_630dd0[], ext_6302f0[];

typedef void(FASTCALL *VAdd4)(float *, const float *, const float *, float);
typedef void(FASTCALL *VAdd3)(float *, const float *, float);
typedef double(VECTORCALL *Exp)(double);

extern "C" void THISCALL f16_4e7240(u8 *self, float *pos, float *vel, float t) {
  float dt = t - AT(float, self, 0x28);
  float k = AT(float, self, 0xc);
  float *p0 = (float *)self, *p10 = (float *)(self + 0x10), *p1c = (float *)(self + 0x1c);
  if (k >= 0.001f) {
    float e = (float)((Exp)(void *)ext_634db8)((double)-(k * dt));
    ((VAdd4)(void *)ext_443ef0)(pos, p10, p1c, e);
    ((VAdd3)(void *)ext_451890)(pos, p0, dt);
    ((VAdd4)(void *)ext_443ef0)(vel, p0, p1c, -(e * AT(float, self, 0xc)));
  } else {
    ((VAdd4)(void *)ext_443ef0)(pos, p10, p1c, dt);
    ((VAdd3)(void *)ext_451890)(pos, p0, dt * dt);
    ((VAdd4)(void *)ext_443ef0)(vel, p1c, p0, dt + dt);
  }
}

extern "C" void THISCALL f16_443b40(u8 *self, u32 child) {
  do {
    u8 *arr = AT(u8 *, self, 0x7b);
    u32 n = AT(u16, arr, 2), i = 0;
    if (n)
      while (AT(u32, arr, 0x404 + 4 * i) != child && ++i != n) {
      }
    u16 left = (u16)(n - 1);
    AT(u16, arr, 2) = left;
    if (left) {
      u8 *a2 = AT(u8 *, self, 0x7b);
      AT(u32, a2, 0x404 + 4 * i) = AT(u32, a2, 0x404 + 4 * AT(u16, a2, 2));
    } else {
      u8 *a2 = AT(u8 *, self, 0x7b);
      if (AT(u16, a2, 0) == 0) {
        vcall<void>(G(void *, 0x6ff968), 0x20, a2);
        AT(u32, self, 0x7b) = 0;
        if (vcall<u32>(G(void *, 0x6ff968), 0x14) == 0) {
          if (G(void *, 0x6ff968)) vcall<void>(G(void *, 0x6ff968), 0, 1u);
          G(u32, 0x6ff968) = 0;
        }
      }
    }
    if (vcall<bool>(self, 0x310)) return;
    if (vcall<bool>(self, 0x30c)) return;
    if (!vcall<void *>(self, 0x20)) return;
    u8 *g = vcall<u8 *>(self, 0x20);
    self = ((u8 * (THISCALL *)(void *))(void *)ext_4db7e0)(AT(void *, g, 8));
  } while (self);
}

extern "C" int f16_630200(u8 *s) {
  ((void (*)(void *, void *, u32))(void *)ext_630dd0)(s, s + 0x8c, AT(u32, s, 0xb14));
  ((void (*)(void *, void *, u32))(void *)ext_630dd0)(s, s + 0x980, AT(u32, s, 0xb20));
  ((void (*)(void *, void *))(void *)ext_6302f0)(s, s + 0xb28);
  int max;
  for (max = 18; max >= 3; max--)
    if (AT(u16, s, 0xa76 + 4 * G(u8, 0x6c1070 + max))) break;
  AT(u32, s, 0x16a0) += 3 * max + 17;
  return max;
}

PCREG(4e7240, f16_4e7240);
PCREG(443b40, f16_443b40);
PCREG(630200, f16_630200);
