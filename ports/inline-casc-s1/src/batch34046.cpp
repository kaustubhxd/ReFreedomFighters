// batch34046.cpp - cascade tier E, batch 34046: 0x486c30 (map a key to one of seven fields), 0x4d2680 (pack two byte blocks into a stack message and send it),
// 0x4d87c0 (set a flag byte from a parsed number, or log it).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
extern "C" void THISCALL ext_4d2820(void *self, void *msg);       // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                  // /GS check
extern "C" u32 THISCALL ext_4cc1d0(void *p);                      // thiscall, plain ret: returns [p]
typedef u32 (*hook_t)();
typedef long(*atol_t)(const char *);

// 0x486c30, thiscall(k) ret 4, returns the 1-based position of k among the fields +0x10, +0x14, +0x18, +0x1c, +0x24, +0x20, +0x28 (checked in that order -> 1, 2, 3, 4, 5, 6, 7);
// anything else calls the assert hook (int3 when null) and returns its result.
static u32 THISCALL fn486c30(u8 *self, u32 k) {
  if (k == *(u32 *)(self + 0x10)) return 1;
  if (k == *(u32 *)(self + 0x14)) return 2;
  if (k == *(u32 *)(self + 0x18)) return 3;
  if (k == *(u32 *)(self + 0x1c)) return 4;
  if (k == *(u32 *)(self + 0x24)) return 5;
  if (k == *(u32 *)(self + 0x20)) return 6;
  if (k == *(u32 *)(self + 0x28)) return 7;
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(486c30, fn486c30);

// 0x4d2680, thiscall(a, b, c, d, e) ret 0x14: builds a message on the stack: {b, c, d, bytes of a (b of them), bytes of e (d of them)} (two memcpy calls, then the three header dwords),
// 0x4d2820(this, message) and the /GS check.
static void THISCALL fn4d2680(u8 *self, u8 *a, u32 b, u32 c, u32 d, u8 *e) {
  u8 *msg = (u8 *)__builtin_alloca(d + 0xc + b);
  ext_634d22(msg + 0xc, a, b);
  ext_634d22(msg + 0xc + b, e, d);
  *(u32 *)(msg + 4) = c;
  *(u32 *)(msg + 8) = d;
  *(u32 *)msg = b;
  ext_4d2820(self, msg);
  ext_633654(0);
}
PCREG(4d2680, fn4d2680);

// 0x4d87c0, thiscall(p) ret 4: when p: flag = atol(p) != 0 (import 0x6762e0) stored into the byte at [this+0x104]. Otherwise logs: r = logger(0x700390)->slot0x20(0x696c88, 0xd4), t = this->slot4(ptr,
// the byte at ptr) (ptr = [this+0x104], caller-popped), x = 0x4cc1d0(t), r's slot 0x2c called with ECX = t (the slot 4 result) and stack (r, 0x696d80, x), caller-popped.
static void THISCALL fn4d87c0(u8 *self, const char *p) {
  if (p) {
    long v = G(atol_t, 0x6762e0)(p);
    u8 *flag = *(u8 **)(self + 0x104);
    *flag = v != 0;
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x696c88u, 0xd4u);
  u8 *ptr = *(u8 **)(self + 0x104);
  u32 vt = *(u32 *)r;
  u32 byte = *ptr;
  u32 sv = *(u32 *)self;
  u32 slot4 = ((u32 *)sv)[1];
  u32 t;
  asm volatile("push %[b]\n\tpush %[p]\n\tcall *%[fn]\n\tadd $8, %%esp" : "=a"(t) : "c"(self), [b] "r"(byte), [p] "r"(ptr), [fn] "r"(slot4) : "edx", "memory", "cc");
  u32 x = ext_4cc1d0((void *)t);
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[x]\n\tpush $0x696d80\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(t), [x] "r"(x), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(4d87c0, fn4d87c0);
