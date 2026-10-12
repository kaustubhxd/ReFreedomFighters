// batch6332.cpp - unclaimed-63 gap-band batch 32: one list search over a virtual iterator that returns the node (band 0x4c1000-0x4e1000).
//   0x4ce0c0 (C-set; no GC name): thiscall, one stack argument target, ret 4. If this is null, return 0. vtbl[+0x4c](&local);
//     v = vtbl[+0x64](&local); if v == 0 return 0. Loop: if [v] == target return v (the node pointer, not its contents).
//     Else v = vtbl[+0x64](&local); if v != 0 repeat; else return 0.
// The &local argument is a stack address (the stubs do not record it).
#include "ff.h"

typedef u32(THISCALL * call1_fn)(void *, u32 *);
typedef void(THISCALL * call1v_fn)(void *, u32 *);

// 0x4ce0c0 (C-set): node pointer if found, else 0.
static u32 THISCALL unnamed4ce0c0(u8 *self, u32 target) {
  if (self == 0)
    return 0;
  u32 local = 0;
  ((call1v_fn)(*(u32 *)(*(u32 *)self + 0x4c)))((void *)self, &local);
  u32 v = ((call1_fn)(*(u32 *)(*(u32 *)self + 0x64)))((void *)self, &local);
  if (v == 0)
    return 0;
  while (*(u32 *)v != target) {
    v = ((call1_fn)(*(u32 *)(*(u32 *)self + 0x64)))((void *)self, &local);
    if (v == 0)
      return 0;
  }
  return v;
}
PCREG(4ce0c0, unnamed4ce0c0);
