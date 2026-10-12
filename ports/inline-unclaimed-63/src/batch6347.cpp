// batch6347.cpp - unclaimed-63 gap-band batch 47: 0x4d95f0 (A+D+E set; no GC name), thiscall, two stack arguments X and f (a float), ret 8.
//   If this[+0x3c] & 0x200c00: return. w = this u16[+0x5c]. If w != 0: r = O1->vtbl[+0x5c](w), where O1 = [[[0x70039c]+0x9b]+8].
//   If w == 0 or r == 0: p = O1->vtbl[+0x50](); this u16[+0x5c] = p ? O1->vtbl[+0x58](p) : 0 (thiscall calls).
//   R = (u16 this[+0x5c]) != 0 ? O1->vtbl[+0x5c](w) : 0. If R[+0x1c] (byte) >= 6: return. If < 3: R[count + 0x1d] = (u8)(int)(f * [0x697098]).
//   R[count] = X (dword index count) and R[+0x1c] += 1. X->vtbl[+0x368]() (thiscall, no arguments, plain ret). Then 0x4d9d20 with
//   ECX = this and one stack argument X, ret 4 (original code, stubbed by the spec). X's vtable slot +0x368 is called with ECX = X and
//   one stack argument, this (thiscall, ret 4).
#include "ff.h"

extern "C" u32 THISCALL ext_4d9d20(void *self, u32 x);   // thiscall, one stack argument, ret 4 (checked: the callee ends with ret 4), stubbed by the spec

typedef u32(THISCALL * q_fn)(void *, u32);
typedef void(THISCALL * noarg_fn)(void *);
typedef void(THISCALL * one_fn)(void *, u32);
typedef u32(THISCALL * noret_fn)(void *);

// 0x4d95f0 (A+D+E set).
static void THISCALL unnamed4d95f0(u8 *self, u32 x, float f) {
  if (*(u32 *)(self + 0x3c) & 0x200c00u)
    return;
  u16 w = *(u16 *)(self + 0x5c);
  u32 r = 0;
  if (w != 0) {
    u32 eng = G(u32, 0x70039c);
    u32 db = *(u32 *)(eng + 0x9b);
    u32 o1 = *(u32 *)(db + 8);
    r = ((q_fn)(*(u32 *)(*(u32 *)o1 + 0x5c)))((void *)o1, (u32)w);
  }
  if (w == 0 || r == 0) {
    u32 eng = G(u32, 0x70039c);
    u32 db = *(u32 *)(eng + 0x9b);
    u32 o1 = *(u32 *)(db + 8);
    u32 p = ((noret_fn)(*(u32 *)(*(u32 *)o1 + 0x50)))((void *)o1);
    u32 nw = 0;
    if (p != 0)
      nw = ((q_fn)(*(u32 *)(*(u32 *)o1 + 0x58)))((void *)o1, p);
    *(u16 *)(self + 0x5c) = (u16)nw;
  }
  u32 R = 0;
  u16 w2 = *(u16 *)(self + 0x5c);
  if (w2 != 0) {
    u32 eng = G(u32, 0x70039c);
    u32 db = *(u32 *)(eng + 0x9b);
    u32 o1 = *(u32 *)(db + 8);
    R = ((q_fn)(*(u32 *)(*(u32 *)o1 + 0x5c)))((void *)o1, (u32)w2);
  }
  u8 cnt = *(u8 *)(R + 0x1c);
  if (cnt >= 6)
    return;
  if (cnt < 3)
    *(u8 *)(R + cnt + 0x1d) = (u8)(int)(f * G(float, 0x697098));
  cnt = *(u8 *)(R + 0x1c);
  *(u32 *)(R + 4u * cnt) = x;
  *(u8 *)(R + 0x1c) = (u8)(cnt + 1);
  ((one_fn)(*(u32 *)(*(u32 *)x + 0x368)))((void *)x, (u32)self);
  ext_4d9d20((void *)self, x);
}
PCREG(4d95f0, unnamed4d95f0);
