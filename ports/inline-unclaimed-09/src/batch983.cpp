// batch983.cpp - area 56 band, claim A49 (0x536750): a search loop with a register-argument call.
#include "ff.h"

extern "C" u32 FASTCALL ext_4cc850(u32 ecx, u32 edx);  // original exe helper (register arguments; hooked in the spec, GUESS)

// A49 0x536750: field = this->5302; arr = base + field (the exe overwrites its base argument with base + field);
// for i < count: entry = arr[i] + field; if ext_4cc850(entry[1] + field, a) == 0 return entry.
static u32 THISCALL f536750(u8 *self, u32 base, u32 count, u32 a) {
  u32 field = *(u32 *)(self + 0x5302);
  if (field == 0 || base == 0 || count == 0) return 0;
  u32 arr = base + field;
  for (u32 i = 0; i < count; i++) {
    u32 entry = *(u32 *)(arr + 4 * i) + field;
    u32 r = ext_4cc850(*(u32 *)(entry + 4) + field, a);
    if (r == 0) return entry;
  }
  return 0;
}
PCREG(536750, f536750);
