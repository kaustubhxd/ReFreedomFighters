// batch34117.cpp - cascade tier E, batch 34117: 0x4ceae0 (log every item of a container).
#include "ff.h"

// 0x4ceae0, thiscall plain: nothing when this is null. this->slot0x4c(&it); p = this->slot0x64(&it); while p is non-zero: log = [0x700390]->slot0x20(0x695b7c, 0x35d); log->slot0x2c(log, 0x695c2c, p[0], p[[this+0x18] - 1]) (cdecl,
// ecx clobbered); p = this->slot0x64(&it).
static void THISCALL fn4ceae0(u8 *self) {
  u32 it[3];
  if (!self) return;
  vcall<void>(self, 0x4c, (u32)it);
  u32 *p = vcall<u32 *>(self, 0x64, (u32)it);
  while (p) {
    u8 *lg = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x695b7cu, 0x35du);
    u32 k = *(u32 *)(self + 0x18);
    typedef void (*pf)(u8 *, u32, u32, u32);
    (*(pf *)(*(u8 **)lg + 0x2c))(lg, 0x695c2c, p[0], p[k - 1]);
    p = vcall<u32 *>(self, 0x64, (u32)it);
  }
}
PCREG(4ceae0, fn4ceae0);
