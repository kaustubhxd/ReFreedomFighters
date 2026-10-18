// batch9007.cpp - wire-ai thread (2026-10-13): PlayBodySound 0x546980 (GC 8029e0d4 PlayBodySound(float*, bool, float, unsigned int, bool),
// high), the ragdoll's body impact / drag sound, called by PullTriangleCyl2 0x547080 when a limb hits a face fast enough.
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(float *m);                                           // mreset
extern "C" void *THISCALL ext_4db3b0(void *geom);                                        // ZBaseGeom::GetOwnerRoom
extern "C" u32 THISCALL ext_43ec00(void *room, float *mat, float *pos, u32 snd, u32 a, u32 b, u32 c);   // ZGROUP::AddSound3d
typedef float(THISCALL *vRand546)(void *self, const char *file, u32 line);

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline void *db() { return *(void **)(sys() + 0x9b); }
static inline void *snds() { return *(void **)(sys() + 0x1a9f); }
static u8 *hero() {
  void *nm = vcall<void *>(db(), 0x138);
  u32 ref = 0;
  vcall<void>(nm, 0x88, (const char *)0x681320u, &ref);   // "HitmanGround"
  return vcall<u8 *>(db(), 0x58, ref);
}
// the sound object's volume (+0x84) and pitch step (+0x64 new, +0x60 the change): trunc(((engine random - base) * 50) as float)
static void tune(u32 handle, float vol, float base, u32 line) {
  u8 *so = vcall<u8 *>(db(), 0x60, handle);
  if (!so) return;
  *(float *)(so + 0x84) = vol;
  void *e = sys();
  float r = ((vRand546)(*(void ***)e)[0x1c0 / 4])(e, (const char *)0x6a2e20u, line);
  float f = (float)(((double)r - (double)base) * 50.0);   // x87 fsub / fmul (53-bit), fstp dword
  s32 p = _mm_cvttss_si32(_mm_set_ss(f));
  *(s32 *)(so + 0x60) = p - *(s32 *)(so + 0x64);
  *(s32 *)(so + 0x64) = p;
}

// 0x546980 PlayBodySound(float* pos, bool water, float vol, unsigned int id, bool drag), fastcall (ecx = pos, dl = water), ret 0xc.
//  No sound system ([engine]+0x1a9f) -> 0. The repeat interval (static 0x711cf8) is 0.5 s, 0.8 s for a drag the hero's flag 0x800 (+0x417)
//  allows: then the hero's ("HitmanGround") sound set (slot 0x578) gives "BodyDrag_Water" / "BodyDrag" (sound system slot 0x60).
//  Static 0x711d1c: 0 -> set to the clock and play; else while the clock is before it + interval x 1024 -> 0 (no sound), after it -> 0 and
//  play (so two calls in a row can play).
//  Drag (no hero drag sound yet: the hero's "BodyDrop_Water" / "Bodyfall"): the geom of id (database slot 0x54) or 0; its room's
//  AddSound3d(identity, pos, sound, 0, 0, 0); volume and pitch ((random - 0.75) x 50); returns the handle.
//  Impact: the geom of id or 0; its material record (render system +0x18 slot 0xf8(geom +0x6c)) byte 2 -> the database's slot 0x160 object
//  +0x28, else the sound system's "default"; sound = slot 0x58("Body", that), else slot 0x58("Body", "default"), else 0; AddSound3d; volume
//  and pitch ((random - 0.5) x 50); returns 0.
static u32 FASTCALL playBodySound(float *pos, u8 water, float vol, u32 id, u32 drag) {
  if (*(u32 *)(sys() + 0x1a9f) == 0) return 0;
  u8 impact = 1;
  u32 snd = 0;
  G(float, 0x711cf8) = bitsf(0x3f000000u);                       // 0x67a6ac 0.5
  float interval = bitsf(0x3f000000u);
  if ((u8)drag) {
    u8 *h = hero();
    impact = 0;
    if (h && (*(u32 *)(h + 0x417) & 0x800)) {
      u32 set = vcall<u32>(h, 0x578);
      snd = vcall<u32>(snds(), 0x60, set, (const char *)(water ? 0x6a2e4cu : 0x6a2e5cu));   // "BodyDrag_Water" / "BodyDrag"
      interval = bitsf(0x3f4ccccdu);                             // 0x67c1a8 0.8
      G(float, 0x711cf8) = interval;
    } else {
      interval = G(float, 0x711cf8);
    }
  }
  s32 *stamp = (s32 *)0x711d1c;
  s32 *now = (s32 *)(sys() + 0x40);
  if (*stamp == 0) {
    if (stamp != now) *stamp = *now;
  } else {
    s32 k = _mm_cvttss_si32(_mm_set_ss(interval * bitsf(0xc4800000u)));   // 0x67862c -1024
    if (*now < *stamp - k) return 0;
    *stamp = 0;
  }
  float mat[12];
  if (!impact) {
    if (snd == 0) {
      u8 *h = hero();
      if (h) {
        u32 set = vcall<u32>(h, 0x578);
        snd = vcall<u32>(snds(), 0x60, set, (const char *)(water ? 0x6a2e68u : 0x6a2e78u));   // "BodyDrop_Water" / "Bodyfall"
      }
    }
    ext_4de7a0(mat);
    void *g = vcall<void *>(db(), 0x54, id);
    if (!g) return 0;
    u32 handle = ext_43ec00(ext_4db3b0(g), mat, pos, snd, 0, 0, 0);
    tune(handle, vol, bitsf(0x3f400000u), 0x7c1);                // 0x684ce4 0.75
    return handle;
  }
  u8 *g = vcall<u8 *>(db(), 0x54, id);
  if (!g) return 0;
  u32 matSet = 0;
  u8 *rec = vcall<u8 *>(*(void **)(*(u8 **)(sys() + 0x1aa3) + 0x18), 0xf8, *(u32 *)(g + 0x6c));
  if (rec) {
    u8 *mo = vcall<u8 *>(db(), 0x160, (u32)rec[2]);
    matSet = mo ? *(u32 *)(mo + 0x28) : vcall<u32>(snds(), 0x5c, (const char *)0x685ffcu);   // "default"
  }
  u32 body = vcall<u32>(snds(), 0x5c, (const char *)0x6a2e84u);  // "Body"
  u32 s = vcall<u32>(snds(), 0x58, body, matSet);
  if (!s) {
    u32 def = vcall<u32>(snds(), 0x5c, (const char *)0x685ffcu);
    s = vcall<u32>(snds(), 0x58, body, def);
    if (!s) return 0;
  }
  ext_4de7a0(mat);
  u32 handle = ext_43ec00(ext_4db3b0(g), mat, pos, s, 0, 0, 0);
  if (!handle) return 0;
  tune(handle, vol, bitsf(0x3f000000u), 0x7f3);
  return 0;
}
PCREG(546980, playBodySound);
