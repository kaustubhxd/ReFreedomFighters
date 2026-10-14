// batch988.cpp - area 56 claim A55 (0x5a0290, InitHitAnims, area 09 hit-reaction leaf).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5330(u8 *name);                 // GUESS hook in the spec (helper, one register argument)
extern "C" void STDCALL ext_5a3550(u32 end, u32 *L);          // GUESS hook in the spec (growth path, two stack arguments)

static u32 vcall0(u8 *self, u32 slot) {
  return ((u32(THISCALL *)(u8 *))(*(u32 *)(*(u8 **)self + slot)))(self);
}
static u32 vcall1(u8 *self, u32 slot, u32 a) {
  return ((u32(THISCALL *)(u8 *, u32))(*(u32 *)(*(u8 **)self + slot)))(self, a);
}
static u32 importCall(u32 a, u32 b) {
  return ((u32(*)(u32, u32))G(u32, 0x676414))(a, b);   // cdecl import; the spec writes its slot to a GUESS stub
}
static u32 nameOf(u8 *self, u32 slot) {
  u32 p = vcall0(self, slot);
  return p ? ext_4e5330((u8 *)p) : 0x677b5a;
}

// A55 0x5a0290: see docs/20-unclaimed-56.md, claim A55.
static void THISCALL initHitAnims5a0290(u8 *self) {
  u8 *cfg = (u8 *)G(u32, 0x7003b8) + 0xb55;
  u32 size = *(u32 *)(cfg + 4) - *(u32 *)cfg;
  if (size >= 0x40) {
    u32 i = 0;
    u32 cnt = 0;
    do {
      u32 begin = *(u32 *)(G(u32, 0x7003b8) + 0xb55);
      u32 entry = begin + i * 0x40;
      u32 n1 = nameOf(self, 0x2c0);
      if (importCall(n1, *(u32 *)entry) == 0) {
        u32 n2 = nameOf(self, 0x2c4);
        if (importCall(n2, *(u32 *)(entry + 4)) == 0) {
          *(u32 *)(self + 0x932) = i;
          return;
        }
      }
      i++;
      cnt = (u32)((s32)(*(u32 *)(G(u32, 0x7003b8) + 0xb59) - *(u32 *)(G(u32, 0x7003b8) + 0xb55)) >> 6);
    } while (i != cnt);
  }
  u32 L[16];
  L[0] = nameOf(self, 0x2c0);
  L[1] = nameOf(self, 0x2c4);
  static const u32 consts[14] = {0x6aee40, 0x6aee58, 0x6aee70, 0x6aee8c, 0x6aeea4, 0x6aeeb8, 0x6aeecc,
                                 0x6aeee0, 0x6aeef4, 0x6aef04, 0x6aeef4, 0x6aef04, 0x6aeef4, 0x6aef04};
  for (int k = 0; k < 14; k++) L[2 + k] = vcall1(self, 0x21c, consts[k]);
  u8 *base = (u8 *)G(u32, 0x7003b8);
  u32 endp = *(u32 *)(base + 0xb59);
  u32 cap = *(u32 *)(base + 0xb5d);
  if (endp == cap) {
    ext_5a3550(endp, L);
  } else {
    if (endp != 0) {
      u8 *dst = (u8 *)endp;
      for (int k = 0; k < 16; k++) ((u32 *)dst)[k] = L[k];
    }
    *(u32 *)(base + 0xb59) = endp + 0x40;
  }
  base = (u8 *)G(u32, 0x7003b8);
  *(u32 *)(self + 0x932) = (u32)((s32)(*(u32 *)(base + 0xb59) - *(u32 *)(base + 0xb55)) >> 6) - 1;
}
PCREG(5a0290, initHitAnims5a0290);
