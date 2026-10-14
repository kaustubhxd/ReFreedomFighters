// u69_64.cpp - area 69, group 64 (slice 8). Maps a 32-bit value through a table at the global 0x70039c -> +0x190b (16-byte entries: start at +0, length at +0xc). No callees.
#include "ff.h"

// 0x432b80, MakeDeviceIndex(unsigned int) (GC map high). stdcall one arg (ret 4). A value with any bit in 0xffff0000 is returned as it is. Otherwise the
// table is scanned in order (until an entry with start <= v < start + length is found; the scan wraps at the end of the address space as in the original):
// the result is v + (index << 16) - start of that entry. If nothing matches, v is returned.
static u32 STDCALL makeDeviceIndex432b80(u32 v) {
  if (v & 0xffff0000u)
    return v;
  u8 *g = *(u8 **)0x70039c;
  u8 *edi = *(u8 **)(g + 0x190b);
  u32 ecx = 0;
  if (edi == 0)
    return v;
  u8 *edx = edi;
  do {
    u32 ebx = *(u32 *)edx;
    if (ebx <= v) {
      u32 e = *(u32 *)(edx + 0xc) + ebx;
      if (e > v)
        return v + (ecx << 16) - ebx;
    }
    ++ecx;
    edi += 0x10;
    edx = edi;
  } while (edx != 0);
  return v;
}
PCREG(432b80, makeDeviceIndex432b80);
