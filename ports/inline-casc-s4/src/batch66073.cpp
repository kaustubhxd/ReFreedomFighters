// batch66073.cpp - cascade s4 batch 66073: 0x574280 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" void THISCALL ext_563750(void *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_562e90(void *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_5aa6e0(void *self);                 // plain ret
extern "C" void THISCALL ext_573d40(void *self);                 // plain ret
extern "C" void THISCALL ext_4f9680(void *self, u32 a);          // ret 4

static u8 *lookup(u32 id) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return (*(v1o_t **)tab)[0x58 / 4](tab, id);
}

// 0x574280, thiscall(a, b) ret 8, returns al = 0 (this = t): 0x563750(t, 3, 0); 0x562e90(t, a, b); t[0x4c]->slot 0x2f (0xbc)(0); t[0x50]->slot 0xbc(0); for t[0x180], t[0x184], t[0x18c], t[0x1c8] when set: ->slot 0xbc(1).
// lookup(t[0x1bc / 0x1c0 / 0x1c4])->slot 0x95 (0x254)(); lookup(t[0x90][0x676])->slot 0x94 (0x250)(); 0x5aa6e0(t[0xf8]); 0x573d40(t); t[0xf8][0x8cf] = 0; 0x4f9680(0x700e24, 3).
static u8 THISCALL fn574280(u8 *t, u32 a, u32 b) {
  ext_563750(t, 3, 0);
  ext_562e90(t, a, b);
  u8 *o = *(u8 **)(t + 0x4c);
  (*(v1_t **)o)[0xbc / 4](o, 0);
  o = *(u8 **)(t + 0x50);
  (*(v1_t **)o)[0xbc / 4](o, 0);
  static const u16 offs[4] = {0x180, 0x184, 0x18c, 0x1c8};
  for (int i = 0; i < 4; i++) {
    o = *(u8 **)(t + offs[i]);
    if (o) (*(v1_t **)o)[0xbc / 4](o, 1);
  }
  static const u16 ids[3] = {0x1bc, 0x1c0, 0x1c4};
  for (int i = 0; i < 3; i++) {
    o = lookup(rd(t + ids[i]));
    (*(v0_t **)o)[0x254 / 4](o);
  }
  u8 *w = *(u8 **)(t + 0x90);
  o = lookup(rd(w + 0x676));
  (*(v0_t **)o)[0x250 / 4](o);
  ext_5aa6e0(*(u8 **)(t + 0xf8));
  ext_573d40(t);
  (*(u8 **)(t + 0xf8))[0x8cf] = 0;
  ext_4f9680((void *)0x700e24, 3);
  return 0;
}
PCREG(574280, fn574280);
