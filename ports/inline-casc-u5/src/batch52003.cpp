// batch52003.cpp - cascade tier H, batch 52003: 0x52b170 (run 0x52e830 on a lifted segment, with logging/assert paths).
#include "ff.h"

extern "C" u32 THISCALL ext_52e830(void *self, float *a, float *b, float f, u32 x, u32 y, void *p, void *t);  // ret 0x1c
extern "C" void THISCALL ext_52b080(void *self);                                                              // plain thiscall
extern "C" void FASTCALL ext_633654(u32 cookie);                                                              // /GS check
typedef u32 (*hook_t)();

// Log through the object at 0x700390: r = slot 0x20(file, line), then r's slot 0x2c (caller-cleans, ECX = r's vtable) with (r, fmt).
static inline void log2(u32 file, u32 line, u32 fmt) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, file, line);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[a2]\n\tpush %[a1]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [a1] "r"((u32)r), [a2] "r"(fmt), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}

static inline void call_assert() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x52b170, thiscall(P, Q, f, a, b, S, T) ret 0x1c, /GS. P and Q are float[3]; the two vectors A = (P0, h + P1, P2), B = (Q0, h + Q1, Q2) with h = [this+0x20].
// this[0x24] set: log (0x6a0f54, 0x236f, 0x6a103c), return 0. [0x701b4d] set: assert hook, return 0.
// Else clear S[0x4d..0x50] (and S[0x48] with S[0x49..0x4c] when S[0x48] is set); this[0x31] clear: log (0x6a0f54, 0x2383, 0x6a1190), assert hook, ext_52b080(S), return 0.
// Else r = ext_52e830 with ECX = [this+0x65] (unaligned) and (&A, &B, f, a, b, S + 0x51, T); S[0x99] clear: return 0; else ext_52b080(S) and return r.
static u32 THISCALL fn52b170(u8 *self, float *P, float *Q, float f, u8 a, u8 b, u8 *S, u8 *T) {
  u32 res = 0;
  if (self[0x24]) {
    log2(0x6a0f54, 0x236f, 0x6a103c);
    ext_633654(0);
    return 0;
  }
  float h = *(float *)(self + 0x20);
  float A[3], B[3];
  A[0] = P[0]; A[2] = P[2]; B[0] = Q[0]; B[2] = Q[2];
  A[1] = h + P[1];
  B[1] = h + Q[1];
  if (G(u8, 0x701b4d)) {
    call_assert();
    ext_633654(0);
    return 0;
  }
  S[0x4d] = 0; S[0x4e] = 0; S[0x4f] = 0; S[0x50] = 0;
  if (S[0x48]) {
    S[0x48] = 0;
    S[0x49] = 0; S[0x4a] = 0; S[0x4b] = 0; S[0x4c] = 0;
  }
  if (self[0x31]) {
    u32 ec = self[0x65] | self[0x66] << 8 | self[0x67] << 16 | (u32)self[0x68] << 24;
    res = ext_52e830((void *)ec, A, B, f, a, b, S + 0x51, T);
    if (S[0x99]) {
      ext_52b080(S);
      ext_633654(0);
      return res;
    }
    ext_633654(0);
    return 0;
  }
  log2(0x6a0f54, 0x2383, 0x6a1190);
  call_assert();
  ext_52b080(S);
  ext_633654(0);
  return 0;
}
PCREG(52b170, fn52b170);
