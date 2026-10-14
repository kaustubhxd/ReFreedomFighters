// batch38045.cpp - cascade s8 batch 38045: 0x5cc020 (load a control's saved block from a stream).
#include "ff.h"

extern "C" u32 THISCALL ext_5c9f80(u8 *self, u8 *s);     // ret 4, bool in AL (the settings-block loader of batch 38023)
extern "C" void THISCALL ext_6625c0(u8 *self, u8 *s);    // ret 4
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define RD(slot, off) SLOT(s, slot, v1_t)(s, (u32)(self + (off)))

// 0x5cc020, thiscall(stream) ret 4, returns bool: false when the header loader 0x5c9f80 fails; otherwise reads the typed fields (slots 0x6c / 0x50 / 0x68 / 0x58 of the stream, destination pointer as the only
// argument), three 4-byte blobs through slot 0x18(dst, 4), runs the sub-loader 0x6625c0 on four embedded records (+0x4e4, +0x511, +0x53e, +0x56b) and reads two more bytes.
static bool THISCALL fn5cc020(u8 *self, u8 *s) {
  if (!(u8)ext_5c9f80(self, s)) return false;
  RD(0x6c, 0x451);
  RD(0x6c, 0x45d);
  RD(0x50, 0x469);
  RD(0x50, 0x46d);
  RD(0x50, 0x479);
  RD(0x50, 0x47d);
  RD(0x50, 0x481);
  RD(0x50, 0x485);
  RD(0x50, 0x489);
  RD(0x6c, 0x48d);
  RD(0x6c, 0x499);
  RD(0x50, 0x4a5);
  RD(0x68, 0x4a9);
  RD(0x50, 0x4aa);
  RD(0x50, 0x4ae);
  RD(0x50, 0x4b2);
  RD(0x58, 0x4b6);
  RD(0x50, 0x4ba);
  RD(0x50, 0x4be);
  RD(0x50, 0x4c2);
  RD(0x50, 0x4c6);
  RD(0x68, 0x4ca);
  RD(0x6c, 0x4cb);
  SLOT(s, 0x18, v2_t)(s, (u32)(self + 0x4d8), 4);
  SLOT(s, 0x18, v2_t)(s, (u32)(self + 0x4dc), 4);
  SLOT(s, 0x18, v2_t)(s, (u32)(self + 0x4e0), 4);
  ext_6625c0(self + 0x4e4, s);
  ext_6625c0(self + 0x511, s);
  ext_6625c0(self + 0x53e, s);
  ext_6625c0(self + 0x56b, s);
  RD(0x68, 0x598);
  RD(0x68, 0x599);
  return true;
}
PCREG(5cc020, fn5cc020);
