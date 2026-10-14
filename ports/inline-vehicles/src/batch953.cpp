// batch953.cpp - residue-03 (core todo), batch 953: ZWeaponTest::Init(ZGROUP*, DBREAD&), 0x469130, thiscall, ret 8.
// Releases the sub-object at [sys+0x1907] (vslot 0xc with 0x6e5d3c, 0x68875c, 0) when present; reads the DBREAD (0x4e5e60,
// stood in) into [this+0x48]; asks the render manager (vslot 0x58) for a geometry whose list at +0x50 is walked:
// each node's object is added to this list at [this+0x4c + 4*n] when its vslot 0x1e0 (arg 0x1007d4) answers true
// (nodes with no object test 0x200002 against 0x100000). Then zeroes [this+0x1e0..+0x370) with the CRT memset (0x634d10,
// exe), sets [this+0x370] = 0 and calls CreateWeapons (0x46d5f0, stood in in the checker). The ZGROUP argument is not read.
#include "ff.h"

extern "C" void *THISCALL ext_4e5e60(void *dbread);                              // DBREAD read (stood in)
extern "C" void *__attribute__((cdecl)) ext_634d10(void *p, int c, u32 n);      // CRT memset (exe)
extern "C" void THISCALL ext_46d5f0(void *self);                                 // CreateWeapons (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x469130 ZWeaponTest::Init(ZGROUP*, DBREAD&).
static void THISCALL weaponInit(u8 *t, void *zgroup, void *dbread) {
  u8 *sys = *(u8 **)0x70039c;
  void *o = *(void **)(sys + 0x1907);
  if (o)
    vcall<void>(o, 0xc, 0x6e5d3cu, 0x68875cu, 0u);
  D(t, 0x48) = (u32)ext_4e5e60(dbread);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u8 *g = (u8 *)vcall<u32>(rm, 0x58, D(t, 0x48));
  D(t, 0x1dc) = 0;
  for (u8 *b = *(u8 **)(g + 0x50); b; b = *(u8 **)(b + 0x60)) {
    u8 *esi = *(u8 **)(b + 0x54);
    u32 a = esi ? *(u32 *)(*(u8 **)(esi + 0xc) + 0x23) : 0x200002u;
    // The exe leaves the loop when the flag test fails (je to the end at 0x4691cb), not just this node.
    if (!(a & 0x100000))
      break;
    u8 ok = (u8)vcall<u32>(esi, 0x1e0, 0x1007d4u);
    if (ok) {
      u32 i = D(t, 0x1dc);
      D(t, 0x4c + 4 * i) = (u32)esi;
      D(t, 0x1dc) = i + 1;
    }
  }
  D(t, 0x370) = 0;
  ext_634d10(t + 0x1e0, 0, 0x190);
  ext_46d5f0(t);
}
PCREG(469130, weaponInit);
