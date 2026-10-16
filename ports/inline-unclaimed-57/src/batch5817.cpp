// batch5817.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 117: 0x5d76f0 (GUESS name unnamed_5d76f0), thiscall, no stack args, plain ret.
// If this+0x1cc == 0: if engine+0x40 > this+0x1c8: 0x5d7e00(this) (batch 107; hooked). Return.
// Else: al = (q->vt[+0x38](0x6b5c9c, 0) != 0) || (q2->vt[+0x38](0x6b5cb4, 0) != 0) (q = engine+0x1907; the second call only if the first is 0).
// If this+0x1c3 != 0: x = this+0x156; if x == 2: if this+0x1e6 != 0 and engine+0x40 > this+0x1c8: 0x5d7bc0(this) (hooked), this+0x1e6 = 0; return.
//   if x == 1 and al: R = (this+0x14e)->vt[+0x30](1); R2 = obj->vt[+0x4c](obj) (obj = this+0x44, sub = (engine)+0x9b for the slot: sub->vt[+0x4c](obj));
//   obj->vt[+0x12c](R, word(this+0x142), R2)... (see code); return. Otherwise return unless x == 2 (above).
// If this+0x1c3 == 0: if al: this+0x156 = (this+0x14e)->vt[+0x14](); obj->vt[+0x128](word(this+0x142), 0, 0). If this+0x1cc == 0 return. If this+0x13c
// >= this+0x48: return. t = (engine+0x40 - this+0x1c4) (float) * G(0x6785e4) * G(0x685270); if trunc(t) <= entry A (this+0x4c + 12 i): return.
// Else: loc = (this+0x1d1 dword p1, p2) = entries; if this+0x1d1 != 0: obj->vt[+0x130](this+0x1d1, word(this+0x14a), &loc). this+0x13c += 1.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *Slot2r)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *Slot3)(u8 *self, u32 a, u32 b, u32 c);
typedef void(THISCALL *SlotV)(u8 *self);

extern "C" void THISCALL ext_5d7e00(u8 *self);  // batch 107, original code (hooked in the spec)
extern "C" void THISCALL ext_5d7bc0(u8 *self);  // area 49's function, original code (hooked in the spec)

// 0x5d76f0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d76f0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (*(u8 *)(self + 0x1cc) == 0) {
    if ((s32)*(u32 *)(eng + 0x40) > (s32)*(u32 *)(self + 0x1c8)) ext_5d7e00(self);
    return;
  }
  u8 *q = *(u8 **)(eng + 0x1907);
  u32 al = ((Slot2r)VT(q)[0x38 / 4])(q, 0x6b5c9c, 0) != 0;
  if (!al) {
    eng = G(u8 *, 0x70039c);
    q = *(u8 **)(eng + 0x1907);
    al = ((Slot2r)VT(q)[0x38 / 4])(q, 0x6b5cb4, 0) != 0;
  }
  if (*(u8 *)(self + 0x1c3) != 0) {
    u32 x = *(u32 *)(self + 0x156);
    if (x >= 2) {
      if (x == 2 && *(u8 *)(self + 0x1e6) != 0) {
        eng = G(u8 *, 0x70039c);
        if ((s32)*(u32 *)(eng + 0x40) > (s32)*(u32 *)(self + 0x1c8)) {
          ext_5d7bc0(self);
          *(u8 *)(self + 0x1e6) = 0;
        }
        return;
      }
      if (al) {
        u8 *r14 = *(u8 **)(self + 0x14e);
        *(u32 *)(self + 0x156) = ((SlotN)VT(r14)[0x14 / 4])(r14);
        u8 *obj = *(u8 **)(self + 0x44);
        ((Slot3)VT(obj)[0x128 / 4])(obj, (u32)*(u16 *)(self + 0x142), 0, 0);
      }
      return;
    }
    if (x == 1 && al) {
      u8 *r14 = *(u8 **)(self + 0x14e);
      u32 R = ((SlotA)VT(r14)[0x30 / 4])(r14, 1);
      u8 *obj = *(u8 **)(self + 0x44);
      eng = G(u8 *, 0x70039c);
      u8 *sub = *(u8 **)(eng + 0x9b);
      void **objVt = VT(obj);
      u32 R2 = ((SlotA)VT(sub)[0x4c / 4])(sub, (u32)(unsigned long)obj);
      ((Slot3)objVt[0x12c / 4])(obj, R, (u32)*(u16 *)(self + 0x142), R2);
    }
    return;
  }
  // flag at +0x1c3 clear
  if (al) {
    u8 *r14 = *(u8 **)(self + 0x14e);
    *(u32 *)(self + 0x156) = ((SlotN)VT(r14)[0x14 / 4])(r14);
    u8 *obj = *(u8 **)(self + 0x44);
    ((Slot3)VT(obj)[0x128 / 4])(obj, (u32)*(u16 *)(self + 0x142), 0, 0);
  }
  if (*(u8 *)(self + 0x1cc) == 0) return;
  u32 idx = *(u32 *)(self + 0x13c);
  if ((s32)idx >= (s32)*(u32 *)(self + 0x48)) return;
  eng = G(u8 *, 0x70039c);
  s32 t = (s32)(*(u32 *)(eng + 0x40) - *(u32 *)(self + 0x1c4));
  float tf = (float)t * G(float, 0x6785e4);
  tf = tf * G(float, 0x685270);
  s32 tr = _mm_cvttss_si32(_mm_set_ss(tf));
  u32 *ent = (u32 *)(self + 0x4c + 12 * idx);
  if (tr <= (s32)ent[0]) return;
  u32 loc[2];
  loc[0] = ent[1];  // +0x50 entry
  loc[1] = ent[2];  // +0x54 entry
  u32 d1 = *(u32 *)(self + 0x1d1);
  if (d1 != 0) {
    u8 *obj = *(u8 **)(self + 0x44);
    ((Slot3)VT(obj)[0x130 / 4])(obj, d1, (u32)*(u16 *)(self + 0x14a), (u32)(unsigned long)loc);
  }
  *(u32 *)(self + 0x13c) += 1;
}
PCREG(5d76f0, unnamed5d76f0);
