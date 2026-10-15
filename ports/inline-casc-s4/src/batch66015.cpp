// batch66015.cpp - cascade s4 batch 66015: 0x4f04e0 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4f05d0(void *self, void *s);   // ret 4
extern "C" void ext_634273(void *p, u32 flag);             // cdecl

// 0x4f04e0, thiscall(s) ret 4, returns al (this = t): 0x4f05d0(t, s) == 0 (al) -> return.
// s->slot 0x48(t + 0x93); s->slot 0x40(&id); s->slot 0x48(t + 0xa3); s->slot 0x60(&str). t[0x9b] set -> sys->slot 0xfc(t[0x9b]); t[0x9b] = 0.
// buf = sys->slot 0xf8(strlen(str) + 2); t[0x9b] = buf; buf = '%' + str; 0x634273(str, 1); t[0x9f] = sys[0x9b]->slot 0x58(id); return 1.
static u8 THISCALL fn4f04e0(u8 *t, u8 *s) {
  u32 id;
  const char *str;
  if (!(u8)ext_4f05d0(t, s)) return 0;
  (*(v1_t **)s)[0x48 / 4](s, (u32)(t + 0x93));
  (*(v1_t **)s)[0x40 / 4](s, (u32)&id);
  (*(v1_t **)s)[0x48 / 4](s, (u32)(t + 0xa3));
  (*(v1_t **)s)[0x60 / 4](s, (u32)&str);
  u8 *sys = G(u8 *, 0x70039c);
  if (rd(t + 0x9b)) (*(v1_t **)sys)[0xfc / 4](sys, rd(t + 0x9b));
  wr(t + 0x9b, 0);
  u32 len = 0;
  while (str[len]) len++;
  sys = G(u8 *, 0x70039c);
  u8 *buf = (*(v1o_t **)sys)[0xf8 / 4](sys, len + 2);
  wr(t + 0x9b, (u32)buf);
  buf[0] = 0x25;
  u8 *d = *(u8 **)(t + 0x9b) + 1;
  const char *p = str;
  char ch;
  do {
    ch = *p++;
    *d++ = ch;
  } while (ch);
  ext_634273((void *)str, 1);
  str = 0;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(t + 0x9f, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  return 1;
}
PCREG(4f04e0, fn4f04e0);
