// batch422.cpp - residue 2 row 0x565a60 (thiscall, no arguments). A = dword [[0x70039c] + 0x9b]; B = vtable slot 0x138 of A
// (thiscall, no arguments; returns eax); local = 0; slot 0x88 of B with arguments (0x6a6c28, &local); dword [this+0xcae] = local;
// 0x563a50 with ECX = this (thiscall, no arguments; GUESS, hooked by address in the spec).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_563a50(void *self);

static void THISCALL loadThroughEngine(u8 *self) {
  u32 engine = G(u32, 0x70039c);
  u32 A = U32(engine, 0x9b);
  u32 B = vcall<u32>((void *)(unsigned long)A, 0x138);
  u32 local = 0;
  vcall<void>((void *)(unsigned long)B, 0x88, 0x6a6c28u, (u32)(unsigned long)&local);
  U32(self, 0xcae) = local;
  ext_563a50(self);
}
PCREG(565a60, loadThroughEngine);
