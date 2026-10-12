// batch1004.cpp - unclaimed-04 batch 4 (docs/20-unclaimed-04.md): ZMovementBaseMove::CalcNewSpeed (0x487c70, high name).
// thiscall, four stack arguments (ret 0x10). The argument a2 is never read. The callees 0x43e960 and 0x441940 (fastcall:
// this in ecx, one pointer in edx, no stack arguments) and 0x4e0d80 (vsetlen, thiscall with one float) are original code.
// The virtual calls go through the object's vtable (slot 0x60 on self, slot 0x10 on the returned object).
#include "ff.h"

typedef u32(THISCALL *vfn0_t)(void *self);
typedef u32(THISCALL *vfn1_t)(void *self, u32 a);

static inline u32 vcall0(void *obj, u32 slot) {
  u32 fn = *(u32 *)(*(u32 *)obj + slot);
  return ((vfn0_t)fn)(obj);
}
static inline u32 vcall1(void *obj, u32 slot, u32 a) {
  u32 fn = *(u32 *)(*(u32 *)obj + slot);
  return ((vfn1_t)fn)(obj, a);
}

extern "C" void FASTCALL ext_43e960(void *ecx, void *edx);  // original code
extern "C" void FASTCALL ext_441940(void *ecx, void *edx);  // original code
extern "C" void THISCALL ext_4e0d80(float *v, float s);     // vsetlen, original code (batch 33)

static inline void setField21(u8 *self, u32 v) {
  *(u32 *)(self + 0x21) = v;
}

// 0x487c70. self = this, a1 = first pointer argument, outA = 3-float vector at arg 3, outB = 3-float vector at arg 4.
static void THISCALL moveBaseMoveCalcNewSpeed(u8 *self, u8 *a1, u32 unused, u32 *outA, u32 *outB) {
  (void)unused;
  u8 *owner = *(u8 **)(self + 4);
  u32 flags = *(u32 *)(owner + 0x417);
  u32 e8 = flags & 8;

  outA[0] = outA[1] = outA[2] = 0;
  outB[0] = outB[1] = outB[2] = 0;

  // state pointer from the flag bits 0x20 and 0x40 (outB[1] becomes -1 or +1)
  if (flags & 0x20) {
    setField21(self, (u32)(self + 0x1a5));
    outB[1] = 0xbf800000u;
  } else if (flags & 0x40) {
    setField21(self, (u32)(self + 0x1bd));
    outB[1] = 0x3f800000u;
  }

  // flags 0x2000 and 0x4000: the state pointer, and one of two callees
  if (flags & 0x2000) {
    if (flags & 0x10000) {
      setField21(self, (u32)(self + 0x235));
      if (flags & 0x8000)
        ext_43e960(outA, a1 + 0x18);
      else
        ext_441940(outA, a1 + 0x18);
    } else {
      setField21(self, (u32)(self + 0x205));
    }
  } else if (flags & 0x4000) {
    if (flags & 0x10000) {
      setField21(self, (u32)(self + 0x24d));
      if (flags & 0x8000)
        ext_441940(outA, a1 + 0x18);
      else
        ext_43e960(outA, a1 + 0x18);
    } else {
      setField21(self, (u32)(self + 0x21d));
    }
  }

  // result of the self vtable call (slot 0x60), then flag 0x8 or 0x10 picks an object from its slot 0x10
  u8 *R = (u8 *)vcall0(self, 0x60);
  if (e8) {
    u32 O = vcall1(R, 0x10, 3);
    setField21(self, O);
    ext_441940(outA, a1 + 0x18);
  } else if (flags & 0x10) {
    u32 O = vcall1(R, 0x10, 4);
    setField21(self, O);
    ext_43e960(outA, a1 + 0x18);
  }

  // scale outB[1] by the global at 0x68d42c
  outB[1] = fbits(bitsf(outB[1]) * *(float *)0x68d42c);

  // flags 0x1, 0x2, 0x4: objects from R's slot 0x10 (args 1 or 2), or fixed state pointers
  if (flags & 1) {
    if (flags & 4) {
      u32 O = vcall1(R, 0x10, 2);
      setField21(self, O);
      ext_441940(outA, a1);
    } else {
      u32 O = vcall1(R, 0x10, 1);
      setField21(self, O);
      ext_43e960(outA, a1);
    }
  } else if (flags & 2) {
    if (flags & 4) {
      setField21(self, (u32)(self + 0xb5));
      ext_441940(outA, a1);
    } else {
      u32 p;
      if (e8) {
        p = (u32)(self + 0x85);
      } else {
        p = (u32)(self + 0x9d);
        if (!(flags & 0x10)) p = (u32)(self + 0x6d);
      }
      setField21(self, p);
      ext_43e960(outA, a1);
    }
  }

  // the float at the state pointer's +4 (or the default at 0x678858) goes to vsetlen on outA
  u32 sp = *(u32 *)(self + 0x21);
  float s = sp ? *(float *)(sp + 4) : *(float *)0x678858;
  ext_4e0d80((float *)outA, s);
}
PCREG(487c70, moveBaseMoveCalcNewSpeed);
