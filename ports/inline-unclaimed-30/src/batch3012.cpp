// batch3012.cpp - unclaimed-30: batch 12 (docs/20-unclaimed-30.md, claim 1). ZFFActor::ReplaceSpecialAnim(name, id) [map 0x5a2890;
// thiscall, ret 8]. A null name returns 0. "cc_punch" replaces the dword at +0x7ae and "cc_kick" the one at +0x7b2: the new value is
// this's slot 0x5a0 (id), the old value goes to slot 0x598. Any other name reports line 0x2e5 and calls slot 0x598 with id.
// The name tests are _stricmp == 0 (case-insensitive) in the exe.
#include "ff.h"

typedef void (*reportStrFn)(void *, const char *, const char *);

// _stricmp == 0: ASCII case-folded equality (the C locale).
static u8 lowerAscii(u8 c) { return (c >= 'A' && c <= 'Z') ? (u8)(c + 32) : c; }
static bool strEq(const char *a, const char *b) {
  for (;; a++, b++) {
    if (lowerAscii((u8)*a) != lowerAscii((u8)*b)) return false;
    if (!*a) return true;
  }
}

// The exe tests the second argument (id) for zero first; its slot is then reused as the "old value" output, so the error path
// releases 0 (not id).
static u32 THISCALL replaceSpecialAnim(u8 *self, const char *name, u32 id) {
  if (!id) return 0;
  u32 old = 0;
  if (strEq(name, (const char *)0x6ae918)) {
    old = *(u32 *)(self + 0x7ae);
    u32 nu = vcall<u32>(self, 0x5a0, id);
    *(u32 *)(self + 0x7ae) = nu;
    vcall<void>(self, 0x598, old);
  } else if (strEq(name, (const char *)0x6ae924)) {
    old = *(u32 *)(self + 0x7b2);
    u32 nu = vcall<u32>(self, 0x5a0, id);
    *(u32 *)(self + 0x7b2) = nu;
    vcall<void>(self, 0x598, old);
  } else {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x6ae6a0, 0x2e5);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6ae930, name);
    vcall<void>(self, 0x598, old);
  }
  return 0;
}
PCREG(5a2890, replaceSpecialAnim);
