// batch67527.cpp - cascade s6 batch 67527: 0x65c3e0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x65c3e0, thiscall(unused) ret 4: walks the 8-byte records [this+0x24 .. this+(this[0x20]+5)*8) and drives the object's slots: slot 0x44 when the record's key changes
// class bits (0x78000000), slots 0x78 / 0x7c to switch the record kind (low nibble), slot 0x74 when the 0x7ff0 field changes and the payload has a +8 field, and slot 0x80 for
// every record whose key equals the previous one. A kind-9 record stops the walk. The cursor is written back; returns whether records remain.
static u32 THISCALL fn65c3e0(u8 *self, u32 unused) {
  u32 *end = (u32 *)(self + (D32(self, 0x20) + 5) * 8);
  u32 *esi = *(u32 **)(self + 0x24);
  if (esi == end) return 0;
  u32 vc = 0xffffffffu;
  u8 bl = 0xff;
  for (;;) {
    u32 ecx = esi[0];
    u8 *v8 = (u8 *)esi[1];
    if (vc == ecx) goto do80;
    if ((ecx & 0xf) == 9) { esi += 2; break; }
    if (((ecx ^ vc) & 0x78000000u) == 0) goto do45a;
    if ((ecx & 0x78000000u) == 0x78000000u) goto next;
    vcall<void>(self, 0x44, D32(*(u8 **)(v8 + 0x14), 0x20));
  do45a:
    if (bl != (esi[0] & 0xf)) {
      if (bl != 0xff) vcall<void>(self, 0x7c, (u32)bl);
      bl = (u8)(esi[0] & 0xf);
      vcall<void>(self, 0x78, (u32)bl);
    }
    if ((esi[0] ^ vc) & 0x7ff0) {
      u32 p = D32(v8, 8);
      if (p) vcall<void>(self, 0x74, p, (u32)bl);
    }
    vc = esi[0];
  do80:
    vcall<void>(self, 0x80, (u32)v8, (u32)bl);
  next:
    esi += 2;
    if (esi == end) break;
  }
  *(u32 **)(self + 0x24) = esi;
  if (bl != 0xff) vcall<void>(self, 0x7c, (u32)bl);
  return esi != end;
}
PCREG(65c3e0, fn65c3e0);
