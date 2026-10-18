// batch1215.cpp - pathfinding tree: FindPath3, the coarse-to-fine driver that turns two world points into a
// CChkPntLst, and its helpers.
//
// CFindPath3Context_packed (PC, /Zp1): +0x44 / +0x48 / +0x49 / +0x4d the time-slice coroutine fields (as in the fine
// context), +0x51 the embedded CFindPathTwoContext_packed (so its "fresh" byte is +0x99), +0xe3 float[3] search start
// (the second argument, raised 30 units), +0xef float[3] search goal (first argument, raised 30), +0xfb u16[3] start
// cell, +0x101 u16[3] goal cell, +0x107 / +0x108 u8 "start / goal cell is the point's own column", +0x109 u16 the fine
// search's result index.
#include "pf.h"

extern "C" int THISCALL ext_530e80(void *oct, u16 *out, const u16 *pos, u32 ry, u32 rxz, float weight);
extern "C" void THISCALL ext_531220(void *oct);
extern "C" int THISCALL ext_530ca0(void *it, u16 *out, float *p, u8 *flag);
extern "C" u32 THISCALL ext_52b0c0(void *ctx);
extern "C" void THISCALL ext_52b080(void *ctx);
extern "C" u32 THISCALL ext_530130(void *oct, u16 *from, u16 *to, float maxF, int level, int mode, void *helpers);
extern "C" u32 THISCALL ext_52f2b0(void *oct, u16 *from, u16 *to, float maxF, int mode, void *ctx, void *helpers);
extern "C" void *THISCALL ext_476dc0(void *lst, int n);
extern "C" void THISCALL ext_52d1c0(void *oct, void *lst, int *n, float *len, float *prev, float *p, int total,
                                    void *helpers, void *extra);
extern "C" void THISCALL ext_4e1b60(void *coli);                  // COLI::COLI()
extern "C" void ext_41e2c0(void *p);                              // array delete through the engine allocator

#define ASTAR(o, i) (*(u8 **)((o) + 0x98) + (u32)(u16)(i) * 0x15)

// 0x531220 (no GC name) clears the corridor markers: +2 of every area record (count u16 at +0x58) and of every
// component node (count u16 at +0x52), and the A* base slot (+0xa) of every area record. thiscall (octree).
static void THISCALL clearMarkers(u8 *self) {
  u8 *a = *(u8 **)(self + 0x5a);
  for (u16 k = 0; k < *(u16 *)(self + 0x58); k++) {
    *(u16 *)(a + k * 12 + 2) = 0;
    *(u16 *)(a + k * 12 + 0xa) = 0;
  }
  u8 *c = *(u8 **)(self + 0x54);
  for (u16 k = 0; k < *(u16 *)(self + 0x52); k++) *(u16 *)(c + k * 0x16 + 2) = 0;
}
PCREG(531220, clearMarkers);

