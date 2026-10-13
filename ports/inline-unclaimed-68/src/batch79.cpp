// batch79.cpp - unclaimed-68 batch 79 (slice 7). Names GUESS (FUN_addr). Exe callees are hooked by address in the spec.
#include "ff.h"

extern "C" void THISCALL ext_54dfa0(u8 *self);                 // exe, thiscall, no args
extern "C" void THISCALL ext_469870(u8 *self);                 // exe base ctor, thiscall, no args
extern "C" void THISCALL ext_63a850(u8 *self);                 // exe base ctor, thiscall, no args
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 idx);         // exe element accessor, thiscall, ret 4
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 v);           // exe, thiscall, ret 4

typedef u32(THISCALL *VSlot0)(u8 *self);
// COM call with the interface pushed; the exe leaves ECX = the incoming value, so the pointer is typed thiscall on that value.
typedef void(THISCALL *ComSet)(u32 ecx_val, u8 *iface, u32 state, u32 value);
typedef u32(STDCALL *Ft2Lft)(const void *ft, void *lft);
typedef u32(STDCALL *Ft2St)(const void *ft, void *st);

// 0x54ab70: 0x54dfa0(this); tail call [[this+0x40b1]].slot+0x10 with ECX = this+0x40b1 (no args).
static u32 THISCALL g54ab70(u8 *self) {
  ext_54dfa0(self);
  u8 *sub = self + 0x40b1;
  return ((VSlot0)*(u32 *)(*(u8 **)sub + 0x10))(sub);
}
PCREG(54ab70, g54ab70);

// 0x61aaf0: cached render state: if ([0x724948] != v) { [0x724948] = v; dev = [0x724a00]; dev.slot+0xc8(dev, 0x89, v) }.
static void THISCALL g61aaf0(u32 v) {
  if (G(u32, 0x724948) == v) return;
  u8 *dev = G(u8 *, 0x724a00);
  G(u32, 0x724948) = v;
  ((ComSet)*(u32 *)(*(u8 **)dev + 0xc8))(v, dev, 0x89u, v);
}
PCREG(61aaf0, g61aaf0);

// 0x4ae4f0: ctor: base 0x469870; flags +4 |= 0x20; +0x44 = 0; vt = 0x690cc0; returns this.
static u8 *THISCALL g4ae4f0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20u;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x690cc0u;
  return self;
}
PCREG(4ae4f0, g4ae4f0);

// 0x559f30: r = [this+0x1c].slot+0x6a8(); e = 0x5003d0([arg+8], 0); return 0x5002f0(e, r). ret 4.
static u32 THISCALL g559f30(u8 *self, u8 *arg) {
  u8 *o = *(u8 **)(self + 0x1c);
  u32 r = ((VSlot0)*(u32 *)(*(u8 **)o + 0x6a8))(o);
  u8 *e = ext_5003d0(*(u8 **)(arg + 8), 0u);
  return ext_5002f0(e, r);
}
PCREG(559f30, g559f30);

// 0x426ff0: FILETIME ft passed by value (args 1-2); FileTimeToLocalFileTime(&ft, &l); return FileTimeToSystemTime(&l, st) != 0. ret 0xc.
static bool STDCALL g426ff0(u32 lo, u32 hi, void *st) {
  u32 ft[2] = {lo, hi};
  u32 l[2];
  G(Ft2Lft, 0x676104)(ft, l);
  return G(Ft2St, 0x6760bc)(l, st) != 0;
}
PCREG(426ff0, g426ff0);

// 0x659070: ctor: base 0x63a850; vt = 0x6c4410; +0xb9a4 = [[0x70039c]+0x190f]; returns this.
static u8 *THISCALL g659070(u8 *self) {
  ext_63a850(self);
  *(u32 *)self = 0x6c4410u;
  *(u32 *)(self + 0xb9a4) = *(u32 *)(G(u8 *, 0x70039c) + 0x190f);
  return self;
}
PCREG(659070, g659070);
