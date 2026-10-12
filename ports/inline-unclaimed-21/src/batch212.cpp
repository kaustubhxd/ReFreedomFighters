// batch212.cpp - unclaimed area 21 (docs/20-unclaimed-21.md), slice floor(addr/16) mod 20 == 0. Two functions that call
// through the render-manager object (global 0x70039c, offset 0x9b, then offset 8) and through their own vtables. Names GUESS.
#include "ff.h"

extern "C" void THISCALL ext_4dce70(u8 *self, u32 arg);   // original, thiscall, one stack word (stubbed in the harness)

typedef u32(THISCALL *SlotNone)(u8 *);             // vtable slot with no argument, eax result
typedef u32(THISCALL *SlotOne)(u8 *, u32);         // vtable slot with one stack word, eax result
typedef void(THISCALL *SlotArgVoid)(u8 *, u32);    // vtable slot with one stack word, no result used

static u32 vslot(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// The child object used by both functions: [[ [0x70039c] + 0x9b ] + 8].
static u8 *rmChild() {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *a = *(u8 **)(rm + 0x9b);
  return *(u8 **)(a + 8);
}

// 0x4dc9c0, thiscall(arg) (ret 4). f = [this+0x3c]. If (f & 0x40000) and (f & 0x4000) and not (f & 0x200c00):
// w = u16 [this+0x5c]; r = 0; if w: r = child->vt[0x5c](child, w). If r == 0: x = child2->vt[0x50](child2); ext_4dce70(this, x).
// Then w2 = u16 [this+0x5c]: if w2: base = child->vt[0x5c](child, w2); [base+0x18] = arg; else [0x18] = arg (the exe
// stores through a null base). Returns arg. If the first test fails, returns f. Name GUESS.
static u32 THISCALL pairStore_4dc9c0(u8 *self, u32 arg) {
  u32 f = *(u32 *)(self + 0x3c);
  if (!(f & 0x40000) || !(f & 0x4000) || (f & 0x200c00)) return f;
  u16 w = *(u16 *)(self + 0x5c);
  u32 r = 0;
  if (w) {
    u8 *obj = rmChild();
    r = ((SlotOne)vslot(obj, 0x5c))(obj, w);
  }
  if (!r) {
    u8 *obj = rmChild();
    u32 x = ((SlotNone)vslot(obj, 0x50))(obj);
    ext_4dce70(self, x);
  }
  u16 w2 = *(u16 *)(self + 0x5c);
  if (w2) {
    u8 *obj = rmChild();
    u8 *base = (u8 *)((SlotOne)vslot(obj, 0x5c))(obj, w2);
    *(u32 *)(base + 0x18) = arg;
  } else {
    G(u32, 0x18) = arg;
  }
  return arg;
}
PCREG(4dc9c0, pairStore_4dc9c0);

// 0x5922c0, thiscall(arg) (ret 4). o = this->vt[0x504](this); if o and o->vt[0x1e0](o, 0x1007d2) (low byte):
// o->vt[0x34c](o, arg) and return. Else: x = this->vt[0x3a0](this, &local, arg) (ret 8); this->vt[0x390](this, x);
// this->vt[0x84](this, arg). Name GUESS.
typedef u32(THISCALL *SlotOutArg)(u8 *, u32 *, u32);  // vtable slot with an out pointer and one more word (ret 8)

static void THISCALL callIfOk_5922c0(u8 *self, u32 arg) {
  u8 *o = (u8 *)(u32)((SlotNone)vslot(self, 0x504))(self);
  if (o) {
    u8 ok = (u8)((SlotOne)vslot(o, 0x1e0))(o, 0x1007d2u);
    if (ok) {
      ((SlotArgVoid)vslot(o, 0x34c))(o, arg);
      return;
    }
  }
  u32 local = 0;
  u32 x = ((SlotOutArg)vslot(self, 0x3a0))(self, &local, arg);
  ((SlotArgVoid)vslot(self, 0x390))(self, x);
  ((SlotArgVoid)vslot(self, 0x84))(self, arg);
}
PCREG(5922c0, callIfOk_5922c0);
