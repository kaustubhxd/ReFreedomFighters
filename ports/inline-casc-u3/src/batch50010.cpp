// batch50010.cpp - cascade u3, tier H, batch 50010: 0x5ee970 (serialise an object's fields into a stream object).
#include "ff.h"

extern "C" void THISCALL ext_49b3a0(u8 *s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);   // ret 0x20

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5ee970, thiscall(s) ret 4 (all fields unaligned): [this+0x15] slot 0x10(s); ext_49b3a0(s, byte[+4], byte[+0x4d], byte[+0x6a], 0, 0, 0, 0, 0); then s slot 0x3c / 0x44 / 0x4c writes of the fields
// 0x3c: +0x11, +0x19; 0x4c(float): +0x41; 0x3c: +0x45, +0x49, +0x4e, +0x52, +0x56, +0x5a, +0x5e; 0x44: +0x62, +0x66; 0x3c: +0x6b, +0x73, +0x6f; 0x44: +0x78, +0x7c; 0x3c: +0x80;
// 0x3c: ([+9] - [+5]) >> 2 (signed); then for each pointer slot from [+5] to [+9]: e = *slot, [[[e]]] slot 0x10(s), s slot 0x3c([e+4]).
static void THISCALL fn5ee970(u8 *self, u8 *s) {
  vcall<void>((void *)rd32(self + 0x15), 0x10, (u32)s);
  ext_49b3a0(s, self[4], self[0x4d], self[0x6a], 0, 0, 0, 0, 0);
  vcall<void>(s, 0x3c, rd32(self + 0x11));
  vcall<void>(s, 0x3c, rd32(self + 0x19));
  vcall<void>(s, 0x4c, bitsf(rd32(self + 0x41)));
  vcall<void>(s, 0x3c, rd32(self + 0x45));
  vcall<void>(s, 0x3c, rd32(self + 0x49));
  vcall<void>(s, 0x3c, rd32(self + 0x4e));
  vcall<void>(s, 0x3c, rd32(self + 0x52));
  vcall<void>(s, 0x3c, rd32(self + 0x56));
  vcall<void>(s, 0x3c, rd32(self + 0x5a));
  vcall<void>(s, 0x3c, rd32(self + 0x5e));
  vcall<void>(s, 0x44, rd32(self + 0x62));
  vcall<void>(s, 0x44, rd32(self + 0x66));
  vcall<void>(s, 0x3c, rd32(self + 0x6b));
  vcall<void>(s, 0x3c, rd32(self + 0x73));
  vcall<void>(s, 0x3c, rd32(self + 0x6f));
  vcall<void>(s, 0x44, rd32(self + 0x78));
  vcall<void>(s, 0x44, rd32(self + 0x7c));
  vcall<void>(s, 0x3c, rd32(self + 0x80));
  vcall<void>(s, 0x3c, (u32)((s32)(rd32(self + 9) - rd32(self + 5)) >> 2));
  for (u32 p = rd32(self + 5); p != rd32(self + 9); p += 4) {
    u8 *e = *(u8 **)p;
    vcall<void>(*(void **)e, 0x10, (u32)s);
    e = *(u8 **)p;
    vcall<void>(s, 0x3c, *(u32 *)(e + 4));
  }
}
PCREG(5ee970, fn5ee970);
