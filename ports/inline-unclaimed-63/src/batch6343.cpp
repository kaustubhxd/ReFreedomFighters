// batch6343.cpp - unclaimed-63 gap-band batch 43: 0x4d2fe0 (C-set; no GC name), thiscall, one stack argument P, ret 4.
//   this->vtbl[+0xc]() (thiscall, no arguments). L = P->vtbl[+0x18](&L, 4) (out value; the caller sees the callee's write).
//   While L != -1: size = (L + 7) & ~3; Y = 0x4cd9b0(this+0x40b4, size, 1) (pool allocator, original code, stubbed by the spec);
//     B = this[+0x4004]; B[Y] = size; p = B + Y + 4; P->vtbl[+0x18](p, L) (thiscall); Q = (out) P->vtbl[+0x40](&P) (thiscall, one
//     argument, the address of the argument slot; the callee may write it); p[+4] = 0x6e7a30 + Q * 20; this+0x4008 object's
//     vtbl[+4](p) (thiscall, one argument); L = P->vtbl[+0x18](&L, 4).
//   The callees (vtbl slots) pop their own arguments; the pool allocator pops 8 (as in 0x4d25f0).
#include "ff.h"

extern "C" u32 THISCALL ext_4cd9b0(void *pool, u32 size, u32 one);   // pool allocator, original code, stubbed by the spec

typedef void(THISCALL * noarg_fn)(void *);
typedef void(THISCALL * read_fn)(void *, u32, u32);
typedef void(THISCALL * one_fn)(void *, u32);

// 0x4d2fe0 (C-set).
static void THISCALL unnamed4d2fe0(u8 *self, u32 p0) {
  ((noarg_fn)(*(u32 *)(*(u32 *)self + 0xc)))((void *)self);
  u32 obj = p0;   // the object for every P call (the original keeps esi)
  u32 arg = p0;   // the argument slot: the callee writes its out value through &arg
  u32 L = 0;
  ((read_fn)(*(u32 *)(*(u32 *)obj + 0x18)))((void *)obj, (u32)&L, 4u);
  while (L != 0xffffffffu) {
    u32 size = (L + 7u) & 0xfffffffcu;
    u32 y = ext_4cd9b0((void *)(self + 0x40b4), size, 1u);
    u8 *b = *(u8 **)(self + 0x4004);
    *(u32 *)(b + y) = size;
    u8 *p = b + y + 4;
    ((read_fn)(*(u32 *)(*(u32 *)obj + 0x18)))((void *)obj, (u32)p, L);
    ((one_fn)(*(u32 *)(*(u32 *)obj + 0x40)))((void *)obj, (u32)&arg);
    *(u32 *)(p + 4) = 0x6e7a30u + arg * 20u;
    u8 *o = self + 0x4008;
    ((one_fn)(*(u32 *)(*(u32 *)o + 4)))((void *)o, (u32)p);
    ((read_fn)(*(u32 *)(*(u32 *)obj + 0x18)))((void *)obj, (u32)&L, 4u);
  }
}
PCREG(4d2fe0, unnamed4d2fe0);
