// batch710.cpp - soldier AI, batch 710 (2026-10-11): cover spots (CFFCoverList) -- quality test, check, take.
// CFFCoverList: spot vector begin at +0x5f, end at +0x63, CCoverSpot = 0x48 bytes: +0 CReservable (expiry, holder),
// +8 user, +0x10 position, +0x1c facing vector, +0x34 flags (0x20 = reserved with the bool of CCoverSpot::Reserve).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // out = a - b
extern "C" void THISCALL ext_4e09b0(float *);                                     // vneg
extern "C" void THISCALL ext_4e0d00(float *, float);                              // vscalar
extern "C" float THISCALL ext_585910(void *, void *, float *, u32);               // CoverSpotQuality
extern "C" void THISCALL ext_5df400(void *, u32, float, u32, u32);                // CCoverSpot::Reserve
extern "C" void THISCALL ext_5de9c0(void *);                                      // CReservable::Release

static inline s32 spot_count(u8 *self) { return (*(s32 *)(self + 0x63) - *(s32 *)(self + 0x5f)) / 0x48; }

// 0x585910 CFFCoverList::CoverSpotQuality(CCoverSpot&, float*, bool) [high], returns float on the x87 stack.
// Flat direction from the spot to pos (y zeroed, normalised in x87 precision when x or z is non-zero); when the bool is
// false it is negated and doubled. Quality is 1 when dot(spot facing, that direction) > 1, else 0. (With the bool
// true and unit vectors the dot cannot exceed 1, so callers passing true get 0 unless the facing is longer than 1;
// as compiled.)
static float THISCALL cover_SpotQuality(void *, u8 *spot, float *pos, u32 flag) {
  float d[3];
  ext_43e920(d, pos, (float *)(spot + 0x10));
  d[1] = 0;
  asm("" : "+m"(d[1]));   // keep the 0 * (1/len) products: the original multiplies the zeroed y too (NaN when len is 0)
  if (!(d[0] == 0.0f) || !(d[2] == 0.0f)) {
    long double x = d[0], y = d[1], z = d[2];
    long double len = fsqrt_x87(x * x + y * y + z * z);
    long double inv = 1.0L / len;
    d[0] = (float)(d[0] * inv);
    d[1] = (float)(d[1] * inv);
    d[2] = (float)(d[2] * inv);
  }
  if (!(u8)flag) {
    ext_4e09b0(d);
    ext_4e0d00(d, 2.0f);
  }
  float *f = (float *)(spot + 0x1c);
  float dot = f[1] * d[1] + f[0] * d[0];
  dot = dot + f[2] * d[2];
  return dot > 1.0f ? 1.0f : 0.0f;
}
PCREG(585910, cover_SpotQuality);

// 0x5857f0 CFFCoverList::CheckCover(unsigned int actor, unsigned int user, int spot, bool reserve) [high]: true when
// the user's geom exists, the index is valid, the spot is free or already the actor's, and the quality from the user's
// root point is positive; then reserves it for 5 s if asked. A failed check releases a held spot if asked.
static u32 THISCALL cover_CheckCover(u8 *self, u32 actor, u32 user, s32 idx, u32 reserve) {
  void *db = *(void **)(*(u8 **)0x70039c + 0x9b);
  void *g = vcall<void *>(db, 0x58, user);
  if (!g)
    return 0;
  if (!(idx < spot_count(self)) || idx < 0)
    return 0;
  u8 *spot = *(u8 **)(self + 0x5f) + idx * 0x48;
  u32 h = *(u32 *)(spot + 4);
  if (h != 0 && actor != h)
    return 0;
  float pos[3] = {0, 0, 0};
  vcall<void>(g, 0x84, pos);
  float q = ext_585910(self, spot, pos, 1);
  if (q > 0.0f) {
    if ((u8)reserve)
      ext_5df400(spot, actor, 5.0f, user, 1);
    return 1;
  }
  if ((u8)reserve && *(u32 *)(spot + 4))
    ext_5de9c0(spot);
  return 0;
}
PCREG(5857f0, cover_CheckCover);

// 0x588530 CFFCoverList::TakeCover(void*) [high]: event {actor, spot index}; reserves the spot for 3 s for the actor,
// keeping its user and flag. Index past the end: "WARNING: Tried to take non-exsistent cover". Always returns 1.
static u32 THISCALL cover_TakeCover(u8 *self, u32 *ev) {
  s32 idx = (s32)ev[1];
  if (!(idx < spot_count(self))) {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ab8a0, 0x493);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6abb68);
    return 1;
  }
  u8 *spot = *(u8 **)(self + 0x5f) + idx * 0x48;
  ext_5df400(spot, ev[0], 3.0f, *(u32 *)(spot + 8), (*(u32 *)(spot + 0x34) >> 5) & 1);
  return 1;
}
PCREG(588530, cover_TakeCover);

// 0x5875c0 CFFCoverList::FindCoverNoThreat(unsigned int actor, float* pos, float range) [high]: FindCover with an
// identity matrix, x from -range to +range, y and z up to range, a 0.15*range term, no threat.
extern "C" u32 THISCALL ext_586bc0(void *, u32, u32, float *, float *, float, float, float, float, float *, u32);
extern "C" void THISCALL ext_4de7a0(float *);   // mreset (identity 3x3)
static u32 THISCALL cover_FindCoverNoThreat(u8 *self, u32 actor, float *pos, float range) {
  float m[9];
  ext_4de7a0(m);
  return ext_586bc0(self, actor, 0, m, pos, -range, range, range, range * 0.15f, pos, 0);
}
PCREG(5875c0, cover_FindCoverNoThreat);
