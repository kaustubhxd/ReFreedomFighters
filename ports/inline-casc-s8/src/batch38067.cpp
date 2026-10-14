// batch38067.cpp - cascade s8 batch 38067: 0x61f0d0 (free everything a loaded model/table object owns through two allocator structs).
#include "ff.h"

typedef void (*free_t)(u32);
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))

// frees arr[0..cnt) (non-null entries) and then the array itself through the function pointer at fs[8]; the function pointer is re-read before every call
static void drop_array(u8 *a, u32 arr, u32 cnt, u32 fs) {
  for (u32 i = 0; i < W(a, cnt); i++) {
    u32 p = ((u32 *)W(a, arr))[i];
    if (p) ((free_t)W(W(a, fs), 8))(p);
  }
  u32 p = W(a, arr);
  if (p) ((free_t)W(W(a, fs), 8))(p);
}
static void drop_chain(u32 p, u8 *a) {
  while (p) {
    free_t f = (free_t)W(W(a, 0x64), 8);
    u32 next = *(u32 *)p;
    f(p);
    p = next;
  }
}

// 0x61f0d0, cdecl(a, b) (void). b+0x14 = free(ptr).
static void fn61f0d0(u8 *a, u8 *b) {
  u32 *e = (u32 *)W(a, 0x14);
  u32 *end = e + W(a, 0x18);
  while (e != end) {
    u8 *p = (u8 *)*e++;
    if (p && W(p, 0x10)) ((free_t)W(b, 0x14))(W(p, 0x14));
  }
  drop_array(a, 0, 4, 0x10);
  drop_array(a, 0x70, 0x74, 0x80);
  drop_array(a, 0x14, 0x18, 0x24);
  drop_array(a, 0x28, 0x2c, 0x38);
  drop_array(a, 0x3c, 0x40, 0x4c);
  drop_chain(W(a, 0x50), a);
  u32 second = W(a, 0x54);
  W(a, 0x50) = 0;
  drop_chain(second, a);
  W(a, 0x54) = 0;
  W(a, 0x5c) = 0;
  W(a, 0x60) = 0;
  W(a, 0x58) = 0;
  if (W(a, 0xa4)) ((free_t)W(b, 0x14))(W(a, 0xa4));
  if (W(a, 0x90)) ((free_t)W(b, 0x14))(W(a, 0x90));
}
PCREG(61f0d0, fn61f0d0);
