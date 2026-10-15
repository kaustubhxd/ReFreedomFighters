// batch66016.cpp - cascade s4 batch 66016: 0x509c20 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x509c20, thiscall(p) ret 4 (this = s): r = 0x5003d0(p[4], 0); r[4] == 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else logger(0x69c8e0, 0x111) prints 0x69c6b0, 0x69c9b0, assert hook, id = 0.
// h = (u16) sys[0x9b]->slot 0x114(id, 0, 0x69d214, 0xb1). l = s[0xc][0x18]: l set -> iterate (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]): s[0xc]->slot 0x12c(e, h, 0).
static void THISCALL fn509c20(u8 *s, u8 *p) {
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
  u32 id;
  u32 t = r[4];
  if (t == 3) {
    id = rd(r);
  } else if (t == 4) {
    u8 *o = *(u8 **)r;
    id = (*(v0r_t **)o)[0x34 / 4](o);
  } else {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x111u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c9b0u);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    id = 0;
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 h16 = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, id, 0, 0x69d214u, 0xb1u);
  u8 *w = *(u8 **)(s + 0xc);
  u8 *l = *(u8 **)(w + 0x18);
  if (!l) return;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  w = *(u8 **)(s + 0xc);
  l = *(u8 **)(w + 0x18);
  u8 *e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
  if (!it[0]) return;
  do {
    w = *(u8 **)(s + 0xc);
    (*(v3_t **)w)[0x12c / 4](w, (u32)e, h16, 0);
    w = *(u8 **)(s + 0xc);
    l = *(u8 **)(w + 0x18);
    e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
  } while (it[0]);
}
PCREG(509c20, fn509c20);
