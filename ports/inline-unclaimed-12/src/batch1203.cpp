// batch1203.cpp - unclaimed-12: batch 3 (docs/20-unclaimed-12.md, claim 3). Thiscall; callee pops the stack args.
// Names are from the GC name map (high confidence for both). ext_<hex> is the original code at that address (build.sh binds it).
#include "ff.h"

// the base class CopyData entry at 0x45d5b0: loads the vtable of ecx and jumps through slot +0x48 (original code, not lifted here)
extern "C" void THISCALL ext_45d5b0(u8 *self, const u8 *src);

// 0x5a65c0, ZFFPRIVATESTDOBJ::CopyData(const ZGEOM*) (high): when src->+0xc->+0x23 equals 0x200482, copies dword +0x18 from
// the source; then tail-jumps to the base CopyData (ext_45d5b0 here, as a call: the callee pops the same one argument).
static void THISCALL privStdObjCopyData(u8 *self, const u8 *src) {
  const u8 *block = *(const u8 *const *)(src + 0xc);
  if (*(const u32 *)(block + 0x23) == 0x200482) *(u32 *)(self + 0x18) = *(const u32 *)(src + 0x18);
  ext_45d5b0(self, src);
}
PCREG(5a65c0, privStdObjCopyData);

// 0x59d250, the exe function called below (its arguments are (obj, 2, dword +0x48 of this, 1); ret 0xc).
extern "C" void THISCALL ext_59d250(u8 *self, u32 a, u32 b, u32 c);

// 0x5b7a10, ZTargetObtained2::Command(unsigned short, void*) (high): when the word argument equals the word at +0x4c, calls
// 0x59d250 on the object at (global 0x7003b8)+0x2c15 with arguments 2, the dword at +0x48 and 1. Always returns 0.
static u32 THISCALL targetObtained2Command(u8 *self, u32 cmd, void *) {
  if ((u16)cmd == *(const u16 *)(self + 0x4c)) {
    u8 *base = G(u8 *, 0x7003b8);
    u8 *target = *(u8 **)(base + 0x2c15);
    ext_59d250(target, 2, *(const u32 *)(self + 0x48), 1);
  }
  return 0;
}
PCREG(5b7a10, targetObtained2Command);
