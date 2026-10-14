// batch35108.cpp - cascade s5 batch 35108: 0x427dc0 (GUESS open a file for appending, logging failures).
#include "ff.h"

typedef u32(STDCALL *create_t)(u32, u32, u32, u32, u32, u32, u32);
typedef u32(STDCALL *seek_t)(u32, u32, u32, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static void log_open(u32 line, u32 fmt, u32 path) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x6789ac, line);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[p]\n\tpush %[fmt]\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [p] "r"(path), [fmt] "r"(fmt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

// 0x427dc0, stdcall(path) ret 4, returns the handle or 0. h = CreateFileA(path, GENERIC_WRITE 0x40000000, 0, 0, OPEN_ALWAYS 4, 0x80, 0) (IAT 0x676068); -1 logs line 0x48 (fmt 0x678a34, path) and returns 0.
// Otherwise SetFilePointer(h, 0, 0, FILE_END 2) (IAT 0x67611c); -1 logs line 0x4c (fmt 0x678a70, path); the handle is returned either way.
static u32 STDCALL fn427dc0(u32 path) {
  u32 h = (*(create_t *)0x676068)(path, 0x40000000, 0, 0, 4, 0x80, 0);
  if (h == 0xffffffff) {
    log_open(0x48, 0x678a34, path);
    return 0;
  }
  if ((*(seek_t *)0x67611c)(h, 0, 0, 2) == 0xffffffff) log_open(0x4c, 0x678a70, path);
  return h;
}
PCREG(427dc0, fn427dc0);
