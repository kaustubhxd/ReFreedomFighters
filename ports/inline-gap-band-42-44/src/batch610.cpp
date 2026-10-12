// batch610.cpp - band 0x421000-0x441000, batch 610: eight small setters, a constructor and two list/flag helpers.
//   0x4333c0 (thiscall, byte arg): if (byte [this+0xfd] != al) { store; notify 0x431580(this, 0x67a018, arg) }
//   0x4333f0 (thiscall, byte arg): same with [this+0xfe] and name 0x67a024
//   0x4335a0 (thiscall, byte arg): same with [this+0xfc] and name 0x67a03c
//   0x433e90 (thiscall, byte arg): same with [this+0x106] and name 0x67a394
//   0x433e60 (thiscall, dword arg): if (dword [this+0x102] != arg) { store; notify 0x431410(this, 0x67a39c, arg) }
//   0x4359f0 (thiscall, one arg): constructor: [this+4] = arg, vtable 0x67a630, [this+8] = 0, byte [this+0xc] = 0; returns this
//   0x435d70 (thiscall, one arg): if (count [this+0x1c] < 3) { [this+0x10 + 4*count] = arg; count++ }
//   0x43e5d0 (thiscall, one arg): if (arg) dword [this+0x18] |= 1 else dword [this+0x18] &= ~1
// The notify helpers 0x431580 and 0x431410 are not ported (SEH frames, string temporaries): hooked by address in the spec.
// The byte setters compare and store only the low byte, but notify with the full dword argument (as the exe does).
#include "ff.h"

extern "C" void THISCALL ext_431580(void *self, u32 name, u32 value);  // notify helper (thiscall, ret 8)
extern "C" void THISCALL ext_431410(void *self, u32 name, u32 value);  // notify helper (thiscall, ret 8)

static inline void byteSet(u8 *self, u32 v, u32 off, u32 name) {
  if (*(u8 *)(self + off) == (u8)v)
    return;
  *(u8 *)(self + off) = (u8)v;
  ext_431580(self, name, v);
}

static void THISCALL setByteFd(u8 *self, u32 v) {
  byteSet(self, v, 0xfd, 0x67a018);
}
PCREG(4333c0, setByteFd);

static void THISCALL setByteFe(u8 *self, u32 v) {
  byteSet(self, v, 0xfe, 0x67a024);
}
PCREG(4333f0, setByteFe);

static void THISCALL setByteFc(u8 *self, u32 v) {
  byteSet(self, v, 0xfc, 0x67a03c);
}
PCREG(4335a0, setByteFc);

static void THISCALL setByte106(u8 *self, u32 v) {
  byteSet(self, v, 0x106, 0x67a394);
}
PCREG(433e90, setByte106);

static void THISCALL setDword102(u8 *self, u32 v) {
  if (*(u32 *)(self + 0x102) == v)
    return;
  *(u32 *)(self + 0x102) = v;
  ext_431410(self, 0x67a39c, v);
}
PCREG(433e60, setDword102);

static u8 *THISCALL initPair(u8 *self, u32 a) {
  *(u32 *)(self + 4) = a;
  *(u32 *)self = 0x67a630;
  *(u32 *)(self + 8) = 0;
  *(u8 *)(self + 0xc) = 0;
  return self;
}
PCREG(4359f0, initPair);

static void THISCALL pushSmall(u8 *self, u32 a) {
  u32 n = *(u32 *)(self + 0x1c);
  if (n < 3) {
    *(u32 *)(self + n * 4 + 0x10) = a;
    *(u32 *)(self + 0x1c) = n + 1;
  }
}
PCREG(435d70, pushSmall);

static void THISCALL setFlag18(u8 *self, u32 a) {
  if (a)
    *(u32 *)(self + 0x18) |= 1;
  else
    *(u32 *)(self + 0x18) &= 0xfffffffeu;
}
PCREG(43e5d0, setFlag18);
