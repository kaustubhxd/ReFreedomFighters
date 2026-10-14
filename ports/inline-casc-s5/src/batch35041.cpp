// batch35041.cpp - cascade s5 batch 35041: 0x41e590 (GUESS destroy the owned object, logging when it still reports a leak).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // CRT free-style, cdecl
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// log line object: lg = [0x700390]; r = lg slot 0x20(0x677254, line) then slot 0x2c of r called with ECX = r's vtable and caller-popped args (r, fmt[, x]).
static inline u8 *log_open(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  return (*(r2_t **)lg)[0x20 / 4](lg, 0x677254, line);
}

// 0x41e590, thiscall, no arguments. C = [this+4]; nothing when null. x = C slot 0xc(); when non-zero three log lines (0xfd: 0x677278; 0xfe: 0x6772d0 with x; 0x108: 0x677278) go through the logger at
// 0x700390. Then C (reloaded) slot 0(1) when set, free([this+0x28], 4), [this+4] = [this+0x24] = [this+0x28] = 0.
static void THISCALL fn41e590(u8 *self) {
  u8 *C = *(u8 **)(self + 4);
  if (!C) return;
  u32 x = (*(g0_t **)C)[0xc / 4](C);
  if (x) {
    u8 *r = log_open(0xfd);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x677278\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    r = log_open(0xfe);
    vt = *(u32 *)r;
    slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push %[x]\n\tpush $0x6772d0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [x] "r"(x), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    r = log_open(0x108);
    vt = *(u32 *)r;
    slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x677278\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  }
  C = *(u8 **)(self + 4);
  if (C) (*(v1_t **)C)[0](C, 1);
  ext_634273(*(void **)(self + 0x28), 4);
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
}
PCREG(41e590, fn41e590);
