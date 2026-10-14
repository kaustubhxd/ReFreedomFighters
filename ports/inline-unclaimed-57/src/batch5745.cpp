// batch5745.cpp - unclaimed-57, band batch 45 (name GUESS): 0x5c30c0, thiscall, two stack args (w, unused), ret 8.
// If (word)w == word this+0xf5: 0x5c3560(this, 1, 1) (thiscall, two args, callee pops 8; unverified, hooked and logged); if byte this+0xf9
// is zero return 0; else this+0x115 = (float)(int)(dword engine+0x40) * (float 0x6785e4) (engine = dword 0x70039c); this->vt[+0x64](0x10);
// return 0. Else if (word)w == word this+0xf7: 0x5c3560(this, 1, 1); this->vt[+0x68](0x10, 0); return 0. Else return 0.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *SlotOne)(u8 *self, u32 a);
typedef void(THISCALL *SlotTwo)(u8 *self, u32 a, u32 b);

extern "C" void THISCALL ext_5c3560(u8 *self, u32 a, u32 b);  // unverified, original code (hooked and logged in the spec)

static u32 THISCALL unnamed5c30c0(u8 *self, u32 w, u32 unused) {
  (void)unused;
  if ((u16)w == *(u16 *)(self + 0xf5)) {
    ext_5c3560(self, 1, 1);
    if (*(u8 *)(self + 0xf9) == 0) return 0;
    u8 *engine = G(u8 *, 0x70039c);
    float fv = (float)(s32)*(u32 *)(engine + 0x40) * G(float, 0x6785e4);
    *(float *)(self + 0x115) = fv;
    ((SlotOne)VT(self)[0x64 / 4])(self, 0x10);
    return 0;
  }
  if ((u16)w == *(u16 *)(self + 0xf7)) {
    ext_5c3560(self, 1, 1);
    ((SlotTwo)VT(self)[0x68 / 4])(self, 0x10, 0);
  }
  return 0;
}
PCREG(5c30c0, unnamed5c30c0);
