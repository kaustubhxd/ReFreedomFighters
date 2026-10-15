// batch47006.cpp - cascade t8 batch 47006: 0x566650, 0x470420 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u32(THISCALL *v2r_t)(void *, u32, u32);
typedef u32(THISCALL *v3r_t)(void *, u32, u32, u32);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);

extern "C" void THISCALL ext_4711f0(void *self, u32 a, u32 b);   // ret 8

static inline u32 rd32(u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = (u8)v; p[1] = (u8)(v >> 8); p[2] = (u8)(v >> 16); p[3] = (u8)(v >> 24); }
static inline u8 *tbl_() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// object lookup: engine[0x9b]->slot 0x58(id)
static inline u8 *lookup(u32 id) {
  u8 *t = tbl_();
  return (u8 *)(*(v1r_t **)t)[0x58 / 4](t, id);
}
// reads an id by name: engine[0x9b]->slot 0x138() -> o, o->slot 0x88(name, &out); out starts 0
static inline u32 read_named(u32 name) {
  u8 *t = tbl_();
  u8 *o = (u8 *)(*(v0r_t **)t)[0x138 / 4](t);
  u32 loc = 0;
  (*(v2r_t **)o)[0x88 / 4](o, name, (u32)&loc);
  return loc;
}

// 0x566650, thiscall(), plain ret. Config reads by name through engine[0x9b] slot 0x138 / 0x88: this[0xa04] = id(0x6a5c48); this[0xa00] = id(0x6a6db0);
// this[0x180] = lookup(id(0x6a6db8)); this[0x9f4] = engine[0x9b][0xae4]->slot 0(0x6a67e8, 0x6a6dcc); this[0x44]->slot 0x130(this[0x90], word this[0x190], 0);
// unaligned dword this[0xa1f] = this[0x94] + 0x57; o = lookup(id(0x6a6dd4)); when set o->slot 0x2c(); this->slot 0x64(0x10).
static void THISCALL fn566650(u8 *self) {
  *(u32 *)(self + 0xa04) = read_named(0x6a5c48);
  *(u32 *)(self + 0xa00) = read_named(0x6a6db0);
  u32 id = read_named(0x6a6db8);
  *(u32 *)(self + 0x180) = (u32)lookup(id);
  u8 *ob = *(u8 **)(tbl_() + 0xae4);
  *(u32 *)(self + 0x9f4) = (*(v2r_t **)ob)[0](ob, 0x6a67e8, 0x6a6dcc);
  u8 *c = *(u8 **)(self + 0x44);
  u32 w = (u32)(u16)(self[0x190] | (self[0x191] << 8));
  (*(v3_t **)c)[0x130 / 4](c, *(u32 *)(self + 0x90), w, 0);
  wr32(self + 0xa1f, *(u32 *)(self + 0x94) + 0x57);
  u8 *o = lookup(read_named(0x6a6dd4));
  if (o) (*(v0_t **)o)[0x2c / 4](o);
  (*(v1_t **)self)[0x64 / 4](self, 0x10);
}
PCREG(566650, fn566650);

static inline u32 rd16(u8 *p) { return (u16)(p[0] | (p[1] << 8)); }
static inline void set3(u8 *o, u8 *self) {
  (*(v3_t **)o)[0x128 / 4](o, rd16(self + 0xa4), 4, 0);
  (*(v3_t **)o)[0x128 / 4](o, rd16(self + 0xa6), 0xffffffff, 0);
  (*(v3_t **)o)[0x128 / 4](o, rd16(self + 0xa2), (u32)self, 0);
}

// 0x470420, thiscall(), tail-jumps this slot 0x374 (returns its eax). 0x4711f0(this, 5, 0); o = lookup(this[0xfd] (unaligned)): when set 3 calls of slot 0x128 (word 0xa4, 4, 0), (word 0xa6, -1, 0), (word 0xa2, this, 0).
// p = this slot 0x2f4(): p set and p slot 0x1e0(0x200074) true and p slot 0x420() nonzero: done. Else o = lookup(this[0x101]): when set, if bit 10 of o[8][0x3c] is set: o slot 0x2c(); then the same 3 calls on o.
static u32 THISCALL fn470420(u8 *self) {
  ext_4711f0(self, 5, 0);
  u8 *o = lookup(rd32(self + 0xfd));
  if (o) set3(o, self);
  u8 *p = (u8 *)(*(v0r_t **)self)[0x2f4 / 4](self);
  bool done = false;
  if (p) {
    if ((*(v1b_t **)p)[0x1e0 / 4](p, 0x200074)) {
      if ((*(v0r_t **)p)[0x420 / 4](p)) done = true;
    }
  }
  if (!done) {
    o = lookup(rd32(self + 0x101));
    if (o) {
      u32 x = *(u32 *)(*(u8 **)(o + 8) + 0x3c);
      if (!(~(x >> 10) & 1)) (*(v0_t **)o)[0x2c / 4](o);
      set3(o, self);
    }
  }
  return (*(v0r_t **)self)[0x374 / 4](self);
}
PCREG(470420, fn470420);
