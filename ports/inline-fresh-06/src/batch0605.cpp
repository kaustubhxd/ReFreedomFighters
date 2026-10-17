// batch0605.cpp - fresh-06 batch 5 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);       // __builtin_delete (cdecl)
extern "C" void THISCALL ext_469870(void *self);     // base ctor used by several ZGEOM-like classes
static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
static inline void *rmAlloc(u32 arg) { return vcall<void *>(*(void **)((u8 *)rmgr() + 8), 0x44, arg); }

// 0x5dc060 (no map name; GUESS: destructor body, vtables 0x6b6ab8 then 0x686874): the object at +0x48 is deleted
// (slot 0 with 1) when set, +0x44/+0x30 cleared, the render manager's slot 0x34(this) unregisters it.
static void THISCALL dtor6b6ab8(u8 *self) {
  void *o = *(void **)(self + 0x48);
  *(u32 *)self = 0x6b6ab8;
  if (o) vcall<void>(o, 0, 1u);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(rmgr(), 0x34, self);
}
PCREG(5dc060, dtor6b6ab8);

// 0x4b9160 (no map name; GUESS: destructor body, vtables 0x692a30 then 0x686874): buffers +0x8d (0x6d) and +0x6d
// (0x2c) freed, +0x44/+0x30 cleared, unregistered (render manager slot 0x34).
static void THISCALL dtor692a30(u8 *self) {
  void *p = *(void **)(self + 0x8d);
  *(u32 *)self = 0x692a30;
  ext_634273(p, 0x6d);
  ext_634273(*(void **)(self + 0x6d), 0x2c);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(rmgr(), 0x34, self);
}
PCREG(4b9160, dtor692a30);

// 0x4baf60, CWaves::End(): every wave of the list at +0x48 (iterator: slot 0x4c begin, slot 0x64 next until null)
// frees its +0x1c buffer (only when +0x70 is 0) and its +0x20 buffer (__builtin_delete(p, 4)); then the list is
// deleted (slot 0 with 1). The field is not cleared.
static void THISCALL wavesEnd(u8 *self) {
  if (*(void **)(self + 0x48)) {
    u32 it[3];
    vcall<void>(*(void **)(self + 0x48), 0x4c, it);
    u8 *e = vcall<u8 *>(*(void **)(self + 0x48), 0x64, it);
    while (e) {
      if (*(u32 *)(self + 0x70) == 0) ext_634273(*(void **)(e + 0x1c), 4);
      ext_634273(*(void **)(e + 0x20), 4);
      e = vcall<u8 *>(*(void **)(self + 0x48), 0x64, it);
    }
  }
  void *l = *(void **)(self + 0x48);
  if (l) vcall<void>(l, 0, 1u);
}
PCREG(4baf60, wavesEnd);

// 0x4cabe0 and 0x5d5120 (no map names; GUESS: factories with the base ctor inlined): render manager +8 slot 0x44
// (incoming ECX as its argument) allocates; a non-null object gets 0x469870, flag 0x20 at +4, +0x44 = 0 and vtable
// 0x695020 (0x5d5120: vtable 0x6ab31c and +0x48 = 0xfffffc00).
static void *THISCALL new695020(u32 ecx) {
  u8 *p = (u8 *)rmAlloc(ecx);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = 0x695020;
  }
  return p;
}
PCREG(4cabe0, new695020);
static void *THISCALL new6ab31c(u32 ecx) {
  u8 *p = (u8 *)rmAlloc(ecx);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = 0x6ab31c;
    *(u32 *)(p + 0x48) = 0xfffffc00u;
  }
  return p;
}
PCREG(5d5120, new6ab31c);

// 0x4fc460 (no map name; GUESS: clear an owned doubly linked list): while the head (+0x48) is set, the head node is
// unlinked from its owner (+0x10: current +0x50, head +0x48, tail +0x4c; node prev +8, next +0xc, fields re-read
// after each store as the original) and freed (__builtin_delete(n, 0x15)); then +0x4c, +0x48, +0x50 cleared.
static void THISCALL ownedListClear(u8 *self) {
  while (*(u8 **)(self + 0x48)) {
    u8 *n = *(u8 **)(self + 0x48);
    u8 *ow = *(u8 **)(n + 0x10);
    if (*(u8 **)(ow + 0x50) == n) *(u32 *)(ow + 0x50) = *(u32 *)(n + 0xc);
    u8 *prev = *(u8 **)(n + 8);
    u32 next = *(u32 *)(n + 0xc);
    if (prev) *(u32 *)(prev + 0xc) = next;
    else *(u32 *)(*(u8 **)(n + 0x10) + 0x48) = next;
    u8 *nx = *(u8 **)(n + 0xc);
    u32 pv = *(u32 *)(n + 8);
    if (nx) *(u32 *)(nx + 8) = pv;
    else *(u32 *)(*(u8 **)(n + 0x10) + 0x4c) = pv;
    ext_634273(n, 0x15);
  }
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x50) = 0;
}
PCREG(4fc460, ownedListClear);

