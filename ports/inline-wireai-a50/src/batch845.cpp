// batch845.cpp - area 50 (residue-10 list): ZInputAction::AddNode(int index, bool on) [high, vt 1].
// Tagged list head at +0xc: a node with tag 3 is itself (minus 4); with tag 1 the node's +8 word is the next one (minus 4);
// anything else is no node. The owner's +0x11 word is the object whose table (+0x1344, 10-byte entries) holds the entry
// for index (its word +0x1210 must be larger than index). A new node (0x4382e0) takes the entry's old value and the
// owner's tagged value; the entry's word +4 is set to the node; the counters at +0x42 (matched when the entry's byte +8
// equals "on") and +0x19 are updated, the sub-object (+0x15) gets vt +4(index), and +0x32 bit 0x10 is cleared when the
// counters differ.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_4382e0(void *a);   // node allocator (not ported here)

// The owner node of a tagged head pointer, or 0 (the exe's three-way select).
static u32 OwnerOf(u32 p) {
  if (!p) return 0;
  u32 t = *(u32 *)p;
  if (t == 3) return p - 4;
  if (t == 1) {
    u32 q = *(u32 *)(p + 8);
    return q ? q - 4 : 0;
  }
  return 0;
}

static void THISCALL AddNode(u8 *self, s32 index, u8 on) {
  u32 owner = OwnerOf(F32(self, 0xc));
  u8 *obj = (u8 *)F32(owner, 0x11);
  if ((s32)F32(obj, 0x1210) <= index) return;
  u32 off = (u32)index * 10u;
  u8 *esi = (u8 *)FP(obj, 0x1344) + off;
  u8 *n = (u8 *)ext_4382e0(FP(esi, 0));
  u32 old = *(volatile u32 *)(esi + 4);   // read before the entry is rewritten (the node may alias the entry)
  F32(n, 5) = old;
  F32(n, 0) = self ? (u32)(unsigned long)self + 4u : 0u;
  F8(n, 4) = on;
  FP(esi, 4) = n;
  u32 owner2 = OwnerOf(F32(self, 0xc));
  u8 *obj2 = (u8 *)F32(owner2, 0x11);
  if (F8(FP(obj2, 0x1344), off + 8) == on) F32(self, 0x42) += 1;
  vcall<void>(FP(self, 0x15), 4, (u32)index);
  F32(self, 0x19) += 1;
  if (F32(self, 0x42) != F32(self, 0x19)) F8(self, 0x32) &= 0xef;
}
PCREG(4377e0, AddNode);
