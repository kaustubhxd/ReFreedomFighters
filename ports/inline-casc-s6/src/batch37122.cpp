// batch37122.cpp - cascade s6 batch 37122: 0x4d19c0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 flag);   // release
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);           // allocate

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4d19c0, thiscall(flag) ret 4, returns the size field & 0x3fffffff: recomputes this object's size (+4) and header block (+0xc). Child objects chained through +0x24 / +0x30
// each contribute their slot-0x10 size (called with the flag argument) and set bit 31 and counted; the entries of the list at +0x18 (value +0x10, next +8) add up and are counted
// again. The total is rounded to 4. With the low flag byte set the second count is clamped to 1, without it a count above 1 sets bit 30. The old header (+0xc) is released and a new
// one of (count + 8) dwords is allocated: {+0x20 value, size, [size words and the count/list values when bits 30/31 are set]}; +8 receives the byte size of the whole header and +4 its size.
static u32 THISCALL fn4d19c0(u8 *self, u32 flag) {
  u32 cnt1 = 0, ebx = 0;
  u8 *child = *(u8 **)(self + 0x24);
  D32(self, 4) = 0;
  if (child) {
    do {
      u32 r = vcall<u32>(child, 0x10, flag);
      ebx++;
      D32(self, 4) = (r + D32(self, 4)) | 0x80000000u;
      child = *(u8 **)(child + 0x30);
    } while (child);
    cnt1 = ebx;
    ebx = 0;
  }
  u32 ecx = D32(self, 4);
  u32 edi = ecx & 0x3fffffffu;
  u8 *n = *(u8 **)(self + 0x18);
  if (n) {
    do {
      ecx += D32(n, 0x10);
      ebx++;
      D32(self, 4) = ecx;
      n = *(u8 **)(n + 8);
    } while (n);
  }
  u32 eax = (D32(self, 4) + 3) & 0xfffffffcu;
  D32(self, 4) = eax;
  if ((u8)flag) {
    if ((s32)ebx > 1) ebx = 1;
  } else if ((s32)ebx > 1) {
    D32(self, 4) = eax | 0x40000000u;
  }
  u8 *old = *(u8 **)(self + 0xc);
  if (old) ext_634273(old, 4);
  u64 b = (u64)(ebx + 8) * 4;
  u32 *hdr = (u32 *)ext_41e290((b >> 32) ? 0xffffffffu : (u32)b);
  D32(self, 0xc) = (u32)hdr;
  hdr[0] = D32(self, 0x20);
  u32 *p = hdr + 2;
  if (D32(self, 4) & 0xc0000000u) {
    p++;
    if ((s32)D32(self, 4) < 0) *p++ = cnt1;
    if (D32(self, 4) & 0x40000000u) {
      *p++ = ebx;
      for (u8 *m = *(u8 **)(self + 0x18); m; m = *(u8 **)(m + 8)) *p++ = D32(m, 0x10);
    }
    hdr[2] = edi + (u32)((s32)((u8 *)p - (u8 *)hdr) >> 2) * 4;
  }
  u32 bytes = ((u32)((u8 *)p - (u8 *)hdr)) & 0xfffffffcu;
  D32(self, 4) += bytes;
  D32(self, 8) = bytes;
  hdr[1] = D32(self, 4);
  return D32(self, 4) & 0x3fffffffu;
}
PCREG(4d19c0, fn4d19c0);
