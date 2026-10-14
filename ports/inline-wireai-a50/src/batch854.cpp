// batch854.cpp - area 50 (residue-9 candidate): 0x4fc710 [179 instr, thiscall, no args; no name in the map (GUESS "Init
// from the settings object")]. The settings object (render manager +0x9b, vt +0x138) answers named floats (vt +0x84,
// written to locals), a three-dword block (vt +0x9c) and a dword (vt +0x88). The values go to this+0x152 (packed from the
// block), to the sub-object at this+0x44 (vt +0x214, +0x218, +0x21c, +0x220, +0x224, and its floats at +0x70 and +0x74),
// and to this+0x6e (a dword, only while it is zero). A local equal to zero is replaced by a constant (the exe's
// compare-with-zero idiom; NaN does not match). Then 0x4fd5d0 runs on this (a word table from the render manager, stood
// in by the harness), the words at +0x84, +0x48, +0x68 are cleared, a debug call on the engine's sub-object (vt +0x0c) is
// made when it exists, and this+0x5e gets a float from the engine's object (vt +0xbc, then its vt +0x58 with a name, 1.0).
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4fd5d0(void *self);        // word table from the render manager (stood in by the harness)

// the engine's global manager (the object at [[0x70039c]+0x9b])
static inline u8 *Settings() { return (u8 *)vcall<u8 *>(FP(G(u8 *, 0x70039c), 0x9b), 0x138); }

// 0x4fc710 (name GUESS).
static void THISCALL Init4fc710(u8 *self) {
  float v0c = 0.0f, v10 = 0.0f, v14 = 0.0f, v4 = 0.0f, v8 = 0.0f, v18 = 0.0f;
  vcall<void>(Settings(), 0x84, (u32)0x6922bc, &v0c);
  vcall<void>(Settings(), 0x84, (u32)0x6922c8, &v10);
  u8 *blk = vcall<u8 *>(Settings(), 0x9c, (u32)0x69c218, 4u);
  U32(self, 0x152) = 0;
  U32(self, 0x156) = 0;
  if (blk) {
    u32 packed = U32(blk, 0);
    packed = (packed << 8) + U32(blk, 4);
    packed = (packed << 8) + U32(blk, 8);
    U32(self, 0x152) = packed;
  }
  vcall<void>(Settings(), 0x84, (u32)0x69c208, &v14);
  vcall<void>(Settings(), 0x84, (u32)0x6954e8, &v4);
  v18 = v4;
  vcall<void>(Settings(), 0x84, (u32)0x6954f8, &v8);
  if (v4 == 0.0f) v18 = G(float, 0x68d448);
  if (v8 == 0.0f) v8 = G(float, 0x67c1ac);

  u8 *a = (u8 *)FP(self, 0x44);
  vcall<void>(a, 0x214, v0c);
  vcall<void>(a, 0x218, v10);
  vcall<void>(a, 0x21c, U32(self, 0x152));
  vcall<void>(a, 0x220, v14);
  vcall<void>(a, 0x224, bitsf(0x4286cccdu));
  F32(a, 0x70) = v18;
  F32(a, 0x74) = v8;

  bool have = U32(self, 0x6e) != 0;
  U32(self, 0x144) = 0;
  U32(self, 0x148) = 0;
  U32(self, 0x74) = 0;
  U8(self, 0x4c) = 0;
  if (!have) {
    u32 v18i = 0;
    vcall<void>(Settings(), 0x88, (u32)0x690418, &v18i);
    U32(self, 0x6e) = v18i;
  }
  ext_4fd5d0(self);
  U32(self, 0x84) = 0;
  U32(self, 0x48) = 0;
  U8(self, 0x68) = 0;

  u8 *eng = G(u8 *, 0x70039c);
  u8 *dbg = (u8 *)FP(eng, 0x1907);
  if (dbg) vcall<void>(dbg, 0x0c, (u32)0x6e8d9c, (u32)0x67d9e8, 0u);
  eng = G(u8 *, 0x70039c);
  u8 *y = vcall<u8 *>(eng, 0xbc);
  F32(self, 0x5e) = vcall<float>(y, 0x58, (u32)0x6922d4, 1.0f);
}
PCREG(4fc710, Init4fc710);
