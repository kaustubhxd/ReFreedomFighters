// batch108.cpp - climb down: the fall's landing (fall damage, splash, landing animation clock) (climb thread, batch 108).
#include "ff.h"

extern "C" void FASTCALL ext_441940(float *v, const float *a);                    // v += a (x87), original
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);               // striwcmp, original
extern "C" void *THISCALL ext_4db3b0(void *geom);                                 // ZBaseGeom::GetOwnerRoom
extern "C" void THISCALL ext_581b60(void *coli, float *out);                      // COLI hit normal (batch 107)
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat, original
extern "C" void THISCALL ext_4e09b0(float *v);                                    // vneg, original

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *engineDb() { return *(u8 **)(sys() + 0x9b); }
static inline s32 ticks() { return *(s32 *)(sys() + 0x40); }
static inline float nowSec() { return (float)ticks() * 0.0009765625f; }
static inline float since(float t) { return (float)(s32)((u32)ticks() - (u32)(s32)(t * 1024.0f)) * 0.0009765625f; }
static inline float minss(float a, float b) { return a < b ? a : b; }

// The splash on water, as in ZFFHeroMovementJump::Move (batch 107) but with line 0x490 and no name test after the ray.
static void splash(u8 *self) {
  u8 *p = vcall<u8 *>(engineDb(), 0x160, 0xb5u);
  if (!p)
    return;
  u8 *q = vcall<u8 *>(engineDb(), 0x58, *(u32 *)(p + 0x18));
  if (!q)
    return;
  if (!(*(u32 *)(*(u8 **)(q + 0xc) + 0x23) & 0x100000u)) {
    typedef void (*hookfn)();
    hookfn hook = G(hookfn, 0x7003b0);
    if (hook)
      hook();
    else
      __builtin_debugtrap();
  }
  float pt[3] = {0.0f, 200.0f, -50.0f};
  float off[3];
  typedef long double(THISCALL * randfn)(void *, const char *, u32);
  randfn rnd = *(randfn *)(*(u8 **)sys() + 0x1c0);
  off[0] = (float)(rnd(sys(), (const char *)0x6b7a5c, 0x490) * 50.0f - 25.0f);
  off[1] = 0.0f;
  off[2] = (float)(rnd(sys(), (const char *)0x6b7a5c, 0x490) * 50.0f - 25.0f);
  ext_441940(pt, off);
  vcall<void>(*(void **)(self + 0x36d), 0x84, pt);
  float dir[3] = {0.0f, -200.0f, 0.0f};
  u8 coli[0x70];
  *(u32 *)coli = 0x3f800000u;
  void *ray = *(void **)(*(u8 **)(sys() + 0x1aa3) + 0x1c);
  if (!vcall<bool>(ray, 0x30, coli, 0u, pt, dir, 0u, 4u, 1u, 0u))
    return;
  void *room = ext_4db3b0(*(void **)(*(u8 **)(self + 0x36d) + 8));
  if (!room)
    return;
  float n[3], m[9], hit[3];
  ext_581b60(coli, n);
  vcall<void>(*(void **)(*(u8 **)(coli + 0x10) + 0x54), 0x88, n);
  ext_4de040(m, n, 0);
  for (int i = 0; i < 3; ++i) {
    float t = m[i];
    m[i] = m[3 + i];
    m[3 + i] = t;
  }
  ext_4e09b0(m);
  hit[0] = *(float *)(coli + 4);
  hit[1] = *(float *)(coli + 8);
  hit[2] = *(float *)(coli + 0xc);
  vcall<void>(room, 0x94, m, hit);
  vcall<void>(q, 0x1bc, room, m, hit, 0u, 0u, 0u, 1u);
}

