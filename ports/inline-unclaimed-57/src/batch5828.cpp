// batch5828.cpp - residue 9, 0x479810 (ZActor::OnPathCanceled(ZActor::PATH_CANCEL_REASONS), gc name map), thiscall, one stack arg, ret 4.
// this->vt[+0x128]((u16)G(0x6ffa2c), arg, 0); this+0x6ba = 0 (dword); this+0x6be = 0 (byte).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot3)(u8 *self, u32 a, u32 b, u32 c);

// 0x479810, thiscall, one stack argument (ZActor::OnPathCanceled)
static void THISCALL unnamed479810(u8 *self, u32 reason) {
  ((Slot3)VT(self)[0x128 / 4])(self, (u32)G(u16, 0x6ffa2c), reason, 0);
  *(u32 *)(self + 0x6ba) = 0;
  *(u8 *)(self + 0x6be) = 0;
}
PCREG(479810, unnamed479810);
