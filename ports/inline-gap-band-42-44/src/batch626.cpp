// batch626.cpp - band 0x421000-0x441000, batch 626: four thiscall functions returning al.
//   0x429a50 (no args): m = dword [this+0x71]; if m: slot 0x20 of m (ecx = m, arg m); then if m' = dword [this+0x71] (reloaded):
//     slot 8 of m' (ecx = m', arg m'); dword [this+0x71] = 0; return 1.
//   0x429a80: same with dword [this+0xd], and the release call is at [this+0xd].
//   0x428830 (no args): if dword [this+0xd] is 0 return 0. Else loop: o = [this+0xd]; the exe loads the vtable of o into ecx
//     and calls its slot 0x1c with ecx = that vtable and one argument o; repeat while the result is 0x8007001e or 0x8007000c;
//     then byte [this+0x1b1] = 1; return 1.
//   0x4288c0: same with [this+0xd] and byte [this+0x45].
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef u32(THISCALL *vNone)(void *self);

static u8 THISCALL releaseMember71(u8 *self) {
  u8 *m = *(u8 **)(self + 0x71);
  if (m)
    ((vOne)VT(m, 0x20))(m, (u32)m);
  m = *(u8 **)(self + 0x71);
  if (m)
    ((vOne)VT(m, 8))(m, (u32)m);
  *(u32 *)(self + 0x71) = 0;
  return 1;
}
PCREG(429a50, releaseMember71);

static u8 THISCALL releaseMemberD(u8 *self) {
  u8 *m = *(u8 **)(self + 0xd);
  if (m)
    ((vOne)VT(m, 0x20))(m, (u32)m);
  m = *(u8 **)(self + 0xd);
  if (m)
    ((vOne)VT(m, 8))(m, (u32)m);
  *(u32 *)(self + 0xd) = 0;
  return 1;
}
PCREG(429a80, releaseMemberD);

static u32 callSlot1cVtable(u8 *o) {
  void *vt = *(void **)o;
  return ((vOne)((void **)vt)[0x1c / 4])(vt, (u32)o);
}

static u8 THISCALL retryThenFlagB1(u8 *self) {
  if (*(u32 *)(self + 0xd) == 0)
    return 0;
  u32 r;
  do {
    r = callSlot1cVtable(*(u8 **)(self + 0xd));
  } while (r == 0x8007001eu || r == 0x8007000cu);
  self[0x1b1] = 1;
  return 1;
}
PCREG(428830, retryThenFlagB1);

static u8 THISCALL retryThenFlag45(u8 *self) {
  if (*(u32 *)(self + 0xd) == 0)
    return 0;
  u32 r;
  do {
    r = callSlot1cVtable(*(u8 **)(self + 0xd));
  } while (r == 0x8007001eu || r == 0x8007000cu);
  self[0x45] = 1;
  return 1;
}
PCREG(4288c0, retryThenFlag45);
