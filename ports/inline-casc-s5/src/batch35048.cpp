// batch35048.cpp - cascade s5 batch 35048: 0x533e00 (GUESS allocate an entry of a 0x400-slot pool and reset its fields).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x533e00, thiscall, no arguments, returns EAX. Count [this+0x100c] == 0x400: log line 0xeb through the object at 0x700390 (slot 0x20(0x6a19bc, 0xeb), then slot 0x2c of the result with
// ECX = its vtable and caller-popped args (r, 0x6a1a10, 0x400)) and return 0. Otherwise: H = [this]; i = [this+0x1010] (free list head); [this+0x1010] = [this+0xc+4*i]; id = H slot 4();
// table [this+4][(H[0x10] & id)] = i; entry = [this+8] + i * 0xfd: +0x10 = id, +0x30/+0x34/+0x38 = 0, +0 = 0, +0x20 = +0x24 = 0, +0x28 = 1.0f, +0xe0 = +0xe4 = 0, +0xe8 = 1.0f; count++; returns id.
static u32 THISCALL fn533e00(u8 *self) {
  if (*(u32 *)(self + 0x100c) == 0x400) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x6a19bc, 0xeb);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x400\n\tpush $0x6a1a10\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    return 0;
  }
  u8 *H = *(u8 **)self;
  u32 i = *(u32 *)(self + 0x1010);
  *(u32 *)(self + 0x1010) = *(u32 *)(self + 0xc + i * 4);
  u32 id = (*(g0_t **)H)[4 / 4](H);
  H = *(u8 **)self;
  u32 *tbl = *(u32 **)(self + 4);
  tbl[*(u32 *)(H + 0x10) & id] = i;
  u32 off = i * 0xfd;
  u8 *b = *(u8 **)(self + 8);
  *(u32 *)(b + off + 0x10) = id;
  b = *(u8 **)(self + 8);
  *(u32 *)(b + off + 0x30) = 0;
  b = *(u8 **)(self + 8);
  *(u32 *)(b + off + 0x34) = 0;
  b = *(u8 **)(self + 8);
  *(u32 *)(b + off + 0x38) = 0;
  b = *(u8 **)(self + 8);
  *(u32 *)(b + off) = 0;
  b = *(u8 **)(self + 8);
  *(u32 *)(b + off + 0x20) = 0;
  *(u32 *)(b + off + 0x24) = 0;
  *(u32 *)(b + off + 0x28) = 0x3f800000;
  b = *(u8 **)(self + 8);
  *(u32 *)(b + off + 0xe0) = 0;
  *(u32 *)(b + off + 0xe4) = 0;
  *(u32 *)(b + off + 0xe8) = 0x3f800000;
  (*(u32 *)(self + 0x100c))++;
  return id;
}
PCREG(533e00, fn533e00);
