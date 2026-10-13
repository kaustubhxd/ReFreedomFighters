// f16b029.cpp - fresh slice 16, batch 29 (2026-10-12).
// 0x44c740 Z2DOBJ::OwnerDraw(geom, flags, buf, cam, M, ofs, data): p = GetPos([this+8]) * M (vmmul); M[8] > 0.3f -> return;
//           p += ofs (PSVECAdd); billboard R (3x3): b+0x18 == 0 and -0.99f <= M[5] <= 0.99f (not NaN-checked: comiss) ->
//           R0 = {0, 0, 1}, R2 = vnorm(vcross(M row 1, R0)), R1 = vcross(R0, R2); else mreset(R). buf slot 0x30([this+8],
//           R, p, 0xff). All vector helpers run as exe code. Ret 0x1c. Cookie not reproduced.
// 0x409300 (cdecl a, n, tabp, m, level): b[i] = |a[i]| (x87 fabs: an SNaN comes out quiet), mx = largest b[i] (ordered >);
//           b[i] = floor(b[i] + 0.5) (CRT floor stubbed), sum = sum of b[i] (each step rounded to double then float, as
//           the x87 at 53-bit precision). Scan i = 0 .. m-2 over table t = *tabp + 0x514: level < t[0xc0+i] and sum <=
//           t[i] (or unordered) and mx <= t[0x40+i] (or unordered) -> stop. Returns i. (A codebook/quantiser pick: GUESS.)
// 0x44b980 ZSNDOBJ::CalcCenSize(): static sounds (no flag +0x14 bit 0): SetCen(0, 0, 0), 0x4dd060(&{0,0,0}) (size), SetRadius
//           (0). Else r = [[0x70039c]+0x1a9f] ? 2 * f([+0x18]+0x54) : 200; SetRadius(r); 0x4dd060(&{r,r,r}); SetCen(&{0,0,0}).
//           Cookie not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4db500[], ext_4419f0[], ext_441940[], ext_446ee0[], ext_44c840[], ext_4de7a0[], ext_634dca[],
    ext_4dc5d0[], ext_4dd060[], ext_4dce50[], ext_4dc600[];

typedef void(FASTCALL *V2)(float *, const float *);
typedef void(FASTCALL *V3)(float *, const float *, const float *);
typedef float(FASTCALL *VN)(float *);
typedef void(FASTCALL *V1)(float *);

extern "C" void THISCALL f16_44c740(u8 *self, u32 geom, u32 flags, void *buf, u32 cam, float *M, float *ofs, u32 data) {
  (void)geom, (void)flags, (void)cam, (void)data;
  volatile float p[3] = {0, 0, 0};
  volatile float R[9];
  ((void(THISCALL *)(void *, volatile float *))(void *)ext_4db500)(AT(void *, self, 8), p);
  ((V2)(void *)ext_4419f0)((float *)p, M);
  if (M[8] > 0.3f) return;
  ((V2)(void *)ext_441940)((float *)p, ofs);
  if (AT(u8, self, 0x18) == 0 && !(M[5] > 0.99f) && !(-0.99f > M[5])) {
    R[0] = 0;
    R[1] = 0;
    R[2] = 1.0f;
    ((V3)(void *)ext_446ee0)((float *)R + 6, M + 3, (float *)R);
    (void)((VN)(void *)ext_44c840)((float *)R + 6);
    ((V3)(void *)ext_446ee0)((float *)R + 3, (float *)R, (float *)R + 6);
  } else {
    ((V1)(void *)ext_4de7a0)((float *)R);
  }
  vcall<void>(buf, 0x30, AT(u32, self, 8), (float *)R, (float *)p, 0xffu);
}

typedef double (*Floor)(double);

extern "C" int f16_409300(float *a, int n, u8 **tabp, int m, int level) {
  u8 *tab = *tabp;
  float b[128];
  float mx = 0, sum = 0;
  if (n > 0) {
    for (int i = 0; i < n; i++) b[i] = (float)__builtin_fabs((double)a[i]);
    for (int i = 0; i < n; i++)
      if (b[i] > mx) mx = b[i];
    for (int i = 0; i < n; i++) b[i] = (float)((Floor)(void *)ext_634dca)((double)b[i] + (double)0.5f);
    for (int i = 0; i < n; i++) sum = (float)((double)sum + (double)b[i]);
  }
  int i = 0;
  float *t = (float *)(tab + 0x514);
  for (; i < m - 1; i++, t++) {
    if (level >= *(int *)(t + 0xc0)) continue;
    if (sum > t[0]) continue;
    if (!(mx > t[0x40])) break;
  }
  return i;
}

typedef void(THISCALL *SetF)(void *, float);
typedef void(THISCALL *SetP)(void *, volatile float *);

extern "C" void THISCALL f16_44b980(u8 *self) {
  if (!(AT(u8, self, 0x14) & 1)) {
    ((void(THISCALL *)(void *, float, float, float))(void *)ext_4dc5d0)(AT(void *, self, 8), 0.0f, 0.0f, 0.0f);
    volatile float z[3] = {0, 0, 0};
    ((SetP)(void *)ext_4dd060)(AT(void *, self, 8), z);
    ((SetF)(void *)ext_4dce50)(AT(void *, self, 8), 0.0f);
    return;
  }
  float r = AT(u32, G(u8 *, 0x70039c), 0x1a9f) ? AT(float, AT(u8 *, self, 0x18), 0x54) + AT(float, AT(u8 *, self, 0x18), 0x54)
                                               : 200.0f;
  ((SetF)(void *)ext_4dce50)(AT(void *, self, 8), r);
  volatile float v[3];
  v[0] = r;
  v[1] = r;
  v[2] = r;
  ((SetP)(void *)ext_4dd060)(AT(void *, self, 8), v);
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
  ((SetP)(void *)ext_4dc600)(AT(void *, self, 8), v);
}

PCREG(44c740, f16_44c740);
PCREG(409300, f16_409300);
PCREG(44b980, f16_44b980);
