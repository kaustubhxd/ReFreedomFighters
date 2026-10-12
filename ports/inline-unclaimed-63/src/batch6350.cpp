// batch6350.cpp - unclaimed-63 gap-band batch 50: 0x4ceb60 (C-set; no GC name), thiscall, no stack arguments, plain ret.
//   buf = 0x41e290(0x100) (cdecl, original, stubbed). count = nodes after this[+4] (the walk starts at the head and counts the
//   links). logger 0x700390: lg->vtbl[+0x20](0x695b7c, 0x24b) -> log; log->vtbl[+0x2c](log, 0x695bfc, count) (cdecl).
//   For each node from this[+4]: cur = buf; for j < node[+8]: 0x6762d0(node value at vp, cur, 10) (cdecl, formats the value into cur);
//   cur += strlen(cur); vp += this[+0x18] * 4 (vp starts at node + 0x10). If node[+8] != 0: cur[-1] = 0.
//   Then logger 0x700390: lg->vtbl[+0x20](0x695b7c, 0x262) -> log2; log2->vtbl[+0x2c](log2, 0x695c18, node[+8], buf) (cdecl).
//   Finally 0x41e2c0(buf) (cdecl, original, stubbed).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);     // cdecl allocator, original code, stubbed by the spec
extern "C" void ext_41e2c0(u32 p);       // cdecl free, original code, stubbed by the spec

typedef char *(*fmt_fn)(u32, char *, u32);
typedef u32(THISCALL * log20_fn)(void *, u32, u32);
typedef void (*printf3_fn)(u32, u32, u32);
typedef void (*printf4_fn)(u32, u32, u32, u32);

// 0x4ceb60 (C-set).
static void THISCALL unnamed4ceb60(u8 *self) {
  u8 *buf = (u8 *)ext_41e290(0x100u);
  u32 count = 0;
  u32 e = *(u32 *)(self + 4);
  if (e != 0) {
    do {
      e = *(u32 *)(e + 4);
      count++;
    } while (e != 0);
  }
  u32 lg = G(u32, 0x700390);
  u32 l = ((log20_fn)(*(u32 *)(*(u32 *)lg + 0x20)))((void *)lg, 0x695b7cu, 0x24bu);
  ((printf3_fn)(*(u32 *)(*(u32 *)l + 0x2c)))(l, 0x695bfcu, count);
  u32 node = *(u32 *)(self + 4);
  while (node != 0) {
    char *cur = (char *)buf;
    u32 *vp = (u32 *)(node + 0x10);
    u32 n = *(u32 *)(node + 8);
    for (u32 j = 0; j < n; j++) {
      ((fmt_fn)G(u32, 0x6762d0))(*vp, cur, 10u);
      while (*cur != 0)
        cur++;
      vp = (u32 *)((u8 *)vp + *(u32 *)(self + 0x18) * 4u);
    }
    if (n != 0)
      cur[-1] = 0;
    u32 lg2 = G(u32, 0x700390);
    u32 l2 = ((log20_fn)(*(u32 *)(*(u32 *)lg2 + 0x20)))((void *)lg2, 0x695b7cu, 0x262u);
    ((printf4_fn)(*(u32 *)(*(u32 *)l2 + 0x2c)))(l2, 0x695c18u, *(u32 *)(node + 8), (u32)buf);
    node = *(u32 *)(node + 4);
  }
  ext_41e2c0((u32)buf);
}
PCREG(4ceb60, unnamed4ceb60);
