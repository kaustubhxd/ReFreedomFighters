#include "ff.h"
// batch925.cpp - unclaimed-80 claim 5 (docs/20-unclaimed-80.md). GUESS FUN_5c39f0 (0x5c39f0, no name in the map). Thiscall, the
// argument is in ecx (esi), no stack arguments, void.
//   edi = (the global sub-object at 0x70039c+0x9b) slot +0x138 (no arguments)
//   if esi == 0, or slot +0x20 of the table object (global 0x70038c) returns nonzero: edi slot +0x60 (0x6adca0, 0, 0x10)
//   else if the table's fn at +8 is nonzero and lo(+0xc) <= esi < hi(+0x10) (unsigned): r = fn(esi) (thiscall, no
//        arguments); edi slot +0x60 (0x6adca0, r, 0x10)
//   else: if [esi-4] == 0, table slot +0xac with esi; then edi slot +0x60 (0x6adca0, [esi-4], 0x10).

static void THISCALL guessFun5c39f0(u8 *esi) {
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u8 *(THISCALL * r_fn)(u8 *);
  typedef u32(THISCALL * r0_fn)(u8 *);
  typedef void(THISCALL * c60_fn)(u8 *, u32, u32, u32);
  typedef void(THISCALL * arg1_fn)(u8 *, u32);
  u8 *edi = ((r_fn)(*(u32 *)(*(u32 *)sub + 0x138)))(sub);
  c60_fn c60 = (c60_fn)(*(u32 *)(*(u32 *)edi + 0x60));
  if (esi == 0) {
    c60(edi, 0x6adca0u, 0u, 0x10u);
    return;
  }
  u8 *t = G(u8 *, 0x70038c);
  u32 flag = ((r0_fn)(*(u32 *)(*(u32 *)t + 0x20)))(t);
  if (flag != 0) {
    c60(edi, 0x6adca0u, 0u, 0x10u);
    return;
  }
  t = G(u8 *, 0x70038c);
  u32 fn = *(u32 *)(t + 8);
  u32 lo = *(u32 *)(t + 0xc);
  u32 hi = *(u32 *)(t + 0x10);
  u32 p = (u32)esi;
  if (fn != 0 && !(lo > p) && !(p >= hi)) {
    u32 r = ((r0_fn)fn)(esi);
    c60(edi, 0x6adca0u, r, 0x10u);
    return;
  }
  if (*(u32 *)(esi - 4) == 0)
    ((arg1_fn)(*(u32 *)(*(u32 *)t + 0xac)))(t, p);
  c60(edi, 0x6adca0u, *(u32 *)(esi - 4), 0x10u);
}
PCREG(5c39f0, guessFun5c39f0);
