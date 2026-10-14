// batch5738.cpp - unclaimed-57, band batch 38 (names GUESS).
// 0x5de230 (stdcall, two args (w, a2), ret 8, returns 0): if (word)w == word at 0x7143a0, call 0x5de090(a2) (stdcall, one arg; unverified,
//   hooked and logged in the spec).
// 0x5d83e0 (thiscall, no args, ret): return if byte this+0xbb != 0; return if (signed) dword (dword 0x70039c)+0x40 <= dword this+0xb3;
//   0x5d8470(this) (thiscall, no args; unverified, hooked and logged); return if dword this+0xbc != 0; sub = dword this+0x44;
//   sub->vt[+0x114](0x10) (thiscall, one argument; stubbed in the spec).
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

extern "C" void STDCALL ext_5de090(u32 a);            // unverified, original code (logged in the spec)
extern "C" void THISCALL ext_5d8470(u8 *self);        // unverified, original code (logged in the spec)

static u32 STDCALL unnamed5de230(u32 w, u32 a2) {
  if ((u16)w == G(u16, 0x7143a0)) ext_5de090(a2);
  return 0;
}
PCREG(5de230, unnamed5de230);

static void THISCALL unnamed5d83e0(u8 *self) {
  if (self[0xbb] != 0) return;
  u8 *eng = G(u8 *, 0x70039c);
  if ((s32)*(u32 *)(eng + 0x40) <= (s32)*(u32 *)(self + 0xb3)) return;
  ext_5d8470(self);
  if (*(u32 *)(self + 0xbc) != 0) return;
  u8 *sub = *(u8 **)(self + 0x44);
  ((Slot1)VT(sub)[0x114 / 4])(sub, 0x10);
}
PCREG(5d83e0, unnamed5d83e0);
