// batch36001.cpp - cascade s4 batch 36001: 0x436260, 0x444fe0, 0x4531e0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);

// 0x436260, thiscall(no args): three loops over pointer arrays (this+4 count [0xc], this+0x10 count [0x1c], this+0x20 count [0x60]):
// o->slot 8(); then o = array[i] again; if o: o->slot 0(1) (scalar deleting dtor). Counts re-read each pass.
static void THISCALL fn436260(u8 *self) {
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) {
    void *o = *(void **)(self + 4 + 4 * i);
    (*(v0_t **)o)[8 / 4](o);
    o = *(void **)(self + 4 + 4 * i);
    if (o) (*(v1_t **)o)[0](o, 1);
  }
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) {
    void *o = *(void **)(self + 0x10 + 4 * i);
    (*(v0_t **)o)[8 / 4](o);
    o = *(void **)(self + 0x10 + 4 * i);
    if (o) (*(v1_t **)o)[0](o, 1);
  }
  for (u32 i = 0; i < *(u32 *)(self + 0x60); i++) {
    void *o = *(void **)(self + 0x20 + 4 * i);
    (*(v0_t **)o)[8 / 4](o);
    o = *(void **)(self + 0x20 + 4 * i);
    if (o) (*(v1_t **)o)[0](o, 1);
  }
}
PCREG(436260, fn436260);

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);  // ret 8

// 0x444fe0, thiscall(a) ret 4: if p = this[0xa4]: p->slot 0x3c(a); if p->slot 0x14() != 0 return; delete p (slot 0, flag 1); this[0xa4] = 0;
// walk c = this[0x50] (chain through c[0x60]) while the flags of c ([0x54] ? [[0x54]+0xc][0x23] : 0x200002) have bit 0x100000: return when c[0x3c] & 0x400000;
// then loop: if !this->slot 0x1e0(0x100021) or this[0xa4] return; 0x4dc630(this[8], 0, 0x400000); this = this->slot 0x20(); stop when null.
static void THISCALL fn444fe0(u8 *self, u32 a) {
  u8 *p = *(u8 **)(self + 0xa4);
  if (!p) return;
  (*(v1_t **)p)[0x3c / 4](p, a);
  p = *(u8 **)(self + 0xa4);
  if ((*(v0r_t **)p)[0x14 / 4](p) != 0) return;
  p = *(u8 **)(self + 0xa4);
  if (p) (*(v1_t **)p)[0](p, 1);
  *(u32 *)(self + 0xa4) = 0;
  u8 *c = *(u8 **)(self + 0x50);
  while (c) {
    u8 *w = *(u8 **)(c + 0x54);
    u32 fl = w ? *(u32 *)(*(u8 **)(w + 0xc) + 0x23) : 0x200002u;
    if (!(fl & 0x100000u)) break;
    if (*(u32 *)(c + 0x3c) & 0x400000u) return;
    c = *(u8 **)(c + 0x60);
  }
  for (;;) {
    if (!(*(v1b_t **)self)[0x1e0 / 4](self, 0x100021u)) return;
    if (*(u32 *)(self + 0xa4) != 0) return;
    ext_4dc630(*(void **)(self + 8), 0, 0x400000u);
    self = (*(v0o_t **)self)[0x20 / 4](self);
    if (!self) return;
  }
}
PCREG(444fe0, fn444fe0);

extern "C" void STDCALL ext_610100(void *a);                                   // ret 4
extern "C" void THISCALL ext_4e13c0(void *self, void *out, u32 n);             // ret 8
extern "C" void THISCALL ext_4e11e0(void *self, u32 *out, u32 n);              // ret 8
extern "C" void THISCALL ext_4e12f0(void *self, void *out, u32 n);             // ret 8
extern "C" void THISCALL ext_4e12e0(void *self, void *out, u32 n);             // ret 8 (tail jump to 4e11e0)
extern "C" void THISCALL ext_4e1b30(void *self);                               // plain ret

// 0x4531e0, thiscall(s) ret 4: this = edi, s = esi. 0x610100(s); this[0x5b] = 0; s.read(&tmp, 1) via 4e13c0; v = 4e11e0(s, 1) three times
// into this[0x61], this[0x60], this[0x5b] as (v != 0); 4e12f0(s, this+0x22, 0xc); 4e12e0(s, this+0x5c, 1); 4e1b30(s);
// this[0x56] (unaligned dword) = 0x41200000; 0x4dc630(this[8], 0, 0x13).
static void THISCALL fn4531e0(u8 *self, u8 *s) {
  u32 loc[2];
  u32 v;
  ext_610100(s);
  self[0x5b] = 0;
  ext_4e13c0(s, loc, 1);
  ext_4e11e0(s, &v, 1);
  self[0x61] = (v != 0);
  ext_4e11e0(s, &v, 1);
  self[0x60] = (v != 0);
  ext_4e11e0(s, &v, 1);
  self[0x5b] = (v != 0);
  ext_4e12f0(s, self + 0x22, 0xc);
  ext_4e12e0(s, self + 0x5c, 1);
  ext_4e1b30(s);
  self[0x56] = 0x00; self[0x57] = 0x00; self[0x58] = 0x20; self[0x59] = 0x41;
  ext_4dc630(*(void **)(self + 8), 0, 0x13);
}
PCREG(4531e0, fn4531e0);
