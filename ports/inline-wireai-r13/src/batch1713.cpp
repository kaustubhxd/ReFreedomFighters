// batch1713.cpp - two small functions from the area-13 band, 2026-10-12. GUESS names.
// 0x651010: thiscall, two stack arguments, ret 8. Stores a at this+0x84 and b at this+0x88.
// 0x64fad0: thiscall, no stack arguments, plain ret (so the tail target takes none either). Loads the child pointer at the
//   unaligned offset this+0xbd; when it is non-null, tail-jumps through the child's vtable slot 0x60 with ecx = child. The null
//   path leaves eax untouched, so the return value is modelled as void (the spec does not compare eax).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

void THISCALL GUESS_651010(u8 *self, u32 a, u32 b) {
  AT(u32, self, 0x84) = a;
  AT(u32, self, 0x88) = b;
}
PCREG(651010, GUESS_651010);

typedef void(THISCALL *Slot0Fn)(void *self);

void THISCALL GUESS_64fad0(u8 *self) {
  u8 *child = AT(u8 *, self, 0xbd);
  if (child)
    ((Slot0Fn)AT(void *, AT(u8 *, child, 0), 0x60))(child);
}
PCREG(64fad0, GUESS_64fad0);
