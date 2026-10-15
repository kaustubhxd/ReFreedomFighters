// batch1801.cpp - fresh-18 batch 1: small thiscall wrappers, destructors, constructors and list clears (slice 18).
// Names come from the GC name map where it has one (confidence in brackets); others are GUESS.
#include "ff.h"

#define VT(o) (*(u8 **)(o))
template <class R, class... A>
static inline R vfast(void *fnp, A... a) {
  typedef R(FASTCALL * fn)(A...);
  return ((fn)fnp)(a...);
}
static inline u8 *engineObj9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

extern "C" void THISCALL ext_54cec0(void *self);
extern "C" void THISCALL ext_650dc0(void *self, u32 a);          // ZRenderBaseDll::SetActiveAxis [low]
extern "C" void THISCALL ext_563110(void *self, u32 a, u32 b);   // CBaseWindow::OnWindowOpen [medium]
extern "C" void THISCALL ext_42bae0(void *self);
extern "C" void THISCALL ext_658020(void *self);                 // ZRender::~ZRender [low]
extern "C" void THISCALL ext_655a70(void *self);
extern "C" void THISCALL ext_564460(void *self);
extern "C" void THISCALL ext_469870(void *self);
extern "C" void ext_634273(void *p, u32 size);                    // operator delete(p, size), cdecl

// 0x54dce0 GUESS: clears global byte 0x713e19 and this+4, then calls own vtable slot 0x18.
static void THISCALL f54dce0(u8 *self) {
  G(u8, 0x713e19) = 0;
  *(u32 *)(self + 4) = 0;
  vcall<void>(self, 0x18);
}
PCREG(54dce0, f54dce0);

// 0x601a60 CHostInterface::getNameForHostEvent(unsigned int) [high]: forwards to engine object (+0x9b) slot 0x118.
static u32 THISCALL f601a60(void *, u32 ev) { return vcall<u32>(engineObj9b(), 0x118, ev); }
PCREG(601a60, f601a60);

// 0x4cbe20 ZGEOMCLASSINFO::AllocOne(const char*, ZBaseGeom*, ZGEOM*) [medium]: calls the fastcall factory at this+0x1f
// as fn(name, base, this, geom).
static u32 THISCALL f4cbe20(u8 *self, u32 name, u32 base, u32 geom) {
  return vfast<u32>(*(void **)(self + 0x1f), name, base, (u32)self, geom);
}
PCREG(4cbe20, f4cbe20);

// 0x549820 GUESS: 0x54cec0(this), then vtable slot 0x9c when byte this+0xa26d is set.
static void THISCALL f549820(u8 *self) {
  ext_54cec0(self);
  if (self[0xa26d]) vcall<void>(self, 0x9c);
}
PCREG(549820, f549820);

// 0x54c2a0 GUESS: SetActiveAxis(this, a), then this+0x50 object's slot 0x20 (a) when it exists.
static void THISCALL f54c2a0(u8 *self, u32 a) {
  ext_650dc0(self, a);
  void *o = *(void **)(self + 0x50);
  if (o) vcall<void>(o, 0x20, a);
}
PCREG(54c2a0, f54c2a0);

// 0x656f60 ZPrimControlGC::GetConvBones(unsigned int) const [medium]: slot 0xc(i), then slot 0xc(result+0x8c).
static u32 THISCALL f656f60(void *self, u32 i) {
  u8 *p = vcall<u8 *>(self, 0xc, i);
  return vcall<u32>(self, 0xc, *(u32 *)(p + 0x8c));
}
PCREG(656f60, f656f60);

// 0x57c360 ZFFAutoSave::OnWindowOpen(unsigned int, bool) [high]
static bool THISCALL f57c360(void *self, u32 a, u32 b) {
  ext_563110(self, a, b);
  vcall<void>(self, 0xf8);
  return false;
}
PCREG(57c360, f57c360);

// 0x42bf60 ZSysInterface scalar deleting destructor [low]
static void *THISCALL f42bf60(void *self, u32 flags) {
  ext_42bae0(self);
  if (flags & 1) ext_634273(self, 0x1b71);
  return self;
}
PCREG(42bf60, f42bf60);

// 0x6580e0 ZRenderGC scalar deleting destructor [medium]
static void *THISCALL f6580e0(void *self, u32 flags) {
  ext_658020(self);
  if (flags & 1) ext_634273(self, 0x11e7);
  return self;
}
PCREG(6580e0, f6580e0);

