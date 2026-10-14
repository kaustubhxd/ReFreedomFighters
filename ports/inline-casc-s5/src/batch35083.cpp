// batch35083.cpp - cascade s5 batch 35083: 0x425250 (GUESS fatal error report: log, optional exit, message box, exit(-1)).
#include "ff.h"

extern "C" void ext_42abee(char *buf, const char *fmt, u32 *va);   // cdecl, vsprintf-style
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);
typedef u8(THISCALL *b0_t)(void *);
typedef u8(THISCALL *b2_t)(void *, u32, u32);
typedef void(THISCALL *v0_t)(void *);
typedef u32(STDCALL *mbox_t)(u32, const char *, u32, u32);
typedef void(*exit_t)(s32);

// 0x425250, cdecl(unused, fmt, ...), does not return in the exe (exit). buf (0x400 bytes) = 0x42abee(buf, fmt, address of the first variable argument). Log line 0x8b through the object at 0x700390 (slot 0x20(0x6786c4, 0x8b),
// then slot 0x2c of the result with ECX = its vtable and caller-popped (r, 0x6786f8, buf)); when [0x700390] slot 0x44() is true: int3. [0x70039c] slot 0x3c(); when [0x70039c] slot 0x5c(0x6783ec, 0) is true exit(-1)
// (IAT 0x676374). MessageBoxA(0, buf, 0x678018, 0x40010); [0x70039c] slot 0x14(); exit(-1).
static void fn425250(u32 unused, const char *fmt, u32 va0) {
  char buf[0x400];
  (void)unused;
  ext_42abee(buf, fmt, &va0);
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x6786c4, 0x8b);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[buf]\n\tpush $0x6786f8\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [buf] "r"(buf), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  lg = G(u8 *, 0x700390);
  if ((*(b0_t **)lg)[0x44 / 4](lg)) __asm__ volatile("int3");
  u8 *eng = G(u8 *, 0x70039c);
  (*(v0_t **)eng)[0x3c / 4](eng);
  eng = G(u8 *, 0x70039c);
  if ((*(b2_t **)eng)[0x5c / 4](eng, 0x6783ec, 0)) G(exit_t, 0x676374)(-1);
  G(mbox_t, 0x6761bc)(0, buf, 0x678018, 0x40010);
  eng = G(u8 *, 0x70039c);
  (*(v0_t **)eng)[0x14 / 4](eng);
  G(exit_t, 0x676374)(-1);
}
PCREG(425250, fn425250);
