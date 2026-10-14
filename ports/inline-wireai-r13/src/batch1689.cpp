// batch1689.cpp - 0x476970 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, no stack arguments, plain ret. A count at
// this+0x5c: zero returns 0; byte at this+0x72 set: tail into vslot 0x28 of this (returns its eax); else two saturating
// allocations (n*4; 0x41e290 hooked, cdecl) stored at this+0x64 and this+0x68, this+0x60 = n, then manager slot 0x58(dword
// this+0x73): null returns 0; a null list (obj+0x50) returns obj; else for each node: store the node's value at
// this+0x64 + off, store this at value+0x6c, r = manager slot 0x4c(value), store r at this+0x68 + off, off += 4, next node
// via +0x60. Returns the last r. GUESS: the names and the slot numbers.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_41e290[];
typedef u32(*NewFn)(u32 size);

static u32 SatMul4(u32 n) {
  u64 p = (u64)n * 4u;
  return p > 0xffffffffull ? 0xffffffffu : (u32)p;
}

u32 THISCALL GUESS_476970(u8 *self) {
  u32 n = AT(u32, self, 0x5c);
  if (!n) return n;
  if (AT(u8, self, 0x72)) return vcall<u32>(self, 0x28);
  AT(u32, self, 0x64) = ((NewFn)(void *)ext_41e290)(SatMul4(n));
  AT(u32, self, 0x68) = ((NewFn)(void *)ext_41e290)(SatMul4(AT(u32, self, 0x5c)));
  AT(u32, self, 0x60) = AT(u32, self, 0x5c);
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u32 obj = vcall<u32>(mgr, 0x58, AT(u32, self, 0x73));
  if (!obj) return 0;
  u32 node = AT(u32, obj, 0x50);
  if (!node) return obj;
  u32 r = 0;
  u32 off = 0;
  do {
    u32 val = AT(u32, node, 0x54);
    AT(u32, AT(u8 *, self, 0x64), off) = val;
    AT(u32, val, 0x6c) = (u32)self;
    r = vcall<u32>(mgr, 0x4c, val);
    AT(u32, AT(u8 *, self, 0x68), off) = r;
    off += 4;
    node = AT(u32, node, 0x60);
  } while (node);
  return r;
}
PCREG(476970, GUESS_476970);
