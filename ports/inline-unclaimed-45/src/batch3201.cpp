// batch3201.cpp - area 45 (residue 4), batch 3201: three small ZActor members from residue-04.txt.
#include "ff.h"

// 0x478b40 ZActor::GetCage() const [vtable] (residue-04.txt), thiscall, plain ret: returns the dword at +0x6bf.
static u32 THISCALL getCage(const u8 *self) { return *(const u32 *)(self + 0x6bf); }
PCREG(478b40, getCage);

// 0x5a2980 ZFFActor::ResetLastHitPos() [vtable] (residue-04.txt), thiscall, plain ret: zeroes the dwords at +0x8fb,
// +0x8ff and +0x903 (unaligned).
static void THISCALL resetLastHitPos(u8 *self) {
  *(u32 *)(self + 0x8fb) = 0;
  *(u32 *)(self + 0x8ff) = 0;
  *(u32 *)(self + 0x903) = 0;
}
PCREG(5a2980, resetLastHitPos);

// 0x47bfc0 ZActor::SetPathNotify(float) [vtable] (residue-04.txt), thiscall, ret 4: stores the float argument at +0x6ba.
static void THISCALL setPathNotify(u8 *self, float v) { *(float *)(self + 0x6ba) = v; }
PCREG(47bfc0, setPathNotify);
