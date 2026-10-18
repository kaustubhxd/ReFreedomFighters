#include "ff.h"

typedef s32 (*Scan)(void *, u32, u32, u32 *);
extern "C" u32 ext_620cb0(u8 *s, void *obj, u32 p, u32 q);
extern "C" u32 ext_620d50(u8 *s, void *obj, u32 p, u32 q);
extern "C" u32 ext_620c00(u8 *s, void *obj, u32 p, u32 q);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

// 0x61f400: cdecl(s, p, end, out): drives a scanner callback (the function pointer stored in the first dword of the object s->[0x8c]) in a loop.
// The callback is called as cb(obj, p, end, &cur) and moves the cursor cur (initially the pointer s itself). Its result r selects (r + 15, bytemap at 0x61f56c):
// -15 finish (calls 0x620cb0 when s->[0x50] != 0, then *out = end, returns 0), -4 *out = end, return 0, -2 / -1 *out = p, return 0 (6 / 5 without out),
// 0 s->[0x118] = cur, return 4; 11 / 13 call 0x620d50 / 0x620c00 (0 -> return 1) and continue the scan from cur, 15 the same after an optional 0x620cb0;
// anything else (and r + 15 > 30) returns 9. s->[0x110] = 0x61f400, s->[0x118] = p / cur, s->[0x11c] = cur are the scan state.
extern "C" u32 fn_61f400(u8 *s, u32 p, u32 end, u32 *out) {
  static const u8 map[31] = {0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 1, 8, 2, 3, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 8, 6, 8, 7};
  u32 cur = (u32)s;
  wr32u(s + 0x110, 0x61f400);
  wr32u(s + 0x118, p);
  s32 r = (*(Scan *)rd32u(s + 0x8c))((void *)rd32u(s + 0x8c), p, end, &cur);
  wr32u(s + 0x11c, cur);
  for (;;) {
    u32 idx = (u32)r + 15;
    if (idx > 0x1e) return 9;
    switch (map[idx]) {
      case 0:
        if (rd32u(s + 0x50)) {
          wr32u(s + 0x11c, end);
          ext_620cb0(s, (void *)rd32u(s + 0x8c), p, end);
        }
        // fall through
      case 1:
        if (out) *out = end;
        return 0;
      case 2:
        if (!out) return 6;
        *out = p;
        return 0;
      case 3:
        if (!out) return 5;
        *out = p;
        return 0;
      case 4:
        wr32u(s + 0x118, cur);
        return 4;
      case 5:
        if (!ext_620d50(s, (void *)rd32u(s + 0x8c), p, cur)) return 1;
        break;
      case 6:
        if (!ext_620c00(s, (void *)rd32u(s + 0x8c), p, cur)) return 1;
        break;
      case 7:
        if (rd32u(s + 0x50)) ext_620cb0(s, (void *)rd32u(s + 0x8c), p, cur);
        break;
      default: return 9;
    }
    wr32u(s + 0x118, cur);
    p = cur;
    r = (*(Scan *)rd32u(s + 0x8c))((void *)rd32u(s + 0x8c), p, end, &cur);
    wr32u(s + 0x11c, cur);
  }
}
PCREG(61f400, fn_61f400);
