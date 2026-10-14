// batch36077.cpp - cascade s4 batch 36077: 0x5da470, 0x5f5520 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);
typedef s32(*cmp_t)(const char *, const char *);
typedef void *(*memmove_t)(void *, const void *, u32);
typedef void (*hook_t)(void);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

static u8 *find_obj(u32 id) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return (*(v1o_t **)tab)[0x58 / 4](tab, id);
}

static u32 name_of(u8 *o) {
  u32 n = rd(o + 4);
  return n ? n : 0x67c8e8u;
}

// 0x5da470, thiscall() plain ret (this = s): o = find(s[0x56]); no o -> 0; s[0x5e] == 0 -> o.
// Else walk the list L = sys[0x190f]->slot 0x98(): for i while i < L->slot 0x14() (the first test is signed > 0): p = find(L->slot 0x30(i)); _stricmp(name(p), name(o)) == 0 -> return p; name(x) = x[4] or 0x67c8e8. Otherwise 0.
static u8 *THISCALL fn5da470(u8 *s) {
  u8 *o = find_obj(rd(s + 0x56));
  if (!o) return 0;
  if (!rd(s + 0x5e)) return o;
  u32 nm = name_of(o);
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
  u8 *L = (*(v0o_t **)mgr)[0x98 / 4](mgr);
  s32 i = 0;
  s32 n = (s32)(*(v0u_t **)L)[0x14 / 4](L);
  if (n <= 0) return 0;
  do {
    u32 id = (*(v1u_t **)L)[0x30 / 4](L, (u32)i);
    u8 *p = find_obj(id);
    if (G(cmp_t, 0x676414)((const char *)name_of(p), (const char *)nm) == 0) return p;
    i++;
    n = (s32)(*(v0u_t **)L)[0x14 / 4](L);
  } while (i < n);
  return 0;
}
PCREG(5da470, fn5da470);

// 0x5f5520, thiscall(a, b) ret 8 (this = t; a and b point at dwords): cnt = *b; cnt == 0 -> return.
// start = *a; start + cnt > t[8] (unsigned) -> assert hook [0x7003b0] (call it if set, else int3), return.
// Otherwise for i in [start, start + cnt): e = t[0] + i * 8; e[4] == 4 -> (*e)->slot 0x28(*e); e[4] = 0.
// Then memmove(t[0] + start * 8, t[0] + (start + cnt) * 8, (t[8] - start - cnt) * 8); entries [t[8] - cnt, t[8]) get byte 4 = 0; t[8] -= cnt.
static void THISCALL fn5f5520(u8 *t, u32 *a, u32 *b) {
  if (!*b) return;
  u32 start = *a;
  if (*b + start > rd(t + 8)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    return;
  }
  for (u32 i = start; i < *a + *b; i++) {
    u8 *e = *(u8 **)t + i * 8;
    if (e[4] == 4) {
      u8 *ob = *(u8 **)e;
      (*(v0_t **)ob)[0x28 / 4](ob);
    }
    e[4] = 0;
  }
  start = *a;
  u32 cnt = *b;
  u8 *base = *(u8 **)t;
  G(memmove_t, 0x676278)(base + start * 8, base + (start + cnt) * 8, (rd(t + 8) - start - cnt) << 3);
  for (u32 j = rd(t + 8) - *b; j < rd(t + 8); j++) (*(u8 **)t)[j * 8 + 4] = 0;
  wr(t + 8, rd(t + 8) - *b);
}
PCREG(5f5520, fn5f5520);
