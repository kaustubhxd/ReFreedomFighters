#include "ff.h"
// batch8023.cpp - unclaimed-79 unclaimed small rows (docs/20-unclaimed-79.md). Names GUESS (no GC name).

extern "C" void ext_634273(u8 *p, u32 n);   // cdecl heap free wrapper, stubbed in spec

// 0x499d20 (GUESS): thiscall (ret 4). Sets vtable 0x68e9cc, zeroes this+0xc; frees this (size 0x13c) when bit 0 of the argument is set.
static u8 *THISCALL f_499d20(u8 *self, u32 flags) {
  *(u32 *)self = 0x68e9cc;
  *(u32 *)(self + 0xc) = 0;
  if ((flags & 1) != 0) ext_634273(self, 0x13c);
  return self;
}
PCREG(499d20, f_499d20);

// 0x48f4d0 (GUESS): thiscall, no arguments, plain ret. Frees this+0xaec (size 0) when nonzero, zeroes it, then zeroes this+0xae8.
static void THISCALL f_48f4d0(u8 *self) {
  u32 p = *(u32 *)(self + 0xaec);
  if (p != 0) {
    ext_634273((u8 *)(unsigned long)p, 0);
    *(u32 *)(self + 0xaec) = 0;
  }
  *(u32 *)(self + 0xae8) = 0;
}
PCREG(48f4d0, f_48f4d0);

// 0x495920 (GUESS): thiscall, no arguments, plain ret. Frees this+4 (size 1) when nonzero, then calls slot 0 of the objects at
// this+0 and this+0x10 with 1 when nonzero (each callee pops 4).
static void THISCALL f_495920(u8 *self) {
  u32 p = *(u32 *)(self + 0x4);
  if (p != 0) ext_634273((u8 *)(unsigned long)p, 1);
  u8 *c = *(u8 **)self;
  if (c != 0) vcall<void, u32>(c, 0, 1u);
  u8 *d = *(u8 **)(self + 0x10);
  if (d != 0) vcall<void, u32>(d, 0, 1u);
}
PCREG(495920, f_495920);
