// batch1019.cpp - area 81, batch 1019: GUESS FUN_4a0ea0 (name unknown), 0x4a0ea0, thiscall, one stack argument, returns a bool (al). Cookie check not
// reproduced (no SEH frame). Stand-ins (GUESS, fastcall without stack arguments): 0x43e960, 0x441940, 0x4e0870 (the spec records their vector arguments
// into the heap so the clamps are compared). The x87 step is the exe's own fsub on whatever st0 holds (inline asm), then fstp; the compare is >=.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void __attribute__((fastcall)) ext_43e960(void *ecx, void *edx);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_441940(void *ecx, void *edx);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_4e0870(void *ecx, void *edx);   // GUESS (stood in)

// One lane of the clamp: when |v| > Y (ordered), v becomes +Y or -Y by the sign of v (0 > v gives -Y).
static void clampLane(float *v, float Y) {
  if (__builtin_fabsf(*v) > Y)
    *v = (0.0f > *v) ? -Y : Y;
}

// The exe's x87 step: st0 = st0 - [0x678858], then pop into a float. The port uses the same instruction, so the same st0 gives the same value.
static float x87SubPop(void) {
  float out;
  __asm__ volatile("fsubs (%1)\n\tfstps %0" : "=m"(out) : "r"((u32)0x678858) : "memory", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
  return out;
}

// GUESS FUN_4a0ea0 (0x4a0ea0): thiscall on this, one stack argument (x), returns the bool.
static u32 THISCALL funUnk4a0ea0(u8 *self, u32 xArg) {
  u8 *X = (u8 *)xArg;
  if (*(u8 *)(self + 0x5a) & 5)
    return 0;
  u32 kind = D(self, 0x48);
  if (kind == 8)
    return 1;
  if (kind != 6) {
    u32 l20 = (u32)self;
    u32 rr = vcall<u32>(X, 0x128, (u32)*(u16 *)0x7002d0, (u32)&l20, 0u);
    return (rr & 0xffffff00u) | (u32)(l20 == 1);
  }
  u8 *M = (u8 *)D(self, 0x44);
  float v[3];
  u8 *Z = (u8 *)D(M, 8);
  v[0] = *(float *)(Z + 0x30);
  v[1] = *(float *)(Z + 0x34);
  v[2] = *(float *)(Z + 0x38);
  vcall<void>(M, 0x84, (u32)v);
  vcall<void>(X, 0x8c, (u32)v);
  u8 *XZ = (u8 *)D(X, 8);
  ext_43e960(v, XZ + 0x30);
  clampLane(&v[0], *(float *)(XZ + 0x40));
  clampLane(&v[1], *(float *)(XZ + 0x44));
  clampLane(&v[2], *(float *)(XZ + 0x48));
  ext_441940(v, XZ + 0x30);
  vcall<void>(X, 0x84, (u32)v);
  float w[3] = {v[0], v[1], v[2]};
  vcall<void>(M, 0x8c, (u32)w);
  ext_43e960(w, Z + 0x30);
  clampLane(&w[0], *(float *)(Z + 0x40));
  clampLane(&w[1], *(float *)(Z + 0x44));
  clampLane(&w[2], *(float *)(Z + 0x48));
  ext_441940(w, Z + 0x30);
  vcall<void>(M, 0x84, (u32)w);
  ext_4e0870(v, w);
  float x = (float)(int)D(self, 0x56);
  float tmp = x87SubPop();
  return (u32)(x >= tmp);
}
PCREG(4a0ea0, funUnk4a0ea0);
