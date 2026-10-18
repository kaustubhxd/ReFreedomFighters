#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *out, void *a, void *b);
extern "C" void FASTCALL ext_443ef0(void *ecx, void *edx, void *b, u32 fbits);
extern "C" void FASTCALL ext_446ee0(void *ecx, void *edx, void *b);
extern "C" void FASTCALL ext_451890(void *ecx, void *edx, u32 fbits);
extern "C" float THISCALL ext_4af0d0(void *shape);
extern "C" void FASTCALL ext_633654(u32 cookie);

#define EBP (fr + 0x80)
#define P(off) (EBP - (off))
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float cf(u32 addr) { return *(const float *)addr; }

typedef float(THISCALL *VF2)(void *, u32, u32);
typedef u32(THISCALL *V3)(void *, void *, void *, void *);
typedef void(THISCALL *V2)(void *, void *, void *);

// 0x4ae5a0: thiscall(a, b) ret 8 -> bool, /GS. Two bodies a, b (positions at +0 / +4 / +8, velocity at +0xc / +0x10 / +0x14, shape pointer at +0x30 with the radius at shape+0x624
// and a "rigid" flag at shape+0x726): false when |dy| of (b - a) exceeds 200 or the squared xz distance exceeds (r_a + r_b - [0x67a284])^2. Otherwise both bodies are pushed out
// of each other along the xz difference of their positions to the midpoint (weights 1 / 1, 2 / 0 or 0 / 2 chosen by the rigid flags and the 0x4af0d0 priority of the shapes):
// normalised direction (x87, long double with the 53-bit control word), penetration = radius - length, new position via 0x443ef0, reflection / bounce (0x446ee0, 0x451890),
// this slot 0x84 accepts the move, shape slot 0x578 gets the velocity and the shape radius shrinks by dt * [0x67da24]; both bodies get byte +0x34 = 1; returns true.
// The locals keep the original frame layout (the real helpers write them): ebp = fr + 0x80.
static bool body_4ae5a0(u8 *self, u8 *a, u8 *b) {
  u8 fr[0xa0];
  __builtin_memset(fr, 0xcc, sizeof fr);
  W32(P(0x3c), (u32)self);
  W32(P(0x40), (u32)a);
  W32(P(0x30), (u32)b);
  ext_43e920(P(0x4c), b, a);
  double dyabs = (double)RF(P(0x48));
  if (dyabs < 0) dyabs = -dyabs;
  if (dyabs > *(double *)0x690de0) return false;
  WF(P(0x48), 0.0f);
  u8 *s1 = (u8 *)R32(a + 0x30);
  u8 *s2 = (u8 *)R32(b + 0x30);
  float x = RF(P(0x4c)), z = RF(P(0x44));
  float rr = RF(s1 + 0x624) + RF(s2 + 0x624);
  rr = rr - cf(0x67a284);
  float d2 = x * x + 0.0f;
  d2 = d2 + z * z;
  rr = rr * rr;
  if (d2 > rr) return false;
  float f = cf(0x67a6ac);
  W32(P(0x54), (u32)a);
  W32(P(0x50), (u32)b);
  W32(P(0x38), (u32)s1);
  W32(P(0x34), (u32)s2);
  WF(P(0x1c), 1.0f);
  WF(P(0x18), 1.0f);
  WF(P(0x60), (RF(b) - RF(a)) * f + RF(a));
  WF(P(0x5c), (RF(b + 4) - RF(a + 4)) * f + RF(a + 4));
  WF(P(0x58), (RF(b + 8) - RF(a + 8)) * f + RF(a + 8));
  if (s1[0x726]) {
    if (!s2[0x726]) {
      WF(P(0x1c), 2.0f);
      WF(P(0x18), 0.0f);
    }
  } else if (s2[0x726]) {
    WF(P(0x1c), 0.0f);
    WF(P(0x18), 2.0f);
  } else {
    float r1 = ext_4af0d0(s1);
    WF(P(0x14), r1);
    float r2 = ext_4af0d0(s2);
    WF(P(0x20), r2);
    float v1 = RF(P(0x14)), v2 = RF(P(0x20));
    if (v1 > v2) {
      WF(P(0x1c), 2.0f);
      WF(P(0x18), 0.0f);
    } else if (v2 > v1) {
      WF(P(0x1c), 0.0f);
      WF(P(0x18), 2.0f);
    }
  }
  for (int i = 0; i < 2; i++) {
    float w = RF(P(0x1c) + 4 * i);
    if (w == 0.0f) continue;
    u8 *body = (u8 *)R32(P(0x54) + 4 * i);
    ext_43e920(P(0x2c), body, P(0x60));
    float vx = RF(P(0x2c)), vz = RF(P(0x24));
    W32(P(0x28), 0);
    float sum = vx * vx + 0.0f;
    sum = sum + vz * vz;
    if (!(sum == 0.0f)) {
    } else {
      u8 *E = G(u8 *, 0x70039c);
      float g1 = (*(VF2 *)(*(u8 **)E + 0x1c4))(E, 0x690d54, 0x166);
      WF(P(0x20), g1);
      float g2 = (*(VF2 *)(*(u8 **)E + 0x1c4))(E, 0x690d54, 0x166);
      vx = RF(P(0x20));
      WF(P(0x2c), vx);
      WF(P(0x14), g2);
      vz = RF(P(0x14));
      WF(P(0x24), vz);
      W32(P(0x28), 0);
      float sum2 = vx * vx + 0.0f;
      sum2 = sum2 + vz * vz;
      if (sum2 == 0.0f) {
        vx = cf(0x678858);
        vz = 0.0f;
        WF(P(0x2c), vx);
        W32(P(0x28), 0);
        WF(P(0x24), vz);
      }
    }
    float len;
    if (vx == 0.0f && vz == 0.0f) {
      len = 0.0f;
    } else {
      u8 *c = P(0x2c);
      long double xx = (long double)RF(c) * (long double)RF(c);
      long double yy = (long double)RF(c + 4) * (long double)RF(c + 4);
      long double s = xx + yy;
      long double zz = (long double)RF(c + 8) * (long double)RF(c + 8);
      s = s + zz;
      long double l = fsqrt_x87(s);
      long double inv = (long double)1.0f / l;
      WF(c, (float)((long double)RF(c) * inv));
      WF(c + 4, (float)((long double)RF(c + 4) * inv));
      WF(c + 8, (float)((long double)RF(c + 8) * inv));
      len = (float)l;
    }
    u8 *sh = (u8 *)R32(P(0x38) + 4 * i);
    float rad = RF(sh + 0x624);
    if (len > rad) continue;
    float pen = rad - len;
    ext_443ef0(P(0x10), body, P(0x2c), fbits(pen));
    WF(P(0x14), pen);
    float v0 = RF(body + 0xc);
    WF(P(0x6c), v0);
    float v1 = RF(body + 0x10);
    WF(P(0x68), v1);
    float v2 = RF(body + 0x14);
    WF(P(0x64), v2);
    float dot = v0 * RF(P(0x2c));
    float t1 = v1 * RF(P(0x28));
    float t2 = v2 * RF(P(0x24));
    dot = dot + t1;
    dot = dot + t2;
    if (dot > 0.0f) {
      ext_446ee0(P(0x78), P(0x2c), P(0x6c));
      float m = pen;
      if (RF(P(0x74)) > 0.0f)
        m = m * cf(0x690de8);
      else
        m = m * cf(0x67c198);
      m = m * w;
      ext_451890(P(0x10), body + 0x24, fbits(m));
    }
    u8 *tvt = (u8 *)R32(P(0x3c));
    u32 ok = ((V3)(*(u32 *)(*(u8 **)tvt + 0x84)))(tvt, sh, body, P(0x10)) & 0xff;
    if (!ok) continue;
    u8 *shp = sh;
    (*(V2 *)(*(u8 **)shp + 0x578))(shp, body + 0xc, P(0x10));
    u8 *E = G(u8 *, 0x70039c);
    float dt = RF(E + 0x48) * cf(0x67da24);
    float nr = RF(sh + 0x624) - dt;
    float mx = 0.0f > nr ? 0.0f : nr;
    WF(sh + 0x624, mx);
    WF(body, RF(P(0x10)));
    WF(body + 4, RF(P(0xc)));
    WF(body + 8, RF(P(8)));
  }
  *(u8 *)(R32(P(0x40)) + 0x34) = 1;
  *(u8 *)(R32(P(0x30)) + 0x34) = 1;
  return true;
}
extern "C" u32 THISCALL fn_4ae5a0(u8 *self, u8 *a, u8 *b);
extern "C" u32 THISCALL fn_4ae5a0(u8 *self, u8 *a, u8 *b) {
  bool r = body_4ae5a0(self, a, b);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(4ae5a0, fn_4ae5a0);
