// batch238.cpp - area 59 (residue 18), docs/20-unclaimed-59.md. Three one-word reads of rows of a[+4] (rows 2, 1, 0) into a
// float triple; a vtable call (0x84) writing a 3-dword struct; the middle float replaced by the struct's second dword;
// 0x43e920 and 0x4de040 on stack objects; and a vtable call (0x7c) on the object and the struct. Name GUESS.
// SEH frame not reproduced: the original builds a SEH frame and a security cookie (0x633654), which this port does not
// do; the cookie check has no effect on the results. The stack-local objects are the port's own locals.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);
extern "C" void THISCALL ext_43e920(u8 *self, u8 *p);       // original, thiscall, one stack word (ret 4)
extern "C" void FASTCALL ext_4de040(u8 *a, u8 *b, u32 c);   // original, fastcall (ecx, edx) plus one stack word (ret 4)

// 0x5035a0, thiscall(a) ret 4.
static void THISCALL triple_5035a0(u8 *self, u8 *a) {
  u8 *r2 = ext_5003d0(*(u8 **)(a + 4), 2);
  u8 *r1 = ext_5003d0(*(u8 **)(a + 4), 1);
  u8 *r0 = ext_5003d0(*(u8 **)(a + 4), 0);
  float L[3];
  L[0] = *(float *)r0;
  L[1] = *(float *)r1;
  L[2] = *(float *)r2;
  u32 s[3] = {0, 0, 0};
  vcall<void>(*(u8 **)(self + 0xc), 0x84, (u32)s);
  L[1] = *(float *)&s[1];
  u8 local1c[16];
  u8 local40[16];
  ext_43e920(local1c, (u8 *)L);
  ext_4de040(local40, local1c, 0);
  vcall<void>(*(u8 **)(self + 0xc), 0x7c, (u32)local40, (u32)s);
}
PCREG(5035a0, triple_5035a0);
