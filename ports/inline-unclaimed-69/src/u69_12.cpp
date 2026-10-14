// u69_12.cpp - area 69, group 12 (unclaimed-69 thread).
#include "ff.h"

extern "C" void THISCALL ext_45d3a0(void *self);  // ZGEOM::ClassInit2 (other area; stubbed in the spec: GUESS)

// 0x4ef090, ZCHAROBJ::ClassInit2() (GC map medium). thiscall, void. Calls ZGEOM::ClassInit2, then looks at the string at +0x9b:
// if it is non-empty and starts with '%', slot 0x284 is called with the rest; otherwise slot 0x288 is called with the
// string and the constant address 0x677b5a (the exe pushes the string first, so the constant is the first argument).
static void THISCALL charObjClassInit2(u8 *self) {
  ext_45d3a0(self);
  u8 *str = *(u8 **)(self + 0x9b);
  if (!str || *str == 0)
    return;
  if (*str == '%') {
    vcall<void>(self, 0x284, (void *)(str + 1));
    return;
  }
  vcall<void>(self, 0x288, (void *)0x677b5a, (void *)str);
}
PCREG(4ef090, charObjClassInit2);
