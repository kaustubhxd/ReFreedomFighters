// batch228.cpp - small leaves, slices 0/1. 0x529f40 (name GUESS): calls vtable slots on its argument a (0x68 with this+4,
// 0x64 with this[0x18], 0x68 with this+0x1c, 0x4c with the floats this[0x28] and this[0x2c]), then the original 0x529fa0
// (stubbed) on this+0x30 with a; returns al = 1.
#include "ff.h"

extern "C" void THISCALL ext_529fa0(u8 *self, u8 *a);   // original, thiscall (ecx = this+0x30), one stack word (stubbed)

typedef void(THISCALL *SlotWord)(u8 *, u32);        // vtable slot, one stack word, no result used
typedef void(THISCALL *SlotFloat)(u8 *, float);     // vtable slot, one float stack word

static u32 vslot11(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x529f40, thiscall(a) (ret 4): a->vt[0x68](a, this+4); a->vt[0x64](a, [this+0x18]); a->vt[0x68](a, this+0x1c);
// a->vt[0x4c](a, float [this+0x28]); a->vt[0x4c](a, float [this+0x2c]); 0x529fa0(this+0x30, a); return 1 (al).
static u8 THISCALL pushPair_529f40(u8 *self, u8 *a) {
  ((SlotWord)vslot11(a, 0x68))(a, (u32)(self + 4));
  ((SlotWord)vslot11(a, 0x64))(a, *(u32 *)(self + 0x18));
  ((SlotWord)vslot11(a, 0x68))(a, (u32)(self + 0x1c));
  ((SlotFloat)vslot11(a, 0x4c))(a, *(float *)(self + 0x28));
  ((SlotFloat)vslot11(a, 0x4c))(a, *(float *)(self + 0x2c));
  ext_529fa0(self + 0x30, a);
  return 1;
}
PCREG(529f40, pushPair_529f40);
