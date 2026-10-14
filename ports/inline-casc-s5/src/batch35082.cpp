// batch35082.cpp - cascade s5 batch 35082: 0x438eb0 (GUESS evaluate an entry by kind: flag, own byte, or signed byte maximum).
#include "ff.h"

extern "C" u8 THISCALL ext_439670(u32 self);   // plain ret, AL
extern "C" u8 THISCALL ext_438e30(u8 *self);   // plain ret, AL
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x438eb0, stdcall(p) ret 4, returns AL. p null: log line 0x6d2 through the object at 0x700390 (slot 0x20(0x67a850, 0x6d2), then slot 0x2c of the result with ECX = its vtable and caller-popped (r, 0x67a8f8)), false.
// b = byte p[0xc] (zero: false); kind = dword p[0]; when kind != 3: b &= 0x439670(p[8]); zero b gives false; kind 0 returns byte p[0x2d]; kind 1 returns 0x438e30(p); anything else false.
static u8 STDCALL fn438eb0(u8 *p) {
  if (!p) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x67a850, 0x6d2);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x67a8f8\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    return 0;
  }
  u8 b = p[0xc];
  if (!b) return 0;
  u32 kind = *(u32 *)p;
  if (kind != 3) b &= ext_439670(*(u32 *)(p + 8));
  if (!b) return 0;
  if (kind == 0) return p[0x2d];
  if (kind == 1) return ext_438e30(p);
  return 0;
}
PCREG(438eb0, fn438eb0);
