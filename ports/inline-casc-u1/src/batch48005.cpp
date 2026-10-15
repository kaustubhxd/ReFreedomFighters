// batch48005.cpp - cascade tier H, batch 48005: 0x545ee0 (stream three record arrays of an object through an archive, logging one of them).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
typedef void (*log_fn)(void *obj, u32 fmt, s32 idx, double d, u32 a, u32 b);

// 0x545ee0, thiscall(ar) ret 4, returns true. ar slots: 0x48 (pointer), 0x50 (pointer), 0x6c (pointer); unaligned fields: +0xf array A (0x34-byte records, count [+0x28]), +0x13 array B (0xc-byte records, count [+0x2c]), +0x17 array C (0xc-byte, count [+0x30]).
// ar->0x48(this+0x28); for each A record p: ar->0x6c(p+0xc), (p), (p+0x18), (p+0x24); ar->0x48(this+0x2c); for each B record p: log = [0x700390]->slot0x20(0x6a2e20, 0xb6c); log->slot0x2c (cdecl: log, 0x6a2eac, i, (double)[p+8], [p], [p+4]);
// ar->0x50(p+8), 0x48(p), 0x48(p+4); ar->0x48(this+0x30); for each C record p: ar->0x50(p+8), 0x48(p), 0x48(p+4).
static bool THISCALL fn545ee0(u8 *self, u8 *ar) {
  vcall<void>(ar, 0x48, (u32)(self + 0x28));
  u8 *p = (u8 *)rd32(self + 0xf);
  for (s32 i = 0; i < *(s32 *)(self + 0x28); i++) {
    vcall<void>(ar, 0x6c, (u32)(p + 0xc));
    vcall<void>(ar, 0x6c, (u32)p);
    vcall<void>(ar, 0x6c, (u32)(p + 0x18));
    vcall<void>(ar, 0x6c, (u32)(p + 0x24));
    p += 0x34;
  }
  vcall<void>(ar, 0x48, (u32)(self + 0x2c));
  u8 *cur = (u8 *)rd32(self + 0x13);
  for (s32 i = 0; i < *(s32 *)(self + 0x2c); i++) {
    u8 *lo = G(u8 *, 0x700390);
    u8 *lg = vcall<u8 *>(lo, 0x20, 0x6a2e20u, 0xb6cu);
    log_fn f = *(log_fn *)(*(u8 **)lg + 0x2c);
    f(lg, 0x6a2eac, i, (double)bitsf(rd32(cur + 8)), *(u32 *)cur, rd32(cur + 4));
    vcall<void>(ar, 0x50, (u32)(cur + 8));
    vcall<void>(ar, 0x48, (u32)cur);
    vcall<void>(ar, 0x48, (u32)(cur + 4));
    cur += 0xc;
  }
  vcall<void>(ar, 0x48, (u32)(self + 0x30));
  p = (u8 *)rd32(self + 0x17);
  for (s32 i = 0; i < *(s32 *)(self + 0x30); i++) {
    vcall<void>(ar, 0x50, (u32)(p + 8));
    vcall<void>(ar, 0x48, (u32)p);
    vcall<void>(ar, 0x48, (u32)(p + 4));
    p += 0xc;
  }
  return true;
}
PCREG(545ee0, fn545ee0);
