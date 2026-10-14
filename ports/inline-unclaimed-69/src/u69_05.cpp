// u69_05.cpp - area 69, group 5 (unclaimed-69 thread).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *unusedEcx, void *p);     // ZRenderGC::Init: one stack argument (ret 4), ECX unused
extern "C" void *THISCALL ext_4e12e0(void *blk, void *p, u32 n);    // DBLK::Get (tail-jump; stub in spec: GUESS, two args)
extern "C" void THISCALL ext_4e1b30(void *blk);                     // DBLK::NextBlock (stub in spec: GUESS)

// 0x5d6210, CLensFlareControl::Command(cmd, value) (GC map high). thiscall, two stack args (ret 8). If cmd equals the word
// at +0x56, the dword value goes to +0x48; else if cmd equals the word at +0x58, it goes to +0x4c. Returns 0.
static u32 THISCALL lensFlareControlCommand(u8 *self, u32 cmd, u32 value) {
  if ((u16)cmd == *(u16 *)(self + 0x56)) {
    *(u32 *)(self + 0x48) = value;
    return 0;
  }
  if ((u16)cmd == *(u16 *)(self + 0x58))
    *(u32 *)(self + 0x4c) = value;
  return 0;
}
PCREG(5d6210, lensFlareControlCommand);

// 0x44d010, ZBoneParticle::CopyDataBlock(DBLK*) (GC map high). thiscall, one stack arg (ret 4): initialises the renderer
// hook (ZRenderGC::Init, original), gets a block (DBLK::Get with this+0x18 and 1), then advances the block (NextBlock).
static void THISCALL boneParticleCopyDataBlock(u8 *self, u8 *blk) {
  ext_610100(self, blk);
  ext_4e12e0(blk, (void *)(self + 0x18), 1u);
  ext_4e1b30(blk);
}
PCREG(44d010, boneParticleCopyDataBlock);

// 0x4ccd10, STRREFTAB::STRREFTAB(int, int) (GC map medium). thiscall, two stack args (ret 8). count = max(a, 1); +0x0c = count,
// +0x18 = b + 1, +0x10 = count * (b + 1), +0x04, +0x08, +0x14 = 0; the vtable 0x695aa0 is stored last. Returns this.
static u8 *THISCALL strRefTabCtor(u8 *self, s32 a, s32 b) {
  s32 count = (a >= 1) ? a : 1;
  u32 stride = (u32)b + 1u;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = stride;
  *(s32 *)(self + 0xc) = count;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x10) = (u32)count * stride;
  *(u32 *)(self + 8) = 0;
  *(u32 *)self = 0x695aa0u;
  return self;
}
PCREG(4ccd10, strRefTabCtor);
