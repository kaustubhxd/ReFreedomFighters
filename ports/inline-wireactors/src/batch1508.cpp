// batch1508.cpp - recruits thread, batch 1508: ZFFHERO follower set-up and the "hero push" (a follower in the
// hero's way is told to step aside).
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef float(THISCALL *vcallRandF)(void *self, const char *file, u32 line);

extern "C" void THISCALL ext_4de7a0(float *m);   // mreset (identity 3x4)

// 0x592850 ZFFHERO::InitializeFollowers(), thiscall, plain ret.
// Appends 17 formation slots of 0x15 bytes at +0xd4e (count +0xd4a): 16 zero bytes, a byte the original never sets
// (its stack contents; the port writes 0xcc, the checker's stack fill), float 1.0 at +0x11. Then: hero position
// (own slot 0x84) into +0xeb3, +0xebf..+0xec7 = 0, +0xecb = the level object named "rEnemyPathFinder3", and the
// follow parameters +0xed3 = 170.0, +0xed7 = 1.0, +0xedb = 550.0, +0xedf = 0. The identity matrix it builds is
// unused. Stack cookie not ported.
#pragma pack(push, 1)
struct FormSlot {
  u32 z[4];
  u8 flag;
  float w;
};
#pragma pack(pop)
static void THISCALL heroInitializeFollowers(u8 *self) {
  float m[12];
  ext_4de7a0(m);
  for (int k = 0; k < 17; ++k) {
    FormSlot s;
    s.z[0] = s.z[1] = s.z[2] = s.z[3] = 0;
    s.flag = 0xcc;   // indeterminate in the original
    s.w = 1.0f;
    __builtin_memcpy(self + 0xd4e + *(u32 *)(self + 0xd4a) * 0x15, &s, 0x15);
    ++*(u32 *)(self + 0xd4a);
  }
  float *hp = (float *)(self + 0xeb3);
  ((u32 *)hp)[2] = 0;
  ((u32 *)hp)[1] = 0;
  ((u32 *)hp)[0] = 0;
  vcall<void>(self, 0x84, hp);
  *(u32 *)(self + 0xec7) = 0;
  *(u32 *)(self + 0xec3) = 0;
  *(u32 *)(self + 0xebf) = 0;
  void *names = vcall<void *>(objTable(), 0x138);
  u32 id = 0;
  vcall<void>(names, 0x88, (const char *)0x68a9e0, &id);
  *(u32 *)(self + 0xecb) = vcall<u32>(objTable(), 0x58, id);
  *(u32 *)(self + 0xed3) = 0x432a0000u;   // 170.0
  *(u32 *)(self + 0xed7) = 0x3f800000u;   // 1.0
  *(u32 *)(self + 0xedb) = 0x44098000u;   // 550.0
  *(u32 *)(self + 0xedf) = 0;
}
PCREG(592850, heroInitializeFollowers);

extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);           // vdist2, ST0
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract: dst = a - b

// 0x5941d0 ZFFHERO::PushFollower(ZFFActor* a, float* heroDir, float* followerPos, float* unused, float* heroPos,
// float* heroMat, float heroRadius), thiscall, ret 0x1c, AL = pushed.
// When the follower is inside (heroRadius / 2 + 75) of the hero and in front of it (flattened direction from hero
// to follower, d, against the matrix's first row: m0 . d < 0), it is sent "HeroPush" with a side 0..3:
//   - roughly head-on (m0 . d < -0.707) and the hero's heading along m0 (|m0 . heroDir| > 0.9): 0 or 1 at random;
//   - otherwise, with s = (m2 . d > 0) (m2 = third row): heading along m0 (> 0.707): s; against (< -0.5): !s;
//     else heading along m2 (> 0.5): 2 + !s, otherwise 2 + s.
// Dot products are evaluated in the original's operand order (float); the direction is normalised on the x87.
static u8 THISCALL heroPushFollower(u8 *self, u8 *a, const float *dir, const float *fpos, const float *unused,
                                    const float *hpos, const float *m, float radius) {
  (void)self;
  (void)unused;
  float rr = radius * 0.5f + 75.0f;   // 0x67a6ac, 0x680a8c
  float d2 = ext_4e0830(fpos, hpos);
  if (!(rr * rr > d2))
    return 0;
  float v[3];
  ext_43e920(v, fpos, hpos);
  v[1] = 0.0f;
  if (v[0] != 0.0f || v[2] != 0.0f) {   // NaN components also normalise (unordered compares)
    long double x = v[0], y = v[1], z = v[2];
    long double len = fsqrt_x87(x * x + y * y + z * z);
    long double inv = 1.0L / len;
    v[0] = (float)(v[0] * inv);
    v[1] = (float)(v[1] * inv);
    v[2] = (float)(v[2] * inv);
  }
  float vx = v[0], vy = v[1], vz = v[2];
  float m0 = m[0], m1 = m[1];
  float f0 = (m0 * vx + m1 * vy) + m[2] * vz;
  if (!(0.0f > f0))
    return 0;
  s32 side;
  if (-0.707f > f0 && __builtin_fabs((double)((dir[1] * m1 + m0 * dir[0]) + dir[2] * m[2])) > (double)0.9f) {
    u8 *sys = G(u8 *, 0x70039c);
    float r = ((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x6ac6d0, 0x635);
    side = !(r > 0.5f);
  } else {
    float s2 = (m[7] * vy + m[6] * vx) + m[8] * vz;
    bool s = s2 > 0.0f;
    float h0 = (dir[0] * m0 + dir[1] * m1) + dir[2] * m[2];
    if (h0 > 0.707f)
      side = s;
    else if (-0.5f > h0)
      side = !s;
    else {
      float h2 = (m[7] * dir[1] + m[6] * dir[0]) + m[8] * dir[2];
      side = 2 + (h2 > 0.5f ? !s : s);
    }
  }
  void **vt = *(void ***)a;
  u16 msg = vcall<u16>(objTable(), 0x114, (const char *)0x6a56c0, 0u, (const char *)0x6ac6d0, 0x657u);
  typedef void(THISCALL * f128)(void *, u32, void *, u32);
  ((f128)vt[0x128 / 4])(a, (u32)msg, &side, 0);
  return 1;
}
PCREG(5941d0, heroPushFollower);
