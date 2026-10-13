// batch1138.cpp - collision thread, batch 1138 (hard-row lane, mid-size row, name GUESS): 0x55c5b0. Reads list entries of the
// argument's list at [arg+4] (indices 2, 1, 0 through 0x5003d0) and branches on the type field [list+8] and on byte 4 of entry
// 1. Logger path (other types): the log stream from 0x700390 slot 0x20 and its slot 0x2c (cdecl), then the hook at 0x7003b0.
// Ends with the render manager's slot 0x114 (five arguments; the fifth points at a local dword) and slot 0x134 of [this+0x1c].
// The stack frame is not reproduced (the exe's frame has no exception handler here).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 idx);   // exe: bounded accessor, ret 4

typedef void (*CdeclLog)(void *, u32, u32);   // (stream, tag, tag): cdecl
typedef void (*CdeclVoid)(void);

// The logger path of 0x55c5b0 (log 0x69c8e0 / 0x111 through the logger, then (0x69c6b0, 0x69c9b0) through its stream, then hook).
static void logAndHook55c5b0(void) {
  void *S = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0u, 0x111u);
  CdeclLog f = (CdeclLog)((*(void ***)S)[0x2c / 4]);
  f(S, 0x69c6b0u, 0x69c9b0u);
  CdeclVoid h = (CdeclVoid)G(void *, 0x7003b0);
  if (h) h();
}

// 0x55c5b0 (name GUESS): thiscall (ECX = this), one stack argument arg, ret 4.
static void THISCALL run55c5b0(u8 *self, u8 *arg) {
  u8 *L = *(u8 **)(arg + 4);
  u32 V = *(u32 *)ext_5003d0(L, 2);
  u32 t = *(u32 *)(L + 8);
  if (t == 4) {
    ext_5003d0(L, 3);
  } else if (t != 3) {
    CdeclVoid h = (CdeclVoid)G(void *, 0x7003b0);
    if (h) h();
  }
  u8 *e1 = (u8 *)ext_5003d0(L, 1);
  u32 bt = e1[4];
  if (bt == 4) {
    vcall<void>(*(void **)e1, 0x34);
  } else if (bt != 3) {
    logAndHook55c5b0();
  }
  e1 = (u8 *)ext_5003d0(L, 1);
  bt = e1[4];
  u32 ebx;
  if (bt == 3) {
    ebx = *(u32 *)e1;
  } else if (bt == 4) {
    ebx = vcall<u32>(*(void **)e1, 0x34);
  } else {
    logAndHook55c5b0();
    ebx = 0;
  }
  u8 *e0 = (u8 *)ext_5003d0(L, 0);
  void *O = *(void **)(self + 0x1c);
  void *rm = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  u16 w = (u16)vcall<u32>(rm, 0x114, ebx, 0u, 0x6a5eb0u, 0x29au, (u32)&V);
  vcall<void>(O, 0x134, *(u32 *)e0, (u32)w);
}
PCREG(55c5b0, run55c5b0);
