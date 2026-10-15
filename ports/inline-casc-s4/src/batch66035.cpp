// batch66035.cpp - cascade s4 batch 66035: 0x45e570 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4da3a0(void *self);   // plain ret (al)

// 0x45e570, thiscall(a) ret 4 (this = t): 0x4da3a0(t[8]) (al) == 0 -> return. L = t[0x10][8]: L set -> iterate (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]): o = [0x70038c]->slot 0x33 (0xcc)(e); o == a ->
// (o[4] & 4 and t[0x10][4] & 5 -> a->slot 0x17 (0x5c)(4, 0, 0); o[0x14] & 8, o[0x1c], t[0x10] and t[0x10][0x10] set -> *t[0x10][0x10] = 0; o->slot 0x15 (0x54)(t)) and stop; otherwise advance.
// Then: t[0x10][8]->slot 5 (0x14)() == 0 -> t->slot 0x50 (0x140)().
static void THISCALL fn45e570(u8 *t, u8 *a) {
  if (!(u8)ext_4da3a0(*(u8 **)(t + 8))) return;
  u8 *l = *(u8 **)(*(u8 **)(t + 0x10) + 8);
  if (l) {
    u32 it[3];
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    l = *(u8 **)(*(u8 **)(t + 0x10) + 8);
    u8 *e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0]) {
      do {
        u8 *g = G(u8 *, 0x70038c);
        u8 *o = (*(v1o_t **)g)[0xcc / 4](g, (u32)e);
        if (o == a) {
          if ((o[4] & 4) && ((*(u8 **)(t + 0x10))[4] & 5)) (*(v3_t **)a)[0x5c / 4](a, 4, 0, 0);
          if ((o[0x14] & 8) && rd(o + 0x1c)) {
            u8 *x = *(u8 **)(t + 0x10);
            if (x) {
              u8 *y = *(u8 **)(x + 0x10);
              if (y) wr(y, 0);
            }
          }
          (*(v1_t **)o)[0x54 / 4](o, (u32)t);
          break;
        }
        l = *(u8 **)(*(u8 **)(t + 0x10) + 8);
        e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
      } while (it[0]);
    }
  }
  l = *(u8 **)(*(u8 **)(t + 0x10) + 8);
  if (!(*(v0r_t **)l)[0x14 / 4](l)) (*(v0_t **)t)[0x140 / 4](t);
}
PCREG(45e570, fn45e570);
