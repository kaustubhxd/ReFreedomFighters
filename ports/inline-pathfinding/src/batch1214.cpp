// batch1214.cpp - pathfinding tree: the fine A* (FindPath) with its time slicing, and the path shortcut pass.
//
// CFindPathTwoContext_packed (the time-sliced search state; PC, /Zp1): +0x44 time-slice record* {u32 start, u32
// budget, u32 maxSlices, u32 slices, ..., u8 enabled at +0x10}, +0x48 u8 fresh (set by isTimeUp when a search ends),
// +0x49 int resume step, +0x4d int step counter of the current call, +0x51 u16 current A* index, +0x53 u16 highest
// index seen, +0x55 current A* record*, +0x59 u16[3] start cell, +0x5f u16[3] goal cell, +0x65 iterator (0x2d bytes).
// The search is a coroutine: each call counts its steps from 0 and runs the step whose number equals `resume` (and
// every later one) unless time slicing is off; each finished step "yields" (0x52b0c0), which bumps `resume` and
// returns true when the slice is used up, so the call returns 0 and continues there next frame.
#include "pf.h"

extern "C" u32 THISCALL ext_531740(void *it, const u16 *pos, int level);
extern "C" u32 THISCALL ext_530a40(void *it);
extern "C" float FASTCALL ext_532850(const u16 *a, const u16 *b);
extern "C" u32 THISCALL ext_532770(void *oct, u16 *path, u32 idx, int level);
extern "C" u32 THISCALL ext_531b40(void *oct, u32 from, void *it, u32 dir, float cost, const u16 *x);
extern "C" u32 THISCALL ext_52e320(void *it, const s16 *d);
extern "C" u32 THISCALL ext_531070(void *it, const s16 *d);
extern "C" void THISCALL ext_52d250(void *oct, u32 head, u32 node);
extern "C" u32 THISCALL ext_532420(void *oct, u32 from, const u16 *x);
extern "C" void THISCALL ext_52b080(void *ctx);
extern "C" u32 THISCALL ext_52b0c0(void *ctx);
extern "C" void THISCALL ext_5318a0(void *oct, u32 idx);
extern "C" int THISCALL ext_52dbb0(void *oct, const u8 *a, const u8 *b, void *helpers);

#define ASTAR(o, i) (*(u8 **)((o) + 0x98) + (u32)(u16)(i) * 0x15)
#define TIMEFILE ((const char *)0x6a0ea8)

// 0x52b0c0 (no GC name; CContext time check) yield: when slicing is on, read the clock (ZSysInterface +0x1c8), and
// when more than `budget` passed restart the slice; while fewer than maxSlices slices were used, an expired slice
// counts one more and reports true. Always bumps `resume`. thiscall (context), bool.
static bool THISCALL ctxYield(u8 *ctx) {
  bool over = false;
  u32 *ts = *(u32 **)(ctx + 0x44);
  if (ts && ((u8 *)ts)[0x10]) {
    u32 now = vcall<u32>(g_pSysInterface, 0x1c8, TIMEFILE, 0x3d);
    ts = *(u32 **)(ctx + 0x44);
    over = now - ts[0] > ts[1];
    if (over) ts[0] = now;
    ts = *(u32 **)(ctx + 0x44);
    if (ts[3] < ts[2]) {
      if (over) ts[3]++;
    } else {
      over = false;
    }
  }
  (*(int *)(ctx + 0x49))++;
  return over;
}
PCREG(52b0c0, ctxYield);

// 0x5318a0 (no GC name) path shortcut: walking back from `idx`, each record's predecessor link (+0xe) is replaced by
// the farthest ancestor that still has a free straight line (CheckLine) to it: doubling search, then halving. Records
// reached over a special link (+0x14 bit 0) are left as they are. thiscall (octree), ret 4.
static void THISCALL shortcutPath(u8 *self, u32 idx32) {
  u16 cur = (u16)idx32;
  u8 prevFlag = 0, bl = 0;
  if (!cur) return;
  for (;;) {
    u32 e = cur;
    if (bl & 1) e = *(u16 *)(self + 0x9e + e * 32);
    u8 *rec = ASTAR(self, e);
    u16 si = *(u16 *)(rec + 0xe);
    bl = rec[0x14];
    if (!si) return;
    int step = 1;
    u32 best;
    u8 bh;
    u8 *p;
    for (;;) {                       // doubling
      best = si;
      bh = bl;
      if (!cur || ((bl | prevFlag) & 1)) break;
      p = ASTAR(self, si);
      bool stop = false;
      for (int c = 0; c < step; c++) {
        si = *(u16 *)(p + 0xe);
        bl = p[0x14];
        if (!si) break;
        if (bl & 1) {
          stop = true;
          break;
        }
        p = ASTAR(self, si);
      }
      if (stop || (bl & 1) || !si) break;
      if (!ext_52dbb0(self, p, rec, 0)) break;
      step *= 2;
    }
    si = (u16)best;
    bl = bh;
    if ((u16)best && cur && !((bh | prevFlag) & 1) && step > 1) {
      do {                           // halving
        step /= 2;
        p = ASTAR(self, si);
        bool hit = false;
        for (int c = 0; c < step; c++) {
          si = *(u16 *)(p + 0xe);
          bl = p[0x14];
          if (!si) {
            hit = true;
            break;
          }
          if (bl & 1) break;
          p = ASTAR(self, si);
        }
        if (!hit && si && !(bl & 1) && ext_52dbb0(self, p, rec, 0)) {
          best = si;
          bh = bl;
        } else {
          bl = bh;
          si = (u16)best;
        }
      } while (step > 1);
    }
    if (!((bl | prevFlag) & 1)) *(u16 *)(rec + 0xe) = (u16)best;
    cur = *(u16 *)(rec + 0xe);
    bl = rec[0x14];
    prevFlag = bl;
    if (!cur) return;
  }
}
PCREG(5318a0, shortcutPath);

