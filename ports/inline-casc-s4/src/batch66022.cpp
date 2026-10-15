// batch66022.cpp - cascade s4 batch 66022: 0x63f2d0 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4ce7b0(void *self);   // plain ret

// Claim a record: clear its old back-reference slot when it has one and mark it used with the engine time sys[0x3c].
static void claim(u8 *t, u8 *e) {
  u32 w = *(u16 *)(e + 6);
  if (w != 0xffff) {
    *(u16 *)(e + 6) = 0xffff;
    wr(t + 0x270 + w * 4, 0);
  }
  e[5] |= 1;
  wr(e, rd(G(u8 *, 0x70039c) + 0x3c));
}

// 0x63f2d0, thiscall(a) ret 4, returns the record (this = t): c = a[8]; i = (u16)c[0x5a]. i != 0: e = t[0x68][i & 0xfff]; e[5] & 1 clear -> claim(e).
// e[0x42] & 1 -> t->slot 0x23 (0x8c)(e), t->slot 0x22 (0x88)(e); return e.
// i == 0: e = t[0x21c]->slot 2 (8)(); e[0x3c] = a; k = (0x4ce7b0(t + 0xb990) + 1) & 0xfff (k == 0 -> assert hook, else int3); t[0x68][k] = e; c[0x5a] = k; claim(e); t->slot 0x22 (0x88)(e); return e.
static u8 *THISCALL fn63f2d0(u8 *t, u8 *a) {
  u8 *c = *(u8 **)(a + 8);
  u32 i = *(u16 *)(c + 0x5a);
  u8 *e;
  if (i) {
    e = *(u8 **)(*(u8 **)(t + 0x68) + (i & 0xfff) * 4);
    if (!(e[5] & 1)) claim(t, e);
    if (e[0x42] & 1) {
      (*(v1_t **)t)[0x8c / 4](t, (u32)e);
      (*(v1_t **)t)[0x88 / 4](t, (u32)e);
    }
    return e;
  }
  u8 *o = *(u8 **)(t + 0x21c);
  e = (*(v0o_t **)o)[8 / 4](o);
  wr(e + 0x3c, (u32)a);
  u32 k = (ext_4ce7b0(t + 0xb990) + 1) & 0xfff;
  if (!k) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  wr(*(u8 **)(t + 0x68) + k * 4, (u32)e);
  *(u16 *)(c + 0x5a) = (u16)k;
  claim(t, e);
  (*(v1_t **)t)[0x88 / 4](t, (u32)e);
  return e;
}
PCREG(63f2d0, fn63f2d0);
