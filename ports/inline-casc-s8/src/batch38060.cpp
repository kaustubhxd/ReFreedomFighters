// batch38060.cpp - cascade s8 batch 38060: 0x562e90 (leave a menu page: reset the page object, re-register hot keys, close helpers).
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)
#define TABLE (*(u8 **)(ENG + 0x9b))
#define U32F(off) (*(u32 *)(self + (off)))
#define UNAL(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 *parent(u8 *self) { return (u8 *)SLOT(self, 0x84, v0_t)(self); }
// the embedded object at p + 0xcb: its vtable pointer is stored (unaligned) at that address
static u32 emb_count(u8 *p) {
  u8 *e = p + 0xcb;
  return SLOT(e, 0x14, v0_t)(e);
}

// 0x562e90, thiscall(a, b) ret 8, returns false. parent = slot 0x84(): parent slot 0x30c(0); when b (low byte) is set sends (a, b) to this[0x44] slot 0x2dc, clears +0x88, tells this[0xf8] (slot 0x214 with +0xf0)
// and sets +0xdc = 3; slot 0x68(0x10, 0); if the parent's embedded list (at +0xcb, slot 0x14) is empty re-initialises the parent (slots 0x114(0x10), its +0x6f object slot 0x254, 0x30c(0)); if it is still empty,
// registers the four hot keys from the global table at [0x7003b8] + 0x2c3d (this[0x44] slot 0x130 with the name id from table slot 0x114) and resets the helpers (this[0x94]+0x1329b, table slot 0xb4, config
// slot 0x138, own slot 0xc4); finally either switches the page object this[0x94] (flag +0x1041: parent slot 0x25c(0x6a6628) then 0x25c of the result with 0x6a665c when this[0x44]'s name equals 0x6a6644, else
// 0x6a663c, its slot 0xbc(1)) or hides this[0xfc] (slot 0xbc(1)).
static u32 THISCALL fn562e90(u8 *self, u32 a, u32 b) {
  u8 *p = parent(self);
  SLOT(p, 0x30c, v1_t)(p, 0);
  if ((u8)b) {
    u8 *o = *(u8 **)(self + 0x44);
    self[0x88] = 0;
    SLOT(o, 0x2dc, v2_t)(o, a, b);
    u8 *x = *(u8 **)(self + 0xf8);
    if (x) SLOT(x, 0x214, v1_t)(x, U32F(0xf0));
    U32F(0xdc) = 3;
  }
  SLOT(self, 0x68, v2_t)(self, 0x10, 0);
  p = parent(self);
  if (emb_count(p) == 0) {
    p = parent(self);
    SLOT(p, 0x114, v1_t)(p, 0x10);
    p = parent(self);
    u8 *q = *(u8 **)(p + 0x6f);
    SLOT(q, 0x254, v0_t)(q);
    p = parent(self);
    SLOT(p, 0x30c, v1_t)(p, 0);
  }
  p = parent(self);
  if (emb_count(p) == 0) {
    for (u32 k = 0; k < 4; k++) {
      u32 v = *(u32 *)(G(u8 *, 0x7003b8) + k * 4 + 0x2c3d);
      if (v) {
        u8 *o = *(u8 **)(self + 0x44);
        u8 **vt = *(u8 ***)o;
        u8 *t = TABLE;
        u16 id = (u16)SLOT(t, 0x114, v4_t)(t, 0x6a666c, 0, 0x6a64b4, 0x230);
        ((v3_t)vt[0x130 / 4])(o, v, id, 0);
      }
    }
    u8 *pg = *(u8 **)(self + 0x94);
    if (pg) *(u32 *)(pg + 0x1329b) = 0;
    u8 *t = TABLE;
    SLOT(t, 0xb4, v1_t)(t, 0);
    u8 *cfg = *(u8 **)(ENG + 0x1a9f);
    if (cfg) SLOT(cfg, 0x138, v1_t)(cfg, 0);
    SLOT(self, 0xc4, v1_t)(self, 0);
  }
  u8 *pg = *(u8 **)(self + 0x94);
  if (pg && pg[0x1041]) {
    p = parent(self);
    u8 *r = (u8 *)SLOT(p, 0x25c, v2_t)(p, 0x6a6628, 0);
    if (!r) return 0;
    const u8 *nm = (const u8 *)0x67c8e8;
    u8 *o44 = *(u8 **)(self + 0x44);
    if (*(u32 *)(o44 + 4)) nm = *(const u8 **)(o44 + 4);
    const u8 *ref = (const u8 *)0x6a6644;
    bool eq = true;
    for (u32 i = 0;; i++) {
      if (nm[i] != ref[i]) {
        eq = false;
        break;
      }
      if (nm[i] == 0) break;
    }
    u8 *s = (u8 *)SLOT(r, 0x25c, v2_t)(r, eq ? 0x6a665c : 0x6a663c, 0);
    if (!s) return 0;
    SLOT(s, 0xbc, v1_t)(s, 1);
    return 0;
  }
  u8 *h = *(u8 **)(self + 0xfc);
  if (h) SLOT(h, 0xbc, v1_t)(h, 1);
  return 0;
}
PCREG(562e90, fn562e90);
