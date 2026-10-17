// batch1217.cpp - pathfinding tree: request processing (ProcessQueue, RespondToRequest) and the time-slice record.
//
// ZPathfinder3 +0x18 CTimeSlice* {+0 start, +4 budget, +8 max slices, +0xc slices, +0x10 u8 enabled}, +0x1c
// CRespondToRequestContext* (coroutine fields +0x44..+0x4d, +0x51 CFindPathContext (its fresh byte = +0x99), +0x1fe
// SPathRequest copy of the request being served, +0x230 u8 "have a request").
#include "pf.h"

extern "C" u32 THISCALL ext_52cf00(void *ts, u32 on);
extern "C" void THISCALL ext_52cf10(void *ts);
extern "C" void THISCALL ext_52cf40(void *ts);
extern "C" u32 THISCALL ext_52b0c0(void *ctx);
extern "C" void THISCALL ext_52c6e0(void *self, u8 *req, u8 *ctx);
extern "C" void *THISCALL ext_52b170(void *self, float *a, float *b, float maxF, u32 f1, u32 f2, void *ctx,
                                     void *helpers);
extern "C" void *THISCALL ext_52b4e0(void *self, void *lst);
extern "C" u32 THISCALL ext_52b390(void *q, u8 *out);

#define PF_FILE ((const char *)0x6a0f54)
#define TSFILE ((const char *)0x6a13d8)   // engine\pathfinder\timeslicing.cpp

// 0x52cf00 (no GC name) CTimeSlice enable: sets +0x10, returns the old value. thiscall, ret 4, AL.
static u8 THISCALL tsEnable(u8 *ts, u32 on) {
  u8 old = ts[0x10];
  ts[0x10] = (u8)on;
  return old;
}
PCREG(52cf00, tsEnable);

// 0x52cf10 (no GC name) CTimeSlice begin frame: slices = 0, start = now (timeslicing.cpp line 0x23).
static void THISCALL tsBegin(u8 *ts) {
  *(u32 *)(ts + 0xc) = 0;
  *(u32 *)ts = vcall<u32>(g_pSysInterface, 0x1c8, TSFILE, 0x23);
}
PCREG(52cf10, tsBegin);

// 0x52cf40 (no GC name) CTimeSlice restart: start = now.
static void THISCALL tsRestart(u8 *ts) { *(u32 *)ts = vcall<u32>(g_pSysInterface, 0x1c8, TSFILE, 0x23); }
PCREG(52cf40, tsRestart);

// 0x52b390 (no GC name) CPathRequestQueue pop: copies the request at head and advances it; false when empty.
// thiscall, ret 4, AL.
static bool THISCALL queuePop(u8 *q, u8 *out) {
  int head = *(int *)(q + 8);
  if (head == *(int *)(q + 0xc)) return false;
  __builtin_memcpy(out, *(u8 **)q + head * 0x32, 0x32);
  *(int *)(q + 8) = (*(int *)(q + 8) + 1) % *(int *)(q + 4);
  return true;
}
PCREG(52b390, queuePop);

static inline bool stepRuns(u8 *ctx) {
  int n = *(int *)(ctx + 0x4d);
  *(int *)(ctx + 0x4d) = n + 1;
  u8 *ts = *(u8 **)(ctx + 0x44);
  return !ts || !ts[0x10] || (!ctx[0x48] && n == *(int *)(ctx + 0x49));
}
static inline void endSlice(u8 *ctx) {
  u32 *ts = *(u32 **)(ctx + 0x44);
  if (ts && ((u8 *)ts)[0x10]) {
    u32 now = vcall<u32>(g_pSysInterface, 0x1c8, (const char *)0x6a0ea8, 0x3d);
    ts = *(u32 **)(ctx + 0x44);
    if (now - ts[0] > ts[1]) ts[0] = now;
  }
  ctx[0x48] = 1;
}
static inline void coroutineStart(u8 *ctx) {
  *(int *)(ctx + 0x4d) = 0;
  if (ctx[0x48]) {
    ctx[0x48] = 0;
    *(int *)(ctx + 0x49) = 0;
  }
}

// copies the request at the queue head (no pop); false when empty
static inline bool queuePeek(u8 *q, u8 *out) {
  int head = *(int *)(q + 8);
  if (head == *(int *)(q + 0xc)) return false;
  __builtin_memcpy(out, *(u8 **)q + head * 0x32, 0x32);
  return true;
}

// 0x52c000 ZPathfinder3::ProcessQueue(bool) [map high; GameCube reference]. thiscall, ret 4. With the flag the time slice is
// switched on for the call (and restored after). Step 0: begin the frame's slice and take the first request whose
// actor is still set (cancelled requests have actor 0 and are dropped); step 1: restart the slice and answer it
// (RespondToRequest), keeping it while that search is paused.
static void THISCALL processQueue(u8 *self, u32 flag) {
  u8 lock = (u8)flag;
  u32 saved = flag;
  u8 *ctx = *(u8 **)(self + 0x1c);
  if (*(void **)(self + 0x18) && lock) saved = (flag & 0xffffff00u) | (u8)ext_52cf00(*(void **)(self + 0x18), 0);
  coroutineStart(ctx);
  if (stepRuns(ctx)) {
    if (*(void **)(self + 0x18)) ext_52cf10(*(void **)(self + 0x18));
    bool have = queuePeek(*(u8 **)(self + 0x79), ctx + 0x1fe);
    ctx[0x230] = have;
    if (have) {
      while (!*(u32 *)(ctx + 0x202)) {
        u8 *q = *(u8 **)(self + 0x79);
        bool got = queuePeek(q, ctx + 0x1fe);
        if (got) *(int *)(q + 8) = (*(int *)(q + 8) + 1) % *(int *)(q + 4);
        ctx[0x230] = got;
        if (!queuePeek(*(u8 **)(self + 0x79), ctx + 0x1fe)) {
          ctx[0x230] = 0;
          break;
        }
        ctx[0x230] = 1;
      }
    }
    if (ext_52b0c0(ctx) & 0xff) goto out;
  }
  if (stepRuns(ctx)) {
    if (*(void **)(self + 0x18)) ext_52cf40(*(void **)(self + 0x18));
    if (ctx[0x230]) {
      ext_52c6e0(self, ctx + 0x1fe, ctx + 0x51);
      if (!ctx[0x99]) goto out;
      ctx[0x230] = 0;
    }
    if (ext_52b0c0(ctx) & 0xff) goto out;
  }
  endSlice(ctx);
  ctx[0x230] = 0;
out:
  if (*(void **)(self + 0x18) && lock) ext_52cf00(*(void **)(self + 0x18), saved);
}
PCREG(52c000, processQueue);

