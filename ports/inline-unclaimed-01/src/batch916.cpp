#include "ff.h"
// batch916.cpp - unclaimed-01 claim 15 (docs/20-unclaimed-01.md). CExplodeMolotov::ReadInput(DBREAD&) (0x584bc0, high).
// The DBREAD operators 0x4e5e60 (dword) and 0x4e5e40 (word) are original code, stubbed by the spec (shared serial_stubs).

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);   // DBREAD::operator unsigned int
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);   // DBREAD::operator unsigned short (low word of eax)

// Reads two dwords into this+0x48 and this+0x4c, then a byte from the buffer the DBREAD points to; if that byte is not
// 0xff and its low six bits are 3, reads one more dword. Then a word into this+0x54, and a word from the global sub-object's
// slot +0x114 (four arguments) into this+0x56.
static void THISCALL explodeMolotovReadInput(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x48) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  u8 al = **(u8 **)dbread;
  if (al != 0xff && (al & 0x3f) == 3)
    ext_4e5e60(dbread);
  *(u16 *)(self + 0x54) = (u16)ext_4e5e40(dbread);
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u32(THISCALL * slot114_fn)(u8 *, u32, u32, u32, u32);
  slot114_fn f = *(slot114_fn *)(*(u32 *)sub + 0x114);
  *(u16 *)(self + 0x56) = (u16)f(sub, 0x692b34u, 0u, 0x6ab6d4u, 0x2bcu);
}
PCREG(584bc0, explodeMolotovReadInput);
