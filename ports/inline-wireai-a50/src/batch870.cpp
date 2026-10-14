// batch870.cpp - area 50 (residue-09 file row): 0x4fd890 CMAINCAMERACONTROL::Save(ZSaveGame*) [100 instr, thiscall, one stack arg
// (the stream), ret 4, returns true]. Clears bit 6 of this+4; then the stream's slots write the fields in this order: dword +0x48
// (0x3c), bytes +0x4c and +0x4d (0x60), a 16-byte block at +0x4e (0x10), a float +0x5e (0x4c), a byte +0x68 (0x60), dword +0x6a
// (0x44), dwords +0x6e and +0x78 (0x3c), words +0x7c, +0x7e, +0x80, +0x82 (0x40), the 12-byte vector at +0x98 (0x6c), and dwords
// +0x144 (0x3c), +0x148 (0x44), +0x14e (0x3c), +0x152 (0x44), +0x156 (0x3c).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x4fd890 CMAINCAMERACONTROL::Save.
static bool THISCALL SaveCamCtl_4fd890(u8 *self, u8 *s) {
  U32(self, 4) = U32(self, 4) & 0xffffffbfu;
  vcall<void>(s, 0x3c, U32(self, 0x48));
  vcall<void>(s, 0x60, (u32)U8(self, 0x4c));
  vcall<void>(s, 0x60, (u32)U8(self, 0x4d));
  vcall<void>(s, 0x10, (u32)(self + 0x4e), 0x10u);
  vcall<void>(s, 0x4c, F32(self, 0x5e));
  vcall<void>(s, 0x60, (u32)U8(self, 0x68));
  vcall<void>(s, 0x44, U32(self, 0x6a));
  vcall<void>(s, 0x3c, U32(self, 0x6e));
  vcall<void>(s, 0x3c, U32(self, 0x78));
  vcall<void>(s, 0x40, (u32)U16(self, 0x7c));
  vcall<void>(s, 0x40, (u32)U16(self, 0x7e));
  vcall<void>(s, 0x40, (u32)U16(self, 0x80));
  vcall<void>(s, 0x40, (u32)U16(self, 0x82));
  vcall<void>(s, 0x6c, (u32)(self + 0x98));
  vcall<void>(s, 0x3c, U32(self, 0x144));
  vcall<void>(s, 0x44, U32(self, 0x148));
  vcall<void>(s, 0x3c, U32(self, 0x14e));
  vcall<void>(s, 0x44, U32(self, 0x152));
  vcall<void>(s, 0x3c, U32(self, 0x156));
  return true;
}
PCREG(4fd890, SaveCamCtl_4fd890);
