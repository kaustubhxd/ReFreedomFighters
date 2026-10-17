// batch1319.cpp - inventory thread (inline-inventory, 2026-10-11): CInventory::RemoveItem() (0x4ad4d0).
// The function takes no argument (the caller passes only `this`). It walks the container list at +0x11a (count slot 0x14,
// first element slot 0x30(0), removal slot 0x3c(id)): each id is looked up twice in the reference table; a missing object
// does nothing; a missing second object or a failing check logs an error (cdecl slot 0x2c); the holder at +0x6a is told
// (slot 0x128); the action list at +0x1c6 drops the entries of this id (manager record +0x106 == id, then its slot 0xac);
// the object gets slot 0x210(1). The SEH frame of the original (fs:[0]) is not reproduced.
#include "ff.h"

extern "C" u32 THISCALL ext_4cc1d0(u8 *list);                         // count of a list or message object
extern "C" void THISCALL ext_4cbec0(u8 *s);                           // MYSTR::~MYSTR()
static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL inventoryRemoveItem(u8 *self) {
  u8 *ref = refTable();
  u8 *L = self + 0x11a;
  if (!vcall<u32>(L, 0x14)) return;
  u8 m1[0x20] = {0}, m1b[0x20] = {0}, m2[0x20] = {0};          // MYSTR temps (ebp-0x90, ebp-0x190, ebp-0x110)
  u8 *owner = *(u8 **)(self + 0x44);
  do {
    u32 id = vcall<u32>(L, 0x30, 0u);
    u8 *ob = vcall<u8 *>(ref, 0x58, id);
    if (ob) {
      u8 *ob2 = vcall<u8 *>(ref, 0x58, id);
      if (!ob2) {
        u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6909a4u, 0x290u);
        u8 *mo = vcall<u8 *>(owner, 0x1d8, m1, 1u);
        u32 cnt = ext_4cc1d0(mo);
        ((u32(*)(u8 *, u32, u32))(*(u32 *)(*(u8 **)pr + 0x2c)))(pr, 0x690c24u, cnt);
        ext_4cbec0(m1);
        vcall<u32>(ob, 0x210, 1u);
      } else if (!vcall<u32>(L, 0x28, id)) {
        u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6909a4u, 0x295u);
        u8 *m1r = vcall<u8 *>(owner, 0x1d8, m1b, 1u);
        u8 *m2r = vcall<u8 *>(ob2, 0x1d8, m2, 1u);
        u32 cntb = ext_4cc1d0(m1r);
        u32 cnts = ext_4cc1d0(m2r);
        ((u32(*)(u8 *, u32, u32, u32))(*(u32 *)(*(u8 **)pr + 0x2c)))(pr, 0x690c60u, cnts, cntb);
        ext_4cbec0(m2);
        ext_4cbec0(m1b);
        vcall<u32>(ob, 0x210, 1u);
      } else {
        vcall<u32>(L, 0x3c, id);
        u32 hq = *(u32 *)(self + 0x6a);
        if (hq) {
          u8 *holder = vcall<u8 *>(ref, 0x58, hq);
          vcall<u32>(holder, 0x128, (u32)*(u16 *)(self + 0x4a), id, 0u);
        }
        u8 *A = self + 0x1c6;
        u32 cur[3] = {0, 0, 0};
        vcall<u32>(A, 0x4c, cur);
        u32 e = vcall<u32>(A, 0x5c, cur);
        while (cur[0]) {
          u8 *r = vcall<u8 *>(G(u8 *, 0x70038c), 0xcc, e);
          // no record, or a record of this id: the entry is removed (a record of another id is kept)
          if (!r || *(u32 *)(r + 0x106) == id) {
            if (r) vcall<u32>(r, 0xac);
            vcall<u32>(A, 0x44, cur);
          }
          e = vcall<u32>(A, 0x5c, cur);
        }
        vcall<u32>(ob, 0x210, 1u);
      }
    }
  } while (vcall<u32>(L, 0x14));
}
PCREG(4ad4d0, inventoryRemoveItem);
