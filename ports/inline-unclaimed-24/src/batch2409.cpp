// batch2409.cpp - decomp area 24, batch 2409: CAction::ChangeNames(const char*) (0x49fd70), thiscall, ret 4.
// Vtable slot 0x88 on this with (name, 0). When self[+0x63] is set, slot 0x128 on the object at self[+0x44] with
// (the word global at 0x7002c8, 1, that object).
#include "ff.h"

// 0x49fd70
static void THISCALL actionChangeNames(u8 *self, const char *name) {
  vcall<void>(self, 0x88, name, 0u);
  if (self[0x63] != 0) {
    void *o = *(void **)(self + 0x44);
    u32 w = G(u16, 0x7002c8);
    vcall<void>(o, 0x128, w, 1u, o);
  }
}
PCREG(49fd70, actionChangeNames);
