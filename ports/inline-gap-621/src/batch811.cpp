// batch811.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634d22(u32 a, u32 b, u32 c);   // hooked callee (GUESS)
typedef u8 *(THISCALL *VCallRet)(u8 *, u32);   // vt[0xc]: thiscall one word, returns a pointer
typedef u32(THISCALL *VCallVal)(u8 *, u32);    // vt[0x50]: thiscall one word, returns a value

// 0x656930, stdcall(dst, src) ret 8: copies three dwords from src+0x10 to dst+0x10.
static void STDCALL copy3_656930(u8 *dst, const u8 *src) {
  *(u32 *)(dst + 0x10) = *(const u32 *)(src + 0x10);
  *(u32 *)(dst + 0x14) = *(const u32 *)(src + 0x14);
  *(u32 *)(dst + 0x18) = *(const u32 *)(src + 0x18);
}
PCREG(656930, copy3_656930);

// 0x657470, thiscall(arg) ret 4: two calls through vt[0xc]; the second takes the word at r+0x7c.
static void THISCALL twoCalls_657470(u8 *self, u32 arg) {
  VCallRet f = (VCallRet)(*(u32 *)(*(u32 *)self + 0xc));
  u8 *r = f(self, arg);
  VCallRet g = (VCallRet)(*(u32 *)(*(u32 *)self + 0xc));
  g(self, *(u32 *)(r + 0x7c));
}
PCREG(657470, twoCalls_657470);

// 0x650b70, thiscall(arg) ret 4: tail-calls vt[0x50] of the object at this+0xbd (null gives 0).
static u32 THISCALL tailVt50_650b70(u8 *self, u32 arg) {
  u8 *obj = *(u8 **)(self + 0xbd);
  if (obj == 0) return 0;
  VCallVal f = (VCallVal)(*(u32 *)(*(u32 *)obj + 0x50));
  return f(obj, arg);
}
PCREG(650b70, tailVt50_650b70);

// 0x4cf670, thiscall(a, b) ret 8: calls 0x634d22(this+4, a, b << 2).
static void THISCALL callWithShift_4cf670(u8 *self, u32 a, u32 b) {
  ext_634d22(*(u32 *)(self + 4), a, b << 2);
}
PCREG(4cf670, callWithShift_4cf670);
