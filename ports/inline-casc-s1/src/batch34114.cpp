// batch34114.cpp - cascade tier E, batch 34114: 0x4d2a20 (copy the idx-th flagged record's string).
#include "ff.h"

extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);   // cdecl memcpy

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4d2a20, thiscall(dst, cap, idx) ret 0xc, bool: the buffer at [this+8] holds [this+0xc] bytes of records (dword length at +0, flag byte +4, unaligned string length +5, string from +0x11). The idx-th record
// with a non-zero flag is found; false when there is none. Its string length + 1 must not exceed cap (signed) or the assert hook runs; the string is copied to dst with a terminating zero; returns true.
static bool THISCALL fn4d2a20(u8 *self, u8 *dst, s32 cap, u32 idx) {
  u32 total = *(u32 *)(self + 0xc);
  u32 off = 0;
  if (total == 0) return false;
  u8 *buf = *(u8 **)(self + 8);
  u32 ecx = idx;
  u8 *rec;
  for (;;) {
    rec = buf + off;
    off += *(u32 *)rec;
    if (rec[4] != 0) {
      if (ecx == 0) break;
      ecx--;
    }
    if (!(off < total)) return false;
  }
  u32 len = rd32(rec + 5);
  if ((s32)(len + 1) > cap) {
    typedef void (*hf)(void);
    hf h = G(hf, 0x7003b0);
    if (!h) asm volatile("int3"); else h();
  }
  ext_634d22((u32)dst, (u32)(rec + 0x11), rd32(rec + 5));
  dst[rd32(rec + 5)] = 0;
  return true;
}
PCREG(4d2a20, fn4d2a20);
