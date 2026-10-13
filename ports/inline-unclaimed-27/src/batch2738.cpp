#include "ff.h"
// batch2738.cpp - unclaimed-27 batch 40 (docs/20-unclaimed-27.md). FUN_59ac70, name unknown (GUESS). SEH frame not reproduced (tagged).
// Callees are hooked in the spec (stubs, NOT verified): slot +0x1a8 of G, slot +0 of the two sub-objects, 0x4cd0e0, slot +0x34 of the engine.
extern "C" void THISCALL ext_4cd0e0(u8 *self);

typedef void(THISCALL * slot1a8_fn)(u8 *, u32);
typedef void(THISCALL * slot0_fn)(u8 *, u32);
typedef void(THISCALL * slot34_fn)(u8 *, u32);

// 0x59ac70 (GUESS): thiscall, no arguments, void.
static void THISCALL funcTeardown(u8 *self) {
  u32 a = *(u32 *)(self + 0x1054);
  *(u32 *)(self + 0) = 0x6adae0u;
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  ((slot1a8_fn)(*(u32 *)(*(u32 *)g + 0x1a8)))(g, a);
  if (a != 0) ((slot0_fn)(*(u32 *)(*(u32 *)(u8 *)(unsigned long)a + 0)))((u8 *)(unsigned long)a, 1u);

  u32 b = *(u32 *)(self + 0x1058);
  g = (u8 *)(unsigned long)G(u32, 0x70039c);
  ((slot1a8_fn)(*(u32 *)(*(u32 *)g + 0x1a8)))(g, b);
  if (b != 0) ((slot0_fn)(*(u32 *)(*(u32 *)(u8 *)(unsigned long)b + 0)))((u8 *)(unsigned long)b, 1u);

  ext_4cd0e0(self + 0x131f0);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0) = 0x686874u;

  g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  ((slot34_fn)(*(u32 *)(*(u32 *)eng + 0x34)))(eng, (u32)(unsigned long)self);
}
PCREG(59ac70, funcTeardown);
