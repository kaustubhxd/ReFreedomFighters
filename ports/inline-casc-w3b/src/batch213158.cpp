#include "ff.h"

extern "C" void THISCALL ext_4daf90(void *node, void *out);
extern "C" void FASTCALL ext_43e960(void *out, void *a);
extern "C" void THISCALL ext_4e09b0(void *v);
extern "C" double VECTORCALL ext_634d7c(double x);
extern "C" void FASTCALL ext_633654(u32 cookie);

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, void *, void *);
typedef u32(THISCALL *V3)(void *, u32, void *, void *);
typedef u32(THISCALL *V4)(void *, void *, void *, void *, u32);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u16 R16(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline float cf(u32 addr) { return *(const float *)addr; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x591f60: thiscall(), /GS. Scans the items of this slot 0x528() (iterator: slot 0x4c(&itv) / 0x5c(&itv) / 0x44(&itv)), looks each up in the engine table (slot 0x58), skips this's own
// entities (this slots 0x504 / 0x500) and entities whose [e+8][0x3c] has 0x800, asks e slot 0x128(word [this+0x7c6], &list, this) for a candidate list, measures the distance
// of the entity (0x4daf90, slot 0x84, 0x43e960, negate 0x4e09b0, sqrt + [0x6970c0]), may take the matrices of the entity (or its parent, slot 0x20) through slots 0x2e0 / 0x98 when
// slot 0x1e0(0x1007d1) says so, and keeps the candidate c (c[0x5a] & 5 == 0) with this slot 0x654(c, &m1, &m2, flag) true and the smallest distance; returns it (0 when none).
// The locals keep the original frame layout (S = frame + 0x10, offsets as the original's esp-relative accesses before the two pushes).
static u32 body_591f60(u8 *self) {
  u8 fr[0xc0];
  __builtin_memset(fr, 0xcc, sizeof fr);
  u8 *S = fr + 0x10;
  W32(S + 0x98, 0);
  W32(S + 0xc, (u32)self);
  u8 *B = S + 0x3c;
  u8 *A = S + 0x78;
  W32(B, 0);
  __builtin_memset(A, 0, 32);
  W32(B + 4, 0);
  W32(B + 8, 0);
  (*(V2 *)(vt(self) + 0x384))(self, A, B);
  u8 *L = (u8 *)(*(V0 *)(vt(self) + 0x528))(self);
  W32(S + 0x14, (u32)L);
  if (!L) return 0;
  WF(S + 0x10, cf(0x67cd48));
  W32(S + 0x18, 0);
  (*(V1 *)(vt(L) + 0x4c))(L, (u32)(S + 0x24));
  u32 id = (*(V1 *)(vt(L) + 0x5c))(L, (u32)(S + 0x24));
  while (R32(S + 0x24) != 0) {
    do {
      u8 *E = G(u8 *, 0x70039c);
      u8 *tbl = (u8 *)R32(E + 0x9b);
      u8 *esi = (u8 *)(*(V1 *)(vt(tbl) + 0x58))(tbl, id);
      if (!esi) {
        (*(V1 *)(vt(L) + 0x44))(L, (u32)(S + 0x24));
        break;
      }
      if ((*(V0 *)(vt(self) + 0x504))(self) == (u32)esi) break;
      if ((*(V0 *)(vt(self) + 0x500))(self) == (u32)esi) break;
      if (R32((u8 *)R32(esi + 8) + 0x3c) & 0x800) break;
      W32(S + 4, 0);
      (*(V3 *)(vt(esi) + 0x128))(esi, R16(self + 0x7c6), S + 4, self);
      u8 *out = (u8 *)R32(S + 4);
      if (!out) break;
      ext_4daf90((void *)R32(esi + 8), S + 0x30);
      (*(V1 *)(vt(esi) + 0x84))(esi, (u32)(S + 0x30));
      ext_43e960(S + 0x30, B);
      ext_4e09b0(S + 0x30);
      float x = RF(S + 0x30), y = RF(S + 0x34), z = RF(S + 0x38);
      float sum = x * x + y * y;
      sum = sum + z * z;
      float len = (float)ext_634d7c((double)sum);
      float d = len + cf(0x6970c0);
      S[8] = 0;
      WF(S + 0x1c, d);
      u8 ok = (u8)(*(V1 *)(vt(esi) + 0x1e0))(esi, 0x1007d1);
      if (ok) {
        (*(V2 *)(vt(esi) + 0x2e0))(esi, S + 0x54, S + 0x48);
        (*(V2 *)(vt(esi) + 0x98))(esi, S + 0x54, S + 0x48);
        S[8] = 1;
      } else {
        if ((*(V0 *)(vt(esi) + 0x20))(esi) != 0) {
          u8 *p = (u8 *)(*(V0 *)(vt(esi) + 0x20))(esi);
          if ((u8)(*(V1 *)(vt(p) + 0x1e0))(p, 0x1007d1) != 0) {
            u8 *q = (u8 *)(*(V0 *)(vt(esi) + 0x20))(esi);
            (*(V2 *)(vt(q) + 0x2e0))(q, S + 0x54, S + 0x48);
            (*(V2 *)(vt(q) + 0x98))(q, S + 0x54, S + 0x48);
            S[8] = 1;
          }
        }
      }
      u32 n = R32(out);
      W32(S + 0x20, n);
      for (u32 i = 0; n != 0 && i < n; i++) {
        u8 *c = (u8 *)R32(out + 4 * i + 4);
        if (!c) continue;
        if (c[0x5a] & 5) continue;
        u32 r = (*(V4 *)(vt(self) + 0x654))(self, c, S + 0x54, S + 0x48, R32(S + 8));
        if ((u8)r == 0) continue;
        float nd = -RF(S + 0x1c);
        if (nd > RF(S + 0x10)) {
          WF(S + 0x10, nd);
          W32(S + 0x18, (u32)c);
        }
      }
    } while (0);
    id = (*(V1 *)(vt(L) + 0x5c))(L, (u32)(S + 0x24));
  }
  return R32(S + 0x18);
}
extern "C" u32 THISCALL fn_591f60(u8 *self);
extern "C" u32 THISCALL fn_591f60(u8 *self) {
  u32 r = body_591f60(self);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(591f60, fn_591f60);
