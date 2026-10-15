// batch66076.cpp - cascade s4 batch 66076: 0x6490b0 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_64d030(void *self, u32 d, u32 rec, u32 a, u32 b);   // ret 0x10
extern "C" void THISCALL ext_63e850(void *self, u32 e);                         // ret 4
extern "C" void THISCALL ext_64c090(void *self, u32 s);                         // ret 4

// 0x6490b0, thiscall(masks, recs, n, d) ret 0x10, returns masks + (((2 * n + 0x7f) >> 5) & ~3) * 4 (this = t): the sibling of 0x648fb0 that does not compact the record array: now = sys[0x3c]; n <= 0 -> the return value only.
// For each block of up to 16 records (one mask dword each, two bits per record, bit 1 set skips): r = *recs++; s = t[0x10071][(u16)r[0x5a] & 0xfff]. s == 0 -> 0x64d030(t, d, r, 0, 0).
// Otherwise s[5] & 1 clear: e = s[8]; e[5] & 1 clear -> 0x63e850(t[0x1005d], e); 0x64c090(t, s). Then s[0x10] = now; s[0x18] = d[0x18]; d[0x18] = s.
static u32 THISCALL fn6490b0(u8 *t, u32 *masks, u32 *recs, s32 n, u8 *d) {
  u32 ret = (u32)masks + ((((u32)n * 2 + 0x7f) >> 5) & 0xfffffffcu) * 4;
  u32 now = rd(G(u8 *, 0x70039c) + 0x3c);
  if (n <= 0) return ret;
  do {
    u32 bits = *masks++;
    s32 cnt = n < 16 ? n : 16;
    n -= 16;
    for (; cnt; cnt--) {
      if (!(bits & 2)) {
        u8 *r = (u8 *)*recs;
        u32 idx = *(u16 *)(r + 0x5a) & 0xfff;
        u8 *s = ((u8 **)rd(t + 0x10071))[idx];
        if (!s) {
          ext_64d030(t, (u32)d, (u32)r, 0, 0);
        } else {
          if (!(s[5] & 1)) {
            u8 *e = *(u8 **)(s + 8);
            if (!(e[5] & 1)) ext_63e850(*(u8 **)(t + 0x1005d), (u32)e);
            ext_64c090(t, (u32)s);
          }
          wr(s + 0x10, now);
          wr(s + 0x18, rd(d + 0x18));
          wr(d + 0x18, (u32)s);
        }
      }
      recs++;
      bits >>= 2;
    }
  } while (n > 0);
  return ret;
}
PCREG(6490b0, fn6490b0);
