// batch761.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

typedef u32(THISCALL *VtArg)(u8 *, u32);                           // one stack word; vt[0x4c] writes it, vt[0x5c] returns a node
typedef int(__attribute__((cdecl)) *Memcmp3)(const u8 *, const u8 *, u32);   // import pointer at 0x67640c (contract as stubbed)

// 0x4d2a90, thiscall(a, b) ret 8, returns bool (al). If b == 0, b = strlen(a) + 1. Embedded object at this+0x4008: its
// vt[0x4c](obj, &local) and vt[0x5c](obj, &local) walk nodes (node: dword length at +0, data at +0xc). A node whose length
// equals b and whose data matches (import 0x67640c returns 0, cdecl (a, node+0xc, b)) gives true. Name GUESS.
static bool THISCALL findNodeByLen_4d2a90(u8 *self, const u8 *a, u32 b) {
  if (b == 0) {
    u32 n = 0;
    while (a[n] != 0) ++n;
    b = n + 1;
  }
  u8 *edi = self + 0x4008;
  u32 local = 0;
  VtArg f4c = (VtArg)(*(u32 *)(*(u32 *)edi + 0x4c));
  f4c(edi, (u32)&local);
  VtArg f5c = (VtArg)(*(u32 *)(*(u32 *)edi + 0x5c));
  u8 *node = (u8 *)f5c(edi, (u32)&local);
  while (local != 0) {
    if (*(u32 *)node == b) {
      Memcmp3 mc = (Memcmp3)(*(u32 *)0x67640cu);
      int r = mc(a, node + 0xc, b);
      if (r == 0) return true;
    }
    node = (u8 *)f5c(edi, (u32)&local);
  }
  return false;
}
PCREG(4d2a90, findNodeByLen_4d2a90);
