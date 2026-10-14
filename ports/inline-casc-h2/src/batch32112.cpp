// batch32112.cpp - cascade h2 (): one tier H (float / SSE) function.
#include "ff.h"

extern "C" void THISCALL ext_5233a0(u8 *self, u32 *out, float a);   // thiscall ret 8
extern "C" void THISCALL ext_4e09b0(u32 *self);                     // thiscall, plain ret (operates on the buffer)
extern "C" void THISCALL ext_521600(u8 *self, u32 *p);              // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                    // /GS check

static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x520b10, thiscall(float a, byte flag) ret 8 (/GS frame): same as 0x520bb0 with [this+0x2f4] = 3 and an extra 0x4e09b0(&buf) between the 0x5233a0 fill and 0x521600:
// byte [this+0x2fc] = flag; [this+0x2f8] = a; [this+0x2f4] = 3; slot 0 of the object embedded at this+0x2695 with (0x3f060a92, 0x3e32b8c2, 0x40490fdb);
// 0x5233a0([this+0x5c], &buf, [this+0x2f8]); 0x4e09b0(&buf); 0x521600(this, &buf); [this+0x216] = 0 (unaligned); /GS check.
static void THISCALL fn520b10(u8 *self, float a, u32 flag) {
  u32 buf[4];
  self[0x2fc] = (u8)flag;
  *(float *)(self + 0x2f8) = a;
  *(u32 *)(self + 0x2f4) = 3;
  vcall<void>(self + 0x2695, 0, 0x3f060a92u, 0x3e32b8c2u, 0x40490fdbu);
  ext_5233a0(*(u8 **)(self + 0x5c), buf, *(float *)(self + 0x2f8));
  ext_4e09b0(buf);
  ext_521600(self, buf);
  wr32(self + 0x216, 0);
  ext_633654(0);
}
PCREG(520b10, fn520b10);
