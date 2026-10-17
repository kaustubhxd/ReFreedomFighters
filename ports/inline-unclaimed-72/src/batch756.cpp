// batch756.cpp - area 72, gap rows, pure stores (2026-10-12). See docs/20-unclaimed-72.md.
#include "ff.h"

static void THISCALL f_54ba20(u8 *self, u32 a) { *(u8 *)(self + 0xa273) = (u8)a; }
PCREG(54ba20, f_54ba20);

static void THISCALL f_549350(u8 *self) {
  *(u32 *)(self + 0x40b1) = 0x6a3298u;
  *(u32 *)self = 0x6a3234u;
}
PCREG(549350, f_549350);

static void THISCALL f_4cfd90(u8 *self, u32 a, u32 b) {
  (void)self;
  *(u32 *)((u8 *)a + 0x11) = *(u32 *)((u8 *)b + 0x11);
}
PCREG(4cfd90, f_4cfd90);

static void THISCALL f_4c3280(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 0x48) = a;
  *(u32 *)(self + 0x4c) = b;
}
PCREG(4c3280, f_4c3280);

static void THISCALL f_4d4940(u8 *self, u32 a, u32 b) {
  (void)b;
  if (a == 0x10)
    *(u8 *)(self + 5) = 0;
}
PCREG(4d4940, f_4d4940);
