// batch1318.cpp - inventory thread (inline-inventory, 2026-10-11): CInventory::AddItem(unsigned int id) (0x4acf30).
// The original's SEH frame (fs:[0]) is not reproduced; it has no effect on the result.
// Branches:
//  - no object for the id: log "ERROR: Tried to add non-existing item to Object %s" (logger slot 0x20 then cdecl slot 0x2c);
//  - an object that is neither an item (0x1007d1) nor a template (0x1007d3): log "...not an item, to Object %s";
//  - an owner of class 0x80200014 whose item's template is "KevlarVest": armour message (MSG_SETARMORPOINTS), then the
//    item's slot 0x210(1) if it is an item;
//  - a template: a new item is made (slot 0x2c4), added to the owner (slot 0x2f0 or the armour-state slot 0x328);
//  - an ammo-type item (0x1007d8): its value goes to the owner (slot 0x98), and the owner's object gets it (0x328);
//  - otherwise the id joins the container list (+0x11a, slot 4) and the owner at +0x6a is told (slot 0x128).
#include "ff.h"

extern "C" u32 THISCALL ext_4cc1d0(u8 *list);                         // count of a list or message object
extern "C" void THISCALL ext_4cbec0(u8 *s);                           // MYSTR::~MYSTR()
static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 isA(u8 *g, u32 type) { return (u8)vcall<u32>(g, 0x1e0, type); }
typedef int (*stricmp_t)(u32, u32);
#define crt_stricmp (*(stricmp_t *)0x676414)                         // IAT: _stricmp
#define NONAME 0x67c8e8

static u32 THISCALL inventoryAddItem(u8 *self, u32 id) {
  u8 *ref = refTable();
  u8 *ob = vcall<u8 *>(ref, 0x58, id);
  u8 m1[0x20] = {0};                                         // MYSTR temps (ebp-0x90, ebp-0x110)
  u8 m2[0x20] = {0};
  u8 *owner = *(u8 **)(self + 0x44);

  if (!ob) {
    u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6909a4u, 0x243u);
    u8 *mo = vcall<u8 *>(owner, 0x1d8, m1, 1u);
    u32 cnt = ext_4cc1d0(mo);
    ((u32(*)(u8 *, u32, u32))(*(u32 *)(*(u8 **)pr + 0x2c)))(pr, 0x690b78u, cnt);   // cdecl print
    ext_4cbec0(m1);
    return 0;
  }
  if (!isA(ob, 0x1007d1) && !isA(ob, 0x1007d3)) {
    u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6909a4u, 0x248u);
    u8 *m2r = vcall<u8 *>(owner, 0x1d8, m2, 1u);
    u8 *m1r = vcall<u8 *>(ob, 0x1d8, m1, 1u);
    u32 cntb = ext_4cc1d0(m2r);
    u32 cnts = ext_4cc1d0(m1r);
    ((u32(*)(u8 *, u32, u32, u32))(*(u32 *)(*(u8 **)pr + 0x2c)))(pr, 0x690bb0u, cnts, cntb);
    ext_4cbec0(m1);
    ext_4cbec0(m2);
    return 0;
  }

  // 4ad0b7: the template of an item (or the template itself)
  u8 *tmpl = ob;
  if (isA(ob, 0x1007d1)) tmpl = vcall<u8 *>(ob, 0x2e8);     // no argument on this path (the ammo path pushes 0)
  if (isA(owner, 0x80200014)) {
    u32 nm = *(u32 *)(tmpl + 4);
    if (crt_stricmp(nm ? nm : NONAME, 0x690bf4u) == 0) {    // "KevlarVest": armour points
      u16 msg = (u16)vcall<u32>(ref, 0x114, 0x690c00u, 0u, 0x6909a4u, 0x252u);
      vcall<u32>(owner, 0x128, (u32)msg, 0x32u, 0u);
      u8 *mm = vcall<u8 *>(ref, 0x138);
      u32 v120 = 0;
      vcall<u32>(mm, 0x88, 0x690c14u, &v120);
      u8 *obj = vcall<u8 *>(ref, 0x58, v120);
      if (obj) vcall<u32>(obj, 0xbc, 0u);
      if (!isA(ob, 0x1007d1)) return 0;
      vcall<u32>(ob, 0x210, 1u);
      return 0;
    }
  }

  // 4ad1d7: a template makes a new item, which joins the owner
  u8 *b = ob;
  u32 cid = id;
  if (isA(ob, 0x1007d3)) {
    u8 *nw = vcall<u8 *>(ob, 0x2c4, *(u32 *)(ref + 0xadc), 0x4954454du);
    u32 nid = vcall<u32>(ref, 0x4c, nw);
    cid = nid;
    if (!nid) return 0;
    b = vcall<u8 *>(ref, 0x58, nid);
    vcall<u32>(b, 0x2d0, 1u, 0u);
    if (isA(ob, 0x1007d5)) {
      u32 v = vcall<u32>(ob, 0x31c);
      vcall<u32>(b, 0x328, v);
    } else {
      u32 a = vcall<u32>(owner, 0x20, 0u);
      u32 id2 = vcall<u32>(ref, 0x4c, owner);
      vcall<u32>(b, 0x2f0, id2, a);
    }
  }

  // 4ad2ca: an ammo-type item gives its value to the owner
  if (isA(b, 0x1007d8)) {
    u32 t = vcall<u32>(b, 0x2e8, 0u);
    u32 v = vcall<u32>(self, 0x98, t);
    u8 *obj2 = vcall<u8 *>(ref, 0x58, v);
    if (obj2) {
      u32 w = vcall<u32>(b, 0x320);
      vcall<u32>(obj2, 0x328, w);
      return (u32)obj2;
    }
  }

  // 4ad333: the container list gets the id; the owner at +0x6a is told
  vcall<u32>(self + 0x11a, 4, cid);
  u32 q = *(u32 *)(self + 0x6a);
  if (q) {
    u8 *o3 = vcall<u8 *>(ref, 0x58, q);
    vcall<u32>(o3, 0x128, (u32)*(u16 *)(self + 0x48), cid, 0u);
  }
  return (u32)b;
}
PCREG(4acf30, inventoryAddItem);
