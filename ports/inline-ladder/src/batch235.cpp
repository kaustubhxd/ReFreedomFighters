// batch235.cpp - ZIKLNKOBJ::EmitFootDustParticle(float) base body (inline-ladder thread, 2026-10-11).
// Called by ZFFHERO::EmitFootDustParticle (batch 231) for non-hero actors. Labels: GUESS where a name is inferred.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_456b70(void *tmpl, u32 *ctlA, u32 *ctlB);   // ZParticleTemplate::GetController (batch lifted elsewhere)

static const char *const kFile = (const char *)0x685ee0;   // "..\..\code\engine\geomsextend\ziklnkobj.cpp"

// 0x4664a0 ZIKLNKOBJ::EmitFootDustParticle(float t) [GameCube reference, high; vtable slot 0x3d4+? (ZActor 251)], thiscall, ret 4.
// Skipped when the global object at 0x7003b8 has byte +0xab8 set, or the owner geom (+8) lacks flag 0x1000 at +0x3c,
// or the speed object (+0x6c) has float +0x271 > 2000.0. Template = db(+0x15d). GetController gives two keys.
// Emitter = db(key A); its slot 0x218 spawns: (key B, world origin, spread, t * 1024 truncated).
// Origin: local point (0, y, 0) from own slot 0x3b8 (y from the call's output) turned to world with own slot 0x84.
// Spread = ((r1 - 0.5) * 200, 5.0, (r2 - 0.5) * 200) with two engine randoms (slot 0x1c0, file, line 0x438). GUESS: a
// random upward-dust puff spread over 200 units horizontally.
static void THISCALL ikEmitFootDust(u8 *self, float t) {
  u8 *g = (u8 *)G(u32, 0x7003b8);
  if (g[0xab8])
    return;
  u8 *owner = (u8 *)U32(self, 8);
  if (!(U32(owner, 0x3c) & 0x1000))
    return;
  u8 *spd = (u8 *)U32(self, 0x6c);
  if (F32(spd, 0x271) > 2000.0f)
    return;
  u8 *db = (u8 *)U32(G(u32, 0x70039c), 0x9b);
  void *tmpl = vcall<void *>(db, 0x58, U32(self, 0x15d));
  if (!tmpl)
    return;
  u32 ctlA = 0, ctlB = 0;
  ext_456b70(tmpl, &ctlA, &ctlB);
  void *emitter = vcall<void *>(db, 0x58, ctlA);
  void *eng = (void *)G(u32, 0x70039c);
  float p[3];
  u32 r = vcall<u32>(self, 0x3b8, p);
  vcall<void>(self, 0x398, r);
  p[0] = 0.0f;
  p[2] = 0.0f;
  vcall<void>(self, 0x84, p);
  float rnd1 = (float)((vcall<long double>(eng, 0x1c0, kFile, 0x438u) - (long double)0.5f) * (long double)200.0f);
  float v[3];
  v[0] = rnd1;
  v[1] = 5.0f;
  float rnd2 = (float)((vcall<long double>(eng, 0x1c0, kFile, 0x438u) - (long double)0.5f) * (long double)200.0f);
  v[2] = rnd2;
  s32 ival = _mm_cvttss_si32(_mm_set_ss(t * 1024.0f));
  vcall<void>(emitter, 0x218, ctlB, p, v, (u32)ival);
}
PCREG(4664a0, ikEmitFootDust);