// 0x5e2590, ZFFHeroMovementFall::GetActiveAnim(AnimHeader** out, a, b, c, pos) (GC map medium; the GC function has the
// "Water" string too). thiscall, ret 0x14, returns the animation phase in ST0. From the exe:
//  1. Debug print of the height above ground, as in the jump's Move.
//  2. While falling (+0x555): when the hero is on the ground (slot 0x5a4) or under 5 units up, it lands: +0x555 = 0,
//     +0x556 = 1 (one 16-bit store), land time +0x55f = now. Ground = GeomRefToPtr(hero slot 0x428()).
//     - Ground named "WaterWalk*" or "WaterSwim*": if the sound object at sys+0x1a9f exists, a volume
//       min(90, (fall start height +0x557 - pos[1]) / 5 + 10) goes to +0x88 of the geom of hero slot 0x3f4(sound
//       slot 0x58(slot 0x5c("Body"), slot 0x5c("Water"))); then the splash (see splash()).
//     - Otherwise (or no ground): fall damage = max(0, start height - pos[1] - safe drop +0x54c) * (hero+0x7fb *
//       +0x550) / 100 (maxss: NaN gives 0). When above 0, the hero's slot 0x664 gets a 12-dword damage record:
//       {render handle of the hero (engine slot 0x4c), 0, 7 (damage type), 0, pos xyz, 0, -1.0, 0, damage, damage * 0.1}.
//  3. Still falling: the start height +0x557 follows pos[1] upward; out = Fall (+0x563); phase = min(fps * t, frames) /
//     fps with t = seconds since +0x55b, fps = int at anim+0x6c, frames = (anim+0x64) - (anim+0x60) + 1; without an
//     animation fps = 25 and frames = 1. The divide is on the x87 stack, so the result keeps x87 precision.
//  4. Landed (+0x556): once (+0x577 clear), when sys+0x1a9f is set, v = min(90, drop / 5) goes to +0x88 of the geom of
//     owner slot 0x3f8(1), and 0.1 to +0x78 and v to +0x88 of that of owner slot 0x3f8(0); +0x577 set; owner slot 0x400(now)
//     three times. out = Land_Soft (+0x567); t = seconds since +0x55f; when fps * t passes frames, "falling" +0x554 clears
//     (the movement may end). Returns t.
//  5. Neither: returns 0.
static long double THISCALL fallGetActiveAnim(u8 *self, u8 **out, const float *a, const float *b, const float *c,
                                              const float *pos) {
  (void)a;
  (void)b;
  (void)c;
  u8 *dbg = vcall<u8 *>(sys(), 0x190);
  typedef void (*printfn)(void *, const char *, ...);
  (*(printfn *)(*(u8 **)dbg + 0x188))(dbg, (const char *)0x6792bc, (double)*(float *)(*(u8 **)(self + 0x36d) + 0x942));
  if (self[0x555]) {
    if (vcall<bool>(*(void **)(self + 0x36d), 0x5a4) || 5.0f > *(float *)(*(u8 **)(self + 0x36d) + 0x942)) {
      *(u16 *)(self + 0x555) = 0x100;
      *(float *)(self + 0x55f) = nowSec();
      u32 gref = vcall<u32>(*(void **)(self + 0x36d), 0x428);
      u8 *ground = vcall<u8 *>(engineDb(), 0x58, gref);
      bool water = false;
      if (ground) {
        const char *nm = *(const char **)(ground + 4);
        if (ext_4cc850(nm ? nm : (const char *)0x67c8e8, (const char *)0x6acac0) == 0) {
          water = true;
        } else {
          const char *nm2 = *(const char **)(ground + 4);
          water = ext_4cc850(nm2 ? nm2 : (const char *)0x67c8e8, (const char *)0x6acacc) == 0;
        }
      }
      if (water) {
        void *snd = *(void **)(sys() + 0x1a9f);
        if (snd) {
          float v = minss(90.0f, (*(float *)(self + 0x557) - pos[1]) / 5.0f + 10.0f);
          u32 s1 = vcall<u32>(snd, 0x5c, (const char *)0x6a2e84);   // "Body"
          u32 s2 = vcall<u32>(*(void **)(sys() + 0x1a9f), 0x5c, (const char *)0x6b7cc0);   // "Water"
          u32 h = vcall<u32>(*(void **)(sys() + 0x1a9f), 0x58, s1, s2);
          u32 r = vcall<u32>(*(void **)(self + 0x36d), 0x3f4, h);
          u8 *g = vcall<u8 *>(engineDb(), 0x60, r);
          if (g)
            *(float *)(g + 0x88) = v;
        }
        splash(self);
      } else {
        u8 *hero = *(u8 **)(self + 0x36d);
        float d = *(float *)(self + 0x557) - pos[1];
        d = d - *(float *)(self + 0x54c);
        float k = *(float *)(hero + 0x7fb) * *(float *)(self + 0x550);
        d = d > 0.0f ? d : 0.0f;
        d = d * k;
        d = d / 100.0f;
        if (d > 0.0f) {
          u32 rec[12];
          rec[0] = vcall<u32>(engineDb(), 0x4c, hero);
          rec[1] = 0;
          rec[2] = 7;
          rec[3] = 0;
          rec[4] = *(const u32 *)&pos[0];
          rec[5] = *(const u32 *)&pos[1];
          rec[6] = *(const u32 *)&pos[2];
          rec[7] = 0;
          rec[8] = 0xbf800000u;
          rec[9] = 0;
          *(float *)&rec[10] = d;
          *(float *)&rec[11] = d * 0.100000001490116119f;
          vcall<void>(*(void **)(self + 0x36d), 0x664, rec);
        }
      }
    }
  }
  if (self[0x555]) {
    if (pos[1] > *(float *)(self + 0x557))
      *(float *)(self + 0x557) = pos[1];
    float t = since(*(float *)(self + 0x55b));
    float fps = 25.0f, frames = 1.0f;
    *out = *(u8 **)(self + 0x563);
    u8 *an = *(u8 **)(self + 0x563);
    if (an) {
      fps = (float)*(s32 *)(an + 0x6c);
      frames = (float)(*(s32 *)(an + 0x64) - *(s32 *)(an + 0x60) + 1);
    }
    float f = minss(fps * t, frames);
    return (long double)f / fps;
  }
  if (!self[0x556])
    return 0.0L;
  if (!self[0x577]) {
    if (*(u32 *)(sys() + 0x1a9f)) {
      float v = minss(90.0f, (*(float *)(self + 0x557) - pos[1]) / 5.0f);
      u32 r1 = vcall<u32>(*(void **)(self + 4), 0x3f8, 1u);
      u8 *g1 = vcall<u8 *>(engineDb(), 0x60, r1);
      if (g1)
        *(float *)(g1 + 0x88) = v;
      u32 r0 = vcall<u32>(*(void **)(self + 4), 0x3f8, 0u);
      u8 *g0 = vcall<u8 *>(engineDb(), 0x60, r0);
      if (g0) {
        *(u32 *)(g0 + 0x78) = 0x3dcccccdu;   // 0.1
        *(float *)(g0 + 0x88) = v;
      }
    }
    self[0x577] = 1;
    for (int i = 0; i < 3; ++i)
      vcall<void>(*(void **)(self + 4), 0x400, nowSec());
  }
  *out = *(u8 **)(self + 0x567);
  float t = since(*(float *)(self + 0x55f));
  float fps = 25.0f, frames = 1.0f;
  u8 *an = *(u8 **)(self + 0x567);
  if (an) {
    frames = (float)(*(s32 *)(an + 0x64) - *(s32 *)(an + 0x60) + 1);
    fps = (float)*(s32 *)(an + 0x6c);
  }
  if (fps * t > frames)
    self[0x554] = 0;
  return t;
}
PCREG(5e2590, fallGetActiveAnim);
