// batch5832.cpp - residue 9, 0x49eed0 (CMsgForward::CopyEventDataBlock(DBREAD&), gc name map), thiscall, one stack argument (DBREAD&), ret 4.
// this+0x48 = reader A(db) (0x4e5e60, original code, hooked); sub->vt[+0x58](this+0x48) (sub = engine+0x9b); this+0x4c (word) = reader B(db) (0x4e5e40, hooked).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);  // reader A (dword), original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);  // reader B (word in ax), original code (hooked in the spec)

// 0x49eed0, thiscall, one stack argument (CopyEventDataBlock)
static void THISCALL unnamed49eed0(u8 *self, u8 *db) {
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  ((Slot1)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x48));
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(db);
}
PCREG(49eed0, unnamed49eed0);
