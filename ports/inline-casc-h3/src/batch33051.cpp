// batch33051.cpp - h3 (Sonnet) batch 33051: tiny tier C wrappers (the 0x5003d0 / 0x5002f0 pair, vcall chains)
#include "ff.h"

extern "C" u32 THISCALL ext_59ffc0(u8 *self);                       // returns [this+0x77f]
extern "C" u32 THISCALL ext_59dfd0(u8 *self);                       // bool in al
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);                // ret 4 (the second pushed dword stays for 0x5002f0)
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);                // ret 4
extern "C" void THISCALL ext_563110(u8 *self, u32 a, u32 b);        // ret 8
extern "C" void THISCALL ext_4711f0(u8 *self, u32 a, u32 b);        // ret 8

// 0x55ace0: thiscall(a) ret 4: x = 0x59ffc0([this+0x1c]); return 0x5002f0(0x5003d0([a+8], 0), x)
static u32 THISCALL fn55ace0(u8 *self, u8 *a) {
  u32 x = ext_59ffc0(*(u8 **)(self + 0x1c));
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0(r, x);
}
PCREG(55ace0, fn55ace0);

// 0x474410: thiscall: r = slot 0x10(); r2 = r->slot 0x2e8(); tail r2->slot 0x300(); null -> 0
static u32 THISCALL fn474410(u8 *self) {
  u8 *r = vcall<u8 *>(self, 0x10);
  if (!r) return 0;
  u8 *r2 = vcall<u8 *>(r, 0x2e8);
  if (!r2) return 0;
  return vcall<u32>(r2, 0x300);
}
PCREG(474410, fn474410);

// 0x519610: thiscall(a) ret 4: x = [this+0x14]->slot 0x358(); return 0x5002f0(0x5003d0([a+8], 0), x)
static u32 THISCALL fn519610(u8 *self, u8 *a) {
  u32 x = vcall<u32>(*(u8 **)(self + 0x14), 0x358);
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0(r, x);
}
PCREG(519610, fn519610);

// 0x5582e0: thiscall(a) ret 4: x = (u8)0x59dfd0([this+0x1c]); return 0x5002f0(0x5003d0([a+8], 0), x)
static u32 THISCALL fn5582e0(u8 *self, u8 *a) {
  u32 x = (u8)ext_59dfd0(*(u8 **)(self + 0x1c));
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0(r, x);
}
PCREG(5582e0, fn5582e0);

// 0x57c360: thiscall(a,b) ret 8 bool: 0x563110(a,b); slot 0xf8(); return 0
static u32 THISCALL fn57c360(u8 *self, u32 a, u32 b) {
  ext_563110(self, a, b);
  vcall<u32>(self, 0xf8);
  return 0;
}
PCREG(57c360, fn57c360);

// 0x656f40: thiscall(a) ret 4: r = slot 0xc(a); return slot 0xc([r+0x94])
static u32 THISCALL fn656f40(u8 *self, u32 a) {
  u8 *r = vcall<u8 *>(self, 0xc, a);
  return vcall<u32>(self, 0xc, *(u32 *)(r + 0x94));
}
PCREG(656f40, fn656f40);

// 0x656fa0: same with +0x84
static u32 THISCALL fn656fa0(u8 *self, u32 a) {
  u8 *r = vcall<u8 *>(self, 0xc, a);
  return vcall<u32>(self, 0xc, *(u32 *)(r + 0x84));
}
PCREG(656fa0, fn656fa0);

// 0x46b730: thiscall: if (slot 0x35c()) { slot 0x374(); 0x4711f0(6, 0) }
static void THISCALL fn46b730(u8 *self) {
  if (vcall<u32>(self, 0x35c)) {
    vcall<u32>(self, 0x374);
    ext_4711f0(self, 6, 0);
  }
}
PCREG(46b730, fn46b730);
