// batch36065.cpp - cascade s4 batch 36065: 0x4a44d0, 0x4f20a0, 0x4f5d30 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v5o_t)(void *, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4a44d0, thiscall() plain ret (this = s): for the names 0x681320 / 0x68fcbc / 0x68fccc / 0x68fcdc: o = tab->slot 0x138(); id = 0; o->slot 0x88(name, &id); s[0x1c8 / 0x1cc / 0x1d0 / 0x1d4] = tab->slot 0x58(id).
static void THISCALL fn4a44d0(u8 *s) {
  static const u32 names[4] = {0x681320, 0x68fcbc, 0x68fccc, 0x68fcdc};
  static const u32 offs[4] = {0x1c8, 0x1cc, 0x1d0, 0x1d4};
  for (int i = 0; i < 4; i++) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
    u32 id = 0;
    (*(v2_t **)o)[0x88 / 4](o, names[i], (u32)&id);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    wr(s + offs[i], (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  }
}
PCREG(4a44d0, fn4a44d0);

extern "C" void THISCALL ext_44edd0(void *self, void *a);          // ret 4
extern "C" void THISCALL ext_4e12e0(void *a, u32 *p, u32 f);       // ret 8
extern "C" void THISCALL ext_4e11e0(void *a, u32 *p, u32 f);       // ret 8
extern "C" u32 THISCALL ext_4e1600(void *a);                       // plain ret
extern "C" void THISCALL ext_4e14a0(void *a, u8 *p, u32 f);        // ret 8
extern "C" void THISCALL ext_4e1b30(void *a);                      // plain ret

// 0x4f20a0, thiscall(a) ret 4 (this = d, a = stream): 0x44edd0(d, a); 0x4e12e0(a, &id, 1); x = d[0x6f] = tab->slot 0x58(id); d->slot 0x32c(x); 0x4e12e0(a, d + 0x73, 1); 0x4e12e0(a, &id2, 1); d[0x1db] = tab->slot 0x58(id2);
// 0x4e11e0(a, &f1, 1); d[0x5fc] = 0; d[0x5fb] = (f1 != 0); kind(a) == 3: 0x4e11e0(a, &f2, 1), d[0x5fc] = (f2 != 0); kind(a) == 3: 0x4e14a0(a, d + 0x5fd, 1). 0x4e1b30(a).
static void THISCALL fn4f20a0(u8 *d, u8 *a) {
  ext_44edd0(d, a);
  u32 id = 0;
  ext_4e12e0(a, &id, 1);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, id);
  wr(d + 0x6f, (u32)x);
  (*(v1_t **)d)[0x32c / 4](d, (u32)x);
  ext_4e12e0(a, (u32 *)(d + 0x73), 1);
  u32 id2 = 0;
  ext_4e12e0(a, &id2, 1);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(d + 0x1db, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id2));
  u32 f1 = 0;
  ext_4e11e0(a, &f1, 1);
  d[0x5fc] = 0;
  d[0x5fb] = (f1 != 0);
  if ((u8)ext_4e1600(a) == 3) {
    u32 f2 = 0;
    ext_4e11e0(a, &f2, 1);
    d[0x5fc] = (f2 != 0);
  }
  if ((u8)ext_4e1600(a) == 3) ext_4e14a0(a, d + 0x5fd, 1);
  ext_4e1b30(a);
}
PCREG(4f20a0, fn4f20a0);

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // ret 8

// 0x4f5d30, thiscall(m, str, v) ret 0xc returns eax (this = d): b = tab->slot 0x58(d[0x7c]); b == 0 -> 0. s = m->slot 0x294(0x69a664, 0x699654, 0, 1); s == 0 -> 0.
// s->slot 0x154(); 0x4dc630(s[8], 0x800000, 0); s->slot 0x27c(b); s->slot 0x248(d[0x80]); s->slot 0x2a0(v); s->slot 0x284(str[0] == '%' ? str + 1 : str); s->slot 0x158(); return s.
static u8 *THISCALL fn4f5d30(u8 *d, u8 *m, u8 *str, u32 v) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *b = (*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x7c));
  if (!b) return 0;
  u8 *s = (*(v5o_t **)m)[0x294 / 4](m, 0x69a664u, 0x699654u, 0, 1);
  if (!s) return s;
  (*(v0_t **)s)[0x154 / 4](s);
  ext_4dc630(*(u8 **)(s + 8), 0x800000u, 0);
  (*(v1_t **)s)[0x27c / 4](s, (u32)b);
  (*(v1_t **)s)[0x248 / 4](s, rd(d + 0x80));
  (*(v1_t **)s)[0x2a0 / 4](s, v);
  if (str[0] == 0x25) {
    (*(v1_t **)s)[0x284 / 4](s, (u32)(str + 1));
    (*(v0_t **)s)[0x158 / 4](s);
    return s;
  }
  (*(v1_t **)s)[0x284 / 4](s, (u32)str);
  (*(v0_t **)s)[0x158 / 4](s);
  return s;
}
PCREG(4f5d30, fn4f5d30);
