// batch1035.cpp - area 81, batch 1035: 0x43a380, thiscall (this), no stack arguments, plain ret. No SEH frame, no cookie check.
// A lookup in the global table at 0x6e48c0 (16-byte records; the first record whose link equals the sentinel 0x6e41d0 is used, the
// record's buffer pointer and count come from its words). For each of count entries: this->vslot 0xa8 is called (thiscall, one argument:
// the entry's word at +4 of the array at +8), its result r selects the flag byte at sys+0xf0b+5*r. The buffer byte at (entry index + this+0x131c)
// is set to 0 when the flag is below 0x80 and to 0x7f otherwise; when bit 0x40 is set, the byte is set to 0x7f and bit 0x40 is cleared.
// No stand-ins: the lookup and flags are memory, the virtual call goes to the object's own slot.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define G32(a) (*(volatile u32 *)(a))
#define B8(a) (*(volatile u8 *)(a))

// 0x43a380 (thiscall: this).
static void THISCALL lookupFlags(u8 *self) {
  u8 *sys = (u8 *)G32(0x70039c);
  u32 esi = 0;
  u32 eax = G32(0x6e48c0);
  if (eax != 0) {
    for (;;) {
      if (eax == 0x6e41d0) {
        esi = esi * 16 + 0x6e48b8;
        break;
      }
      esi++;
      eax = G32(esi * 16 + 0x6e48c0);
      if (eax == 0) {
        esi = 0;
        break;
      }
    }
  }
  u8 *rec = (u8 *)esi;
  u8 *buf = (u8 *)D(rec, 0);
  u32 count = D(rec, 0xc);
  u8 *arr = (u8 *)D(rec, 8);
  for (u32 i = 0; i < count; ++i) {
    u32 arg = D(arr, 12 * i + 4);
    u32 r = vcall<u32>(self, 0xa8, arg);
    u8 *flag = sys + r * 5 + 0xf0b;
    u8 *out = buf + i;
    if (B8(flag) < 0x80)
      out[D(self, 0x131c)] = 0;
    else
      out[D(self, 0x131c)] = 0x7f;
    if (B8(flag) & 0x40) {
      out[D(self, 0x131c)] = 0x7f;
      B8(flag) = B8(flag) & 0xbf;
    }
  }
}
PCREG(43a380, lookupFlags);
