#include "ff.h"
// batch3523.cpp - area 35 claim 23 (docs/20-unclaimed-35.md): 0x4fd020, CMAINCAMERACONTROL::Load(ZLoadGame*) (residue name).
// Thiscall, one stack arg (the loader); returns al = 1. The exe's pushes are noted per call (the first pushed is the last arg).
// Stubbed in the harness: the loader's vtable slots (logging), the global's vtable slot +0xc (logging, three args), 0x4fd5d0.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a0, u32 a1);
typedef u32(THISCALL *Slot3)(u8 *self, u32 a0, u32 a1, u32 a2);

extern "C" void THISCALL ext_4fd5d0(u8 *self);

static void call1(u8 *o, u32 off, u32 a0) {
  ((Slot1)*(u32 *)(*(u32 *)o + off))(o, a0);
}
static void call2(u8 *o, u32 off, u32 a0, u32 a1) {
  ((Slot2)*(u32 *)(*(u32 *)o + off))(o, a0, a1);
}
static void call3(u8 *o, u32 off, u32 a0, u32 a1, u32 a2) {
  ((Slot3)*(u32 *)(*(u32 *)o + off))(o, a0, a1, a2);
}

// 0x4fd020, CMAINCAMERACONTROL::Load(ZLoadGame*) (residue name).
u8 THISCALL cameraControlLoad(u8 *self, u32 loader) {
  u8 *L = (u8 *)loader;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  call1(L, 0x40, (u32)(self + 0x48));
  call1(L, 0x68, (u32)(self + 0x4c));
  call1(L, 0x68, (u32)(self + 0x4d));
  call2(L, 0x18, (u32)(self + 0x4e), 0x10);
  call1(L, 0x50, (u32)(self + 0x5e));
  call1(L, 0x68, (u32)(self + 0x68));
  call1(L, 0x48, (u32)(self + 0x6a));
  call1(L, 0x40, (u32)(self + 0x6e));
  *(u32 *)(self + 0x74) = 0;
  call1(L, 0x40, (u32)(self + 0x78));
  call1(L, 0x44, (u32)(self + 0x7c));
  call1(L, 0x44, (u32)(self + 0x7e));
  call1(L, 0x44, (u32)(self + 0x80));
  call1(L, 0x44, (u32)(self + 0x82));
  call1(L, 0x70, (u32)(self + 0x98));
  call1(L, 0x40, (u32)(self + 0x144));
  call1(L, 0x48, (u32)(self + 0x148));
  call1(L, 0x40, (u32)(self + 0x14e));
  call1(L, 0x48, (u32)(self + 0x152));
  call1(L, 0x40, (u32)(self + 0x156));
  *(u32 *)(self + 0x84) = 0;
  u32 g = *(u32 *)(*(u32 *)0x70039c + 0x1907);
  if (g)
    call3((u8 *)g, 0xc, 0x6e8d9c, 0x67d9e8, 0);
  ext_4fd5d0(self);
  return 1;
}
PCREG(4fd020, cameraControlLoad);
