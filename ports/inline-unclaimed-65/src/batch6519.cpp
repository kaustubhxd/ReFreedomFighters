// batch6519.cpp - unclaimed-65: batch 19 (docs/20-unclaimed-65.md, claim 19): ZItem::ClassInit2() (0x46bca0), the whole function
// lifted; branch group 1 (the first 0x2e8 result is zero, 46bce7 to 46bd45) is the only one verified so far (see the doc for groups 2 to 4).
// The SEH prolog 0x6336b0 and the cookie 0x633654 are not reproduced (tagged in the doc).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }
static u32 vc3(u8 *o, u32 s, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c); }

// a call with `self` in ecx and three stack arguments that the CALLER removes (add esp, 0xc follows the original call)
static void callCallerCleans3(u8 *self, u32 fn, u32 a, u32 b, u32 c) {
  asm volatile(
      "pushl %[c]\n\t"
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%[fn]\n\t"
      "addl $12, %%esp\n\t"
      :
      : "c"(self), [fn] "r"(fn), [a] "r"(a), [b] "r"(b), [c] "r"(c)
      : "eax", "edx", "memory", "cc");
}

extern "C" void THISCALL ext_45d3a0(u8 *s);                  // plain thiscall, no args
extern "C" u32 THISCALL ext_4cc1d0(u8 *p);                   // plain, returns the first dword of p
extern "C" void THISCALL ext_4cbec0(u8 *p);                  // plain (sets edx and eax; the port does not use them)
extern "C" void THISCALL ext_4d2280(u8 *s);                  // plain thiscall, no args
extern "C" void THISCALL ext_4d3ab0(u8 *s, u32 a, u32 b);    // thiscall, two arguments (ret 8)
extern "C" void THISCALL ext_4d2330(u8 *s);                  // plain thiscall, no args

// 0x46bca0, ZItem::ClassInit2(). Locals: S is the struct at ebp-0x41d4 (to ebp-0x0c), R the dword at ebp-0x41e0,
// L90 at ebp-0x90 and L110 at ebp-0x110. See docs/20-unclaimed-65.md (claim 19) for the call-site table.
static void THISCALL classInit2(u8 *self) {
  u8 S[0x41c8];
  u32 R = 0;
  u8 L90[0x80];
  u8 L110[0x80];

  ext_45d3a0(self);
  // group 1: the first 0x2e8 result is zero
  if (vc0(self, 0x2e8) == 0) {
    u8 *obj = (u8 *)vc2(G(u8 *, 0x700390), 0x20, 0x6887c4, 0x32e);
    u8 *p = (u8 *)vc2(self, 0x1d8, (u32)L90, 1);
    const u32 v = ext_4cc1d0(p);
    callCallerCleans3(p, *(const u32 *)(*(const u32 *)obj + 0x2c), (u32)obj, 0x6888b0, v);
    ext_4cbec0(L90);
    vc1(self, 0x210, 1);
    return;
  }

  // group 1 (continued): the second 0x2e8 result goes to the 0x2ec test; zero takes the 0x334 path
  if ((vc1(self, 0x2ec, vc0(self, 0x2e8)) & 0xff) == 0) {
    u8 *obj = (u8 *)vc2(G(u8 *, 0x700390), 0x20, 0x6887c4, 0x334);
    u8 *p = (u8 *)vc2(self, 0x1d8, (u32)L110, 1);
    const u32 v = ext_4cc1d0(p);
    callCallerCleans3(p, *(const u32 *)(*(const u32 *)obj + 0x2c), (u32)obj, 0x6888e4, v);
    ext_4cbec0(L110);
    vc1(self, 0x210, 1);
    return;
  }

  // group 2: 46bdaf to 46bdf4
  vc0(self, 0x2fc);
  ext_4d2280(S);
  ext_4d3ab0(S, 0x68884c, *(const u32 *)(self + 0x5c));
  vc2(self, 0x168, *(const u16 *)(self + 0x7c), (u32)S);

  // group 3: 46bdf4 to 46be76, the render slot 0x58 and the loop over the object at this+0x78
  u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *s = (u8 *)vc1(render, 0x58, *(const u32 *)(self + 0x60));
  if (*(u8 **)(self + 0x78) != 0) {
    vc1(*(u8 **)(self + 0x78), 0x4c, (u32)&R);
    u32 x = vc1(*(u8 **)(self + 0x78), 0x64, (u32)&R);
    while (x != 0) {
      u8 *y = (u8 *)vc1(G(u8 *, 0x70038c), 0xcc, *(const u32 *)x);
      const u32 edi = *(const u32 *)(y + 0x44);
      vc1(*(u8 **)(self + 0x78), 0x44, (u32)&R);
      if (s != 0) vc2(s, 0x2e8, (u32)self, edi);
      x = vc1(*(u8 **)(self + 0x78), 0x64, (u32)&R);
    }
  }

  // group 4: 46be78 to 46befb, the tail
  vc3(self, 0x2f0, *(const u32 *)(self + 0x64), 0, 1);
  vc2(self, 0x110, 0x10, 0);
  vc0(self, 0x40);
  *(u32 *)(*(u8 **)(self + 0x10) + 0x18) |= 1;
  u8 *v = (u8 *)vc0(self, 0x2e8);
  u8 *t = (u8 *)vc2(v, 0x25c, 0x688860, 0);
  if (t != 0 && vc0(self, 0x2dc) == 0) {
    u8 *render2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    const u32 q = vc1(render2, 0x4c, (u32)t);
    vc1(self, 0x2d8, q);
  }
  ext_4d2330(S);
}

PCREG(46bca0, classInit2);
