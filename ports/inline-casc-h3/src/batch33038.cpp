// batch33038.cpp - h3 (Sonnet) cascade batch 33038: three scalar-deleting dtor shapes + one bool combiner
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);   // sized operator delete, caller pops
extern "C" void THISCALL ext_602240(u8 *self);                        // base dtor body, ret 0
extern "C" u32 THISCALL ext_466cd0(u8 *self);                         // returns byte [this]
extern "C" u32 THISCALL ext_467700(u8 *self);                         // float [this+0x35] < const

// 0x5df820: thiscall(flags) ret 4: set vtable, if (flags & 1) delete(this, 0x15), return this
static u8 *THISCALL fn5df820(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if (flags & 1) ext_634273(self, 0x15);
  return self;
}
PCREG(5df820, fn5df820);

// 0x655a80: same with vtable 0x6c3be4 and size 4
static u8 *THISCALL fn655a80(u8 *self, u32 flags) {
  *(u32 *)self = 0x6c3be4;
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(655a80, fn655a80);

// 0x5f1460: thiscall(flags) ret 4: call base dtor 0x602240, if (flags & 1) delete(this, 0x19), return this
static u8 *THISCALL fn5f1460(u8 *self, u32 flags) {
  ext_602240(self);
  if (flags & 1) ext_634273(self, 0x19);
  return self;
}
PCREG(5f1460, fn5f1460);

// 0x4746d0: thiscall bool: p = this+0x26a; return a(p) && !b(p)
static u32 THISCALL fn4746d0(u8 *self) {
  u8 *p = self + 0x26a;
  if (!(u8)ext_466cd0(p)) return 0;
  if ((u8)ext_467700(p)) return 0;
  return 1;
}
PCREG(4746d0, fn4746d0);
