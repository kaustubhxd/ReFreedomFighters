// batch67510.cpp - cascade s6 batch 67510: 0x6526e0.
#include "ff.h"

typedef u32(STDCALL *i1_t)(u32);
typedef u32(STDCALL *i2_t)(u32, u32);
typedef u32(STDCALL *i3_t)(u32, u32, u32);
typedef u32(STDCALL *i4_t)(u32, u32, u32, u32);
typedef u32(STDCALL *i12_t)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
#define IAT(T, a) (*(T *)(a))

// 0x6526e0, thiscall(cls, name, style, exstyle, rect, parent, unused) ret 0x1c, returns bool: creates a window. The rect (4 ints) is first adjusted for the style (AdjustWindowRectEx 0x676218).
// With no class name (cls == 0) the default class 0x7f5a10 is looked up (GetClassInfo 0x67618c with this+0x12f) and, when missing, registered (RegisterClassEx 0x676188 with style
// 0x2b, window procedure 0x655a10, the application icon / arrow cursor / stock brush 4); a failed registration returns false. CreateWindowEx (0x676190) then builds the window from
// the adjusted rectangle with this+0x12f as instance (the global 0x725824 holds `this` meanwhile) and SetWindowLong (0x6761fc) stores `this` in the window at this+0x133.
static u8 THISCALL fn6526e0(u8 *self, u32 cls, u32 name, u32 style, u32 exstyle, s32 *rect, u32 parent, u32 unused) {
  s32 r[4] = {rect[0], rect[1], rect[2], rect[3]};
  IAT(i4_t, 0x676218)((u32)r, style, 0, exstyle);
  u32 edi = cls;
  if (!edi) {
    u32 wc[12];
    if (!IAT(i3_t, 0x67618c)(*(u32 *)(self + 0x12f), 0x7f5a10, (u32)wc)) {
      wc[0] = 0x30;
      wc[1] = 0x2b;
      wc[2] = 0x655a10;
      wc[3] = 0;
      wc[4] = 0;
      wc[5] = *(u32 *)(self + 0x12f);
      wc[6] = IAT(i2_t, 0x676248)(0, 0x7f00);
      wc[7] = IAT(i2_t, 0x6761cc)(0, 0x7f00);
      wc[8] = IAT(i1_t, 0x676034)(4);
      wc[9] = 0;
      wc[10] = 0x7f5a10;
      wc[11] = 0;
      if ((u16)IAT(i1_t, 0x676188)((u32)wc) == 0) return 0;
    }
    edi = 0x7f5a10;
  }
  *(u32 *)0x725824 = (u32)self;
  IAT(i12_t, 0x676190)(exstyle, edi, name, style, (u32)r[0], (u32)r[1], (u32)(r[2] - r[0]), (u32)(r[3] - r[1]), parent, 0, *(u32 *)(self + 0x12f), 0);
  IAT(i3_t, 0x6761fc)(*(u32 *)(self + 0x133), 0xffffffebu, (u32)self);
  *(u32 *)0x725824 = 0;
  return 1;
}
PCREG(6526e0, fn6526e0);
