// batch6512.cpp - unclaimed-65: batch 12 (docs/20-unclaimed-65.md, claim 13): ZRepositionCharacter::Reposition, the whole function
// lifted; branch group 1 (the render slot +0x58 result is zero) is the only one verified so far (see the doc for groups 2 to 4).
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *F4)(u8 *self, u32 a, u32 b, u32 c, u32 d);

static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }
static u32 vc3(u8 *o, u32 s, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c); }
static u32 vc4(u8 *o, u32 s, u32 a, u32 b, u32 c, u32 d) { return ((F4)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c, d); }

// a call with `self` in ecx and two stack arguments that the CALLER removes (add esp, 8 follows the original call)
static void callCallerCleans2(u8 *self, u32 fn, u32 a, u32 b) {
  asm volatile(
      "pushl %[b]\n\t"
      "pushl %[a]\n\t"
      "call *%[fn]\n\t"
      "addl $8, %%esp\n\t"
      :
      : "c"(self), [fn] "r"(fn), [a] "r"(a), [b] "r"(b)
      : "eax", "edx", "memory", "cc");
}

extern "C" void THISCALL ext_4de7a0(u8 *s);         // plain thiscall, no args (sets +8 to 1.0)
extern "C" void THISCALL ext_5d1440(u8 *s);         // plain thiscall, no args
extern "C" u32 THISCALL ext_589c20(u8 *self, u32 a);  // thiscall, one argument (ret 4)
extern "C" u32 THISCALL ext_59a580(u8 *self, u32 a, u32 b, u32 c);  // thiscall, three arguments (ret 0xc)

// 0x5c4290, ZRepositionCharacter::Reposition() (residue 17). See docs/20-unclaimed-65.md (claim 13) for the layout.
static void THISCALL repositionCharacter(u8 *self) {
  u8 *a = *(u8 **)(self + 0x48);
  const u32 v = vc0(a, 0x14);
  if (v == *(const u32 *)(self + 0x4c)) *(u32 *)(self + 0x4c) = 0;
  const u32 q = vc1(a, 0x30, *(const u32 *)(self + 0x4c));
  u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  const u32 s = vc1(render, 0x58, q);
  if (s == 0) {
    u8 *g = G(u8 *, 0x700390);
    const u32 x = vc2(g, 0x20, 0x6b3fe0, 0x53);
    const u32 xvt = *(const u32 *)x;
    callCallerCleans2((u8 *)xvt, *(const u32 *)(xvt + 0x2c), x, 0x6b4020);
    return;
  }

  // group 2 onwards: the struct at ebp-0x34 (fr[0..8] with +8 = 1.0 from 0x4de7a0), L10 = fr[9], L0c = fr[10], L8 = fr[11]
  u32 fr[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  u32 *L10 = &fr[9];
  u32 edi = 0;
  ext_4de7a0((u8 *)fr);
  vc2((u8 *)s, 0x80, (u32)fr, (u32)L10);
  u8 *b = *(u8 **)(self + 0x50);
  if (vc1(b, 0x1e0, 0x2003e8) & 0xff) {
    edi = (u32)*(u8 **)(self + 0x50);
    u8 *bb = (u8 *)edi;
    if (*(const u32 *)(bb + 0x85a) == 0) *(u32 *)(bb + 0x85a) = vc1(bb, 0x100, 0x6a6e88);
    ext_5d1440(*(u8 **)(bb + 0x85a));
  }
  vc2(*(u8 **)(self + 0x50), 0x370, (u32)fr, (u32)L10);

  u8 *rm = G(u8 *, 0x70039c);
  u8 *pX = *(u8 **)(rm + 0x190f);
  u8 *Y = (u8 *)vc0(pX, 0x20);
  (void)vc0(Y, 0x64);

  u8 *zobj = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u32 l38 = vc2(zobj, 0x25c, 0x685f44, 0);
  if (l38) {
    u8 *w = (u8 *)l38;
    u8 *rr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    const u32 word = (u16)vc4(rr, 0x114, 0x68c098, 0, 0x6b3fe0, 0x68);
    vc3(w, 0x128, word, 0, 0);   // the two zeros pushed before the 0x114 call are the 2nd and 3rd arguments (ret 0xc)
  }
  const u8 lowb = edi ? (u8)(*(const u8 *)(edi + 0x684) - 1) : 0;
  l38 = (l38 & ~0xffu) | lowb;
  const u32 r = ext_589c20(G(u8 *, 0x7003b8), l38);
  const u32 nn = *(const u32 *)(s + 4);
  ext_59a580((u8 *)r, nn ? nn : 0x67c8e8, 0xffffffffu, 0);
  *(u32 *)(self + 0x4c) += 1;
}
PCREG(5c4290, repositionCharacter);
