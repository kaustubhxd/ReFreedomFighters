// batch1234.cpp - pathfinding tree: ZActor::OnPathFound(request) [map 0x479910; thiscall, ret 4]. The request (0x20 bytes)
// carries the found path as a list (+0x1c: count +8, point array +0xc with 16-byte records: f0 at +0, point at +4).
// No path pending (+0x691 == 0): the list and the request are released. Otherwise the path is cut at the point the actor
// has reached: the last point is clipped against the path object's bounds (+8 -> +0x40..+0x48), the list is shortened,
// and the remaining points are reported to the engine. Notices go out through the vtable slots of the actor (0x64c,
// 0x650, 0x220, 0x628, 0x5f4, 0x5f8) and of the message table's collision object (0x218, 0x220).
// Float compares follow the exe's ucomiss/comiss flag tests (a NaN takes the same branch as the exe).
// The exe's SEH frame (fs:[0]) is not reproduced; nothing in the body can throw in this harness.
#include "pf.h"

extern "C" void THISCALL ext_4e0a10(float *out);                                    // zmath.cpp: vector from the engine
extern "C" float THISCALL ext_44c840(const float *v);                               // returns ST0; the exe discards it
extern "C" void THISCALL ext_4e0d00(float *v, float s);                             // v *= s
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // dst = a + b
extern "C" void FASTCALL ext_443ef0(float *dst, const float *y, const float *p, float s);   // dst = p * s + y
extern "C" void THISCALL ext_477580(void *lst, u32 flags);                          // path list release (flags & 1: delete)
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract: dst = a - b
extern "C" void ext_41e2c0(void *p);                                               // array delete through the engine allocator

typedef void (*reportStrFn)(void *, const char *, const char *);
typedef void (*reportDblFn)(void *, const char *, double, const char *);

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static u8 *rdp(const u8 *p) { return (u8 *)rd32u(p); }
static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static void wrf(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }

// The list's own release (what 0x477580 does with flags 1): the arrays, then the list (0x18 bytes).
static void freeList(u8 *lst) {
  if (rd32u(lst + 0xc)) ext_41e2c0((void *)rd32u(lst + 0xc));
  if (rd32u(lst + 0x10)) ext_634273((void *)rd32u(lst + 0x10), 4);
  if (rd32u(lst + 0x14)) ext_634273((void *)rd32u(lst + 0x14), 4);
  ext_634273(lst, 0x18);
}

// The colour the exe sends with the collision queries: each component (v + 1) * 255 * 0.5, truncated, packed as
// 0xff, then R, G, B bytes.
static u32 packColor(const float *v) {
  int c0 = (int)((v[0] + 1.0f) * 255.0f * 0.5f);
  int c1 = (int)((v[1] + 1.0f) * 255.0f * 0.5f);
  int c2 = (int)((v[2] + 1.0f) * 255.0f * 0.5f);
  u32 e = (u32)(c0 | 0xff00) << 8;
  e = (e | (u32)c1) << 8;
  return e | (u32)c2;
}

// The reporter's name for this actor: the object from its vtable +0x20 names the thing ("%s"), GUESS: a default.
static const char *actorName(u8 *self) {
  u8 *no = vcall<u8 *>(self, 0x20);
  u32 nm = rd32u(no + 4);
  return nm ? (const char *)nm : (const char *)0x67c8e8;
}

// The engine's message table (+0x9b) and its collision object (+0xadc).
static u8 *collisionObj() {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = *(u8 **)(eng + 0x9b);
  return *(u8 **)(msg + 0xadc);
}

