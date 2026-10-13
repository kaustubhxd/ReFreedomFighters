// batch107.cpp - climb down: the jump's per-frame move, landing and water splash (climb thread, batch 107).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);  // PSVECSubtract, original
extern "C" void FASTCALL ext_446ee0(float *out, const float *a, const float *b);  // vcross, original
extern "C" void FASTCALL ext_441940(float *v, const float *a);                    // v += a (x87), original
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);               // striwcmp, original
extern "C" void *THISCALL ext_4db3b0(void *geom);                                 // ZBaseGeom::GetOwnerRoom
extern "C" void THISCALL ext_581b60(void *coli, float *out);                      // COLI hit normal (below)
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat, original
extern "C" void THISCALL ext_4e09b0(float *v);                                    // vneg, original

// 0x581b60, thiscall (one stack arg: out), ret 4. Normal of the hit triangle of a COLI (ray result): corners at
// +0x14, +0x20, +0x2c; out = vcross(c2 - c0, c1 - c0) (c2 at +0x2c), normalised on the x87 stack unless all three components equal 0
// (same body as 0x45bfd0, other offsets). Callers: ZFFHeroMovementJump::Move and Fall::GetActiveAnim (with a COLI on the
// stack), ZFFHERO::EmitFootDustParticle, CExplodeMolotov::CollideParticles. Name: guess, from the callers.
static void THISCALL coliHitNormal(u8 *coli, float *out) {
  float e1[3], e2[3];
  ext_43e920(e1, (float *)(coli + 0x2c), (float *)(coli + 0x14));
  ext_43e920(e2, (float *)(coli + 0x20), (float *)(coli + 0x14));
  ext_446ee0(out, e1, e2);
  if (out[0] == 0.0f && out[1] == 0.0f && out[2] == 0.0f)
    return;
  long double x = out[0], y = out[1], z = out[2];
  long double inv = 1.0L / fsqrt_x87(x * x + y * y + z * z);
  out[0] = (float)(out[0] * inv);
  out[1] = (float)(out[1] * inv);
  out[2] = (float)(out[2] * inv);
}
PCREG(581b60, coliHitNormal);

static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *engineDb() { return *(u8 **)(sys() + 0x9b); }
static inline float nowSec() { return (float)*(s32 *)(sys() + 0x40) * 0.0009765625f; }

