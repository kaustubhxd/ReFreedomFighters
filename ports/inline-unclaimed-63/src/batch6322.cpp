// batch6322.cpp - unclaimed-63 batch 22 (docs/20-unclaimed-63.md): 0x5e0ee0 (GUESS constructor, vptr 0x6b7678; no GC name). SEH frame
// not reproduced. Body: call the base constructor 0x4876a0 (thiscall, two stack arguments a1, a2, callee pops 8); vptr = 0x6b7678;
// [this+0x1d] = 0; p = 0x41e290(0x1c) (cdecl, one argument, original); if p: r = 0x4ccbe0(ECX = p; 8, 0) (thiscall, two stack
// arguments, callee pops 8); [this+0x76] = r; else [this+0x76] = 0. Returns this (ret 8). 0x4876a0, 0x41e290 and 0x4ccbe0 are original code, stubbed.
#include "ff.h"

extern "C" void THISCALL ext_4876a0(void *self, u32 a1, u32 a2);   // base constructor, stubbed
extern "C" u32 ext_41e290(u32 size);                                // cdecl allocation, stubbed
extern "C" u32 THISCALL ext_4ccbe0(void *self, u32 a1, u32 a2);    // stubbed

// 0x5e0ee0 (GUESS constructor).
static u32 THISCALL unnamed5e0ee0(u8 *self, u32 a1, u32 a2) {
  ext_4876a0(self, a1, a2);
  *(u32 *)self = 0x6b7678u;
  self[0x1d] = 0;
  u32 p = ext_41e290(0x1c);
  if (p != 0) {
    u32 r = ext_4ccbe0((void *)p, 8u, 0u);
    *(u32 *)(self + 0x76) = r;
  } else {
    *(u32 *)(self + 0x76) = 0;
  }
  return (u32)self;
}
PCREG(5e0ee0, unnamed5e0ee0);
