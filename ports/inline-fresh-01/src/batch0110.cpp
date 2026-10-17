// batch0110.cpp - fresh-01 batch 10 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *p);                          // shared base constructor
extern "C" void THISCALL ext_4ccba0(u8 *t);                          // REFTAB32::REFTAB32
extern "C" u8 *THISCALL ext_4cfbe0(u8 *self);                        // fallback lookup
extern "C" u8 *ext_45c4f0(u32 cls, u32 where);                       // ZGEOM alloc in place (cdecl)
extern "C" u8 *ext_45c4b0(u32 cls);                                  // ZGEOM alloc (cdecl)
extern "C" u32 THISCALL ext_457030(u8 *p, u32 c, u32 a, u32 b);      // ZGEOM subclass constructor
extern "C" void THISCALL ext_4f97f0(u8 *p, u32 b, u32 c, u32 d);     // window constructor
extern "C" void ext_634273(void *p, u32 size);                       // operator delete(void*, size)
extern "C" void *ext_41e290(u32 size);                               // operator new

typedef u32(THISCALL *s20Fn)(void *, u32, u32);
typedef void (*log3Fn)(void *, u32, u32);
typedef void (*handlerFn)();

static u8 *render() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x44e590, ZBoneParticle::SaveCleanup(bool): for each bone entry e in the array at +0x20 (count +0x1c): g = render
// slot 0x58(e+0x10); when g exists: save ? g slot 0x294(this+8, e+0xc) : g slot 0x290(this+8, e+0xc, 0, 0).
static void THISCALL boneParticleSaveCleanup(u8 *self, u32 save) {
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) {
    u8 *e = (*(u8 ***)(self + 0x20))[i];
    u8 *g = vcall<u8 *>(render(), 0x58, *(u32 *)(e + 0x10));
    if (!g) continue;
    if ((u8)save) vcall<void>(g, 0x294, *(u32 *)(self + 8), *(u32 *)(e + 0xc));
    else vcall<void>(g, 0x290, *(u32 *)(self + 8), *(u32 *)(e + 0xc), 0u, 0u);
  }
}
PCREG(44e590, boneParticleSaveCleanup);

// 0x4beb10 (unnamed factory): p = allocator slot 0x44 (ECX pushed, GUESS as in batch 6); when set: base constructor
// 0x469870, +4 |= 0x20, +0x44 = 0, vtable 0x692fa0, REFTAB32 at +0x54 and +0x100. Returns p.
static u8 *THISCALL factory4beb10(u32 ecxIn) {
  u8 *a = *(u8 **)(render() + 8);
  u8 *p = vcall<u8 *>(a, 0x44, ecxIn);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = 0x692fa0;
    ext_4ccba0(p + 0x54);
    ext_4ccba0(p + 0x100);
  }
  return p;
}
PCREG(4beb10, factory4beb10);

// 0x63f610, ZDrawArray<ZArrayBlock, ...>::Remove(ZArrayBlock*): count (+0xc)--; b = own slot 0x2c(entry) (the block;
// the vtable is read before the decrement); the entry joins the block's free list (entry word = b+2 word,
// b+2 = (entry - b - 0x10) >> 12) and b's used byte drops. An empty block leaves the ring (this+8 moves on, or 0
// when it was alone) and goes to own slot 0x34; otherwise b moves to the front of the ring (before this+8).
static void THISCALL drawArrayRemove(u8 *self, u8 *entry) {
  u8 *vt = *(u8 **)self;
  --*(u32 *)(self + 0xc);
  typedef u8 *(THISCALL * f2c)(void *, u8 *);
  u8 *b = (*(f2c *)(vt + 0x2c))(self, entry);
  u16 nx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)entry = nx;
  *(u16 *)(b + 2) = (u16)((s32)((u32)entry - (u32)b - 0x10) >> 12);
  if (b[0] == 0) {
    if (*(u8 **)(self + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = n == b ? 0 : n;
    }
    *(u32 *)(*(u8 **)(b + 8) + 0xc) = *(u32 *)(b + 0xc);
    *(u32 *)(*(u8 **)(b + 0xc) + 8) = *(u32 *)(b + 8);
    vcall<void>(self, 0x34, b);
    return;
  }
  if (b == *(u8 **)(self + 8)) return;
  *(u32 *)(*(u8 **)(b + 8) + 0xc) = *(u32 *)(b + 0xc);
  *(u32 *)(*(u8 **)(b + 0xc) + 8) = *(u32 *)(b + 8);
  u8 *c = *(u8 **)(self + 8);
  *(u8 **)(b + 8) = c;
  u8 *t = *(u8 **)(c + 0xc);
  *(u8 **)(b + 0xc) = t;
  *(u8 **)(t + 8) = b;
  *(u8 **)(c + 0xc) = b;
  *(u8 **)(self + 8) = b;
}
PCREG(63f610, drawArrayRemove);

