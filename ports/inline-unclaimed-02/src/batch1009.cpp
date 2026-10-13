#include "ff.h"
// batch1009.cpp - unclaimed-02 batch 9 (docs/20-unclaimed-02.md). Names from the GC name map (naming only).

// 36-byte block copy: the exe does this with the helper at 0x4de420 (two 16-byte moves and one dword). The byte copy
// here ends in the same memory state.
static inline void copy36(u8 *dst, const u8 *src) {
  for (int i = 0; i < 36; ++i)
    dst[i] = src[i];
}

// 0x4a54d0, ZMatPosAnim::CopyData(ZEventBase*) (high). Copies the fields of the source ZMatPosAnim (the argument) into
// this: a word at +0x5d, dwords at +0x5f, +0x63, +0x67, a 36-byte block at +0x6b, bytes at +0x8f..+0x92, a 36-byte block
// at +0x93, a dword at +0xb7 (skipped when both are the same address), dword +0xbb, byte +0xbf, dword +0xc0, bytes
// +0xc4..+0xc6, dword +0xc7, byte +0xcb, dword +0xcc, dword +0xd0. Callee pops 4 bytes.
static void THISCALL matPosAnimCopyData(u8 *self, u8 *src) {
  *(u16 *)(self + 0x5d) = *(u16 *)(src + 0x5d);
  *(u32 *)(self + 0x5f) = *(u32 *)(src + 0x5f);
  *(u32 *)(self + 0x63) = *(u32 *)(src + 0x63);
  *(u32 *)(self + 0x67) = *(u32 *)(src + 0x67);
  copy36(self + 0x6b, src + 0x6b);
  self[0x8f] = src[0x8f];
  self[0x90] = src[0x90];
  self[0x91] = src[0x91];
  self[0x92] = src[0x92];
  copy36(self + 0x93, src + 0x93);
  if (self + 0xb7 != src + 0xb7)
    *(u32 *)(self + 0xb7) = *(u32 *)(src + 0xb7);
  *(u32 *)(self + 0xbb) = *(u32 *)(src + 0xbb);
  self[0xbf] = src[0xbf];
  *(u32 *)(self + 0xc0) = *(u32 *)(src + 0xc0);
  self[0xc4] = src[0xc4];
  self[0xc5] = src[0xc5];
  self[0xc6] = src[0xc6];
  *(u32 *)(self + 0xc7) = *(u32 *)(src + 0xc7);
  self[0xcb] = src[0xcb];
  *(u32 *)(self + 0xcc) = *(u32 *)(src + 0xcc);
  *(u32 *)(self + 0xd0) = *(u32 *)(src + 0xd0);
}
PCREG(4a54d0, matPosAnimCopyData);
