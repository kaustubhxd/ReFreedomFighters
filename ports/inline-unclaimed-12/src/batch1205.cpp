// batch1205.cpp - unclaimed-12: batch 5 (docs/20-unclaimed-12.md, claim 5). Thiscall; the callee pops the stack args.
// Names are from the GC name map (high confidence for both).
#include "ff.h"

// 0x4e5e60, DBREAD::operator unsigned int(): thiscall, no arguments, returns the next dword (original code here).
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);

// 0x4b8330, CTelePortList::Init(ZLIST*, DBREAD&) (high): the list argument is not read. Two DBREAD reads, in order, go to
// dwords +0x4c and +0x50; dword +0x48 becomes 0.
static void THISCALL teleportListInit(u8 *self, void *list, u8 *dbread) {
  (void)list;
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x50) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x48) = 0;
}
PCREG(4b8330, teleportListInit);

// the virtual slot +0x114 takes four stack arguments; the caller pushes 0x378 first, so it is the last one
typedef u32(THISCALL *RenderInitFn)(u8 *self, u32 a, u32 b, u32 c, u32 d);

// 0x4c92d0, ZActivateBinoculars::Init(ZGEOM*, DBREAD&) (high): calls slot +0x114 of the object at [global 0x70039c]+0x9b with
// (0x6887ec, 0, 0x695494, 0x378) and stores the low word of its result at +0x48. Neither argument is read.
static void THISCALL activateBinocularsInit(u8 *self, void *, void *) {
  u8 *rm = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(rm + 0x9b);
  const u32 vtbl = *(const u32 *)obj;
  RenderInitFn fn = (RenderInitFn)(*(const u32 *)(vtbl + 0x114));
  *(u16 *)(self + 0x48) = (u16)fn(obj, 0x6887ec, 0, 0x695494, 0x378);
}
PCREG(4c92d0, activateBinocularsInit);
