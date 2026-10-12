// batch6590.cpp - unclaimed-68 batch 59 (claim 60): 0x584bc0, CExplodeMolotov::ReadInput(DBREAD&) (name from the ledger, high).
// thiscall, one stack argument (the stream), ret 4. Reads dword to +0x48, dword to +0x4c; peeks the byte at [[stream]] and, when it is
// not 0xff and (byte & 0x3f) == 3, reads one more dword (discarded); word to +0x54; then +0x56 = word of the render manager's slot
// +0x114(0x692b34, 0, 0x6ab6d4, 0x2bc) (four stack arguments).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *stream);   // DBREAD::operator unsigned int, ret 0
extern "C" u16 THISCALL ext_4e5e40(u8 *stream);   // DBREAD::operator unsigned short, ret 0

typedef u32(THISCALL *VSlot114)(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4);

static void THISCALL molotovReadInput(u8 *self, u8 *stream) {
  *(u32 *)(self + 0x48) = ext_4e5e60(stream);
  *(u32 *)(self + 0x4c) = ext_4e5e60(stream);
  u8 b = **(u8 **)stream;
  if (b != 0xff && (b & 0x3f) == 3) ext_4e5e60(stream);
  *(u16 *)(self + 0x54) = ext_4e5e40(stream);
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = ((VSlot114)*(u32 *)(*(u8 **)mgr + 0x114))(mgr, 0x692b34u, 0u, 0x6ab6d4u, 0x2bcu);
  *(u16 *)(self + 0x56) = (u16)r;
}
PCREG(584bc0, molotovReadInput);
