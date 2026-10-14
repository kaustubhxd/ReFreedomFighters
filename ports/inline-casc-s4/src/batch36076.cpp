// batch36076.cpp - cascade s4 batch 36076: 0x56cb20, 0x5d3d90 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void STDCALL ext_610100(u32 a);                 // ret 4
extern "C" u32 THISCALL ext_4e5e60(void *r);               // plain ret

static u8 *find_obj(u32 id) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return (*(v1o_t **)tab)[0x58 / 4](tab, id);
}

// 0x56cb20, thiscall(r) ret 4 (this = s): 0x610100(r); nine 32-bit reads from r through 0x4e5e60: v1, v2 dropped; v3, v4, v5, v6, v7 kept; s[0x188] = v8; s[0x184] = v9; s[0x44]->slot 0x2f (0xbc)(1);
// s[0x180] = find(v3), s[0x18c] = find(v4), s[0x190] = find(v5), s[0x194] = find(v6), s[0x198] = find(v7) (find = sys[0x9b]->slot 0x58).
static void THISCALL fn56cb20(u8 *s, u8 *r) {
  ext_610100((u32)r);
  ext_4e5e60(r);
  ext_4e5e60(r);
  u32 v3 = ext_4e5e60(r);
  u32 v4 = ext_4e5e60(r);
  u32 v5 = ext_4e5e60(r);
  u32 v6 = ext_4e5e60(r);
  u32 v7 = ext_4e5e60(r);
  wr(s + 0x188, ext_4e5e60(r));
  u32 v9 = ext_4e5e60(r);
  u8 *w = *(u8 **)(s + 0x44);
  wr(s + 0x184, v9);
  (*(v1_t **)w)[0xbc / 4](w, 1);
  wr(s + 0x180, (u32)find_obj(v3));
  wr(s + 0x18c, (u32)find_obj(v4));
  wr(s + 0x190, (u32)find_obj(v5));
  wr(s + 0x194, (u32)find_obj(v6));
  wr(s + 0x198, (u32)find_obj(v7));
}
PCREG(56cb20, fn56cb20);

// 0x5d3d90, thiscall() plain ret (this = s): for the names 0x681320 / 0x68fcbc / 0x68fccc / 0x68fcdc: o = tab->slot 0x138(); id = 0; o->slot 0x88(name, &id); s[0x68 / 0x6c / 0x70 / 0x74] = id (the id itself).
// Then the same lookup for 0x67a1b8, and s[0x85] = sys[0x9b]->slot 0x58(id).
static void THISCALL fn5d3d90(u8 *s) {
  static const u32 names[4] = {0x681320, 0x68fcbc, 0x68fccc, 0x68fcdc};
  static const u32 offs[4] = {0x68, 0x6c, 0x70, 0x74};
  for (int i = 0; i < 4; i++) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
    u32 id = 0;
    (*(v2_t **)o)[0x88 / 4](o, names[i], (u32)&id);
    wr(s + offs[i], id);
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u32 id = 0;
  (*(v2_t **)o)[0x88 / 4](o, 0x67a1b8u, (u32)&id);
  wr(s + 0x85, (u32)find_obj(id));
}
PCREG(5d3d90, fn5d3d90);
