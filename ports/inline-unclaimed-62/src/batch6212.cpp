// batch6212.cpp - unclaimed-62 claim 5 (slice 1): 0x5dbed0 (no name in the name map) [thiscall, ret 4, returns al]. False when this+0x48 is null
// or no entry matches. For each entry of that list (begin +0x4c, next +0x5c): the message table's slot 0x58 turns the entry into an object m; a
// vector copy of the argument's three floats goes to m's slot 0x8c; then m's slot 0x180 (the vector, 0) decides: non-zero returns true.
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static u8 THISCALL fn5dbed0(u8 *self, u8 *arg) {
  u8 *list = rdp(self + 0x48);
  if (!list) return 0;
  u32 it[3];
  vcall<void>(list, 0x4c, it);
  u32 cur = vcall<u32>(list, 0x5c, it);
  while (it[0] != 0) {
    u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *m = (u8 *)vcall<u32>(msg, 0x58, cur);
    float v[3];
    __builtin_memcpy(&v[0], arg, 4);
    __builtin_memcpy(&v[1], arg + 4, 4);
    __builtin_memcpy(&v[2], arg + 8, 4);
    vcall<void>(m, 0x8c, v);
    if (vcall<u32>(m, 0x180, v, (u32)0) & 0xff) return 1;
    cur = vcall<u32>(rdp(self + 0x48), 0x5c, it);
  }
  return 0;
}
PCREG(5dbed0, fn5dbed0);
