// u69_88.cpp - area 69, gameplay-core residue-8. 0x5bdcc0 CCivilianPath::Init2() (thiscall, no args, plain ret).
// Reads the global object G = [0x70039c] and M = [G+0x9b]; R = M->vt[0x58]([this+0x59]); if R: Z = R->vt[0x100](0x6b3538);
// if Z: RegisterPath via 0x5bef80 with ECX = Z and stack args (0x44, 0x48, float 0x54, bool 0x4c, bool 0x50, byte 0x58).
// Callees: M's slot 0x58 and R's slot 0x100 are fake vtables in the spec (GUESS); 0x5bef80 is a logging hook (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_5bef80(void *self, u32 p0, u32 p1, float p2, u32 p3, u32 p4, u32 p5);   // RegisterPath, GUESS hook

static void THISCALL init2_5bdcc0(u8 *self) {
  u8 *g = G(u8 *, 0x70039c);
  u8 *m = *(u8 **)(g + 0x9b);
  u32 r = ((u32(THISCALL *)(void *, u32))*(u32 *)(*(u32 *)m + 0x58))(m, *(u32 *)(self + 0x59));
  if (!r)
    return;
  u32 z = ((u32(THISCALL *)(void *, u32))*(u32 *)(*(u32 *)r + 0x100))((void *)r, 0x6b3538);
  if (!z)
    return;
  ext_5bef80((void *)z, *(u32 *)(self + 0x44), *(u32 *)(self + 0x48), *(float *)(self + 0x54),
             *(u32 *)(self + 0x4c) != 0, *(u32 *)(self + 0x50) != 0, *(u8 *)(self + 0x58));
}
PCREG(5bdcc0, init2_5bdcc0);
