// batch34029.cpp - cascade tier E, batch 34029: 0x4d6250, a grow-by-doubling for an array of 42-byte records.
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);                             // cdecl alloc
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
extern "C" void ext_41e2c0(void *p);                             // cdecl free

// 0x4d6250, thiscall, no args: [this] = capacity (records of 0x2a bytes), [this+8] = data. Allocates 2*capacity records (size saturates at 0xffffffff on overflow);
// a failed allocation logs through the object at 0x700390 (slot 0x20(0x696770, 0x14f), then its slot 0x2c with (r, 0x696be8), caller-popped) and carries on;
// copies capacity*0x2a bytes (32-bit product) into the new block, frees the old one, [this] = 2*capacity, [this+8] = new block.
static void THISCALL fn4d6250(u8 *self) {
  u32 edi = *(u32 *)self + *(u32 *)self;
  u64 m = (u64)edi * 0x2a;
  u32 size = (m >> 32) ? 0xffffffffu : (u32)m;
  u8 *p = (u8 *)ext_41e290(size);
  if (!p) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x696770u, 0x14fu);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x696be8\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  }
  ext_634d22(p, *(u8 **)(self + 8), *(u32 *)self * 0x2a);
  u8 *old = *(u8 **)(self + 8);
  *(u32 *)self = edi;
  ext_41e2c0(old);
  *(u8 **)(self + 8) = p;
}
PCREG(4d6250, fn4d6250);