// 0x4d0590 (unnamed, buffer of at least n): r = (this+0x1cc) slot 0xc(n + 0x10, 0), else 0x4cfbe0(); when both fail:
// logs ([0x700390] slot 0x20(0x695dc0, 0x432), cdecl slot 0x2c(obj, 0x695e98, n)), [0x70038c] slot 0x78, and the
// handler at [0x7003b0] (int3 when unset) before the failure path. Failure path (also when r's capacity
// [[r+0x11]+8] < n, signed): handler (int3 when unset). Returns r.
static u8 *THISCALL buffer4d0590(u8 *self, s32 n) {
  u8 *r = vcall<u8 *>(self + 0x1cc, 0xc, (u32)n + 0x10, 0u);
  if (!r) {
    r = ext_4cfbe0(self);
    if (!r) {
      u8 *mgr = G(u8 *, 0x700390);
      u8 *l = (u8 *)(*(s20Fn *)(*(u8 **)mgr + 0x20))(mgr, 0x695dc0, 0x432);
      (*(log3Fn *)(*(u8 **)l + 0x2c))(l, 0x695e98, (u32)n);
      vcall<void>(G(u8 *, 0x70038c), 0x78);
      handlerFn h = G(handlerFn, 0x7003b0);
      if (!h) __builtin_debugtrap();
      h();
      goto fail;
    }
  }
  if (*(s32 *)(*(u8 **)(r + 0x11) + 8) >= n) return r;
fail: {
  handlerFn h = G(handlerFn, 0x7003b0);
  if (!h) __builtin_debugtrap();
  h();
  return r;
}
}
PCREG(4d0590, buffer4d0590);

// 0x457410 (unnamed geom factory, fastcall a, b; stack c, where): p = where ? 0x45c4f0(0xd9, where) : 0x45c4b0(0xd9);
// returns 0x457030(p; c, a, b) when p is set, else 0.
static u32 FASTCALL geomFactory457410(u32 a, u32 b, u32 c, u32 where) {
  u8 *p = where ? ext_45c4f0(0xd9, where) : ext_45c4b0(0xd9);
  if (!p) return 0;
  return ext_457030(p, c, a, b);
}
PCREG(457410, geomFactory457410);

// 0x4d4050 (unnamed, ring of 20 strings): the slot at +0xfb7 + idx*4 (idx = +0x10d3) is freed (delete size 1) when
// set and replaced by a new copy of s; idx advances and wraps to 0 at 20 (signed); +0x10d7 = idx.
static void THISCALL ringString4d4050(u8 *self, const char *s) {
  u32 *slot = (u32 *)(self + *(s32 *)(self + 0x10d3) * 4 + 0xfb7);
  if (*slot) ext_634273((void *)*slot, 1);
  u32 len = 0;
  while (s[len]) len++;
  void *p = ext_41e290(len + 1);
  *(void **)(self + *(s32 *)(self + 0x10d3) * 4 + 0xfb7) = p;
  char *d = *(char **)(self + *(s32 *)(self + 0x10d3) * 4 + 0xfb7);
  char ch;
  do {
    ch = *s++;
    *d++ = ch;
  } while (ch);
  ++*(s32 *)(self + 0x10d3);
  if (*(s32 *)(self + 0x10d3) >= 0x14) *(s32 *)(self + 0x10d3) = 0;
  *(u32 *)(self + 0x10d7) = *(u32 *)(self + 0x10d3);
}
PCREG(4d4050, ringString4d4050);

// 0x4f4990 (unnamed window factory, fastcall where, b; stack c, d): p = 0x45c4f0(0x97, where); when set: constructor
// 0x4f97f0(p; b, c, d), vtable 0x699924, +0x8f = 0, +0x93 = 1. Returns p (0 when the allocation fails).
static u8 *FASTCALL windowFactory4f4990(u32 where, u32 b, u32 c, u32 d) {
  u8 *p = ext_45c4f0(0x97, where);
  if (!p) return 0;
  ext_4f97f0(p, b, c, d);
  *(u32 *)p = 0x699924;
  *(u32 *)(p + 0x8f) = 0;
  *(u32 *)(p + 0x93) = 1;
  return p;
}
PCREG(4f4990, windowFactory4f4990);
