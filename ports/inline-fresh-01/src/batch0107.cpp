// batch0107.cpp - fresh-01 batch 7 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void THISCALL ext_561020(u8 *p);                                   // CBaseWindow::CBaseWindow
extern "C" void THISCALL ext_469870(u8 *p);                                   // shared base constructor
extern "C" u32 THISCALL ext_442c00(u8 *self, u8 *src);                        // ZTreeGroup::CopyData
extern "C" void THISCALL ext_4cbec0(u8 *s);                                   // MYSTR::~MYSTR
extern "C" void ext_634273(void *p, u32 size);                                // operator delete(void*, size)
extern "C" void THISCALL ext_43de40(u8 *self, u32 info, u32 name, u32 parent);  // ZSTDOBJ::ZSTDOBJ
extern "C" void THISCALL ext_4dcdf0(u32 geom, u32 prim);                      // ZBaseGeom::SetPrim
extern "C" u8 *THISCALL ext_440220(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);  // ZGROUP::DuplicateToResource

static u8 *allocator() { return *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 8); }

// 0x56dc50 (unnamed window factory): p = allocator slot 0x44 (the incoming ECX pushed as its stack word, GUESS as in
// batch 6); when set: CBaseWindow(), vtable 0x6a81d8. Returns p.
static u8 *THISCALL factory56dc50(u32 ecxIn) {
  u8 *p = vcall<u8 *>(allocator(), 0x44, ecxIn);
  if (p) {
    ext_561020(p);
    *(u32 *)p = 0x6a81d8;
  }
  return p;
}
PCREG(56dc50, factory56dc50);

// Factories 0x4b2bd0, 0x4f1c90, 0x5b7990, 0x5db890: p = allocator slot 0x44 (ECX pushed, GUESS); when set: base
// constructor 0x469870, flag 0x20 in +4, +0x44 = 0, then the class vtable. Returns p.
static inline u8 *factoryVt(u32 ecxIn, u32 vt) {
  u8 *p = vcall<u8 *>(allocator(), 0x44, ecxIn);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = vt;
  }
  return p;
}
static u8 *THISCALL factory4b2bd0(u32 e) { return factoryVt(e, 0x691168); }
PCREG(4b2bd0, factory4b2bd0);
static u8 *THISCALL factory4f1c90(u32 e) { return factoryVt(e, 0x698584); }
PCREG(4f1c90, factory4f1c90);
static u8 *THISCALL factory5b7990(u32 e) { return factoryVt(e, 0x6b245c); }
PCREG(5b7990, factory5b7990);
static u8 *THISCALL factory5db890(u32 e) { return factoryVt(e, 0x6b68d8); }
PCREG(5db890, factory5db890);

// 0x444310, ZROOM::CopyData(const ZGEOM*): when src is a 0x100021 (src slot 0x1e0), copies dwords +0x98, +0x94, +0x90,
// +0x8c and tells [0x70038c] slot 0xbc(this+0x90); then ZTreeGroup::CopyData(src), whose EAX is returned.
static u32 THISCALL roomCopyData(u8 *self, u8 *src) {
  if (vcall<u8>(src, 0x1e0, 0x100021u)) {
    *(u32 *)(self + 0x98) = *(u32 *)(src + 0x98);
    *(u32 *)(self + 0x94) = *(u32 *)(src + 0x94);
    *(u32 *)(self + 0x90) = *(u32 *)(src + 0x90);
    *(u32 *)(self + 0x8c) = *(u32 *)(src + 0x8c);
    vcall<void>(G(u8 *, 0x70038c), 0xbc, self + 0x90);
  }
  return ext_442c00(self, src);
}
PCREG(444310, roomCopyData);

// 0x63ead0 (unnamed, hash table serialize): for each bucket b < this+0x3408 (loop ends on !=), for each entry e in
// the chain at this[b] (next at +8): when stream slot 0x18() == 1 (save), stream slot 4(e[0]) and slot 4(e[1]); else
// (load) *(stream slot 4(e[1])) = e[0].
static void THISCALL hashSerialize(u32 *self, u8 *st) {
  u32 b = 0;
  if (self[0xd02] == 0) return;
  do {
    u32 *e = (u32 *)self[b];
    if (e) {
      do {
        typedef u32 *(THISCALL * f4)(void *, u32);
        if (vcall<u32>(st, 0x18) == 1) {
          vcall<void>(st, 4, e[0]);
          vcall<void>(st, 4, e[1]);
        } else {
          u32 *p = (*(f4 *)(*(u8 **)st + 4))(st, e[1]);
          *p = e[0];
        }
        e = (u32 *)e[2];
      } while (e);
    }
    b++;
  } while (b != self[0xd02]);
}
PCREG(63ead0, hashSerialize);

