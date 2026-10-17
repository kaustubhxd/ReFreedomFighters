// batch0112.cpp - fresh-01 batch 12 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void ext_4690b0(void *p, u32 size);                       // empty cdecl body (sized delete)
extern "C" void *ext_41e290(u32 size);                               // operator new
extern "C" u32 THISCALL ext_4ccbe0(u8 *p, u32 a, u32 b);             // REFTAB::REFTAB(int, int)
extern "C" void THISCALL ext_442050(u8 *self, u8 *child);            // ZTreeGroup::AddStaticChildTreeGroup
extern "C" void THISCALL ext_441e40(u8 *self, u8 *child);            // ZTreeGroup::AddDynamicChildTreeGroup
extern "C" void FASTCALL ext_633654(u32 cookie);                     // __security_check_cookie
extern "C" u32 *THISCALL ext_5003d0(u32 arr, u32 i);                 // array element pointer (checked)
extern "C" u32 THISCALL ext_506040(u32 *e);                          // script value -> handle
extern "C" u32 THISCALL ext_5002f0(u32 *e, u32 v);                   // script value set
extern "C" void THISCALL ext_43de40(u8 *self, u32 info, u32 name, u32 parent);  // ZSTDOBJ::ZSTDOBJ
extern "C" void THISCALL ext_4dc630(u32 geom, u32 a, u32 b);         // ZBaseGeom::SetControl
extern "C" void THISCALL ext_51a960(u8 *p, u32 a, u32 b);            // base constructor
extern "C" void THISCALL ext_51b530(u8 *p);                          // one-time class setup

typedef void (*handlerFn)();
typedef u32(THISCALL *s20Fn)(void *, u32, u32);
typedef void (*log3Fn)(void *, u32, u32);

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x57f1d0 (unnamed window, scalar deleting destructor): as 0x57bad0 with the size 0x18d: +0x44 = +0x30 = 0, vtable
// 0x686874, render slot 0x34(this); flag 1: flag 4 -> 0x4690b0(this, 0x18d), else the handler (int3 when unset).
static u8 *THISCALL windowScalarDelete57f1d0(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(render(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x18d);
    } else {
      handlerFn h = G(handlerFn, 0x7003b0);
      if (!h) __builtin_debugtrap();
      h();
    }
  }
  return self;
}
PCREG(57f1d0, windowScalarDelete57f1d0);

// 0x441d90, ZTreeGroup::AddChildTreeGroup(ZTreeGroup*): creates the child table (+0x77) on first use (new(0x1c),
// REFTAB(4, 0); 0 when new fails), adds the child (table slot 4), then AddStatic/AddDynamicChildTreeGroup when the
// child's slot 0x308 / 0x30c say so.
static void THISCALL treeGroupAddChild(u8 *self, u8 *child) {
  if (*(u32 *)(self + 0x77) == 0) {
    u8 *p = (u8 *)ext_41e290(0x1c);
    *(u32 *)(self + 0x77) = p ? ext_4ccbe0(p, 4, 0) : 0;
  }
  vcall<void>(*(u8 **)(self + 0x77), 4, child);
  if (vcall<u8>(child, 0x308)) ext_442050(self, child);
  if (vcall<u8>(child, 0x30c)) ext_441e40(self, child);
}
PCREG(441d90, treeGroupAddChild);

// 0x570310, CSewerMenu::ClearStats(): unless +0x1a3 is set: each of the +0x22c text items at +0x1cc gets slot
// 0x284(0x677b5a) and slot 0xbc(1); +0x230 = 0; the two items at +0x1c0 get slot 0x70(&{0, 12.0, 0}); +0x234 = 0.
static void THISCALL sewerMenuClearStats(u8 *self) {
  if (self[0x1a3] == 0) {
    for (u32 i = 0; i < *(u32 *)(self + 0x22c); i++) {
      u8 *o = ((u8 **)(self + 0x1cc))[i];
      vcall<void>(o, 0x284, 0x677b5au);
      vcall<void>(((u8 **)(self + 0x1cc))[i], 0xbc, 1u);
    }
    *(u32 *)(self + 0x230) = 0;
    u32 v[3] = {0, 0x41400000, 0};
    for (u32 k = 0; k < 2; k++) vcall<void>(((u8 **)(self + 0x1c0))[k], 0x70, (u32 *)v);
    *(u32 *)(self + 0x234) = 0;
  }
  ext_633654(G(u32, 0x6f5630));
}
PCREG(570310, sewerMenuClearStats);

