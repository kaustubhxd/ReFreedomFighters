// batch922.cpp - vehicles thread, batch 922: tank wheel dust and exhaust emitters, CUnderCarriageTank::FrameUpdate.
#include "ff.h"

extern "C" void THISCALL ext_517030(void *em, u32 a, u32 b);          // emitter set-up wrapper (908)
extern "C" void THISCALL ext_516f40(void *em, const float *d);         // ParticleEmitter::SetEmitDir (908)
extern "C" void THISCALL ext_5168b0(void *em);                         // ParticleEmitter::FrameUpdate
extern "C" void THISCALL ext_527bd0(void *uc);                         // DynamicsFrameUpdate (919)
extern "C" void THISCALL ext_529660(void *uc);                         // UpdateWheelsYPos (902)
extern "C" void THISCALL ext_5279f0(void *uc);                         // correct reversed dampers (920)
extern "C" void THISCALL ext_529130(void *uc);                         // probe ground (920)
extern "C" void THISCALL ext_529450(void *uc);                         // weight transfer (921)
extern "C" void THISCALL ext_529020(void *uc);                         // dampers follow anchors (921)
extern "C" void THISCALL ext_528b60(void *uc);                         // track speeds (921)
extern "C" void THISCALL ext_528ae0(void *uc);                         // track scroll (921)
extern "C" void THISCALL ext_5292c0(void *uc);  // wheel dust (this batch; called by address so specs can stand in)
extern "C" void THISCALL ext_5295d0(void *uc);  // exhaust (this batch)
extern "C" void FASTCALL ext_4de420(float *d, const float *s);         // mcpy
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);  // vangle
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);  // vcross

static const u32 ABS64[4] __attribute__((aligned(16))) = {0xffffffff, 0x7fffffff, 0xffffffff, 0x7fffffff};
#define F(p, o) (*(float *)((u8 *)(p) + (o)))
static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *world() { return *(void **)(sysp() + 0x9b); }

// 0x516250 (CDamper, unnamed): the dust particle definition of the ground under the wheel: ground geom +0xad (0 ->
// none), its material from the hit info +0xa5 (render manager +0x1c slot 0x74, +0x18 slot 0xf8), byte +2 of that
// -> world slot 0x160.
static u32 THISCALL damperGroundDust(u8 *d) {
  u32 id = *(u32 *)(d + 0xad);
  if (!id)
    return 0;
  vcall<u32>(world(), 0x58, id);
  u32 m = vcall<u32>(*(void **)(*(u8 **)(sysp() + 0x1aa3) + 0x1c), 0x74, d + 0xa5);
  u8 *p = vcall<u8 *>(*(void **)(*(u8 **)(sysp() + 0x1aa3) + 0x18), 0xf8, m);
  if (!p)
    return 0;
  return vcall<u32>(world(), 0x160, (u32)p[2]);
}
PCREG(516250, damperGroundDust);

// 0x52a070 (CWheel, unnamed): the wheel's two emitters (+0x3d, +0xb6) take particle sets +0x44 / +0x48 of `def`.
static void THISCALL wheelSetDust(u8 *w, u8 *def) {
  ext_517030(w + 0x3d, *(u32 *)(def + 0x44), 0x677b5a);
  ext_517030(w + 0xb6, *(u32 *)(def + 0x48), 0x677b5a);
}
PCREG(52a070, wheelSetDust);

// 0x5292c0 (CUnderCarriageTank, unnamed: wheel dust). 10% of frames the dust type follows the ground under the
// first right-row damper. Emission interval = 4 / |left track speed| when that is over 10 (else 0) on both emitters
// of every wheel; dust direction (0, 0.5, -1), or (0, 0.5, 1) when driving backward (sign * speed < 0).
static void THISCALL ucTankWheelDust(u8 *s) {
  float dir[3];
  dir[0] = 0;
  dir[1] = 0.5f;
  float v = F(s, 0x78) * F(s, 0x68);
  dir[2] = -1.0f;
  float ts = (float)_mm_cvtsd_f64(_mm_and_pd(_mm_set_sd((double)F(s, 0x7c)), _mm_load_pd((const double *)ABS64)));
  float rate = 0;
  typedef long double(THISCALL * rfn)(void *, const char *, u32);
  u8 *sy = sysp();
  volatile float r = (float)(*(rfn *)(*(u8 **)sy + 0x1c0))(sy, (const char *)0x6a0b90, 0x280);
  u8 *def = 0;
  if (0.1f >= r)
    def = (u8 *)damperGroundDust(s + 0x785);
  if (ts > 10.0f)
    rate = 4.0f / ts;
  if (0.0f > v)
    dir[2] = 1.0f;
  static const u32 row[2][2] = {{0x8d, 0xe75}, {0x91, 0x180d}};
  for (int k = 0; k < 2; k++)
    for (s32 i = 0; i < *(s32 *)(s + row[k][0]); i++) {
      u8 *w = s + row[k][1] + i * 0x133;
      if (def)
        wheelSetDust(w, def);
      F(w, 0x4d) = rate;
      F(w, 0xc6) = rate;
      ext_516f40(w + 0xb6, dir);
    }
}
PCREG(5292c0, ucTankWheelDust);