// 0x613ba0 (no map name; GUESS: allocate a pool block of 0x8c-byte entries): own slot 0x30 gives the block (null:
// false). Block +1 = byte +0x10, self-linked (+8/+0xc), +0 = 0, word +2 = 0; entry i (i < n - 1, n = own slot 0x28)
// gets next index i + 1 at block+0x10+i*0x8c, the last 0xffff; the block is linked in front of the ring at +8. True.
static u8 THISCALL poolAllocBlock(u8 *self) {
  u8 *b = vcall<u8 *>(self, 0x30);
  if (!b) return 0;
  b[1] = self[0x10];
  u32 n = vcall<u32>(self, 0x28);
  *(u8 **)(b + 8) = b;
  *(u8 **)(b + 0xc) = b;
  b[0] = 0;
  *(u16 *)(b + 2) = 0;
  u32 last = n - 1;
  u8 *d = b + 0x10;
  for (u32 i = 0; i != last; ++i, d += 0x8c) *(u16 *)d = (u16)(i + 1);
  *(u16 *)d = 0xffff;
  u8 *h = *(u8 **)(self + 8);
  if (h) {
    *(u8 **)(b + 8) = h;
    u8 *t = *(u8 **)(h + 0xc);
    *(u8 **)(b + 0xc) = t;
    *(u8 **)(t + 8) = b;
    *(u8 **)(h + 0xc) = b;
  }
  *(u8 **)(self + 8) = b;
  return 1;
}
PCREG(613ba0, poolAllocBlock);

// 0x638ea0 (no map name; GUESS: Morton bit masks for a w x h x d grid): stores (a, b, c) at +0/+4/+8, clears
// +0xc..+0x20, then hands out ascending bits round-robin to the x/y/z masks (+0xc/+0x10/+0x14) while the matching
// size is above the current level bit (1, 2, 4, ...); stops when a level hands out no bit.
static void THISCALL mortonMasks(u32 *self, u32 a, u32 b, u32 c) {
  self[2] = c;
  self[0] = a;
  self[1] = b;
  for (int i = 3; i <= 8; ++i) self[i] = 0;
  u32 lvl = 1, bit = 1, any;
  do {
    any = 0;
    if (lvl < a) { self[3] |= bit; bit += bit; any = bit; }
    if (lvl < b) { self[4] |= bit; bit += bit; any = bit; }
    if (lvl < c) { self[5] |= bit; bit += bit; any = bit; }
    lvl += lvl;
  } while (any);
}
PCREG(638ea0, mortonMasks);

