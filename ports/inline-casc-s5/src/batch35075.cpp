// batch35075.cpp - cascade s5 batch 35075: 0x4a8020 (GUESS write a record's fields to a stream object).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4a8020, thiscall(s) ret 4, returns true. this[4] &= ~0x40; s slot 0x54 (1 arg) with the unaligned dwords at +0x72 and +0x76; s slot 0x60 (1 arg) with the bytes at +0x7b .. +0x80 in order.
static u8 THISCALL fn4a8020(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  (*(v1_t **)s)[0x54 / 4](s, rd32u(self + 0x72));
  (*(v1_t **)s)[0x54 / 4](s, rd32u(self + 0x76));
  for (int i = 0x7b; i <= 0x80; i++) (*(v1_t **)s)[0x60 / 4](s, self[i]);
  return 1;
}
PCREG(4a8020, fn4a8020);
