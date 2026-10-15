// batch0614.cpp - fresh-06 batch 14 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}
static inline void *logAt(u32 file, u32 line) { return vcall<void *>(G(void *, 0x700390), 0x20, file, line); }
typedef void (*sink1)(void *, u32);
typedef void (*sink2)(void *, u32, u32);
static inline void sinkMsg(void *s, u32 a) { (*(sink1 *)(*(u8 **)s + 0x2c))(s, a); }
static inline void sinkMsg(void *s, u32 a, u32 b) { (*(sink2 *)(*(u8 **)s + 0x2c))(s, a, b); }
extern "C" void THISCALL ext_469870(void *self);
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" u32 THISCALL ext_4e5e60(void *db);

// 0x50f2e0, ZScriptSceneInterface_t::GetSceneFloat(OpaqueCallParameters_t&) (stdcall): argument 0 is a value of type
// 3 (as is) or 4 (object slot 0x34); other types log (0x69c8e0 line 0x111; 0x69c6b0, 0x69c9b0), call the handler and
// use 0. The render manager's object (slot 0x138) slot 0x84(v, &f) gives the float (0 first). A result (array +8
// element 0) of type 0 or 2 gets the float's bits with type 2; another type logs (line 0xd5; 0x69c6b0, 0x69c938) and
// calls the handler (int3 when none; not exercised).
static void STDCALL scriptGetSceneFloat(u8 *p) {
  u32 *a = (u32 *)ext_5003d0(*(void **)(p + 4), 0);
  u32 v;
  u8 t = ((u8 *)a)[4];
  if (t == 3) {
    v = a[0];
  } else if (t == 4) {
    v = vcall<u32>((void *)a[0], 0x34);
  } else {
    sinkMsg(logAt(0x69c8e0, 0x111), 0x69c6b0, 0x69c9b0);
    handlerCall();
    v = 0;
  }
  u32 f = 0;
  vcall<void>(vcall<void *>(rmgr(), 0x138), 0x84, v, &f);
  u8 *r = (u8 *)ext_5003d0(*(void **)(p + 8), 0);
  u8 rt = r[4];
  if (rt != 0 && rt != 2) {
    sinkMsg(logAt(0x69c8e0, 0xd5), 0x69c6b0, 0x69c938);
    handlerCall();
    return;
  }
  *(u32 *)r = f;
  r[4] = 2;
}
PCREG(50f2e0, scriptGetSceneFloat);

// 0x5524a0, CFFTools_if::EnginePause(OpaqueCallParameters_t&) (stdcall): logs a note (0x6a57fc line 0x52f, 0x6a5d70);
// the geom for argument 0 (render manager slot 0x58; no null check) gives its matrix and position (slot 0x80); with
// colour (200, 200, 200) the root tree (render manager +0xadc) makes a pause marker (slot 0x238(m, pos, colour,
// 0xff00, 0), handle kept in 0x713f08) or moves the existing one (slot 0x23c(handle, ...)). Then render manager slot
// 0xb4(1).
static void STDCALL toolsEnginePause(u8 *p) {
  float f[0x0f];
  float *m = f, *pos = f + 9, *col = f + 12;
  sinkMsg(logAt(0x6a57fc, 0x52f), 0x6a5d70);
  void *g = vcall<void *>(rmgr(), 0x58, *(u32 *)ext_5003d0(*(void **)(p + 4), 0));
  vcall<void>(g, 0x80, m, pos);
  col[0] = 200.0f;
  col[1] = 200.0f;
  col[2] = 200.0f;
  void *t = *(void **)((u8 *)rmgr() + 0xadc);
  u32 h = G(u32, 0x713f08);
  if (!h) G(u32, 0x713f08) = vcall<u32>(t, 0x238, m, pos, col, 0xff00u, 0u);
  else vcall<void>(t, 0x23c, h, m, pos, col, 0xff00u, 0u);
  vcall<void>(rmgr(), 0xb4, 1u);
}
PCREG(5524a0, toolsEnginePause);

