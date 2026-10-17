// batch1640.cpp - ZActor::UpdateBlockers(float dt) (0x47c690, residue 13; multi-batch job, full port, 2026-10-12).
//
// The whole function is ported and the original's jump targets are kept as labels. Callees stay exe code:
//   0x487440  out-buffer call with self (unnamed; thiscall, ECX = out buffer)
//   0x47ad60  check on the global object 0x6ff9c0 with (self+0x6ce, self) (unnamed)
//   0x47aad0  same object, (self+0x6ce, self), result unused (unnamed)
//   0x477740  ZActor::ActivateBaseMove (high; thiscall, ECX = self)
//   0x487550  CPathUserProfile::CanOpenDoor (medium; thiscall, ECX = out buffer)
//   0x41e680  ConvPtr (low; thiscall, ECX = object)
//   0x43e920  PSVECSubtract (low; fastcall ECX = dst, EDX = a, stack = b)
//   0x44c840  vnorm (medium; thiscall, ECX = vector; the float result is discarded: the original pops st0)
// Field names are GUESS (read from the code): +0x6c6 move object, +0x6ca and +0x722 times, +0x730 / +0x731 flags,
// +0x6d2 word count, +0x64c state, +0x6d6 time, +0x695 list object, +0x6ce id, +0x6da / +0x6e6 / +0x6f2 vectors.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_487440[];
extern "C" char ext_47ad60[];
extern "C" char ext_47aad0[];
extern "C" char ext_477740[];
extern "C" char ext_487550[];
extern "C" char ext_41e680[];
extern "C" char ext_43e920[];
extern "C" char ext_44c840[];

typedef void(THISCALL *Fn1v)(void *self, void *a);
typedef u8(THISCALL *Fn2a)(void *self, u32 a, u32 b);
typedef u8(THISCALL *FnObjArg)(void *self, void *a);
typedef void *(THISCALL *Fn0p)(void *self);
typedef float(THISCALL *FnVnorm)(void *self);
typedef void(FASTCALL *VecSubFn)(float *dst, const float *a, const float *b);

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

