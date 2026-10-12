// batch1033.cpp - unclaimed-04 batch 33 (docs/20-unclaimed-04.md): three slice-3 functions (GUESS labels).
#include "ff.h"

typedef s32(THISCALL *vi0_t)(void *self);
typedef float(THISCALL *vf0_t)(void *self);
typedef u32(THISCALL *thiscall2_t)(void *self, u32 a, u32 b);
typedef u32(__attribute__((cdecl)) *cdecl3_t)(u32 a, u32 b, u32 c);

static inline u32 vslot(void *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}

// 0x42d270: a flag at N[-2] gates N[-1] = (N[-1] == 0); *q advances by 0xc unless it equals R+4 (R = this+0x1b6d).
static void THISCALL unk42d270FlagGate(u8 *self, u32 *q) {
  u8 *p = *(u8 **)(self + 0x1b61);
  u32 *n = (u32 *)*(u32 *)(p + 4);
  if (n[-2] != 0) n[-1] = (n[-1] == 0) ? 1 : 0;
  u32 cur = *q;
  u8 *r = *(u8 **)(self + 0x1b6d);
  if (cur != *(u32 *)(r + 4)) *q = cur + 0xc;
}
PCREG(42d270, unk42d270FlagGate);

// 0x64fcb0: (int)(x / y) with x = (float) vt[0xdc]() and y = vt[0xf8]() (float in st0). The x87 divides at 53-bit precision
// and stores single, so the quotient is (float)((double)x / (double)y).
static s32 THISCALL unk64fcb0Ratio(u8 *self) {
  s32 i = ((vi0_t)vslot(self, 0xdc))(self);
  float x = (float)i;
  float y = ((vf0_t)vslot(self, 0xf8))(self);
  float q = (float)((double)x / (double)y);
  return _mm_cvtt_ss2si(_mm_set_ss(q));
}
PCREG(64fcb0, unk64fcb0Ratio);

// 0x5f94f0: logger. obj = global 0x700390; L = obj->vt[0x20](0x6b8a64, 0x29e); L->vt[0x2c](L, 0x69c6b0, 0x69c7f0) (cdecl);
// then the global 0x7003b0, when non-zero, is called (cdecl, no arguments). Returns 0. One stack argument, unused.
static u32 __attribute__((stdcall)) unk5f94f0Logger(u32 unused) {
  (void)unused;
  u8 *obj = *(u8 **)0x700390;
  u32 l = ((thiscall2_t)vslot(obj, 0x20))(obj, 0x6b8a64, 0x29e);
  ((cdecl3_t)vslot((void *)l, 0x2c))(l, 0x69c6b0, 0x69c7f0);
  void (*cb)(void) = (void (*)(void)) * (u32 *)0x7003b0;
  if (cb) cb();
  return 0;
}
PCREG(5f94f0, unk5f94f0Logger);
