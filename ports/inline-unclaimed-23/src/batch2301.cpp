// batch2301.cpp - unclaimed-23 batch 1 (docs/20-unclaimed-23.md): ZItem::Place(const float*, const float*) at 0x46ff20.
// Name from the GC name map (high). Calls: vtable slot +0x2dc on this (no arguments, returns X); if X is not null: a helper
// 0x4db2c0 on [X+8] (thiscall, two stack arguments), helpers 0x4dfd10, 0x4de420, 0x4de480, 0x4419f0 and 0x43e960 (fastcall,
// original code), and vtable slot +0x74 on this with two stack arguments. Frame layout kept as the PC has it (the four
// locals are contiguous, so a helper that writes past its own local lands on the same bytes). The /GS cookie check at the
// end (0x633654) is not reproduced: it only aborts on a corrupted frame. Callee pops 8 (ret 8).
#include "ff.h"

// Original helpers, bound by build.sh to their PC addresses.
extern "C" void THISCALL ext_4db2c0(void *self, void *a1, void *a2);   // thiscall, two stack arguments, original code
extern "C" void FASTCALL ext_4dfd10(void *ecx, void *edx);
extern "C" void FASTCALL ext_4de420(void *ecx, void *edx);
extern "C" void FASTCALL ext_4de480(void *ecx, void *edx);
extern "C" void FASTCALL ext_4419f0(void *ecx, void *edx);
extern "C" void FASTCALL ext_43e960(void *ecx, void *edx);

// 0x46ff20, ZItem::Place(const float*, const float*) (high). Frame: L4 = ebp-0x64, L3 = ebp-0x40, L2 = ebp-0x1c,
// L1 = ebp-0x10; the frame here is 0x64 bytes from L4, so L1 sits at offset 0x54. a1 is the output (edi), a2 is the input
// position copied into L1.
static void THISCALL itemPlace(u8 *self, u32 a1, u32 a2) {
  typedef u32(THISCALL * call0_fn)(void *);
  typedef void(THISCALL * call2_fn)(void *, void *, void *);
  u8 frame[0x64];
  u8 *L4 = frame;
  u8 *L3 = frame + 0x24;
  u8 *L2 = frame + 0x48;
  u8 *L1 = frame + 0x54;
  u32 x = ((call0_fn)(*(u32 *)(*(u32 *)self + 0x2dc)))(self);
  if (!x) return;
  ((u32 *)L1)[0] = ((u32 *)a2)[0];
  ((u32 *)L1)[1] = ((u32 *)a2)[1];
  ((u32 *)L1)[2] = ((u32 *)a2)[2];
  ext_4db2c0((void *)*(u32 *)(x + 8), L3, L2);
  ext_4dfd10(L4, L3);
  ext_4de420(L3, (void *)a1);
  ext_4de480(L4, L3);
  ext_4419f0(L2, L4);
  ext_43e960(L1, L2);
  ((call2_fn)(*(u32 *)(*(u32 *)self + 0x74)))(self, L4, L1);
}
PCREG(46ff20, itemPlace);
