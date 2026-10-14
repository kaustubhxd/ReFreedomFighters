// batch35031.cpp - cascade s5 batch 35031: 0x5f52f0 (GUESS hand out the next slot of a pool and store a value in it).
#include "ff.h"

extern "C" void ext_42ab62(u32 a);   // cdecl, one argument
typedef u32 (*hook_t)();
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x5f52f0, thiscall(p) ret 4, returns the slot. Pool: [this] array of 8-byte entries, [this+4] capacity, [this+8] next index. Index >= capacity: 0x42ab62(0x6b89b4) and the assert hook (int3 when
// null). e = entries + 8 * i; [this+8] = i + 1. Entry kind byte e[4] of 0 or 2: *(u32 *)e = *p, e[4] = 2. Any other kind: log line through the object at 0x700390 (slot 0x20(0x69c8e0, 0xd5) then
// slot 0x2c of the result with ECX = its vtable and caller-popped args (r, 0x69c6b0, 0x69c938)) and the assert hook. Returns e.
static u8 *THISCALL fn5f52f0(u8 *self, u32 *p) {
  if (*(u32 *)(self + 8) >= *(u32 *)(self + 4)) {
    ext_42ab62(0x6b89b4);
    assert_hook();
  }
  u32 i = *(u32 *)(self + 8);
  u8 *e = *(u8 **)self + i * 8;
  *(u32 *)(self + 8) = i + 1;
  u8 k = e[4];
  if (k == 0 || k == 2) {
    *(u32 *)e = *p;
    e[4] = 2;
    return e;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0xd5);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push $0x69c938\n\tpush $0x69c6b0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  assert_hook();
  return e;
}
PCREG(5f52f0, fn5f52f0);