// 0x5e65b0, ZFFHeroMovementJump::Move(a, b, c, d, e) (GC map high). thiscall, ret 0x14. From the exe:
//  1. own slot 0x40(a..e) (new position into d, inferred), dPlanned = d - b; own slot 0x48(a..e) (collision), dReal = d - b.
//     Per axis with dPlanned != 0 (NaN counts): r = max(0, dReal / dPlanned) (maxss); if 1 > r the jump velocity
//     component (+0x5a3) is scaled by r (the jump loses speed into whatever it hit).
//  2. Debug print: sys slot 0x190() gives an object whose varargs slot 0x188(obj, fmt 0x6792bc, double height) is called
//     with the hero's height above ground (hero+0x942).
//  3. Landing, only once (+0x55e clear) and after take-off (+0x559 clear): the owner (+4) must be on the ground (slot
//     0x5a4) or under 5 units up, and more than 0xcc ticks (about 0.2 s) must have passed since the start (+0x551 * 1024,
//     truncated). Then +0x55e is set, the land time +0x55a = now, the owner's slot 0x400(now) is called three times.
//  4. When sys+0x1a9f is set: owner slot 0x3f8(1) (result unused), then the geom of owner slot 0x3f8(0) (engine slot 0x60)
//     gets the float 0.075 at +0x78.
//  5. Water splash: ground = GeomRefToPtr(owner slot 0x428()); p = engine slot 0x160(0xb5) (a lookup by id; guess: the
//     splash effect template) and q = GeomRefToPtr(p+0x18); stops if either is missing. q's class flags ((q+0xc)+0x23) must
//     have bit 20, else the assert hook [0x7003b0] is called (int3 when there is none). A random point: offset
//     (r1*50 - 25, 0, r2*50 - 25) + (0, 200, -50) with r = sys slot 0x1c0(file, line 0x29e) (x87 float), turned to world
//     by hero slot 0x84; a ray straight down 200 units from it (the collision object [sys+0x1aa3]+0x1c, slot 0x30; COLI on
//     the stack with only its first float set to 1). On a hit, when the ground's name matches "WaterWalk*" or
//     "WaterSwim*" (striwcmp, "<NONAME>" for none) and the hero's geom has an owner room: n = hit normal (0x581b60),
//     ((coli+0x10)+0x54)->slot 0x88(n), m = createmat(n, 0) with rows 0 and 1 swapped and row 0 negated, then
//     room->slot 0x94(m, hit point) and q->slot 0x1bc(room, m, hit point, 0, 0, 0, 1) (spawns the splash).
static void THISCALL jumpMove(u8 *self, const float *a, const float *b, float *c, float *d, float *e) {
  float dPlanned[3], dReal[3];
  vcall<void>(self, 0x40, a, b, c, d, e);
  ext_43e920(dPlanned, d, b);
  vcall<void>(self, 0x48, a, b, c, d, e);
  ext_43e920(dReal, d, b);
  float *jv = (float *)(self + 0x5a3);
  for (int i = 0; i < 3; ++i) {
    if (dPlanned[i] == 0.0f)
      continue;
    float r = dReal[i] / dPlanned[i];
    r = 0.0f > r ? 0.0f : r;
    if (1.0f > r)
      jv[i] = jv[i] * r;
  }
  u8 *dbg = vcall<u8 *>(sys(), 0x190);
  typedef void (*printfn)(void *, const char *, ...);
  (*(printfn *)(*(u8 **)dbg + 0x188))(dbg, (const char *)0x6792bc, (double)*(float *)(*(u8 **)(self + 0x36d) + 0x942));
  if (self[0x55e] || self[0x559])
    return;
  if (!vcall<bool>(*(void **)(self + 4), 0x5a4) && !(5.0f > *(float *)(*(u8 **)(self + 0x36d) + 0x942)))
    return;
  if ((s32)(*(u32 *)(sys() + 0x40) - (u32)(s32)(*(float *)(self + 0x551) * 1024.0f)) <= 0xcc)
    return;
  self[0x55e] = 1;
  *(float *)(self + 0x55a) = nowSec();
  for (int i = 0; i < 3; ++i)
    vcall<void>(*(void **)(self + 4), 0x400, nowSec());
  if (*(u32 *)(sys() + 0x1a9f)) {
    vcall<u32>(*(void **)(self + 4), 0x3f8, 1u);
    u32 ref = vcall<u32>(*(void **)(self + 4), 0x3f8, 0u);
    u8 *g = vcall<u8 *>(engineDb(), 0x60, ref);
    if (g)
      *(u32 *)(g + 0x78) = 0x3d99999au;   // 0.075
  }
  u32 gref = vcall<u32>(*(void **)(self + 4), 0x428);
  u8 *ground = vcall<u8 *>(engineDb(), 0x58, gref);
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
  off[0] = (float)(rnd(sys(), (const char *)0x6b7a5c, 0x29e) * 50.0f - 25.0f);
  off[1] = 0.0f;
  off[2] = (float)(rnd(sys(), (const char *)0x6b7a5c, 0x29e) * 50.0f - 25.0f);
  ext_441940(pt, off);
  vcall<void>(*(void **)(self + 0x36d), 0x84, pt);
  float dir[3] = {0.0f, -200.0f, 0.0f};
  u8 coli[0x70];
  *(u32 *)coli = 0x3f800000u;
  void *ray = *(void **)(*(u8 **)(sys() + 0x1aa3) + 0x1c);
  if (!vcall<bool>(ray, 0x30, coli, 0u, pt, dir, 0u, 4u, 1u, 0u))
    return;
  const char *nm = *(const char **)(ground + 4);
  bool water;
  if (ext_4cc850(nm ? nm : (const char *)0x67c8e8, (const char *)0x6acac0) == 0) {
    water = true;
  } else {
    const char *nm2 = *(const char **)(ground + 4);
    water = ext_4cc850(nm2 ? nm2 : (const char *)0x67c8e8, (const char *)0x6acacc) == 0;
  }
  void *room = ext_4db3b0(*(void **)(*(u8 **)(self + 0x36d) + 8));
  if (!water || !room)
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
PCREG(5e65b0, jumpMove);
