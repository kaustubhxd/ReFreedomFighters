// batch834.cpp - animation layer thread, batch 834: ZIKLNKOBJ facing, focal point and geometry copy.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4620d0(void *self, void *geom);   // ZLNKOBJ::CopyGeometryFrom (not ported here)

// ZIKLNKOBJ::DisableFacing() [medium]: calls vt +0x3c8 with the argument 0 and a 16-byte block {0, 0, 0, -1} (the
// exe's stack scratch, passed as four more words); then sets the facing byte +0x158 to 1.
static void THISCALL DisableFacing(u8 *self) {
  u32 blk[4] = {0, 0, 0, 0xffffffffu};
  vcall<void>(self, 0x3c8, 0u, blk[0], blk[1], blk[2], blk[3]);
  F8(self, 0x158) = 1;
}
PCREG(466420, DisableFacing);

// ZIKLNKOBJ::GetFocalPoint(float* out) const [high]: out = (0, this+0x1ca, 0), then the object's vt +0x84(out) (tail call).
static void THISCALL GetFocalPoint(u8 *self, float *out) {
  out[0] = 0.0f;
  out[1] = FF(self, 0x1ca);
  out[2] = 0.0f;
  vcall<void>(self, 0x84, out);
}
PCREG(466800, GetFocalPoint);

// ZIKLNKOBJ::CopyGeometryFrom(ZGEOM* g) [medium]: the base copy (0x4620d0), then vt +0x32c(1).
static void THISCALL CopyGeometryFrom(u8 *self, void *g) {
  ext_4620d0(self, g);
  vcall<void>(self, 0x32c, 1u);
}
PCREG(466360, CopyGeometryFrom);