// 0x52c6e0 ZPathfinder3::RespondToRequest(SPathRequest*, CRespondToRequestContext*) [map high; GameCube reference;
// zpathfinder3.cpp lines 0x2313..0x235f]. thiscall, ret 8. Searches from the actor's current position (when the
// actor's +0x54 object is a 0x200074 class, vtable +0x1e0 / +0x630) or the request's start, to the request's goal,
// with the radius as the f limit. While the search is paused nothing else happens. A found path is post-processed;
// when its first point is between 10 and 200 units from the request's start, that point is moved to the start and
// the running lengths are recomputed (above 200 a warning is printed). The response (0x20 bytes) goes to the actor's
// +0x54 object (vtable +0x128 with the message id at +0x95); then the request is popped.
static void THISCALL respondToRequest(u8 *self, u8 *req, u8 *ctx) {
  coroutineStart(ctx);
  if (stepRuns(ctx)) {
    if (self[0x24]) {
      pfReport(PF_FILE, 0x2313, (const char *)0x6a103c);
    } else {
      if (G(u8, 0x701b58)) pfReport(PF_FILE, 0x2317, (const char *)0x6a10d8);
      float P[3] = {*(float *)(req + 8), *(float *)(req + 0xc), *(float *)(req + 0x10)};
      u32 actor = *(u32 *)(req + 4);
      if (actor && actor != 0xffffffffu) {
        u8 *a = vcall<u8 *>(*(void **)((u8 *)g_pSysInterface + 0x9b), 0x54, actor);
        void *obj = *(void **)(a + 0x54);
        if (vcall<u8>(obj, 0x1e0, 0x200074)) {
          P[0] = P[1] = P[2] = 0;
          vcall<void>(obj, 0x630, P);
        }
      }
      u8 *lst = (u8 *)ext_52b170(self, P, (float *)(req + 0x14), *(float *)(req + 0x2c), req[0x30], req[0x31],
                                  ctx + 0x51, *(void **)(self + 0x49));
      if (!ctx[0x99]) {
        if (lst) {
          pfReport(PF_FILE, 0x232c, (const char *)0x6a10f0);
          pfBreak();
        }
        return;
      }
      if (lst) lst = (u8 *)ext_52b4e0(self, lst);
      actor = *(u32 *)(req + 4);
      if (actor && actor != 0xffffffffu) {
        u8 *a = vcall<u8 *>(*(void **)((u8 *)g_pSysInterface + 0x9b), 0x54, actor);
        if (a) {
          if (lst && *(int *)(lst + 8) > 0) {
            float S[3] = {*(float *)(req + 8), *(float *)(req + 0xc), *(float *)(req + 0x10)};
            float d = ext_4e0870(S, (float *)(*(u8 **)(lst + 0xc) + 4));
            if (d > 200.0f) {
              void *r = vcall<void *>(G(void *, 0x700390), 0x20, PF_FILE, 0x234a);
              typedef void (*fn)(void *, const char *, double);
              (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a1118, (double)d);
            }
            if (d > 10.0f && 200.0f > d) {
              float *pts = *(float **)(lst + 0xc);
              pts[1] = S[0];
              pts[2] = S[1];
              pts[3] = S[2];
              for (int i = 1; i < *(int *)(lst + 8); i++) {
                float *p = (float *)(*(u8 **)(lst + 0xc) + i * 16);
                p[0] = (float)((long double)ext_4e0870(p - 3, p + 1) + (long double)p[-4]);
              }
              *(float *)(lst + 4) = *(float *)(*(u8 **)(lst + 0xc) + *(int *)(lst + 8) * 16 - 16);
            }
          }
          u32 *resp = (u32 *)ext_41e290(0x20);
          if (resp) __builtin_memset(resp, 0, 0x20);
          for (int k = 0; k < 6; k++) resp[k] = *(u32 *)(req + 8 + 4 * k);
          resp[7] = (u32)lst;
          resp[6] = *(u32 *)req;
          if (G(u8, 0x701b58)) {
            void *r = vcall<void *>(G(void *, 0x700390), 0x20, PF_FILE, 0x235f);
            typedef void (*fn)(void *, const char *, u32);
            (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a1178, *(u32 *)req);
          }
          void *obj = *(void **)(a + 0x54);
          if (obj) vcall<void>(obj, 0x128, (u32) * (u16 *)(self + 0x95), resp, 0);
        }
      }
      ext_52b390(*(void **)(self + 0x79), req);
      if (ext_52b0c0(ctx) & 0xff) return;
    }
  }
  endSlice(ctx);
}
PCREG(52c6e0, respondToRequest);
