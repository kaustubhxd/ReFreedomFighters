// batch975.cpp - residue-05 (core todo), batch 975: 0x5b0810 (GUESS FUN_5b0810), thiscall(buffer&), ret 4, returns buffer[+0xc] == 0.
// The read mirror of PutDataIntoBuffer (batch 958). Reads [this+4] from the buffer (0x5f0280, stood in); when it is not 1, logs
// through the debug channel (0x700390 vslot 0x20(0x6b1150, 0x8d), then cdecl vslot 0x2c(channel, 0x6b1188)). Otherwise: [this+8],
// [this+0xc] are read, [this+0x10] and [this+0x14] are read in place, four locals (L3..L6) go to the setter (0x5af2a0, this+0x18)
// at indexes 0xd, 0xc, 0xe, 0x10; then a loop over the eight-value array (0x6a7400 and 0x6a7410 dwords, then 0): each step reads a
// count and a value and, when the count is non-zero, calls 0x5aee20 (this+0x2c) with (array element, value); the last setter at
// index 0xf takes one more read.
#include "ff.h"

extern "C" void THISCALL ext_5f0280(void *buf, u32 *out);          // CBuffer::Get (stood in)
extern "C" void THISCALL ext_5af2a0(void *self, u32 idx, u32 v);   // setter (stood in)
extern "C" void THISCALL ext_5aee20(void *self, u32 a, u32 b);     // (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5b0810 (GUESS FUN_5b0810).
static u8 THISCALL invTakeData(u8 *t, u8 *buf) {
  ext_5f0280(buf, (u32 *)(t + 4));
  if (D(t, 4) != 1) {
    u8 *ch = (u8 *)vcall<u32>(*(void **)0x700390, 0x20, 0x6b1150u, 0x8du);
    u32 fn = *(u32 *)(*(u32 *)ch + 0x2c);
    ((u32(*)(void *, u32))fn)(ch, 0x6b1188u);
    return *(u8 *)(buf + 0xc) == 0;
  }
  u32 l1, l2, l3, l4, l5, l6, l8, l9;
  ext_5f0280(buf, &l1);
  D(t, 8) = l1;
  ext_5f0280(buf, (u32 *)(t + 0x10));
  ext_5f0280(buf, &l2);
  D(t, 0xc) = l2;
  ext_5f0280(buf, (u32 *)(t + 0x14));
  ext_5f0280(buf, &l3);
  ext_5f0280(buf, &l4);
  ext_5f0280(buf, &l5);
  ext_5f0280(buf, &l6);
  u8 *e = t + 0x18;
  ext_5af2a0(e, 0xd, l3);
  ext_5af2a0(e, 0xc, l4);
  ext_5af2a0(e, 0xe, l5);
  ext_5af2a0(e, 0x10, l6);
  u32 a[9];
  for (int k = 0; k < 4; k++) {
    a[k] = *(u32 *)(0x6a7400 + 4 * k);
    a[4 + k] = *(u32 *)(0x6a7410 + 4 * k);
  }
  a[8] = 0;
  int k = 0;
  do {
    u32 cnt;
    ext_5f0280(buf, &cnt);
    ext_5f0280(buf, &l8);
    if (cnt)
      ext_5aee20(t + 0x2c, a[k], l8);
    k++;
  } while (a[k]);
  ext_5f0280(buf, &l9);
  ext_5af2a0(e, 0xf, l9);
  return *(u8 *)(buf + 0xc) == 0;
}
PCREG(5b0810, invTakeData);
