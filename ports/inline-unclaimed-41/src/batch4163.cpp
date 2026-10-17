// batch4163.cpp - unclaimed-41 batch 52 (residue 0): 0x528c80 ZTank::Save undercarriage
// Thiscall, one stack argument s (ZSaveGame*), ret 4, returns al = 1
#include "ff.h"

extern "C" u32 THISCALL ext_516520(u8 *self, u8 *s);
extern "C" u32 THISCALL ext_529fa0(u8 *self, u8 *s);
extern "C" u32 THISCALL ext_516e20(u8 *self, u8 *s);

typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * ff_t)(u8 *, float);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static u8 THISCALL fn528c80(u8 *self, u8 *s) {
  // First call: vt[0x68](s, this)
  ((f1_t)vslot(s, 0x68))(s, (u32)self);

  // Slot calls for various field offsets
  // vt[0x68] for more pointer fields
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0xc));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x50));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0xf0));
  ((f1_t)vslot(s, 0x68))(s, (u32)(self + 0x200));

  // vt[0x70] for more fields
  ((f1_t)vslot(s, 0x70))(s, (u32)(self + 0x300));
  ((f1_t)vslot(s, 0x70))(s, (u32)(self + 0x500));
  ((f1_t)vslot(s, 0x70))(s, (u32)(self + 0x700));

  // vt[0x4c] for float fields
  ((ff_t)vslot(s, 0x4c))(s, *(float *)(self + 0x100));
  ((ff_t)vslot(s, 0x4c))(s, *(float *)(self + 0x120));
  ((ff_t)vslot(s, 0x4c))(s, *(float *)(self + 0x140));

  // vt[0x44] for dword field
  ((f1_t)vslot(s, 0x44))(s, *(u32 *)(self + 0x15));

  // vt[0x64] for dword field
  ((f1_t)vslot(s, 0x64))(s, *(u32 *)(self + 0x400));

  // vt[0x60] for byte field (avoid stack locals for first attempt)
  ((f1_t)vslot(s, 0x60))(s, (u32)(self + 0x450));

  // Loop 1: calls to 0x516520 (8 times, stride 0xde from this+0x95)
  for (int i = 0; i < 8; i++) {
    ext_516520(self + 0x95 + i * 0xde, s);
  }

  // Loop 2: calls to 0x529fa0 (8 times, stride 0x133 from this+0xe75)
  for (int i = 0; i < 8; i++) {
    ext_529fa0(self + 0xe75 + i * 0x133, s);
  }

  // Direct calls to 0x516e20
  ext_516e20(self + 0x21ce, s);
  ext_516e20(self + 0x2247, s);

  return 1;
}
PCREG(528c80, fn528c80);
