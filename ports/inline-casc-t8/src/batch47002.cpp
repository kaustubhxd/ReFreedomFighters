// batch47002.cpp - cascade t8 batch 47002: 0x61fbc0 (tier F row).
#include "ff.h"

typedef u32 (*cb3_t)(u32, u32, u32 *);
typedef u32 (*cb1_t)(u32);
typedef void (*cb1v_t)(u32);
typedef u32 (*cb4_t)(u32, u32 *, u32, u32);

// 0x61fbc0, cdecl(a, b), returns 0 / 1 / 0x12. A record of 0x100 dwords set to -1 followed by three out words {d, c, e} (all 0), passed to a[0x78](a[0xf8], b, rec) (cdecl);
// zero result, or a[0x78] == 0: cleanup (e(d) when e is set) and 0x12. Else a[0xf0] = a[0xc](0x778) (the constant of 0x626e00);
// zero: cleanup, return 1. Else r = (a[0xe8] ? 0x626d70 : 0x626b00)(a[0xf0], rec, c, d) (cdecl, 4 args); zero: cleanup, 0x12; else a[0xf4] = d, a[0x8c] = r, a[0xfc] = e, return 0.
static u32 fn61fbc0(u8 *a, u32 b) {
  cb3_t fn = *(cb3_t *)(a + 0x78);
  if (!fn) return 0x12;
  u32 rec[0x103];
  for (int i = 0; i < 0x100; i++) rec[i] = 0xffffffff;
  rec[0x100] = 0;  // d
  rec[0x101] = 0;  // c
  rec[0x102] = 0;  // e
  if (fn(*(u32 *)(a + 0xf8), b, rec)) {
    u32 h = (*(cb1_t *)(a + 0xc))(0x778);
    *(u32 *)(a + 0xf0) = h;
    if (!h) {
      if (rec[0x102]) ((cb1v_t)rec[0x102])(rec[0x100]);
      return 1;
    }
    cb4_t f2 = *(u32 *)(a + 0xe8) ? (cb4_t)0x626d70 : (cb4_t)0x626b00;
    u32 r = f2(h, rec, rec[0x101], rec[0x100]);
    if (r) {
      *(u32 *)(a + 0xf4) = rec[0x100];
      *(u32 *)(a + 0x8c) = r;
      *(u32 *)(a + 0xfc) = rec[0x102];
      return 0;
    }
  }
  if (rec[0x102]) ((cb1v_t)rec[0x102])(rec[0x100]);
  return 0x12;
}
PCREG(61fbc0, fn61fbc0);
