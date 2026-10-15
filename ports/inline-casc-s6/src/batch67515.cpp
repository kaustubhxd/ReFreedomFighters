// batch67515.cpp - cascade s6 batch 67515: 0x535150.
#include "ff.h"

extern "C" u32 THISCALL ext_533e00(u8 *self);                      // allocates / looks up a free slot id (plain ret)
extern "C" void THISCALL ext_44b610(u8 *obj);                      // plain ret
extern "C" void __attribute__((cdecl)) ext_44b740(u8 *obj);        // cdecl, one argument

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x535150, thiscall(ref, scale, posA, posB) ret 0x10, returns the slot id or 0: creates and initialises a record. A free slot id comes from 0x533e00 (this+0x8b); its table record
// (slot 0x60) is reset to defaults (state 3, flags 6 | 0x80, scale values 1.0 and 360.0, zeroed counters, +0x6c from the engine word +0x1c), takes `scale` at +0x80 / +0x7c,
// the table handle of `ref` at +0x3c and the two 3-float vectors at +0x14 and +0x20. This object's slot 0x4c then registers it; on refusal the record is torn down
// (0x44b610, 0x44b740) and 0 returned.
static u32 THISCALL fn535150(u8 *self, u32 ref, u32 scale, u32 *vecB, u32 *vecA) {
  u32 id = ext_533e00(self + 0x8b);
  if (!id) return 0;
  u8 *r = (u8 *)vcall<u32>(tabObj(), 0x60, id);
  D32(r, 0x40) &= 0xfffffff7u;
  D32(r, 8) = 0xffffffffu;
  D32(r, 0xd0) = 0;
  D32(r, 0x6c) = 0;
  D32(r, 0x80) = scale;
  D32(r, 0x70) = 0;
  D32(r, 8) = 1;
  D32(r, 0x84) = 0x3f800000u;
  D32(r, 0x88) = 0x3f800000u;
  D32(r, 0x44) = 0x43b40000u;
  D32(r, 0x48) = 0x43b40000u;
  D32(r, 0x4c) = 0;
  D32(r, 0x50) = 0;
  D32(r, 0x2c) = 0;
  D32(r, 0x78) = 0;
  D32(r, 0x8c) = 0;
  D32(r, 0x64) = 0;
  D32(r, 0x68) = 0;
  D32(r, 0x60) = 0;
  D32(r, 0x40) = 6;
  D32(r, 0x6c) = D32(*(u8 **)0x70039c, 0x1c);
  D32(r, 4) = 3;
  D32(r, 0x7c) = scale;
  u32 h = vcall<u32>(tabObj(), 0x4c, ref);
  D32(r, 0x40) |= 0x80;
  D32(r, 0x3c) = h;
  D32(r, 8) = 1;
  D32(r, 0x2c) = 0;
  D32(r, 0x58) = 0x3f800000u;
  r[0xec] = 0;
  *(u32 *)(r + 0xed) = 0;
  *(u32 *)(r + 0xf1) = 0;
  *(u32 *)(r + 0xf5) = 0;
  D32(r, 0x14) = vecA[0];
  D32(r, 0x18) = vecA[1];
  D32(r, 0x1c) = vecA[2];
  D32(r, 0x20) = vecB[0];
  D32(r, 0x24) = vecB[1];
  D32(r, 0x28) = vecB[2];
  if (!(u8)vcall<u32>(self, 0x4c, (u32)r)) {
    ext_44b610(r);
    ext_44b740(r);
    return 0;
  }
  return id;
}
PCREG(535150, fn535150);