static inline bool stepRuns(u8 *ctx) {
  int n = *(int *)(ctx + 0x4d);
  *(int *)(ctx + 0x4d) = n + 1;
  u8 *ts = *(u8 **)(ctx + 0x44);
  return !ts || !ts[0x10] || (!ctx[0x48] && n == *(int *)(ctx + 0x49));
}

static inline void itFromRec(u8 *ctx) {
  u8 *it = ctx + 0x65;
  u8 *rec = *(u8 **)(ctx + 0x55);
  *(u16 *)(it + 0x18) = *(u16 *)(rec + 4);
  *(u16 *)(it + 0x1a) = *(u16 *)(rec + 6);
  *(u16 *)(it + 0x1c) = *(u16 *)(rec + 8);
  *(u16 *)(it + 0xc) = *(u16 *)(rec + 4);
  *(u16 *)(it + 0xe) = *(u16 *)(rec + 6);
  *(u16 *)(it + 0x10) = *(u16 *)(rec + 8);
  *(u16 *)(it + 0x16) = *(u16 *)rec;
}

// One climb or drop try (x/z step with y +-1): returns 0 blocked, 1 tried, 0xffff A* full.
static inline u32 climbTry(u8 *self, u8 *ctx, s16 dx, s16 dz, s16 dy) {
  u8 *it = ctx + 0x65;
  s16 d[3] = {dx, dz, dy};
  if (it[0x20] == 3) ext_52e320(it, d);
  else ext_531070(it, d);
  u32 from = *(u16 *)(ctx + 0x51);
  if (!*(u16 *)(it + 0x16)) return 0;
  u16 idx = (u16)ext_530a40(it);
  if (!idx) return 0xffff;
  u8 *base = *(u8 **)(self + 0x98);
  u8 *n = base + idx * 0x15;
  float f = *(float *)(base + (u16)from * 0x15 + 0xa) + 1.0001f;
  if (*(float *)(n + 0xa) > f + 0.1f) {
    n[0x14] &= 0xfe;
    *(u16 *)(n + 0xe) = (u16)from;
    *(float *)(n + 0xa) = f;
    *(u16 *)n = *(u16 *)(it + 0x16);
    *(u16 *)(n + 4) = *(u16 *)(it + 0x18);
    *(u16 *)(n + 6) = *(u16 *)(it + 0x1a);
    *(u16 *)(n + 8) = *(u16 *)(it + 0x1c);
    ext_52d250(self, from, idx);
  }
  return 1;
}

