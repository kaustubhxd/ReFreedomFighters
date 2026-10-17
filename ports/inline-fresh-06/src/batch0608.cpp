// batch0608.cpp - fresh-06 batch 8 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

extern "C" void *ext_41e290(u32 n);                  // __builtin_new (cdecl)
extern "C" void ext_4690b0(void *p, u32 sz);         // sized pool free (cdecl, GUESS)
extern "C" void THISCALL ext_469870(void *self);
extern "C" void *THISCALL ext_4ccbe0(void *self, s32 a, s32 b);   // REFTAB::REFTAB(int, int)
static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}
// addss with the operand order of the original (destination first: decides which NaN comes out)
static inline float addss(float a, float b) {
  asm("addss %1, %0" : "+x"(a) : "x"(b));
  return a;
}

// 0x4422e0, ZTreeGroup::AttachDynamicGeoms(ZBaseGeom*): the mirror of DetachDynamicGeoms (0x442e20) with own slot
// 0x2f0 for each child; a geom other than +8 with flag 0x40000 and without bit 10 (+0x3c) is attached to its dynamic
// container.
extern "C" u8 THISCALL ext_4db9a0(void *g, u32 cls);
extern "C" void THISCALL ext_4d9ce0(void *g);
static void THISCALL treeAttachDynGeoms(u8 *self, u8 *g) {
  u8 *p = *(u8 **)(g + 0x54);
  u32 t = p ? *(u32 *)(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
  if (t & 0x100000) {
    if (ext_4db9a0(g, 0x100020)) {
      if (vcall<u8>(p, 0x310)) return;
      if (vcall<u8>(p, 0x30c) && g != *(u8 **)(self + 8)) return;
    }
    for (u8 *q = *(u8 **)(p + 0x50); q; q = *(u8 **)(q + 0x60)) vcall<void>(self, 0x2f0, q);
  }
  if (g == *(u8 **)(self + 8)) return;
  u32 f = *(u32 *)(g + 0x3c);
  if (!((f >> 10) & 1) && (f & 0x40000)) ext_4d9ce0(g);
}
PCREG(4422e0, treeAttachDynGeoms);

// 0x45ab60, ZPICOBJ::ReadGlobalPixel(const float*, int*): the point is copied, made local by own slot 0x8c, then x
// and y map to texture space: (half + v) / (half + half) with the half sizes at geom (+8) +0x40 / +0x44; own slot
// 0x214(point, out) reads the pixel. Returns its EAX.
static u32 THISCALL picReadGlobalPixel(u8 *self, const float *p, s32 *out) {
  float v[3] = {p[0], p[1], p[2]};
  vcall<void>(self, 0x8c, v);
  u8 *g = *(u8 **)(self + 8);
  float h = *(float *)(g + 0x40);
  v[0] = addss(h, v[0]) / addss(h, h);
  h = *(float *)(g + 0x44);
  v[1] = addss(h, v[1]) / addss(h, h);
  return vcall<u32>(self, 0x214, v, out);
}
PCREG(45ab60, picReadGlobalPixel);

// 0x57f360 (no map name; GUESS: apply a volume slider): the sound manager (engine slot 0xbc) gets the level (+0x188,
// slot 0xac); the slider (+0x180) gets trunc(level * 20) (slot 0x36c, with 1); own slot 0x84's object gets the level
// (slot 0x314); 0x57f6b0; the sound manager's slot 0xbc gets byte +0x18c; then CNewMenu::GetButton (0x57f750, tail).
extern "C" void THISCALL ext_57f6b0(void *self);
extern "C" u32 THISCALL ext_57f750(void *self);
static u32 THISCALL applyVolume(u8 *self) {
  void *sm = vcall<void *>(G(void *, 0x70039c), 0xbc);
  vcall<void>(sm, 0xac, *(u32 *)(self + 0x188));
  s32 n = _mm_cvttss_si32(_mm_mul_ss(_mm_set_ss(*(float *)(self + 0x188)), _mm_set_ss(20.0f)));   // 0x67da20 = 20.0
  vcall<void>(*(void **)(self + 0x180), 0x36c, n, 1u);
  void *o = vcall<void *>(self, 0x84);
  vcall<void>(o, 0x314, *(u32 *)(self + 0x188));
  ext_57f6b0(self);
  void *sm2 = vcall<void *>(G(void *, 0x70039c), 0xbc);
  vcall<void>(sm2, 0xbc, (u32)self[0x18c]);
  return ext_57f750(self);
}
PCREG(57f360, applyVolume);

// 0x4f7960 (no map name; GUESS: constructor, vtable 0x69ae94): base 0x4f97f0(a, b, c); +0x8f = 0, +0x93 = 1, +0x9f,
// +0xab, +0xaf = 0; REFTAB(4, 0) at +0xb3; byte +0xd3 = 0. Returns this.
extern "C" void THISCALL ext_4f97f0(void *self, u32 a, u32 b, u32 c);
static void *THISCALL ctor69ae94(u8 *self, u32 a, u32 b, u32 c) {
  ext_4f97f0(self, a, b, c);
  *(u32 *)self = 0x69ae94;
  *(u32 *)(self + 0x8f) = 0;
  *(u32 *)(self + 0x93) = 1;
  *(u32 *)(self + 0x9f) = 0;
  *(u32 *)(self + 0xab) = 0;
  *(u32 *)(self + 0xaf) = 0;
  ext_4ccbe0(self + 0xb3, 4, 0);
  self[0xd3] = 0;
  return self;
}
PCREG(4f7960, ctor69ae94);

// 0x4c38e0 (no map name; GUESS: constructor, vtable 0x693fc8): 0x469870, flag 0x20 at +4, +0x44 = 0, +0x7e = 0,
// +0x8a = 0 (written a second time unless it is the address of a stack local, which a heap object never is);
// RegisterZMsg (0x68fee8, 0, 0x69404c, 0x58) to word 0x700348. Returns this.
static void *THISCALL ctor693fc8(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x693fc8;
  *(u32 *)(self + 0x7e) = 0;
  *(u32 *)(self + 0x8a) = 0;
  G(u16, 0x700348) = vcall<u16>(rmgr(), 0x114, 0x68fee8u, 0u, 0x69404cu, 0x58u);
  return self;
}
PCREG(4c38e0, ctor693fc8);

// 0x49c420 (no map name; GUESS: resolve tagged pointers in a chain, stdcall (node, unused)): for each node (next
// +0xc), each of the three words at +0/+4/+8 with a pointer part (bits 3..31) is replaced by the render manager's
// slot 0x54((ptr + 0x60) | 0x40000000), keeping its low 3 tag bits.
static void STDCALL resolveTagged(u32 *n, u32) {
  while (n) {
    for (int k = 0; k < 3; ++k) {
      u32 v = n[k];
      u32 m = v & 0xfffffff8u;
      if (m) n[k] = vcall<u32>(rmgr(), 0x54, (m + 0x60) | 0x40000000u) | (v & 7);
    }
    n = (u32 *)n[3];
  }
}
PCREG(49c420, resolveTagged);

// 0x54b420 (no map name; GUESS: create the 0x54-byte child, vtable 0x6a383c): new + 0x54cb50 + fields; stored at
// +0x8049; its slot 0x3c gets [+0xa278]; its +8 = this; returns its slot 0x10 result as a bool.
extern "C" void THISCALL ext_54cb50(void *self);
static u8 THISCALL createChild6a383c(u8 *self) {
  u8 *o = (u8 *)ext_41e290(0x54);
  if (o) {
    ext_54cb50(o);
    *(u32 *)o = 0x6a383c;
    *(u32 *)(o + 0x50) = 0;
    *(u32 *)(o + 0x44) = 0;
    *(u32 *)(o + 0x4c) = 0;
  }
  u32 a = *(u32 *)(self + 0xa278);
  *(u8 **)(self + 0x8049) = o;
  vcall<void>(o, 0x3c, a);
  *(u8 **)(o + 8) = self;
  return vcall<u8>(o, 0x10) != 0;
}
PCREG(54b420, createChild6a383c);

// 0x4c32a0 (no map name; GUESS: constructor, vtable 0x693e3c): 0x469870, flag 0x20 at +4, +0x44 = 0; a new REFTAB(0x20,
// 0) at +0x48 (0 when the allocation fails); +0x4c = 0, +0x50 = 10.0, +0x54 = 0, +0x5c = 1.0, +0x58 = 0. Returns this.
static void *THISCALL ctor693e3c(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x693e3c;
  void *p = ext_41e290(0x1c);
  *(void **)(self + 0x48) = p ? ext_4ccbe0(p, 0x20, 0) : 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x50) = 0x41200000u;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x5c) = 0x3f800000u;
  *(u32 *)(self + 0x58) = 0;
  return self;
}
PCREG(4c32a0, ctor693e3c);

