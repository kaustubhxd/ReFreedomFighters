// batch38023.cpp - cascade s8 batch 38023: 0x5c9f80 (load a settings block from a stream).
#include "ff.h"

extern "C" u32 THISCALL ext_4fb360(u8 *self, u8 *s);   // ret 4, bool in AL
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define RD(slot, off) SLOT(s, slot, v1_t)(s, (u32)(self + (off)))   /* typed stream read into this+off */

// 0x5c9f80, thiscall(stream) ret 4, returns bool: false when the header check 0x4fb360 fails; otherwise reads 29 fields by the stream's typed read slots
// (0x40 / 0x48 / 0x50 / 0x68 / 0x6c / 0x74, the destination pointer is the only argument) into this and returns true.
static bool THISCALL fn5c9f80(u8 *self, u8 *s) {
  if (!(u8)ext_4fb360(self, s)) return false;
  RD(0x48, 0x64);
  RD(0x48, 0x68);
  RD(0x50, 0x2f6);
  RD(0x50, 0x2fa);
  RD(0x6c, 0x2fe);
  RD(0x68, 0x30a);
  RD(0x68, 0x30b);
  RD(0x6c, 0x30c);
  RD(0x6c, 0x318);
  RD(0x6c, 0x324);
  RD(0x50, 0x330);
  RD(0x50, 0x334);
  RD(0x50, 0x338);
  RD(0x50, 0x33c);
  RD(0x50, 0x340);
  RD(0x74, 0x344);
  RD(0x40, 0x368);
  RD(0x74, 0x36c);
  RD(0x6c, 0x390);
  RD(0x6c, 0x39c);
  RD(0x6c, 0x3a8);
  RD(0x74, 0x3b4);
  RD(0x6c, 0x3d8);
  RD(0x74, 0x3e4);
  RD(0x6c, 0x408);
  RD(0x74, 0x414);
  RD(0x6c, 0x438);
  RD(0x6c, 0x444);
  RD(0x68, 0x450);
  return true;
}
PCREG(5c9f80, fn5c9f80);
