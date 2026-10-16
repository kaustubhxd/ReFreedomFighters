#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_563110(void *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_5747e0(void *self);
extern "C" u32 THISCALL ext_5aa6e0(void *self);
extern "C" u32 THISCALL ext_561720(void *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_573d40(void *self);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }
static inline void show(u32 obj, u32 arg) { void *o = (void *)obj; (*(V1 *)(vt(o) + 0xbc))(o, arg); }
static inline u8 *eng() { return G(u8 *, 0x70039c); }
static inline void *table() { return (void *)rd32u(eng() + 0x9b); }
static inline void *lookup(u32 id) {
  void *t = table();
  return (void *)(*(V1 *)(vt(t) + 0x58))(t, id);
}

// 0x5743c0: thiscall(a, b) ret 8, returns 0 in AL (/GS protected): switches a panel into its idle layout. 0x563110(this, a, b), 0x5747e0(this), this[0x1f1] = 1; when the engine object's
// slot 0xbc()->slot 0xdc() is set this[0xf8]'s byte +0x8cf is set; widgets this[0x4c] / [0x50] shown (slot 0xbc(1)); this[0xdc] = 2 and this slot 0xec(); the widgets this[0x180] / [0x184],
// when they and their ids this[0x1b0] / [0x1b4] exist, get slot 0x284(id) and are hidden (slot 0xbc(0)); this[0x1c8] hidden; the table entry for [this[0x90]+0x676] gets slot 0x254(), those for
// this[0x1c4], [0x1bc], [0x1c0] slot 0x250(); 0x5aa6e0(this[0xf8]), this[0xf8] slot 0x214(0x400); this slot 0x84()->slot 0x25c(0x6a8f44, 0) hidden (slot 0xbc(0)); 0x561720(this, this[0x1dc], 0);
// the widget this[0x1dc] is placed at (60.0f, float([G+0x73] - 0x28), 0) (slot 0x70) and hidden; this slot 0xd4(0xff); 0x573d40(this).
extern "C" u32 THISCALL fn_5743c0(u8 *self, u32 a, u32 b) {
  u32 vec[3];
  ext_563110(self, a, b);
  ext_5747e0(self);
  self[0x1f1] = 1;
  {
    void *g = eng();
    void *x = (void *)(*(V0 *)(vt(g) + 0xbc))(g);
    if ((u8)(*(V0 *)(vt(x) + 0xdc))(x)) ((u8 *)rd32u(self + 0xf8))[0x8cf] = 1;
  }
  show(rd32u(self + 0x4c), 1);
  show(rd32u(self + 0x50), 1);
  {
    u8 *sv = vt(self);
    wr32u(self + 0xdc, 2);
    (*(V0 *)(sv + 0xec))(self);
  }
  u8 *w = (u8 *)rd32u(self + 0x180);
  if (w) {
    u32 id = rd32u(self + 0x1b0);
    if (id) {
      (*(V1 *)(vt(w) + 0x284))(w, id);
      show(rd32u(self + 0x180), 0);
    }
  }
  w = (u8 *)rd32u(self + 0x184);
  if (w) {
    u32 id = rd32u(self + 0x1b4);
    if (id) {
      (*(V1 *)(vt(w) + 0x284))(w, id);
      show(rd32u(self + 0x184), 0);
    }
  }
  w = (u8 *)rd32u(self + 0x1c8);
  if (w) show((u32)w, 0);
  {
    u32 id = rd32u((u8 *)rd32u(self + 0x90) + 0x676);
    void *y = lookup(id);
    (*(V0 *)(vt(y) + 0x254))(y);
  }
  {
    void *y = lookup(rd32u(self + 0x1c4));
    (*(V0 *)(vt(y) + 0x250))(y);
    y = lookup(rd32u(self + 0x1bc));
    (*(V0 *)(vt(y) + 0x250))(y);
    y = lookup(rd32u(self + 0x1c0));
    (*(V0 *)(vt(y) + 0x250))(y);
  }
  ext_5aa6e0((void *)rd32u(self + 0xf8));
  {
    void *f = (void *)rd32u(self + 0xf8);
    (*(V1 *)(vt(f) + 0x214))(f, 0x400);
  }
  {
    void *z = (void *)(*(V0 *)(vt(self) + 0x84))(self);
    void *r = (void *)(*(V2 *)(vt(z) + 0x25c))(z, 0x6a8f44, 0);
    show((u32)r, 0);
  }
  ext_561720(self, rd32u(self + 0x1dc), 0);
  {
    s32 h = (s32)rd32u(eng() + 0x73) - 0x28;
    void *w2 = (void *)rd32u(self + 0x1dc);
    vec[0] = 0x42700000;
    vec[2] = 0;
    float fy = (float)h;
    __builtin_memcpy(&vec[1], &fy, 4);
    (*(V1 *)(vt(w2) + 0x70))(w2, (u32)vec);
  }
  show(rd32u(self + 0x1dc), 0);
  (*(V1 *)(vt(self) + 0xd4))(self, 0xff);
  ext_573d40(self);
  ext_633654(G(u32, 0x6f5630));
  return 0;
}
PCREG(5743c0, fn_5743c0);
