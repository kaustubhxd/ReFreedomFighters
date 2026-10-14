// batch35034.cpp - cascade s5 batch 35034: 0x5a4dc0 (GUESS reset a record and re-resolve two handles through the engine table).
#include "ff.h"

typedef u32(THISCALL *g1_t)(void *, u32);

static inline void z32(u8 *p) { p[0] = p[1] = p[2] = p[3] = 0; }
static inline void z16(u8 *p) { p[0] = p[1] = 0; }
static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5a4dc0, thiscall, no arguments, all fields unaligned. Clears dwords +0x5a, +0x4c, +0x50, +0x54, words +0x58 and +0x109, bytes +0x61, +0x73, +0x85, +0x97 and the dwords
// +0x63..+0x6f, +0x75..+0x81, +0x87..+0x93, +0x99..+0xe5 (step 4); then [+0x11b] = table slot 0x58([+0x117]) and [+0x123] = table slot 0x58([+0x11f]) with table = [engine+0x9b].
static void THISCALL fn5a4dc0(u8 *self) {
  z32(self + 0x5a);
  z32(self + 0x4c);
  z32(self + 0x50);
  z32(self + 0x54);
  z16(self + 0x58);
  z16(self + 0x109);
  self[0x61] = 0;
  z32(self + 0x63);
  z32(self + 0x67);
  z32(self + 0x6b);
  z32(self + 0x6f);
  self[0x73] = 0;
  z32(self + 0x75);
  z32(self + 0x79);
  z32(self + 0x7d);
  z32(self + 0x81);
  self[0x85] = 0;
  z32(self + 0x87);
  z32(self + 0x8b);
  z32(self + 0x8f);
  z32(self + 0x93);
  self[0x97] = 0;
  z32(self + 0x99);
  z32(self + 0x9d);
  z32(self + 0xa1);
  z32(self + 0xa5);
  z32(self + 0xa9);
  z32(self + 0xad);
  z32(self + 0xb1);
  z32(self + 0xb5);
  z32(self + 0xb9);
  z32(self + 0xbd);
  z32(self + 0xc1);
  z32(self + 0xc5);
  z32(self + 0xc9);
  z32(self + 0xcd);
  z32(self + 0xd1);
  z32(self + 0xd5);
  z32(self + 0xd9);
  z32(self + 0xdd);
  z32(self + 0xe1);
  z32(self + 0xe5);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u32 a = (*(g1_t **)tab)[0x58 / 4](tab, rd32u(self + 0x117));
  u32 b0 = rd32u(self + 0x11f);
  wr32u(self + 0x11b, a);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 b = (*(g1_t **)tab)[0x58 / 4](tab, b0);
  wr32u(self + 0x123, b);
}
PCREG(5a4dc0, fn5a4dc0);