// 0x432c50 (unnamed, remove named entry): (this+0xc8) slot 0x88(key); r = (this+0xac) slot 0x84(key); when r is set:
// its string (+4) is destroyed and freed (0x80 bytes) when set, then (this+0xac) slot 0x90(key); finally the engine
// ([0x70039c]) slot 0x64(key).
static void THISCALL removeEntry432c50(u8 *self, u32 key) {
  vcall<void>(self + 0xc8, 0x88, key);
  u8 *m = self + 0xac;
  u8 *r = vcall<u8 *>(m, 0x84, key);
  if (r) {
    u8 *s = *(u8 **)(r + 4);
    if (s) {
      ext_4cbec0(s);
      ext_634273(s, 0x80);
    }
    vcall<void>(m, 0x90, key);
  }
  vcall<void>(G(u8 *, 0x70039c), 0x64, key);
}
PCREG(432c50, removeEntry432c50);

// 0x650b90, ZRender::RemoveCamera(ZCAMERA*): list = this+0x8c; when list slot 0x28(render slot 0x4c(cam)) is nonzero:
// list slot 0x3c(render slot 0x4c(cam)), then v = own slot 0xa4(0) and v slot 0xc(cam) when v is set. The list's
// vtable is read before each render call; list and render are re-read each time.
static void THISCALL renderRemoveCamera(u8 *self, u32 cam) {
  typedef u32(THISCALL * f1)(void *, u32);
  u8 *vt = **(u8 ***)(self + 0x8c);
  u32 id = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, cam);
  if (!(*(f1 *)(vt + 0x28))(*(u8 **)(self + 0x8c), id)) return;
  vt = **(u8 ***)(self + 0x8c);
  id = vcall<u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, cam);
  (*(f1 *)(vt + 0x3c))(*(u8 **)(self + 0x8c), id);
  u8 *v = vcall<u8 *>(self, 0xa4, 0u);
  if (v) vcall<void>(v, 0xc, cam);
}
PCREG(650b90, renderRemoveCamera);

// 0x648d50 (unnamed, ZArrayBlock new block): b = own slot 0x30(); false when null. b[1] = this[0x10]; n = own slot
// 0x28(); b links to itself (+8, +0xc), b[0] = 0, word +2 = 0; the free list words at b+0x10 + 0x20*i are i+1 for
// i < n-1 and 0xffff for the last; b goes into the ring before this+8 (when set) and becomes this+8. Returns true.
static u8 THISCALL arrayNewBlock(u8 *self) {
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
  u32 i = 0;
  if (last) {
    do {
      *(u16 *)d = (u16)(i + 1);
      i++;
      d += 0x20;
    } while (i != last);
  }
  *(u16 *)d = 0xffff;
  u8 *c = *(u8 **)(self + 8);
  if (c) {
    *(u8 **)(b + 8) = c;
    u8 *t = *(u8 **)(c + 0xc);
    *(u8 **)(b + 0xc) = t;
    *(u8 **)(t + 8) = b;
    *(u8 **)(c + 0xc) = b;
  }
  *(u8 **)(self + 8) = b;
  return 1;
}
PCREG(648d50, arrayNewBlock);

// 0x45ad90 (unnamed ZSTDOBJ subclass constructor): ZSTDOBJ(info, name, parent), vtable 0x683e50, floats +0x18, +0x1c,
// +0x20 = 10.0, SetPrim(0) on the geom at +8. Returns this.
static u8 *THISCALL stdObjCtor45ad90(u8 *self, u32 info, u32 name, u32 parent) {
  ext_43de40(self, info, name, parent);
  *(u32 *)self = 0x683e50;
  *(u32 *)(self + 0x18) = 0x41200000;
  *(u32 *)(self + 0x1c) = 0x41200000;
  *(u32 *)(self + 0x20) = 0x41200000;
  ext_4dcdf0(*(u32 *)(self + 8), 0);
  return self;
}
PCREG(45ad90, stdObjCtor45ad90);

// 0x4f9e90, ZScrollbar::DuplicateToResource(ZGROUP*, unsigned int, DBLK*, char*, bool): ZGROUP::DuplicateToResource,
// then copies dwords +0x8f, +0x93, +0x97, +0x9b, +0xa7, +0xab, +0xaf into the copy, which is returned.
static u8 *THISCALL scrollbarDuplicate(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u8 *r = ext_440220(self, a, b, c, d, e);
  static const u16 offs[] = {0x8f, 0x93, 0x97, 0x9b, 0xa7, 0xab, 0xaf};
  for (u32 i = 0; i < 7; i++) *(u32 *)(r + offs[i]) = *(u32 *)(self + offs[i]);
  return r;
}
PCREG(4f9e90, scrollbarDuplicate);

// 0x5a4610 (unnamed): g = render slot 0x58(arg); when g is a 0x2007f9 or a 0x2003e8 (slot 0x1e0) and
// t = [g+0x54]+4 - 3 is not -1 and t <= 6 (signed), returns this + 0x61 + t*18; else 0.
static u8 *THISCALL slot5a4610(u8 *self, u32 arg) {
  u8 *g = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, arg);
  if (!g) return 0;
  if (!vcall<u8>(g, 0x1e0, 0x2007f9u) && !vcall<u8>(g, 0x1e0, 0x2003e8u)) return 0;
  s32 t = (s32)(*(u32 *)(*(u8 **)(g + 0x54) + 4) - 3u);
  if (t == -1 || t > 6) return 0;
  return self + (u32)t * 18u + 0x61;
}
PCREG(5a4610, slot5a4610);
