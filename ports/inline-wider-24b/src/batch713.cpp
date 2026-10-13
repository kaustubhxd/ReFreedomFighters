// batch713.cpp - soldier AI, batch 713 (2026-10-11): cover upkeep -- spot type, the per-frame reservation check, and
// the shoot-over ray test.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);
extern "C" void THISCALL ext_4e0d00(float *, float);                              // vscalar
extern "C" void *THISCALL ext_4e1b60(void *);                                      // COLI::COLI
extern "C" void THISCALL ext_4de7a0(float *);                                      // mreset
extern "C" float THISCALL ext_585910(void *, void *, float *, u32);               // CoverSpotQuality
extern "C" bool THISCALL ext_5de970(void *);                                       // reservation expired (0x5de970)
extern "C" void THISCALL ext_5de9c0(void *);                                       // CReservable::Release
extern "C" void THISCALL ext_588180(void *, void *, u32, float);                  // debug draw of one spot (unnamed)
extern "C" s32 THISCALL ext_585a10(void *);                                        // CCoverSpot type (below)

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline void *scene() { return *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc); }

// 0x585a10 (unnamed; CCoverSpot type from flags +0x34): bit 0 -> 0, bit 1 -> 1, bit 2 -> 2, none -> assert and 0.
// Matches the CCoverSpot::eType argument of CreateSpot* (inferred).
static s32 THISCALL spot_GetType(u8 *spot) {
  u32 f = *(u32 *)(spot + 0x34);
  if (f & 1)
    return 0;
  if (f & 2)
    return 1;
  if (f & 4)
    return 2;
  void (*h)() = *(void (**)())0x7003b0;
  if (h) {
    h();
    return 0;
  }
  __builtin_debugtrap();
  return 0;
}
PCREG(585a10, spot_GetType);

// 0x587850 CFFCoverList::FrameUpdate() [high]. Debug: while the static float 0x714290 is >= 0 every spot is drawn
// (0x588180, colour 0xff00, size 10); a value of exactly 0 draws once (it is then set to -1).
// Upkeep, up to 256 spots per frame from cursor +0x73 (restarting at the beginning when it reached the end): a held spot
// whose user (+8) no longer gets quality > 0 from the user's root point sends the holder the "cover no good" message
// (u16 +0x54, data 0) and is released; otherwise, if the reservation has expired, the holder gets the u16 +0x50
// message with a pointer to the static 0x714298 holding the spot index, and the spot is released if still expired.
static void THISCALL cover_FrameUpdate(u8 *self) {
  float g = G(float, 0x714290);
  if (g >= 0.0f) {
    for (u8 *s = *(u8 **)(self + 0x5f); s != *(u8 **)(self + 0x63); s += 0x48)
      ext_588180(self, s, 0xff00, 10.0f);
    g = G(float, 0x714290);
  }
  if (g == 0.0f)
    G(u32, 0x714290) = 0xbf800000;
  u8 *&cur = *(u8 **)(self + 0x73);
  if (!cur || cur == *(u8 **)(self + 0x63))
    cur = *(u8 **)(self + 0x5f);
  for (int k = 256; k; k--) {
    if (cur == *(u8 **)(self + 0x63))
      break;
    if (*(u32 *)(cur + 4) != 0) {
      u32 user = *(u32 *)(cur + 8);
      bool release = false;
      if (user) {
        float pos[3] = {0, 0, 0};
        void *ug = vcall<void *>(db(), 0x58, user);
        vcall<void>(ug, 0x84, pos);
        u8 *s = cur;
        float q = ext_585910(self, s, pos, (u8)((*(u32 *)(s + 0x34) >> 5) & 1));
        if (!(0.0f < q) && q == q) {
          vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)(cur + 4), (u32) * (u16 *)(self + 0x54), 0);
          release = true;
        }
      }
      if (!release && ext_5de970(cur)) {
        u8 *s = cur;
        G(s32, 0x714298) = (s32)(s - *(u8 **)(self + 0x5f)) / 0x48;
        vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)(s + 4), (u32) * (u16 *)(self + 0x50), (void *)0x714298);
        if (ext_5de970(cur))
          release = true;
      }
      if (release)
        ext_5de9c0(cur);
    }
    cur += 0x48;
  }
}
PCREG(587850, cover_FrameUpdate);

// 0x5deb20 CCoverSpot::CheckShootOver(float* dir, float height, float length) [medium]: true when a ray from the spot
// raised by height, along dir (normalised in x87 precision when non-zero) scaled to length, is clear
// (collision slot 0x2e0(coli, 0, 2, 0x200000, 1, 0)). With the config value "ShowInvalidCovers" > 0 a blocked spot
// is drawn: a box (10 x [5|10|20 by spot type] x 10, slot 0x238) and the ray (slot 0x218), both red.
struct COLI { float start[3]; float delta[3]; u8 a[0x22]; float end[3]; u8 b[0x38]; };
static bool THISCALL spot_CheckShootOver(u8 *self, float *dir, float height, float length) {
  COLI c;
  ext_4e1b60(&c);
  float *p = (float *)(self + 0x10);
  c.start[0] = p[0];
  c.start[2] = p[2];
  c.start[1] = p[1] + height;
  float *d = c.delta;
  d[0] = dir[0];
  d[1] = dir[1];
  d[2] = dir[2];
  if (!(d[0] == 0.0f) || !(d[1] == 0.0f) || !(d[2] == 0.0f)) {
    long double x = d[0], y = d[1], z = d[2];
    long double len = fsqrt_x87(x * x + y * y + z * z);
    long double inv = 1.0L / len;
    d[0] = (float)(d[0] * inv);
    d[1] = (float)(d[1] * inv);
    d[2] = (float)(d[2] * inv);
  }
  ext_4e0d00(d, length);
  ((u8 *)&c)[0x6c] = 0;
  bool hit = vcall<bool>(scene(), 0x2e0, &c, 0, 2, 0x200000, 1, 0);
  const char *val;
  if (vcall<bool>(*(void **)0x70039c, 0x5c, (const char *)0x6aba90, &val)) {
    typedef double(__attribute__((cdecl)) * atof_t)(const char *);
    double v = (*(atof_t *)0x6762d4)(val);
    if (v > 0.0 && hit) {
      float m[9];
      ext_4de7a0(m);
      float h;
      if (ext_585a10(self) == 2)
        h = 20.0f;
      else if (ext_585a10(self) == 1)
        h = 10.0f;
      else
        h = 5.0f;
      float box[3] = {10.0f, h, 10.0f};
      vcall<void>(scene(), 0x238, m, p, box, 0xff0000, 0);
      vcall<void>(scene(), 0x218, c.start, (float *)((u8 *)&c + 0x28), 0xff0000);
    }
  }
  return !hit;
}
PCREG(5deb20, spot_CheckShootOver);
