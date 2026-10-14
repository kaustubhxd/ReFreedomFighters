// batch34134.cpp - cascade tier E, batch 34134: 0x4f67a0 (command handler).
#include "ff.h"

// 0x4f67a0, thiscall(id, unused) ret 8: with t = [this+0x44]: when (u16)id == word [this+0x48]: t->slot0x374(0, 1); r = t->slot0x2c4(); v = t->slot0x20(); r->slot0x2fc(v) (r's vtable read before the slot-0x20 call);
// t->slot0xbc(0); this->slot0x64(0x10). Else when (u16)id == word [this+0x4a]: this->slot0x68(0x10, 0). Always returns 0.
static u32 THISCALL fn4f67a0(u8 *self, u32 id, u32 unused) {
  u16 w = (u16)id;
  if (w == *(u16 *)(self + 0x48)) {
    u8 *t = *(u8 **)(self + 0x44);
    vcall<void>(t, 0x374, 0u, 1u);
    t = *(u8 **)(self + 0x44);
    u8 *r = vcall<u8 *>(t, 0x2c4);
    t = *(u8 **)(self + 0x44);
    u8 *vt = *(u8 **)r;
    u32 v = vcall<u32>(t, 0x20);
    typedef void (THISCALL *f1)(void *, u32);
    (*(f1 *)(vt + 0x2fc))(r, v);
    t = *(u8 **)(self + 0x44);
    vcall<void>(t, 0xbc, 0u);
    vcall<void>(self, 0x64, 0x10u);
    return 0;
  }
  if (w == *(u16 *)(self + 0x4a)) vcall<void>(self, 0x68, 0x10u, 0u);
  return 0;
}
PCREG(4f67a0, fn4f67a0);
