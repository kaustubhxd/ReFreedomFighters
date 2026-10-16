#include "ff.h"

typedef u32(THISCALL *V0)(void *);
extern "C" u32 ext_62c640(u32 a, u32 b);

static inline u32 rd32u(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x62d690: cdecl(a, b): parser step over b-0xf (a[1] is a repeat counter)
extern "C" u32 fn_62d690(u32 *a, int b) {
  u32 i = (u32)b - 0xf;
  if (i <= 0x17) {
    static const u8 map[24] = {0, 7, 7, 7, 7, 7, 1, 7, 7, 2, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 5, 6};
    switch (map[i]) {
      case 0: return 0;
      case 1: a[0] = 0x62d5c0; return 0x2c;
      case 2: if (--a[1] == 0) a[0] = 0x62cf90; return 0x28;
      case 3: if (--a[1] == 0) a[0] = 0x62cf90; return 0x2a;
      case 4: if (--a[1] == 0) a[0] = 0x62cf90; return 0x29;
      case 5: if (--a[1] == 0) a[0] = 0x62cf90; return 0x2b;
      case 6: a[0] = 0x62d5c0; return 0x2d;
      default: break;
    }
  }
  if (a[3] == 0 && b == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62d690, fn_62d690);

static inline u32 cls(u8 *base, u8 *p) {
  if (p[0] == 0) return base[0x4c + p[1]];
  return ext_62c640(p[0], p[1]);
}

// 0x622ef0: cdecl(base, p, end, st): like 0x622ad0 over (lead, code) byte pairs, class via table or 0x62c640.
// Returns the last class-derived value left in eax (p == end on entry leaves the caller's eax: not modelled, spec avoids it).
extern "C" u32 fn_622ef0(u8 *base, u8 *p, u8 *end, volatile s32 *st) {
  if (p == end) return 0;
  s32 col = st[1];
  u32 ret = 0;
  do {
    u32 c = cls(base, p) - 5;
    ret = c;
    if (c > 5) {
      p += 2;
    } else {
      switch (c) {
        case 1: p += 3; break;
        case 2: p += 4; break;
        case 4:
          st[0] = st[0] + 1;
          p += 2;
          if (p != end) {
            ret = cls(base, p);
            if (ret == 0xa) p += 2;
          }
          col = -1;
          st[1] = -1;
          break;
        case 5:
          col = -1;
          st[1] = -1;
          st[0] = st[0] + 1;
          p += 2;
          break;
        default: p += 2; break;
      }
    }
    col++;
    st[1] = col;
  } while (p != end);
  return ret;
}
PCREG(622ef0, fn_622ef0);

// 0x473e50: thiscall(this): picks a field of this by the kind of the object returned by slot 0x350 of this->[0x50c]()
u32 THISCALL fn_473e50(u8 *self) {
  u8 *s = (u8 *)(*(V0 *)(*(u8 **)self + 0x50c))(self);
  if (!s) return rd32u(self + 0x266);
  u8 *o = (u8 *)(*(V0 *)(*(u8 **)s + 0x350))(s);
  u32 k = (*(V0 *)(*(u8 **)o + 0x330))(o);
  if (k <= 0xb) {
    static const u8 map[12] = {0, 0, 1, 1, 1, 1, 1, 2, 4, 4, 4, 3};
    switch (map[k]) {
      case 0: {
        u8 *p = (u8 *)(*(V0 *)(*(u8 **)self + 0x508))(self);
        if (!p) break;
        u8 *e1 = (u8 *)(*(V0 *)(*(u8 **)p + 0x350))(p);
        u8 *e2 = (u8 *)(*(V0 *)(*(u8 **)s + 0x350))(s);
        u32 k2 = (*(V0 *)(*(u8 **)e2 + 0x330))(e2);
        u32 k1 = (*(V0 *)(*(u8 **)e1 + 0x330))(e1);
        if (k1 == k2) return rd32u(self + 0x2d7);
        break;
      }
      case 1: return rd32u(self + 0x2d3);
      case 2: return rd32u(self + 0x2df);
      case 3: return 0;
      default: break;
    }
  }
  return rd32u(self + 0x2db);
}
PCREG(473e50, fn_473e50);
