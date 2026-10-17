// batch5823.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 123: 0x5d4c00 (CBoxAutoFire::FireShot(), GUESS name), thiscall, no args, plain ret.
// cut = trunc((this+0x48 + this+0x4c) * G(0x678620)); if cut >= engine+0x40: return. Loop: this+0x4c = this+0x48 + this+0x4c; mreset(m40) (0x4de7a0, original code);
// A = sub->vt[+0x58](this+0x50); B = sub->vt[+0x58](this+0x54); if A && B: A->vt[+0x98](m40, v10); 0x5d4e80(this, A, m40, v10) (original code);
// 0x5d4e80(this, B, m40, v1c) (original code); C = sub->vt[+0x58](this+0x5c); if C: C->vt[+0xbc](1); C->vt[+0x33c](2); if C->vt[+0x35c]() == 0: C->vt[+0x360](0x64);
// if !(u8)C->vt[+0x354]: C->vt[+0x2d0](6,0), C->vt[+0x2d0](0,0); C->vt[+0x7c](m40, v10); C->vt[+0x32c](v1c); C->vt[+0x2d0](3,0), C->vt[+0x2d0](0,0);
// O = logger->vt[+0x20](0x6b53ac, 0x65); O->vt[+0x2c](O, 0x6b53e0) (cdecl). Loop while cut < engine+0x40.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot1)(u8 *self, u32 a);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *Slot2r)(u8 *self, u32 a, u32 b);
typedef void (*FnC2)(u32 a, u32 b);  // cdecl

extern "C" void THISCALL ext_4de7a0(u8 *self);                          // mreset: writes 9 dwords into the 36-byte block, original code
extern "C" void THISCALL ext_5d4e80(u8 *self, u8 *obj, u8 *a, u8 *out);  // vector helper, 3 stack args (ret 0xc), original code

static s32 cutOf(u8 *self) {
  float s = *(float *)(self + 0x48) + *(float *)(self + 0x4c);
  return _mm_cvttss_si32(_mm_set_ss(s * G(float, 0x678620)));
}

// 0x5d4c00, thiscall, no args (GUESS name)
static void THISCALL unnamed5d4c00(u8 *self) {
  if (cutOf(self) >= (s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40)) return;
  do {
    *(float *)(self + 0x4c) = *(float *)(self + 0x48) + *(float *)(self + 0x4c);
    u32 L1c[3] = {0, 0, 0};
    u32 L10[3] = {0, 0, 0};
    u32 M40[9];
    ext_4de7a0((u8 *)M40);
    u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *A = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x50));
    sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *B = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x54));
    if (A != 0 && B != 0) {
      ((Slot2)VT(A)[0x98 / 4])(A, (u32)(unsigned long)M40, (u32)(unsigned long)L10);
      ext_5d4e80(self, A, (u8 *)M40, (u8 *)L10);
      ext_5d4e80(self, B, (u8 *)M40, (u8 *)L1c);
      sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *C = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x5c));
      if (C != 0) {
        ((Slot1)VT(C)[0xbc / 4])(C, 1);
        ((Slot1)VT(C)[0x33c / 4])(C, 2);
        if (((SlotN)VT(C)[0x35c / 4])(C) == 0) ((Slot1)VT(C)[0x360 / 4])(C, 0x64);
        if (!(u8)((SlotN)VT(C)[0x354 / 4])(C)) {
          ((Slot2)VT(C)[0x2d0 / 4])(C, 6, 0);
          ((Slot2)VT(C)[0x2d0 / 4])(C, 0, 0);
        }
        ((Slot2)VT(C)[0x7c / 4])(C, (u32)(unsigned long)M40, (u32)(unsigned long)L10);
        ((Slot1)VT(C)[0x32c / 4])(C, (u32)(unsigned long)L1c);
        ((Slot2)VT(C)[0x2d0 / 4])(C, 3, 0);
        ((Slot2)VT(C)[0x2d0 / 4])(C, 0, 0);
        u8 *lg = G(u8 *, 0x700390);
        u8 *O = (u8 *)(unsigned long)((Slot2r)VT(lg)[0x20 / 4])(lg, 0x6b53ac, 0x65);
        ((FnC2)VT(O)[0x2c / 4])((u32)(unsigned long)O, 0x6b53e0);
      }
    }
  } while (cutOf(self) < (s32)*(u32 *)(G(u8 *, 0x70039c) + 0x40));
}
PCREG(5d4c00, unnamed5d4c00);
