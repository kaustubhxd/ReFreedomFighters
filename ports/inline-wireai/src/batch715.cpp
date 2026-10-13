// batch715.cpp - soldier AI, batch 715 (2026-10-11): CFFCoverList::CreateSpot, the cover-spot placement.
// Helpers left as exe code: vaddscalar 0x451890, PSVECSubtract 0x43e920, vsetlen 0x4e0d80, vadd 0x43e8e0, distance
// 0x4e0870, CCoverSpot::Init 0x5def10, the insert at a position 0x588750 (which shifts through 0x5885c0), mreset 0x4de7a0.
// The lower bound (x-sorted list) is ported here; the list holds 0x48-byte spots at begin/end/cap.
#include "ff.h"

extern "C" void FASTCALL ext_451890(float *out, const float *a, float s);       // out += a * s
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b); // out = a - b
extern "C" void FASTCALL ext_43e8e0(float *out, const float *a, const float *b); // out = a + b
extern "C" void THISCALL ext_4e0d80(float *v, float len);                        // vsetlen
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);           // distance
extern "C" void THISCALL ext_4de7a0(float *m);                                  // mreset
extern "C" bool THISCALL ext_5def10(void *spot, float *a, float *b, float *c, float *d, u32 type, u32 flags);
extern "C" void THISCALL ext_588750(void *list, void *pos, void *src);          // insert at pos (ret 8)

// 0x585a40 CFFCoverList::CreateSpot(float* a, float* b, float* c, float* d, bool check, eType type, u32 flags) [high].
// Position V = b + d * -25. With check set and V not valid for the pathfinder, V is moved to the nearest valid point
// (FindNearestPoint(V, 10, 10, 1)) along the way, and if still invalid the debug draw (ShowInvalidCovers) shows it.
// Then V must be at least 15 from every existing spot (otherwise a too-close debug draw and self->byte[0x56] = 1).
// A new spot is initialised from (b, a, c, d, type, flags) and inserted at its x-sorted place. Returns true when a spot
// was created. Pathfinder "rEnemyPathFinder3" is looked up on the geom database each call; missing: warning, false.
// FF_MAX_COVERSPOTS: when the list is full the overflow counter (0x714294) is bumped and a warning is logged, false.
struct CSpot { u8 b[0x48]; };

static void warn(u32 line, const char *fmt, u32 slot, u32 arg, bool hasArg) {
  void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6ab8a0, line);
  if (hasArg) {
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *, u32);
    (*(printf_t *)(*(u8 **)log + slot))(log, fmt, arg);
  } else {
    typedef void(__attribute__((cdecl)) * printf0_t)(void *, const char *);
    (*(printf0_t *)(*(u8 **)log + slot))(log, fmt);
  }
}

static u8 *lower_bound_x(u8 *first, u8 *last, float x) {
  s32 n = (s32)(last - first) / 0x48;
  while (n > 0) {
    s32 half = n >> 1;
    u8 *mid = first + half * 0x48;
    if (x > *(float *)(mid + 0x10)) {
      first = mid + 0x48;
      n = n - half - 1;
    } else {
      n = half;
    }
  }
  return first;
}

static bool THISCALL cover_CreateSpot(u8 *self, float *a, float *b, float *c, float *d, u32 check, u32 type, u32 flags) {
  u8 *eng = *(u8 **)0x70039c;
  void *db = *(void **)(eng + 0x9b);
  void *obj = vcall<void *>(db, 0x138);
  u32 ref = 0;
  vcall<void>(obj, 0x88, (const char *)0x68a9e0, &ref);
  u8 *pf = vcall<u8 *>(*(void **)(*(u8 **)0x70039c + 0x9b), 0x58, ref);
  if (!pf) {
    warn(0x1dc, (const char *)0x6aba58, 0x30, 0, false);
    return false;
  }

  float V[3] = {b[0], b[1], b[2]};
  ext_451890(V, d, -25.0f);

  bool skipCheck = !(u8)check;
  if (!skipCheck && !vcall<bool>(pf, 0x220, V)) {
    float W[3] = {V[0], V[1], V[2]};
    bool bl = vcall<bool>(pf, 0x218, V, 10.0f, 10.0f, 1.0f);
    V[1] = W[1];
    float X[3];
    ext_43e920(X, V, W);
    ext_4e0d80(X, 15.0f);
    ext_43e8e0(V, W, X);
    bool moved = bl && vcall<bool>(pf, 0x220, V);
    if (!moved) {
      u32 show = 0;
      const char *cfg = 0;
      show = vcall<bool>(*(void **)0x70039c, 0x5c, (const char *)0x6aba90, &cfg);   // "ShowInvalidCovers"
      if (!show)
        return false;
      typedef double(__attribute__((cdecl)) * atof_t)(const char *);
      double v = (*(atof_t *)0x6762d4)(cfg);
      if (!(v > 0.0))
        return false;
      float M[12];
      ext_4de7a0(M);
      float h = (type == 2) ? 20.0f : ((type == 1) ? 10.0f : 5.0f);
      float box[3] = {10.0f, h, 10.0f};
      float Vc[3] = {V[0], V[1], V[2]};
      void *sc = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
      vcall<void>(sc, 0x238, M, b, box, 0xffff00, 0);
      vcall<void>(sc, 0x218, b, Vc, 0xffff00);
      return false;
    }
  }

  u8 *lp = *(u8 **)(self + 0x6b);
  s32 capCount = (s32)(*(u32 *)(lp + 8) - *(u32 *)lp) / 0x48;
  s32 count = (s32)(*(u32 *)(lp + 4) - *(u32 *)lp) / 0x48;
  if (count >= capCount) {
    G(s32, 0x714294)++;
    warn(0x215, (const char *)0x6abaa4, 0x2c, capCount + G(s32, 0x714294), true);
    return false;
  }

  u8 *begin = *(u8 **)lp;
  u8 *end = *(u8 **)(lp + 4);
  if (begin != end) {
    for (u8 *s = begin; s != end; s += 0x48) {
      float dist = ext_4e0870((float *)(s + 0x10), b);
      if (15.0f > dist) {
        // too close: draw the neighbour and the new point in magenta and red, mark the cover, refuse
        float M[12];
        ext_4de7a0(M);
        float sz[3] = {3.0f, 3.0f, 3.0f};
        void *sc = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc);
        vcall<void>(sc, 0x238, M, s + 0x10, sz, 0xff00ff, 1);
        vcall<void>(sc, 0x238, M, b, sz, 0xff00ff, 1);
        vcall<void>(sc, 0x218, s + 0x10, b, 0xff0000);
        self[0x56] = 1;
        return false;
      }
    }
  }

  CSpot S;   // only the fields the original clears are set here; the rest is Init's job
  *(u32 *)(S.b + 0) = 0;
  *(u32 *)(S.b + 4) = 0;
  *(u32 *)(S.b + 0x34) = 0;
  *(u32 *)(S.b + 0x38) = 0;
  *(u32 *)(S.b + 0x40) = 0;
  *(u32 *)(S.b + 0x44) = 0;
  if (!ext_5def10(&S, b, a, c, d, type, flags))
    return false;
  u8 *pos = lower_bound_x(begin, end, *(float *)(S.b + 0x10));
  ext_588750(lp, pos, &S);
  return true;
}
PCREG(585a40, cover_CreateSpot);
