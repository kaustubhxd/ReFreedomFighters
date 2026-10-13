// batch812.cpp - core gameplay batch 812 (docs/20-unclaimed-65.md, batch 812), two residue-00 entries (core-todo/residue-00.txt):
// 0x4fc040 (CMAINCAMERACONTROL::CopyData): thiscall, one stack argument (the source), ret 4; copies the dword at +0x78, five words at
// +0x7c..+0x82 and the dword at +0x6e from the source into this. 0x522740 (ZTankIf::~ZTankIf): thiscall, one stack flag word, ret 4;
// sets the vtable to 0x6a06f4, calls 0x51aa60 (no arguments, ecx = this), and when bit 0 of the flag is set calls the CRT free 0x634273
// with size 0x20 (cdecl, the caller removes two words); returns this.
#include "ff.h"

extern "C" void THISCALL ext_51aa60(u8 *self);            // thiscall, no arguments (another claim; stubbed in the spec)
extern "C" void ext_634273(void *p, u32 size);            // cdecl CRT free (exe code, stubbed by the harness)

static void THISCALL fn4fc040(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x78) = *(const u32 *)(src + 0x78);
  *(u16 *)(self + 0x7c) = *(const u16 *)(src + 0x7c);
  *(u16 *)(self + 0x7e) = *(const u16 *)(src + 0x7e);
  *(u16 *)(self + 0x80) = *(const u16 *)(src + 0x80);
  *(u16 *)(self + 0x82) = *(const u16 *)(src + 0x82);
  *(u32 *)(self + 0x6e) = *(const u32 *)(src + 0x6e);
}

static u8 *THISCALL fn522740(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a06f4;
  ext_51aa60(self);
  if (flags & 1) ext_634273(self, 0x20);
  return self;
}

PCREG(4fc040, fn4fc040);
PCREG(522740, fn522740);
