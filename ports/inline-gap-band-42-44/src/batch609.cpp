// batch609.cpp - band 0x421000-0x441000, batch 609: nine short accessors and one constructor.
//   0x424450 (thiscall, void): byte [this+0x25e8] = 1
//   0x428ab0 (cdecl, void): dword [0x7003a0] = 0
//   0x428fb0 (thiscall, returns this+0x11)
//   0x428fc0 (thiscall, returns this+0x35)
//   0x429450 (thiscall, returns byte [this+0xc] in al)
//   0x4298a0 (thiscall, one byte argument): byte [this+0xc] = arg
//   0x423ee0 (thiscall, one dword argument): dword [this+0x1b37] = arg
//   0x42acc0 (thiscall, constructor: vtable 0x679754, +8 = 0x4d2, +0xc = 0, byte +0x11 = 0; returns this)
//   0x424d70 (cdecl, one argument): calls vslot 0x154 of [0x70039c] with the argument, returns 0
// Thunks that jump on with the caller's stack (0x4234e0, 0x423f90, 0x427140, 0x429ad0) are not in this batch.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);                         // one argument

static void THISCALL setFlag25e8(u8 *self) {
  *(u8 *)(self + 0x25e8) = 1;
}
PCREG(424450, setFlag25e8);

static void clearGlobal7003a0(void) {
  G(u32, 0x7003a0) = 0;
}
PCREG(428ab0, clearGlobal7003a0);

static u8 *THISCALL addrPlus11(u8 *self) {
  return self + 0x11;
}
PCREG(428fb0, addrPlus11);

static u8 *THISCALL addrPlus35(u8 *self) {
  return self + 0x35;
}
PCREG(428fc0, addrPlus35);

static u8 THISCALL getByteC(u8 *self) {
  return *(u8 *)(self + 0xc);
}
PCREG(429450, getByteC);

static void THISCALL setByteC(u8 *self, u8 v) {
  *(u8 *)(self + 0xc) = v;
}
PCREG(4298a0, setByteC);

static void THISCALL setDword1b37(u8 *self, u32 v) {
  *(u32 *)(self + 0x1b37) = v;
}
PCREG(423ee0, setDword1b37);

static u8 *THISCALL initAction(u8 *self) {
  *(u32 *)self = 0x679754;
  *(u32 *)(self + 8) = 0x4d2;
  *(u32 *)(self + 0xc) = 0;
  *(u8 *)(self + 0x11) = 0;
  return self;
}
PCREG(42acc0, initAction);

static u32 callSlot154(u32 a) {
  u8 *sys = G(u8 *, 0x70039c);
  ((vOne)VT(sys, 0x154))(sys, a);
  return 0;
}
PCREG(424d70, callSlot154);
