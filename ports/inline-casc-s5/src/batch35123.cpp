// batch35123.cpp - cascade s5 batch 35123: 0x5f25d0 (GUESS start the resource an entry names, logging when it cannot be started).
#include "ff.h"

typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static void log_it(u32 line, u32 fmt) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x6b8738, line);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[fmt]\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [fmt] "r"(fmt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

// 0x5f25d0, stdcall(s) ret 4. Nothing when [s+0x20] is set or the global byte 0x7143ac is set. e = [engine+0x9b] slot 0x58([s+0x24]); with e: c = [e+0x10]; when c and [c+0x1c] are non-zero c slot 0() runs, otherwise line 0x24a (fmt 0x6b8860)
// is logged through the logger at 0x700390 (slot 0x20(0x6b8738, line), then slot 0x2c of the result with ECX = its vtable and caller-popped (r, fmt)). Without e: line 0x24f (fmt 0x6b8890) while [s+0x20] is still zero.
static void STDCALL fn5f25d0(u8 *s) {
  if (*(u32 *)(s + 0x20) != 0) return;
  if (G(u8, 0x7143ac) != 0) return;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x58 / 4](tab, *(u32 *)(s + 0x24));
  if (e) {
    u8 *c = *(u8 **)(e + 0x10);
    if (c && *(u32 *)(c + 0x1c)) {
      (*(v0_t **)c)[0](c);
      return;
    }
    log_it(0x24a, 0x6b8860);
    return;
  }
  if (*(u32 *)(s + 0x20) != 0) return;
  log_it(0x24f, 0x6b8890);
}
PCREG(5f25d0, fn5f25d0);
