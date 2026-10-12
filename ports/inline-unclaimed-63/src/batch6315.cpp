// batch6315.cpp - unclaimed-63 batch 15 (docs/20-unclaimed-63.md): three small thunks (GUESS names, no GC names).
//   0x558ae0 (thiscall, one argument P, ret 4): f = 0x5003d0([P+4], 0); b = ([f] != 0); then a tail jump to this->[+0x1c]->vtbl[+0x6fc]
//     with b as its one argument (the PC overwrites the argument slot with b and jumps).
//   0x558b10 (the same, with the slot +0x700).
//   0x558b40 (thiscall, one unused argument, ret 4): calls [this+0x1c]->vtbl[+0x6e0]() (no arguments).
// The tail jumps are written as calls followed by return: the callee pops its one argument, so the caller's stack is the same.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);   // original, stubbed by the spec

typedef void(THISCALL * call1_fn)(void *, u32);
typedef void(THISCALL * call0_fn)(void *);

// 0x558ae0 (GUESS).
static void THISCALL thunk558ae0(u8 *self, u8 *p) {
  u32 f = ext_5003d0((void *)*(u32 *)(p + 4), 0);
  u32 b = (*(u32 *)f != 0) ? 1u : 0u;
  u32 o = *(u32 *)(self + 0x1c);
  ((call1_fn)(*(u32 *)(*(u32 *)o + 0x6fc)))((void *)o, b);
}
PCREG(558ae0, thunk558ae0);

// 0x558b10 (GUESS).
static void THISCALL thunk558b10(u8 *self, u8 *p) {
  u32 f = ext_5003d0((void *)*(u32 *)(p + 4), 0);
  u32 b = (*(u32 *)f != 0) ? 1u : 0u;
  u32 o = *(u32 *)(self + 0x1c);
  ((call1_fn)(*(u32 *)(*(u32 *)o + 0x700)))((void *)o, b);
}
PCREG(558b10, thunk558b10);

// 0x558b40 (GUESS).
static void THISCALL thunk558b40(u8 *self, u32 unused) {
  (void)unused;
  u32 o = *(u32 *)(self + 0x1c);
  ((call0_fn)(*(u32 *)(*(u32 *)o + 0x6e0)))((void *)o);
}
PCREG(558b40, thunk558b40);
