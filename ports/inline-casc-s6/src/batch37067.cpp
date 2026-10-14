// batch37067.cpp - cascade s6 batch 37067: 0x4010c0.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d52(void *p);    // free
extern "C" void __attribute__((cdecl)) ext_405670(u32 x);
extern "C" void __attribute__((cdecl)) ext_4024a0(u32 x);
typedef void (*rel_t)(u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// Releases the objects held by one entry of a typed table: slot 0x10 of the class registered at base + index * 4 is called with the item.
static void releaseAll(u8 *st, u32 countOff, u32 idxOff, u32 itemOff, u32 base) {
  for (s32 i = 0; i < (s32)D32(st, countOff); i++) {
    u8 *cls = *(u8 **)(base + D32(st, idxOff + 4 * i) * 4);
    (*(rel_t *)(cls + 0x10))(D32(st, itemOff + 4 * i));
  }
}

// 0x4010c0, cdecl(p): destroys the state record at p+0x1c (if any) and clears the first 8 dwords of p. The state holds counts at +8 (buffers to free), +0xc / +0x10 / +0x14 / +0x18
// (items released through virtual slot 0x10 of the classes registered in the tables at 0x6f1dd8 / 0x6f1dc0 / 0x6f1dc4 / 0x6f1dcc, class index at +0x124 + 0x200 * k, item at
// +0x224 + 0x200 * k), +0x1c (items freed with 0x405670 from +0x924) and +0x20 (items released with 0x4024a0 from +0xd24); the state itself is then freed.
static void fn4010c0(u8 *p) {
  u8 *st = *(u8 **)(p + 0x1c);
  if (st) {
    for (s32 i = 0; i < (s32)D32(st, 8); i++) {
      if (D32(st, 0x24 + 4 * i)) ext_634d52((void *)D32(st, 0x24 + 4 * i));
    }
    releaseAll(st, 0xc, 0x124, 0x224, 0x6f1dd8);
    releaseAll(st, 0x10, 0x324, 0x424, 0x6f1dc0);
    releaseAll(st, 0x14, 0x524, 0x624, 0x6f1dc4);
    releaseAll(st, 0x18, 0x724, 0x824, 0x6f1dcc);
    for (s32 i = 0; i < (s32)D32(st, 0x1c); i++) {
      if (D32(st, 0x924 + 4 * i)) ext_405670(D32(st, 0x924 + 4 * i));
    }
    for (s32 i = 0; i < (s32)D32(st, 0x20); i++) ext_4024a0(D32(st, 0xd24 + 4 * i));
    ext_634d52(st);
  }
  for (int i = 0; i < 8; i++) D32(p, 4 * i) = 0;
}
PCREG(4010c0, fn4010c0);
