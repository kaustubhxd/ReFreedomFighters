// batch992.cpp - residue-10 (core todo), batch 992: CWheel::InitEmitters(const ZGROUP*, ZSTDOBJ*), 0x529ae0, thiscall, ret 8.
// Emitter helpers 0x516b60 (this+0x3d and this+0xb6), 0x516f40 and 0x516fd0 (stood in). Three local vectors: a10 = (0, 20, 0) (after the
// s vslot 0x84(&a10) and g vslot 0x8c(&a10), a10[1] = 20 - [this+0x14]), a1c = (0, 1, 0), a28 = (0.6109, 0, 0.6109). The wheel's fields
// +0x6a, +0x6e, +0x72 and +0xe3, +0xe7, +0xeb take a10; +0x9a, +0x117 are 0 and 260.0, and constants are written at +0x76, +0x7a, +0x7e, +0x51.
#include "ff.h"

extern "C" void THISCALL ext_516b60(void *self, u32 a, u32 b, u32 c);   // stood in
extern "C" void THISCALL ext_516f40(void *self, u32 p);                  // stood in
extern "C" void THISCALL ext_516fd0(void *self, u32 p);                  // stood in

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x529ae0 CWheel::InitEmitters(const ZGROUP*, ZSTDOBJ*).
static void THISCALL initEmitters(u8 *t, u8 *g, u8 *s) {
  u32 a10[3] = {0, 0x41a00000u, 0};
  u32 a1c[3] = {0, 0x3f800000u, 0};
  u32 a28[3] = {0x3f1c61aau, 0, 0x3f1c61aau};
  ext_516b60(t + 0x3d, 0, 0x69f9b8u, (u32)s);
  D(t, 0x6a) = a10[0];
  D(t, 0x6e) = a10[1];
  D(t, 0x72) = a10[2];
  a1c[0] = 0;
  ext_516f40(t + 0x3d, (u32)a1c);
  D(t, 0x9a) = 0;
  D(t, 0x9e) = 0x437a0000u;
  ext_516fd0(t + 0x3d, (u32)a28);
  D(t, 0x76) = 0x420c0000u;
  D(t, 0x7a) = 0x41a00000u;
  D(t, 0x7e) = 0x420c0000u;
  D(t, 0x51) = 0x3ecccccdu;
  a1c[0] = 0;
  a1c[1] = 0x3f000000u;
  a1c[2] = 0xbf800000u;
  a28[0] = 0x3eb2b8c2u;
  a28[1] = 0x3e860a92u;
  a28[2] = 0;
  a10[0] = 0;
  a10[1] = 0x41a00000u;
  a10[2] = 0;
  vcall<void>(s, 0x84, (u32)a10);
  F(a10, 4) = F(a10, 4) - F(t, 0x14);
  vcall<void>(g, 0x8c, (u32)a10);
  ext_516b60(t + 0xb6, 0, 0x6a0be8u, (u32)g);
  D(t, 0xe3) = a10[0];
  D(t, 0xe7) = a10[1];
  D(t, 0xeb) = a10[2];
  ext_516f40(t + 0xb6, (u32)a1c);
  D(t, 0x117) = 0x437a0000u;
  ext_516fd0(t + 0xb6, (u32)a28);
}
PCREG(529ae0, initEmitters);
