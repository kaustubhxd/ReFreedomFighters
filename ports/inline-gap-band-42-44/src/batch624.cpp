// batch624.cpp - band 0x421000-0x441000, batch 624: two thiscall functions returning al = 1.
//   0x429b10 (thiscall, no args): m = dword [this+0xd]; if m: call slot 0x20 of m with ecx = m and one argument m; then
//     byte [this+0x1b1] = 0; return 1.
//   0x429b30 (thiscall, no args): same, but byte [this+0x45] = 0.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);

static u8 THISCALL clearAfterSlot20b10(u8 *self) {
  u8 *m = *(u8 **)(self + 0xd);
  if (m)
    ((vOne)VT(m, 0x20))(m, (u32)m);
  *(u8 *)(self + 0x1b1) = 0;
  return 1;
}
PCREG(429b10, clearAfterSlot20b10);

static u8 THISCALL clearAfterSlot20b30(u8 *self) {
  u8 *m = *(u8 **)(self + 0xd);
  if (m)
    ((vOne)VT(m, 0x20))(m, (u32)m);
  *(u8 *)(self + 0x45) = 0;
  return 1;
}
PCREG(429b30, clearAfterSlot20b30);
