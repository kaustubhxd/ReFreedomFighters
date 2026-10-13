// batch1207.cpp - unclaimed-12: batch 7 (docs/20-unclaimed-12.md, claim 7, in slice). Thiscall; the callee pops the stack arg.
// Names are from the GC name map (high confidence for both).
#include "ff.h"

// 0x45f3c0, the load helper called by ZSHAPE::Load (original code here; thiscall, one stack argument; the object is passed in ecx).
extern "C" u32 THISCALL ext_45f3c0(u8 *self, void *load);

// 0x44b2f0, ZSHAPE::Load(ZLoadGame*) (high): ecx is still this when the argument is pushed for the helper, so the helper gets
// this and the load argument. Returns true when the low byte of the helper's result is nonzero (test al, al: the upper bits of
// eax are ignored, as the harness found when the helper returned a full random dword).
static bool THISCALL shapeLoad(u8 *self, void *load) {
  return (u8)ext_45f3c0(self, load) != 0;
}
PCREG(44b2f0, shapeLoad);

// DBREAD operators: dword (0x4e5e60), float (0x4e5e80, result in st0), bool (0x4e5ef0, result in al). Original code here.
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);
extern "C" float THISCALL ext_4e5e80(u8 *dbread);
extern "C" u32 THISCALL ext_4e5ef0(u8 *dbread);

// 0x4b9570, ZProjectile::ReadInput(DBREAD&) (high): reads in this order: dword to +0x4c; float to +0x48; dword compared with 0
// to byte +0x50; dword to +0x91; a bool read sets (true) or clears (false) bit 0 of the dword at +0x89.
static void THISCALL projectileReadInput(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  *(float *)(self + 0x48) = ext_4e5e80(dbread);
  *(u8 *)(self + 0x50) = ext_4e5e60(dbread) != 0;
  *(u32 *)(self + 0x91) = ext_4e5e60(dbread);
  if ((u8)ext_4e5ef0(dbread))
    *(u32 *)(self + 0x89) |= 1u;
  else
    *(u32 *)(self + 0x89) &= 0xfffffffeu;
}
PCREG(4b9570, projectileReadInput);
