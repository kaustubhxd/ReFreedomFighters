#include "ff.h"
// batch3539.cpp - claim 39 (docs/20-gap-band-561000.md): 0x5094c0 ZActorIf::calcPositionInBox(ZGEOM*, float*, float*).
// Stdcall, three args (A, C, P), ret 0xc. The exe overwrites the A and C argument slots with fstp; the port reads them first and
// uses locals. x87 operations at 53-bit precision: the products are done in double and rounded to float on store.
// Stubbed in the harness: the manager's vtable +0x1c0 (thiscall, two args, float return), 0x451890 (fastcall, float stack arg).

typedef float(THISCALL *TF2)(u8 *self, u32 a0, u32 a1);

extern "C" void FASTCALL ext_451890(u32 a0, u32 a1, float a2);

static float callMgr1c0(u32 a0, u32 a1) {
  u8 *mgr = *(u8 **)0x70039c;
  return ((TF2)*(u32 *)(*(u32 *)mgr + 0x1c0))(mgr, a0, a1);
}

void STDCALL calcPositionInBox(u32 A, u32 C, u32 P) {
  u8 *B = *(u8 **)((u8 *)A + 8);
  float b40 = *(float *)(B + 0x40);
  float b48 = *(float *)(B + 0x48);
  float local18[3];
  float local24[3];
  float t1, t2, fl0, fl1;
  double d;
  local18[0] = *(float *)((u8 *)C + 0x18);
  local18[1] = *(float *)((u8 *)C + 0x1c);
  local18[2] = *(float *)((u8 *)C + 0x20);
  local24[0] = *(float *)((u8 *)C + 0);
  local24[1] = *(float *)((u8 *)C + 4);
  local24[2] = *(float *)((u8 *)C + 8);

  t1 = callMgr1c0(0x69cff0, 0x1a4);
  d = ((double)t1 - (double)0.5f) * (double)b40;
  fl0 = (float)d;
  t2 = callMgr1c0(0x69cff0, 0x1a5);
  d = ((double)t2 - (double)0.5f) * (double)b48;
  fl1 = (float)d;

  ext_451890(P, (u32)local18, fl0 + fl0);
  ext_451890(P, (u32)local24, fl1 + fl1);
}
PCREG(5094c0, calcPositionInBox);
