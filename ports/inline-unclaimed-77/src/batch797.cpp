// batch797.cpp - unclaimed-77 claims 35 to 38 (docs/20-unclaimed-77.md), residue 4 rows. The tail-jump targets 0x43de70 and 0x651380 are
// stubbed (GUESS); virtual slots 0x240 and 0xc are stubbed in the harness.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);   // stubbed (GUESS): plain thiscall, logs ecx
extern "C" void THISCALL ext_651380(void *self);   // stubbed (GUESS): plain thiscall, logs ecx

// 0x44e700, GUESS FUN_44e700: stores the vtable 0x680abc at this, then tail-jumps to 0x43de70 (forwarded here as a plain call).
static void THISCALL guessFun44e700(u8 *self) {
  *(u32 *)self = 0x680abcu;
  ext_43de70(self);
}
PCREG(44e700, guessFun44e700);

// 0x658c80, GUESS FUN_658c80: zeroes the dwords at +0x114b and +0x114f, then tail-jumps to 0x651380.
static void THISCALL guessFun658c80(u8 *self) {
  *(u32 *)(self + 0x114b) = 0;
  *(u32 *)(self + 0x114f) = 0;
  ext_651380(self);
}
PCREG(658c80, guessFun658c80);

// 0x654a40, GUESS FUN_654a40: calls slot 0x240 of this; then sets the byte at g_pSysInterface+0x60 when the byte at +0x1a97 is zero.
static void THISCALL guessFun654a40(u8 *self) {
  void **vt = *(void ***)self;
  ((void (THISCALL *)(void *))(*(void **)((u8 *)vt + 0x240)))(self);
  u8 *si = G(u8 *, 0x70039c);
  if (si[0x1a97] == 0) {
    si[0x60] = 1;
  }
}
PCREG(654a40, guessFun654a40);

// 0x656fc0, ZPrimControlGC::GetNrBones(unsigned int) (medium): p = slot 0xc(id); returns the dword at p+0x7c.
static u32 THISCALL primControlGetNrBones(u8 *self, u32 id) {
  void **vt = *(void ***)self;
  u8 *p = ((u8 *(THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0xc)))(self, id);
  return *(u32 *)(p + 0x7c);
}
PCREG(656fc0, primControlGetNrBones);