// 0x5d9360, CTVOSDCamControl::CTVOSDCamControl(): 0x469870, flag 0x20 at +4, +0x44 = 0, vtable 0x6b63d8, +0x98 = the
// global at 0x6ef80c; four messages registered (render manager slot 0x114: names 0x682e18, 0x6b6494, 0x6b64a8,
// 0x6b64b4; file 0x6b645c, lines 0x21-0x24) with the ids as words at +0x80..+0x86. Returns this.
static void *THISCALL tvOsdCamCtor(u8 *self) {
  static const u32 names[4] = {0x682e18, 0x6b6494, 0x6b64a8, 0x6b64b4};
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b63d8;
  *(u32 *)(self + 0x98) = G(u32, 0x6ef80c);
  for (u32 i = 0; i < 4; ++i)
    *(u16 *)(self + 0x80 + 2 * i) = (u16)vcall<u32>(rmgr(), 0x114, names[i], 0u, 0x6b645cu, 0x21u + i);
  return self;
}
PCREG(5d9360, tvOsdCamCtor);

// 0x56cb20, CMultiplayerKOTH::CopyEventDataBlock(DBREAD&): base 0x610100(db); nine uints: two skipped, five geom ids
// (render manager slot 0x58 -> +0x180, +0x18c, +0x190, +0x194, +0x198, resolved after the reads), then +0x188 and
// +0x184; the object at +0x44 gets slot 0xbc(1) before the ids are resolved.
extern "C" void THISCALL ext_610100(void *self, void *db);
static void THISCALL kothCopyEventDataBlock(u8 *self, void *db) {
  ext_610100(self, db);
  ext_4e5e60(db);
  ext_4e5e60(db);
  u32 id[5];
  for (u32 i = 0; i < 5; ++i) id[i] = ext_4e5e60(db);
  *(u32 *)(self + 0x188) = ext_4e5e60(db);
  *(u32 *)(self + 0x184) = ext_4e5e60(db);
  vcall<void>(*(void **)(self + 0x44), 0xbc, 1u);
  *(u32 *)(self + 0x180) = vcall<u32>(rmgr(), 0x58, id[0]);
  *(u32 *)(self + 0x18c) = vcall<u32>(rmgr(), 0x58, id[1]);
  *(u32 *)(self + 0x190) = vcall<u32>(rmgr(), 0x58, id[2]);
  *(u32 *)(self + 0x194) = vcall<u32>(rmgr(), 0x58, id[3]);
  *(u32 *)(self + 0x198) = vcall<u32>(rmgr(), 0x58, id[4]);
}
PCREG(56cb20, kothCopyEventDataBlock);

// 0x4f12e0, ZCHAROBJ::SetText(const char*): the same text as now (+0x97) changes nothing (true). Else the old text is
// freed (engine slot 0xfc) and cleared; a non-empty new text is copied into an engine allocation (slot 0xf8, length +
// 1) at +0x97, the cached layout (+0x9b) is freed and cleared, and own slot 0x278 runs (its AL is the result). An empty
// or null text runs own slot 0x230, frees and clears +0x9b, and returns true (only AL is set).
static u8 THISCALL charObjSetText(u8 *self, const char *s) {
  const char *old = *(const char **)(self + 0x97);
  if (old) {
    const char *a = old, *b = s;
    for (;; ++a, ++b) {
      if (*a != *b) break;
      if (!*a) return 1;
    }
    vcall<void>(G(void *, 0x70039c), 0xfc, old);
    *(u32 *)(self + 0x97) = 0;
  }
  if (s && *s) {
    u32 n = 0;
    while (s[n]) ++n;
    char *d = vcall<char *>(G(void *, 0x70039c), 0xf8, n + 1);
    *(char **)(self + 0x97) = d;
    char c;
    do {
      c = *s++;
      *d++ = c;
    } while (c);
    if (*(void **)(self + 0x9b)) vcall<void>(G(void *, 0x70039c), 0xfc, *(void **)(self + 0x9b));
    *(u32 *)(self + 0x9b) = 0;
    return vcall<u8>(self, 0x278);
  }
  vcall<void>(self, 0x230);
  if (*(void **)(self + 0x9b)) vcall<void>(G(void *, 0x70039c), 0xfc, *(void **)(self + 0x9b));
  *(u32 *)(self + 0x9b) = 0;
  return 1;
}
PCREG(4f12e0, charObjSetText);
