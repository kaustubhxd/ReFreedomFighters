// batch47001.cpp - cascade t8 batch 47001: 0x41f550, 0x434e20 (tier F rows).
#include "ff.h"

typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u8 *(*strpbrk_t)(const u8 *, const u8 *);

extern "C" void THISCALL ext_41f190(void *self, void *p);   // ret 4
extern "C" u8 *ext_41e290(u32 n);                           // cdecl malloc
extern "C" void ext_634273(u8 *p, u32 n);                   // cdecl free(p, 1)

// The exe's hash of an object pointer p (inlined twice in 0x41f550): 0 for null or when ctx slot 0x20(p) is nonzero; else when ctx[8] is set and
// ctx[0xc] <= p < ctx[0x10] the ctx[8](p) thiscall callback result; else p[-1] (dword); when that is 0, ctx slot 0xac(p) is called first (to fill it); result p[-1].
static u32 hash_of(u32 p) {
  u8 *ctx = G(u8 *, 0x70038c);
  if (!p) return 0;
  if ((*(v1r_t **)ctx)[0x20 / 4](ctx, p)) return 0;
  ctx = G(u8 *, 0x70038c);
  v0r_t cb = *(v0r_t *)(ctx + 8);
  if (cb && *(u32 *)(ctx + 0xc) <= p && p < *(u32 *)(ctx + 0x10)) return cb((void *)p);
  if (*(u32 *)(p - 4) == 0) (*(v1_t **)ctx)[0xac / 4](ctx, p);
  return *(u32 *)(p - 4);
}

// 0x41f550, thiscall(a, b) ret 8: swap two keys in a hash table: ha = hash(a), hb = hash(b); tab = this[0x28], mask = this[4][0x10];
// tab[mask & ha] = b; tab[mask & hb] = a; a[-1] = hb; b[-1] = ha; 0x41f190(this, a), 0x41f190(this, b).
static void THISCALL fn41f550(u8 *self, u32 a, u32 b) {
  u32 ha = hash_of(a);
  u32 hb = hash_of(b);
  u32 *tab = *(u32 **)(self + 0x28);
  tab[*(u32 *)(*(u8 **)(self + 4) + 0x10) & ha] = b;
  tab = *(u32 **)(self + 0x28);
  tab[*(u32 *)(*(u8 **)(self + 4) + 0x10) & hb] = a;
  *(u32 *)(a - 4) = hb;
  *(u32 *)(b - 4) = ha;
  ext_41f190(self, (void *)a);
  ext_41f190(self, (void *)b);
}
PCREG(41f550, fn41f550);

// 0x434e20, thiscall(path) ret 4: copy path to a malloc'd buffer (0x41e290(len+1)); a trailing '/' or '\\' is cut; then for each separator ("/\\", strpbrk)
// at position q: *q = 0; when strpbrk(buf, "/\\") is nonzero, this->slot 0x4c(buf) is called; *q = '/'; q = strpbrk(q+1, "/\\"). Finally this->slot 0x4c(buf), free(buf, 1).
static void THISCALL fn434e20(u8 *self, u8 *path) {
  u32 n = 0;
  while (path[n]) n++;
  u8 *buf = ext_41e290(n + 1);
  u32 i = 0;
  u8 ch;
  do {
    ch = path[i];
    buf[i] = ch;
    i++;
  } while (ch);
  u32 m = 0;
  while (path[m]) m++;
  if (buf[m - 1] == 0x5c || buf[m - 1] == 0x2f) {
    u32 k = 0;
    while (path[k]) k++;
    buf[k - 1] = 0;
  }
  strpbrk_t pb = G(strpbrk_t, 0x676418);
  u8 *q = pb(buf, (const u8 *)0x67a4e4);
  while (q) {
    *q = 0;
    if (pb(buf, (const u8 *)0x67a4e4)) (*(v1_t **)self)[0x4c / 4](self, (u32)buf);
    *q = 0x2f;
    q = pb(q + 1, (const u8 *)0x67a4e4);
  }
  (*(v1_t **)self)[0x4c / 4](self, (u32)buf);
  ext_634273(buf, 1);
}
PCREG(434e20, fn434e20);
