// batch2302.cpp - unclaimed-23 batch 2 (docs/20-unclaimed-23.md): ZFFSearchLightAddActors::Init2() at 0x5c5be0. Name from the
// GC name map (high). The render-manager object o = [[0x70039c]+0x9b] gives R through its slot +0x138; R's slot +0x88 writes an
// out value. Then: X = [0x700390]->vtbl[+0x20](0x6b43b0, 0x27); X's slot +0x2c (caller cleans two arguments: 0x6b43f0 and X,
// ECX = *X); a call on this's slot +0x58; o's slot +0x114 with four arguments (chosen by this+0x4c); o's slot +0x4c (no
// arguments) returns a value; M = this+0x44 gets slot +0x12c with four arguments (out, the 16-bit result, &this+0x48,
// and M); then this's slot +0x58. The out value decides whether the X block runs. Callee pops as the PC implies.
#include "ff.h"

typedef u32(THISCALL * call0_fn)(void *);
typedef u32(THISCALL * call2r_fn)(void *, u32, u32);
typedef void(THISCALL * call2_fn)(void *, u32, u32 *);
typedef u32(THISCALL * call4_fn)(void *, u32, u32, u32, u32);
typedef void(THISCALL * call4v_fn)(void *, u32, u32, u32 *, u32);

// 0x5c5be0 (high). The 0x2c call is made in asm (ECX = *X, pushes 0x6b43f0 then X, 'add $8, %esp' afterwards), because the
// PC callee does not pop. Other calls use the callee-pops convention, as the PC has no cleanup after them.
static void THISCALL searchLightInit2(u8 *self) {
  u32 rm = G(u32, 0x70039c);
  void *o = (void *)*(u32 *)(rm + 0x9b);
  void *r = (void *)((call0_fn)(*(u32 *)(*(u32 *)o + 0x138)))(o);
  u32 out = 0;
  ((call2_fn)(*(u32 *)(*(u32 *)r + 0x88)))(r, 0x6b43a0, &out);
  if (out == 0) {
    void *g = (void *)G(u32, 0x700390);
    u32 x = ((call2r_fn)(*(u32 *)(*(u32 *)g + 0x20)))(g, 0x6b43b0, 0x27);
    u32 vx = *(u32 *)x;
    u32 target = *(u32 *)(vx + 0x2c);
    asm volatile("push $0x6b43f0\n\tpush %[x]\n\tcall *%[fn]\n\tadd $8, %%esp"
                 :
                 : "c"(vx), [x] "r"(x), [fn] "r"(target)
                 : "eax", "edx", "memory", "cc");
    ((call0_fn)(*(u32 *)(*(u32 *)self + 0x58)))(self);
  }
  u32 r114;
  if (*(u32 *)(self + 0x4c) != 0)
    r114 = ((call4_fn)(*(u32 *)(*(u32 *)o + 0x114)))(o, 0x6b4438, 0, 0x6b43b0, 0x2f);
  else
    r114 = ((call4_fn)(*(u32 *)(*(u32 *)o + 0x114)))(o, 0x6b444c, 0, 0x6b43b0, 0x33);
  u32 edi = (u16)r114;
  u32 m = *(u32 *)(self + 0x44);
  u32 loc = *(u32 *)(self + 0x48);
  ((call0_fn)(*(u32 *)(*(u32 *)o + 0x4c)))(o);
  ((call4v_fn)(*(u32 *)(*(u32 *)m + 0x12c)))((void *)m, out, edi, &loc, m);
  ((call0_fn)(*(u32 *)(*(u32 *)self + 0x58)))(self);
}
PCREG(5c5be0, searchLightInit2);
