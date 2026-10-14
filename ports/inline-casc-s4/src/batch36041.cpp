// batch36041.cpp - cascade s4 batch 36041: 0x6019b0, 0x62da60, 0x427020, 0x628b40, 0x620c00 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32 (*cmp_t)(u32, u32);
typedef u32(STDCALL *fl_t)(u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x6019b0, thiscall(name) ret 4 returns eax (this = d): for i < d[0xc]: rec = *d[4][i]; rec[0] != 0 -> skip; _stricmp(rec[0xc], name) == 0 -> return sys[0x9b]->slot 0x58(rec[4]). Not found: 0.
static u32 THISCALL fn6019b0(u8 *d, u32 name) {
  u32 i = 0;
  if (rd(d + 0xc) == 0) return 0;
  do {
    u8 *p1 = *(u8 **)(*(u8 **)(d + 4) + i * 4);
    u8 *rec = *(u8 **)p1;
    if (rd(rec) == 0) {
      u8 *r2 = **(u8 ***)(*(u8 **)(d + 4) + i * 4);
      if (G(cmp_t, 0x676414)(rd(r2 + 0xc), name) == 0) {
        u8 *p2 = *(u8 **)(*(u8 **)(d + 4) + i * 4);
        u8 *r3 = *(u8 **)p2;
        u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        return (u32)(*(v1o_t **)tab)[0x58 / 4](tab, rd(r3 + 4));
      }
    }
    i++;
  } while (i < rd(d + 0xc));
  return 0;
}
PCREG(6019b0, fn6019b0);

typedef u32 (*cb4_t)(u8 *, u32, u32, u32);

// 0x62da60, cdecl(p, code, a, b, obj) returns eax: code 0xf -> 0. code 0x12: cb = obj[0x1c]; cb(obj, a, b, 0x6c0208) -> *p = 0x62db60, return 0; cb(obj, a, b, 0x6c01f4) -> *p = 0x62db10, return 0.
// code 0x1b: *p = 0x62cf90, return 0x10. Otherwise (and after the failed 0x12 callbacks): p[3] == 0 and code == 0x1c -> return 0x34; else *p = 0x51f230, return -1.
static s32 fn62da60(u8 *p, u32 code, u32 a, u32 b, u8 *obj) {
  if (code == 0xf) return 0;
  if (code == 0x12) {
    cb4_t cb = *(cb4_t *)(obj + 0x1c);
    if (cb(obj, a, b, 0x6c0208u)) {
      wr(p, 0x62db60);
      return 0;
    }
    cb = *(cb4_t *)(obj + 0x1c);
    if (cb(obj, a, b, 0x6c01f4u)) {
      wr(p, 0x62db10);
      return 0;
    }
  } else if (code == 0x1b) {
    wr(p, 0x62cf90);
    return (s32)code - 0x11;
  }
  if (rd(p + 0xc) == 0 && code == 0x1c) return (s32)code + 0x18;
  wr(p, 0x51f230);
  return -1;
}
PCREG(62da60, fn62da60);

extern "C" void ext_634273(u32 a, u32 b);   // cdecl

// 0x427020, thiscall(key) ret 4 returns al (this = d): iterate l = d[0x10c] (slot 0x4c(&it), e = slot 0x64(&it) until 0): find e[4] == key; e[8]--; != 0 -> 0.
// else e[0xc] and e[0x10] (when set): slot 0x14(1); ext_634273(e[0], 1); l->slot 0x44(&it) (remove); FreeLibrary(key); return 1.
static u8 THISCALL fn427020(u8 *d, u32 key) {
  u8 *l = *(u8 **)(d + 0x10c);
  if (!l) return 0;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(d + 0x10c);
  u8 *e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  if (!e) return 0;
  while (key != rd(e + 4)) {
    l = *(u8 **)(d + 0x10c);
    e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
    if (!e) return 0;
  }
  wr(e + 8, rd(e + 8) - 1);
  if (rd(e + 8) != 0) return 0;
  u8 *o = *(u8 **)(e + 0xc);
  if (o) (*(v1_t **)o)[0x14 / 4](o, 1);
  o = *(u8 **)(e + 0x10);
  if (o) (*(v1_t **)o)[0x14 / 4](o, 1);
  ext_634273(rd(e), 1);
  l = *(u8 **)(d + 0x10c);
  (*(v1_t **)l)[0x44 / 4](l, (u32)it);
  G(fl_t, 0x6760b0)(key);
  return 1;
}
PCREG(427020, fn427020);

typedef void (*cb5_t)(u8 *, u32 *, u32, u8 **, u8 *);
extern "C" u32 ext_62c5b0(u8 *buf, u32 s);   // cdecl
extern "C" s32 ext_628c10(u8 *buf);          // cdecl

// 0x628b40, cdecl(obj, b, c) returns eax: l88 = b; buf (0x84 bytes), l8c = buf; obj[0x3c](obj, &l88, c, &l8c, &l5); l88 != c -> 0. *l8c = 0;
// 0x62c5b0(buf, 0x6bfe40) != 0 and obj[0x44] == 2 -> return obj. idx = 0x628c10(buf); idx == -1 -> 0; return table[idx] at 0x6f4424.
static u32 fn628b40(u8 *obj, u32 b, u32 c) {
  u32 l88 = b;
  u8 buf[0x84];
  u8 *l8c = buf;
  u8 l5;
  (*(cb5_t *)(obj + 0x3c))(obj, &l88, c, &l8c, &l5);
  if (l88 != c) return 0;
  *l8c = 0;
  if (ext_62c5b0(buf, 0x6bfe40u) != 0 && rd(obj + 0x44) == 2) return (u32)obj;
  s32 idx = ext_628c10(buf);
  if (idx == -1) return 0;
  return ((u32 *)0x6f4424)[idx];
}
PCREG(628b40, fn628b40);

extern "C" void ext_620cb0(u8 *a, u8 *b, u32 c, u32 d);   // cdecl
extern "C" u32 ext_620180(u8 *e, u8 *b, u32 c, u32 d);    // cdecl
extern "C" u32 ext_6206e0(u8 *e);                         // cdecl
extern "C" void ext_6200d0(u32 s);                        // cdecl
extern "C" void ext_6204a0(u8 *e);                        // cdecl
typedef void (*cb2_t)(u32, u32);

// 0x620c00, cdecl(a, b, c, d) returns eax: a[0x44] == 0: a[0x50] -> 0x620cb0(a, b, c, d); return 1. Else e = a + 0x22c, k = b[0x44]: 0x620180(e, b, c + k * 4, d - k * 3) zero -> 0;
// e[0xc] == e[8] and 0x6206e0(e) zero -> 0. *e[0xc] = 0; e[0xc]++; s = e[0x10] zero -> 0; 0x6200d0(s); a[0x44](a[4], s); 0x6204a0(e); return 1.
static u32 fn620c00(u8 *a, u8 *b, u32 c, u32 d) {
  if (rd(a + 0x44) == 0) {
    if (rd(a + 0x50)) ext_620cb0(a, b, c, d);
    return 1;
  }
  u8 *e = a + 0x22c;
  u32 k = rd(b + 0x44);
  if (!ext_620180(e, b, c + k * 4, d - k * 3)) return 0;
  if (rd(e + 0xc) == rd(e + 8)) {
    if (!ext_6206e0(e)) return 0;
  }
  **(u8 **)(e + 0xc) = 0;
  wr(e + 0xc, rd(e + 0xc) + 1);
  u32 s = rd(e + 0x10);
  if (!s) return 0;
  ext_6200d0(s);
  (*(cb2_t *)(a + 0x44))(rd(a + 4), s);
  ext_6204a0(e);
  return 1;
}
PCREG(620c00, fn620c00);
