// batch67524.cpp - cascade s6 batch 67524: 0x46d2d0.
#include "ff.h"

extern "C" void THISCALL ext_4dc630(u8 *self, u32 setBits, u32 clearBits);          // ret 8
extern "C" void THISCALL ext_4db2c0(u8 *src, u32 *mat, u32 *vec);                    // ret 8
extern "C" void THISCALL ext_4da340(u8 *self, u32 a, u32 b, u32 c, u32 d);           // ret 0x10

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x46d2d0, stdcall(factory, src, key, show) ret 0x10, returns the new object or 0: asks `factory` for an object of type 'METI' with the key (slot 0x1c0); on failure returns 0.
// The new object's +8 member gets flag 0x800000 cleared (0x4dc630), slot 0x2c runs when `show` is set, the object registered under the name 0x688854 (slot 0x100) is told about it
// (its slot 0x54), the pose of src's +8 member (0x4db2c0 into a 0x24-byte matrix and 3-float vector) is applied (slot 0x74) and every child of the new object (list at +8, advanced with slot
// 0x50) that is not flagged 0x800000 is flagged, positioned twice (0x4da340 with 1 and 2) and its sub-object at +0x54 bracketed by slots 0x154 / 0x158.
static u32 STDCALL fn46d2d0(u8 *factory, u8 *src, u32 key, u8 show) {
  u32 mat[9], vec[3];
  u8 *esi = (u8 *)vcall<u32>(factory, 0x1c0, key, 0x4954454du, 0u, 0u, 1u);
  if (!esi) return 0;
  ext_4dc630(*(u8 **)(esi + 8), 0, 0x800000);
  if (show) vcall<void>(esi, 0x2c);
  u8 *x = (u8 *)vcall<u32>(esi, 0x100, 0x688854u);
  if (x) vcall<void>(x, 0x54, (u32)esi);
  ext_4db2c0(*(u8 **)(src + 8), mat, vec);
  vcall<void>(esi, 0x74, (u32)mat, (u32)vec);
  u8 *cur = *(u8 **)(esi + 8);
  while (cur) {
    if (!(D32(cur, 0x3c) & 0x800000)) {
      u8 *sub = *(u8 **)(cur + 0x54);
      if (sub) vcall<void>(sub, 0x154);
      ext_4dc630(cur, 0x800000, 0);
      ext_4da340(cur, 1, 0, 0, 0);
      ext_4da340(cur, 2, 0, 0, 0);
      sub = *(u8 **)(cur + 0x54);
      if (sub) vcall<void>(sub, 0x158);
    }
    vcall<void>(esi, 0x50, (u32)&cur);
  }
  return (u32)esi;
}
PCREG(46d2d0, fn46d2d0);