// 0x530ca0 (no GC name) ZPFOctreeIterator_packed: cell for a path end point. Nearest walkable cell within 3 cells in
// x/z and 10 below; *own = 1 only when that cell is in the point's own x/z column. Failing that, a wider search
// (15 / 15, y weight 0.1). thiscall (iterator), ret 0xc, 1 = found.
static int THISCALL endPointCell(u8 *it, u16 *out, float *p, u8 *own) {
  *own = 1;
  u8 *oct = *(u8 **)it;
  float *mn = (float *)(oct + 6), *mx = (float *)(oct + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
  float lx = (p[0] - mn[0]) / ex * (float)*(int *)(oct + 0x3c);
  float ly = (p[1] - mn[1]) / ey * (float)*(int *)(oct + 0x44);
  float lz = (p[2] - mn[2]) / ez * (float)*(int *)(oct + 0x40);
  int tx = _mm_cvtt_ss2si(_mm_set_ss(lx));
  int tz = _mm_cvtt_ss2si(_mm_set_ss(lz));
  u16 c[3] = {(u16)tx, (u16)tz, (u16)_mm_cvtt_ss2si(_mm_set_ss(ly))};
  bool found = ext_530e80(*(u8 **)it, out, c, 10, 3, 1.0f) != 0;
  if (out[0] != (u16)tx || out[1] != (u16)tz) *own = 0;
  if (found) return 1;
  *own = 0;
  return ext_530e80(*(u8 **)it, out, c, 15, 15, 0.1f) != 0;
}
PCREG(530ca0, endPointCell);

static inline bool stepRuns(u8 *ctx) {
  int n = *(int *)(ctx + 0x4d);
  *(int *)(ctx + 0x4d) = n + 1;
  u8 *ts = *(u8 **)(ctx + 0x44);
  return !ts || !ts[0x10] || (!ctx[0x48] && n == *(int *)(ctx + 0x49));
}

// CContext::isTimeUp inlined in FindPath3 (identical to 0x52b080).
static inline void endSlice(u8 *ctx) {
  u32 *ts = *(u32 **)(ctx + 0x44);
  if (ts && ((u8 *)ts)[0x10]) {
    u32 now = vcall<u32>(g_pSysInterface, 0x1c8, (const char *)0x6a0ea8, 0x3d);
    ts = *(u32 **)(ctx + 0x44);
    if (now - ts[0] > ts[1]) ts[0] = now;
  }
  ctx[0x48] = 1;
}

#define LAST_ERROR G(u32, 0x701b60)   // 0xffff when the coarse search failed

// 0x52e830 ZPFOctree_packed::FindPath3(float* goal, float* start, float maxF, bool noGoalEnd, bool noStartEnd,
// CFindPath3Context_packed*, CHelpers*) [map high; GC 801968ec; source zpfoctreepacked.cpp lines 0x46e / 0x46f].
// thiscall, ret 0x1c. Returns a new CChkPntLst (path from the goal end back to the start, world points at the cell
// centres raised 30 units, link points with +15 for climbs), or NULL (no path, paused by time slicing, or the last
// straight piece to the start hits collision).
// Steps (time-sliced): reset corridor markers; reset the used A* records; cells of both ends; FindPathCoarse on the
// coarsest level (mode 1) then on each finer level (mode 2, levels - 0x4c + k); FindPath (mode 2) on elements; build.
static void *THISCALL findPath3(u8 *self, float *goal, float *start, float maxF, u32 noGoalEnd, u32 noStartEnd,
                                u8 *ctx, void *helpers) {
  LAST_ERROR = 0;
  *(int *)(ctx + 0x4d) = 0;
  if (ctx[0x48]) {
    ctx[0x48] = 0;
    *(int *)(ctx + 0x49) = 0;
  }
  float *pS = (float *)(ctx + 0xe3), *pG = (float *)(ctx + 0xef);
  u16 *cS = (u16 *)(ctx + 0xfb), *cG = (u16 *)(ctx + 0x101);
  u8 *ownS = ctx + 0x107, *ownG = ctx + 0x108;
  if (stepRuns(ctx)) {
    pS[0] = start[0];
    pS[1] = start[1];
    pS[2] = start[2];
    pG[0] = goal[0];
    pG[1] = goal[1];
    pG[2] = goal[2];
    pS[1] = pS[1] + 30.0f;
    pG[1] = pG[1] + 30.0f;
    ext_531220(self);
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    u16 n = *(u16 *)(self + 0x96);
    u8 *r = *(u8 **)(self + 0x98);
    for (u32 k = 0; k < n; k++, r += 0x15) {
      if (*(float *)(r + 0xa) != 100000.0f) {   // 0x68af2c; unordered also resets
        *(u32 *)(r + 0xa) = 0x47c35000;
        *(u16 *)r = 0;
        r[0x14] = 0;
        *(u32 *)(r + 0x10) = 0;
        *(u16 *)(r + 0xe) = 0;
      }
    }
    *(u16 *)(self + 0x96) = 2;
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    u8 it[0x30];
    if (self) {
      *(u8 **)it = self;
      *(u16 **)(it + 4) = (u16 *)(self + 0x96);
      *(u32 *)(it + 8) = 0x40;
    }
    if (!ext_530ca0(it, cS, pS, ownS)) {
      ext_52b080(ctx);
      return 0;
    }
    if (!ext_530ca0(it, cG, pG, ownG)) {
      ext_52b080(ctx);
      return 0;
    }
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    u16 r = (u16)ext_530130(self, cS, cG, maxF, *(int *)(self + 0x38) - *(int *)(self + 0x4c), 1, helpers);
    if (r == 0xffff || r == 0) {
      LAST_ERROR = 0xffff;
      ext_52b080(ctx);
      return 0;
    }
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  for (int k = 1; k < *(int *)(self + 0x4c); k++) {
    if (!stepRuns(ctx)) continue;
    u16 r = (u16)ext_530130(self, cS, cG, maxF, *(int *)(self + 0x38) - *(int *)(self + 0x4c) + k, 2, helpers);
    if (r == 0xffff || r == 0) {
      LAST_ERROR = 0xffff;
      endSlice(ctx);
      return 0;
    }
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  if (stepRuns(ctx)) {
    u16 r = (u16)ext_52f2b0(self, cS, cG, maxF, 2, ctx + 0x51, 0);
    *(u16 *)(ctx + 0x109) = r;
    if (!ctx[0x99]) return 0;              // the fine search paused
    if (r == 0xffff || r == 0) {
      ext_52b080(ctx);
      return 0;
    }
    if (ext_52b0c0(ctx) & 0xff) return 0;
  }
  // count the path (and link uses when the level has link points)
  int n = 0, links = 0;
  u16 idx = *(u16 *)(ctx + 0x109);
  if (idx) {
    u8 hasPts = self[5];
    do {
      n++;
      u8 *rec = ASTAR(self, idx);
      u8 lf = rec[0x14] & 1;
      u16 back = *(u16 *)(rec + 0xe);
      if (lf) back = *(u16 *)(self + 0x9e + back * 32);
      if (hasPts && lf) links++;
      idx = back;
    } while (idx);
  }
  int total = n;
  if (!*ownS && !(u8)noStartEnd) total++;
  if (!*ownG && !(u8)noGoalEnd) total++;
  void *mem = ext_41e290(0x18);
  u8 *lst = mem ? (u8 *)ext_476dc0(mem, total + links) : 0;
  int cnt = 0;
  float len = 0;
  float prev[3], w[3];
  if (!*ownG && !(u8)noGoalEnd) {
    w[0] = pG[0];
    w[1] = pG[1];
    w[2] = pG[2];
    ext_52d1c0(self, lst, &cnt, &len, prev, w, total, helpers, 0);
  }
  u32 cur = *(u16 *)(ctx + 0x109);
  u8 flag = 0;
  for (int i = 0; i < n; i++) {
    u8 lf = flag & 1;
    u32 e = (u16)cur;
    if (lf) e = *(u16 *)(self + 0x9e + e * 32);
    u8 *rec = ASTAR(self, e);
    float cx = (float)(int)*(u16 *)(rec + 4) + 0.5f;
    float cz = (float)(int)*(u16 *)(rec + 6) + 0.5f;
    float cy = (float)(int)*(u16 *)(rec + 8) + 0.5f;
    float *mn = (float *)(self + 6), *mx = (float *)(self + 0x12);
    float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
    w[0] = ex * cx / (float)*(int *)(self + 0x3c) + mn[0];
    w[2] = ez * cz / (float)*(int *)(self + 0x40) + mn[2];
    w[1] = ey * cy / (float)*(int *)(self + 0x44) + mn[1] + 30.0f;
    if (i == 0 && *ownG && !(u8)noGoalEnd) {
      w[0] = pG[0];
      w[2] = pG[2];
    }
    if (i == n - 1 && *ownS && !(u8)noStartEnd) {
      w[0] = pS[0];
      w[2] = pS[2];
    }
    if (lf) {
      u8 *E = self + 0x9e + (u16)cur * 32;
      if (self[5]) {
        w[0] = *(float *)(E + 4);
        w[1] = *(float *)(E + 8) + 15.0f;   // 0x680a80
        w[2] = *(float *)(E + 0xc);
        ext_52d1c0(self, lst, &cnt, &len, prev, w, total, helpers, E);
        w[0] = *(float *)(E + 0x10);
        w[1] = *(float *)(E + 0x14) + 15.0f;
        w[2] = *(float *)(E + 0x18);
        ext_52d1c0(self, lst, &cnt, &len, prev, w, total, helpers, E);
      } else {
        pfReport((const char *)0x6a1438, 0x46e, (const char *)0x6a0fc0);
        pfReport((const char *)0x6a1438, 0x46f, (const char *)0x6a1008);
      }
    } else {
      if (cnt) len = (float)((long double)ext_4e0870(prev, w) + (long double)len);
      prev[0] = w[0];
      prev[1] = w[1];
      prev[2] = w[2];
      float *pt = (float *)(*(u8 **)(lst + 0xc) + cnt * 16);
      pt[0] = len;
      (*(int **)(lst + 0x10))[cnt] = 0;
      (*(int **)(lst + 0x14))[cnt] = 0;
      int c0 = cnt++;
      pt = (float *)(*(u8 **)(lst + 0xc) + c0 * 16);
      pt[1] = w[0];
      pt[2] = w[1];
      pt[3] = w[2];
    }
    cur = *(u16 *)(rec + 0xe);
    flag = rec[0x14];
  }
  if (!*ownS && !(u8)noStartEnd) {
    float p[3] = {pS[0], pS[1], pS[2]};
    u8 coli[0x70];
    ext_4e1b60(coli);
    *(float *)coli = prev[0];
    *(float *)(coli + 4) = prev[1];
    *(float *)(coli + 8) = prev[2];
    *(float *)(coli + 0xc) = p[0] - prev[0];
    *(float *)(coli + 0x10) = p[1] - prev[1];
    *(float *)(coli + 0x14) = p[2] - prev[2];
    void *col = *(void **)(*(u8 **)((u8 *)g_pSysInterface + 0x9b) + 0xadc);
    if (vcall<u8>(col, 0x2e0, coli, 0, 0x21, 0x200000, 1, 0)) {
      if (!lst) {
        endSlice(ctx);
        return 0;
      }
      if (*(void **)(lst + 0xc)) ext_41e2c0(*(void **)(lst + 0xc));
      if (*(void **)(lst + 0x10)) ext_634273(*(void **)(lst + 0x10), 4);
      if (*(void **)(lst + 0x14)) ext_634273(*(void **)(lst + 0x14), 4);
      ext_634273(lst, 0x18);
      endSlice(ctx);
      return 0;
    }
    ext_52d1c0(self, lst, &cnt, &len, prev, p, total, helpers, 0);
  }
  *(int *)(lst + 8) = cnt;
  *(float *)(lst + 4) = len;
  endSlice(ctx);
  return lst;
}
PCREG(52e830, findPath3);
