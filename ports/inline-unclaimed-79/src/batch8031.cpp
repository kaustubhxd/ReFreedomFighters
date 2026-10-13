#include "ff.h"
// batch8031.cpp - residue 18 unported list (docs/20-unclaimed-79.md). Names GUESS (no GC name). Helpers stubbed in spec.

extern "C" u32 THISCALL ext_562440(u8 *self);                    // helper, no args
extern "C" void THISCALL ext_563510(u8 *self, u32 a);            // helper, one arg (0x6a6850)
extern "C" u32 THISCALL ext_4e5f10(u8 *self);                    // helper, no args, returns eax
extern "C" void THISCALL ext_4e6420(u8 *self);                   // helper, no args
extern "C" void THISCALL ext_4d2700(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);   // five args (ret 0x14 path assumed)

// 0x64c7e0 (GUESS): thiscall (ret 4). Returns table[a & 0xfff], the table pointer being the dword at this+0x10071.
static u32 THISCALL f_64c7e0(u8 *self, u32 a) {
  u32 *t = *(u32 **)(self + 0x10071);
  return t[a & 0xfff];
}
PCREG(64c7e0, f_64c7e0);

// 0x52cea0 (GUESS): thiscall (ret 4). Stores a at this+0x44, zeroes the dword at this+0x49 and the byte at this+0x48; returns this.
static u8 *THISCALL f_52cea0(u8 *self, u32 a) {
  *(u32 *)(self + 0x44) = a;
  *(u32 *)(self + 0x49) = 0;
  *(u8 *)(self + 0x48) = 0;
  return self;
}
PCREG(52cea0, f_52cea0);

// 0x5625a0 (GUESS): thiscall, no args. Calls helper 0x562440 (no args), then 0x563510 with the constant 0x6a6850.
static void THISCALL f_5625a0(u8 *self) {
  ext_562440(self);
  ext_563510(self, 0x6a6850u);
}
PCREG(5625a0, f_5625a0);

// 0x4e5e60 (GUESS): thiscall, no args. esi = helper 0x4e5f10 (returns eax); calls helper 0x4e6420; returns esi.
static u32 THISCALL f_4e5e60(u8 *self) {
  u32 esi = ext_4e5f10(self);
  ext_4e6420(self);
  return esi;
}
PCREG(4e5e60, f_4e5e60);

// 0x6043a0 (GUESS): thiscall, no args. Calls slot +8 of the object at [[0x724278]+0x3c] with the word at this+0x24.
static void THISCALL f_6043a0(u8 *self) {
  u8 *g = G(u8 *, 0x724278);
  u8 *o = *(u8 **)(g + 0x3c);
  u32 w = *(u16 *)(self + 0x24);
  vcall<void, u32>(o, 0x8, w);
}
PCREG(6043a0, f_6043a0);

// 0x4d39e0 (GUESS): thiscall (ret 0x10), arguments a, b, c, d. Calls 0x4d2700 with (a, 2, d, b, c) (five stack arguments).
static void THISCALL f_4d39e0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  ext_4d2700(self, a, 2u, d, b, c);
}
PCREG(4d39e0, f_4d39e0);

// 0x4875e0 (GUESS): thiscall (ret 4), argument obj. If obj is null returns 1. Else returns the al of slot 0 of obj called with the dword at this+4.
static u8 THISCALL f_4875e0(u8 *self, u32 obj) {
  if (obj == 0) return 1;
  return (u8)vcall<u32, u32>((u8 *)(unsigned long)obj, 0x0, *(u32 *)(self + 0x4));
}
PCREG(4875e0, f_4875e0);
