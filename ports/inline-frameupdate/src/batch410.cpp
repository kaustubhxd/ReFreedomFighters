// batch410.cpp - ZCollisionBox::GetStrips(unsigned int mask) [low], 0x4ea300. thiscall, ret 4.
// Asks the box system (object at [[0x70039c]+0x1aa3]+0x1c) to fill the strip buffer at +8 (count +0xc, capacity +0x10)
// via slot 0x84 with eight arguments; on failure (buffer too small) it logs an error from zcollisionbox.cpp line 0x87
// and clears the strip count +0x14. Name: GC ZCollisionBox::GetStrips(unsigned int) [low]; the pushes and the error text
// match, so the name is kept at low confidence.
#include "ff.h"

typedef void(__attribute__((cdecl)) *logPrint)(void *obj, const char *fmt, u32 size);

static u8 THISCALL boxGetStrips(u8 *self, u32 mask) {
  u8 *box = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
  u8 ok = vcall<u8>(box, 0x84, (u32)(self + 8), *(u32 *)(self + 0xc), *(u32 *)(self + 0x10),
                    (u32)(self + 0x18), (u32)(self + 0x3c), (u32)(self + 0x48), mask, 0u);
  if (ok) {
    *(u32 *)(self + 0x14) = 0;
    return 1;
  }
  u8 *log = vcall<u8 *>(G(u8 *, 0x700390), 0x20, (const char *)0x697650u, 0x87u);  // zcollisionbox.cpp
  u8 *vt = *(u8 **)log;
  ((logPrint)(*(void **)(vt + 0x2c)))(log, (const char *)0x697680u, *(u32 *)(self + 0x10));  // "ERROR: Stack buffer size %d ..."
  *(u32 *)(self + 0x14) = 0;
  return 0;
}
PCREG(4ea300, boxGetStrips);
