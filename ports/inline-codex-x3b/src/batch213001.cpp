#include "ff.h"

extern "C" u32 THISCALL ext_5aeff0(void *self, u32 a);
extern "C" u32 THISCALL ext_5af130(void *self, u32 a);
extern "C" u32 THISCALL ext_5af1d0(void *self, u32 a);

// 0x5af2a0: thiscall(this, sel, val) ret 8: setter twin of 0x5af1d0; returns eax as left by the code
u32 THISCALL fn_5af2a0(u8 *self, int sel, u32 val) {
  u32 i = (u32)sel - 0xc;
  if (i > 4) return i;
  switch (i) {
    case 0: *(u32 *)(self + 0xc) = val; return val;
    case 1: *(u32 *)(self + 8) = val; return val;
    case 2: *(u32 *)self = val; return val;
    case 3: {
      u32 f = val != 0;
      *(u32 *)(self + 0x10) = f;
      return f;
    }
    default: *(u32 *)(self + 4) = val; return val;
  }
}
PCREG(5af2a0, fn_5af2a0);

// 0x5afc70: thiscall(this, a) ret 4: lookup via [this+0x14], dispatch on the id (-3 .. 0x10)
u32 THISCALL fn_5afc70(u8 *self, u32 a) {
  u32 r = ext_5aeff0(*(void **)(self + 0x14), a);
  u32 i = r - 3;
  if (i > 0xd) return 0;
  static const u8 map[14] = {0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 1, 1, 2, 1};
  switch (map[i]) {
    case 0: {
      u8 *e = (u8 *)ext_5af130(*(void **)(self + 0x14), r);
      return *(u32 *)(e + 0xc);
    }
    case 1: return ext_5af1d0(self, r);
    default: return 0;
  }
}
PCREG(5afc70, fn_5afc70);

// 0x622d20: cdecl(base, p): skips (0, code) pairs while class table base[0x4c + code] is 9, 10 or 0x15; returns p
extern "C" u8 *fn_622d20(u8 *base, u8 *p) {
  for (;;) {
    if (*p != 0) return p;
    u32 c = base[0x4c + p[1]];
    if (c < 9) return p;
    if (c > 10 && c != 0x15) return p;
    p += 2;
  }
}
PCREG(622d20, fn_622d20);

// 0x6228e0: cdecl(base, p): scan class table base[0x4c + byte], step by 2, 3, 4 or 1 per class; returns bytes consumed
extern "C" u32 fn_6228e0(u8 *base, u8 *p) {
  u8 *cur = p;
  static const u8 map[25] = {0, 1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 3};
  for (;;) {
    u32 v = (u32)base[0x4c + *cur] - 5;
    if (v > 0x18) break;
    u32 m = map[v];
    if (m == 4) break;
    static const u8 step[4] = {2, 3, 4, 1};
    cur += step[m];
  }
  return (u32)(cur - p);
}
PCREG(6228e0, fn_6228e0);
