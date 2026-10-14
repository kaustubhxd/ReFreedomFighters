// batch35043.cpp - cascade s5 batch 35043: 0x607ec0 (GUESS constructor of a bound call: try a helper object's slot 0x50 twice, log when both fail).
#include "ff.h"

typedef s32(THISCALL *call8_t)(u32 ecx, u32, u32, u32, u32, u32, u32, u32, u32);   // thiscall, eight stack args, callee pops 0x20
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x607ec0, thiscall(a, b, c, d) ret 0x10, returns this. [this+0x110] = 0, vtable 0x6bc894, [+4] = c, [+8] = d, [+0xc] = a, [+0x114] = 0. s = a slot 0x50 called with ECX = a and eight stack args
// (a, c, d, 1, 1, b, 0, this+0x110); when s >= 0 (signed) done. Otherwise o = [+0xc]: slot 0x50 of o called with ECX = o's vtable and (o, [+4], [+8], 1, 0, b, 0, this+0x110); when still negative the line
// 0xe1 is logged through the object at 0x700390 (slot 0x20(0x6bcb80, 0xe1), then slot 0x2c of the result with ECX = its vtable and caller-popped args (r, 0x6bcbc4)).
static u8 *THISCALL fn607ec0(u8 *self, u8 *a, u32 b, u32 c, u32 d) {
  *(u32 *)(self + 0x110) = 0;
  *(u32 *)self = 0x6bc894;
  *(u32 *)(self + 4) = c;
  *(u32 *)(self + 8) = d;
  *(u8 **)(self + 0xc) = a;
  *(u32 *)(self + 0x114) = 0;
  u32 f = (*(u32 **)a)[0x50 / 4];
  s32 r = ((call8_t)f)((u32)a, (u32)a, c, d, 1, 1, b, 0, (u32)(self + 0x110));
  if (r >= 0) return self;
  u8 *o = *(u8 **)(self + 0xc);
  u32 vt = *(u32 *)o;
  u32 f2 = ((u32 *)vt)[0x50 / 4];
  r = ((call8_t)f2)(vt, (u32)o, *(u32 *)(self + 4), *(u32 *)(self + 8), 1, 0, b, 0, (u32)(self + 0x110));
  if (r >= 0) return self;
  u8 *lg = G(u8 *, 0x700390);
  u8 *x = (*(r2_t **)lg)[0x20 / 4](lg, 0x6bcb80, 0xe1);
  u32 vtx = *(u32 *)x;
  u32 slot = ((u32 *)vtx)[0x2c / 4];
  asm volatile("push $0x6bcbc4\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vtx), [r] "r"(x), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  return self;
}
PCREG(607ec0, fn607ec0);
