// batch1904.cpp - unclaimed-66 batch 4 (residue 5): CHitpointControl::CopyEventDataBlock(DBREAD&) (vtable). Thiscall, one
// argument, ret 4. The DBREAD readers are called in this order (as the PC code does): 0x4e5e80 (float) -> +0x48, 0x4e5e80
// -> +0x4c, 0x4e5e60 (dword) -> +0x50, 0x4e5e40 (word) -> +0x54, 0x4e5ef0 (byte) -> +0x56. Then the DBREAD's tag byte
// (the byte at *(*db)) gates three reads: 0x4e5ef0 -> +0x63 when tag != 0xff and (tag & 0x3f) != 0xff; 0x4e5e80 -> +0x57
// when tag != 0xff and (tag & 0x3f) == 2; 0x4e5e60 -> +0x5b when tag != 0xff and (tag & 0x3f) == 8 (else +0x5b = 0); and
// 0x4e5e80 -> +0x5f when tag != 0xff and (tag & 0x3f) == 2. The readers are STUBS in the spec (docs/20-unclaimed-66.md).
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *);
extern "C" u32 THISCALL ext_4e5e60(void *);
extern "C" u32 THISCALL ext_4e5e40(void *);
extern "C" u32 THISCALL ext_4e5ef0(void *);

static inline u8 tagOf(void *dbread) { return *(u8 *)(*(u8 **)dbread); }

// 0x5827d0, CHitpointControl::CopyEventDataBlock(DBREAD&) (vtable).
static void THISCALL hitpointCopyEventDataBlock(u8 *self, void *dbread) {
  *(float *)(self + 0x48) = ext_4e5e80(dbread);
  *(float *)(self + 0x4c) = ext_4e5e80(dbread);
  *(u32 *)(self + 0x50) = ext_4e5e60(dbread);
  *(u16 *)(self + 0x54) = (u16)ext_4e5e40(dbread);
  *(u8 *)(self + 0x56) = (u8)ext_4e5ef0(dbread);
  if (tagOf(dbread) != 0xff && (tagOf(dbread) & 0x3f) != 0xff) *(u8 *)(self + 0x63) = (u8)ext_4e5ef0(dbread);
  if (tagOf(dbread) != 0xff && (tagOf(dbread) & 0x3f) == 2) *(float *)(self + 0x57) = ext_4e5e80(dbread);
  if (tagOf(dbread) != 0xff && (tagOf(dbread) & 0x3f) == 8) *(u32 *)(self + 0x5b) = ext_4e5e60(dbread);
  else *(u32 *)(self + 0x5b) = 0;
  if (tagOf(dbread) != 0xff && (tagOf(dbread) & 0x3f) == 2) *(float *)(self + 0x5f) = ext_4e5e80(dbread);
}
PCREG(5827d0, hitpointCopyEventDataBlock);
