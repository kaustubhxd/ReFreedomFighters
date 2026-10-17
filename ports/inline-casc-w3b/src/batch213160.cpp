#include "ff.h"

extern "C" u32 THISCALL ext_5b1000(void *p, const char *name);
extern "C" void THISCALL ext_5b15d0(void *p, const char *buf, void *iout, void *vec, void *mat);
extern "C" void THISCALL ext_574680(void *self, u32 a, u32 b, u32 fbits, void *out, u32 f90);
extern "C" void THISCALL ext_4db2c0(void *obj, void *m, void *v);
extern "C" void THISCALL ext_4de7a0(void *m);
extern "C" void THISCALL ext_4e09b0(void *v);
extern "C" float THISCALL ext_44c840(void *v);
extern "C" void FASTCALL ext_4de040(void *m, void *v, u32 flag);
extern "C" void FASTCALL ext_633654(u32 cookie);

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V1p)(void *, void *);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V2p)(void *, void *, u32);
typedef u32(THISCALL *V5)(void *, u32, u32, u32, u32, u32);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline float cf(u32 addr) { return *(const float *)addr; }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static bool streq(const char *a, const char *b) {
  while (*a == *b) {
    if (*a == 0) return true;
    a++; b++;
  }
  return false;
}
// cdecl vcall (M's vtable in ecx) with (fmt, a)
static void vt_log2(void *M, u32 off, u32 fmt, u32 a) {
  u32 vtp = *(u32 *)M, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[f]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $12, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [f] "r"(fmt), [o] "r"(M)
               : "edx", "memory", "cc");
}