// 0x638d60 (no map name; GUESS: blit an 8-bit paletted rect to 32-bit): own slot 0x38(id) gives the texture (width
// +4, height +8, pixels +0x10); a size different from (w, h) calls the handler (int3 when none; not exercised). Rows
// start at pixels + x0 + y0 * width; each of h rows (when h > 0) writes w (when w > 0) palette entries ([+0x2d]) to
// dst, which steps by the stride in bytes.
static void THISCALL blitPal8(u8 *self, u32 *dst, u32 x0, u32 y0, s32 w, s32 h, s32 stride, u32 id) {
  u8 *t = vcall<u8 *>(self, 0x38, id);
  if (*(s32 *)(t + 4) != w) handlerCall();
  if (*(s32 *)(t + 8) != h) handlerCall();
  u32 row = *(u32 *)(t + 4) * y0 + x0;
  u8 *px = *(u8 **)(t + 0x10);
  if (h <= 0) return;
  do {
    if (w > 0) {
      u8 *s = px + row;
      for (s32 i = 0; i < w; ++i) dst[i] = (*(u32 **)(self + 0x2d))[s[i]];
    }
    dst = (u32 *)((u8 *)dst + stride);
    row += *(u32 *)(t + 4);
  } while (--h);
}
PCREG(638d60, blitPal8);

