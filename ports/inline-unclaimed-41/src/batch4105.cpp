// batch4105.cpp - unclaimed-41 batch 5 (slice 13): three small functions.
#include "ff.h"

// 0x4daa70: five stack arguments (the caller does not adjust esp, so it pops 0x14); a checksum stub in the spec (GUESS).
extern "C" void THISCALL ext_4daa70(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
// 0x4d24e0: four stack arguments (ret 0x10); a checksum stub in the spec (GUESS). It takes ecx = the caller's ecx.
extern "C" void THISCALL ext_4d24e0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4);

// 0x596710: thiscall, one stack argument (out, ret 4). Copies 64 bytes from this+0x37d to out (four 16-byte moves), then
// out+0x40 = dword(this+0x3bd) and out+0x44 = byte(this+0x3c1).
static void THISCALL copyRecord596710(u8 *self, u8 *out) {
  for (u32 i = 0; i < 0x40; i++)
    out[i] = self[0x37d + i];
  *(u32 *)(out + 0x40) = *(u32 *)(self + 0x3bd);
  out[0x44] = self[0x3c1];
}
PCREG(596710, copyRecord596710);

// 0x45dc90: thiscall, four stack arguments (ret 0x10). Calls 0x4daa70 with ecx = this+8 and (a1, a2, a3, a4, 1).
static void THISCALL wrap45dc90(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 *obj = *(u8 **)(self + 8);
  ext_4daa70(obj, a1, a2, a3, a4, 1u);
}
PCREG(45dc90, wrap45dc90);

// 0x4d3d50: thiscall, two stack arguments (ret 8). Calls 0x4d24e0 with the caller's ecx (this) and (a1, 8, a2, 0).
static void THISCALL wrap4d3d50(u8 *self, u32 a1, u32 a2) {
  ext_4d24e0(self, a1, 8u, a2, 0u);
}
PCREG(4d3d50, wrap4d3d50);
