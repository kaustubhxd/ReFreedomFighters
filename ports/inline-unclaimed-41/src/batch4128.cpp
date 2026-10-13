// batch4128.cpp - unclaimed-41 batch 28 (slice 13): 0x4a2c50 ZParamAnim::CopyData(one stack argument S, ret 4).
// SEH frame not reproduced: the fs:[0] push, the fs:[0] save and restore around the body are not modelled (fs:[0] writes are not compared).
// The /GS cookie check is not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_4da6d0(u8 *self);                 // ecx = B, no arguments (stub, GUESS)
extern "C" u32 THISCALL ext_4cc1d0(u8 *self);                  // ecx = R, no arguments; returns eax (stub, GUESS)
extern "C" void THISCALL ext_4cbec0(u8 *self);                 // ecx = &L90, no arguments (stub, GUESS)

typedef u32(THISCALL * f0_t)(u8 *);
typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * f4_t)(u8 *, u32, u32, u32, u32);
typedef u32(THISCALL * fq_t)(u8 *, u32, u32, float);     // the function pointer at Q+4: three stack arguments, callee pops, returns al

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

// caller pops 12: the exe's o.vt[0x2c] calls (ecx = the value given, arguments pushed a3, a2, a1)
static void callCallerPop3(u8 *ecxv, u32 fn, u32 a1, u32 a2, u32 a3) {
  asm volatile("pushl %[a3]\n\tpushl %[a2]\n\tpushl %[a1]\n\tcall *%[fn]\n\taddl $12, %%esp"
               : "+c"(ecxv)
               : [a3] "r"(a3), [a2] "r"(a2), [a1] "r"(a1), [fn] "r"(fn)
               : "eax", "edx", "memory", "cc");
}

static void THISCALL fn4a2c50(u8 *self, u8 *S) {
  u8 *A = *(u8 **)(self + 0x44);
  {
    u8 *B = *(u8 **)(A + 8);
    if (*(u32 *)(B + 0x6c) != 0)
      ext_4da6d0(B);
  }
  u32 E = ((f1_t)vslot(A, 0x4c))(A, 0x80004u);

  *(u32 *)(self + 0x4d) = 0;
  *(u32 *)(self + 0x49) = 0;
  *(u32 *)(self + 0x51) = 0;
  *(u32 *)(self + 0x55) = 0xbf800000u;

  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u16 *)0x7002e8 = (u16)((f4_t)vslot(o, 0x114))(o, 0x67b508u, 0u, 0x68f94cu, 0xa0u);
  o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u16 *)0x7002ec = (u16)((f4_t)vslot(o, 0x114))(o, 0x68f9e8u, 0u, 0x68f94cu, 0xa1u);

  if (E == 0) {
    // logger path (dd), then A.vt[0x1d8](&L90, 0), 0x4cc1d0(R), O.vt[0x2c](O, 0x68f9c0, R2) with ecx = R, 0x4cbec0(&L90)
    u8 *Lg = G(u8 *, 0x700390);
    u8 *O = (u8 *)((f2_t)vslot(Lg, 0x20))(Lg, 0x68f94cu, 0xddu);
    u32 L90[16];
    u8 *R = (u8 *)((f2_t)vslot(A, 0x1d8))(A, (u32)L90, 0u);
    u32 R2 = ext_4cc1d0(R);
    callCallerPop3(R, vslot(O, 0x2c), (u32)O, 0x68f9c0u, R2);
    ext_4cbec0((u8 *)L90);
    ((f0_t)vslot(self, 0x58))(self);
  } else {
    // copy path: this+0x11a from S+0x11a; the two word globals from o.vt[0x114]; the byte, dword and float fields
    *(u16 *)(self + 0x11a) = *(u16 *)(S + 0x11a);
    o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    *(u16 *)0x7002f0 = (u16)((f4_t)vslot(o, 0x114))(o, 0x688c10u, 0u, 0x68f94cu, 0xe3u);
    o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    *(u16 *)0x7002f4 = (u16)((f4_t)vslot(o, 0x114))(o, 0x688c1cu, 0u, 0x68f94cu, 0xe4u);

    u32 q = *(u32 *)(self + 0x59);     // edx: the object whose +4 is the function pointer
    self[0x11d] = S[0x11d];
    self[0x48] = S[0x48];
    self[0x11c] = S[0x11c];
    *(u32 *)(self + 0x51) = *(u32 *)(S + 0x51);
    *(u32 *)(self + 0x55) = *(u32 *)(S + 0x55);
    float f = *(float *)(S + 0x11e);
    *(float *)(self + 0x11e) = f;
    u32 bz = self[0x11d];
    u32 fq = *(u32 *)(q + 4);
    u8 al = (u8)((fq_t)fq)(self + 0x59, E, bz, f);
    if (al == 0) {
      u8 *Lg = G(u8 *, 0x700390);
      u8 *O2 = (u8 *)((f2_t)vslot(Lg, 0x20))(Lg, 0x68f94cu, 0xedu);
      u32 t = *(u32 *)(A + 4);
      u32 third = (t != 0) ? t : 0x67c8e8u;
      callCallerPop3((u8 *)*(u32 *)O2, vslot(O2, 0x2c), (u32)O2, 0x68f998u, third);
      ((f0_t)vslot(self, 0x58))(self);
    }
  }

  // 0x4a2e82
  if (self[0x11c] == 0) {
    ((f1_t)vslot(A, 0x3c))(A, 1u);
    ((f2_t)vslot(self, 0x68))(self, 0x10u, 0u);
  }
}
PCREG(4a2c50, fn4a2c50);
