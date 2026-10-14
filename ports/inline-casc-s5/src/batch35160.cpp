// batch35160.cpp - cascade s5 batch 35160: 0x50c200 (GUESS apply a record flag to an engine entry, logging when it is missing).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef u8(THISCALL *b1_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *l2_t)(void *, u32, u32);

// 0x50c200, stdcall(a) ret 4, no return value. id = [0x5003d0(a[4], 0)]; e = engine[+0x9b] slot 0x58(id). When e is non-null and e slot 0x1e0(0x1007d1) is true: e slot 0x300([0x5003d0(a[4], 1)] != 0).
// Otherwise the logger (0x700390) slot 0x20(0x69d420, 0x4b8) returns r and slot 0x2c(r, 0x69da80) is called with ECX = the vtable, caller-popped.
static void STDCALL fn50c200(u8 *a) {
  u32 id = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 0);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *e = (*(e1_t **)tab)[0x58 / 4](tab, id);
  if (e && (*(b1_t **)e)[0x1e0 / 4](e, 0x1007d1)) {
    u32 v = *(u32 *)ext_5003d0(*(u32 *)(a + 4), 1);
    (*(v1_t **)e)[0x300 / 4](e, v != 0);
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(l2_t **)lg)[0x20 / 4](lg, 0x69d420, 0x4b8);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push $0x69da80\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(50c200, fn50c200);
