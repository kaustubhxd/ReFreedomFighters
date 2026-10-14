// batch37107.cpp - cascade s6 batch 37107: 0x604e10.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);           // ret 4
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);   // allocate
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 flag);   // release
typedef u32 (*hook_t)();
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static u32 slen(const u8 *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x604e10, thiscall(a) ret 4: script op "concatenate two strings". a+4 must carry exactly two arguments (else error 0xd7 and the assert hook). The two string objects' texts
// (+0xc) are joined into this object's buffer (+0xc, capacity word at +0x10, re-allocated through 0x634273 / 0x41e290 when the joined text and its NUL do not fit) and a clone
// of this object (slot 0x24) is stored in the result node a+8 unless that node holds something other than nothing or an object (an object it holds is released with slot 0x28).
static void THISCALL fn604e10(u8 *self, u8 *a) {
  u8 *args = *(u8 **)(a + 4);
  if (D32(args, 8) != 2) {
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6b9c38, 0xd7);
    (*(cd3_t **)L)[0x2c / 4](L, 0x69c6b0, 0x6b9c6c);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    return;
  }
  u8 *s1 = (u8 *)D32(ext_5003d0((u32)args, 0), 0);
  u8 *s2 = (u8 *)D32(ext_5003d0((u32)args, 1), 0);
  u8 *t1 = *(u8 **)(s1 + 0xc);
  u8 *t2 = *(u8 **)(s2 + 0xc);
  u32 total = slen(t1) + 1 + slen(t2);
  if ((s32)total > (s32)*(u16 *)(self + 0x10)) {
    ext_634273(*(void **)(self + 0xc), 1);
    *(void **)(self + 0xc) = ext_41e290(total);
    *(u16 *)(self + 0x10) = (u16)total;
  }
  u8 *dst = *(u8 **)(self + 0xc);
  u8 *p = *(u8 **)(s1 + 0xc);
  while ((*dst++ = *p++)) {}
  u32 l1 = slen(*(u8 **)(s1 + 0xc));
  dst = *(u8 **)(self + 0xc) + l1;
  p = *(u8 **)(s2 + 0xc);
  while ((*dst++ = *p++)) {}
  u8 *n = ext_5003d0(*(u32 *)(a + 8), 0);
  u8 ty = n[4];
  if (ty != 0) {
    if (ty != 4) return;
    vcall<void>((void *)D32(n, 0), 0x28);
  }
  D32(n, 0) = vcall<u32>(self, 0x24);
  n[4] = 4;
}
PCREG(604e10, fn604e10);
