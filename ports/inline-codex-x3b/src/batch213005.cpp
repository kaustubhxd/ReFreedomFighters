#include "ff.h"

typedef u32(THISCALL *Slot0)(void *);
typedef u32(THISCALL *Slot2)(void *, const char *, volatile u32 *);

// 0x592350: stdcall(sel) ret 4: sel 3..6 asks the engine object table for object [slot 0x138], then slot 0x88(str, &out); returns out
u32 STDCALL fn_592350(u32 sel) {
  u32 i = sel - 3;
  if (i > 3) return 0;
  static const u32 strs[4] = {0x6acfcc, 0x6acfdc, 0x6acfec, 0x6acffc};
  u8 *eng = G(u8 *, 0x70039c);
  void *tab = *(void **)(eng + 0x9b);
  void *o = (void *)(*(Slot0 *)(*(u8 **)tab + 0x138))(tab);
  volatile u32 out = 0;
  (*(Slot2 *)(*(u8 **)o + 0x88))(o, (const char *)strs[i], &out);
  return out;
}
PCREG(592350, fn_592350);

// 0x622bb0: cdecl(base, p): like 0x6228e0 with two-byte (0, code) and 0xd8..0xff lead bytes; returns bytes consumed
extern "C" u32 fn_622bb0(u8 *base, u8 *p) {
  u8 *cur = p;
  for (;;) {
    u32 c;
    u32 a = cur[0];
    if (a == 0) {
      c = base[0x4c + cur[1]];
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
          case 2: c = cur[1] < 0xfe ? 0x1d : 0; break;
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
PCREG(622bb0, fn_622bb0);