// 0x64d9e0, ZDrawArray<ZPrimDrawEntry,...>::Remove(ZPrimDrawEntry*): count +0xc drops; the entry's block (own slot
// 0x2c) gets the entry back on its free list (entry word = old head, head = entry index, 20-byte entries from +0x10),
// flag 2 of entry +5 cleared, block use count (byte +0) drops. An empty block leaves the ring (the current block
// pointer +8 moves on, or to null when it was alone) and is released (own slot 0x34); a non-empty one other than the
// current block is moved in front of it and becomes current.
static void THISCALL primDrawArrayRemove(u8 *self, u8 *e) {
  --*(u32 *)(self + 0xc);
  u8 *b = vcall<u8 *>(self, 0x2c, e);
  e[5] &= 0xfd;
  u16 old = *(u16 *)(b + 2);
  --b[0];
  *(u16 *)e = old;
  *(u16 *)(b + 2) = (u16)((s32)(e - b - 0x10) / 20);
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
  u8 *h = *(u8 **)(self + 8);
  *(u8 **)(b + 8) = h;
  u8 *t = *(u8 **)(h + 0xc);
  *(u8 **)(b + 0xc) = t;
  *(u8 **)(t + 8) = b;
  *(u8 **)(h + 0xc) = b;
  *(u8 **)(self + 8) = b;
}
PCREG(64d9e0, primDrawArrayRemove);

// 0x49c560, CListUser::DisconnectFromAllMembers(void*): the members of the geom's list id (+0x68) come from
// PriUnfoldList(+0x39 array, id) (count = high + low word); each is flagged (0x1000000 at +0x3c) and tracked down in the
// dynamic list, and when that returns bit 0, in the static list (both with (member id, geom, true)). Then the id's
// chain at [+0x1d] + id*4 is freed (CMemPool::DeAlloc on +4, next at +0xc), its slot cleared and the next slot set to
// 1; the geom is flagged too.
extern "C" u32 THISCALL ext_49c980(void *self, u32 *arr, u32 id);
extern "C" u8 THISCALL ext_49cbb0(void *self, u32 id, void *g, u32 b);
extern "C" u8 THISCALL ext_49ccc0(void *self, u32 id, void *g, u32 b);
extern "C" void THISCALL ext_4e6bf0(void *pool, void *p);
static void THISCALL listUserDisconnectAll(u8 *self, u8 *g) {
  u32 id = *(u32 *)(g + 0x68);
  u32 r = ext_49c980(self, *(u32 **)(self + 0x39), id);
  u32 n = (r >> 16) + (r & 0xffff);
  for (u32 i = 0; i < n; ++i) {
    u8 *m = (*(u8 ***)(self + 0x39))[i];
    *(u32 *)(m + 0x3c) |= 0x1000000;
    u32 mid = *(u32 *)(m + 0x68);
    if (ext_49cbb0(self, mid, g, 1) & 1) ext_49ccc0(self, mid, g, 1);
  }
  u32 *slot = *(u32 **)(self + 0x1d) + id;
  u8 *e = (u8 *)slot[0];
  slot[1] = 1;
  while (e) {
    u8 *nx = *(u8 **)(e + 0xc);
    ext_4e6bf0(self + 4, e);
    e = nx;
  }
  slot[0] = 0;
  *(u32 *)(g + 0x3c) |= 0x1000000;
}
PCREG(49c560, listUserDisconnectAll);

// 0x4be520, CLensFlare deleting destructor: +0x44/+0x30 cleared, base vtable 0x686874, unregistered (render manager
// slot 0x34); flags bit 0: bit 2 -> 0x4690b0(this, 0x6a), else the error handler (int3 when none; not exercised).
// Returns this.
static void *THISCALL lensFlareDelDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(rmgr(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x6a);
    else handlerCall();
  }
  return self;
}
PCREG(4be520, lensFlareDelDtor);
