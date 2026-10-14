// batch890.cpp - area 50 (residue-09 candidate table row): 0x58a8d0 [89 table entry; ECX = this, EDX = an output array; no stack
// args; returns this; the exe's cookie check (0x633654) is not reproduced]. GUESS "Collect58a8d0": ask this for a count (vt +0x48),
// then for each of the count items: ask for a handle (vt +0x40), map it to a value through the manager (vt +0x58, manager at
// g+0x9b), read three small blocks from the item (vt +0x6c, +0x50, +0x50, +0x48, +0x50, +0x6c, +0x48), and append a 48-byte record to
// the output: the count dword at out+0, then the records at out+4 (three 16-byte copies with the blocks at 0x00, 0x10, 0x20).
// The local frame is kept at the exe's offsets: fr = ebp-0x3c, so ebp-X is fr+(0x3c-X).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x58a8d0 (name GUESS).
static u8 *FASTCALL Collect58a8d0(u8 *self, u32 *out) {
  u8 fr[0x3c];
  for (u32 i = 0; i < sizeof fr; i++) fr[i] = 0;
  s32 cnt;
  vcall<void>(self, 0x48, (void *)(fr + 4));                 // [ebp-0x38]: count
  cnt = *(s32 *)(fr + 4);
  for (s32 k = 0; k < cnt; k++) {
    vcall<void>(self, 0x40, (void *)(fr + 0));              // [ebp-0x3c]: handle
    u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
    *(u32 *)(fr + 8) = vcall<u32>(mgr, 0x58, *(u32 *)(fr + 0));   // [ebp-0x34]
    vcall<void>(self, 0x6c, (void *)(fr + 0x0c));           // [ebp-0x30]
    vcall<void>(self, 0x50, (void *)(fr + 0x18));           // [ebp-0x24]
    vcall<void>(self, 0x50, (void *)(fr + 0x1c));           // [ebp-0x20]
    vcall<void>(self, 0x48, (void *)(fr + 0x20));           // [ebp-0x1c]
    vcall<void>(self, 0x50, (void *)(fr + 0x24));           // [ebp-0x18]
    vcall<void>(self, 0x6c, (void *)(fr + 0x28));           // [ebp-0x14]
    vcall<void>(self, 0x48, (void *)(fr + 0x34));           // [ebp-8]
    u32 n = out[0];
    u8 *rec = (u8 *)out + 4 + 48 * n;
    for (u32 b = 0; b < 16; b++) rec[b] = fr[8 + b];
    for (u32 b = 0; b < 16; b++) rec[0x10 + b] = fr[0x18 + b];
    for (u32 b = 0; b < 16; b++) rec[0x20 + b] = fr[0x28 + b];
    out[0] = n + 1;
  }
  return self;
}
PCREG(58a8d0, Collect58a8d0);
