// batch0609.cpp - fresh-06 batch 9 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

extern "C" void *ext_41e290(u32 n);                  // __builtin_new (cdecl)
extern "C" void ext_4690b0(void *p, u32 sz);         // sized pool free (cdecl, GUESS)
extern "C" void THISCALL ext_469870(void *self);
static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}
// SSE ops with the original's operand order (the destination decides which NaN comes out)
static inline float addss(float a, float b) {
  asm("addss %1, %0" : "+x"(a) : "x"(b));
  return a;
}
static inline float mulss(float a, float b) {
  asm("mulss %1, %0" : "+x"(a) : "x"(b));
  return a;
}

// 0x548d60, CShatter deleting destructor: +0x44/+0x30 cleared, base vtable 0x686874, unregistered (render manager
// slot 0x34); flags bit 0: bit 2 -> 0x4690b0(this, 0x5c), else the error handler (int3 when none; not exercised).
// Returns this.
static void *THISCALL shatterDelDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(rmgr(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x5c);
    else handlerCall();
  }
  return self;
}
PCREG(548d60, shatterDelDtor);

// 0x5736a0, ZBaseMap deleting destructor: same shape, size 0x206.
static void *THISCALL baseMapDelDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(rmgr(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x206);
    else handlerCall();
  }
  return self;
}
PCREG(5736a0, baseMapDelDtor);

// 0x5d8fa0, CTVOnOff::CTVOnOff(): 0x469870, flag 0x20 at +4, +0x44 = 0, vtable 0x6b624c, +0x48 = 0; two messages
// registered with the render manager (slot 0x114: name 0x6b6300 / 0x6b630c, 0, file 0x6b62d0, line 0x16 / 0x17), ids
// stored as words at +0x50 / +0x52. Returns this.
static void *THISCALL tvOnOffCtor(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b624c;
  *(u32 *)(self + 0x48) = 0;
  *(u16 *)(self + 0x50) = (u16)vcall<u32>(rmgr(), 0x114, 0x6b6300u, 0u, 0x6b62d0u, 0x16u);
  *(u16 *)(self + 0x52) = (u16)vcall<u32>(rmgr(), 0x114, 0x6b630cu, 0u, 0x6b62d0u, 0x17u);
  return self;
}
PCREG(5d8fa0, tvOnOffCtor);

// 0x4c6360 (no map name; GUESS: constructor, vtable 0x694b1c): 0x469870, flag 0x20 at +4, +0x44 = 0, +0x4c = 0; a new
// 0x108-byte object built by 0x4d8330(0x694c2c, 0x694ba0, this + 0x48) (null when the allocation fails) goes to +0x4c
// and to the engine's slot 0x1a4. Returns this.
extern "C" void *THISCALL ext_4d8330(void *o, u32 a, u32 b, void *c);
static void *THISCALL ctor694b1c(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x694b1c;
  *(u32 *)(self + 0x4c) = 0;
  void *p = ext_41e290(0x108);
  void *o = p ? ext_4d8330(p, 0x694c2c, 0x694ba0, self + 0x48) : 0;
  *(void **)(self + 0x4c) = o;
  vcall<void>(G(void *, 0x70039c), 0x1a4, o);
  return self;
}
PCREG(4c6360, ctor694b1c);

// 0x51fbe0, ZPmv::UpdateTowerCannonDir(): SetNextTowerCannonDir; the direction controller at +0x1684 gets slot 8
// (+0x166c), and when slot 0xc says so, slot 4(+0x166c, +0x1678); a matrix is made from +0x166c (createmat, fastcall,
// third arg null). With a weapon at +0x1658: UpdateWeaponFireAndPos(weapon, +0x16d9, matrix, +0x1660, [+0x16d5] != 0,
// true).
extern "C" void THISCALL ext_51f930(void *self);
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);
extern "C" void THISCALL ext_514890(void *self, void *w, void *a, void *m, void *b, u32 f1, u32 f2);
static void THISCALL pmvUpdateTowerCannonDir(u8 *self) {
  float m[9];
  ext_51f930(self);
  u8 *ctl = self + 0x1684;
  vcall<void>(ctl, 8, self + 0x166c);
  if (vcall<u8>(ctl, 0xc)) vcall<void>(ctl, 4, self + 0x166c, self + 0x1678);
  ext_4de040(m, (const float *)(self + 0x166c), 0);
  void *w = *(void **)(self + 0x1658);
  if (w) ext_514890(self, w, self + 0x16d9, m, self + 0x1660, *(u32 *)(self + 0x16d5) != 0, 1);
}
PCREG(51fbe0, pmvUpdateTowerCannonDir);

