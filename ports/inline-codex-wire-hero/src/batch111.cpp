// batch111.cpp - going down into a sewer: lining the hero up with the lid (climb thread, batch 111).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);           // PSVECSubtract
extern "C" void THISCALL ext_4e09b0(float *v);                                             // vneg
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);        // createmat
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);  // out = a + b*s
extern "C" void FASTCALL ext_4de4b0(float *out, const float *a, const float *b);           // mmtmul
extern "C" void FASTCALL ext_4de4f0(float *m, const float *a);                             // matrix rows times a (in place)
extern "C" void THISCALL ext_595010(void *hero, u32 item);                                 // ZFFHERO::SetTempItem
extern "C" void THISCALL ext_59a6a0(void *osd, bool on);                                   // OSD flag (batch 109)
extern "C" void THISCALL ext_59a6b0(void *osd, float v);                                   // ZGameOSD::ProgressValue

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *engineDb() { return *(u8 **)(sys() + 0x9b); }
static inline float nowSec() { return (float)*(s32 *)(sys() + 0x40) * 0.0009765625f; }

// 0x59a6b0, ZGameOSD::ProgressValue(float) (GC map high). thiscall, ret 4: +0x22cf = the value clamped to [0, 1]
// (below 0 gives 0; minss with 1.0, so NaN passes through).
static void THISCALL progressValue(u8 *self, float v) {
  float r;
  if (0.0f > v)
    r = 0.0f;
  else
    r = 1.0f < v ? 1.0f : v;
  *(float *)(self + 0x22cf) = r;
}
PCREG(59a6b0, progressValue);

// 0x5e5600, ZFFHeroMovementOpenSewer::GotControl() (GC map high). thiscall. From the exe:
//  1. "opening" +0x54c = 1 and +0x54d = 0 (16-bit store), start time +0x54f; the hero's (+0x36d) slot 0x59c fills the
//     hero matrix (+0x573) and position (+0x55b); the position's y (+0x55f) is raised by 1.
//  2. lid = GeomRefToPtr(sewer (+0x557) + 4); its matrix and position go to +0x597 and +0x567 (slot 0x80).
//     v = lid position - hero position with y = 0, negated; the hero's target matrix +0x597 = createmat(v); v negated back
//     and normalised on the x87 stack (skipped when all zero). Target position y (+0x56b) = hero y.
//  3. Target position = lid position + v * -81.945 (0xc2a3e3d7): the hero stands about 82 units from the lid, facing it.
//  4. The lid's child (slot 0x20) is turned to face the hero: child matrix/pos (slot 0x80) m1/p1, then
//     m2 = createmat(-v), rel = mmtmul(m2, m1); child slot 0x7c(m2, p1); lid slot 0x80(m2, p1); m2 = rows of m2 times rel
//     (0x4de4f0); lid slot 0x7c(m2, p1). (Meaning inferred: the lid and its child keep their relative turn.)
//  5. Target y = hero y again; SetTempItem(1) (the hero holds a temporary item, guess: the crowbar); the display flag
//     goes on, ProgressValue(0), and hero+0x9e3 = now.
static void THISCALL openSewerGotControl(u8 *self) {
  float t = nowSec();
  void *hero = *(void **)(self + 0x36d);
  *(u16 *)(self + 0x54c) = 1;
  *(float *)(self + 0x54f) = t;
  vcall<void>(hero, 0x59c, (float *)(self + 0x573), (float *)(self + 0x55b));
  *(float *)(self + 0x55f) = *(float *)(self + 0x55f) + 1.0f;
  u8 *lid = vcall<u8 *>(engineDb(), 0x58, *(u32 *)(*(u8 **)(self + 0x557) + 4));
  vcall<void>(lid, 0x80, (float *)(self + 0x597), (float *)(self + 0x567));
  float v[3];
  ext_43e920(v, (float *)(self + 0x567), (float *)(self + 0x55b));
  v[1] = 0.0f;
  ext_4e09b0(v);
  ext_4de040((float *)(self + 0x597), v, 0);
  ext_4e09b0(v);
  if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)) {
    long double x = v[0], y = v[1], z = v[2];
    long double inv = 1.0L / fsqrt_x87(x * x + y * y + z * z);
    v[0] = (float)(v[0] * inv);
    v[1] = (float)(v[1] * inv);
    v[2] = (float)(v[2] * inv);
  }
  *(u32 *)(self + 0x56b) = *(u32 *)(self + 0x55f);
  ext_443ef0((float *)(self + 0x567), (float *)(self + 0x567), v, bitsf(0xc2a3e3d7u));
  float m1[9], p1[3], m2[9], rel[9];
  vcall<void>(vcall<void *>(lid, 0x20), 0x80, m1, p1);
  ext_4e09b0(v);
  ext_4de040(m2, v, 0);
  ext_4de4b0(rel, m2, m1);
  vcall<void>(vcall<void *>(lid, 0x20), 0x7c, m2, p1);
  vcall<void>(lid, 0x80, m2, p1);
  ext_4de4f0(m2, rel);
  vcall<void>(lid, 0x7c, m2, p1);
  *(u32 *)(self + 0x56b) = *(u32 *)(self + 0x55f);
  ext_595010(*(void **)(self + 0x36d), 1);
  ext_59a6a0(*(void **)(*(u8 **)(self + 0x36d) + 0x852), true);
  ext_59a6b0(*(void **)(*(u8 **)(self + 0x36d) + 0x852), 0.0f);
  *(float *)(*(u8 **)(self + 0x36d) + 0x9e3) = nowSec();
}
PCREG(5e5600, openSewerGotControl);
