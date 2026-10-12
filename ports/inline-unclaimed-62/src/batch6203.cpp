// batch6203.cpp - unclaimed-62 claim 2 (residue 03): ZKillBox::CopyEventDataBlock(DBREAD&) [map 0x5b1bf0; thiscall, ret 4]. The DBREAD u32
// operator (0x4e5e60, patched by the harness) gives: a flag (this+0x82 = value != 0), a flag (this+0x87 = value != 0), and a dword kept at
// this+0x88. The message table's slot 0x58 turns that dword into an object stored at this+0x83. The DBREAD u16 operator (0x4e5e40) gives
// the word at this+0x48. A third u32 goes to this+0x4e; if it is zero, the message table's slot 0x4c gives this+0x44 as the value kept at
// this+0x4e. Last, exe 0x4e5ef0 on the reader gives the byte at this+0x8c.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);   // DBREAD u32 operator (patched in the harness)
extern "C" u16 THISCALL ext_4e5e40(u8 *dbread);   // DBREAD u16 operator (patched in the harness)
extern "C" u8 THISCALL ext_4e5ef0(u8 *dbread);    // exe: byte read (patched in the harness)

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL killBoxCopyEventDataBlock(u8 *self, u8 *r) {
  self[0x82] = ext_4e5e60(r) != 0;
  self[0x87] = ext_4e5e60(r) != 0;
  u32 v = ext_4e5e60(r);
  wr32u(self + 0x88, v);
  u8 *msg = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 obj = vcall<u32>(msg, 0x58, v);
  wr32u(self + 0x83, obj);
  u16 w = ext_4e5e40(r);
  *(u16 *)(self + 0x48) = w;
  u32 x = ext_4e5e60(r);
  wr32u(self + 0x4e, x);
  if (x == 0) {
    u32 y = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, rd32u(self + 0x44));
    wr32u(self + 0x4e, y);
  }
  self[0x8c] = ext_4e5ef0(r);
}
PCREG(5b1bf0, killBoxCopyEventDataBlock);
