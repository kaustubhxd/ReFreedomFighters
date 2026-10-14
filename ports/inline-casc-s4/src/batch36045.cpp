// batch36045.cpp - cascade s4 batch 36045: 0x5d7610, 0x603790 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v0r_t)(void *);
typedef void *(*vStrncpy)(void *dst, const char *src, u32 n);   // IAT 0x67642c (cdecl)
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4e5e60(void *r);    // plain ret
extern "C" u8 *THISCALL ext_4e5ea0(void *r);    // plain ret, returns a string

// 0x5d7610, thiscall(r) ret 4 (this = s): s[0x1d6], s[0x1da], s[0x15a] = three u32 reads from r (0x4e5e60); str = 0x4e5ea0(r); strlen(str) > 0x63 -> assert hook (int3 when none); strncpy(s + 0x15e, str, 0x63); s[0x1c1] = 0;
// v = read; s[0x1de] = s[0x1e2] = 0; s[0x1c2] = (v != 0); when the byte at **r is neither 0xff nor ((b & 0x3f) == 0xff): s[0x1de] = read; the same test again (re-reading **r): s[0x1e2] = read.
static void THISCALL fn5d7610(u8 *s, u8 *r) {
  wr(s + 0x1d6, ext_4e5e60(r));
  wr(s + 0x1da, ext_4e5e60(r));
  wr(s + 0x15a, ext_4e5e60(r));
  u8 *str = ext_4e5ea0(r);
  u32 n = 0;
  while (str[n]) n++;
  if (n > 0x63) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  ((vStrncpy)(u32)G(u32, 0x67642c))(s + 0x15e, (const char *)str, 0x63);
  s[0x1c1] = 0;
  u32 v = ext_4e5e60(r);
  wr(s + 0x1de, 0);
  wr(s + 0x1e2, 0);
  s[0x1c2] = (v != 0);
  u8 b = **(u8 **)r;
  if (b != 0xff && (u8)(b & 0x3f) != 0xff) wr(s + 0x1de, ext_4e5e60(r));
  b = **(u8 **)r;
  if (b != 0xff && (u8)(b & 0x3f) != 0xff) wr(s + 0x1e2, ext_4e5e60(r));
}
PCREG(5d7610, fn5d7610);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x603790, thiscall(p) ret 4 (this = d): idx = *0x5003d0(p[4], 1); idx >= d[0x14] -> assert hook (int3 when none). e = d[0xc] + idx * 8; e[4] == 4 -> (*(u32 *)e)->slot 0x28(); e[4] = 0; same bound check again; e again.
// r = 0x5003d0(p[4], 0); r == e -> return. e[4] == 4 -> (*(u32 *)e)->slot 0x28() again. r[4] != 4: *e = *r, e[4] = r[4]. Otherwise *e = (*(u32 *)r)->slot 0x24(), e[4] = r[4].
static void THISCALL fn603790(u8 *d, u8 *p) {
  u32 idx = rd(ext_5003d0(*(u8 **)(p + 4), 1));
  if (!(idx < rd(d + 0x14))) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u8 *e = *(u8 **)(d + 0xc) + idx * 8;
  if (e[4] == 4) {
    u8 *o = *(u8 **)e;
    (*(v0_t **)o)[0x28 / 4](o);
  }
  e[4] = 0;
  if (!(idx < rd(d + 0x14))) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  e = *(u8 **)(d + 0xc) + idx * 8;
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
  if (r == e) return;
  if (e[4] == 4) {
    u8 *o = *(u8 **)e;
    (*(v0_t **)o)[0x28 / 4](o);
  }
  if (r[4] != 4) {
    wr(e, rd(r));
    e[4] = r[4];
    return;
  }
  u8 *o2 = *(u8 **)r;
  wr(e, (*(v0r_t **)o2)[0x24 / 4](o2));
  e[4] = r[4];
}
PCREG(603790, fn603790);
