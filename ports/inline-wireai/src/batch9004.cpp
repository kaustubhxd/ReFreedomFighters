// batch9004.cpp - wire-ai thread (2026-10-13): CRagdoll2::InitIndices 0x644660 (GC 8021f0fc, name medium), part of CRagdoll2::Init's tree.
#include "ff.h"

// 0x644660 CRagdoll2::InitIndices(), thiscall, plain ret: the link (this+0x36) slot 0x2b4(bone id) gives the bone index of each of the 23
// bones the ragdoll reads; stored at +0x183, +0x187, ... +0x1db in this order of ids: 2, 0xb, 0xc, 0x16, 0x17, 0xe, 0xf, 0x10, 0x11,
// 0x12, 0x13, 0x14, 0x15, 3, 4, 5, 6, 7, 8, 9, 0xa, 0x2b, 0x1c. The link pointer is re-read before every call.
static void THISCALL initIndices(u8 *self) {
  static const u32 ids[23] = {2, 0xb, 0xc, 0x16, 0x17, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 3, 4, 5, 6, 7, 8, 9, 0xa, 0x2b, 0x1c};
  for (int k = 0; k < 23; k++) {
    void *lk = *(void **)(self + 0x36);
    *(u32 *)(self + 0x183 + 4 * k) = vcall<u32>(lk, 0x2b4, ids[k]);
  }
}
PCREG(644660, initIndices);
