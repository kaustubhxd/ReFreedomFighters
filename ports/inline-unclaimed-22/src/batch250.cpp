// batch250.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch250"): ZMoveOnSpline::Load.
// Name from the GameCube name map (high); behaviour from the PC bytes. The straight-line body was generated from the
// disassembly listing (scratch script) and checked against it. The exe reads the three geom ids into its own argument slot
// ([ebp+8]); the port uses a local.
#include "ff.h"

extern "C" u32 THISCALL ext_440e10(u8 *self, u8 *l);            // original base Load (ret 4); al = success
extern "C" void THISCALL ext_523710(u8 *self, u8 *l);           // original (ret 4): loads the path object at +0x5c
extern "C" void THISCALL ext_4e78c0(u8 *self, u8 *l);           // original (ret 4): loads the block at +0x144
extern "C" void FASTCALL ext_511bc0(u8 *l, u8 *p);              // original, fastcall (ecx = stream, edx = this + 0xda), ret

// 0x5135c0 ZMoveOnSpline::Load(ZLoadGame*) ret 4, returns al. Base load 0x440e10 first (false: its eax is returned), then the
// reads below in exe order (+0x159, +0x1c1, +0x1c5 = engine db->vt[0x58](id read with slot 0x40)); this->vt[0x2e4](); true.
static u32 THISCALL moveOnSplineLoad_5135c0(u8 *self, u8 *l) {
  u32 ok = ext_440e10(self, l);
  if (!(u8)ok) return ok;
  u32 id;
  ext_523710(*(u8 **)(self + 0x5c), l);
  vcall<void>(l, 0x6c, (u32)(self + 0x60));
  vcall<void>(l, 0x74, (u32)(self + 0x6c));
  vcall<void>(l, 0x6c, (u32)(self + 0x90));
  vcall<void>(l, 0x74, (u32)(self + 0x9c));
  vcall<void>(l, 0x50, (u32)(self + 0xc0));
  vcall<void>(l, 0x18, (u32)(self + 0xc4), 4u);
  vcall<void>(l, 0x50, (u32)(self + 0xc8));
  vcall<void>(l, 0x68, (u32)(self + 0xcc));
  vcall<void>(l, 0x68, (u32)(self + 0xcd));
  vcall<void>(l, 0x40, (u32)(self + 0xce));
  vcall<void>(l, 0x40, (u32)(self + 0xd2));
  vcall<void>(l, 0x40, (u32)(self + 0xd6));
  vcall<void>(l, 0x68, (u32)(self + 0x11e));
  vcall<void>(l, 0x48, (u32)(self + 0x11f));
  ext_511bc0(l, self + 0xda);
  vcall<void>(l, 0x40, (u32)(self + 0x123));
  vcall<void>(l, 0x70, *(u32 *)(self + 0x127));
  vcall<void>(l, 0x70, *(u32 *)(self + 0x12b));
  vcall<void>(l, 0x40, (u32)(self + 0x12f));
  vcall<void>(l, 0x68, (u32)(self + 0x133));
  ext_4e78c0(self + 0x144, l);
  vcall<void>(l, 0x40, (u32)&id);
  *(u32 *)(self + 0x159) = vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, id);
  vcall<void>(l, 0x6c, (u32)(self + 0x15d));
  vcall<void>(l, 0x74, (u32)(self + 0x169));
  vcall<void>(l, 0x48, (u32)(self + 0x18d));
  vcall<void>(l, 0x48, (u32)(self + 0x191));
  vcall<void>(l, 0x50, (u32)(self + 0x195));
  vcall<void>(l, 0x50, (u32)(self + 0x199));
  vcall<void>(l, 0x74, (u32)(self + 0x19d));
  vcall<void>(l, 0x40, (u32)&id);
  *(u32 *)(self + 0x1c1) = vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, id);
  vcall<void>(l, 0x40, (u32)&id);
  *(u32 *)(self + 0x1c5) = vcall<u32>(*(u8 **)(*(u8 **)0x70039cu + 0x9b), 0x58, id);
  vcall<void>(l, 0x50, (u32)(self + 0x1c9));
  vcall<void>(l, 0x40, (u32)(self + 0x1d1));
  vcall<void>(l, 0x40, (u32)(self + 0x1d9));
  vcall<void>(l, 0x48, (u32)(self + 0x1dd));
  vcall<void>(l, 0x50, (u32)(self + 0x1e1));
  vcall<void>(l, 0x48, (u32)(self + 0x1e5));
  vcall<void>(l, 0x50, (u32)(self + 0x1e9));
  vcall<void>(l, 0x70, *(u32 *)(self + 0x1ed));
  vcall<void>(l, 0x68, (u32)(self + 0x215));
  vcall<void>(self, 0x2e4);
  return 1;
}
PCREG(5135c0, moveOnSplineLoad_5135c0);
