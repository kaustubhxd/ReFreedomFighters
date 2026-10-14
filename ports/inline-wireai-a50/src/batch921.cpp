// batch921.cpp - residue-9 slice, two bodies read in full.
//  0x499c50 [thiscall (ECX = this), one stack arg (a), ret 4, returns this]: r = manager(g+0x9b) slot +0x4c (a); this's slot +0x3c (r).
//  0x5fa090 [thiscall (ECX = this), one stack arg (index), ret 4, returns the dword that the entry at index points to]: the table is at
//           this+4 (count at +0x14, entries array at +0xc). If index >= count, the engine hook at 0x7003b0 is called (if it is set) with
//           ECX = this and no arguments. Then the entry's dword is returned.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x499c50 (no name in the map).
static u8 *THISCALL Init499c50(u8 *self, u32 a) {
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u32 r = vcall<u32>(mgr, 0x4c, a);
  vcall<void>(self, 0x3c, r);
  return self;
}
PCREG(499c50, Init499c50);

// 0x5fa090 (no name in the map).
static u32 THISCALL Entry5fa090(u8 *self, u32 idx) {
  u8 *t = (u8 *)FP(self, 4);
  if (idx >= U32(t, 0x14)) {
    typedef void(THISCALL * hook_t)(void *);
    hook_t hook = (hook_t)G(u32, 0x7003b0);
    if (hook) hook(self);
    else asm volatile("int3");   // the exe jumps to an int3 when the hook is null (the same trap)
  }
  u8 *p = (u8 *)FP(t, 0xc);
  return *(u32 *)(*(u8 **)((u8 *)p + idx * 4));
}
PCREG(5fa090, Entry5fa090);
