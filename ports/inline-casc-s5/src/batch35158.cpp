// batch35158.cpp - cascade s5 batch 35158: 0x50c870 (GUESS fetch an engine entry by id and check its kind, logging on failure).
#include "ff.h"

typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u8(THISCALL *b1_t)(void *, u32);
typedef u8 *(THISCALL *l2_t)(void *, u32, u32);

// 0x50c870, stdcall(id) ret 4. e = engine[+0x9b] slot 0x58(id). Null: logger (0x700390) slot 0x20(0x69d420, 0xa4) returns r; slot 0x2c(r, 0x69d450) with ECX = the vtable, caller-popped; returns 0.
// Else when e slot 0x1e0(0x1007d1) is false: logger slot 0x20(0x69d420, 0xa9); slot 0x2c(r, 0x69d4a0, [e+4]) (same convention); returns 0. Otherwise returns e.
static u8 *STDCALL fn50c870(u32 id) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (!e) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = (*(l2_t **)lg)[0x20 / 4](lg, 0x69d420, 0xa4);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x69d450\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    return 0;
  }
  if (!(*(b1_t **)e)[0x1e0 / 4](e, 0x1007d1)) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = (*(l2_t **)lg)[0x20 / 4](lg, 0x69d420, 0xa9);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    u32 k = *(u32 *)(e + 4);
    asm volatile("push %[k]\n\tpush $0x69d4a0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [k] "r"(k), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    return 0;
  }
  return e;
}
PCREG(50c870, fn50c870);
