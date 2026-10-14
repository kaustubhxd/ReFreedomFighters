// batch1688.cpp - 0x476d30 (GUESS, residue 13 gap band, 2026-10-12). Save-style, thiscall, one stack argument (the saver),
// ret 4. ZGROUP::Save (0x441790, hooked; thiscall, one argument, ret 4) first; when its low byte is zero, returns its eax.
// Otherwise: saver slot 0x60(byte this+0x72), slot 0x40(word this+0x70). When the byte at +0x72 is set: saver slot 0x64(dword
// this+0x6c), and returns (last eax with low byte 1). Else: slot 0x44(this+0x5c), slot 0x44(this+0x60), then for each of the
// count (this+0x5c) entries of the array at this+0x64, slot 0x64(entry); then slot 0x10(this+0x68, count*4); returns the last
// eax with low byte 1. GUESS: the slot names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_441790[];
typedef u32(THISCALL *SaveFn)(void *self, u32 saver);

u32 THISCALL GUESS_476d30(u8 *self, u32 saver) {
  u32 r = ((SaveFn)(void *)ext_441790)(self, saver);
  if (!(u8)r) return r;
  vcall<void>((void *)saver, 0x60, (u32)AT(u8, self, 0x72));
  vcall<void>((void *)saver, 0x40, (u32)AT(u16, self, 0x70));
  if (AT(u8, self, 0x72)) {
    u32 last = vcall<u32>((void *)saver, 0x64, AT(u32, self, 0x6c));
    return (last & 0xffffff00u) | 1u;
  }
  vcall<void>((void *)saver, 0x44, AT(u32, self, 0x5c));
  vcall<void>((void *)saver, 0x44, AT(u32, self, 0x60));
  s32 n = AT(s32, self, 0x5c);
  for (s32 i = 0; i < n; i++) {
    u32 entry = AT(u32, AT(u8 *, self, 0x64), (u32)i * 4);
    vcall<void>((void *)saver, 0x64, entry);
  }
  u32 last = vcall<u32>((void *)saver, 0x10, AT(u32, self, 0x68), (u32)n * 4);
  return (last & 0xffffff00u) | 1u;
}
PCREG(476d30, GUESS_476d30);
