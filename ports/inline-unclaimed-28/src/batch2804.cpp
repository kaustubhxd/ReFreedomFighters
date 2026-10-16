#include "ff.h"
// batch2804.cpp - unclaimed-28 batch 4 (docs/20-unclaimed-28.md). Name from the GC name map (low; naming only).
// The CBuffer readers (0x5f0280 dword into a pointer, 0x5f02f0 byte into a pointer) and the error logger chain run as
// original code here; the harness stubs them with logging handlers.

extern "C" void THISCALL ext_5f0280(u8 *buf, u8 *dst); // read a dword into dst
extern "C" void THISCALL ext_5f02f0(u8 *buf, u8 *dst); // read a byte into dst

// 0x5b1870, ZSewerControl::TakeDataOutOfBuffer(CBuffer&) (low). Reads a dword into this+4. If it equals 1: 19 times, reads a
// byte into this+0xc (p-1), dwords into p, p+4, p+8, and a byte into p+0xc, with p starting at this+0xd and stepping by 0x12.
// Otherwise it logs through the global at 0x700390 (vtable slot +0x20 with two arguments returns an object; its vtable slot
// +0x2c is called cdecl with (object, 0x6b1188)). Both paths return true when buf+0xc is zero. Callee pops 4 bytes.
static u8 THISCALL sewerTakeDataOutOfBuffer(u8 *self, u8 *buf) {
  ext_5f0280(buf, self + 4);
  if (*(u32 *)(self + 4) == 1) {
    u8 *p = self + 0xd;
    for (int n = 0x13; n != 0; --n) {
      ext_5f02f0(buf, p - 1);
      ext_5f0280(buf, p);
      ext_5f0280(buf, p + 4);
      ext_5f0280(buf, p + 8);
      ext_5f02f0(buf, p + 0xc);
      p += 0x12;
    }
    return buf[0xc] == 0;
  }
  u8 *logger = G(u8 *, 0x700390);
  u8 *obj = vcall<u8 *, u32, u32>(logger, 0x20, 0x6b1524u, 0x79u);
  u8 *vt = *(u8 **)obj;
  ((void(__attribute__((cdecl)) *)(u32, u32)) * (u32 *)(vt + 0x2c))((u32)obj, 0x6b1188u);
  return buf[0xc] == 0;
}
PCREG(5b1870, sewerTakeDataOutOfBuffer);
