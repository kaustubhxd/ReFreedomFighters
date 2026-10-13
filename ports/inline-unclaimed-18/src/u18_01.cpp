// u18_01.cpp - area 18, first group: trivial accessors and a list walk (unclaimed-18 thread). Names: GC map where noted.
#include "ff.h"

// 0x483ed0, ZPlayer::GetStatus() const (GC map high). thiscall; returns the flag dword at +0x417.
static u32 THISCALL playerGetStatus(u8 *self) { return *(u32 *)(self + 0x417); }
PCREG(483ed0, playerGetStatus);

// 0x4f7f10, ZSlider::IsChanging() const (GC map high). thiscall; returns the raw byte at +0xd3 in AL (not normalised).
static u8 THISCALL sliderIsChanging(u8 *self) { return self[0xd3]; }
PCREG(4f7f10, sliderIsChanging);

// 0x64fc50, ZRender::GetSizeX() const (GC map high). thiscall; returns the dword at +0x84.
static u32 THISCALL renderGetSizeX(u8 *self) { return *(u32 *)(self + 0x84); }
PCREG(64fc50, renderGetSizeX);

// 0x5d92d0, CTVOnOff::Init() (GC map high). thiscall; clears the dword at +0x4c.
static void THISCALL tvOnOffInit(u8 *self) { *(u32 *)(self + 0x4c) = 0; }
PCREG(5d92d0, tvOnOffInit);

// 0x658d50, ZGeomDrawEntry::BonesSize() (GC map high). thiscall. Size of the bone block: 0x90 + 0x84 * count(+0x3f),
// plus 0x2e0 when the flag bit 4 of the byte at +0x3c is set.
static u32 THISCALL geomDrawEntryBonesSize(u8 *self) {
  u32 extra = (self[0x3c] & 4) ? 0x2e0u : 0u;
  return (u32)self[0x3f] * 0x84u + 0x90u + extra;
}
PCREG(658d50, geomDrawEntryBonesSize);

// 0x4e83d0, ZBinTree::Minimum(SBinTreeNode*) (GC map high). thiscall, one stack arg (ret 4): walks the +4 links from the
// node until the next link is the tree's sentinel (this+8); returns the last node before the sentinel (the node itself when
// its next link is already the sentinel).
static u8 *THISCALL binTreeMinimum(u8 *tree, u8 *node) {
  u8 *sentinel = *(u8 **)(tree + 8);
  u8 *cur = node;
  u8 *next = *(u8 **)(cur + 4);
  if (next == sentinel)
    return cur;
  do {
    cur = next;
    next = *(u8 **)(cur + 4);
  } while (next != sentinel);
  return cur;
}
PCREG(4e83d0, binTreeMinimum);
