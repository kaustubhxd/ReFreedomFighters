#include "ff.h"
// batch2708.cpp - unclaimed-27 claim 8 (docs/20-unclaimed-27.md). Name from the GC name map (high).

// 0x4e7ce0, ZRunMatPosAnim::SetFrameStart(int) (high). Thiscall, ret 4.
// If the dword at this+9 is 0: calls vtable slot +0x20 of the object at the global 0x700390 with (0x697528, 0x96), gets an
// object A, then calls A's vtable slot +0x2c with (A, 0x697558) as a cdecl call whose ecx is A's vtable pointer (the exe does
// `mov ecx, [eax]` before the call, and the caller cleans up 8 bytes). Otherwise, with A = the object at this+9: the offset
// is A+8 when the top two bits of the dword at A+4 are 0x40000000, 0x80000000 or 0xc0000000, else 8; the value is the
// argument clamped to the signed range [lo, hi] at A+off+4 .. A+off+8 (lo is used when the argument is below it), and is
// stored as a float at this+0xd.
static void callCdecl2(u32 fn, u32 ecx_value, u32 a, u32 b) {
  __asm__ volatile("pushl %[b]\n\tpushl %[a]\n\tcall *%[fn]\n\taddl $8, %%esp"
                   :
                   : [b] "r"(b), [a] "r"(a), [fn] "r"(fn), "c"(ecx_value)
                   : "eax", "edx", "memory", "cc");
}

static void THISCALL zRunMatPosAnimSetFrameStart(u8 *self, s32 arg) {
  typedef u8 *(THISCALL * slot20_fn)(u8 *, u32, u32);
  u8 *a = *(u8 **)(self + 9);
  if (a == 0) {
    u8 *g = *(u8 **)(unsigned long)0x700390;
    u8 *obj = ((slot20_fn)(*(u32 *)(*(u32 *)g + 0x20)))(g, 0x697528u, 0x96u);
    u32 vtA = *(u32 *)obj;
    u32 fn2c = *(u32 *)(vtA + 0x2c);
    callCdecl2(fn2c, vtA, (u32)(unsigned long)obj, 0x697558u);
    return;
  }

  u32 flags = *(u32 *)(a + 4) & 0xc0000000u;
  u32 off = (flags == 0x40000000u || flags == 0x80000000u || flags == 0xc0000000u) ? *(u32 *)(a + 8) : 8u;
  s32 lo = *(s32 *)(a + off + 4);
  s32 v;
  if (arg < lo) {
    v = lo;
  } else {
    s32 hi = *(s32 *)(a + off + 8);
    v = (arg > hi) ? hi : arg;
  }
  *(float *)(self + 0xd) = (float)v;
}
PCREG(4e7ce0, zRunMatPosAnimSetFrameStart);
