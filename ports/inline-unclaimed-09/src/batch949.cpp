// batch949.cpp - area 56 residue 15, claim A8: ZSHAPE::CopyData(const ZGEOM*) (0x44aa70). thiscall, one stack argument, ret 4.
// Calls are unverified (GUESS recording stubs in the spec). The original's tail jump is a plain call here.
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(u8 *self, u8 *src);

typedef u8 (THISCALL *Pred1e0)(u8 *self, u32 k);
typedef void (THISCALL *Tail)(u8 *self, u32 a);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x44aa70, ZSHAPE::CopyData(const ZGEOM*) (high): see docs/20-unclaimed-56.md claim A8.
static void THISCALL shapeCopyData(u8 *self, u8 *src) {
  ext_45d5b0(self, src);
  u8 flag = ((Pred1e0)slot(src, 0x1e0))(src, 0x4000022);
  if (!(flag & 0xff)) return;
  u32 p = *(u32 *)(src + 0x18);
  if (p == 0) return;
  *(u32 *)(self + 0x18) = p;
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 base = *(u32 *)(m + 0x1c5d);
  if (p >= base && base != 0) {
    u32 end = base + (*(u32 *)(base - 8) & 0x1fffffffu);
    if (p < end) return;
  }
  u8 *obj = G(u8 *, 0x70038c);
  ((Tail)slot(obj, 0xbc))(obj, p);
}
PCREG(44aa70, shapeCopyData);
