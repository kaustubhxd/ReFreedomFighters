// batch39.cpp - climb-tree leaf, inline session batch 39 (Haiku, night): 0x4db2c0 ZBaseGeom::GetMatPos.
#include "ff.h"

// 0x4db2c0, thiscall (const), two stack args (mat at [ebp+8], pos at [ebp+0xc]), ret 8. Nine dwords from this are copied
// to mat (the mcpy at 0x4de420, copied inline here), then the three dwords at this+0x24, +0x28, +0x2c go to pos.
static void THISCALL getMatPos(u8 *self, u32 *mat, u32 *pos) {
  u32 *src = (u32 *)self;
  for (int i = 0; i < 9; i++)
    mat[i] = src[i];
  pos[0] = *(u32 *)(self + 0x24);
  pos[1] = *(u32 *)(self + 0x28);
  pos[2] = *(u32 *)(self + 0x2c);
}
PCREG(4db2c0, getMatPos);
