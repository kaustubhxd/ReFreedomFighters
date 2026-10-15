// batch958.cpp - residue-03 (core todo), batch 958: CPlayerInventory::PutDataIntoBuffer(CBuffer&), 0x5b06b0, thiscall, ret 4.
// Returns (buffer[0xc] byte == 0): the final test reads the CBuffer argument (EBX), not this. The buffer (ECX of 0x5f01c0 with one pushed value) gets: 1 (and this[4] is set to 1), this[8],
// this[0x10], this[0xc], this[0x14]; then 0x5af1d0 (this+0x18, with 0xd, 0xc, 0xe, 0x10) and, after the loop, 0x5af1d0 with
// 0xf. The loop takes 3 and then the local array (four dwords of the constant at 0x6a7400, four of 0x6a7410, then 0) and,
// for each value, puts 0x5af230(this+0x2c, value) and 0x5aefc0(this+0x2c, value) into the buffer. Helpers are exe code,
// stood in by the checker.
#include "ff.h"

extern "C" u32 THISCALL ext_5f01c0(void *buf, u32 v);       // buffer put (exe, one arg)
extern "C" u32 THISCALL ext_5af1d0(void *p, u32 n);         // getter (exe, one arg)
extern "C" u32 THISCALL ext_5af230(void *p, u32 n);         // getter (exe, one arg)
extern "C" u32 THISCALL ext_5aefc0(void *p, u32 n);         // getter (exe, one arg)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5b06b0 CPlayerInventory::PutDataIntoBuffer(CBuffer&).
static u8 THISCALL invPutData(u8 *t, u8 *buf) {
  D(t, 4) = 1;
  ext_5f01c0(buf, 1);
  ext_5f01c0(buf, D(t, 8));
  ext_5f01c0(buf, D(t, 0x10));
  ext_5f01c0(buf, D(t, 0xc));
  ext_5f01c0(buf, D(t, 0x14));
  u8 *f = t + 0x18;
  ext_5f01c0(buf, ext_5af1d0(f, 0xd));
  ext_5f01c0(buf, ext_5af1d0(f, 0xc));
  ext_5f01c0(buf, ext_5af1d0(f, 0xe));
  ext_5f01c0(buf, ext_5af1d0(f, 0x10));
  u32 arr[9];
  for (int k = 0; k < 4; k++) {
    arr[k] = *(u32 *)(0x6a7400 + 4 * k);
    arr[4 + k] = *(u32 *)(0x6a7410 + 4 * k);
  }
  arr[8] = 0;
  u8 *a = t + 0x2c;
  u32 v = 3;
  u32 idx = 0;
  do {
    ext_5f01c0(buf, ext_5af230(a, v));
    ext_5f01c0(buf, ext_5aefc0(a, v));
    idx++;
    v = arr[idx];
  } while (v);
  ext_5f01c0(buf, ext_5af1d0(f, 0xf));
  return *(u8 *)(buf + 0xc) == 0;
}
PCREG(5b06b0, invPutData);
