// batch46006.cpp - cascade t7 (Sonnet), tier G: 0x52d750 = octree/box walk (thiscall this, 9 stack args, ret 0x24, recursive).
#include "ff.h"

extern "C" u32 THISCALL ext_52d580(u8 *self, u8 *a0, u16 *idx, u32 d, s32 p14, s32 p18, s32 p1c, s32 p20, s32 p24, s32 p28);  // ret 0x24

static u32 THISCALL fn52d750(u8 *self, u8 *a0, u16 *idx, s32 depth, s32 p14, s32 p18, s32 p1c, s32 p20, s32 p24, s32 p28);

static inline u32 child(u8 *self, u8 *a0, u16 *idx, s32 depth, u32 slotOff, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, u32 &ebx, u32 &stop) {
  u32 L20 = *(u16 *)(*(u8 **)(self + 0x54) + (u32)(*(u16 *)idx) * 0x16 + slotOff);
  ebx += fn52d750(self, a0, (u16 *)&L20, depth, a3, a4, a5, a6, a7, a8);
  u8 *ent = *(u8 **)(self + 0x54) + (u32)(*(u16 *)idx) * 0x16;
  *(u16 *)(ent + slotOff) = (u16)L20;
  stop = (a0[0x10] != 0 && ebx != 0);
  return ebx;
}

static u32 THISCALL fn52d750(u8 *self, u8 *a0, u16 *idx, s32 depth, s32 p14, s32 p18, s32 p1c, s32 p20, s32 p24, s32 p28) {
  s32 box[6] = {p14, p18, p1c, p20, p24, p28};
  u8 *v1 = *(u8 **)a0;
  if (v1) {
    u8 r = vcall<u8>(v1, 0, (u32)self, (u32)*idx, (u32)&box[0], (u32)&box[3]);
    if (!r) return 0;
  }
  u32 ebx = 0;
  if (depth != 0) {
    u8 *v2 = *(u8 **)(a0 + 4);
    if (v2) ebx = vcall<u32>(v2, 0, (u32)self, (u32)idx, (u32)&box[0], (u32)&box[3], (u32)depth);
    u32 n = *idx;
    if (n == 0) return ebx;
    if (a0[0x10] != 0 && ebx != 0) return ebx;
    depth--;
    s32 mx = (s32)((u32)p20 + (u32)p14) / 2, my = (s32)((u32)p24 + (u32)p18) / 2, mz = (s32)((u32)p28 + (u32)p1c) / 2;
    s32 X = (u16)mx, Y = (u16)my, Z = (u16)mz;
    u32 stop = 0;
    child(self, a0, idx, depth, 6, p14, p18, p1c, X, Y, Z, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 8, X, p18, p1c, p20, Y, Z, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 0xa, p14, Y, p1c, X, p24, Z, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 0xc, X, Y, p1c, p20, p24, Z, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 0xe, p14, p18, Z, X, Y, p28, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 0x10, X, p18, Z, p20, Y, p28, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 0x12, p14, Y, Z, X, p24, p28, ebx, stop);
    if (stop) return ebx;
    child(self, a0, idx, depth, 0x14, X, Y, Z, p20, p24, p28, ebx, stop);
    return ebx;
  }
  u8 *v3 = *(u8 **)(a0 + 8);
  if (v3) ebx = vcall<u32>(v3, 0, (u32)self, (u32)idx, (u32)&box[0], (u32)&box[3], (u32)0);
  if (*idx == 0) return ebx;
  if (a0[0x10] != 0 && ebx != 0) return ebx;
  return ext_52d580(self, a0, idx, 0, p14, p18, p1c, p20, p24, p28);
}
PCREG(52d750, fn52d750);
