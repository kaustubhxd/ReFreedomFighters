// batch49002.cpp - cascade u2 batch 49002: 0x41e340 (add a count to the named bucket entry found through an iterator, spread over a histogram).
#include "ff.h"

typedef void(THISCALL *vi1_t)(void *, void *);
typedef u8 *(THISCALL *vn_t)(void *, void *);
typedef int (*cmp_t)(const char *, const char *);

// 0x41e340, thiscall(name, b, c) ret 0xc: finds the entry whose name (dword [entry]) matches through the import at 0x676414 (returns 0 on match);
// entry: +8 total, +0xc bins (u32 array), +0x10 bin size. total += c; bins covering [b, b+c) get their share (the first bin up to its end,
// whole bins add the bin size, the last bin the remainder).
static void THISCALL fn41e340(u8 *self, u8 *name, u32 b, u32 c) {
  u8 *o = *(u8 **)(self + 0x20);
  if (!o) return;
  u32 it[5];
  (*(vi1_t **)o)[0x4c / 4](o, it);
  o = *(u8 **)(self + 0x20);
  u8 *ent = (*(vn_t **)o)[0x64 / 4](o, it);
  while (ent) {
    if (G(cmp_t, 0x676414)(*(const char **)ent, (const char *)name) == 0) break;
    o = *(u8 **)(self + 0x20);
    ent = (*(vn_t **)o)[0x64 / 4](o, it);
  }
  if (!ent) return;
  *(u32 *)(ent + 8) += c;
  u32 size = *(u32 *)(ent + 0x10);
  u32 q1 = b / size;
  u32 e2 = (c + b) / size;
  if (q1 == e2) {
    (*(u32 **)(ent + 0xc))[q1] += c;
    return;
  }
  u32 *arr = *(u32 **)(ent + 0xc);
  u32 bound = size * (q1 + 1);
  arr[q1] += bound - b;
  u32 rem = b - size * e2 + c;
  if (rem) (*(u32 **)(ent + 0xc))[e2] += rem;
  for (u32 j = q1 + 1; j < e2; j++) (*(u32 **)(ent + 0xc))[j] += *(u32 *)(ent + 0x10);
}
PCREG(41e340, fn41e340);
