// batch878.cpp - area 50 (residue-09 file row): 0x5b23d0 CFFTargetList::Init(ZGEOM*, DBREAD&) [58 instr, thiscall, two stack args,
// ret 8]. A DBREAD word (0x4e5e60, recorded hook) picks a name (0x6b1908 when non-zero, else 0x6acfbc). The render manager's object
// (eng+0x9b, +0xadc) gives an object through vt +0x25c(name, 0); when that is null, vt +0x294(name, 0x67f610, 0, 1) gives it, then its
// vt +0x154, the 0x4dc630 call on its +8 (stood in), and vt +0x124(1, 0, 0, 0). In both cases the object's vt +0x218 gets the geometry
// argument, and this's vt +0x58 is called last.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4e5e60(void *db);                       // DBREAD::operator unsigned int() (stood in)
extern "C" void THISCALL ext_4dc630(void *obj, u32 a, u32 b);      // stood in (2 stack args)

// 0x5b23d0 (name from the residue file).
static void THISCALL InitTargets5b23d0(u8 *self, void *geom, void *db) {
  u32 flag = ext_4e5e60(db);
  u32 name = flag != 0 ? 0x6b1908u : 0x6acfbcu;
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u8 *o = (u8 *)FP(mgr, 0xadc);
  u8 *esi = vcall<u8 *>(o, 0x25c, name, 0u);
  if (esi == 0) {
    esi = vcall<u8 *>(o, 0x294, name, 0x67f610u, 0u, 1u);
    vcall<void>(esi, 0x154);
    ext_4dc630(FP(esi, 8), 0x800000u, 0u);
    vcall<void>(esi, 0x124, 1u, 0u, 0u, 0u);
  }
  vcall<void>(esi, 0x218, geom);
  vcall<void>(self, 0x58);
}
PCREG(5b23d0, InitTargets5b23d0);
