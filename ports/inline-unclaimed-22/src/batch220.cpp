// batch220.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. Small bodies: a pure
// three-dword mask, a pointer pair copy, and thin wrappers that call one vtable slot (some tail-jump in the original;
// the port returns the callee's eax, which is the same value).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);   // original, thiscall, ONE stack word (ret 4), returns a pointer

typedef u32(THISCALL *SlotU32Arg0)(u8 *, u32);
typedef u32(THISCALL *SlotNoArg)(u8 *);

// 0x4d2ed0, thiscall(a): return this->vtable[0x9c](this, a, 2). Name GUESS (two-argument virtual call).
static u32 THISCALL vtCall9c_4d2ed0(u8 *self, u32 a) {
  return vcall<u32>(self, 0x9c, a, 2u);
}
PCREG(4d2ed0, vtCall9c_4d2ed0);

// 0x4856d0, thiscall(): clear the sign bit of the three dwords at this. Name GUESS (abs of a 3-vector).
static void THISCALL clearSigns3_4856d0(u8 *self) {
  *(u32 *)(self + 0) &= 0x7fffffffu;
  *(u32 *)(self + 4) &= 0x7fffffffu;
  *(u32 *)(self + 8) &= 0x7fffffffu;
}
PCREG(4856d0, clearSigns3_4856d0);

// 0x4cf190, thiscall(out): out[2] = -1; out[0] = this->[+8]; if this->[+8] is not null, out[1] = that->[+8];
// then this->[+0xc] &= 0x7fffffff. Name GUESS (range from a linked node).
static void THISCALL fillFromNode_4cf190(u8 *self, u32 *out) {
  out[2] = 0xffffffffu;
  out[0] = *(u32 *)(self + 8);
  u8 *node = *(u8 **)(self + 8);
  if (node) out[1] = *(u32 *)(node + 8);
  *(u32 *)(self + 0xc) &= 0x7fffffffu;
}
PCREG(4cf190, fillFromNode_4cf190);

// 0x45f890, thiscall(a1, a2): p = this->[+0x10]; if p and p->[+8], a1->vtable[0x68](a1, a1->[+0x14], a2). Name GUESS.
static void THISCALL callSlot68Gated_45f890(u8 *self, u8 *a1, u32 a2) {
  u8 *p = *(u8 **)(self + 0x10);
  if (p && *(u32 *)(p + 8)) {
    vcall<void>(a1, 0x68, *(u32 *)(a1 + 0x14), a2);
  }
}
PCREG(45f890, callSlot68Gated_45f890);

// 0x45f9d0, thiscall(a1, a2): p = this->[+0x10]; q = p ? p->[+0x1c] : 0; if q, global->vtable[0x60](global, q->[+4]->[+4], a1, a2)
// where global is the object at 0x7003a4. Name GUESS.
static void THISCALL callSlot60Gated_45f9d0(u8 *self, u8 *a1, u32 a2) {
  u8 *p = *(u8 **)(self + 0x10);
  if (p && *(u8 **)(p + 0x1c)) {
    u8 *q = *(u8 **)(p + 0x1c);
    u8 *r = *(u8 **)(q + 4);
    u8 *global = *(u8 **)0x7003a4u;
    vcall<void>(global, 0x60, *(u32 *)(r + 4), a1, a2);
  }
}
PCREG(45f9d0, callSlot60Gated_45f9d0);

// 0x55bb90, thiscall(a): r = ext_5003d0(a->[+4], 0); value = (u8)*r; return this->[+0x1c]->vtable[0x6f0](value).
// The original tail-jumps with value written over the stack argument, so the callee's eax is this function's eax.
// Name GUESS.
static u32 THISCALL slot6f0Byte_55bb90(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *obj = *(u8 **)(self + 0x1c);
  u32 value = *r;
  SlotU32Arg0 fn = (SlotU32Arg0)(*(u32 *)(*(u32 *)obj + 0x6f0));
  return fn(obj, value);
}
PCREG(55bb90, slot6f0Byte_55bb90);

// 0x5080d0, thiscall(a): r = ext_5003d0(a->[+4], 0); value = (*r != 0); return this->[+0x18]->vtable[0x67c](value).
// Tail jump in the original; the callee's eax is returned. Name GUESS.
static u32 THISCALL slot67cFlag_5080d0(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *obj = *(u8 **)(self + 0x18);
  u32 value = *(u32 *)r != 0;
  SlotU32Arg0 fn = (SlotU32Arg0)(*(u32 *)(*(u32 *)obj + 0x67c));
  return fn(obj, value);
}
PCREG(5080d0, slot67cFlag_5080d0);

// 0x558350, thiscall(a): r = ext_5003d0(a->[+4], 0); v = rm->[+0x9b]->vtable[0x58](*r) where rm is the global at
// 0x70039c; return this->[+0x1c]->vtable[0x2d8](v) (tail jump in the original). Name GUESS.
static u32 THISCALL slot2d8Chain_558350(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  u32 v = vcall<u32>(obj, 0x58, *(u32 *)r);
  u8 *o2 = *(u8 **)(self + 0x1c);
  return vcall<u32>(o2, 0x2d8, v);
}
PCREG(558350, slot2d8Chain_558350);
