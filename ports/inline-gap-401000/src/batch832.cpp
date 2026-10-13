// batch832.cpp - residue-00 batch 832 (docs/20-unclaimed-65.md): 0x5f0f00 (ZFFWindowCoordinator::TapMap), a thiscall with one stack argument
// (ret 4) that stores the argument at this+0x1f on its main path. Stack balance (checked from the exe): the slot 0x114 call pushes six words
// (the saved esi and five arguments) and its callee pops five (ret 0x14), leaving the saved esi; the slot 0x12c call pushes two words and pops
// eight; the final pop restores esi. So 0x114 takes five arguments and 0x12c takes two.
// Callees, all other claims, hooked by address in the spec (GUESS): 0x5f0d30 (thiscall, no arguments), 0x5f0cd0 (fastcall, edx = 0, no stack).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *F5)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);

extern "C" void THISCALL ext_5f0d30(u8 *self);            // thiscall, no arguments (hooked)
extern "C" void FASTCALL ext_5f0cd0(u8 *ecx, u32 edx);     // fastcall, no stack arguments (hooked)

static void THISCALL fn5f0f00(u8 *self, u32 arg) {
  if (*(const u8 *)self != 0) return;
  if (*(const u8 *)(self + 1) != 0) return;
  const u32 eax = *(const u32 *)(self + 0xb);
  if (eax == 0) return;
  const u32 ecx = *(const u32 *)(self + 3);
  if (ecx != 0) {
    if (ecx != eax && ecx != *(const u32 *)(self + 0xf)) return;
    ext_5f0cd0((u8 *)ecx, 0);
    return;
  }
  u8 *r9 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (u8 *)((F0)(*(const u32 *)(*(const u32 *)r9 + 0x138)))(r9);
  u32 local = 0;
  ((F2)(*(const u32 *)(*(const u32 *)obj + 0x88)))(obj, 0x6b2b90, (u32)&local);
  if (local != 0) {
    u8 *r9b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *q = *(u8 **)(r9b + 0xadc);
    const u32 vt = *(const u32 *)q;
    const u32 w = ((F5)(*(const u32 *)(*(const u32 *)r9b + 0x114)))(r9b, 0x6b2b60, 0, 0x6b82f4, 0x6b, 0) & 0xffff;
    u8 *q2 = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
    ((F2)(*(const u32 *)(vt + 0x12c)))(q2, local, w);
  }
  ext_5f0d30(*(u8 **)(self + 0xb));
  *(u32 *)(self + 0x1f) = arg;
}

PCREG(5f0f00, fn5f0f00);
