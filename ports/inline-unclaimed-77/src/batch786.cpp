// batch786.cpp - unclaimed-77 claim 16 (docs/20-unclaimed-77.md): ZBigFile::Exists(const char*) (high). Thiscall, one argument,
// ret 4. The callee 0x4d4de0 is stubbed in the harness (GUESS): thiscall, one argument, returns a value in eax.
#include "ff.h"

extern "C" u32 THISCALL ext_4d4de0(void *self, const char *name);   // stubbed (GUESS): returns eax

// 0x4d4dc0, ZBigFile::Exists(const char*) (high): the callee's eax, with its low byte replaced by (eax != 0) (setne al leaves the
// upper bits of eax alone).
static u32 THISCALL bigFileExists(u8 *self, const char *name) {
  u32 r = ext_4d4de0(self, name);
  return (r & 0xffffff00u) | (u32)(r != 0);
}
PCREG(4d4dc0, bigFileExists);
