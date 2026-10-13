// batch914.cpp - unclaimed-09 batch 6: ZDamageBox::FrameUpdate (docs/20-unclaimed-09.md, claim 6).
// thiscall, no arguments, plain ret. Every virtual call goes through an object's vtable (unverified callees, stubbed in
// the spec with logged handlers). 0x4daf90 is the original code (ext), not stubbed.
#include "ff.h"

// Original code of 0x4daf90 (copies three dwords from self+0x30..0x38 into vec).
extern "C" void THISCALL ext_4daf90(u8 *self, float *vec);

typedef u8(THISCALL *ItemPred)(u8 *self);                                 // vt+0x438 (item.obj), returns al
typedef void(THISCALL *VecCall)(u8 *self, float *v);                      // vt+0x84 (item.obj), vt+0x8c (this+0x44)
typedef u8(THISCALL *VecFloatCall)(u8 *self, float *v, float k);          // vt+0x180 (this+0x44), returns al
typedef u16(THISCALL *SweepCall)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);  // vt+0x114 (global+0x9b): four arguments, ret 0x10
typedef void(THISCALL *ItemSweep)(u8 *self, u32 w, u8 *p, u32 z);          // vt+0x128 (item.obj): three arguments, ret 0xc
typedef void(THISCALL *ListBegin)(u8 *self, u32 *ok);                     // vt+0x4c (list), one argument
typedef u8 *(THISCALL *ListNext)(u8 *self, u32 *ok);                      // vt+0x5c (list)

// Slot at byte offset off of obj's vtable, as a raw address.
static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5db180, ZDamageBox::FrameUpdate() (high): advances this+0x4c by the global's +0x48; while this+0x4c has not passed
// this+0x50, walks the list at this+0x84. Each item whose byte at +8 is clear and whose obj.vt[0x438]() is false, and
// whose float at +9 (less this+0x4c) is negative, is fired: ext 0x4daf90 fills vec from obj+8, obj.vt[0x84](vec),
// this+0x44.vt[0x8c](vec), and if this+0x44.vt[0x180](vec, -10.0) then the global's +0x9b object's vt[0x114] returns a
// word that is passed to obj.vt[0x128]. The timer is cleared at the end.
static void THISCALL dmgBoxFrameUpdate(u8 *self) {
  u8 *g = G(u8 *, 0x70039c);
  float sum = *(float *)(g + 0x48) + *(float *)(self + 0x4c);
  *(float *)(self + 0x4c) = sum;
  if (*(float *)(self + 0x50) > sum) return;
  u8 *list = *(u8 **)(self + 0x84);
  if (!list) {
    *(float *)(self + 0x4c) = 0.0f;
    return;
  }
  u32 ok = 0;
  ((ListBegin)slot(list, 0x4c))(list, &ok);
  u8 *item = ((ListNext)slot(list, 0x5c))(list, &ok);
  while (ok) {
    u8 *obj = *(u8 **)(item + 4);
    bool skip = item[8] == 0 && ((ItemPred)slot(obj, 0x438))(obj);
    if (!skip) {
      float f9 = *(float *)(item + 9) - *(float *)(self + 0x4c);
      *(float *)(item + 9) = f9;
      skip = !(f9 < 0.0f);
    }
    if (!skip) {
      float vec[4];
      ext_4daf90(*(u8 **)(obj + 8), vec);
      ((VecCall)slot(obj, 0x84))(obj, vec);
      u8 *o44 = *(u8 **)(self + 0x44);
      ((VecCall)slot(o44, 0x8c))(o44, vec);
      if (((VecFloatCall)slot(o44, 0x180))(o44, vec, -10.0f)) {
        u8 *gobj = *(u8 **)(g + 0x9b);
        u16 w = ((SweepCall)slot(gobj, 0x114))(gobj, 0x69eaac, 0, 0x6b67d8, 0xa3);
        // The original leaves two pushes (self+0x54 and 0) on the stack; 0x128 pops them as its second and third arguments.
        ((ItemSweep)slot(obj, 0x128))(obj, (u32)w, self + 0x54, 0);
      }
    }
    item = ((ListNext)slot(list, 0x5c))(list, &ok);
  }
  *(float *)(self + 0x4c) = 0.0f;
}
PCREG(5db180, dmgBoxFrameUpdate);
