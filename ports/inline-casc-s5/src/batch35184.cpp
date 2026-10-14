// batch35184.cpp - cascade s5 batch 35184 (tier H): 0x5184f0 (GUESS write a settings block out through a stream object).
#include "ff.h"

extern "C" u8 THISCALL ext_515b70(u8 *self, u8 *s);   // thiscall(s) ret 4, al
extern "C" void THISCALL ext_526090(u8 *self, u8 *s);  // thiscall(s) ret 4
typedef void(THISCALL *w1_t)(void *, u32);
typedef void(THISCALL *w2_t)(void *, void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5184f0, thiscall(s) ret 4, returns al: 0 when 0x515b70(this, s) is false, else 1 after writing the block through s: 0x526090(this+0x2d8, s); slot 0x68(this+0x15d3), (+0x15df), (+0x15eb);
// slot 0x4c(dword +0x15f7), (+0x15fb), (+0x15ff) (float arguments, passed as their raw bits); slot 0x10(this+0x1603, 4); slot 0x4c(+0x1607); slot 0x60(byte +0x160b); slot 0x10(this+0x160c, 4); slot 0x4c(+0x1610);
// slot 0x60(byte +0x1614); slot 0x3c(dwords +0x1615, +0x1619, +0x161d, +0x1621, +0x1625, +0x1629, +0x162d, +0x1631); slot 0x44(+0x1635), (+0x1639); slot 0x4c(+0x163d), (+0x1641); slot 0x44(+0x1645); slot 0x60(byte +0x1649).
static u8 THISCALL fn5184f0(u8 *self, u8 *s) {
  if (!ext_515b70(self, s)) return 0;
  u32 **vt = (u32 **)s;
  ext_526090(self + 0x2d8, s);
  ((w1_t)(*vt)[0x68 / 4])(s, (u32)(self + 0x15d3));
  ((w1_t)(*vt)[0x68 / 4])(s, (u32)(self + 0x15df));
  ((w1_t)(*vt)[0x68 / 4])(s, (u32)(self + 0x15eb));
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x15f7));
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x15fb));
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x15ff));
  ((w2_t)(*vt)[0x10 / 4])(s, self + 0x1603, 4);
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x1607));
  ((w1_t)(*vt)[0x60 / 4])(s, self[0x160b]);
  ((w2_t)(*vt)[0x10 / 4])(s, self + 0x160c, 4);
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x1610));
  ((w1_t)(*vt)[0x60 / 4])(s, self[0x1614]);
  for (u32 off = 0x1615; off <= 0x1631; off += 4) ((w1_t)(*vt)[0x3c / 4])(s, rd32u(self + off));
  ((w1_t)(*vt)[0x44 / 4])(s, rd32u(self + 0x1635));
  ((w1_t)(*vt)[0x44 / 4])(s, rd32u(self + 0x1639));
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x163d));
  ((w1_t)(*vt)[0x4c / 4])(s, rd32u(self + 0x1641));
  ((w1_t)(*vt)[0x44 / 4])(s, rd32u(self + 0x1645));
  ((w1_t)(*vt)[0x60 / 4])(s, self[0x1649]);
  return 1;
}
PCREG(5184f0, fn5184f0);