// 0x511090 (unnamed script native): with the engine object at +0x1a9f: r = obj slot 0x6c(0x506040(arg 0 of p+4)) (the
// vtable read before the argument), and the result slot (p+8 element 0) gets r with type 1 unless its type byte is
// above 1 (then a log and the handler, int3 when unset). Without that object: 0x5002f0(p+8 element 0, 0).
static void THISCALL native511090(u8 *self, u8 *p) {
  u8 *s = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
  if (!s) {
    u32 *e = ext_5003d0(*(u32 *)(p + 8), 0);
    ext_5002f0(e, 0);
    return;
  }
  u8 *vt = *(u8 **)s;
  u32 *e = ext_5003d0(*(u32 *)(p + 4), 0);
  u32 v = ext_506040(e);
  typedef u32(THISCALL * f6c)(void *, u32);
  u32 r = (*(f6c *)(vt + 0x6c))(*(u8 **)(G(u8 *, 0x70039c) + 0x1a9f), v);
  u8 *o = (u8 *)ext_5003d0(*(u32 *)(p + 8), 0);
  if (o[4] <= 1) {
    *(u32 *)o = r;
    o[4] = 1;
    return;
  }
  u8 *mgr = G(u8 *, 0x700390);
  u8 *l = (u8 *)(*(s20Fn *)(*(u8 **)mgr + 0x20))(mgr, 0x69c8e0, 0xc4);
  (*(log3Fn *)(*(u8 **)l + 0x2c))(l, 0x69c6b0, 0x69c938);
  handlerFn h = G(handlerFn, 0x7003b0);
  if (!h) __builtin_debugtrap();
  h();
}
PCREG(511090, native511090);

// 0x43e190, ZHELPER::ZHELPER(ZGEOMCLASSINFO*, const char*, ZBaseGeom*): ZSTDOBJ, vtable 0x67c5c4, +0x44 = +0x18 = +0x34
// = 0, floats +0x28, +0x2c, +0x30, +0x1c, +0x20, +0x24 = 1.0, colours +0x3c = 0xe53333, +0x40 = 0xe5e5e5, SetControl(0x40000,
// 0) on the geom at +8. Returns this.
static u8 *THISCALL helperCtor(u8 *self, u32 info, u32 name, u32 parent) {
  ext_43de40(self, info, name, parent);
  *(u32 *)self = 0x67c5c4;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x28) = 0x3f800000;
  *(u32 *)(self + 0x2c) = 0x3f800000;
  *(u32 *)(self + 0x30) = 0x3f800000;
  *(u32 *)(self + 0x1c) = 0x3f800000;
  *(u32 *)(self + 0x20) = 0x3f800000;
  *(u32 *)(self + 0x24) = 0x3f800000;
  *(u32 *)(self + 0x3c) = 0xe53333;
  *(u32 *)(self + 0x40) = 0xe5e5e5;
  ext_4dc630(*(u32 *)(self + 8), 0x40000, 0);
  return self;
}
PCREG(43e190, helperCtor);

// 0x51b6d0 (unnamed factory, fastcall a, b): p = new(0x20) (0 on failure); constructor 0x51a960(p; a, b), vtable
// 0x69f43c, one-time setup 0x51b530 while [0x701800] is 0; p+0x1c = render slot 0x58(id) with id from (a+0x15) slot
// 0x40(&id). Returns p.
static u8 *FASTCALL factory51b6d0(u8 *a, u32 b) {
  u8 *p = (u8 *)ext_41e290(0x20);
  if (!p) return 0;
  ext_51a960(p, (u32)a, b);
  *(u32 *)p = 0x69f43c;
  if (G(u32, 0x701800) == 0) ext_51b530(p);
  u32 id;
  vcall<void>(*(u8 **)(a + 0x15), 0x40, &id);
  *(u32 *)(p + 0x1c) = vcall<u32>(render(), 0x58, id);
  return p;
}
PCREG(51b6d0, factory51b6d0);
