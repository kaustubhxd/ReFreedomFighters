// batch38097.cpp - cascade s8 batch 38097: 0x4b00e0 (resolve an object by key: through a node list, an alias key, a name match among the owner's list and the owner's flag chain).
#include "ff.h"

extern "C" u8 THISCALL ext_4db9a0(u8 *o, u32 flags);   // ret 4 -> bool
extern "C" u8 *THISCALL ext_4dc130(u8 *o);
extern "C" u8 *THISCALL ext_4db520(u8 *o);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef int (*stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define U(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define DEFNAME ((const char *)0x67c8e8)

static u32 tbl(u32 slot, u32 arg) {
  u8 *t = *(u8 **)(SYS + 0x9b);
  return SLOT(t, slot, v1_t)(t, arg);
}
static const char *name_of(u8 *o) {
  const char *n = (const char *)U(*(u8 **)(o + 0x54), 4);
  return n ? n : DEFNAME;
}

// 0x4b00e0, thiscall(list, key) ret 8 -> object. this+0x4c = owner with a name list at +0x18 (begin 0x4c / next 0x5c).
static u8 *THISCALL fn4b00e0(u8 *self, u8 *list, u32 key) {
  u8 *R = 0;
  u32 it[4];
  if (list) {
    SLOT(list, 0x4c, v1_t)(list, (u32)it);
    u8 *n = (u8 *)SLOT(list, 0x64, v1_t)(list, (u32)it);
    while (n) {
      if (key == U(n, 0xc)) {
        R = (u8 *)tbl(0x54, U(n, 0));
        if (R) break;
      }
      n = (u8 *)SLOT(list, 0x64, v1_t)(list, (u32)it);
    }
  }
  u8 *o2 = (u8 *)tbl(0x54, key);
  if (!R) {
    if (o2) {
      u32 key2 = U(o2, 0x50);
      if (!list) {
        R = o2;
      } else {
        u32 it2[4];
        SLOT(list, 0x4c, v1_t)(list, (u32)it2);
        u8 *b = (u8 *)SLOT(list, 0x64, v1_t)(list, (u32)it2);
        while (b) {
          if (tbl(0x50, key2) == U(b, 0xc)) {
            u8 *x = (u8 *)tbl(0x58, U(b, 0));
            R = (u8 *)U(x, 0x50);
            if (R) break;
          }
          b = (u8 *)SLOT(list, 0x64, v1_t)(list, (u32)it2);
        }
        if (!R) R = o2;
      }
    }
  }
  u8 *M = (u8 *)U(self, 0x4c);
  if (M) {
    if (!R) return 0;
    if ((U(R, 0x3c) >> 10) & 1) {
      u8 *L2 = (u8 *)U(M, 0x18);
      if (L2) {
        u32 it3[4];
        SLOT(L2, 0x4c, v1_t)(L2, (u32)it3);
        L2 = (u8 *)U(*(u8 **)(self + 0x4c), 0x18);
        u32 e = SLOT(L2, 0x5c, v1_t)(L2, (u32)it3);
        while (it3[0] != 0) {
          u8 *ob = (u8 *)tbl(0x54, e);
          if (ob && imp_stricmp(name_of(R), name_of(ob)) == 0) {
            R = ob;
            break;
          }
          if (ext_4db9a0(R, 0x200006)) {
            const char *nb = name_of(ob);
            u8 *q = ext_4dc130(R);
            const char *nq = (const char *)U(q, 4);
            if (imp_stricmp(nq ? nq : DEFNAME, nb) == 0) {
              R = ob;
              break;
            }
          }
          L2 = (u8 *)U(*(u8 **)(self + 0x4c), 0x18);
          e = SLOT(L2, 0x5c, v1_t)(L2, (u32)it3);
        }
      }
    }
  }
  if (!R) return 0;
  if (!ext_4db9a0(R, 0x100001)) return R;
  u8 *s = *(u8 **)(*(u8 **)(R + 0x54) + 0x54);
  for (;;) {
    if (!s) return R;
    u8 *f = *(u8 **)(s + 0x54);
    u32 fl = f ? UN32(*(u8 **)(f + 0xc), 0x23) : 0x200002;
    if (fl & 0x100000) return R;
    if (ext_4db9a0(s, 0x200027)) return s;
    s = ext_4db520(s);
  }
}
PCREG(4b00e0, fn4b00e0);
