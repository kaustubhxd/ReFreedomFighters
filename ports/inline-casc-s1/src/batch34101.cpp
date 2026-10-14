// batch34101.cpp - escalation batch 34101: small wrappers 0x4752e0, 0x4ea2e0, 0x604d30, 0x4cdf50, 0x5adec0, 0x6493d0, 0x473e30.
#include "ff.h"

extern "C" u32 THISCALL ext_466220(void *self);                    // thiscall, plain ret
extern "C" u32 FASTCALL ext_4419f0(u32 a, u8 *e);                  // ecx = a, edx = e, plain ret
extern "C" u32 ext_634d10(u32 a, u32 b, u32 c);                    // cdecl import thunk
extern "C" u32 ext_634273(void *p, u32 n);                         // cdecl free
extern "C" u32 THISCALL ext_5b0e30(void *self, void *a, u32 b);    // thiscall ret 8
extern "C" u32 THISCALL ext_64ea30(void *self, u32 a);             // ret 4, ecx passed through
extern "C" u32 THISCALL ext_466cd0(void *self);                    // thiscall, plain ret (al = byte [this])

// 0x4752e0, thiscall plain: ext_466220(this+4); the unaligned dword [this+0x51] = 0; returns the callee's eax.
static u32 THISCALL fn4752e0(u8 *self) {
  u32 v = ext_466220(self + 4);
  self[0x51] = 0; self[0x52] = 0; self[0x53] = 0; self[0x54] = 0;
  return v;
}
PCREG(4752e0, fn4752e0);

// 0x4ea2e0, thiscall(a) ret 4: ext_4419f0 with ecx = a and edx = this+0x18; returns its eax.
static u32 THISCALL fn4ea2e0(u8 *self, u32 a) {
  return ext_4419f0(a, self + 0x18);
}
PCREG(4ea2e0, fn4ea2e0);

// 0x604d30, cdecl, no arguments: ext_634d10(0x724770, 0, 0xc8); dword [0x724768] = 0; returns the callee's eax.
static u32 fn604d30(void) {
  u32 v = ext_634d10(0x724770, 0, 0xc8);
  G(u32, 0x724768) = 0;
  return v;
}
PCREG(604d30, fn604d30);

// 0x4cdf50, stdcall(a) ret 4: ext_634273(a, 0x10); returns its eax.
static u32 STDCALL fn4cdf50(u8 *a) {
  return ext_634273(a, 0x10);
}
PCREG(4cdf50, fn4cdf50);

// 0x5adec0, thiscall(a) ret 4: ext_5b0e30 on the member at this+0x4b8 with (this, a); returns its eax.
static u32 THISCALL fn5adec0(u8 *self, u32 a) {
  return ext_5b0e30(self + 0x4b8, self, a);
}
PCREG(5adec0, fn5adec0);

// 0x6493d0, thiscall(a) ret 4: ext_64ea30 (ecx passed through) with [[a+0xc]+0xc]; returns its eax.
static u32 THISCALL fn6493d0(u8 *self, u8 *a) {
  u8 *p = *(u8 **)(a + 0xc);
  return ext_64ea30(self, *(u32 *)(p + 0xc));
}
PCREG(6493d0, fn6493d0);

// 0x473e30, thiscall plain: v = ext_466cd0(this+0x26a); when the low byte of v is set the unaligned dword [this+0x136] |= 0x400000; returns v.
static u32 THISCALL fn473e30(u8 *self) {
  u32 v = ext_466cd0(self + 0x26a);
  if ((u8)v) self[0x138] |= 0x40;
  return v;
}
PCREG(473e30, fn473e30);