// Tail of the path hand-off: the path object takes the list, the bounds are checked and reported, and the
// notice state is reset. ls is the last point of the old path (the exe's [ebp-0x34]).
static void tailF(u8 *self, u8 *lst, const float *ls) {
  if (self[0x726] == 0) vcall<void>(self, 0x220, 1u);
  u8 al = self[0x699];
  float X, Y, Zf;
  if (al == 0) {
    X = ls[0]; Y = ls[1]; Zf = ls[2];
  } else {
    X = rdf(self + 0x69a); Y = rdf(self + 0x69e); Zf = rdf(self + 0x6a2);
  }
  if (rd32u(self + 0x695) != 0) vcall<void>(self, 0x628, 2u, 4u, 0u);
  if (al) {
    wrf(self + 0x69a, X); wrf(self + 0x69e, Y); wrf(self + 0x6a2, Zf);
    self[0x699] = 1;
  }
  wr32u(self + 0x695, (u32)lst);
  u8 *x = (u8 *)rd32u(self + 0x73e);
  if (x) {
    float tmp[3];
    vcall<void>(x, 0x4c, tmp);
    u32 r = vcall<u32>(rdp(self + 0x73e), 0x5c, tmp);
    while (rd32u((const u8 *)tmp) != 0) {
      vcall<void>(collisionObj(), 0x220, r);
      r = vcall<u32>(rdp(self + 0x73e), 0x5c, tmp);
    }
  }
  vcall<void>(rdp(self + 0x73e), 0xc);
  if (!(G(float, 0x6ffa48) == 0.0f)) {
    float v40[3];
    ext_4e0a10(v40);
    if ((int)rd32u(rdp(self + 0x695) + 8) > 1) {
      for (int i = 1; i < (int)rd32u(rdp(self + 0x695) + 8); i++) {
        float v1c[3];
        ext_4e0a10(v1c);
        u32 col = packColor(v1c);
        u8 *arr = (u8 *)rd32u(lst + 0xc);
        u32 k16 = (u32)i << 4;
        u8 *xo = (u8 *)rd32u(self + 0x73e);
        u32 r3 = vcall<u32>(collisionObj(), 0x218, arr + k16 - 0xc, arr + k16 + 4, col);
        vcall<void>(xo, 4, r3);
      }
    }
  }
  u8 *lq = (u8 *)rd32u(self + 0x695);
  if (rdf(lq + 4) > 100000.0f) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x68a7c4, 0x642);
    const char *nm = actorName(self);
    (*(reportDblFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68ab50, (double)rdf(lq + 4), nm);
  }
  if (!self[0x6fe]) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x68a7c4, 0x646);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68ab80, actorName(self));
    self[0x6fe] = 1;
  }
  wrf(self + 0x678, 100.0f);
  wr32u(self + 0x722, 0);
  self[0x726] = 1;
  wr32u(self + 0x732, 0);
  self[0x72f] = 0;
  vcall<void>(self, 0x5f4);
  vcall<void>(self, 0x5f8);
  if (rd32u(self + 0x64c) == 0xb) wr32u(self + 0x64c, 0);
}

