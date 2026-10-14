// batch34120.cpp - cascade tier E, batch 34120: 0x56c4c0 (window message filter).
#include "ff.h"

extern "C" u32 THISCALL ext_563d20(void *self, u32 a, u8 *b, u32 c);   // thiscall ret 0xc
extern "C" u32 THISCALL ext_563d40(void *self, u32 a, u8 *b, u32 c);   // thiscall ret 0xc
extern "C" u32 THISCALL ext_56b460(void *self, u32 a);                 // thiscall ret 4
extern "C" u32 THISCALL ext_562d90(void *self, u32 a);                 // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x56c4c0, thiscall(msg) ret 4, bool: false when this->slot0xd8() returns a non-zero low byte. Else x = this->slot0x84()->slot0x2f0(); when x equals the unaligned [this+0xcae]: msg 0x102 calls ext_563d20(this, 0, this+0xce2, [this+0xce6]),
// msg 0x103 ext_563d40(...), and then ext_56b460(this, [this+0xce2]) runs for every msg. Returns ext_562d90(this, msg).
static u32 THISCALL fn56c4c0(u8 *self, u32 msg) {
  if ((u8)vcall<u32>(self, 0xd8)) return 0;
  u8 *o = vcall<u8 *>(self, 0x84);
  u32 x = vcall<u32>(o, 0x2f0);
  if (x == rd32(self + 0xcae)) {
    if (msg == 0x102) ext_563d20(self, 0, self + 0xce2, rd32(self + 0xce6));
    else if (msg == 0x103) ext_563d40(self, 0, self + 0xce2, rd32(self + 0xce6));
    ext_56b460(self, rd32(self + 0xce2));
  }
  return ext_562d90(self, msg);
}
PCREG(56c4c0, fn56c4c0);
