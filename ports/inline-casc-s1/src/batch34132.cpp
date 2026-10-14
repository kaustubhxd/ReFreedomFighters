// batch34132.cpp - cascade tier E, batch 34132: 0x4ce050 (is a name in an enumerated list).
#include "ff.h"

typedef int (*stricmp_t)(const char *, const char *);

// 0x4ce050, thiscall(name) ret 4: false for a null this. Otherwise this->slot0x4c(&it), r = this->slot0x5c(&it) (it = 12-byte local, first dword is the "more" flag);
// while it[0] != 0: when _stricmp(r, name) (import [0x676414], cdecl) is 0 return true, else r = this->slot0x5c(&it). Returns false when the list ends.
static u32 THISCALL fn4ce050(u8 *self, const char *name) {
  u32 it[3];
  if (!self) return 0;
  vcall<void>(self, 0x4c, (u32)it);
  const char *r = vcall<const char *>(self, 0x5c, (u32)it);
  while (it[0] != 0) {
    if (!G(stricmp_t, 0x676414)(r, name)) return 1;
    r = vcall<const char *>(self, 0x5c, (u32)it);
  }
  return 0;
}
PCREG(4ce050, fn4ce050);
