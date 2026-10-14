// u69_79.cpp - area 69, group 79 (slice 8). Six open residue-8 functions. Other areas' callees are GUESS stubs in the spec unless noted.
#include "ff.h"

extern "C" void ext_630000(u32 a);                              // cdecl, one arg (GUESS stub)
extern "C" void ext_62f390(u32 a);                              // cdecl, one arg (GUESS stub)
extern "C" void THISCALL ext_4de7a0(void *self);                // thiscall, no args, ret (GUESS stub)
extern "C" u32 THISCALL ext_4df330(void *self, u32 a, u32 b, u32 c, u32 d);   // thiscall, four args, ret 0x10 (GUESS stub)

// 0x62d5c0, cdecl (obj, code; plain ret). idx = code - 0xf; in 0..0x1a the byte table 0x62d66c gives a case 0..6, else the default case.
static u32 dispatch62d5c0(u8 *obj, u32 code) {
  u32 idx = code - 0xf;
  u32 c = 6;
  if (idx <= 0x1a)
    c = *(const u8 *)(0x62d66c + idx);
  switch (c) {
  case 0:
    return 0;
  case 1:
    *(u32 *)obj = 0x62d690;
    return 0x2e;
  case 2:
    *(u32 *)(obj + 4) += 1;
    return 0x27;
  case 3:
    *(u32 *)obj = 0x62d690;
    return 0x30;
  case 4:
    *(u32 *)obj = 0x62d690;
    return 0x2f;
  case 5:
    *(u32 *)obj = 0x62d690;
    return 0x31;
  default:
    if (*(u32 *)(obj + 0xc) == 0 && code == 0x1c)
      return 0x34;
    *(u32 *)obj = 0x51f230;
    return 0xffffffffu;
  }
}
PCREG(62d5c0, dispatch62d5c0);

// 0x62f140, stdcall one arg (ret 4). ecx is loaded from the arg, so the body uses the arg as the object.
static s32 STDCALL walk62f140(u8 *obj) {
  if (obj == 0)
    return -2;
  u8 *esi = *(u8 **)(obj + 0x1c);
  if (esi == 0)
    return -2;
  if (*(u32 *)(obj + 0x20) == 0)
    return -2;
  if (*(u32 *)(obj + 0x24) == 0)
    return -2;
  *(u32 *)(obj + 0x14) = 0;
  *(u32 *)(obj + 8) = 0;
  *(u32 *)(obj + 0x18) = 0;
  *(u32 *)(obj + 0x2c) = 2;
  s32 f18 = *(s32 *)(esi + 0x18);
  *(u32 *)(esi + 0x14) = 0;
  *(u32 *)(esi + 0x10) = *(u32 *)(esi + 8);
  if (f18 < 0)
    *(u32 *)(esi + 0x18) = 0;
  *(u32 *)(esi + 4) = (*(s32 *)(esi + 0x18) != 0) ? 0x71 : 0x2a;
  *(u32 *)(obj + 0x30) = 1;
  *(u32 *)(esi + 0x20) = 0;
  ext_630000((u32)esi);
  ext_62f390((u32)esi);
  return 0;
}
PCREG(62f140, walk62f140);

// 0x427140: naked forwarder with no frame. The exe does `push ebp; mov ebp,esp; mov eax,[ecx]; pop ebp; jmp [eax+0x13c]`,
// which nets to: load the vtable from ECX and jump to slot 0x13c with the caller's stack untouched. The callee cleans the
// stack, so the arity is the callee's, and call sites push one argument. A C wrapper cannot forward stack arguments, so this is asm.
extern "C" void tail427140(void);
__asm__(
    ".text\n"
    ".globl tail427140\n"
    "tail427140:\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x13c(%eax)\n");
PCREG(427140, tail427140);

// 0x608e00, cdecl no args. CPUID leaf 1: the result is bit 25 of EDX (SSE). Host-dependent: both sides execute the emulator's CPUID.
static u32 cpuidSse608e00(void) {
  u32 a = 1, b = 0, c = 0, d = 0;
  __asm__ volatile("cpuid" : "+a"(a), "=b"(b), "+c"(c), "=d"(d));
  return (d >> 25) & 1;
}
PCREG(608e00, cpuidSse608e00);

// 0x40fe00, cdecl (arr, n; plain ret). arr[0] *= 0.5; then for k = 2..n: a backward pass over arr with arr[j-2] -= arr[j] and arr[j] *= 2
// (single-precision stores, the arithmetic in double).
static void scale40fe00(float *arr, s32 n) {
  arr[0] = (float)((double)arr[0] * (double)*(const float *)0x6bdffc);
  if (n < 2)
    return;
  for (s32 k = 2; k <= n; ++k) {
    s32 cnt = n - k + 1;
    float *p = arr + n;
    do {
      p[-2] = (float)((double)p[-2] - (double)p[0]);
      p[0] = (float)((double)p[0] + (double)p[0]);
      p -= 1;
      --cnt;
    } while (cnt != 0);
  }
}
PCREG(40fe00, scale40fe00);

// 0x45b080, thiscall three stack args (ret 0xc), ECX = self. Calls 0x4de7a0 with ECX = a local struct S, then 0x4df330 with ECX = S and args
// (self+0x18, a1, a2, a3). The stack-cookie check (0x633654) is not modelled: it has no effect when the cookie is intact.
static void THISCALL call45b080(u8 *self, u32 a1, u32 a2, u32 a3) {
  u8 S[0x40];
  ext_4de7a0(S);
  ext_4df330(S, (u32)(self + 0x18), a1, a2, a3);
}
PCREG(45b080, call45b080);
