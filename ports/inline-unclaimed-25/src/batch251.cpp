// batch251.cpp - unclaimed area 25, slice floor(addr/16) mod 20 == 4.
#include "ff.h"

extern "C" void THISCALL ext_523280(u8 *self);   // reset of the path state, original code (plain ret, THISCALL)

typedef u32 (THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef void (*C2)(u32 a, u32 b);   // cdecl

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline void wrw(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }

// 0x523040, thiscall, ret 8 (stack args: shape ZSHAPE*, float t). CMoveAlongPath::ChangePath (map name, body checked).
// A null shape returns at once. Otherwise: an assert-style log call through the logger at 0x700390 (slot 0x20 with
// file 0x6a0778 and line 0xcb, then cdecl slot 0x2c of the result with string 0x6a07e8), stores shape at +0x4b, clears
// +0x4f, copies shape+0x20 to +0x53, sets +0x39 to 3 and stores t at +4. If t == 0 (ordered compare) it sets +0x42 and
// +0x20 to 1.0f, clears the byte at +0x34 and calls ext_523280(this).
static void THISCALL changePath(u8 *selfP, u32 shape, float t) {
  u32 self = (u32)(unsigned long)selfP;
  if (shape == 0)
    return;
  u32 lg = rdw(0x700390, 0);
  u32 ob = ((F2)rdw(rdw(lg, 0), 0x20))((u8 *)(unsigned long)lg, 0x6a0778u, 0xcbu);
  {
    // slot 0x2c: ECX = the object's vtable (as the original loads it), two stack arguments, the caller removes them
    u32 vt2 = rdw(ob, 0);
    u32 fn2 = rdw(vt2, 0x2c);
    asm volatile(
        "pushl %[s]\n\t"
        "pushl %[o]\n\t"
        "call *%[fn]\n\t"
        "addl $8, %%esp\n\t"
        :
        : "c"(vt2), [fn] "r"(fn2), [o] "r"(ob), [s] "r"(0x6a07e8u)
        : "eax", "edx", "memory", "cc");
  }
  wrw(self, 0x4b, shape);
  wrw(self, 0x4f, 0);
  wrw(self, 0x53, rdw(shape, 0x20));
  wrw(self, 0x39, 3);
  *(float *)(unsigned long)(self + 4) = t;
  if (t == 0.0f) {
    wrw(self, 0x42, 0x3f800000u);
    wrw(self, 0x20, 0x3f800000u);
    *(u8 *)(unsigned long)(self + 0x34) = 0;
    ext_523280(selfP);
  }
}
PCREG(523040, changePath);