// 0x42cc60, ZSysInterfaceGC::IsControllerConnected(unsigned) (the map name is a COMDAT alias; GUESS: free a block of a
// 40 KB arena): the block's size word sits 2 bytes below the pointer; the handler at 0x7003b0 is called when there
// is no arena (+0x1b55), when the block is outside [arena, arena + 0xa000], and when its last byte is not 'Z'
// (int3 without a handler; not exercised). Then 0x4ce1c0 on +0x1b51 gets (offset, size). Returns its EAX.
extern "C" u32 THISCALL ext_4ce1c0(void *o, u32 off, u32 sz);
static u32 THISCALL arenaFree(u8 *self, u8 *p) {
  typedef void (*hfn)();
  if (*(u32 *)(self + 0x1b55) == 0) {
    hfn h = G(hfn, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  u8 *q = p - 2;
  u32 base = *(u32 *)(self + 0x1b55);
  u32 sz = *(u16 *)q;
  if ((u32)q < base || (u32)q + sz > base + 0xa000) {
    hfn h = G(hfn, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  if (q[sz - 1] != 0x5a) {
    hfn h = G(hfn, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  return ext_4ce1c0(*(void **)(self + 0x1b51), (u32)q - *(u32 *)(self + 0x1b55), sz);
}
PCREG(42cc60, arenaFree);

// 0x57bee0, ZFFDemoMenu::Init2(): only when the menu state ([+0x94]+0x1044) is 3: from the root (+0x54) find
// 0x6a7590, under it 0x6aa5f4 (slot 0x2dc then slot 0x28 on it) and 0x6aa5fc (slot 0x31c(0, 1) and (0, 2)).
static void THISCALL demoMenuInit2(u8 *self) {
  if (*(u32 *)(*(u8 **)(self + 0x94) + 0x1044) != 3) return;
  void *a = vcall<void *>(*(void **)(self + 0x54), 0x25c, 0x6a7590u, 0u);
  void *b = vcall<void *>(a, 0x25c, 0x6aa5f4u, 0u);
  vcall<void>(b, 0x2dc);
  vcall<void>(b, 0x28);
  void *c = vcall<void *>(a, 0x25c, 0x6aa5fcu, 0u);
  vcall<void>(c, 0x31c, 0u, 1u);
  vcall<void>(c, 0x31c, 0u, 2u);
}
PCREG(57bee0, demoMenuInit2);

// 0x4fd9a0, ZSortCameraList::Save(ZSaveGame*): flag 0x40 of +4 cleared; for each node from +0x48 (next +0xc): id
// (slot 0x3c), byte +0x14 (slot 0x60), float +4 (slot 0x4c, bits); then -1 and the index of the current node (+0x50;
// -1 when not in the list) with slot 0x3c. Returns true.
static u8 THISCALL sortCamListSave(u8 *self, void *sg) {
  u32 cur = 0xffffffffu;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u8 *n = *(u8 **)(self + 0x48);
  for (u32 i = 0; n; ++i) {
    if (*(u8 **)(self + 0x50) == n) cur = i;
    vcall<void>(sg, 0x3c, *(u32 *)n);
    vcall<void>(sg, 0x60, (u32)n[0x14]);
    vcall<void>(sg, 0x4c, *(u32 *)(n + 4));
    n = *(u8 **)(n + 0xc);
  }
  vcall<void>(sg, 0x3c, 0xffffffffu);
  vcall<void>(sg, 0x3c, cur);
  return 1;
}
PCREG(4fd9a0, sortCamListSave);

// 0x5f2720, ZScriptDll::PopScene(): the scene (+0xc) count +0x9c drops; at 0 its owner (+4) gets 0x5fd170. Unless the
// render manager's byte +0xbc4 is set, the scene's +0xa0 and +0xa4 objects (when set) get slot 0x18. Then
// RegisterZMsg (render manager slot 0x114: 0x694c6c, 0, 0x6b8738, 0x1b8) and its word goes to 0x7143b0.
extern "C" void THISCALL ext_5fd170(void *o);
static void THISCALL scriptPopScene(u8 *self) {
  if (--*(s32 *)(*(u8 **)(self + 0xc) + 0x9c) == 0) ext_5fd170(*(void **)(*(u8 **)(self + 0xc) + 4));
  if (((u8 *)rmgr())[0xbc4] == 0) {
    void *o = *(void **)(*(u8 **)(self + 0xc) + 0xa0);
    if (o) vcall<void>(o, 0x18);
    o = *(void **)(*(u8 **)(self + 0xc) + 0xa4);
    if (o) vcall<void>(o, 0x18);
  }
  G(u16, 0x7143b0) = vcall<u16>(rmgr(), 0x114, 0x694c6cu, 0u, 0x6b8738u, 0x1b8u);
}
PCREG(5f2720, scriptPopScene);

// 0x5c37e0 (no map name; GUESS: constructor, vtable 0x6b3de4): 0x469870, flag 0x20 at +4, +0x44 = 0, vtable; then
// RegisterZMsg (0x6ad080, 0, 0x6b3e68, 0x1b) and its word to 0x714338. Returns this.
static void *THISCALL ctor6b3de4(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b3de4;
  G(u16, 0x714338) = vcall<u16>(rmgr(), 0x114, 0x6ad080u, 0u, 0x6b3e68u, 0x1bu);
  return self;
}
PCREG(5c37e0, ctor6b3de4);

// 0x436260 (no map name; GUESS: release three object arrays): arrays at +4 (count +0xc), +0x10 (count +0x1c) and
// +0x20 (count +0x60): each entry gets slot 8, then (re-read, when set) is deleted (slot 0 with 1).
static void THISCALL release3Arrays(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); ++i) {
    void **e = (void **)(self + 4) + i;
    vcall<void>(*e, 8);
    if (*e) vcall<void>(*e, 0, 1u);
  }
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); ++i) {
    void **e = (void **)(self + 0x10) + i;
    vcall<void>(*e, 8);
    if (*e) vcall<void>(*e, 0, 1u);
  }
  for (u32 i = 0; i < *(u32 *)(self + 0x60); ++i) {
    void **e = (void **)(self + 0x20) + i;
    vcall<void>(*e, 8);
    if (*e) vcall<void>(*e, 0, 1u);
  }
}
PCREG(436260, release3Arrays);