void THISCALL ZActor_UpdateBlockers(u8 *self, float dt) {
  u8 out[0x10];
  u32 loc4 = 0;

  // A: a move object is attached and its time (+0x6ca - +0x722) is below 100 (NaN skips)
  if (AT(u32, self, 0x6c6)) {
    float diff = AT(float, self, 0x6ca) - AT(float, self, 0x722);
    if (diff < 100.0f) {
      ((Fn1v)(void *)ext_487440)(out, self);
      if (AT(u8, self, 0x730)) goto LOOP_B;
      if (AT(u8, self, 0x731)) goto LOOP_B;
      // D: the move object's kind
      {
        u8 *esi = AT(u8 *, self, 0x6c6);
        if (vcall<u32>(esi, 0xc) != 1) goto LOOP_B;
        loc4 = 0;
        u8 *inner = AT(u8 *, esi, 4);
        if (inner) {
          vcall<void>(inner, 0x128, (u32)(u16)(*(volatile u16 *)0x6ffa3c), (u32)&loc4, (u32)0);
          if (loc4) goto LOOP_B;
        }
        if (((FnObjArg)(void *)ext_487550)(out, AT(void *, esi, 4))) goto LOOP_B;
        {
          u8 *ecx = AT(u8 *, esi, 4);
          void *r = ((Fn0p)(void *)ext_41e680)(ecx);
          AT(void *, self, 0x732) = r;
        }
        vcall<void>(self, 0x628, (u32)3, (u32)0, (u32)0);   // pushes: 0, 0, 3 (first parameter = 3)
        goto AFTER_A;
      }
    }
  }
  goto AFTER_A;

LOOP_B:
  if (vcall<u32>(AT(u8 *, self, 0x6c6), 0xc) == 1) {
    u8 *db = AT(u8 *, sys(), 0x9b);
    u32 ed = AT(u32, AT(u8 *, self, 0x6c6), 4);
    u32 r = vcall<u32>(db, 0x4c, ed, (u32)0);
    vcall<void>(self, 0x128, (u32)(u16)(*(volatile u16 *)0x6ffa38), r);
  }
  vcall<void>(AT(u8 *, self, 0x6c6), 4, out);
  vcall<void>(self, 0x5f4);
  goto AFTER_A;

AFTER_A:
  if (!AT(u16, self, 0x6d2)) goto END;
  {
    u32 st = AT(u32, self, 0x64c);
    if (st != 0xb) {
      float xmm0 = AT(float, self, 0x722) - dt;
      float xmm1 = AT(float, self, 0x6d6) - xmm0;
      if (!(0.0f > xmm1)) goto END;
    }
    if (st == 0xa) goto END;
    if (!AT(u32, self, 0x695)) goto END;
    if (!((Fn2a)(void *)ext_47ad60)(((u8 *)0x6ff9c0), AT(u32, self, 0x6ce), (u32)self)) {
      // not F: ActivateBaseMove(1, 0) and the state change
      ((Fn2a)(void *)ext_477740)(self, 1, 0);
      AT(u32, self, 0x64c) = 0xb;
      goto END;
    }
  }

  // F (47c850): reset the vector at +0x6da, read the table entry, subtract
  {
    AT(u32, self, 0x6da) = 0;
    AT(u32, self, 0x6de) = 0;
    AT(u32, self, 0x6e2) = 0;
    vcall<void>(self, 0x84, self + 0x6da);
    u8 *lst = AT(u8 *, self, 0x695);
    u8 *ecx = AT(u8 *, lst, 0xc);
    u32 edx = (u32)AT(u16, self, 0x6d2) * 2;
    AT(u32, self, 0x6e6) = AT(u32, ecx, edx * 8 + 0x14);
    AT(u32, self, 0x6ea) = AT(u32, ecx, edx * 8 + 0x18);
    AT(u32, self, 0x6ee) = AT(u32, ecx, edx * 8 + 0x1c);
    ((VecSubFn)(void *)ext_43e920)((float *)(self + 0x6f2), (float *)(self + 0x6e6), (float *)(self + 0x6da));
    float g = *(volatile float *)0x6ffa48;
    if (!(g == 0.0f)) {
      u8 *db = AT(u8 *, sys(), 0x9b);
      u8 *esiObj = AT(u8 *, self, 0x73e);
      u32 r = vcall<u32>(AT(u8 *, db, 0xadc), 0x218, (u32)(self + 0x6da), (u32)(self + 0x6e6), (u32)-1);
      vcall<void>(esiObj, 4, r);
    }
  }
  // P (47c900)
  {
    AT(u32, self, 0x6f6) = 0;
    ((FnVnorm)(void *)ext_44c840)(self + 0x6f2);
    vcall<void>(self, 0x620, (u32)(self + 0x6e6), (u32)1, (u32)0);
    u32 eax = AT(u16, self, 0x6d4);
    float xmm1 = AT(float, self, 0x6ea) - AT(float, self, 0x6de);
    if (eax == 3) {
      eax = 0x1a;
    } else if (eax == 4) {
      goto FAIL;
    } else if (!(xmm1 <= 0.0f) && !(xmm1 != xmm1)) {
      // xmm1 > 0 (ordered)
      if (xmm1 > 200.0f) {
        eax = 0x18;
      } else {
        eax = (xmm1 > 140.0f ? 1u : 0u) * 2u + 0x14u;   // lea eax,[eax*2+0x14] with eax = seta result
      }
    } else {
      // xmm1 <= 0 or NaN
      if (-200.0f > xmm1) {
        eax = 0x19;
      } else {
        eax = (-140.0f > xmm1 ? 1u : 0u) * 2u + 0x15u;   // lea eax,[eax*2+0x15]
      }
    }
    // ACT (47c9ac)
    if (!((Fn2a)(void *)ext_477740)(self, eax, 0)) goto FAIL;
    {
      u16 w = AT(u16, self, 0x6d2);
      u32 ecx2 = (u32)(u16)(w + 1) * 2;
      u8 *lst = AT(u8 *, self, 0x695);
      float xmm0 = AT(float, self, 0x722);
      AT(u32, self, 0x64c) = 0xa;
      float x1 = AT(float, AT(u8 *, lst, 0xc), ecx2 * 8) - xmm0;
      if (!(x1 > 0.0f)) goto END;
      AT(float, self, 0x722) = xmm0 + x1;
      goto END;
    }
  }

FAIL:
  ((Fn2a)(void *)ext_47aad0)(((u8 *)0x6ff9c0), AT(u32, self, 0x6ce), (u32)self);

END:
  return;
}
PCREG(47c690, ZActor_UpdateBlockers);
