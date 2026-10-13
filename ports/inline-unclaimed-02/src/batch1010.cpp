#include "ff.h"
// batch1010.cpp - unclaimed-02 batch 10 (docs/20-unclaimed-02.md). Names from the GC name map (medium; naming only).
// The three CBuffer writers (0x5f01c0, 0x5f0190, 0x5f0220) run as original code here; the harness stubs them with logging.

extern "C" void THISCALL ext_5f01c0(u8 *buf, u32 v);   // a dword write (argument 1)
extern "C" void THISCALL ext_5f0190(u8 *buf, u32 v);   // a byte write (zero-extended)
extern "C" void THISCALL ext_5f0220(u8 *buf, float v); // a float write

// 0x5b16d0, ZSewerControl::PutDataIntoBuffer(CBuffer&) (medium). Sets the dword at this+4 to 1 and writes it to the buffer
// (ext_5f01c0). Then 18 times: a byte from this+(p-1) [p starts at this+0xd, steps by 0x12], three floats at p, p+4, p+8,
// and the byte at p+0xc. Returns true when the buffer's byte at +0xc is zero. Callee pops 4 bytes.
static u8 THISCALL sewerPutDataIntoBuffer(u8 *self, u8 *buf) {
  *(u32 *)(self + 4) = 1;
  ext_5f01c0(buf, 1u);
  u8 *p = self + 0xd;
  for (int n = 0x12; n != 0; --n) {
    ext_5f0190(buf, (u32)p[-1]);
    ext_5f0220(buf, *(float *)p);
    ext_5f0220(buf, *(float *)(p + 4));
    ext_5f0220(buf, *(float *)(p + 8));
    ext_5f0190(buf, (u32)p[0xc]);
    p += 0x12;
  }
  return buf[0xc] == 0;
}
PCREG(5b16d0, sewerPutDataIntoBuffer);
