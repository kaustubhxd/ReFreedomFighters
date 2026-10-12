// batch4134.cpp - unclaimed-41 batch 34 (core-todo residue-19): 0x5dcc70 ZFFFlak::Init() (thiscall, no arguments, ret 0, void).
// r = rm.vt[0x1c0](0x6b6c28, 0x85) (a float in st0); this+0x4c = this+0x5c + float(r * this+0x60).
#include "ff.h"

typedef float(THISCALL * fl2_t)(u8 *, u32, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static void THISCALL fn5dcc70(u8 *self) {
  u8 *rm = G(u8 *, 0x70039c);
  float r = ((fl2_t)vslot(rm, 0x1c0))(rm, 0x6b6c28u, 0x85u);
  float prod = r * *(float *)(self + 0x60);
  *(float *)(self + 0x4c) = *(float *)(self + 0x5c) + prod;
}
PCREG(5dcc70, fn5dcc70);
