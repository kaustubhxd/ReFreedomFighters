// batch34068.cpp - cascade tier E, batch 34068: 0x54cdf0 (flush two id lists into a record cursor), 0x551950 (forward a lookup and set four values), 0x553fa0 (rebind a slot object to a fresh one).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *m, u32 i);    // thiscall ret 4, returns the item object
extern "C" void THISCALL ext_5002f0(void *m, u32 v);   // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x54cdf0, thiscall, plain ret: this->slot0x30(); then for each of the [+0x8014] ids at +0x14 and the [+0x8018] ids at +0x4014 a 12-byte record {0x1001 / 0x1002, 0xc, id} is written at the
// unaligned cursor [+0x8021] (advanced by 0xc each); if byte 0x713e18 is set and 0x713e19 is clear: 0x713e19 = 1 and a record {0x1100, 8} is written (cursor += 8); both counts are cleared.
static void THISCALL fn54cdf0(u8 *self) {
  u32 i;
  vcall<void>(self, 0x30);
  for (i = 0; (s32)rd32(self + 0x8014) > (s32)i;) {
    u8 *cur = (u8 *)rd32(self + 0x8021);
    u32 id = rd32(self + 0x14 + 4 * i);
    i++;
    wr32(cur, 0x1001);
    wr32(cur + 4, 0xc);
    wr32(cur + 8, id);
    wr32(self + 0x8021, rd32(self + 0x8021) + 0xc);
    if (!((s32)i < (s32)rd32(self + 0x8014))) break;
  }
  for (i = 0; (s32)rd32(self + 0x8018) > (s32)i;) {
    u8 *cur = (u8 *)rd32(self + 0x8021);
    u32 id = rd32(self + 0x4014 + 4 * i);
    i++;
    wr32(cur, 0x1002);
    wr32(cur + 4, 0xc);
    wr32(cur + 8, id);
    wr32(self + 0x8021, rd32(self + 0x8021) + 0xc);
    if (!((s32)i < (s32)rd32(self + 0x8018))) break;
  }
  if (G(u8, 0x713e18) != 0 && G(u8, 0x713e19) == 0) {
    u8 *cur;
    G(u8, 0x713e19) = 1;
    cur = (u8 *)rd32(self + 0x8021);
    wr32(cur, 0x1100);
    wr32(cur + 4, 8);
    wr32(self + 0x8021, rd32(self + 0x8021) + 8);
  }
  wr32(self + 0x8014, 0);
  wr32(self + 0x8018, 0);
}
PCREG(54cdf0, fn54cdf0);

// 0x551950, stdcall(a, b, p) ret 0xc: r = a->slot0x18(b); if r is null return 0; m = r->slot0x4c(); for i in 0..3: ext_5002f0(ext_5003d0(m, i), p[i]); returns r.
static u32 STDCALL fn551950(u8 *a, u32 b, u32 *p) {
  u8 *r = vcall<u8 *>(a, 0x18, b);
  if (!r) return 0;
  u8 *m = vcall<u8 *>(r, 0x4c);
  ext_5002f0(ext_5003d0(m, 0), p[0]);
  ext_5002f0(ext_5003d0(m, 1), p[1]);
  ext_5002f0(ext_5003d0(m, 2), p[2]);
  ext_5002f0(ext_5003d0(m, 3), p[3]);
  return (u32)r;
}
PCREG(551950, fn551950);

// 0x553fa0, stdcall(a) ret 4: when the dword at +0x2c15 of [0x7003b8] is zero return that pointer. Otherwise e = [a+0xc]->slot0(0x67a14c, 0); e->slot0x30([0x7003b8]+0x2c15 value + 0x48);
// s = ext_5003d0([a+8], 0); if byte [s+4] is 4: [s]->slot0x28(); if it is 0 or 4: [s] = e->slot0x24(), byte [s+4] = 4; returns e->slot0x28().
static u32 STDCALL fn553fa0(u8 *a) {
  u8 *g = G(u8 *, 0x7003b8);
  if (rd32(g + 0x2c15) == 0) return (u32)g;
  u8 *e = vcall<u8 *>(*(u8 **)(a + 0xc), 0, 0x67a14cu, 0u);
  vcall<void>(e, 0x30, rd32(G(u8 *, 0x7003b8) + 0x2c15) + 0x48);
  u8 *s = ext_5003d0(*(u8 **)(a + 8), 0);
  u8 t = s[4];
  if (t == 0 || t == 4) {
    if (t == 4) vcall<void>(*(u8 **)s, 0x28);
    u32 v = vcall<u32>(e, 0x24);
    *(u32 *)s = v;
    s[4] = 4;
  }
  return vcall<u32>(e, 0x28);
}
PCREG(553fa0, fn553fa0);
