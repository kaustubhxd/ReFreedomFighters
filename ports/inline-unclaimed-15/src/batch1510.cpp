#include "ff.h"
// batch1510.cpp - unclaimed-15 claim 10 (docs/20-unclaimed-15.md): CExplodeMolotov::PlaySound(unsigned int, int) (0x584a20).
// Name from the name map (medium). Thiscall, two arguments, ret 8.
// Stubbed in the harness: the helper 0x43ec00 (thiscall, no stack args), the sub-object's slot +0x20 (six words) and the
// render manager's slot +0x60 (one word).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot6)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

extern "C" u32 THISCALL ext_43ec00(u8 *self);   // helper, stubbed in the harness

// 0x584a20, CExplodeMolotov::PlaySound(unsigned int, int) (medium).
static void THISCALL molotovPlaySound(u8 *self, u32 a1, u32 a2) {
  u8 *mgr = *(u8 **)0x70039c;
  if (*(u32 *)(mgr + 0x1a9f) == 0)
    return;
  if (a1 == 0)
    return;
  u8 *sub = *(u8 **)(self + 0x44);
  u32 edx = *(u32 *)(sub + 8);
  u32 r = ((Slot6)*(u32 *)(*(u32 *)sub + 0x20))(sub, edx, edx + 0x24, a1, 0, 0, 0);
  u32 r2 = ext_43ec00((u8 *)r);
  u8 *rm = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(rm + 0x9b);
  u32 p = ((Slot1)*(u32 *)(*(u32 *)obj + 0x60))(obj, r2);
  *(u32 *)(self + 0x36e) = p;
  if (!p)
    return;
  if ((s32)a2 != -1)
    *(float *)(p + 0x88) = (float)(s32)a2;
  *(u32 *)(*(u32 *)(self + 0x36e) + 0x40) &= ~0x4u;
}
PCREG(584a20, molotovPlaySound);
