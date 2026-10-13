#include "ff.h"
// batch2730.cpp - unclaimed-27 batch 32 (docs/20-unclaimed-27.md). FUN_588940, name unknown (GUESS). Fastcall: ecx = this, edx = out.
typedef void(THISCALL * slot48_fn)(u8 *, s32 *);
typedef void(THISCALL * slot40_fn)(u8 *, u32 *);
typedef u32(THISCALL * slot58_fn)(u8 *, u32);
typedef u32(THISCALL * slot1e0_fn)(u8 *, u32);

static u8 *FASTCALL funcCollectValues(u8 *self, u32 *out) {
  s32 cnt = 0;
  ((slot48_fn)(*(u32 *)(*(u32 *)self + 0x48)))(self, &cnt);
  if (cnt > 0) {
    for (s32 i = 0; i < cnt; i++) {
      u32 item = 0;
      ((slot40_fn)(*(u32 *)(*(u32 *)self + 0x40)))(self, &item);
      u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
      u8 *eng = *(u8 **)(g + 0x9b);
      u8 *obj = (u8 *)(unsigned long)((slot58_fn)(*(u32 *)(*(u32 *)eng + 0x58)))(eng, item);
      u32 val = 0;
      if (obj != 0) {
        u8 al = (u8)((slot1e0_fn)(*(u32 *)(*(u32 *)obj + 0x1e0)))(obj, 0x200006u);
        if (al) val = *(u32 *)(obj + 0x54);
      }
      out[1 + out[0]] = val;
      out[0]++;
    }
  }
  return self;
}
PCREG(588940, funcCollectValues);
