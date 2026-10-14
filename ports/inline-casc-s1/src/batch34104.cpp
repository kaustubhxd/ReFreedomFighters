// batch34104.cpp - escalation batch 34104: wrappers 0x5cd580, 0x65a380, 0x4d3810, 0x5589e0, 0x5cfee0, 0x485f30, 0x4d5730.
#include "ff.h"

extern "C" u32 THISCALL ext_5cd7f0(void *self, void *a, void *b, u32 f, u32 n);   // thiscall ret 0x10
extern "C" u32 THISCALL ext_659070(void *self);                                    // thiscall, plain ret
extern "C" u8 *THISCALL ext_4d2b40(void *self, u32 a, u32 b);                      // thiscall ret 8
extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);                               // thiscall ret 4
extern "C" u32 THISCALL ext_59e650(void *self, u32 a);                             // thiscall ret 4
extern "C" u32 THISCALL ext_4d5580(void *self);                                    // thiscall, plain ret
extern "C" void ext_634273(void *p, u32 n);                                        // cdecl free

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5cd580, thiscall plain: when byte [this+0xdd8] is set: it and byte [this+0xd35] are cleared and ext_5cd7f0(this, this+0xddd, this+0xde9, 0.1f (0x3dcccccd), 3) is called.
static void THISCALL fn5cd580(u8 *self) {
  if (self[0xdd8] == 0) return;
  self[0xdd8] = 0;
  self[0xd35] = 0;
  ext_5cd7f0(self, self + 0xddd, self + 0xde9, 0x3dcccccd, 3);
}
PCREG(5cd580, fn5cd580);

// 0x65a380, thiscall plain, returns this: ext_659070(this); [this] = 0x6c45ac.
static u32 THISCALL fn65a380(u8 *self) {
  ext_659070(self);
  *(u32 *)self = 0x6c45ac;
  return (u32)self;
}
PCREG(65a380, fn65a380);

// 0x4d3810, thiscall(a, b) ret 8, bool: p = ext_4d2b40(this, a, b); false when null, else byte [p+4] = 0 and true.
static bool THISCALL fn4d3810(u8 *self, u32 a, u32 b) {
  u8 *p = ext_4d2b40(self, a, b);
  if (!p) return false;
  p[4] = 0;
  return true;
}
PCREG(4d3810, fn4d3810);

// 0x5589e0, thiscall(a) ret 4: cell = ext_5003d0([a+4], 0); ext_59e650([this+0x1c], *cell); returns its eax.
static u32 THISCALL fn5589e0(u8 *self, u8 *a) {
  u32 *cell = ext_5003d0(*(u8 **)(a + 4), 0);
  return ext_59e650(*(u8 **)(self + 0x1c), *cell);
}
PCREG(5589e0, fn5589e0);

// 0x5cfee0, thiscall(a, v) ret 8, returns [this+0xc89+0x20]: v[0..2] = unaligned dwords [this+0xc71], [this+0xc75], [this+0xc79]; then the 0x24 bytes at this+0xc89 are copied to a.
static u32 THISCALL fn5cfee0(u8 *self, u8 *a, u32 *v) {
  v[0] = rd32(self + 0xc71);
  v[1] = rd32(self + 0xc75);
  v[2] = rd32(self + 0xc79);
  u8 *src = self + 0xc89;
  for (int i = 0; i < 0x24; i++) a[i] = src[i];
  return rd32(src + 0x20);
}
PCREG(5cfee0, fn5cfee0);

// 0x485f30, thiscall(flags) ret 4, returns this: [this] = 0x685294; frees the object (size 0x18) when bit 0 of flags is set.
static u32 THISCALL fn485f30(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x18);
  return (u32)self;
}
PCREG(485f30, fn485f30);

// 0x4d5730, thiscall(flags) ret 4, returns this: ext_4d5580(this); frees the object (size 0x6f) when bit 0 of flags is set.
static u32 THISCALL fn4d5730(u8 *self, u32 flags) {
  ext_4d5580(self);
  if (flags & 1) ext_634273(self, 0x6f);
  return (u32)self;
}
PCREG(4d5730, fn4d5730);
