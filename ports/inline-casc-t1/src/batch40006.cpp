// batch40006.cpp - cascade t1 (Sonnet), tier H: 0x5c78e0, 0x5138f0, 0x4a5f20, 0x523470, 0x40cc20.
#include "ff.h"

extern "C" u32 THISCALL ext_43ec00(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // thiscall ret 0x18
extern "C" float THISCALL ext_4e7930(u8 *self, s32 a, float *m, float *v, float c);       // thiscall ret 0x10, float on st0
extern "C" void FASTCALL ext_4419f0(void *ecx, void *edx);                                // fastcall, plain ret
extern "C" void FASTCALL ext_4de420(void *ecx, void *edx);                                // fastcall, plain ret
extern "C" void FASTCALL ext_4de480(void *ecx, void *edx);                                // fastcall, plain ret
extern "C" void FASTCALL ext_441940(void *ecx, void *edx);                                // fastcall, plain ret
extern "C" void THISCALL ext_460af0(u8 *self, u32 a, u32 b, u32 c);                       // thiscall ret 0xc
extern "C" void THISCALL ext_4e0d00(u8 *self, float f);                                   // thiscall ret 4
extern "C" float THISCALL ext_44c840(u8 *self);                                           // thiscall, float on st0 (discarded)
extern "C" u32 ext_405800(u8 *obj, u8 *p, u32 one);                                       // cdecl

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static u8 *sysobj() { return G(u8 *, 0x70039c); }
static u8 *engTable() { return (u8 *)rd32(sysobj() + 0x9b); }
static float i2f(s32 v) { return _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(v))); }
static s32 f2i(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

// 0x5c78e0, thiscall(p) ret 4: [p+0x24] = (float)([sys+0x40] - (int)(unaligned float [this+0x6d] * K(0x67862c))) * K(0x6785e4); when unaligned [sys+0x1a9f] and [this+0x4c] are set and [p+0x20] == 0:
// o = engine table slot 0x58([p]); o set -> d = [o+8]; r = o->slot 0x20(); [p+0x20] = ext_43ec00(r, d, d + 0x24, [this+0x4c], 0, 0, 0).
static void THISCALL fn5c78e0(u8 *self, u8 *p) {
  s32 t = *(s32 *)(sysobj() + 0x40);
  float f = bitsf(rd32(self + 0x6d)) * G(float, 0x67862c);
  *(float *)(p + 0x24) = i2f(t - f2i(f)) * G(float, 0x6785e4);
  if (rd32(sysobj() + 0x1a9f) == 0) return;
  if (*(u32 *)(self + 0x4c) == 0) return;
  if (*(u32 *)(p + 0x20) != 0) return;
  u8 *o = vcall<u8 *>(engTable(), 0x58, *(u32 *)p);
  if (!o) return;
  u8 *d = *(u8 **)(o + 8);
  u8 *r = vcall<u8 *>(o, 0x20);
  *(u32 *)(p + 0x20) = ext_43ec00(r, (u32)d, (u32)(d + 0x24), *(u32 *)(self + 0x4c), 0, 0, 0);
}
PCREG(5c78e0, fn5c78e0);

// 0x5138f0, thiscall(a) ret 4: [this] = a; o = engine table slot 0x58(a); [this+4] = o; [this+8] = o when o and (u8) o->slot 0x1e0(0x200074), else 0; t = [sys+0x40]; fa = float [this+0x30], fb = float [this+0x34];
// float [this+0xc] = (float)(t - (int)(fa * K(0x67862c))) * K(0x6785e4); float [this+0x10] = (float)((int)(fa * K(0x678620)) - (int)(fb * K(0x67862c)) + t) * K(0x6785e4).
static void THISCALL fn5138f0(u8 *self, u32 a) {
  *(u32 *)self = a;
  u8 *o = vcall<u8 *>(engTable(), 0x58, a);
  *(u8 **)(self + 4) = o;
  if (o && vcall<u8>(o, 0x1e0, (u32)0x200074)) *(u8 **)(self + 8) = *(u8 **)(self + 4);
  else *(u32 *)(self + 8) = 0;
  float fa = *(float *)(self + 0x30);
  s32 t = *(s32 *)(sysobj() + 0x40);
  s32 c1 = f2i(fa * G(float, 0x67862c));
  s32 c2 = f2i(fa * G(float, 0x678620));
  float v1 = i2f(t - c1) * G(float, 0x6785e4);
  *(float *)(self + 0xc) = v1;
  float fb = *(float *)(self + 0x34);
  s32 c3 = f2i(fb * G(float, 0x67862c));
  s32 v = c2 - c3 + *(s32 *)(sysobj() + 0x40);
  *(float *)(self + 0x10) = i2f(v) * G(float, 0x6785e4);
}
PCREG(5138f0, fn5138f0);

// 0x4a5f20, thiscall(float f) ret 4, returns float: r = ext_4e7930(this+0x48, (int)(f * K(0x678620)), m58, v10, float [this+0xc0]); ext_4419f0(v10, this+0x93); ext_4de420(m34, this+0x6b);
// ext_4de480(m34, m58); ext_441940(v10, this+0x5f); [this+0x44]->slot 0x74(m34, v10); returns r. (m = 9 floats, v = 3 floats on the stack)
static float THISCALL fn4a5f20(u8 *self, float f) {
  float m58[9], v10[3], m34[9];
  float r = ext_4e7930(self + 0x48, f2i(f * G(float, 0x678620)), m58, v10, *(float *)(self + 0xc0));
  ext_4419f0(v10, self + 0x93);
  ext_4de420(m34, self + 0x6b);
  ext_4de480(m34, m58);
  ext_441940(v10, self + 0x5f);
  vcall<void>(*(u8 **)(self + 0x44), 0x74, (u32)m34, (u32)v10);
  return r;
}
PCREG(4a5f20, fn4a5f20);

// 0x523470, thiscall(a, b, c) ret 0xc, c a float: t = c < 0 ? 0 : min(K(0x678858), c) (minss: NaN c stays NaN); e = unaligned [this+0x4b]; e == 0 -> 3 dwords at a and 3 dwords at b zeroed;
// else ext_460af0(e+0x1c, a, b, t); e->slot 0x84(a); e->slot 0x88(b) (e re-read each time); ext_4e0d00(b, float [this+0x20]); ext_44c840(b) (float result dropped).
static void THISCALL fn523470(u8 *self, u8 *a, u8 *b, float c) {
  float t;
  if (0.0f > c) t = 0.0f;
  else {
    float k = G(float, 0x678858);
    t = k < c ? k : c;
  }
  u8 *e = (u8 *)rd32(self + 0x4b);
  if (!e) {
    for (int i = 0; i < 12; i++) a[i] = 0;
    for (int i = 0; i < 12; i++) b[i] = 0;
    return;
  }
  ext_460af0(e + 0x1c, (u32)a, (u32)b, fbits(t));
  e = (u8 *)rd32(self + 0x4b);
  vcall<void>(e, 0x84, (u32)a);
  e = (u8 *)rd32(self + 0x4b);
  vcall<void>(e, 0x88, (u32)b);
  ext_4e0d00(b, *(float *)(self + 0x20));
  (void)ext_44c840(b);
}
PCREG(523470, fn523470);

// 0x40cc20, cdecl(obj, src, dst, idx): n = [obj]; prev = idx ? dst[idx-1] : 0; for k < n: dst[idx+k] = (float)((double)src[idx+k] - (double)prev) (x87); r = ext_405800(obj, dst + idx, 1);
// copies n dwords from [obj+0xc] + r*n*4 to dst + idx; for k < n: dst[idx+k] = (float)((double)prev + (double)dst[idx+k]).
static void fn40cc20(u8 *obj, float *src, float *dst, u32 idx) {
  s32 n = *(s32 *)obj;
  float prev = 0.0f;
  float *p = dst + idx;
  if (idx) prev = p[-1];
  for (s32 k = 0; k < n; k++) p[k] = (float)((double)src[idx + k] - (double)prev);
  u32 r = ext_405800(obj, (u8 *)p, 1);
  u32 *s = (u32 *)(*(u8 **)(obj + 0xc) + r * n * 4);
  for (s32 k = 0; k < n; k++) ((u32 *)p)[k] = s[k];
  for (s32 k = 0; k < n; k++) p[k] = (float)((double)prev + (double)p[k]);
}
PCREG(40cc20, fn40cc20);
