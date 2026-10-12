// batch224.cpp - small leaves, slice 0/1 (unclaimed; docs grep done). Pure memory functions, no callees. Names GUESS.
#include "ff.h"

// 0x468200, thiscall(): returns the dword at [this+0x1d2].
static u32 THISCALL getDword1d2_468200(u8 *self) { return *(u32 *)(self + 0x1d2); }
PCREG(468200, getDword1d2_468200);

// 0x52a1c0, thiscall(): [this+0x29] = 0x43960000; [this+0x2d] = 0xc3c80000; [this+0x31] = 0xc0800000 (three floats).
static void THISCALL setConstFloats_52a1c0(u8 *self) {
  *(u32 *)(self + 0x29) = 0x43960000u;
  *(u32 *)(self + 0x2d) = 0xc3c80000u;
  *(u32 *)(self + 0x31) = 0xc0800000u;
}
PCREG(52a1c0, setConstFloats_52a1c0);

// 0x483b40, thiscall(idx) (ret 4): returns the dword at [this + idx*4 + 0x45d].
static u32 THISCALL getIndexed_483b40(u8 *self, u32 idx) { return *(u32 *)(self + idx * 4 + 0x45d); }
PCREG(483b40, getIndexed_483b40);

// 0x469100, thiscall(a, b) (ret 8): [this+4] = (b & [this+4]) | a; returns it.
static u32 THISCALL maskOr_469100(u8 *self, u32 a, u32 b) {
  u32 v = (b & *(u32 *)(self + 4)) | a;
  *(u32 *)(self + 4) = v;
  return v;
}
PCREG(469100, maskOr_469100);

// 0x485080, thiscall(p) (ret 4): [this+0x445] = p[0]; [this+0x449] = p[1]; [this+0x44d] = p[2].
static void THISCALL copy3_485080(u8 *self, u32 *p) {
  *(u32 *)(self + 0x445) = p[0];
  *(u32 *)(self + 0x449) = p[1];
  *(u32 *)(self + 0x44d) = p[2];
}
PCREG(485080, copy3_485080);
