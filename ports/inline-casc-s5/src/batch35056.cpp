// batch35056.cpp - cascade s5 batch 35056: 0x4973b0 (GUESS resolve a handle: direct offset into a table when tagged, else a hashed lookup).
#include "ff.h"

typedef u8(THISCALL *b1_t)(void *, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4973b0, thiscall(h) ret 4, returns EAX. h == 0 gives 0. Bit 0x40000000 set: h &= 0x3fffffff; when unaligned [this+0x65] <= h (unsigned) or h is not a multiple of 16 the error line 0x867 is logged
// through the object at 0x700390 (slot 0x20(0x68e36c, 0x867), then slot 0x2c of the result with ECX = its vtable and caller-popped (r, 0x68e468, h)) and 0 returned; else p = [[this+0x14]+4] + h,
// result p unless dword [p+0x3c] has bit 0x4000000 (then 0). Untagged: [this+8] slot 0x14(h) false gives 0; true gives [this+0xc][ [[this+8]+0x10] & h ].
static u32 THISCALL fn4973b0(u8 *self, u32 h) {
  if (h == 0) return 0;
  if (h & 0x40000000) {
    h &= 0x3fffffff;
    if (rd32u(self + 0x65) <= h || (h & 0xf) != 0) {
      u8 *lg = G(u8 *, 0x700390);
      u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x68e36c, 0x867);
      u32 vt = *(u32 *)r;
      u32 slot = ((u32 *)vt)[0x2c / 4];
      asm volatile("push %[h]\n\tpush $0x68e468\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [h] "r"(h), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
      return 0;
    }
    u8 *p = *(u8 **)(*(u8 **)(self + 0x14) + 4) + h;
    return (*(u32 *)(p + 0x3c) & 0x4000000) ? 0 : (u32)p;
  }
  u8 *o = *(u8 **)(self + 8);
  if (!(*(b1_t **)o)[0x14 / 4](o, h)) return 0;
  o = *(u8 **)(self + 8);
  u32 idx = *(u32 *)(o + 0x10) & h;
  return *(u32 *)(*(u8 **)(self + 0xc) + idx * 4);
}
PCREG(4973b0, fn4973b0);