// 0x615220, ZDrawArray<ZGeomDrawEntryGC,...>::Remove(ZGeomDrawEntry*): as 0x64d9e0 with 140-byte entries.
static void THISCALL geomDrawArrayRemove(u8 *self, u8 *e) {
  --*(u32 *)(self + 0xc);
  u8 *b = vcall<u8 *>(self, 0x2c, e);
  e[5] &= 0xfd;
  u16 old = *(u16 *)(b + 2);
  --b[0];
  *(u16 *)e = old;
  *(u16 *)(b + 2) = (u16)((s32)(e - b - 0x10) / 140);
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
PCREG(615220, geomDrawArrayRemove);

// 0x4b1320, CCutSequenceShowHide::LoadInit(DBREAD&): +0x48, +0x50 and (nonzero) byte +0x54 from three uints; a
// non-empty string is copied into the MYSTR at +0x55 through a local MYSTR.
extern "C" u32 THISCALL ext_4e5e60(void *db);
extern "C" char *THISCALL ext_4e5ea0(void *db);
extern "C" void THISCALL ext_4cbe80(void *s, const char *p);
extern "C" void THISCALL ext_4cbee0(void *s, const void *o);
extern "C" void THISCALL ext_4cbec0(void *s);
static void THISCALL showHideLoadInit(u8 *self, void *db) {
  u8 str[0x80];
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  *(u32 *)(self + 0x50) = ext_4e5e60(db);
  self[0x54] = ext_4e5e60(db) != 0;
  char *p = ext_4e5ea0(db);
  if (!p || !*p) return;
  ext_4cbe80(str, p);
  ext_4cbee0(self + 0x55, str);
  ext_4cbec0(str);
}
PCREG(4b1320, showHideLoadInit);

// 0x64f6a0, ZRender::AddCameraToView(ZCAMERA*): own slot 0xa4(0) gives a view; without one, the screen size (engine
// +0x190f slots 0xd8, 0xdc) becomes the viewport {0, 0, w, h} of view slot 0xa0(0). The camera is added to the view.
extern "C" void THISCALL ext_64dde0(void *v, u32 *vp);
extern "C" void THISCALL ext_648e50(void *v, void *cam);
static void THISCALL renderAddCameraToView(u8 *self, void *cam) {
  void *v = vcall<void *>(self, 0xa4, 0u);
  if (!v) {
    u32 vp[4];
    void *d = *(void **)(G(u8 *, 0x70039c) + 0x190f);
    u32 w = vcall<u32>(d, 0xd8);
    u32 h = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0xdc);
    vp[0] = 0;
    vp[1] = 0;
    vp[2] = w;
    vp[3] = h;
    v = vcall<void *>(self, 0xa0, 0u);
    ext_64dde0(v, vp);
  }
  ext_648e50(v, cam);
}
PCREG(64f6a0, renderAddCameraToView);

// 0x655fa0, ZPrimControlBase::CheckPointInsidePrim(unsigned id, const float *p, float r): walks the prim chain (own
// slot 0xc(id), next id at +8); a prim with a plane set (+0x24, also through slot 0xc: count, then 4-float planes)
// rejects the point when a plane's distance (p1*y + x*p0 + p2*z + p3) is above -r. True when no plane rejects it.
static u8 THISCALL primCheckPointInside(u8 *self, u32 id, const float *p, float r) {
  u32 nr = __builtin_bit_cast(u32, r) ^ 0x80000000u;
  float mr = __builtin_bit_cast(float, nr);
  while (id) {
    u8 *n = vcall<u8 *>(self, 0xc, id);
    u32 ps = *(u32 *)(n + 0x24);
    if (ps) {
      u32 *pl = vcall<u32 *>(self, 0xc, ps);
      u32 cnt = pl[0];
      const float *q = (const float *)(pl + 1);
      for (u32 i = 0; i != cnt; ++i, q += 4) {
        float d = addss(addss(addss(mulss(q[1], p[1]), mulss(p[0], q[0])), mulss(q[2], p[2])), q[3]);
        if (d > mr) return 0;
      }
    }
    id = *(u32 *)(n + 8);
  }
  return 1;
}
PCREG(655fa0, primCheckPointInside);
