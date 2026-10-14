// batch916.cpp - 0x4f7210 [thiscall (ECX = this), one stack arg (a stream object), ret 4, returns al]. Body read in full (2026-10-12).
// First 0x4fa230 (thiscall: this, stream; a serialization routine whose body is NOT read yet: stood in). If it is false, return 0.
// Otherwise: the stream's slot +0x40 reads a dword into the argument slot (a), the manager (g+0x9b) maps it through slot +0x58 into
// this+0x8f; slot +0x40 again reads a dword, mapped the same way into this+0x93; slot +0x40 reads a dword into this+0x97; slot +0x18
// reads 8 bytes into this+0x9b; slot +0x50 reads into this+0xa3; slot +0x68 reads into this+0xa7. Returns 1.
// The SEH and stack cookie frames are not reproduced (the exe's fs:[0] / cookie code is not in the port; tagged).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_4fa230(void *self, void *stream);   // serialization routine (stood in; body not read)

// 0x4f7210 (no name in the map).
static u8 THISCALL Read4f7210(u8 *self, u8 *stream) {
  if (!ext_4fa230(self, stream)) return 0;
  u32 a = (u32)stream;      // [ebp+8] is overwritten by the reads below
  vcall<void>(stream, 0x40, (void *)&a);
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  U32(self, 0x8f) = vcall<u32>(mgr, 0x58, a);
  vcall<void>(stream, 0x40, (void *)&a);
  U32(self, 0x93) = vcall<u32>(mgr, 0x58, a);
  vcall<void>(stream, 0x40, (void *)(self + 0x97));
  vcall<void>(stream, 0x18, (void *)(self + 0x9b), 8u);
  vcall<void>(stream, 0x50, (void *)(self + 0xa3));
  vcall<void>(stream, 0x68, (void *)(self + 0xa7));
  return 1;
}
PCREG(4f7210, Read4f7210);