// Block I (the last point is cut at the bounds): the point at k+1 is moved to the cut point, the list ends at k+2.
static void cutAt(u8 *self, u8 *lst, u8 *obj, int k, float sum) {
  self[0x6c5] = 1;
  self[0x699] = 0;
  u32 k16 = (u32)k << 4;
  u8 *arr = (u8 *)rd32u(lst + 0xc);
  float v1c[3] = {rdf(arr + k16 + 0x14), rdf(arr + k16 + 0x18), rdf(arr + k16 + 0x1c)};
  float pk[3] = {rdf(arr + k16 + 4), rdf(arr + k16 + 8), rdf(arr + k16 + 0xc)};
  vcall<void>(obj, 0x8c, v1c);
  vcall<void>(obj, 0x8c, pk);
  u8 *p8 = (u8 *)rd32u(obj + 8);
  float bx = rdf(p8 + 0x40), by = rdf(p8 + 0x44), bz = rdf(p8 + 0x48);
  float a = 1.0f, b = 1.0f, c = 1.0f;
  float x0 = v1c[0];
  if (x0 > bx) {
    a = (bx - pk[0]) / (x0 - pk[0]);
  } else if (-bx > x0) {
    a = (pk[0] + bx) / (pk[0] - x0);
  }
  a = (a < 9.999999680285692e+37f) ? a : 9.999999680285692e+37f;
  float y0 = v1c[1];
  if (y0 > by) {
    b = (by - pk[1]) / (y0 - pk[1]);
  } else if (-by > y0) {
    b = (pk[1] + by) / (pk[1] - y0);
  }
  b = (b < a) ? b : a;
  float z0 = v1c[2];
  if (z0 > bz) {
    c = (bz - pk[2]) / (z0 - pk[2]);
  } else if (-bz > z0) {
    c = (pk[2] + bz) / (pk[2] - z0);
  }
  c = (c < b) ? c : b;
  float d40[3];
  ext_43e920(d40, v1c, pk);
  float q[3];
  ext_443ef0(q, pk, d40, c);
  vcall<void>(obj, 0x84, q);
  float dist = ext_4e0870(q, (float *)(arr + k16 + 4));
  float sum2 = sum - dist;
  wrf(lst + 4, rdf(lst + 4) - sum2);
  wrf(arr + k16 + 0x14, q[0]);
  wrf(arr + k16 + 0x18, q[1]);
  wrf(arr + k16 + 0x1c, q[2]);
  wrf(arr + k16 + 0x10, rdf(arr + k16) + dist);
  wr32u(lst + 8, (u32)k + 2);
}

// Everything after the point test: the time of the path's last point is tested against the object at +0x6bf.
static void finishPath(u8 *self, u8 *lst, u8 saved6c3, float *ls) {
  u32 obj6bf = rd32u(self + 0x6bf);
  if (obj6bf != 0) {
    self[0x6c5] = 0;
    if (!saved6c3) {
      u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *obj = (u8 *)vcall<u8 *>(msg, 0x58, obj6bf);
      vcall<void>(obj, 0x8c, ls);
      if (!(u8)vcall<u32>(obj, 0x180, ls, 10.0f)) {
        int k = (int)rd32u(lst + 8) - 1;
        float sum = 0.0f;
        if (k >= 0) {
          u8 *arr = (u8 *)rd32u(lst + 0xc);
          for (;;) {
            u8 *p = arr + ((u32)k << 4);
            float tmp[3] = {rdf(p + 4), rdf(p + 8), rdf(p + 0xc)};
            vcall<void>(obj, 0x8c, tmp);
            if ((u8)vcall<u32>(obj, 0x180, tmp, 10.0f)) break;
            float fprev = k > 0 ? rdf(arr + ((u32)(k - 1) << 4)) : 0.0f;
            sum = (rdf(p) - fprev) + sum;
            if (--k < 0) break;
          }
        }
        if (k == -1) {
          ext_477580(lst, 1);
          vcall<void>(self, 0x64c, 3u);
          return;
        }
        if (sum > 0.0f) cutAt(self, lst, obj, k, sum);
      }
    }
  }
  tailF(self, lst, ls);
}

// No list on the request (+0x1c == 0): the stored path is followed from the engine's position; with a non-zero
// flag and a path object it is reported as unresolvable.
static void noList(u8 *self, u8 *rec) {
  if (G(float, 0x6ffa48) == 0.0f) {
    ext_634273(rec, 0x20);
    vcall<void>(self, 0x64c, 0u);
    return;
  }
  u8 *x = (u8 *)rd32u(self + 0x73e);
  if (x) {
    float tmp[3];
    vcall<void>(x, 0x4c, tmp);
    u32 r = vcall<u32>(x, 0x5c, tmp);
    while (rd32u((const u8 *)tmp) != 0) {
      vcall<void>(collisionObj(), 0x220, r);
      r = vcall<u32>(rdp(self + 0x73e), 0x5c, tmp);
    }
    vcall<void>(rdp(self + 0x73e), 0xc);
  }
  float v1c[3];
  ext_4e0a10(v1c);
  u32 col = packColor(v1c);
  u8 *xo = (u8 *)rd32u(self + 0x73e);
  u32 r1 = vcall<u32>(collisionObj(), 0x218, rec, rec + 0xc, col);
  vcall<void>(xo, 4, r1);
  void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x68a7c4, 0x53e);
  (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68ab08, actorName(self));
  ext_634273(rec, 0x20);
  vcall<void>(self, 0x64c, 0u);
}

