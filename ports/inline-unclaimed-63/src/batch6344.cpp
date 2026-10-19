// batch6344.cpp - unclaimed-63 gap-band batch 44: 0x4d2f20 (C-set; no GC name), thiscall, two stack arguments s and n, ret 8.
//   If n == 0: n = strlen(s) + 1. O = this + 0x4008. O->vtbl[+0x4c](&local). node = O->vtbl[+0x5c](&local); if local == 0 return 0.
//   Loop: if [node] == n and 0x67640c(s, node + 0xc, n) == 0 (cdecl, caller cleans), return node.
//   Otherwise node = O->vtbl[+0x5c](&local); if local == 0 return 0; repeat.
#include "ff.h"

typedef void(THISCALL * arg1_fn)(void *, u32 *);
typedef u32(THISCALL * arg1r_fn)(void *, u32 *);
typedef int (*cmp_fn)(u32, u32, u32);

// 0x4d2f20 (C-set).
static u32 THISCALL unnamed4d2f20(u8 *self, u32 s, u32 n) {
  if (n == 0) {
    const u8 *p = (const u8 *)s;
    u32 len = 0;
    while (p[len] != 0)
      len++;
    n = len + 1;
  }
  u8 *o = self + 0x4008;
  u32 local[3];
  ((arg1_fn)(*(u32 *)(*(u32 *)o + 0x4c)))((void *)o, local);
  u32 node = ((arg1r_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, local);
  if (local[0] == 0)
    return 0;
  for (;;) {
    if (*(u32 *)node == n) {
      if (((cmp_fn)G(u32, 0x67640c))(s, node + 0xc, n) == 0)
        return node;
    }
    node = ((arg1r_fn)(*(u32 *)(*(u32 *)o + 0x5c)))((void *)o, local);
    if (local[0] == 0)
      return 0;
  }
}
PCREG(4d2f20, unnamed4d2f20);
