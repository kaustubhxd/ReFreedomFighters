// batch1514.cpp - recruits thread, batch 1514: ZFFHERO::SendFollowersToSafepoints, CFFTools_if::SendFormationEvent_rr.
#include "ff.h"

static inline void *objTable() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void(__attribute__((cdecl)) * logPrintf)(void *log, const char *fmt, ...);
typedef void(__attribute__((cdecl)) * assertHandler)();

struct RefIter {
  u32 cur, a, b;
};

extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);   // vdist (distance), ST0
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);   // vdist2 (squared), ST0

// 0x594c30 ZFFHERO::SendFollowersToSafepoints(ZGEOM* area, float radius, ZLIST* safepoints), thiscall, ret 0xc.
// Every follower within `radius` of the area's position (measured at the follower's height) is sent
// "RunToSafepoint" with the id of the nearest safepoint (list +0x18, REFTAB of ids; positions via slot 0x84) not yet
// given to another follower (at most 16 tracked).
static void THISCALL heroSendFollowersToSafepoints(u8 *self, void *area, float radius, u8 *list) {
  u8 sent[16];
  for (int i = 0; i < 16; ++i)
    sent[i] = 0;
  float C[3] = {0, 0, 0};
  vcall<void>(area, 0x84, C);
  for (u8 *rec = self + 0xa1a; rec != self + 0xa1a + *(u32 *)(self + 0xa16) * 0x30; rec += 0x30) {
    float P[3] = {0, 0, 0};
    vcall<void>(*(void **)rec, 0x84, P);
    C[1] = P[1];
    float d = ext_4e0870(C, P);
    if (!(radius > d))
      continue;
    float best = 9.99999968e37f;
    u32 bestId = 0;
    s32 bestIdx = 0;
    void *t = *(void **)(list + 0x18);
    if (!t)
      continue;
    RefIter it;
    vcall<void>(t, 0x4c, &it);
    u32 id = vcall<u32>(*(void **)(list + 0x18), 0x5c, &it);
    for (s32 i = 0; it.cur != 0; ++i) {
      if (!sent[i]) {
        void *o = vcall<void *>(objTable(), 0x58, id);
        float Q[3] = {0, 0, 0};
        vcall<void>(o, 0x84, Q);
        float dd = ext_4e0830(P, Q);
        if (best > dd) {
          bestId = id;
          bestIdx = i;
          best = dd;
        }
      }
      id = vcall<u32>(*(void **)(list + 0x18), 0x5c, &it);
    }
    if (!bestId)
      continue;
    sent[bestIdx] = 1;
    void *a = *(void **)rec;
    void **avt = *(void ***)a;
    u16 msg = vcall<u16>(objTable(), 0x114, (const char *)0x6a56cc, 0u, (const char *)0x6ac6d0, 0x5e8u);
    typedef void(THISCALL * f128)(void *, u32, void *, u32);
    ((f128)avt[0x128 / 4])(*(void **)rec, (u32)msg, &bestId, 0);
  }
}
PCREG(594c30, heroSendFollowersToSafepoints);

extern "C" u8 *THISCALL ext_5003d0(void *params, u32 i);
extern "C" void THISCALL ext_591820(u8 *hero, u32 msg, void *data);   // ZFFHERO::ForwardEventToFollowers

static void typeError(u32 line, u32 what) {
  void *lo = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x69c8e0, line);
  ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x69c6b0, (const char *)what);
  assertHandler h = G(assertHandler, 0x7003b0);
  if (!h)
    __builtin_debugtrap();
  h();
}

// 0x556e80 CFFTools_if::SendFormationEvent_rr(OpaqueCallParameters_t&), thiscall, ret 4.
// Script: SendFormationEvent_rr(heroId, unused, eventName, a, b): the hero's followers get the event (name resolved
// with table slot 0x114) with data {a, b} (ForwardEventToFollowers). The name parameter is a C string (type 3) or a
// string object (type 4, slot 0x34 gives the C string). A non-zero second parameter logs "unsupported feature";
// a missing or non-hero leader logs an error.
static void THISCALL toolsSendFormationEvent(u8 *self, u8 *params) {
  (void)self;
  u8 *p0 = ext_5003d0(*(void **)(params + 4), 0);
  if (p0[4] != 0 && p0[4] != 1)
    typeError(0x104, 0x69c938);
  u8 *hero = vcall<u8 *>(objTable(), 0x58, *(u32 *)p0);
  u8 *p2 = ext_5003d0(*(void **)(params + 4), 2);
  const char *name;
  if (p2[4] == 3) {
    name = *(const char **)p2;
  } else if (p2[4] == 4) {
    name = vcall<const char *>(*(void **)p2, 0x34);
  } else {
    typeError(0x111, 0x69c9b0);
    name = 0;
  }
  u32 data[2];
  data[0] = *(u32 *)ext_5003d0(*(void **)(params + 4), 3);
  data[1] = *(u32 *)ext_5003d0(*(void **)(params + 4), 4);
  if (!hero || !vcall<u8>(hero, 0x1e0, 0x2003e8u)) {
    void *lo = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6a57fc, 0x2cdu);
    ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x6a58c0);
    return;
  }
  if (*(u32 *)ext_5003d0(*(void **)(params + 4), 1) != 0) {
    void *lo = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6a57fc, 0x2d1u);
    ((logPrintf)(*(void ***)lo)[0x2c / 4])(lo, (const char *)0x6a590c);
  }
  u16 msg = vcall<u16>(objTable(), 0x114, name, 0u, (const char *)0x6a57fc, 0x2d4u);
  ext_591820(hero, (u32)msg, data);
}
PCREG(556e80, toolsSendFormationEvent);
