// batch1200.cpp - pathfinding tree (inline-pathfinding thread, 2026-10-11): small ZPFOctree_packed / ZPathfinder3 /
// ZActor pathfinder leaves. Names from decoders/gc_pc_namemap.tsv (GC startup_release.elf symbols); the PC build packs
// structs with /Zp1, so offsets such as +0x5a and +0x7d are unaligned on purpose.
#include "ff.h"

// 0x532730 ZPFOctree_packed::isActionAllowed(int) [map medium; GameCube reference]. thiscall, this unused, ret 4, bool in AL.
// A link action is refused when bit 15 is set, or when bit 14 (the reverse direction) is set and the action number
// (low 12 bits) is 2 (drop-only links: a jump-down cannot be walked back up).
static bool THISCALL isActionAllowed(void *, u32 action) {
  bool off = (action >> 15) & 1;
  bool dropBack = (action & 0x4000) && (action & 0xfff) == 2;
  return !off && !dropBack;
}
PCREG(532730, isActionAllowed);

// 0x532770 ZPFOctree_packed::isInCoarserPath(unsigned short*, unsigned short, int) [map medium; GameCube reference].
// thiscall, ret 0xc, bool in AL. The path pointer is not read in the PC build. +0x38 = number of levels, +0x5a =
// SPFAreaInfo_packed table (12-byte records: +2 marker, +4 parent), +0x54 = component table (0x16-byte records: +2
// marker, +4 parent). "In the coarser path" = the marker word of the record one level up is 0xffff.
static bool THISCALL isInCoarserPath(u8 *self, u16 *, u32 idx, int level) {
  int levels = *(int *)(self + 0x38);
  u16 i = (u16)idx;
  if (level == levels) {
    u8 *area = *(u8 **)(self + 0x5a);
    return *(u16 *)(area + i * 12 + 2) == 0xffff;
  }
  u8 *comp = *(u8 **)(self + 0x54);
  if (level == (int)((u32)levels - 1u)) {
    u8 *area = *(u8 **)(self + 0x5a);
    u16 p = *(u16 *)(area + i * 12 + 4);
    return *(u16 *)(comp + p * 0x16 + 2) == 0xffff;
  }
  u16 p = *(u16 *)(comp + i * 0x16 + 4);
  return *(u16 *)(comp + p * 0x16 + 2) == 0xffff;
}
PCREG(532770, isInCoarserPath);

// 0x532800 ZPFOctreeNodeCheckBox_packed::isOK(ZPFOctree_packed*, unsigned short, int*, int*) [map medium; GC
// 801955a8 via vtable slot 0]. thiscall, ret 0x10, bool. The box is min (+4,+8,+0xc) / max (+0x10,+0x14,+0x18), ints;
// a node [lo, hi] is OK when it overlaps the box: lo < max and hi > min on every axis (signed).
static bool THISCALL nodeCheckBoxIsOK(u8 *self, void *, u32, int *lo, int *hi) {
  int *b = (int *)self;
  if (lo[0] >= b[4] || lo[1] >= b[5] || lo[2] >= b[6]) return false;
  if (hi[0] <= b[1] || hi[1] <= b[2] || hi[2] <= b[3]) return false;
  return true;
}
PCREG(532800, nodeCheckBoxIsOK);

// 0x530fb0 ZPFOctree_packed::Init0(bool, bool) [map low; GameCube reference stores +0/+4 there, PC +4/+5]. thiscall, ret 8.
static void THISCALL octreeInit0(u8 *self, u32 a, u32 b) {
  self[4] = (u8)a;
  self[5] = (u8)b;
}
PCREG(530fb0, octreeInit0);

// 0x52b370 ZPathfinder3::GetDoorBlockerPtr(int) [map high; vtable slot 137]. thiscall, ret 4. Door ids are 1-based
// into the 8-byte door-blocker array at +0x7d; id 0 gives NULL.
static void *THISCALL getDoorBlockerPtr(u8 *self, int id) {
  if (!id) return 0;
  return *(u8 **)(self + 0x7d) + id * 8 - 8;
}
PCREG(52b370, getDoorBlockerPtr);

// ZActor pathfinder accessors (map high, vtable slots 367..369).
// 0x478e90 ZActor::GetPathFinder3() const: +0x5b2.
static void *THISCALL actorGetPathFinder3(u8 *self) { return *(void **)(self + 0x5b2); }
PCREG(478e90, actorGetPathFinder3);
// 0x47bfb0 ZActor::SetPathFinder3(void*), ret 4.
static void THISCALL actorSetPathFinder3(u8 *self, void *pf) { *(void **)(self + 0x5b2) = pf; }
PCREG(47bfb0, actorSetPathFinder3);
// 0x478620 ZActor::EnablePathFinder(bool), ret 4: byte +0x690.
static void THISCALL actorEnablePathFinder(u8 *self, u32 on) { self[0x690] = (u8)on; }
PCREG(478620, actorEnablePathFinder);
