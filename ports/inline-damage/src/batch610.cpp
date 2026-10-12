// batch610.cpp - damage thread, batch 610: difficulty hitpoint multipliers and the bone-collision record.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

#pragma pack(push, 1)
struct SIKBoneCollision { u8 zone; u8 front; };
#pragma pack(pop)

typedef void (*AssertHook)(void);
typedef void *(THISCALL *vLog)(void *self, const char *file, u32 line);
typedef void (*vMsg3)(void *self, const char *fmt, const char *arg);

static int streq(const char *a, const char *b) {
  for (;; ++a, ++b) {
    if (*a != *b) return 0;
    if (!*a) return 1;
  }
}

// 0x589c40 ZFFGameData::GetHitpointMultiplier(const char* className, int difficulty) (GC 800ea088).
// difficulty < 0 -> the current one (this +0x2c15 -> +0x411). Difficulty above 3 -> 1.0. Table: 4 rows of 9 floats at
// +0xab9 (row stride 36): EnemyPolice, EnemySoldier, EnemySergent, EnemySpecialist, EnemyVeteran, EnemySniper,
// EnemySpetsnaz, Friendly, Hero. FriendlyMP (+0xb49) and HeroMP (+0xb4d) have one value for every difficulty.
// Unknown names log "ERROR: No hitpointmultiplier for '%s'", call the assert hook (int3 without one) and return 1.0.
static float THISCALL getHitpointMultiplier(u8 *self, const char *name, s32 diff) {
  if (diff < 0) diff = *(s32 *)(*(u8 **)(self + 0x2c15) + 0x411);
  if ((u32)diff > 3) return 1.0f;
  static const u32 names[9] = {0x6abf08, 0x6abf14, 0x6abf24, 0x6abf34, 0x6abf44, 0x6abf54, 0x6abf60, 0x6abf70, 0x6a94b8};
  float *row = (float *)(self + 0xab9 + diff * 36);
  for (int k = 0; k < 9; ++k)
    if (streq(name, (const char *)names[k])) return row[k];
  if (streq(name, (const char *)0x6abf7c)) return *(float *)(self + 0xb49);  // FriendlyMP
  if (streq(name, (const char *)0x6abf88)) return *(float *)(self + 0xb4d);  // HeroMP
  u8 *lg = G(u8 *, 0x700390);
  u8 *o = (u8 *)((vLog)VT(lg, 0x20))(lg, (const char *)0x6abf90, 0xfc);
  ((vMsg3)VT(o, 0x2c))(o, (const char *)0x6abfc4, name);
  AssertHook h = G(AssertHook, 0x7003b0);
  if (!h) __builtin_debugtrap();
  h();
  return 1.0f;
}
PCREG(589c40, getHitpointMultiplier);

typedef void (THISCALL *vVec)(void *self, float *v);
typedef s32 (THISCALL *vFind)(void *self, float *v);
typedef u8 *(THISCALL *vP0)(void *self);

// 0x4666e0 ZIKLNKOBJ::GetBoneCollision(const float* pos, const float* dir) (GC 8017cdc0), returns `out`.
// The hit point is moved into the object's frame (own slot 0x8c), the nearest collision bone is looked up (slot 0x2b8,
// -1 = none) and its zone read from the bone table (slot 0x2cc, 48-byte records, zone at +0x2f); no bone -> zone 0.
// front = 1, cleared when dot(first three floats of the base geom (+8) after own slot 0x88, dir) < 0.
static SIKBoneCollision *THISCALL getBoneCollision(u8 *self, SIKBoneCollision *out, const float *pos, const float *dir) {
  float p[3] = {pos[0], pos[1], pos[2]};
  ((vVec)VT(self, 0x8c))(self, p);
  s32 b = ((vFind)VT(self, 0x2b8))(self, p);
  if (b != -1) {
    u8 *tab = ((vP0)VT(self, 0x2cc))(self);
    out->zone = tab[b * 48 + 0x2f];
  } else {
    out->zone = 0;
  }
  out->front = 1;
  float *g = *(float **)(self + 8);
  float v[3] = {g[0], g[1], g[2]};
  ((vVec)VT(self, 0x88))(self, v);
  float d = dir[1] * v[1] + dir[0] * v[0];
  d = d + dir[2] * v[2];
  if (0.0f > d) out->front = 0;
  return out;
}
PCREG(4666e0, getBoneCollision);
