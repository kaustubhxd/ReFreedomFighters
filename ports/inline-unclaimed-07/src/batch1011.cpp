// batch1011.cpp - unclaimed-07 batch 11 (docs/20-unclaimed-07.md, slice 6): ZItemTemplateWeapon::CopyData.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x43f8c0: the base-class copy (thiscall, one argument; original code, not lifted here).
extern "C" void THISCALL ext_43f8c0(u8 *self, u8 *src);

// 0x46cc20, ZItemTemplateWeapon::CopyData(const ZGEOM*) (high): ext_43f8c0(this, src) first; when src slot +0x1e0(0x1007d4)
// is false, returns. Otherwise copies the fields at +0xc6, +0xa4, +0xc0, +0x98, +0x9c, +0xa8, +0xac, +0xb0, +0xb4, +0xb8,
// +0xbc, +0xc5, +0xc4 and +0xd3 from src to this. When src+0xa0 is non-null: slot +0x4c(&local); item = slot +0x5c(&local);
// while local is non-zero: this+0xa0 slot +4(item); item = src+0xa0 slot +0x5c(&local). Then this+0x11b and +0x11f are 0.
static void THISCALL weaponCopyData(u8 *self, u8 *src) {
  ext_43f8c0(self, src);
  if (!(u8)vcall<u32>(src, 0x1e0, 0x1007d4u))
    return;
  *(u8 *)(self + 0xc6) = *(u8 *)(src + 0xc6);
  *(u32 *)(self + 0xa4) = *(u32 *)(src + 0xa4);
  *(u32 *)(self + 0xc0) = *(u32 *)(src + 0xc0);
  *(u32 *)(self + 0x98) = *(u32 *)(src + 0x98);
  *(u32 *)(self + 0x9c) = *(u32 *)(src + 0x9c);
  *(u32 *)(self + 0xa8) = *(u32 *)(src + 0xa8);
  *(u32 *)(self + 0xac) = *(u32 *)(src + 0xac);
  *(u32 *)(self + 0xb0) = *(u32 *)(src + 0xb0);
  *(u32 *)(self + 0xb4) = *(u32 *)(src + 0xb4);
  *(u32 *)(self + 0xb8) = *(u32 *)(src + 0xb8);
  *(u32 *)(self + 0xbc) = *(u32 *)(src + 0xbc);
  *(u8 *)(self + 0xc5) = *(u8 *)(src + 0xc5);
  *(u8 *)(self + 0xc4) = *(u8 *)(src + 0xc4);
  *(u32 *)(self + 0xd3) = *(u32 *)(src + 0xd3);
  u8 *list = *(u8 **)(src + 0xa0);
  if (list) {
    u32 local = 0;
    vcall<void>(list, 0x4c, &local);
    u32 item = vcall<u32>(*(void **)(src + 0xa0), 0x5c, &local);
    if (local != 0) {
      do {
        vcall<void>(*(void **)(self + 0xa0), 4, item);
        item = vcall<u32>(*(void **)(src + 0xa0), 0x5c, &local);
      } while (local != 0);
    }
  }
  *(u32 *)(self + 0x11b) = 0;
  *(u32 *)(self + 0x11f) = 0;
}
PCREG(46cc20, weaponCopyData);