// 0x5295d0 (CUnderCarriageTank, unnamed: exhaust smoke): emission interval 0.05, or 5 / speed over speed 100, at
// least 0.005, and 0.005 once accelerating by more than 50; set on the +0x22c0 emitters at +0x21ce (stride 0x79),
// each updated.
static void THISCALL ucTankExhaust(u8 *s) {
  float x = 0.05000000074505806f;
  float sp = F(s, 0x68);
  if (sp > 100.0f)
    x = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(5.0f), _mm_set_ss(sp)));
  if (F(s, 0x6c) > 50.0f)
    x = 0.004999999888241291f;
  x = _mm_cvtss_f32(_mm_max_ss(_mm_set_ss(0.004999999888241291f), _mm_set_ss(x)));
  for (s32 i = 0; i < *(s32 *)(s + 0x22c0); i++) {
    u8 *e = s + 0x21ce + i * 0x79;
    F(e, 0x10) = x;
    ext_5168b0(e);
  }
}
PCREG(5295d0, ucTankExhaust);

// 0x527d10 CUnderCarriageTank::FrameUpdate(float* mat, float* pos, const float* spline, const float* dir, float
// speed, float accel, float sign), pops 28. Inactive (+0x84 byte clear): nothing. Frozen (+0x21cd): within the
// impact time (now < +0x85) the dampers keep simulating in place (dynamics, wheels, group TM, reversed check),
// after it the group's TM is read back. Otherwise the body follows the spline point (pos = spline, +0x64 =
// spline y + 50), direction (old one to +0x58, new flattened to +0x4c), speed +0x68, acceleration +0x6c, sign
// +0x78; turn angle +0x70 = signed angle between old and new direction, turn rate +0x74 = angle / frame time; then
// ground probe, weight, anchors, dynamics, wheels, tracks, track scroll, dust, exhaust, reversed check. The body
// matrix +0xc and position +0 are returned.
static void THISCALL ucTankFrameUpdate(u8 *s, float *mat, u32 *pos, const u32 *spl, const u32 *dir, float speed,
                                       float accel, float sign) {
  if (!s[0x84])
    return;
  if (s[0x21cd]) {
    if (*(s32 *)(sysp() + 0x40) >= *(s32 *)(s + 0x85)) {
      vcall<void>(*(void **)(s + 0x89), 0x80, mat, pos);
      return;
    }
    ext_527bd0(s);
    ext_529660(s);
    vcall<void>(*(void **)(s + 0x89), 0x7c, s + 0xc, s);
    ext_5279f0(s);
    ext_4de420(mat, (float *)(s + 0xc));
    pos[0] = ((u32 *)s)[0];
    pos[1] = ((u32 *)s)[1];
    pos[2] = ((u32 *)s)[2];
    return;
  }
  ((u32 *)s)[0] = spl[0];
  ((u32 *)s)[1] = spl[1];
  ((u32 *)s)[2] = spl[2];
  F(s, 0x64) = _mm_cvtss_f32(_mm_add_ss(_mm_set_ss(((float *)spl)[1]), _mm_set_ss(50.0f)));
  u32 *nd = (u32 *)(s + 0x4c), *od = (u32 *)(s + 0x58);
  od[0] = nd[0];
  od[1] = nd[1];
  od[2] = nd[2];
  nd[0] = dir[0];
  nd[1] = dir[1];
  nd[2] = dir[2];
  *(u32 *)(s + 0x50) = 0;
  F(s, 0x68) = speed;
  F(s, 0x6c) = accel;
  F(s, 0x78) = sign;
  F(s, 0x70) = ext_4e0030((float *)od, (float *)nd);
  float c[3];
  ext_446ee0(c, (float *)od, (float *)nd);
  if (0.0f > c[1])
    F(s, 0x70) = bitsf(fbits(F(s, 0x70)) ^ 0x80000000);
  F(s, 0x74) = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(F(s, 0x70)), _mm_set_ss(F(sysp(), 0x48))));
  ext_529130(s);
  ext_529450(s);
  ext_529020(s);
  ext_527bd0(s);
  ext_529660(s);
  ext_528b60(s);
  ext_528ae0(s);
  ext_5292c0(s);
  ext_5295d0(s);
  ext_5279f0(s);
  ext_4de420(mat, (float *)(s + 0xc));
  pos[0] = ((u32 *)s)[0];
  pos[1] = ((u32 *)s)[1];
  pos[2] = ((u32 *)s)[2];
}
PCREG(527d10, ucTankFrameUpdate);
