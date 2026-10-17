#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// Tagged byte stream: tag byte t (0xff = end), type = t & 0x3f (1..12 known), bit 6 = "attached" record. Payload size by type class: 0 -> 8, 1 -> 4, 2 -> cstring + NUL,
// 3 -> the u32 at p+1 (includes itself), 4 (type 6) and unknown types -> 0. The next record starts at p + 1 + size.
static u32 rec_size(const u8 *p) {
  static const u8 cls[12] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1, 3};
  u8 t = *p;
  u32 idx = (u32)(t & 0x3f) - 1;
  if (idx > 11) return 0;
  switch (cls[idx]) {
    case 0: return 8;
    case 1: return 4;
    case 2: {
      const u8 *q = p + 1;
      u32 n = 0;
      while (q[n]) n++;
      return n + 1;
    }
    case 3: return rd32u(p + 1);
    default: return 0;
  }
}

// 0x4e1620: thiscall(n) ret 4 -> bool, /GS. Moves the stream cursor [this+8] by n records. n < 0: walks forward collecting record starts (an attached record, bit 6, is
// skipped together with its owner) until a type-6 or end tag, then moves back -n records (fails when fewer were seen; the cursor stays at the end). n > 0: skips n records,
// failing at a type-6 or end tag. n == 0: nothing.
extern "C" u8 THISCALL fn_4e1620(u8 *self, int n);
static u8 THISCALL body_4e1620(u8 *self, int n) {
  u8 *p;
  if (n < 0) {
    u8 *starts[128];
    int cnt = 0;
    for (;;) {
      p = (u8 *)rd32u(self + 8);
      if (*p == 0xff || (*p & 0x3f) == 6) break;
      starts[cnt++] = p;
      for (;;) {
        p = p + 1 + rec_size(p);
        *(u8 **)(self + 8) = p;
        if (*p == 0xff || !((*p >> 6) & 1)) break;
      }
    }
    if (cnt < -n) return 0;
    *(u8 **)(self + 8) = starts[cnt + n];
    return 1;
  }
  while (n != 0) {
    p = (u8 *)rd32u(self + 8);
    n--;
    if (*p == 0xff || (*p & 0x3f) == 6) return 0;
    for (;;) {
      p = p + 1 + rec_size(p);
      *(u8 **)(self + 8) = p;
      if (*p == 0xff || !((*p >> 6) & 1)) break;
    }
  }
  return 1;
}
extern "C" u8 THISCALL fn_4e1620(u8 *self, int n) {
  u8 r = body_4e1620(self, n);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(4e1620, fn_4e1620);
