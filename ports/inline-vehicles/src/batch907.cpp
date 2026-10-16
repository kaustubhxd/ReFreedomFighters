// batch907.cpp - vehicles thread, batch 907: helicopter ground probe, SetPosDir, SplineUpdate, and the
// CMoveAlongPath direction helpers they use.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);  // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b (x87)
extern "C" void THISCALL ext_460af0(void *shape, float *pos, float *vel, float t);  // BasicShape::GetSplinePosVelocity
extern "C" void THISCALL ext_460b60(void *shape, float *vel, float t);              // BasicShape::GetSplineVelocity
extern "C" void THISCALL ext_4e0d00(float *v, float k);                              // vscalar: v *= k
extern "C" float THISCALL ext_44c840(float *v);                                      // vnorm (length in st0)
extern "C" void THISCALL ext_51db60(void *heli);                                     // ZHeli::UpdateDustEmitter

static inline void *world() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x51c470 ZHeli::FindGround(): a world line query (engine +0x9b, +0xadc object, slot 0x2e0) straight down
// 1500 from the heli position (+0x60); ray block at +0x526 (dir +0x532 = (0, -1500, 0), +0x55a = 1.0, byte +0x592
// cleared). Hit: height above ground +0x597 = y - hit y (+0x552), at least 0, result 1. Miss: +0x597 = 1500, 0.
typedef u8(THISCALL *lineQ)(void *, void *, u32, u32, u32, u32, u32);
static u8 THISCALL heliFindGround(u8 *s) {
  u8 *ray = s + 0x526;
  *(u32 *)(s + 0x55a) = 0x3f800000;
  s[0x592] = 0;
  ((u32 *)ray)[0] = *(u32 *)(s + 0x60);
  ((u32 *)ray)[1] = *(u32 *)(s + 0x64);
  ((u32 *)ray)[2] = *(u32 *)(s + 0x68);
  *(u32 *)(s + 0x532) = 0;
  *(u32 *)(s + 0x536) = 0xc4bb8000;
  *(u32 *)(s + 0x53a) = 0;
  u8 *q = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
  if ((*(lineQ *)(*(u8 **)q + 0x2e0))(q, ray, 0, 0x20, 0x200000, 1, 0)) {
    float d = _mm_cvtss_f32(_mm_sub_ss(_mm_load_ss((float *)(s + 0x64)), _mm_load_ss((float *)(s + 0x552))));
    *(float *)(s + 0x597) = d;
    if (0.0f > d)
      *(u32 *)(s + 0x597) = 0;
    return 1;
  }
  *(u32 *)(s + 0x597) = 0x44bb8000;
  return 0;
}
PCREG(51c470, heliFindGround);

// 0x51c540 ZHeli::GetDistToGround(): FindGround, then +0x597 in st0.
static float THISCALL heliGetDistToGround(u8 *s) {
  heliFindGround(s);
  return *(float *)(s + 0x597);
}
PCREG(51c540, heliGetDistToGround);

// 0x51c550 ZHeli::GetVerticalVisionOffset(): -500 (0x69f9e8).
static float THISCALL heliGetVerticalVisionOffset(u8 *s) { return -500.0f; }
PCREG(51c550, heliGetVerticalVisionOffset);

// 0x51cf10 ZHeli::SetPosDir(): slot 0x36c (update the matrix), then the offset +0x276 through slot 0x88 (local
// direction to world) with its y clamped to [0, 1e38], added to the position +0x60, and slot 0x7c(mat +0x6c, pos).
static void THISCALL heliSetPosDir(u8 *s) {
  vcall<void>(s, 0x36c);
  float t[3], p[3];
  t[0] = *(float *)(s + 0x276);
  t[1] = *(float *)(s + 0x27a);
  t[2] = *(float *)(s + 0x27e);
  vcall<void>(s, 0x88, t);
  float y = t[1];
  t[1] = 0.0f > y ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(bitsf(0x7e967699)), _mm_set_ss(y)));
  ext_43e8e0(p, (float *)(s + 0x60), t);
  vcall<void>(s, 0x7c, s + 0x6c, p);
}
PCREG(51cf10, heliSetPosDir);

// 0x4e0830 vdist2(const float*, const float*): squared distance (SSE sum x*x + y*y then + z*z), float in st0.
static float FASTCALL vdist2(const float *a, const float *b) {
  float d[3];
  ext_43e920(d, a, b);
  return _mm_cvtss_f32(_mm_add_ss(_mm_add_ss(_mm_mul_ss(_mm_set_ss(d[0]), _mm_set_ss(d[0])),
                                             _mm_mul_ss(_mm_set_ss(d[1]), _mm_set_ss(d[1]))),
                                  _mm_mul_ss(_mm_set_ss(d[2]), _mm_set_ss(d[2]))));
}
PCREG(4e0830, vdist2);

