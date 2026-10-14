// batch35107.cpp - cascade s5 batch 35107: 0x429350 (GUESS load this object's data from stream s, with three error reports).
#include "ff.h"

typedef u32(THISCALL *c4_t)(u32 ecx, u32, u32, u32, u32);   // thiscall with ECX plus four stack args, callee pops 0x10
typedef u32(THISCALL *c2_t)(u32 ecx, u32, u32);              // ECX plus two stack args, callee pops 8
typedef u32(THISCALL *c3_t)(u32 ecx, u32, u32, u32);         // ECX plus three stack args, callee pops 0xc
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

static void log_fail(u32 line) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x678f5c, line);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push $0x679340\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

// 0x429350, thiscall(s) ret 4, returns bool (AL). s slot 0xc called with ECX = this and stack args (s, this + 0x25, this + 0xd, 0): non-zero logs line 0x426 and returns false. P = unaligned dword [this+0xd]: P slot 0x2c called with
// ECX = its vtable and stack args (P, 0x6be148): non-zero logs 0x42f, false. P slot 0x34 called with ECX = P and stack args (P, unaligned dword [engine+0x9db], 5): non-zero logs 0x43a, false. All three fine: true.
static u8 THISCALL fn429350(u8 *self, u8 *s) {
  u32 f0 = (*(u32 **)s)[0xc / 4];
  if (((c4_t)f0)((u32)self, (u32)s, (u32)(self + 0x25), (u32)(self + 0xd), 0)) {
    log_fail(0x426);
    return 0;
  }
  u32 P = rd32u(self + 0xd);
  u32 vt = *(u32 *)P;
  if (((c2_t)((u32 *)vt)[0x2c / 4])(vt, P, 0x6be148)) {
    log_fail(0x42f);
    return 0;
  }
  P = rd32u(self + 0xd);
  u8 *eng = G(u8 *, 0x70039c);
  u32 f34 = (*(u32 **)P)[0x34 / 4];
  if (((c3_t)f34)(P, P, rd32u(eng + 0x9db), 5)) {
    log_fail(0x43a);
    return 0;
  }
  return 1;
}
PCREG(429350, fn429350);
