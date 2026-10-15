// batch5814.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 114: 0x5d8d60 (GUESS name unnamed_5d8d60), thiscall, four stack arguments (a1..a4; ret 0x10).
// If this+0x20 == 0: 0x45dc90(a1, a2, a3, a4) (stdcall, hooked) and return. Else: n = ++this+0x44; m = this+0x30; D = this+0x40; rem = n % D; f = G(0x678858) / (float)m;
// V = 0; if rem == 0: V = this+0x3c, negated if (((n / 2) % D) != 0). N1 = this+0x18, N2 = this+0x1c; for i < N1, j < N2: k = N1*j + i; r = eng->vt[+0x1bc](0x6b61dc, 0xb5);
// x1 = (float)((r >> 2) % m) * f; cell k (40 bytes at this+0x20): +0xc = x1, +0x10 = x1 + f; r2 = eng->vt[+0x1bc](0x6b61dc, 0xb7); +0x14 = (float)((r2 >> 2) % m) * f,
// +0x18 = that + f; +4 = (old +4) + (float)V. If tgt = this+0x34 != 0: a1->vt[+0x2c](tgt, this+0x24, a3, a4, 7).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *Slot2i)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *Slot5)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);

extern "C" void STDCALL ext_45dc90(u32 a1, u32 a2, u32 a3, u32 a4);  // original code (hooked in the spec)

// 0x5d8d60, thiscall, four stack arguments (GUESS name)
static void THISCALL unnamed5d8d60(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4) {
  if (*(u32 *)(self + 0x20) == 0) {
    ext_45dc90(a1, a2, a3, a4);
    return;
  }
  *(u32 *)(self + 0x44) += 1;
  s32 n = (s32)*(u32 *)(self + 0x44);
  s32 m = (s32)*(u32 *)(self + 0x30);
  s32 D = (s32)*(u32 *)(self + 0x40);
  s32 rem = n % D;
  float f = G(float, 0x678858) / (float)m;
  s32 V = 0;
  if (rem == 0) {
    s32 esi = (s32)*(u32 *)(self + 0x3c);
    s32 q = (n / 2) % D;
    if (q != 0) esi = -esi;
    V = esi;
  }
  s32 N1 = (s32)*(u32 *)(self + 0x18);
  for (s32 i = 0; i < N1; i++) {
    for (s32 j = 0; j < (s32)*(u32 *)(self + 0x1c); j++) {
      s32 k = N1 * j + i;
      u8 *base = *(u8 **)(self + 0x20);
      u8 *eng = G(u8 *, 0x70039c);
      s32 r = (s32)((Slot2i)VT(eng)[0x1bc / 4])(eng, 0x6b61dc, 0xb5);
      s32 t1 = (r >> 2) % (s32)*(u32 *)(self + 0x30);
      float x1 = (float)t1 * f;
      float *cell = (float *)(base + 40 * k);
      cell[3] = x1;
      cell[4] = x1 + f;
      eng = G(u8 *, 0x70039c);
      s32 r2 = (s32)((Slot2i)VT(eng)[0x1bc / 4])(eng, 0x6b61dc, 0xb7);
      s32 t2 = (r2 >> 2) % (s32)*(u32 *)(self + 0x30);
      float x2 = (float)t2 * f;
      cell[5] = x2;
      cell[6] = x2 + f;
      cell[1] = cell[1] + (float)V;
    }
  }
  u32 tgt = *(u32 *)(self + 0x34);
  if (tgt != 0) {
    void **vt = VT(a1);
    ((Slot5)vt[0x2c / 4])((u8 *)(unsigned long)a1, tgt, *(u32 *)(self + 0x24), a3, a4, 7);
  }
}
PCREG(5d8d60, unnamed5d8d60);