static inline float clamp01(float x) {
  return 0.0f > x ? 0.0f : _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(1.0f), _mm_set_ss(x)));
}

// 0x523520 CMoveAlongPath direction around a spline value (name not in the GC map; GetDirAround by inference),
// thiscall(out, t, dist), callee pops 12. Without a shape (+0x4b): (1, 0, 0). Otherwise the spline points at
// t -/+ dist / length(+0x53) * scale(+0x20), clamped to [0, 1]; out = the chord between them, or the spline velocity
// at the lower point when the two are closer than 2^-13 (squared); then the shape's slot 0x88 (to world).
static void THISCALL pathDirAround(u8 *p, float *out, float t, float dist) {
  u8 *sh = *(u8 **)(p + 0x4b);
  if (!sh) {
    *(u32 *)out = 0x3f800000;
    *(u32 *)(out + 1) = 0;
    *(u32 *)(out + 2) = 0;
    return;
  }
  float a[3], va[3], b[3], vb[3];
  float k = dist / *(float *)(p + 0x53) * *(float *)(p + 0x20);
  ext_460af0(sh + 0x1c, a, va, clamp01(t - k));
  float k2 = dist / *(float *)(p + 0x53) * *(float *)(p + 0x20) + t;
  ext_460af0(*(u8 **)(p + 0x4b) + 0x1c, b, vb, clamp01(k2));
  volatile float d2 = vdist2(a, b);
  if (0.0001220703125f > d2) {
    out[0] = va[0];
    out[1] = va[1];
    out[2] = va[2];
  } else {
    ext_43e920(out, b, a);
  }
  vcall<void>(*(void **)(p + 0x4b), 0x88, out);
}
PCREG(523520, pathDirAround);

// 0x523330 CMoveAlongPath::GetDir(float[3]&): spline velocity at the current value (+4), to world (shape slot
// 0x88), scaled by the direction sign/scale +0x20, normalised. Without a shape: (0, 0, 1).
static void THISCALL pathGetDir(u8 *p, float *out) {
  u8 *sh = *(u8 **)(p + 0x4b);
  if (!sh) {
    *(u32 *)out = 0;
    *(u32 *)(out + 1) = 0;
    *(u32 *)(out + 2) = 0x3f800000;
    return;
  }
  ext_460b60(sh + 0x1c, out, *(float *)(p + 4));
  vcall<void>(*(void **)(p + 0x4b), 0x88, out);
  ext_4e0d00(out, *(float *)(p + 0x20));
  ext_44c840(out);
}
PCREG(523330, pathGetDir);

// 0x51d000 ZHeli::SplineUpdate(): copies the path position (path +0x5c: +8..+0x10) to +0x24a, the direction around
// the current value (path slot 0xc) over 500 units to +0x256, sets the jet pitch from the path speed (path +0x24 *
// +0x4a9 + +0x4a5, on the jet sound node of +0x499), looks up geom +0x123 (result unused), then the update slots
// 0x390, 0x374, 0x364, UpdateDustEmitter and SetPosDir.
static void THISCALL heliSplineUpdate(u8 *s) {
  u8 *p = *(u8 **)(s + 0x5c);
  *(u32 *)(s + 0x24a) = *(u32 *)(p + 8);
  *(u32 *)(s + 0x24e) = *(u32 *)(p + 0xc);
  *(u32 *)(s + 0x252) = *(u32 *)(p + 0x10);
  float t = vcall<float>(p, 0xc);
  pathDirAround(*(u8 **)(s + 0x5c), (float *)(s + 0x256), t, 500.0f);
  u32 h = *(u32 *)(s + 0x499);
  if (h) {
    u8 *n = vcall<u8 *>(world(), 0x60, h);
    if (n) {
      s32 v = _mm_cvttss_si32(_mm_mul_ss(_mm_load_ss((float *)(*(u8 **)(s + 0x5c) + 0x24)),
                                         _mm_load_ss((float *)(s + 0x4a9)))) + *(s32 *)(s + 0x4a5);
      *(s32 *)(n + 0x60) = v - *(s32 *)(n + 0x64);
      *(s32 *)(n + 0x64) = v;
    }
  }
  vcall<u32>(world(), 0x58, *(u32 *)(s + 0x123));
  vcall<void>(s, 0x390);
  vcall<void>(s, 0x374);
  vcall<void>(s, 0x364);
  ext_51db60(s);
  heliSetPosDir(s);
}
PCREG(51d000, heliSplineUpdate);
