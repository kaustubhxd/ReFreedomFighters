// batch6210.cpp - unclaimed-62 claim 4 (slice 1): ZGEOM::FindEvent(const char *name) const [map 0x45e490; thiscall, ret 4]. Gated by
// 0x4da3a0 (exe). Walks the list at this+0x10 -> +8 (begin +0x4c, next +0x5c). Each element comes from the allocator's slot 0xcc; when its
// slot 0x14 gives a non-zero value, the wildcard matcher 0x4cc850 (exe; fastcall: value in ecx, name in edx) is run on that value; a result
// of zero is the match and the element is returned. Otherwise 0.
#include "ff.h"

extern "C" u8 THISCALL ext_4da3a0(u8 *self);                             // gate (exe)
extern "C" u32 FASTCALL ext_4cc850(u32 value, const char *name);          // wildcard matcher (exe): 0 on a match

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static u8 *THISCALL zgeomFindEvent(u8 *self, const char *name) {
  if (!ext_4da3a0(rdp(self + 8))) return 0;
  u8 *ilist = rdp(rdp(self + 0x10) + 8);
  if (!ilist) return 0;
  u32 it[3];
  vcall<void>(ilist, 0x4c, it);
  u32 cur = vcall<u32>(ilist, 0x5c, it);
  if (!it[0]) return 0;
  do {
    u8 *el = (u8 *)vcall<u32>(G(u8 *, 0x70038c), 0xcc, cur);
    if (el && vcall<u32>(el, 0x14)) {
      u32 value = vcall<u32>(el, 0x14);
      if (ext_4cc850(value, name) == 0) return el;
    }
    cur = vcall<u32>(rdp(rdp(self + 0x10) + 8), 0x5c, it);
  } while (it[0] != 0);
  return 0;
}
PCREG(45e490, zgeomFindEvent);
