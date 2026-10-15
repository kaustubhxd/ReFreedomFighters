// batch824.cpp - animation layer thread, batch 824 (VM restart 2026-10-11): ZLNKOBJ::CopyAnimFilePointersFrom.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" const char *THISCALL ext_4e5330(void *pack);   // ZAnimFilePack::GetAnimFileName() const (name map medium)

// ZLNKOBJ::CopyAnimFilePointersFrom(ZLNKOBJ* src) [GC name map, see docs/20-anim.md], thiscall, ret 4.
// Clears the anim file (+0x5c) and extra anim file (+0x60) pointers; for each one the source has, the file is looked
// up again by name through own slot 0x2f4(name, out) with out = this+0x64 / this+0x68, and the result is stored.
// The "stray push" noted before was MSVC's argument order: out is pushed before GetAnimFileName is called, then the
// name; slot 0x2f4 pops both (the epilogue has no mov esp, ebp, so it must pop 8).
static void THISCALL CopyAnimFilePointersFrom(u8 *self, u8 *src) {
  F32(self, 0x5c) = 0;
  F32(self, 0x60) = 0;
  if (FP(src, 0x5c))
    F32(self, 0x5c) = vcall<u32>(self, 0x2f4, ext_4e5330(FP(src, 0x5c)), self + 0x64);
  if (FP(src, 0x60))
    F32(self, 0x60) = vcall<u32>(self, 0x2f4, ext_4e5330(FP(src, 0x60)), self + 0x68);
}
PCREG(461fa0, CopyAnimFilePointersFrom);
