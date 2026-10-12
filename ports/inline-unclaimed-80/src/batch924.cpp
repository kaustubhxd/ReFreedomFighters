#include "ff.h"
// batch924.cpp - unclaimed-80 claim 4 (docs/20-unclaimed-80.md). ZFFMortar::Load(ZLoadGame*) (0x5dd3f0, high, vtable). Clears
// bit 0x40 at this+4; calls the global callback at 0x7003b0 (thiscall, no arguments; the exe faults if it is null, so the
// spec always sets it); calls 0x5dd4b0 (thiscall, one argument, original code, stubbed); then slot +0x68 of the load object
// for pointers this+0x48, +0x75, +0x76, +0x77, +0x78, +0x79 and slot +0x40 for this+0x7a. Returns true (al = 1).

extern "C" void THISCALL ext_5dd4b0(u8 *self, u32 arg);

static u8 THISCALL ffMortarLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  typedef void(THISCALL * cb_fn)(u8 *);
  cb_fn cb = (cb_fn)G(u32, 0x7003b0);
  cb(self);
  ext_5dd4b0(self, 0u);
  typedef void(THISCALL * slot_fn)(u8 *, u8 *);
  slot_fn f68 = *(slot_fn *)(*(u32 *)load + 0x68);
  f68(load, self + 0x48);
  f68 = *(slot_fn *)(*(u32 *)load + 0x68);
  f68(load, self + 0x75);
  f68 = *(slot_fn *)(*(u32 *)load + 0x68);
  f68(load, self + 0x76);
  f68 = *(slot_fn *)(*(u32 *)load + 0x68);
  f68(load, self + 0x77);
  f68 = *(slot_fn *)(*(u32 *)load + 0x68);
  f68(load, self + 0x78);
  f68 = *(slot_fn *)(*(u32 *)load + 0x68);
  f68(load, self + 0x79);
  slot_fn f40 = *(slot_fn *)(*(u32 *)load + 0x40);
  f40(load, self + 0x7a);
  return 1;
}
PCREG(5dd3f0, ffMortarLoad);
