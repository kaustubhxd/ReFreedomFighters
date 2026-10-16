#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

// 0x625b30: cdecl(base, p): like 0x622bb0 with the byte roles swapped ([p+1] == 0 selects the class table lookup of [p])
extern "C" u32 fn_625b30(u8 *base, u8 *p) {
  u8 *cur = p;
  for (;;) {
    u32 c;
    u32 a = cur[1];
    if (a == 0) {
      c = base[0x4c + cur[0]];
    } else {
      u32 i = a - 0xd8;
      if (i > 0x27) {
        c = 0x1d;
      } else {
        static const u8 m1[40] = {0, 0, 0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2};
        switch (m1[i]) {
          case 0: c = 7; break;
          case 1: c = 8; break;
          case 2: c = cur[0] < 0xfe ? 0x1d : 0; break;
          default: c = 0x1d; break;
        }
      }
    }
    u32 v = c - 5;
    if (v > 0x18) break;
    static const u8 m2[25] = {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 3, 0};
    u32 m = m2[v];
    if (m == 3) break;
    static const u8 step[3] = {2, 3, 4};
    cur += step[m];
  }
  return (u32)(cur - p);
}
PCREG(625b30, fn_625b30);

// 0x469590: thiscall(this, sel, a, b) ret 0xc: sel 1, 2, 4, 8, 16, 32, 64 forwards to a vtable slot; always returns 0
u32 THISCALL fn_469590(u8 *self, u32 sel, u32 a, u32 b) {
  u32 i = sel - 1;
  if (i > 0x3f) return 0;
  static const u8 map[64] = {0, 1, 7, 2, 7, 7, 7, 3, 7, 7, 7, 7, 7, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 5,
                             7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6};
  u8 *vt = *(u8 **)self;
  switch (map[i]) {
    case 0: (*(V0 *)(vt + 8))(self); break;
    case 1: (*(V0 *)(vt + 0xc))(self); break;
    case 2: (*(V0 *)(vt + 0x4c))(self); break;
    case 3: (*(V0 *)(vt + 0x38))(self); break;
    case 4: (*(V0 *)(vt + 0x3c))(self); break;
    case 5: (*(V2 *)(vt + 0x44))(self, a, b); break;
    case 6: (*(V1 *)(vt + 0x40))(self, b != 0); break;
    default: break;
  }
  return 0;
}
PCREG(469590, fn_469590);
