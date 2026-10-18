#include "ff.h"

extern "C" void THISCALL ext_4de7a0(void *vec);
extern "C" void THISCALL ext_4e89d0(void *self, void *out, float m, u32 cnt, u32 c, u32 b, u32 a);
extern "C" void THISCALL ext_4e87b0(void *self, void *out, float m, u32 cnt, u32 c, u32 b, u32 a);
extern "C" void FASTCALL ext_4df1e0(void *vec, void *p);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline float rdfu(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline float cf(u32 addr) { return *(const float *)addr; }

// 0x4e7930: thiscall(t, vec, out, x) ret 0x10 -> float in st0, /GS. `this` is a packed record {+0 s32 start, +4 float step, +8 u8 mode, +9 ptr P, +0xd float f0, +0x11 float f1}.
// P+off (off = P[8] when P[4]'s top two bits are non-zero, else 8) is a record of ints; the engine table slot 0x17c() offsets six of them. Computes a progress value s from t
// (scaled by 1024 and divided into the step), clamps it to the count-1 as float with minss, passes it to 0x4e89d0 / 0x4e87b0 (stack object at ebp-0x16, hooked) and 0x4df1e0(vec);
// returns f0 / -1.0 when the "reached f1" flag was set, otherwise s. P == 0: 0x4de7a0(vec), out[0..2] = 0, returns 0.0.
static float body_4e7930(u8 *self, s32 t, void *vec, u32 *out) {
  u8 local[0x20];
  u8 *P = (u8 *)rd32u(self + 9);
  if (!P) {
    ext_4de7a0(vec);
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    return 0.0f;
  }
  float f0 = rdfu(self + 0xd);
  float f1 = rdfu(self + 0x11);
  u32 flag = f0 > f1 ? 1 : 0;
  u32 top = rd32u(P + 4) & 0xc0000000u;
  u32 off = (top == 0x40000000u || top == 0x80000000u || top == 0xc0000000u) ? rd32u(P + 8) : 8;
  s32 ts = (s32)rdfu(self + 4);
  u32 cnt = rd32u(P + off);
  u8 flag2 = 0;
  s32 d = (s32)((u32)t - rd32u(self));
  if (d < 0) d = 0;
  s32 edi;
  if (flag) {
    float x = f0 * cf(0x678620);
    edi = (s32)x - (s32)((u32)d * (u32)ts);
  } else {
    edi = (s32)((u32)d * (u32)ts) - (s32)(f0 * cf(0x67862c));
  }
  u8 *eng = G(u8 *, 0x70039c);
  void *tbl = (void *)rd32u(eng + 0x9b);
  u32 k = vcall<u32>(tbl, 0x17c);
  u8 *base = P + off;
  u32 v38 = rd32u(base + 0x18) + k;
  u32 v40 = rd32u(base + 0x10) + k;
  u32 v3c = rd32u(base + 0x14) + k;
  u32 v28 = rd32u(base + 0x24) + k;
  u32 v30 = rd32u(base + 0x1c) + k;
  u32 v2c = rd32u(base + 0x20) + k;
  float xmm2;
  float xmm3 = 0.0f;
  float c1 = cf(0x678620);
  u8 mode = self[8];
  bool toB = true;
  if (mode == 0) {
    float x = (float)edi;
    float y = f1 * c1;
    if (!(x < y) && flag == 0) {
      flag2 = 1;
      toB = false;
    } else {
      float y2 = f1 * c1;
      float x2 = (float)edi;
      if (!(y2 < x2) && flag != 0) {
        flag2 = 1;
        toB = false;
      }
    }
  }
  if (toB) {
    xmm2 = f1;
    float f0b = f0;
    float diff = f1 - f0b;
    if (!(diff == 0.0f)) {
      s32 e2 = (s32)(f0b * c1);
      edi -= e2;
      s32 den = (s32)((u32)(s32)diff << 10);
      s32 rem = edi % den;
      xmm3 = (float)rem * cf(0x6785e4);
    }
    if (flag == 0) xmm2 = f0b;
    xmm2 = xmm2 + xmm3;
  } else {
    xmm2 = f1;  // value unused on this path before the subtraction below (set by the original's xmm2 register); see note
  }
  float cmax = (float)(double)(u32)(cnt - 1);
  float num = xmm2 - (float)(s32)rd32u(base + 4);
  float den2 = (float)(s32)rd32u(base + 0xc);
  float q = num / den2;
  float m = cmax < q ? cmax : q;
  ext_4e89d0(local + 2, out, m, cnt, v30, v2c, v28);
  ext_4e87b0(local + 2, local + 4, m, cnt, v40, v3c, v38);
  ext_4df1e0(vec, local + 4);
  if (flag2) {
    if (self[8]) return rdfu(self + 0xd);
    return cf(0x67af2c);
  }
  return m;
}
extern "C" float THISCALL fn_4e7930(u8 *self, s32 t, void *vec, u32 *out, u32 unused);
extern "C" float THISCALL fn_4e7930(u8 *self, s32 t, void *vec, u32 *out, u32 unused) {
  float r = body_4e7930(self, t, vec, out);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(4e7930, fn_4e7930);
