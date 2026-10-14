// batch38041.cpp - cascade s8 batch 38041: 0x4b59f0 (load an entity's saved block from a stream).
#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);   // ret 4
extern "C" u8 *ext_41e290(u32 size);                       // allocator, cdecl
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // memcpy, cdecl
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0_t)(void *);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define RD(slot, off) SLOT(s, slot, v1_t)(s, (u32)(self + (off)))

// 0x4b59f0, thiscall(stream) ret 4, returns true: clears flag 0x40 of this[4], runs 0x6352f0 and slot 0x88 on a local, then reads the typed fields (slots 0x40 / 0x68 / 0x58 / 0x50 / 0x48 / 0x70 of the
// stream) into this+0x74.. +0x10e, plus a length-prefixed blob read as a pointer through slot 0x10 and copied twice into fresh buffers (this[0x90], this[0x94]); ends with the object at 0x700334 (slot 0xc)
// being handed to the stream's slot 0x80.
static bool THISCALL fn4b59f0(u8 *self, u8 *s) {
  u32 lc = 0, l4, l8;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &lc);
  SLOT(self, 0x88, v1_t)(self, (u32)&lc);
  RD(0x40, 0x74);
  RD(0x40, 0x78);
  RD(0x40, 0x7c);
  RD(0x40, 0x80);
  RD(0x40, 0x84);
  RD(0x40, 0x88);
  RD(0x40, 0x8c);
  RD(0x68, 0x9d);
  RD(0x68, 0x9e);
  RD(0x68, 0x9f);
  RD(0x68, 0xa0);
  RD(0x68, 0x98);
  RD(0x68, 0x99);
  RD(0x68, 0x9a);
  RD(0x68, 0x9b);
  RD(0x58, 0xda);
  RD(0x50, 0xde);
  RD(0x50, 0xe2);
  SLOT(s, 0x40, v1_t)(s, (u32)&l4);
  SLOT(s, 0x10, v2_t)(s, (u32)&l8, l4);
  *(u8 **)(self + 0x90) = ext_41e290(l4);
  *(u8 **)(self + 0x94) = ext_41e290(l4);
  ext_634d22(*(void **)(self + 0x90), (const void *)l8, l4);
  SLOT(s, 0x10, v2_t)(s, (u32)&l8, l4);
  ext_634d22(*(void **)(self + 0x94), (const void *)l8, l4);
  RD(0x48, 0xea);
  RD(0x48, 0xe6);
  RD(0x70, 0xf2);
  RD(0x70, 0x10e);
  u8 *o = G(u8 *, 0x700334);
  SLOT(o, 0xc, v0_t)(o);
  SLOT(s, 0x80, v1_t)(s, G(u32, 0x700334));
  return true;
}
PCREG(4b59f0, fn4b59f0);
