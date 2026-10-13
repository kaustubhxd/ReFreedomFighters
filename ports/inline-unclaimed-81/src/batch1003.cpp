// batch1003.cpp - area 81 (residue 0), batch 1003: CRagdoll2::Setup(arg), 0x645000, thiscall, one stack argument, ret 4.
// SEH frame not reproduced; cookie check not reproduced. Helpers stood in: 0x644660 (thiscall, ecx=this, GUESS), 0x41e290 (cdecl, one
// argument 0x65, returns a pointer, GUESS), 0x540ed0 (thiscall, ecx=the returned pointer, GUESS).
// Zeroes dwords at this+0x3f+4i and this+0x7f+4i (i = 0..15). When arg: this+0x36 = arg; the render manager's slot 0xb4 (arg this+0x18 ... see
// below) gives this+0x32; q = arg's vslot 0x24c; this+0x2e = q's vslot 0x58(arg); this+0x26 = arg+0x20; this+0x2a = sys+0x40; 0x644660(this);
// when this+0x17f is zero: this+0x17f = 0x540ed0(0x41e290(0x65)) or 0 when that is null.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_644660(void *self);                 // GUESS (stood in)
extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 n);          // GUESS (stood in)
extern "C" u32 THISCALL ext_540ed0(void *p);                     // GUESS (stood in)

// 0x645000 CRagdoll2::Setup(arg).
static void THISCALL ragdollSetup(u8 *self, u32 arg) {
  for (u32 i = 0; i < 16; ++i) {
    D(self, 0x3f + 4 * i) = 0;
    D(self, 0x7f + 4 * i) = 0;
  }
  if (!arg)
    return;
  D(self, 0x36) = arg;
  u8 *t = (u8 *)D(arg, 8);
  u32 v = D(t, 0x6c);
  u8 *sys = *(u8 **)0x70039c;
  u8 *rm = (u8 *)D(sys, 0x1aa3);
  D(self, 0x32) = vcall<u32>((void *)D(rm, 0x18), 0xb4, v);
  u32 q = vcall<u32>((void *)arg, 0x24c);
  D(self, 0x2e) = vcall<u32>((void *)q, 0x58, arg);
  D(self, 0x26) = D(arg, 0x20);
  if (self + 0x2a != sys + 0x40)
    D(self, 0x2a) = D(sys, 0x40);
  ext_644660(self);
  if (D(self, 0x17f) == 0) {
    u32 r = ext_41e290(0x65);
    D(self, 0x17f) = r ? ext_540ed0((void *)r) : 0;
  }
}
PCREG(645000, ragdollSetup);