// 0x656e20 ZPrimControlGC scalar deleting destructor [medium]: vtable 0x6c3e28, then 0x655a70.
static void *THISCALL f656e20(u32 *self, u32 flags) {
  self[0] = 0x6c3e28;
  ext_655a70(self);
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(656e20, f656e20);

// 0x4e0e60 DBLK::ConvertFileName(const char*) [medium]: engine (0x70039c) slot 0x144(out, name); returns out.
static u32 THISCALL f4e0e60(void *, u32 out, u32 name) {
  vcall<void>(G(void *, 0x70039c), 0x144, out, name);
  return out;
}
PCREG(4e0e60, f4e0e60);

// 0x42c0a0 ZSysInterface::Vsprintf [high]: when slot 0x1b0 gives an object, call its slot 0x20(a).
static u32 THISCALL f42c0a0(void *self, u32 a) {
  if (!vcall<void *>(self, 0x1b0)) return 0;
  void *o = vcall<void *>(self, 0x1b0);
  return vcall<u32>(o, 0x20, a);
}
PCREG(42c0a0, f42c0a0);

// 0x57baa0 GUESS constructor: base 0x564460, vtables 0x6aa368 / 0x6aa474 (+0x180), byte +0x86 = 1.
static void *THISCALL f57baa0(u8 *self) {
  ext_564460(self);
  *(u32 *)self = 0x6aa368;
  *(u32 *)(self + 0x180) = 0x6aa474;
  self[0x86] = 1;
  return self;
}
PCREG(57baa0, f57baa0);

// 0x4bb160 GUESS constructor: base 0x469870, vtable 0x692c38.
static void *THISCALL f4bb160(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u16 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x692c38;
  *(u32 *)(self + 0x48) = 0;
  return self;
}
PCREG(4bb160, f4bb160);

// 0x63cde0 ZDrawArray<ZDrawResource,...>::Clear() [low]: removes each node (slot 0x34), next at node+8.
static void THISCALL f63cde0(u8 *self) {
  u8 *n = *(u8 **)(self + 8);
  while (n) {
    u8 *next = *(u8 **)(n + 8);
    vcall<void>(self, 0x34, n);
    if (next == *(u8 **)(self + 8)) break;
    n = next;
  }
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 8) = 0;
}
PCREG(63cde0, f63cde0);

// 0x4cdc20 STRREFTAB::Clear() [high]
static void THISCALL f4cdc20(u8 *self) {
  vcall<void>(self, 0x10);
  *(u32 *)(self + 0xc) |= 0x80000000u;
  for (u8 *n = *(u8 **)(self + 4); n;) {
    u8 *next = *(u8 **)(n + 4);
    vcall<void>(self, 0x7c, n);
    n = next;
  }
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4cdc20, f4cdc20);

// 0x657820 ZPrimControlGC::GetPrimVertAnim(unsigned int, unsigned int*, unsigned int*, unsigned int*) [medium]
static bool THISCALL f657820(void *self, u32 i, u32 *a, u32 *b, u32 *c) {
  u8 *p = vcall<u8 *>(self, 0xc, i);
  if (*(u16 *)(p + 2)) return false;
  *a = *(u32 *)(p + 0x48);
  *b = *(u32 *)(p + 0x4c);
  *c = *(u32 *)(p + 0x50);
  return true;
}
PCREG(657820, f657820);

// 0x4dfe20 GUESS: 2x2 transform of a 2-vector in place: v = (m0*v0 + m1*v1, m2*v0 + m3*v1) (v in ecx, m in edx).
static void FASTCALL f4dfe20(float *v, const float *m) {
  float x = v[0];
  v[0] = m[1] * v[1] + m[0] * x;
  v[1] = m[3] * v[1] + m[2] * x;
}
PCREG(4dfe20, f4dfe20);

// 0x6567e0 ZPrimControlBase::GetSubPrim(unsigned int, unsigned int) [high]: walks n links (+8) from prim id.
static u32 THISCALL f6567e0(void *self, u32 id, u32 n) {
  if (!id) return 0;
  for (;;) {
    u8 *p = vcall<u8 *>(self, 0xc, id);
    if (n-- == 0) return id;
    id = *(u32 *)(p + 8);
    if (!id) return 0;
  }
}
PCREG(6567e0, f6567e0);

// 0x4c3220 ZWindElement::Load(ZLoadGame*) [high]: the loader's slot 0x40 gets a pointer to the argument slot,
// which it may overwrite; the (possibly new) value goes to engine (+0x9b) slot 0x58, result stored at +0x48.
static bool THISCALL f4c3220(u8 *self, void *lg) {
  void *arg = lg;
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<void>(lg, 0x40, &arg);
  *(u32 *)(self + 0x48) = vcall<u32>(engineObj9b(), 0x58, arg);
  *(u32 *)(self + 0x4c) = 0;
  return true;
}
PCREG(4c3220, f4c3220);
