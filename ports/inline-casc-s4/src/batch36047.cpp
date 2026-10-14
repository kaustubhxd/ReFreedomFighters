// batch36047.cpp - cascade s4 batch 36047: 0x495dd0, 0x4db070 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4cd9b0(void *self, u32 size, u32 flag);   // ret 8
extern "C" void ext_42ab62(u32 fmt);                                  // cdecl
extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");   // cdecl

// 0x495dd0, thiscall(n, p) ret 8 returns eax (this = s): n == 0 -> return p. n = (n + 15) & ~15. p == 0: t = 0x4cd9b0(*s[0x18], n, 1); t == -1: 0x42ab62(0x68e49c) + assert hook (int3 when none);
// g = [0x70038c]: g -> g->slot 0x2c(0x68e350, t, n); g->slot 0x50(s[0x18][4] + t, n, 0xaf0000); p = s[0x18][4] + t. Then memset(p, 0, n); p[8] = 0; return p.
static u8 *THISCALL fn495dd0(u8 *s, u32 n, u8 *p) {
  if (!n) return p;
  n = (n + 0xf) & 0xfffffff0u;
  if (!p) {
    u8 *x = *(u8 **)(s + 0x18);
    u32 t = ext_4cd9b0(*(u8 **)x, (n + 0xf) & 0xfffffff0u, 1);
    if (t == 0xffffffffu) {
      ext_42ab62(0x68e49c);
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    u8 *g = G(u8 *, 0x70038c);
    if (g) {
      (*(v3_t **)g)[0x2c / 4](g, 0x68e350u, t, n);
      g = G(u8 *, 0x70038c);
    }
    u8 *x2 = *(u8 **)(s + 0x18);
    (*(v3_t **)g)[0x50 / 4](g, rd(x2 + 4) + t, n, 0xaf0000u);
    x2 = *(u8 **)(s + 0x18);
    p = (u8 *)(rd(x2 + 4) + t);
  }
  memset_634d10(p, 0, n);
  wr(p + 8, 0);
  return p;
}
PCREG(495dd0, fn495dd0);

extern "C" u32 FASTCALL ext_4dac50(u8 *node, u8 *buf);              // returns eax
extern "C" u32 FASTCALL ext_4dba00(u32 a, u32 t, u8 *buf);          // ret 4, al

// 0x4db070, fastcall(count = ecx, dest = edx, a, node) ret 8 returns count: x = node[0x54]; flags = x ? x[0xc][0x23] : 0x200002.
// flags & 0x100000: for each child c of x[0x50] (next at +0x60): c[0x3c] & 0x2c00 == 0 -> count = self(count, dest, a, c); return count.
// else flags & 0x800000 and node[0x68] != 0: t = 0x4dac50(node, buf); 0x4dba00(a, t, buf) (low byte) -> dest[count] = node, return count + 1. Otherwise return count.
static u32 FASTCALL fn4db070(u32 count, u32 *dest, u32 a, u8 *node) {
  u8 buf[0x200];
  u8 *x = *(u8 **)(node + 0x54);
  u32 flags;
  if (x) flags = rd(*(u8 **)(x + 0xc) + 0x23);
  else flags = 0x200002;
  if (flags & 0x100000) {
    u8 *c = *(u8 **)(x + 0x50);
    while (c) {
      if (!(rd(c + 0x3c) & 0x2c00)) count = fn4db070(count, dest, a, c);
      c = *(u8 **)(c + 0x60);
    }
    return count;
  }
  if (flags & 0x800000) {
    if (rd(node + 0x68) != 0) {
      u32 t = ext_4dac50(node, buf);
      if ((u8)ext_4dba00(a, t, buf)) {
        dest[count] = (u32)node;
        return count + 1;
      }
    }
  }
  return count;
}
PCREG(4db070, fn4db070);
