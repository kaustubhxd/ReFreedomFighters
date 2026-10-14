// batch34023.cpp - cascade tier E, batch 34023: 0x4fa8a0 (change a mode and notify through the engine table) and 0x50f7d0 (resolve a value from an entry by
// kind, then forward it to engine table slot 0xa0).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);          // thiscall ret 4: entry lookup
typedef u32 (*hook_t)();

// 0x4fa8a0, thiscall(v) ret 4: when [this+0x70] != v: o = this->slot0x2c4(); the engine table slot 0x4c is called with four stack arguments
// (this, &v-slot, v, 0) (callee pops them, result unused); o->slot0x2dc(0x200000); the mode [this+0x70] = v; this->slot0x2f4(v when [this+0x74] & v is non-zero, else 1).
static void THISCALL fn4fa8a0(u8 *self, u32 v) {
  if (*(u32 *)(self + 0x70) == v) return;
  u8 *o = vcall<u8 *>(self, 0x2c4);
  u32 slot = v;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vcall<u32>(tbl, 0x4c, (u32)self, (u32)&slot, v, 0u);
  vcall<void>(o, 0x2dc, 0x200000u);
  u32 w = (*(u32 *)(self + 0x74) & v) ? v : 1;
  *(u32 *)(self + 0x70) = v;
  vcall<void>(self, 0x2f4, w);
}
PCREG(4fa8a0, fn4fa8a0);

// 0x50f7d0, stdcall(a) (the final jump lets the table slot pop the argument): e = 0x5003d0([a+4], 0); by kind = byte [e+4]: 3 -> x = [e]; 4 -> x =
// [e]->slot0x34(); otherwise log through the object at 0x700390 (slot 0x20(0x69c8e0, 0x111), then its slot 0x2c with (r, 0x69c6b0, 0x69c9b0), caller-popped),
// call the assert hook (int3 when null) and x = 0. Then engine table slot 0xa0(x) is the result.
static u32 STDCALL fn50f7d0(u8 *a) {
  u8 *e = (u8 *)ext_5003d0(*(u8 **)(a + 4), 0);
  u32 x;
  u32 kind = e[4];
  if (kind == 3) {
    x = *(u32 *)e;
  } else if (kind == 4) {
    x = vcall<u32>(*(void **)e, 0x34);
  } else {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x111u);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x69c9b0\n\tpush $0x69c6b0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    x = 0;
  }
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return vcall<u32>(tbl, 0xa0, x);
}
PCREG(50f7d0, fn50f7d0);
