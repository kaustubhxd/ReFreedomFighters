// batch1201.cpp - fresh slice 12 (floor(addr/16) mod 20 = 12), batch 1: the smallest free leaves, getters,
// small virtual-call wrappers and two scalar deleting destructors. Names are FUN_ in the exe list (no map entry).
#include "ff.h"

// 0x63eb40: thiscall leaf (max over a linked-list table), ret 0. Original code; the harness hooks and logs it.
extern "C" u32 THISCALL ext_63eb40(u8 *self);
// 0x4ce1c0: thiscall, two stack args (ret 8). Original code; hooked and logged.
extern "C" u32 THISCALL ext_4ce1c0(u8 *self, u32 a, u32 b);
// 0x54fb70 / 0x602240: base destructors (thiscall, ret 0). Original code; hooked and logged.
extern "C" void THISCALL ext_54fb70(u8 *self);
extern "C" void THISCALL ext_602240(u8 *self);
// 0x634273: sized operator delete, cdecl (pointer, size). Hooked and logged.
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x638c80: returns the dword at this+0x29.
static u32 THISCALL get29(u8 *self) { return *(u32 *)(self + 0x29); }
PCREG(638c80, get29);

// 0x615000: clears the byte at this+4.
static void THISCALL clear4(u8 *self) { self[4] = 0; }
PCREG(615000, clear4);

// 0x603d00: returns the constant 0x6b91c8 (an address in .rdata).
static u32 THISCALL ret6b91c8(u8 *) { return 0x6b91c8; }
PCREG(603d00, ret6b91c8);

// 0x614ec0: returns 0x8c.
static u32 THISCALL ret8c(u8 *) { return 0x8c; }
PCREG(614ec0, ret8c);

// 0x654700: returns the byte at this+0x11e7 (bool/byte getter, only AL is written).
static u8 THISCALL getb11e7(u8 *self) { return self[0x11e7]; }
PCREG(654700, getb11e7);

// 0x613340: true when the dword at this+0x22008 is non-zero.
static bool THISCALL has22008(u8 *self) { return *(u32 *)(self + 0x22008) != 0; }
PCREG(613340, has22008);

// 0x63b840: virtual slot 0x20 (no args) shifted left by 12.
static u32 THISCALL slot20shl12(u8 *self) { return vcall<u32>(self, 0x20) << 12; }
PCREG(63b840, slot20shl12);

// 0x656f00: p = slot 0xc(arg); returns the u16 at p+0xe divided by 3 (mul 0xaaaaaaab, shr edx 1).
static u32 THISCALL count16div3(u8 *self, u32 arg) {
  u8 *p = vcall<u8 *>(self, 0xc, arg);
  return (u32)*(u16 *)(p + 0xe) / 3;
}
PCREG(656f00, count16div3);

// 0x655380: calls slot 0xc8, then slot 0x90(arg); EAX is the second call's result.
static u32 THISCALL slotc8then90(u8 *self, u32 arg) {
  vcall<u32>(self, 0xc8);
  return vcall<u32>(self, 0x90, arg);
}
PCREG(655380, slotc8then90);

// 0x656780: v = slot 0xc(a); slot 0x150(b, v); returns true. ret 8.
static bool THISCALL slotc_then150(u8 *self, u32 a, u32 b) {
  u32 v = vcall<u32>(self, 0xc, a);
  vcall<u32>(self, 0x150, b, v);
  return true;
}
PCREG(656780, slotc_then150);

// 0x659ac0: q = p->+0x10; h = q->+0x14; if h: p->+0x18 = h->slot4(p, this). EAX: q when h is null, else the call's
// result (the original leaves them there; the callers ignore it). ret 4.
static u32 THISCALL dispatch18(u8 *self, u8 *p) {
  u8 *q = *(u8 **)(p + 0x10);
  u8 *h = *(u8 **)(q + 0x14);
  if (!h) return (u32)q;
  u32 r = vcall<u32>(h, 4, p, self);
  *(u32 *)(p + 0x18) = r;
  return r;
}
PCREG(659ac0, dispatch18);

// 0x63eb80: adjustor, tail-calls 0x63eb40 on the object at this+0x60.
static u32 THISCALL fwd60(u8 *self) { return ext_63eb40(*(u8 **)(self + 0x60)); }
PCREG(63eb80, fwd60);

// 0x659c00: if this+4 is set: 0x4ce1c0(this+8 -> +4)(this+4 value, this+0 value); this+4 = 0. EAX: 0 when this+4 was
// null, else the callee's result.
static u32 THISCALL release4(u8 *self) {
  u32 h = *(u32 *)(self + 4);
  if (!h) return 0;
  u32 r = ext_4ce1c0(*(u8 **)(self + 8) + 4, h, *(u32 *)self);
  *(u32 *)(self + 4) = 0;
  return r;
}
PCREG(659c00, release4);

// 0x54fd00: scalar deleting destructor: base dtor 0x54fb70, then sized delete (0x6d bytes) when bit 0 of flags is set.
static u8 *THISCALL sdd54fd00(u8 *self, u32 flags) {
  ext_54fb70(self);
  if (flags & 1) ext_634273(self, 0x6d);
  return self;
}
PCREG(54fd00, sdd54fd00);

// 0x5f14c0: scalar deleting destructor: base dtor 0x602240, sized delete 0x15 bytes when bit 0 is set.
static u8 *THISCALL sdd5f14c0(u8 *self, u32 flags) {
  ext_602240(self);
  if (flags & 1) ext_634273(self, 0x15);
  return self;
}
PCREG(5f14c0, sdd5f14c0);
