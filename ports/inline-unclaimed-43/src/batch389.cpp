// batch389.cpp - 0x410a20 (gap band). cdecl(p, out, flag). p is a stream struct: [0] and [0xc] are dwords that the entry
// step combines, [0x10] points at dword entries A, [0x14] at 8-byte records B, [0x20] is the count, [0x24] the index,
// [0x158]/[0x15c] a 64-bit counter. An entry with bit 0x400 is a skip: it bumps the counter, sets the index to i+1
// and returns -1. Otherwise the length is the low byte of A[i], continued through A[i+1..] while the low byte is 0xff
// (bit 0x200 of any of them sets the 0x200 flag). If out is set it is filled; if flag is set the stream advances.
// Returns 0 when the index is at or past the count, 1 on success, -1 on a skip entry.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void bumpCounter(u8 *p) {
  u32 lo = U32(p, 0x158) + 1;
  U32(p, 0x158) = lo;
  if (lo == 0) U32(p, 0x15c) = U32(p, 0x15c) + 1;
}

static u32 pickEntry(u8 *p, u8 *out, u32 flag) {
  u32 idx = U32(p, 0x24);
  s32 n = (s32)U32(p, 0x20);
  if (!(n > (s32)idx)) return 0;
  u32 *A = *(u32 **)(p + 0x10);
  u32 e = A[idx];
  if (e & 0x400) {
    U32(p, 0x24) = idx + 1;
    bumpCounter(p);
    return 0xffffffffu;
  }
  if (out == 0 && flag == 0) return 1;
  u32 len = e & 0xff;
  u32 f200 = e & 0x200;
  u32 f100 = e & 0x100;
  u32 *ep = &A[idx];
  if (len == 0xff) {
    u32 low;
    do {
      u32 v = ep[1];
      ep++;
      idx++;
      low = v & 0xff;
      if (v & 0x200) f200 = 0x200;
      len += low;
    } while (low == 0xff);
  }
  if (out != 0) {
    u32 *B = *(u32 **)(p + 0x14);
    U32(out, 0xc) = f200;
    U32(out, 0x8) = f100;
    U32(out, 0x0) = U32(p, 0xc) + U32(p, 0x0);
    U32(out, 0x18) = U32(p, 0x158);
    U32(out, 0x1c) = U32(p, 0x15c);
    U32(out, 0x10) = B[2 * idx];
    U32(out, 0x4) = len;
    U32(out, 0x14) = B[2 * idx + 1];
  }
  if (flag != 0) {
    U32(p, 0xc) = U32(p, 0xc) + len;
    bumpCounter(p);
    U32(p, 0x24) = idx + 1;
  }
  return 1;
}
PCREG(410a20, pickEntry);
