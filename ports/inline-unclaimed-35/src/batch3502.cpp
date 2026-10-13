#include "ff.h"
// batch3502.cpp - area 35 claim 2 (docs/20-unclaimed-35.md): CFFCoverList::Load(ZLoadGame*) (0x587fe0). Name from the GC name
// map (high). Thiscall, one argument, ret 4, returns true. Stubbed in the harness: 0x5887e0 (reserve, thiscall, one arg),
// 0x5885c0 (insert, thiscall, two args; the second is a stack address) and 0x5df1c0 (fill a record, thiscall, one arg).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

extern "C" void THISCALL ext_5887e0(u8 *self, u32 a1);
extern "C" void THISCALL ext_5885c0(u8 *self, u32 a0, u32 a1);
extern "C" void THISCALL ext_5df1c0(u8 *self, u32 a1);

// 0x587fe0, CFFCoverList::Load(ZLoadGame*) (high).
static u8 THISCALL coverListLoad(u8 *self, u32 zload) {
  u8 *z = (u8 *)zload;
  u8 *g = *(u8 **)0x7003b8;
  *(u32 *)(g + 0x2c1d) = (u32)self;
  u8 *rm = *(u8 **)0x70039c;
  u8 *sub = *(u8 **)(rm + 0x9b);
  *(u32 *)(g + 0x2c25) = ((Slot1)*(u32 *)(*(u32 *)sub + 0x4c))(sub, *(u32 *)(self + 0x44));
  *(u32 *)(self + 4) &= ~0x40u;
  u32 count = 0;
  ((Slot1)*(u32 *)(*(u32 *)z + 0x48))(z, (u32)&count);
  ext_5887e0(self + 0x5f, count);
  for (s32 i = 0; i < (s32)count; ++i) {
    u8 rec[0x48];
    for (u32 j = 0; j < 0x48; ++j)
      rec[j] = 0;
    ext_5df1c0(rec, zload);
    u32 end = *(u32 *)(self + 0x63);
    if (end == *(u32 *)(self + 0x67)) {
      ext_5885c0(self + 0x5f, end, (u32)rec);
    } else {
      if (end)
        for (u32 j = 0; j < 0x48; ++j)
          ((u8 *)end)[j] = rec[j];
      *(u32 *)(self + 0x63) = end + 0x48;
    }
  }
  u32 val = 0;
  ((Slot1)*(u32 *)(*(u32 *)z + 0x40))(z, (u32)&val);
  rm = *(u8 **)0x70039c;
  sub = *(u8 **)(rm + 0x9b);
  *(u32 *)(self + 0x6f) = ((Slot1)*(u32 *)(*(u32 *)sub + 0x58))(sub, val);
  return 1;
}
PCREG(587fe0, coverListLoad);
