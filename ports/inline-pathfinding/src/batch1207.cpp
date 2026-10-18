// batch1207.cpp - pathfinding tree: A* slot allocation, the neighbour visit of the fine A*, TryLine.
#include "pf.h"

extern "C" u32 THISCALL ext_532420(void *oct, u32 from, const u16 *x);   // VisitNeighborSpecialThin
extern "C" u32 THISCALL ext_52e320(void *it, const s16 *d);              // ElementMove (batch1206)
extern "C" u32 THISCALL ext_531070(void *it, const s16 *d);              // NodeMove (batch1206)
extern "C" u32 THISCALL ext_530a40(void *it);                            // aStarIndex (below)
extern "C" void THISCALL ext_52d250(void *oct, u32 head, u32 node);      // AddToPrioQueue (batch1202)
extern "C" u32 THISCALL ext_52e0a0(void *oct, float *a, float *b, u32 flag);   // ZPFOctree_packed::CheckLine
extern "C" void *THISCALL ext_476dc0(void *lst, int n);                  // CChkPntLst::CChkPntLst(int)
extern "C" void THISCALL ext_52d1c0(void *oct, void *lst, int *n, float *len, float *prev, float *p, int,
                                    void *helpers, void *extra);         // AddPoint (batch1203)

// 0x530a40 (no GC name; inlined there) ZPFOctreeIterator_packed: A* slot of the current id, allocated on first use.
// thiscall, u16 in AX, 0 when the A* array (+0x50 entries) is full or the kind is unknown. Iterator +4 = u16* next
// free slot, +8 = int slots per leaf (elements). Kind 1 (component node): record +2 holds the slot, +0 indexes the
// 10-byte size table at octree+0x78 (byte 0 = slots needed); kind 2 (area): the same on the area record; kind 3
// (element): the leaf's base slot at area +0xa, plus (z & 7) * 8 + (x & 7).
static u32 THISCALL aStarIndex(u8 *it) {
  u8 *oct = *(u8 **)it;
  u16 *next = *(u16 **)(it + 4);
  u8 kind = it[0x20];
  if (kind == 1 || kind == 2) {
    u8 *rec = kind == 1 ? *(u8 **)(oct + 0x54) + *(u16 *)(it + 0x16) * 0x16
                        : *(u8 **)(oct + 0x5a) + *(u16 *)(it + 0x16) * 12;
    if (*(u16 *)(rec + 2)) return *(u16 *)(rec + 2);
    u8 *sz = *(u8 **)(oct + 0x78) + *(u16 *)rec * 10;
    u32 c = *next;
    if (sz[0] + c > *(u16 *)(oct + 0x50)) return 0;
    *(u16 *)(rec + 2) = (u16)c;
    **(u16 **)(it + 4) += sz[0];
    return *(u16 *)(rec + 2);
  }
  if (kind != 3) return 0;
  u8 *rec = *(u8 **)(oct + 0x5a) + *(u16 *)(it + 0x16) * 12;
  if (!*(u16 *)(rec + 0xa)) {
    u32 c = *next;
    if ((int)(c + *(u32 *)(it + 8)) > (int)*(u16 *)(oct + 0x50)) return 0;
    *(u16 *)(rec + 0xa) = (u16)c;
    **(u16 **)(it + 4) += (u16)*(u32 *)(it + 8);
  }
  return (u16)(((*(u16 *)(it + 0x1a) & 7) << 3) + (*(u16 *)(it + 0x18) & 7) + *(u16 *)(rec + 0xa));
}
PCREG(530a40, aStarIndex);

// Neighbour steps (0x6e9004, s16 x/z/y): 0 = +z, 1 = -z, 2 = +x, 3 = -x, 4 = +y, 5 = -y.
#define DIRS ((const s16 *)0x6e9004)

// 0x531b40 ZPFOctree_packed::VisitNeighbor(unsigned short from, ZPFOctreeIterator_packed*, PFDirection, float,
// const unsigned short*) [map high; GC 8019a1b8]. thiscall, ret 0x14. Direction 10 = special links (VisitNeighbor-
// SpecialThin), 11 = the iterator's current id, else a step along DIRS (element or node move by iterator kind).
// Returns 0 when blocked, 0xffff when the A* array is full, else 1. The cost argument is not used on PC: every step
// costs 1.0001; the neighbour is relaxed only when its f is more than 0.1 above the new value.
static u32 THISCALL visitNeighbor(u8 *self, u32 from, u8 *it, u32 dir, float, const u16 *x) {
  if (dir == 10) return ext_532420(self, from, x);
  u16 id;
  if (dir == 11) id = *(u16 *)(it + 0x16);
  else if (it[0x20] == 3) id = (u16)ext_52e320(it, DIRS + dir * 3);
  else id = (u16)ext_531070(it, DIRS + dir * 3);
  if (!id) return 0;
  u16 idx = (u16)ext_530a40(it);
  if (!idx) return 0xffff;
  u8 *base = *(u8 **)(self + 0x98);
  u8 *n = base + idx * 0x15;
  float f = *(float *)(base + (u16)from * 0x15 + 0xa) + 1.0001f;   // 0x6a1584
  if (*(float *)(n + 0xa) > f + 0.1f) {                             // 0x67a284
    n[0x14] &= 0xfe;
    *(u16 *)(n + 0xe) = (u16)from;
    *(float *)(n + 0xa) = f;
    *(u16 *)n = *(u16 *)(it + 0x16);
    *(u16 *)(n + 4) = *(u16 *)(it + 0x18);
    *(u16 *)(n + 6) = *(u16 *)(it + 0x1a);
    *(u16 *)(n + 8) = *(u16 *)(it + 0x1c);
    ext_52d250(self, from, idx);
  }
  return 1;
}
PCREG(531b40, visitNeighbor);

// 0x531a50 ZPFOctree_packed::TryLine(float* a, float* b, CHelpers*) [map high; GC 80195424]. thiscall, ret 0xc.
// When the straight line a -> b is free (CheckLine with the flag 1), returns a new two-point CChkPntLst (a, b) with
// its total length at +4; else NULL. AddPoint copies each point into `a`, so a ends up equal to b (as in the exe).
// The exe's SEH frame only guards the constructor (exception unwinding); there is nothing to port from it.
static void *THISCALL tryLine(u8 *self, float *a, float *b, void *helpers) {
  if (!(u8)ext_52e0a0(self, a, b, 1)) return 0;
  void *mem = ext_41e290(0x18);
  void *lst = mem ? ext_476dc0(mem, 2) : 0;
  int n = 0;
  float len = 0;
  ext_52d1c0(self, lst, &n, &len, a, a, 2, helpers, 0);
  ext_52d1c0(self, lst, &n, &len, a, b, 2, helpers, 0);
  *(float *)((u8 *)lst + 4) = len;
  return lst;
}
PCREG(531a50, tryLine);
