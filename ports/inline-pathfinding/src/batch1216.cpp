// batch1216.cpp - pathfinding tree: the ZPathfinder3 request side (FindPathInternal, RequestPathOld, the request
// queue).
//
// ZPathfinder3 more fields: +0x20 float height offset added to path ends, +0x24 bool "data corrupt", +0x49 CHelpers*
// (passed to TryLine), +0x75 u32 next request id, +0x79 CPathRequestQueue*, +0x95 u16 message id sent with an
// immediate response.
// CPathRequestQueue: +0 SPathRequest entries (0x32 bytes), +4 capacity, +8 head (last taken), +0xc tail (next free),
// +0x10 iteration cursor. Live entries are head+1 .. tail-1 (mod capacity).
// SPathRequest (0x32 bytes): +0 request id, +4 actor id, +8 from[3], +0x14 to[3], +0x20 / +0x24 / +0x28 search state
// (zeroed), +0x2c float radius, +0x30 / +0x31 bools.
// SPathResponse (0x20 bytes): +0 from[3], +0xc to[3], +0x18 int (-1 = immediate), +0x1c CChkPntLst*.
#include "pf.h"

extern "C" void *THISCALL ext_52e830(void *oct, float *goal, float *start, float maxF, u32 noGoalEnd, u32 noStartEnd,
                                     void *ctx3, void *helpers);
extern "C" void THISCALL ext_52b080(void *ctx);
extern "C" void *THISCALL ext_531a50(void *oct, float *a, float *b, void *helpers);
extern "C" void *THISCALL ext_52b4e0(void *self, void *lst);
extern "C" u32 THISCALL ext_52a700(void *q, const void *req);
extern "C" void THISCALL ext_52c000(void *self, u32 flag);

#define PF_FILE ((const char *)0x6a0f54)

// 0x52b170 ZPathfinder3::FindPathInternal(float* goal, float* start, float maxF, bool, bool, CFindPathContext*,
// CHelpers*) [map high; GameCube reference; zpathfinder3.cpp lines 0x236f / 0x2383]. thiscall, ret 0x1c. Both ends are
// raised by +0x20, then FindPath3 runs on the packed octree with the context's embedded 3-context (+0x51). Returns
// the path list, or 0 while the search is paused / on errors (corrupt data, debug switch 0x701b4d, unpacked data).
static void *THISCALL findPathInternal(u8 *self, float *a, float *b, float maxF, u32 f1, u32 f2, u8 *ctx,
                                       void *helpers) {
  if (self[0x24]) {
    pfReport(PF_FILE, 0x236f, (const char *)0x6a103c);
    return 0;
  }
  float h = *(float *)(self + 0x20);
  float A[3] = {a[0], h + a[1], a[2]};
  float B[3] = {b[0], h + b[1], b[2]};
  if (G(u8, 0x701b4d)) {
    pfBreak();
    return 0;
  }
  *(int *)(ctx + 0x4d) = 0;
  if (ctx[0x48]) {
    ctx[0x48] = 0;
    *(int *)(ctx + 0x49) = 0;
  }
  if (self[0x31]) {
    void *r = ext_52e830(*(void **)(self + 0x65), A, B, maxF, (u8)f1, (u8)f2, ctx + 0x51, helpers);
    if (!ctx[0x99]) return 0;
    ext_52b080(ctx);
    return r;
  }
  pfReport(PF_FILE, 0x2383, (const char *)0x6a1190);
  pfBreak();
  ext_52b080(ctx);
  return 0;
}
PCREG(52b170, findPathInternal);

// 0x52a700 (no GC name) CPathRequestQueue push: copies the 0x32-byte request to the tail; false when full.
// thiscall, ret 4, AL.
static bool THISCALL queuePush(u8 *q, const u8 *req) {
  int tail = *(int *)(q + 0xc);
  if ((tail + 1) % *(int *)(q + 4) == *(int *)(q + 8)) return false;
  __builtin_memcpy(*(u8 **)q + tail * 0x32, req, 0x32);
  *(int *)(q + 0xc) = (*(int *)(q + 0xc) + 1) % *(int *)(q + 4);
  return true;
}
PCREG(52a700, queuePush);

// 0x52b430 CPathRequestQueue::Load(ZLoadGame*) [map high; GameCube reference]. thiscall, ret 4, true. Capacity, head and
// tail (ZLoadGame +0x48), the entry block (+0x18), then the search state of every entry is cleared.
static bool THISCALL queueLoad(u8 *q, void *lg) {
  vcall<void>(lg, 0x48, q + 4);
  vcall<void>(lg, 0x48, q + 8);
  vcall<void>(lg, 0x48, q + 0xc);
  vcall<void>(lg, 0x18, *(void **)q, *(int *)(q + 4) * 0x32);
  u8 *e = *(u8 **)q;
  for (int i = 0; i < *(int *)(q + 4); i++, e += 0x32) {
    *(u32 *)(e + 0x24) = 0;
    *(u32 *)(e + 0x28) = 0;
    *(u32 *)(e + 0x20) = 0;
  }
  return true;
}
PCREG(52b430, queueLoad);

