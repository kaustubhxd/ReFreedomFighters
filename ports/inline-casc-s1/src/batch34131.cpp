// batch34131.cpp - cascade tier E, batch 34131: 0x49b410 (unpack a flag byte), 0x4a1bf0 (write settings to a stream).
#include "ff.h"

// 0x49b410, thiscall(p0..p7) ret 0x20: reads one byte b through this->slot0x18(&b, 1), then stores bit i of b (0 or 1) at byte pointer pi, in order p0..p7.
static void THISCALL fn49b410(u8 *self, u8 *p0, u8 *p1, u8 *p2, u8 *p3, u8 *p4, u8 *p5, u8 *p6, u8 *p7) {
  u8 b;
  vcall<void>(self, 0x18, (u32)&b, 1u);
  *p0 = b & 1;
  *p1 = (b >> 1) & 1;
  *p2 = (b >> 2) & 1;
  *p3 = (b >> 3) & 1;
  *p4 = (b >> 4) & 1;
  *p5 = (b >> 5) & 1;
  *p6 = (b >> 6) & 1;
  *p7 = (b >> 7) & 1;
}
PCREG(49b410, fn49b410);

// 0x4a1bf0, thiscall(s) ret 4: clears bit 0x40 of [this+4]; s->slot0x40(word [this+0x8b0]); s->slot0x40(word [this+0x8b2]); s->slot0x44([this+0x48]);
// then for i < [this+0x48] (signed, re-read): s->slot0x3c([[this+0x5c+4i]]); finally s->slot0x3c([this+0x6c]). Returns 1.
static u32 THISCALL fn4a1bf0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(s, 0x40, (u32) * (u16 *)(self + 0x8b0));
  vcall<void>(s, 0x40, (u32) * (u16 *)(self + 0x8b2));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x48));
  for (int i = 0; i < *(int *)(self + 0x48); i++) vcall<void>(s, 0x3c, **(u32 **)(self + 0x5c + 4 * i));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x6c));
  return 1;
}
PCREG(4a1bf0, fn4a1bf0);
