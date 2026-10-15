// batch36084.cpp - cascade s4 batch 36084: 0x456ab0, 0x4a7b50 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_456bf0(void *self);   // plain ret
extern "C" u32 THISCALL ext_4cc1d0(void *a);      // mov eax, [ecx]; ret

// 0x456ab0, thiscall() plain ret (this = s): o = 0x456bf0(s); o == 0 -> 0. Walk o (slot 0x4c(&it), id = slot 0x5c(&it) while it[0]):
// p = sys[0x9b]->slot 0x58(id); p != 0: name = p[4] or 0x67c8e8; 0x4cc1d0(s) string equals name (byte compare, NUL included) -> return id. End -> 0.
static u32 THISCALL fn456ab0(u8 *s) {
  u8 *o = ext_456bf0(s);
  if (!o) return 0;
  u32 it[4];
  (*(v1_t **)o)[0x4c / 4](o, (u32)it);
  u32 id = (*(v1r_t **)o)[0x5c / 4](o, (u32)it);
  while (it[0]) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *p = (*(v1o_t **)tab)[0x58 / 4](tab, id);
    if (p) {
      const u8 *name = (const u8 *)rd(p + 4);
      if (!name) name = (const u8 *)0x67c8e8;
      const u8 *a = (const u8 *)ext_4cc1d0(s);
      while (*a == *name && *a) {
        a++;
        name++;
      }
      if (*a == *name) return id;
    }
    id = (*(v1r_t **)o)[0x5c / 4](o, (u32)it);
  }
  return 0;
}
PCREG(456ab0, fn456ab0);

// 0x4a7b50, thiscall(code, unused) ret 8, returns 0 (this = s). code = (u16): 0x401: s[0x7a] == 0 -> 0; f = s[0x7b]; s[0x7c] = 1; f && !(s->slot 0x84() & 0xff) -> s->slot 0x64(0x10).
// 0x400: s[0x7a] == 0 -> 0; f = s[0x7b]; s[0x7c] = 0; f -> s->slot 0x68(0x10, 0).
// Otherwise c = (u16)s[0x50]; c != 0 && c == code: s->slot 0x84(); s[0x7b] == 0 -> s[0x7b] = 1, s[0x76] = sys[0x40] (when the addresses differ), s[0x72] = sys[0x40]; s[0x7c] -> s->slot 0x64(0x10).
static u32 THISCALL fn4a7b50(u8 *s, u32 code, u32 unused) {
  u16 cd = (u16)code;
  if (cd == 0x401) {
    if (!s[0x7a]) return 0;
    u8 f = s[0x7b];
    s[0x7c] = 1;
    if (!f) return 0;
    if ((u8)(*(v0r_t **)s)[0x84 / 4](s)) return 0;
    (*(v1_t **)s)[0x64 / 4](s, 0x10);
    return 0;
  }
  if (cd == 0x400) {
    if (!s[0x7a]) return 0;
    u8 f = s[0x7b];
    s[0x7c] = 0;
    if (!f) return 0;
    (*(v2_t **)s)[0x68 / 4](s, 0x10, 0);
    return 0;
  }
  u16 c = *(u16 *)(s + 0x50);
  if (!c || c != cd) return 0;
  (*(v0_t **)s)[0x84 / 4](s);
  if (s[0x7b]) return 0;
  s[0x7b] = 1;
  u8 *sys = G(u8 *, 0x70039c);
  if (s + 0x76 != sys + 0x40) {
    wr(s + 0x76, rd(sys + 0x40));
    sys = G(u8 *, 0x70039c);
  }
  if (s + 0x72 != sys + 0x40) wr(s + 0x72, rd(sys + 0x40));
  if (s[0x7c]) (*(v1_t **)s)[0x64 / 4](s, 0x10);
  return 0;
}
PCREG(4a7b50, fn4a7b50);
