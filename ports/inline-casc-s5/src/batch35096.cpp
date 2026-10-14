// batch35096.cpp - cascade s5 batch 35096: 0x4d36b0 (GUESS report the blocks still in use in a pool and its free size).
#include "ff.h"

extern "C" void THISCALL ext_4d29d0(u8 *self);   // plain ret
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// log line helper: lg = [0x700390]; r = lg slot 0x20(0x696418, line); r slot 0x2c called with ECX = r's vtable and the caller-popped args (r, fmt, v).
static inline void log_line(u32 line, u32 fmt, u32 v, bool ecx_is_v = false) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x696418, line);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  u32 ecxv = ecx_is_v ? v : vt;
  asm volatile("push %[v]\n\tpush %[fmt]\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(ecxv), [v] "r"(v), [fmt] "r"(fmt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

// 0x4d36b0, thiscall, no arguments. 0x4d29d0(this); then, when the size [this+0xc] is non-zero, walks the blocks from [this+8] (the first dword of a block is its size, byte +4 non-zero means in use): every block in use logs
// line 0x359 (fmt 0x696550, the text at block + 0x11); finally line 0x35c (fmt 0x69655c, [this+4] - [this+0xc]; the exe leaves ECX = that value for this one call, the other two use the vtable) and line 0x35d (fmt 0x69656c, [this+0xc]).
static void THISCALL fn4d36b0(u8 *self) {
  ext_4d29d0(self);
  u32 off = 0;
  if (*(u32 *)(self + 0xc) > off) {
    do {
      u8 *blk = *(u8 **)(self + 8) + off;
      off += *(u32 *)blk;
      if (blk[4]) log_line(0x359, 0x696550, (u32)(blk + 0x11));
    } while (off < *(u32 *)(self + 0xc));
  }
  log_line(0x35c, 0x69655c, *(u32 *)(self + 4) - *(u32 *)(self + 0xc), true);
  log_line(0x35d, 0x69656c, *(u32 *)(self + 0xc));
}
PCREG(4d36b0, fn4d36b0);
