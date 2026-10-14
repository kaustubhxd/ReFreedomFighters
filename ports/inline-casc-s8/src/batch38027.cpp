// batch38027.cpp - cascade s8 batch 38027: 0x5d7bc0 (apply the selected entry of a two-list control).
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

// 0x5d7bc0, thiscall, no args, plain ret. When +0x1c3 is set, +0x156 == 2 and +0x1e6 is clear: sets +0x1e6, fetches two named handles through the table helper (slot 0x138 / 0x88, names
// 0x6b5df8 and 0x6b5e08) and passes each with its name id (table slot 0x114) to this[0x44] slot 0x12c, then stores engine[0x40] + 0x800 at +0x1c8. Otherwise, when the lists +0x14e / +0x152 exist
// and +0x156 is below the first list's count: every entry of the second list (slot 0x30 id, table slot 0x58 object) gets slot 0xbc(index != +0x156), the selected id of the first list is sent to
// slot 0x12c of this[0x44] with the table's handle for it, and the last visited entry of the second list gets slot 0x138(word +0x144, 0, 0).
static void THISCALL fn5d7bc0(u8 *self) {
  if (self[0x1c3] != 0 && U32F(0x156) == 2 && self[0x1e6] == 0) {
    self[0x1e6] = 1;
    u8 *t = TABLE;
    u8 *x = (u8 *)SLOT(t, 0x138, v0_t)(t);
    u32 l4 = 0;
    SLOT(x, 0x88, v2_t)(x, 0x6b5df8, (u32)&l4);
    t = TABLE;
    x = (u8 *)SLOT(t, 0x138, v0_t)(t);
    u32 l8 = 0;
    SLOT(x, 0x88, v2_t)(x, 0x6b5e08, (u32)&l8);
    u8 *ob = *(u8 **)(self + 0x44);
    u8 **vt = *(u8 ***)ob;
    t = TABLE;
    u32 id = SLOT(t, 0x114, v4_t)(t, 0x692dac, 0, 0x6b5d74, 0xe9);
    ((v3_t)vt[0x12c / 4])(ob, l4, id & 0xffff, 0);
    ob = *(u8 **)(self + 0x44);
    vt = *(u8 ***)ob;
    t = TABLE;
    id = SLOT(t, 0x114, v4_t)(t, 0x692d94, 0, 0x6b5d74, 0xea);
    ((v3_t)vt[0x12c / 4])(ob, l8, id & 0xffff, 0);
    *(u32 *)(self + 0x1c8) = *(u32 *)(ENG + 0x40) + 0x800;
    return;
  }
  u8 *l1 = *(u8 **)(self + 0x14e);
  if (!l1) return;
  if (U32F(0x152) == 0) return;
  s32 a = (s32)SLOT(l1, 0x14, v0_t)(l1);
  if ((s32)U32F(0x156) >= a) return;
  s32 ebx = 0;
  s32 last = 0;
  u8 *l2 = *(u8 **)(self + 0x152);
  s32 c = (s32)SLOT(l2, 0x14, v0_t)(l2);
  if (c > 0) {
    do {
      l2 = *(u8 **)(self + 0x152);
      u32 id = SLOT(l2, 0x30, v1_t)(l2, (u32)ebx);
      u8 *t = TABLE;
      u8 *o = (u8 *)SLOT(t, 0x58, v1_t)(t, id);
      if (o) SLOT(o, 0xbc, v1_t)(o, (u32)(ebx != (s32)U32F(0x156)));
      l2 = *(u8 **)(self + 0x152);
      ebx++;
      c = (s32)SLOT(l2, 0x14, v0_t)(l2);
    } while (ebx < c);
    last = ebx;
  }
  l1 = *(u8 **)(self + 0x14e);
  u32 sel = SLOT(l1, 0x30, v1_t)(l1, U32F(0x156));
  u8 *ob = *(u8 **)(self + 0x44);
  u8 *t = TABLE;
  u8 **vt = *(u8 ***)ob;
  u32 h = SLOT(t, 0x4c, v1_t)(t, (u32)ob);
  ((v3_t)vt[0x12c / 4])(ob, sel, *(u16 *)(self + 0x140), h);
  l2 = *(u8 **)(self + 0x152);
  u32 id2 = SLOT(l2, 0x30, v1_t)(l2, (u32)last);
  t = TABLE;
  u8 *o = (u8 *)SLOT(t, 0x58, v1_t)(t, id2);
  if (o) SLOT(o, 0x138, v3_t)(o, *(u16 *)(self + 0x144), 0, 0);
}
PCREG(5d7bc0, fn5d7bc0);