// 0x576a30: thiscall(name) ret 4, /GS, void. Copies `name` into this+0x206; this[0x20b] = 0 when 0x5b1000(this[0x94]+0x50f, name) or the copy equals the string at this[0x94]+0x48;
// looks up the object ids for the name / its 3-character prefix through [table+0xae4] slot 0 (this[0x1b0] / this[0x1b4]); names equal to 0x6a7810 / 0x6a7818 only set this[0x20c] = 1.
// Otherwise: entity = table slot 0x58(this[0x1b8]) -> slot 0x20() -> slot 0x25c(name, 0) = this[0x1c8] (a node list), 0x574680 positions it, the list is scanned for the node named 0x6a94b8
// (its [+0x54] is kept) and, when found, this[0x44] slot 0x130(node[0x54], word of table slot 0x114(...)) is called and a placement matrix / vector is built (real helpers 0x4de7a0, 0x4db2c0,
// 0x4e09b0, 0x44c840, 0x4de040; 0x5b15d0 for names that are not the own one) and handed to node[0x54] slots 0x70 / 0x6c, or it is released with slot 0xbc(1). Missing node -> assert log.
// The locals keep the original frame layout (they overlap: the 12-byte vector at ebp-0x24 lies inside the matrix at ebp-0x48): ebp = fr + 0x68.
static void body_576a30(u8 *self, const char *name) {
  u8 fr[0x80];
  __builtin_memset(fr, 0xcc, sizeof fr);
#define EBP (fr + 0x68)
#define P(off) (EBP - (off))
  char *buf = (char *)(self + 0x206);
  W32(P(0x60), (u32)buf);
  {
    const char *s = name;
    char *d = buf;
    char c;
    do {
      c = *s++;
      *d++ = c;
    } while (c);
  }
  u8 *self94 = (u8 *)R32(self + 0x94);
  if ((u8)ext_5b1000(self94 + 0x50f, name) != 0 || streq(buf, (const char *)(self94 + 0x48))) self[0x20b] = 0;
  u8 *E = G(u8 *, 0x70039c);
  u8 *tbl = (u8 *)R32(E + 0x9b);
  u8 *X = (u8 *)R32(tbl + 0xae4);
  W32(self + 0x1b0, (*(V2 *)vt(X))(X, 0x6a930c, (u32)buf));
  {
    const char *s = buf;
    u8 *d = P(0xc);
    u8 c;
    do {
      c = (u8)*s++;
      *d++ = c;
    } while (c);
    *P(9) = c;
  }
  E = G(u8 *, 0x70039c);
  tbl = (u8 *)R32(E + 0x9b);
  X = (u8 *)R32(tbl + 0xae4);
  W32(self + 0x1b4, (*(V2 *)vt(X))(X, 0x6a925c, (u32)P(0xc)));
  if (streq(buf, (const char *)0x6a7810) || streq(buf, (const char *)0x6a7818)) {
    self[0x20c] = 1;
    return;
  }
  self[0x20c] = 0;
  E = G(u8 *, 0x70039c);
  tbl = (u8 *)R32(E + 0x9b);
  u8 *ent = (u8 *)(*(V1 *)(vt(tbl) + 0x58))(tbl, R32(self + 0x1b8));
  u8 *par = (u8 *)(*(V0 *)(vt(ent) + 0x20))(ent);
  u8 *list = (u8 *)(*(V2 *)(vt(par) + 0x25c))(par, (u32)buf, 0);
  W32(self + 0x1c8, (u32)list);
  E = G(u8 *, 0x70039c);
  u8 *O = (u8 *)(*(V0 *)(vt(E) + 0xbc))(E);
  u8 okf = (u8)(*(V0 *)(vt(O) + 0xdc))(O);
  float sv = okf ? cf(0x6a913c) : cf(0x67da0c);
  u32 svb;
  __builtin_memcpy(&svb, &sv, 4);
  ext_574680(self, R32(self + 0x1b8), R32(self + 0x1c8), svb, P(0x54), 0x42b40000);
  list = (u8 *)R32(self + 0x1c8);
  u8 *found = 0;
  W32(P(0x5c), R32(list + 8));
  while (R32(P(0x5c)) != 0) {
    u8 *node = (u8 *)R32(P(0x5c));
    u8 *prop = (u8 *)R32(node + 0x54);
    u32 nm = R32(prop + 4);
    const char *nstr = (const char *)(nm ? nm : 0x67c8e8);
    if (streq(nstr, (const char *)0x6a94b8)) found = prop;
    list = (u8 *)R32(self + 0x1c8);
    (*(V1p *)(vt(list) + 0x50))(list, P(0x5c));
  }
  if (!found) {
    u8 *L = G(u8 *, 0x700390);
    u8 *M = (u8 *)(*(V2 *)(vt(L) + 0x20))(L, 0x6a945c, 0x1b5);
    vt_log2(M, 0x2c, 0x6a94c0, (u32)buf);
    return;
  }
  u8 *edi = found;
  u8 *me = (u8 *)R32(self + 0x44);
  E = G(u8 *, 0x70039c);
  tbl = (u8 *)R32(E + 0x9b);
  u32 w = (u16)(*(u32(THISCALL **)(void *, u32, u32, u32, u32, u32))(vt(tbl) + 0x114))(tbl, 0x68fdd4, 0, 0x6a945c, 0x18f, 0);
  (*(V2 *)(vt(me) + 0x130))(me, (u32)edi, w);
  W32(P(0x10), 0);
  W32(P(0x14), 0);
  W32(P(0x18), 0);
  ext_4de7a0(P(0x48));
  self94 = (u8 *)R32(self + 0x94);
  bool pathA = false;
  const char *esi = buf;
  if (self94[0x103e] != 0) {
    esi = (const char *)R32(P(0x60));
  } else if (streq(buf, (const char *)(self94 + 0x48))) {
    pathA = true;
  }
  if (!pathA) {
    ext_5b15d0(self94 + 0xedb, esi, P(0x58), P(0x18), P(0x48));
    if (R32(P(0x58)) + 3 > 2) {
    } else {
      (*(V1 *)(vt(edi) + 0xbc))(edi, 1);
      return;
    }
  } else {
    u8 *o90 = (u8 *)R32(self + 0x90);
    u8 *po = (u8 *)(*(V0 *)(vt(o90) + 0x20))(o90);
    ext_4db2c0((void *)R32(po + 8), P(0x48), P(0x18));
  }
  W32(P(0x14), 0x42200000);
  (*(V1p *)(vt(edi) + 0x70))(edi, P(0x18));
  WF(P(0x24), RF(P(0x48)));
  WF(P(0x1c), RF(P(0x40)));
  W32(P(0x20), 0);
  ext_4e09b0(P(0x24));
  (void)ext_44c840(P(0x24));
  ext_4de040(P(0x48), P(0x24), 0);
  (*(V1p *)(vt(edi) + 0x6c))(edi, P(0x48));
}
extern "C" void THISCALL fn_576a30(u8 *self, const char *name);
extern "C" void THISCALL fn_576a30(u8 *self, const char *name) {
  body_576a30(self, name);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(576a30, fn_576a30);
