// batch0118.cpp - fresh-01 batch 18 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *d, const float *s);       // mcpy (3x3 matrix copy)
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x54da90, ZSynth::GetBuffer(unsigned int, SWaveHeader*, unsigned int): scans the +0x805d buffers at +0x803d. Busy
// ones (+0x7d) are counted in +0x8025; among them those whose wave (+0x5d) +8 is negative are counted and the one
// with the lowest +0x35 kept, likewise the lowest among the rest; the first idle one is kept too. A header with a
// negative +8 and exactly 4 negative busy buffers takes the lowest negative one when size is above its +0x35; when
// every buffer is busy the lowest other one when size is above its +0x35; otherwise the first idle one (or 0).
static u8 *THISCALL synthGetBuffer(u8 *self, u32 size, u8 *hdr, u32) {
  u32 neg = 0;
  u8 *bn = 0, *bp = 0, *idle = 0;
  *(u32 *)(self + 0x8025) = 0;
  s32 n = *(s32 *)(self + 0x805d);
  if (n > 0) {
    u8 **arr = *(u8 ***)(self + 0x803d);
    for (u32 k = *(u32 *)(self + 0x805d); k != 0; k--, arr++) {
      u8 *b = *arr;
      if (b[0x7d]) {
        (*(u32 *)(self + 0x8025))++;
        if (*(s32 *)(*(u8 **)(b + 0x5d) + 8) < 0) {
          neg++;
          if (!bn || *(u32 *)(b + 0x35) < *(u32 *)(bn + 0x35)) bn = b;
        } else {
          if (!bp || *(u32 *)(b + 0x35) < *(u32 *)(bp + 0x35)) bp = b;
        }
      } else if (!idle) {
        idle = b;
      }
    }
  }
  if (*(s32 *)(hdr + 8) < 0 && neg == 4) {
    if (size > *(u32 *)(bn + 0x35)) return bn;
    return idle;
  }
  if (*(u32 *)(self + 0x8025) == *(u32 *)(self + 0x805d) && size > *(u32 *)(bp + 0x35)) return bp;
  return idle;
}
PCREG(54da90, synthGetBuffer);

// 0x63b510, ZOffsetAllocPointerSort<1024>::Alloc(unsigned int): first-fit by bucket: buckets 0..+0x3408 at this,
// nodes {offset, size, next} at +0x400; in the first bucket holding a node of at least `size` bytes, the one with the
// lowest offset is unlinked; an exact fit frees the node (u16 count +0x3400 down, free list head u16 +0x3402 =
// node index, the node's first u16 = old head), else the node shrinks from the front and is relinked into bucket
// offset >> +0x3404. Returns the old offset, or -1.
struct OffNode { u32 off, size; OffNode *next; };
static u32 THISCALL offsetAlloc(u8 *self, u32 size) {
  u32 *bucket = (u32 *)self;
  for (u32 i = 0; i != *(u32 *)(self + 0x3408); i++) {
    OffNode **link = (OffNode **)&bucket[i];
    OffNode *best = 0, **bestLink = 0;
    for (OffNode *nd = *link; nd; link = &nd->next, nd = *link) {
      if (nd->size >= size && (!best || best->off > nd->off)) {
        bestLink = link;
        best = nd;
      }
    }
    if (best) {
      *bestLink = best->next;
      u32 off = best->off;
      best->size -= size;
      if (best->size == 0) {
        u8 *nodes = self + 0x400;
        *(u16 *)(nodes + 0x3000) += 0xffff;
        *(u16 *)best = *(u16 *)(nodes + 0x3002);
        *(u16 *)(nodes + 0x3002) = (u16)((s32)((u8 *)best - nodes) / 12);
        return off;
      }
      best->off += size;
      u32 b = best->off >> (*(u32 *)(self + 0x3404) & 31);
      best->next = (OffNode *)bucket[b];
      bucket[b] = (u32)best;
      return off;
    }
  }
  return 0xffffffffu;
}
PCREG(63b510, offsetAlloc);

// 0x442150, ZTreeGroup::AddZGEOMBoxLst(eGlobalTreeType, REFTAB*, const float*, const float*, const float*, int, int,
// bool) const: clears the list (slot 0x14), copies the box matrix and position, lets own slot 0x98 transform them,
// queries the tree manager ([[0x70039c]+0x1aa3]+0x1c slot 0x38: buf, mat, type, mat, pos, ext, a6, 1, a8, 1; a7 is
// not used; 0x800-entry stack buffer) and adds render slot 0x50(id) for each hit. The callee-pop of slot 0x38 is a
// GUESS (thiscall); the exe restores esp from ebp so either works there. /GS cookie; 0x203c-byte frame (__chkstk).
static void THISCALL treeGroupAddBoxList(u8 *self, u32 type, u8 *list, const float *mat, const u32 *pos,
                                        const float *ext, u32 a6, u32, u32 a8) {
  u32 hits[0x800];
  float m[9];
  u32 p[3];
  vcall<void>(list, 0x14);
  ext_4de420(m, mat);
  p[0] = pos[0];
  p[1] = pos[1];
  p[2] = pos[2];
  vcall<void>(self, 0x98, m, p);
  u8 *tm = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
  u32 n = vcall<u32>(tm, 0x38, hits, m, type, m, p, ext, a6, 1u, a8, 1u);
  for (u32 i = 0; i != n; i++) vcall<void>(list, 4, vcall<u32>(render(), 0x50, hits[i]));
  ext_633654(G(u32, 0x6f5630));
}
PCREG(442150, treeGroupAddBoxList);
