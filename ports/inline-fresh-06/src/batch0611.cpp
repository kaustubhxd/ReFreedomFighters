// batch0611.cpp - fresh-06 batch 11 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
static inline bool streq(const u8 *a, const u8 *b) {
  for (;; ++a, ++b) {
    if (*a != *b) return false;
    if (!*a) return true;
  }
}

// 0x576260, ZSubZoneMap::Init(): CBaseWindow::Init; when the map name (+0x94 -> +0x48) is 0x6a6e5c with byte +0x1040
// clear, or is 0x6a8558, the render manager's object (slot 0x138) gets slot 0x60(0x6a6db0, render manager slot
// 0x4c(+0x44), 0x10). (MSVC pushes the 0x10 before slot 0x4c's argument; slot 0x4c pops one word.)
extern "C" void THISCALL ext_562440(void *self);
static void THISCALL subZoneMapInit(u8 *self) {
  ext_562440(self);
  u8 *m = *(u8 **)(self + 0x94);
  const u8 *nm = m + 0x48;
  if ((streq(nm, (const u8 *)0x6a6e5c) && m[0x1040] == 0) || streq(nm, (const u8 *)0x6a8558)) {
    void *o = vcall<void *>(rmgr(), 0x138);
    u32 v = vcall<u32>(rmgr(), 0x4c, *(u32 *)(self + 0x44));
    vcall<void>(o, 0x60, 0x6a6db0u, v, 0x10u);
  }
}
PCREG(576260, subZoneMapInit);

// 0x444fe0, ZROOM::RemoveGate(unsigned): the gate list (+0xa4) drops the id (slot 0x3c); when it is then empty (slot
// 0x14 == 0) it is deleted (slot 0 with 1) and cleared. Unless a child (+0x50 chain via +0x60, while its type flags
// have 0x100000) has control flag 0x400000 at +0x3c, the room and its parents (own slot 0x20) each, while own slot
// 0x1e0(0x100021) is true and the room has no gate list, get SetControl(0, 0x400000) on their geom (+8).
extern "C" void THISCALL ext_4dc630(void *g, u32 a, u32 b);
static void THISCALL roomRemoveGate(u8 *self, u32 id) {
  if (!*(void **)(self + 0xa4)) return;
  vcall<void>(*(void **)(self + 0xa4), 0x3c, id);
  if (vcall<u32>(*(void **)(self + 0xa4), 0x14)) return;
  if (*(void **)(self + 0xa4)) vcall<void>(*(void **)(self + 0xa4), 0, 1u);
  *(u32 *)(self + 0xa4) = 0;
  for (u8 *c = *(u8 **)(self + 0x50); c; c = *(u8 **)(c + 0x60)) {
    u8 *p = *(u8 **)(c + 0x54);
    u32 t = p ? *(u32 *)(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
    if (!(t & 0x100000)) break;
    if (*(u32 *)(c + 0x3c) & 0x400000) return;
  }
  u8 *r = self;
  do {
    if (!vcall<u8>(r, 0x1e0, 0x100021u)) return;
    if (*(u32 *)(r + 0xa4)) return;
    ext_4dc630(*(void **)(r + 8), 0, 0x400000);
    r = vcall<u8 *>(r, 0x20);
  } while (r);
}
PCREG(444fe0, roomRemoveGate);

// 0x658020, ZRender::~ZRender(): vtable 0x6c4004; the objects at +0x11df, +0x11db and +0x11e3 are each unregistered
// from the engine (slot 0x1a8) and deleted (slot 0 with 1) when present; +0x1143 is deleted too; then the base
// destructor 0x64f380.
extern "C" void THISCALL ext_64f380(void *self);
static void THISCALL renderDtor(u8 *self) {
  static const u32 offs[3] = {0x11df, 0x11db, 0x11e3};
  *(u32 *)self = 0x6c4004;
  for (u32 i = 0; i < 3; ++i) {
    vcall<void>(G(void *, 0x70039c), 0x1a8, *(void **)(self + offs[i]));
    void *o = *(void **)(self + offs[i]);
    if (o) vcall<void>(o, 0, 1u);
  }
  void *o = *(void **)(self + 0x1143);
  if (o) vcall<void>(o, 0, 1u);
  ext_64f380(self);
}
PCREG(658020, renderDtor);

// 0x4ee0e0 (no map name; GUESS: placement factory, fastcall: placement in ECX, first constructor argument in EDX;
// stack: two more): 0x45c4f0(0xac, placement) (cdecl); a non-null object is built by 0x4ee240(edx, a, b), gets vtable
// 0x698118, +0x93/+0x97/+0x9b/+0x9f = 0, +0xa3 = 0x40, byte +0xa7 = 0. Returns it (0 when the allocation fails).
extern "C" void *ext_45c4f0(u32 size, void *p);
extern "C" void THISCALL ext_4ee240(void *o, void *x, void *a, void *b);
static void *FASTCALL make698118(void *p, void *x, void *a, void *b) {
  u8 *o = (u8 *)ext_45c4f0(0xac, p);
  if (!o) return 0;
  ext_4ee240(o, x, a, b);
  *(u32 *)o = 0x698118;
  *(u32 *)(o + 0x97) = 0;
  *(u32 *)(o + 0x9b) = 0;
  *(u32 *)(o + 0x9f) = 0;
  *(u32 *)(o + 0x93) = 0;
  *(u32 *)(o + 0xa3) = 0x40;
  o[0xa7] = 0;
  return o;
}
PCREG(4ee0e0, make698118);

// 0x40c320 (no map name; GUESS: scale a span of floats by a table walked with a Bresenham step, cdecl (x0, x1, y0,
// y1, buf)): buf[x0] *= T[y0]; then for x0 < i < x1 the table index advances by (y1 - y0) / (x1 - x0) per element,
// one more (in the sign's direction) whenever the error sum reaches x1 - x0; buf[i] = T[k] * buf[i]. T is the float
// table at 0x6f1f58. x87 multiply kept as inline x87 (53-bit control word, single-precision store).
static inline void fmulst(float *dst, const float *a) {
  asm volatile("flds %1\n\tfmuls %0\n\tfstps %0" : "+m"(*dst) : "m"(*a));
}
static void spanScale(s32 x0, s32 x1, s32 y0, s32 y1, float *buf) {
  s32 dy = y1 - y0, dx = x1 - x0;
  s32 ady = dy < 0 ? -dy : dy;
  s32 q = dy / dx;
  s32 step = dy < 0 ? q - 1 : q + 1;
  s32 qdx = q * dx;
  s32 rem = ady - (qdx < 0 ? -qdx : qdx);
  const float *t = (const float *)0x6f1f58 + y0;
  fmulst(&buf[x0], t);
  s32 err = 0;
  for (s32 i = x0 + 1; i < x1; ++i) {
    err += rem;
    if (err >= dx) {
      err -= dx;
      t += step;
    } else {
      t += q;
    }
    fmulst(&buf[i], t);
  }
}
PCREG(40c320, spanScale);