static inline u8 *queueFirst(u8 *q) {
  int it = *(int *)(q + 8);
  *(int *)(q + 0x10) = it;
  if (it == *(int *)(q + 0xc)) return 0;
  it = (it + 1) % *(int *)(q + 4);
  *(int *)(q + 0x10) = it;
  if (it == *(int *)(q + 0xc)) return 0;
  u8 *e = *(u8 **)q + it * 0x32;
  *(int *)(q + 0x10) = (it + 1) % *(int *)(q + 4);
  return e;
}
static inline u8 *queueNext(u8 *q) {
  int it = *(int *)(q + 0x10);
  if (it == *(int *)(q + 0xc)) return 0;
  u8 *e = *(u8 **)q + it * 0x32;
  *(int *)(q + 0x10) = (it + 1) % *(int *)(q + 4);
  return e;
}

// 0x52c270 ZPathfinder3::RequestPathOld(unsigned int actor, const float* from, const float* to, bool, float radius,
// bool, bool) [map high; GameCube reference; zpathfinder3.cpp lines 0x263e..0x2693]. thiscall, ret 0x1c.
// First tries a straight line (ends raised by +0x20 + 30): when free, the path goes to the actor at once (message
// table +0x54 finds the actor; its +0x54 object gets vtable +0x128 (message id, response, 0)), the actor's queued
// requests are cancelled (actor id 0), and the result is -1. Else the actor's queued request is updated in place, or a
// new one is pushed (after one ProcessQueue when full); returns the new request id, 0 on failure.
// The first bool argument is not used on PC.
static u32 THISCALL requestPathOld(u8 *self, u32 actor, const float *from, const float *to, u32, float radius,
                                   u32 b2, u32 b3) {
  if (G(u8, 0x701b58)) pfReport(PF_FILE, 0x263e, (const char *)0x6a128c);
  if (!*(void **)(self + 0x79)) {
    pfReport(PF_FILE, 0x2640, (const char *)0x6a129c);
    return 0;
  }
  float h = *(float *)(self + 0x20) + 30.0f;
  float A[3] = {from[0], h + from[1], from[2]};
  float B[3] = {to[0], h + to[1], to[2]};
  void *lst = 0;
  if (self[0x31]) {
    lst = ext_531a50(*(void **)(self + 0x65), A, B, *(void **)(self + 0x49));
  } else {
    pfReport(PF_FILE, 0x264f, (const char *)0x6a12d8);
    pfBreak();
  }
  if (lst) {
    void *path = ext_52b4e0(self, lst);
    float *resp = (float *)ext_41e290(0x20);
    if (resp) __builtin_memset(resp, 0, 0x20);
    resp[0] = A[0];
    resp[1] = A[1];
    resp[2] = A[2];
    resp[3] = B[0];
    resp[4] = B[1];
    resp[5] = B[2];
    *(void **)(resp + 7) = path;
    *(int *)(resp + 6) = -1;
    if (G(u8, 0x701b58)) pfReport(PF_FILE, 0x265b, (const char *)0x6a12ec);
    if (actor != 0xffffffffu) {
      u8 *a = vcall<u8 *>(*(void **)((u8 *)g_pSysInterface + 0x9b), 0x54, actor);
      if (a && *(void **)(a + 0x54)) vcall<void>(*(void **)(a + 0x54), 0x128, (u32) * (u16 *)(self + 0x95), resp, 0);
    }
    u8 *q = *(u8 **)(self + 0x79);
    for (u8 *e = queueFirst(q); e; e = queueNext(*(u8 **)(self + 0x79))) {
      if (*(u32 *)(e + 4) == actor) *(u32 *)(e + 4) = 0;
    }
    return 0xffffffffu;
  }
  u8 *q = *(u8 **)(self + 0x79);
  for (u8 *e = queueFirst(q); e; e = queueNext(*(u8 **)(self + 0x79))) {
    if (*(u32 *)(e + 4) != actor) continue;
    *(u32 *)e = *(u32 *)(self + 0x75);
    (*(u32 *)(self + 0x75))++;
    *(float *)(e + 8) = from[0];
    *(float *)(e + 0xc) = from[1];
    *(float *)(e + 0x10) = from[2];
    *(float *)(e + 0x14) = to[0];
    *(float *)(e + 0x18) = to[1];
    *(float *)(e + 0x1c) = to[2];
    e[0x30] = (u8)b2;
    *(u32 *)(e + 0x20) = 0;
    *(u32 *)(e + 0x24) = 0;
    *(u32 *)(e + 0x28) = 0;
    *(float *)(e + 0x2c) = radius;
    e[0x31] = (u8)b3;
    return *(u32 *)e;   // the new request id
  }
  u32 id = *(u32 *)(self + 0x75);
  u8 req[0x32];
  *(u32 *)req = id;
  *(u32 *)(req + 4) = actor;
  *(u32 *)(self + 0x75) = id + 1;
  *(u32 *)(req + 0x20) = 0;
  *(u32 *)(req + 0x24) = 0;
  *(u32 *)(req + 0x28) = 0;
  __builtin_memcpy(req + 8, from, 12);
  __builtin_memcpy(req + 0x14, to, 12);
  req[0x30] = (u8)b2;
  req[0x31] = (u8)b3;
  *(float *)(req + 0x2c) = radius;
  if ((u8)ext_52a700(q, req)) return id;
  ext_52c000(self, 1);
  if ((u8)ext_52a700(*(void **)(self + 0x79), req)) {
    pfReport(PF_FILE, 0x2693, (const char *)0x6a1354);
    return id;
  }
  pfReport(PF_FILE, 0x268f, (const char *)0x6a1318);
  pfBreak();
  return 0;
}
PCREG(52c270, requestPathOld);
