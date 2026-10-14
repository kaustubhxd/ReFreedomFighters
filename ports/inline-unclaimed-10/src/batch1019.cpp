// batch1019.cpp - unclaimed-10, batch 15 (docs/20-unclaimed-10.md): CMsgForward::CopyEventDataBlock(DBREAD&) (0x49eed0),
// thiscall, one argument (the DBREAD), ret 4. this+0x48 = 0x4e5e60(DBREAD) (dword); the engine object (global 0x70039c, field
// +0x9b) gets slot +0x58 with that dword; this+0x4c = low word of 0x4e5e40(DBREAD). The two DBREAD readers are unverified
// callees run as original code (ext_), hooked in the spec with fixed results; the engine slot is stubbed.
#include "ff.h"

#define VT(o) (*(void ***)(o))

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);  // DBREAD reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);  // DBREAD reader, original code (hooked in the spec)

typedef void(THISCALL *SlotEngine)(u8 *self, u32 a);  // engine->vt[+0x58](value)

// 0x49eed0, CMsgForward::CopyEventDataBlock(DBREAD&) (high)
static void THISCALL msgForwardCopyEventDataBlock(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x48) = ext_4e5e60(dbread);
  u8 *engine = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(engine + 0x9b);
  ((SlotEngine)VT(obj)[0x58 / 4])(obj, *(u32 *)(self + 0x48));
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(dbread);
}
PCREG(49eed0, msgForwardCopyEventDataBlock);
