// batch1311.cpp - inventory thread (inline-inventory, 2026-10-11): ZFFInventorySelector::Init (0x568900).
// Fills the selector's child-geom fields: each field = the child named N of the selector's HUD group (vcall 0x25c
// (name, 0) on the group found by message "HitmanGround"-like id at +0x44, see the spec). The order of the lookups is
// the order of the original code. Then the eight stash slots (+0x3ee..+0x42a) get their weapon types and values.
#include "ff.h"

extern "C" u32 THISCALL ext_562440(u8 *self);                        // CBaseWindow::Init()

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

struct ChildField { u32 off; u32 name; };
// Lookups in the order of the original code: field offset (in the selector) <- child named `name`.
static const ChildField CHILDREN[] = {
    {0x34a, 0x6a71e0}, {0x346, 0x6a71f0}, {0x34e, 0x6a7200}, {0x362, 0x6a7214}, {0x35e, 0x6a7220},
    {0x366, 0x6a7230}, {0x36e, 0x6a7244}, {0x36a, 0x6a724c}, {0x372, 0x6a7258}, {0x37a, 0x6a7268},
    {0x376, 0x6a7270}, {0x37e, 0x6a727c}, {0x386, 0x6a728c}, {0x382, 0x6a7298}, {0x38a, 0x6a72a8},
    {0x3aa, 0x6a72bc}, {0x3a6, 0x6a72c4}, {0x3ae, 0x6a72d0}, {0x356, 0x6a72e0}, {0x352, 0x6a72ec},
    {0x35a, 0x6a72fc}, {0x39e, 0x6a7310}, {0x39a, 0x6a7318}, {0x3a2, 0x6a7324}, {0x3b6, 0x6a7334},
    {0x3b2, 0x6a7334}, {0x3ba, 0x6a7334}, {0x3c2, 0x6a7340}, {0x3be, 0x6a7340}, {0x3c6, 0x6a7340},
    {0x3ce, 0x6a7350}, {0x3ca, 0x6a7350}, {0x3d2, 0x6a7350}, {0x3da, 0x6a7358}, {0x3d6, 0x6a7358},
    {0x3de, 0x6a7358}, {0x3e6, 0x6a7368}, {0x3e2, 0x6a7368}, {0x3ea, 0x6a7368},
};

static void THISCALL selectorInit(u8 *self) {
  ext_562440(self);
  // the owner's id in the message map, then the HUD group object for it
  u8 *m1 = vcall<u8 *>(refTable(), 0x138);
  u32 owner = vcall<u32>(refTable(), 0x4c, *(u8 **)(self + 0x44));
  vcall<u32>(m1, 0x60, 0x6a70a8u, owner, 0x10u);
  u32 id = 0;
  vcall<u32>(vcall<u8 *>(refTable(), 0x138), 0x88, 0x6a71d4u, &id);
  u8 *grp = vcall<u8 *>(refTable(), 0x58, id);
  for (const ChildField &f : CHILDREN) {
    *(u32 *)(self + f.off) = vcall<u32>(grp, 0x25c, f.name, 0u);
  }
  // fixed weapon types of the eight stash slots, then their values from the records
  *(u32 *)(self + 0x3f2) = 3;
  *(u32 *)(self + 0x3fa) = 5;
  *(u32 *)(self + 0x402) = 6;
  *(u32 *)(self + 0x40a) = 7;
  *(u32 *)(self + 0x412) = 8;
  *(u32 *)(self + 0x41a) = 0xb;
  *(u32 *)(self + 0x422) = 0xa;
  *(u32 *)(self + 0x42a) = 4;
  *(u32 *)(self + 0x3ee) = *(u32 *)(self + 0x346);
  *(u32 *)(self + 0x3f6) = *(u32 *)(self + 0x35e);
  *(u32 *)(self + 0x3fe) = *(u32 *)(self + 0x36a);
  *(u32 *)(self + 0x406) = *(u32 *)(self + 0x376);
  *(u32 *)(self + 0x40e) = *(u32 *)(self + 0x382);
  *(u32 *)(self + 0x416) = *(u32 *)(self + 0x3a6);
  *(u32 *)(self + 0x41e) = *(u32 *)(self + 0x39a);
  *(u32 *)(self + 0x426) = *(u32 *)(self + 0x352);
}
PCREG(568900, selectorInit);