// 0x52f2b0 ZPFOctree_packed::FindPath(unsigned short* from, unsigned short* to, float maxF, int mode,
// CFindPathTwoContext_packed*, CHelpers*) [map low (floats demoted it); GC 801982d0; source zpfoctreepacked.cpp line
// 0x628]. thiscall, ret 0x18, AX: the goal's A* index (path found, walked back through ctx+0x51), 0 = not found or
// paused (time slice used up), 0xffff = A* full or f above maxF.
// Fine A* on elements: per node the four level steps (+z, -z, +x, -x; when blocked, the same step one cell up, then
// one down), then special links; no pure vertical step. mode 2 keeps to the corridor marked by FindPathCoarse.
// Heuristic only at the start (Manhattan cells). Reports when more than 20000 nodes were used.
static u32 THISCALL findPathFine(u8 *self, u16 *from, u16 *to, float maxF, int mode, u8 *ctx, void *) {
  u8 *it = ctx + 0x65;
  *(int *)(ctx + 0x4d) = 0;
  if (ctx[0x48]) {
    ctx[0x48] = 0;
    *(int *)(ctx + 0x49) = 0;
  }
  if (stepRuns(ctx)) {
    *(u16 *)(self + 0x9c) = 1;
    *(u8 **)it = self;
    *(u16 **)(it + 4) = (u16 *)(self + 0x96);
    *(u32 *)(it + 8) = 0x40;
    *(u16 *)(ctx + 0x59) = from[0];
    *(u16 *)(ctx + 0x5b) = from[1];
    *(u16 *)(ctx + 0x5d) = from[2];
    *(u16 *)(ctx + 0x5f) = to[0];
    *(u16 *)(ctx + 0x61) = to[1];
    *(u16 *)(ctx + 0x63) = to[2];
    ext_531740(it, (u16 *)(ctx + 0x59), *(int *)(self + 0x38));
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    u16 c = (u16)ext_530a40(it);
    *(u16 *)(ctx + 0x51) = c;
    if (!c) {
      ext_52b080(ctx);
      return 0xffff;
    }
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    u8 *rec = ASTAR(self, *(u16 *)(ctx + 0x51));
    *(u8 **)(ctx + 0x55) = rec;
    *(float *)(rec + 0xa) = ext_532850(from, to);
    *(u16 *)(*(u8 **)(ctx + 0x55) + 0xe) = 0;
    *(u16 *)(*(u8 **)(ctx + 0x55) + 0x10) = 0;
    *(u16 *)(*(u8 **)(ctx + 0x55) + 0x12) = 0;
    rec = *(u8 **)(ctx + 0x55);
    *(u16 *)rec = *(u16 *)(it + 0x16);
    *(u16 *)(rec + 4) = *(u16 *)(it + 0xc);
    *(u16 *)(rec + 6) = *(u16 *)(it + 0xe);
    *(u16 *)(rec + 8) = *(u16 *)(it + 0x10);
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    *(u16 *)(ctx + 0x53) = 0;
    if (*(u16 *)(ctx + 0x51)) {
      for (;;) {
        u16 c = *(u16 *)(ctx + 0x51);
        if (c > *(u16 *)(ctx + 0x53)) *(u16 *)(ctx + 0x53) = c;
        u8 *rec = *(u8 **)(ctx + 0x55);
        if (maxF != 0.0f && *(float *)(rec + 0xa) > maxF) goto fail;
        if (*(u16 *)(rec + 4) == *(u16 *)(ctx + 0x5f) && *(u16 *)(rec + 6) == *(u16 *)(ctx + 0x61) &&
            *(u16 *)(rec + 8) == *(u16 *)(ctx + 0x63))
          break;
        if (mode != 2 || (u8)ext_532770(self, (u16 *)(rec + 4), *(u16 *)rec, *(int *)(self + 0x38))) {
          static const s16 climb[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
          for (int dir = 0; dir < 4; dir++) {
            itFromRec(ctx);
            u32 v = (u16)ext_531b40(self, *(u16 *)(ctx + 0x51), it, dir, 1.0f, (u16 *)(ctx + 0x5f));
            if (v == 0xffff) goto fail;
            itFromRec(ctx);
            if (!v) {
              v = climbTry(self, ctx, climb[dir][0], climb[dir][1], 1);
              if (v == 0xffff) goto fail;
              itFromRec(ctx);
              if (!v) {
                if (climbTry(self, ctx, climb[dir][0], climb[dir][1], -1) == 0xffff) goto fail;
              }
            }
          }
          itFromRec(ctx);
          if ((u16)ext_532420(self, *(u16 *)(ctx + 0x51), (u16 *)(ctx + 0x5f)) == 0xffff) goto fail;
        }
        // next open node (the list head is linked through +0x10)
        rec = *(u8 **)(ctx + 0x55);
        *(u16 *)(ctx + 0x51) = *(u16 *)(rec + 0x10);
        *(u16 *)(*(u8 **)(ctx + 0x55) + 0x10) = 0;
        rec = ASTAR(self, *(u16 *)(ctx + 0x51));
        *(u8 **)(ctx + 0x55) = rec;
        *(u16 *)(rec + 0x12) = 0;
        (*(int *)(ctx + 0x49))--;
        if (ext_52b0c0(ctx) & 0xff) return 0;   // the exe inlines this yield; same effect
        if (!*(u16 *)(ctx + 0x51)) break;
      }
      if (*(u16 *)(ctx + 0x53) > 20000) {
        void *r = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6a1438, 0x628);
        typedef void (*fn)(void *, const char *, u32);
        (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6a14d4, *(u16 *)(ctx + 0x53));
      }
    }
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    ext_5318a0(self, *(u16 *)(ctx + 0x51));
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  {
    u16 result = *(u16 *)(ctx + 0x51);
    while (*(u16 *)(ctx + 0x51)) {
      u8 *rec = ASTAR(self, *(u16 *)(ctx + 0x51));
      *(u8 **)(ctx + 0x55) = rec;
      u16 back = *(u16 *)(rec + 0xe);
      if (rec[0x14] & 1) back = *(u16 *)(self + 0x9e + back * 32);
      *(u16 *)(ctx + 0x51) = back;
    }
    ext_52b080(ctx);
    return result;
  }
fail:
  ext_52b080(ctx);
  return 0xffff;
}
PCREG(52f2b0, findPathFine);
