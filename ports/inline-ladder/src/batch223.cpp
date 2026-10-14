// batch223.cpp - ZIKLNKOBJ members, part 2 (inline-ladder thread, 2026-10-11). GC names via the name map.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_462040(void *self, void *blk);   // ZLNKOBJ::CopyDataBlock
extern "C" u32 THISCALL ext_4e1b30(void *blk);               // DBLK::NextBlock
extern "C" u32 THISCALL ext_4620d0(void *self, void *geom);  // ZLNKOBJ::CopyGeometryFrom
extern "C" u32 THISCALL ext_466220(void *target);            // ZTARGET::Clear

// 0x466340 ZIKLNKOBJ::CopyDataBlock(DBLK*) [high], ret 4: the base class's, then DBLK::NextBlock (result returned).
static u32 THISCALL ikCopyDataBlock(u8 *self, void *blk) {
  ext_462040(self, blk);
  return ext_4e1b30(blk);
}
PCREG(466340, ikCopyDataBlock);

// 0x466630 ZIKLNKOBJ::FindBestAnim(const char*) const [medium], ret 4: tail call to own slot 0x21c with the same name.
static u32 THISCALL ikFindBestAnim(void *self, u32 name) { return vcall<u32>(self, 0x21c, name); }
PCREG(466630, ikFindBestAnim);

// 0x466360 ZIKLNKOBJ::CopyGeometryFrom(ZGEOM*) [high], ret 4: the base class's, then own slot 0x32c(1).
static void THISCALL ikCopyGeometryFrom(u8 *self, void *g) {
  ext_4620d0(self, g);
  vcall<void>(self, 0x32c, 1u);
}
PCREG(466360, ikCopyGeometryFrom);

// 0x466800 ZIKLNKOBJ::GetFocalPoint(float *out) [medium], ret 4: out = (0, +0x1ca, 0) (the eye height), then own
// slot 0x84(out) (local to world; tail call).
static u32 THISCALL ikGetFocalPoint(u8 *self, float *out) {
  float h = F32(self, 0x1ca);
  U32(out, 0) = 0;
  F32(out, 4) = h;
  U32(out, 8) = 0;
  return vcall<u32>(self, 0x84, out);
}
PCREG(466800, ikGetFocalPoint);

// 0x466d90 ZIKLNKOBJ::Load2() [medium]: the global object at [0x7003b8] gets +0x4ac = the engine list
// "TrackLinkObjects" (database +0xadc slot 0x25c("TrackLinkObjects", 0)). this is not used.
static void THISCALL ikLoad2(void *) {
  u32 l = vcall<u32>((void *)U32(U32(G(u32, 0x70039c), 0x9b), 0xadc), 0x25c, (const char *)0x685f44, 0u);
  U32(G(u32, 0x7003b8), 0x4ac) = l;
}
PCREG(466d90, ikLoad2);

// 0x467a40 ZIKLNKOBJ::SetHeadTarget(const float*) [medium], ret 4: target +0x1ba..+0x1c2 = the point; the blend
// +0x1c6 rises by 2 * (frame time [engine+0x48] * 4.0) and is clamped to 1.0 (NaN is stored, not clamped).
static void THISCALL ikSetHeadTarget(u8 *self, const u32 *p) {
  U32(self, 0x1ba) = p[0];
  U32(self, 0x1be) = p[1];
  U32(self, 0x1c2) = p[2];
  float x = F32(G(u32, 0x70039c), 0x48) * 4.0f;
  x = x + x;
  x = x + F32(self, 0x1c6);
  F32(self, 0x1c6) = x;
  if (x > 1.0f)
    U32(self, 0x1c6) = 0x3f800000;
}
PCREG(467a40, ikSetHeadTarget);

// 0x467710 ZIKLNKOBJ::Reset() [medium]: own slots 0x3dc and 0x414, ZTARGET::Clear on +0x16d, flags +0x136 = 0.
static void THISCALL ikReset(u8 *self) {
  vcall<void>(self, 0x3dc);
  vcall<void>(self, 0x414);
  ext_466220(self + 0x16d);
  U32(self, 0x136) = 0;
}
PCREG(467710, ikReset);
