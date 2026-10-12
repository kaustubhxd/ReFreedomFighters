// batch787.cpp - unclaimed-77 claim 17 (docs/20-unclaimed-77.md): CGlobalCom::GetpVal(const char*, int) const (medium). Thiscall, two
// stack arguments, ret 8. The callee 0x4d2b40 is stubbed in the harness (GUESS): thiscall, two stack arguments, returns eax.
#include "ff.h"

extern "C" u32 THISCALL ext_4d2b40(void *self, const char *name, s32 index);   // stubbed (GUESS): returns eax

// 0x4d2fc0, CGlobalCom::GetpVal(const char*, int) const (medium): r = callee(this, name, index); r + 5 when r is nonzero, else 0.
static u32 THISCALL globalComGetpVal(u8 *self, const char *name, s32 index) {
  u32 r = ext_4d2b40(self, name, index);
  return r != 0 ? r + 5u : 0u;
}
PCREG(4d2fc0, globalComGetpVal);
