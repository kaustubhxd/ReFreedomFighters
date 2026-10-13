// batch414.cpp - residue 2 rows 0x4a80a0 and 0x60fe20.
// 0x4a80a0 (thiscall, no arguments, returns this): calls 0x469870 (thiscall, no arguments; GUESS, hooked by address), then
// sets bit 0x20 of [this+4], [this+0x44] = 0 and the vtable [this] = 0x6901b0.
// 0x60fe20 (cdecl, no arguments): if dword [0x724958] != dword [0x724950]: [0x724950] = [0x724958]; obj = dword [0x724a00];
// call slot 0xc8 of obj's vtable with ECX = the vtable pointer, arguments (obj, 0x22, value of 0x724958).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_469870(void *self);   // exe callee, hooked in the spec (GUESS)

typedef void(THISCALL *Slot3Fn)(void *ecxVtable, void *obj, u32 a, u32 b);

static u8 *THISCALL initWithVtable(u8 *self) {
  ext_469870(self);
  U32(self, 0x4) |= 0x20u;
  U32(self, 0x44) = 0;
  U32(self, 0x0) = 0x6901b0u;
  return self;
}

static void cdeclSlot0xc8(void) {
  u32 cur = G(u32, 0x724958);
  if (cur == G(u32, 0x724950))
    return;
  *(u32 *)0x724950u = cur;
  u32 obj = G(u32, 0x724a00);
  u32 vt = *(u32 *)(unsigned long)obj;
  u32 fn = *(u32 *)(unsigned long)(vt + 0xc8);
  ((Slot3Fn)(unsigned long)fn)((void *)(unsigned long)vt, (void *)(unsigned long)obj, 0x22u, cur);
}

PCREG(4a80a0, initWithVtable);
PCREG(60fe20, cdeclSlot0xc8);
