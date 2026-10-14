// u69_18.cpp - area 69, group 18 (unclaimed-69 thread).
#include "ff.h"

// 0x410250, cdecl with one stack arg (plain ret), no callees. The arg points at a pointer p; returns the little-endian dword at p+0x12 (bytes 0x12..0x15).
static u32 readU32At12(u8 **pp) {
  return *(u32 *)(*pp + 0x12);
}
PCREG(410250, readU32At12);
