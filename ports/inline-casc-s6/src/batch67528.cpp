// batch67528.cpp - cascade s6 batch 67528: 0x64d230.
#include "ff.h"

extern "C" u32 THISCALL ext_63f3e0(u8 *e, u8 *obj, u8 *owner);   // ret 8
extern "C" u32 THISCALL ext_658f10(u8 *e, u32 idx);              // ret 4
extern "C" int THISCALL ext_658f50(u8 *e);                       // plain ret

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define D16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x64d230, thiscall(req) ret 4: resolves the object slot 0x60 returns for the request's id (word at [req[8]+4]), asks the 0x63f3e0 manager (this[0x1005d]) to attach it to the owner at
// req[8], stores the result at owner[0x10] and makes sure the 4096-entry table at this[0x10071] has an entry for the object's key (word at +0x40, & 0xfff), allocating one through the
// factory at this[0x10169] (slot 8, +8 = result, registered with slot 0x5c) when empty. Then the same for each further child (0x658f10 for index 1 .. count-1, count from 0x658f50).
// Returns 0 only when the manager refuses the first object, 1 otherwise.
static u32 THISCALL fn64d230(u8 *self, u8 *req) {
  u8 *owner = *(u8 **)(req + 8);
  u8 *obj = vcall<u8 *>(self, 0x60, (u32)D16(*(u8 **)(owner + 8), 4));
  if (!obj) return 1;
  u32 res = ext_63f3e0(*(u8 **)(self + 0x1005d), obj, owner);
  if (!res) return 0;
  D32(owner, 0x10) = res;
  if (D32(*(u8 **)(self + 0x10071), (D16(obj, 0x40) & 0xfff) * 4) == 0) {
    u8 *fac = *(u8 **)(self + 0x10169);
    u8 *s = vcall<u8 *>(fac, 8);
    D32(s, 8) = res;
    vcall<void>(self, 0x5c, (u32)s);
    D32(*(u8 **)(self + 0x10071), (D16(obj, 0x40) & 0xfff) * 4) = (u32)s;
  }
  int n = ext_658f50(owner);
  for (int i = 1; i < n; i++) {
    u8 *p = (u8 *)ext_658f10(owner, (u32)i);
    if (!p) continue;
    u32 r = ext_63f3e0(*(u8 **)(self + 0x1005d), p, owner);
    if (D32(*(u8 **)(self + 0x10071), (D16(p, 0x40) & 0xfff) * 4) == 0) {
      u8 *fac = *(u8 **)(self + 0x10169);
      u8 *s = vcall<u8 *>(fac, 8);
      D32(s, 8) = r;
      vcall<void>(self, 0x5c, (u32)s);
      D32(*(u8 **)(self + 0x10071), (D16(p, 0x40) & 0xfff) * 4) = (u32)s;
    }
  }
  return 1;
}
PCREG(64d230, fn64d230);
