// batch38088.cpp - cascade s8 batch 38088: 0x4989a0 (serialize an object into a chunked stream: id list, header fields, two bit masks).
#include "ff.h"

extern "C" void THISCALL ext_498e60(u8 *self, u8 *st);       // ret 4
extern "C" void THISCALL ext_496380(u8 *self, u8 *mask);     // ret 4
extern "C" void THISCALL ext_498cc0(u8 *self, u32 *p);       // ret 4
extern "C" void THISCALL ext_498be0(u8 *self, u32 *p);       // ret 4
extern "C" void THISCALL ext_4991c0(u8 *self, u8 *st);       // ret 4
extern "C" u8 *ext_41e290(u32 n);                            // operator new
extern "C" void *ext_634d10(void *p, u32 v, u32 n);          // memset
extern "C" void ext_634273(void *p, u32 size);               // free
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void tag(u8 *st, u32 id) { SLOT(st, 8, v1_t)(st, id); }
static void put(u8 *st, const void *p, u32 n) { SLOT(st, 0x10, v2_t)(st, (u32)p, n); }
static void sys_tag(u32 id) { SLOT(SYS, 8, v1_t)(SYS, id); }
// the last byte of the mask keeps only the (count % 8) low bits when the count is not a multiple of 8
static void trim(u8 *m, u32 cnt, u32 n) {
  u32 r = (n / 112) & 7;
  if (r) m[cnt - 1] = (u8)((1u << r) - 1);
}

// 0x4989a0, thiscall(stream) ret 4, void.
static void THISCALL fn4989a0(u8 *self, u8 *st) {
  tag(st, 0xe);
  for (u32 i = 0; W(self, 0x4c) != 0 && i != W(self, 0x4c); i++) SLOT(st, 0xc, v1_t)(st, W(*(u8 **)(self + 0x44), 8 * i + 4));
  tag(st, 0xd);
  put(st, *(u8 **)(SYS + 0x9b) + 0x10, 4);
  ext_498e60(self, st);
  tag(st, 9);
  u32 l4 = 0xd, l8 = 0x2000;
  put(st, &l4, 4);
  put(st, &l8, 4);
  tag(st, 7);
  put(st, self + 0x20, 4);
  put(st, self + 0x28, 4);
  put(st, self + 0x24, 4);
  put(st, self + 0x50, 1);
  put(st, self + 0x61, 4);
  u32 n = W(*(u8 **)(self + 0x14), 0xc);
  put(st, &n, 4);
  tag(st, 8);
  u32 l12 = W(*(u8 **)(self + 0x18), 0xc);
  put(st, &l12, 4);
  u32 q = ((u64)n * 0x24924925ull >> 32);
  u32 cnt = ((((n - q) >> 1) + q) >> 6);
  cnt = (cnt + 7) >> 3;
  u32 stref = (u32)st;
  u8 *A = ext_41e290(cnt);
  u8 *B = ext_41e290(cnt);
  ext_634d10(A, 0xff, cnt);
  ext_634d10(B, 0, cnt);
  trim(A, cnt, n);
  ext_496380(self, A);
  sys_tag(4);
  ext_498cc0(self, &stref);
  sys_tag(5);
  ext_634d10(A, 0xff, cnt);
  trim(A, cnt, n);
  ext_498be0(self, &stref);
  sys_tag(6);
  ext_4991c0(self, st);
  sys_tag(7);
  ext_634273(A, 1);
  ext_634273(B, 1);
}
PCREG(4989a0, fn4989a0);
