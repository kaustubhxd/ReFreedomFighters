// batch1125.cpp - collision thread, batch 1125: ZOctreeCompiled::CheckCube (0x4e3520), octree slot 0x1c.
#include "ff.h"

extern "C" void THISCALL ext_4e3380(u8 *node, u8 *info, s32 depth, s32 cx, s32 cy, s32 cz);   // OctreeCubeWalk (1124)

// 0x4e3520 ZOctreeCompiled::CheckCube(SRecurseInfoCompiled *info, const float *a, const float *b) [medium],
// thiscall (ECX = octree), ret 0xc. The octree: +4/+8/+0xc origin x/y/z, +0x10 quantisation scale, +0x14 compiled block.
// The block: dword 0 = offset of the item array; the child/node records start at block+0x14.
// 1. Quantises the box a..b: q = trunc((p - origin) * scale + 32768). Min = q(a), max = q(b) + 1, per axis.
// 2. Stores them in info: +0x14/+0x18/+0x1c min x/y/z, +0x20/+0x24/+0x28 max x/y/z.
// 3. info+0xc = block+0x14 (record base), info+0x10 = block + [block] (item base).
// 4. Calls the walk on the root record (info+0xc) with depth 0 and centre (0x8000, 0x8000, 0x8000).
// The return value is whatever the walk left in eax; no caller reads it (GetStripsInsideBox ignores it).
static void THISCALL octreeCheckCube(u8 *oct, u8 *info, const float *a, const float *b) {
  const float *org = (const float *)(oct + 4);
  float sc = *(const float *)(oct + 0x10);
  s32 qa[3], qb[3];
  for (int k = 0; k < 3; k++) {
    float fa = (a[k] - org[k]) * sc + 32768.0f;
    float fb = (b[k] - org[k]) * sc + 32768.0f;
    qa[k] = (s32)fa;
    qb[k] = (s32)fb + 1;
  }
  *(s32 *)(info + 0x14) = qa[0];
  *(s32 *)(info + 0x18) = qa[1];
  *(s32 *)(info + 0x1c) = qa[2];
  *(s32 *)(info + 0x20) = qb[0];
  *(s32 *)(info + 0x24) = qb[1];
  *(s32 *)(info + 0x28) = qb[2];
  u8 *block = *(u8 **)(oct + 0x14);
  *(u8 **)(info + 0xc) = block + 0x14;
  *(u8 **)(info + 0x10) = block + *(const u32 *)block;
  ext_4e3380(*(u8 **)(info + 0xc), info, 0, 0x8000, 0x8000, 0x8000);
}
PCREG(4e3520, octreeCheckCube);
