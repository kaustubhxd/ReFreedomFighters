#include "ff.h"
// batch937.cpp - unclaimed-80 gap row (docs/20-unclaimed-80.md). ZLNKOBJ::CheckActiveAnim(const char*, int) (0x461980, high). Thiscall,
// two stack arguments (ret 8), bool result in al. The table at this+0x1c has 24-byte entries; the entry for index a2 is used when its
// flag byte (+4) has bit 0 set and its pointer (+0x14) plus 0x4c is nonzero. Then 0x4cc850 is called with ecx = that pointer + 0x4c and
// edx = a1 (fastcall, original code, stubbed by the spec); the result is true when it returns zero.

extern "C" u32 FASTCALL ext_4cc850(u8 *ecx, u32 edx);

static u8 THISCALL lnkObjCheckActiveAnim(u8 *self, u32 a1, u32 a2) {
  u8 *e = *(u8 **)(self + 0x1c) + 24 * a2;
  if ((e[4] & 1) == 0)
    return 0;
  u8 *p = *(u8 **)(e + 0x14);
  if (p + 0x4c == 0)
    return 0;
  u32 r = ext_4cc850(p + 0x4c, a1);
  return r == 0 ? 1 : 0;
}
PCREG(461980, lnkObjCheckActiveAnim);