static void THISCALL actorOnPathFound(u8 *self, u8 *rec) {
  u8 saved6c3 = self[0x6c3];
  self[0x6c3] = 0;
  if (rd32u(self + 0x691) == 0) {
    u8 *lst = (u8 *)rd32u(rec + 0x1c);
    if (lst) freeList(lst);
    ext_634273(rec, 0x20);
    return;
  }
  wr32u(self + 0x691, 0);
  u8 *lst = (u8 *)rd32u(rec + 0x1c);
  if (!lst) {
    noList(self, rec);
    return;
  }
  ext_634273(rec, 0x20);
  float thr = rdf(self + 0x6b6);
  if (thr > 0.0f && rdf(lst + 4) > thr) {
    ext_477580(lst, 1);
    vcall<void>(self, 0x64c, 2u);
    wrf(self + 0x6b6, 0.0f);
    return;
  }
  wrf(self + 0x6b6, 0.0f);
  float t = rdf(self + 0x6ba);
  if (0.0f > t) {
    float tn = -t;
    wrf(self + 0x6ba, tn);
    float l4 = rdf(lst + 4);
    if (!(tn >= l4)) {
      wrf(self + 0x6ba, l4 - tn);
    } else {
      vcall<void>(self, 0x650);
    }
  }
  u8 *arr = (u8 *)rd32u(lst + 0xc);
  u32 cnt = rd32u(lst + 8);
  float ls[3] = {rdf(arr + (cnt << 4) - 0xc), rdf(arr + (cnt << 4) - 8), rdf(arr + (cnt << 4) - 4)};
  float z = rdf(self + 0x6b2);
  if (!(z == 0.0f)) {
    self[0x699] = 0;
    float l4 = rdf(lst + 4);
    if (!((z + 0.0001220703125f) >= l4)) {
      // the first point along the path that the actor is behind
      int k = (int)cnt - 1;
      float dd = l4 - z;
      bool found = false;
      for (; k >= 0; k--) {
        if (dd > rdf(arr + ((u32)k << 4))) {
          found = true;
          break;
        }
      }
      if (!found || k > (int)cnt - 2) {
        pfReport((const char *)0x68a7c4, 0x58f, (const char *)0x68ab28);
        wrf(self + 0x6b2, 0.0f);
        freeList(lst);
        vcall<void>(self, 0x64c, 0u);
        return;
      }
      wr32u(lst + 8, (u32)k + 2);
      u32 k16 = (u32)k << 4;
      float d10[3];
      ext_43e920(d10, (float *)(arr + k16 + 0x14), (float *)(arr + k16 + 4));
      ext_44c840(d10);
      float s = (l4 - z) - rdf(arr + k16);
      ext_4e0d00(d10, s);
      ext_43e8e0((float *)(arr + k16 + 0x14), (float *)(arr + k16 + 4), d10);
      wrf(arr + k16 + 0x10, l4 - z);
      ext_4e0870((float *)(arr + k16 + 0x14), (float *)(arr + k16 + 4));
      wrf(lst + 4, l4 - z);
      wrf(self + 0x6b2, 0.0f);
    } else {
      wrf(self + 0x6b2, 0.0f);
      ext_477580(lst, 1);
      vcall<void>(self, 0x64c, 1u);
      return;
    }
  }
  finishPath(self, lst, saved6c3, ls);
}
PCREG(479910, actorOnPathFound);
