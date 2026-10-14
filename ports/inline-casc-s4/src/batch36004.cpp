// batch36004.cpp - cascade s4 batch 36004: 0x4e7f70, 0x4e86f0, 0x4f0c10, 0x51f880 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  else h();
}

// 0x4e7f70, thiscall(a) ret 4: n = a or this[4] (assert hook when both null); returns when n == this[8]; p = n[4]: when p != this[8]:
// assert hook unless p[0] == n, then this->slot 0x20(n[4]); q = n[8]: returns when q == this[8]; assert hook unless q[0] == n; this->slot 0x20(n[8]).
static void THISCALL fn4e7f70(u8 *self, u8 *a) {
  u8 *n = a;
  if (!n) {
    n = *(u8 **)(self + 4);
    if (!n) assertHook();
  }
  u8 *sent = *(u8 **)(self + 8);
  if (n == sent) return;
  u8 *p = *(u8 **)(n + 4);
  if (p != sent) {
    if (*(u8 **)p != n) assertHook();
    (*(v1_t **)self)[0x20 / 4](self, rd(n + 4));
  }
  u8 *q = *(u8 **)(n + 8);
  if (q == *(u8 **)(self + 8)) return;
  if (*(u8 **)q != n) assertHook();
  (*(v1_t **)self)[0x20 / 4](self, rd(n + 8));
}
PCREG(4e7f70, fn4e7f70);

// 0x4e86f0, thiscall(key, node) ret 8: n = node or this[4] (0 when both null). If n[0xc] > key (signed): c = n[4]; if c: r = this->slot 0xc(key, c);
// r && key <= r[0xc] returns r. If n[0xc] < key: c = n[8]; same check; failing returns 0. Equal or failed left branch: returns n unless n == this[8] (0).
static u8 *THISCALL fn4e86f0(u8 *self, s32 key, u8 *node) {
  u8 *n = node;
  if (!n) {
    n = *(u8 **)(self + 4);
    if (!n) return 0;
  }
  s32 v = (s32)rd(n + 0xc);
  if (v > key) {
    u32 c = rd(n + 4);
    if (c) {
      u8 *r = (*(v2o_t **)self)[0xc / 4](self, (u32)key, c);
      if (r && key <= (s32)rd(r + 0xc)) return r;
    }
  } else if (v < key) {
    u32 c = rd(n + 8);
    if (c) {
      u8 *r = (*(v2o_t **)self)[0xc / 4](self, (u32)key, c);
      if (r && key <= (s32)rd(r + 0xc)) return r;
    }
    return 0;
  }
  if (n == *(u8 **)(self + 8)) return 0;
  return n;
}
PCREG(4e86f0, fn4e86f0);

extern "C" u32 ext_4f00f0();  // no arguments (ignores ecx), plain ret

// 0x4f0c10, thiscall(no args), this = o: o[0x90] = 0 (byte). eng = [0x70039c]; h = *(eng+0x1aa3 (unaligned))[0x18].
// o[0x2a] && !o[0x91]: h->slot 0x40(o[0x2a], o[0x2e]); clear both. o[0x36] && !o[0x91]: for i < o[0x32]: if 0x4f00f0(): o->slot 0x21c(o[0x36][i]);
// h->slot 0x48(o[0x36], o[0x32]); o[0x36] = 0. o[0x3a] && !o[0x91]: h->slot 0x4c(o[0x3a], o[0x32]); o[0x3a] = o[0x32] = 0.
static u8 *holder() { return *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18); }
static void THISCALL fn4f0c10(u8 *self) {
  self[0x90] = 0;
  u32 e = rd(self + 0x2a);
  if (e && !self[0x91]) {
    u8 *h = holder();
    (*(v2_t **)h)[0x40 / 4](h, e, rd(self + 0x2e));
    wr(self + 0x2a, 0);
    wr(self + 0x2e, 0);
  }
  if (rd(self + 0x36) && !self[0x91]) {
    for (u32 i = 0; i < rd(self + 0x32); i++) {
      if (ext_4f00f0()) (*(v1_t **)self)[0x21c / 4](self, ((u32 *)rd(self + 0x36))[i]);
    }
    u8 *h = holder();
    (*(v2_t **)h)[0x48 / 4](h, rd(self + 0x36), rd(self + 0x32));
    wr(self + 0x36, 0);
  }
  u32 t = rd(self + 0x3a);
  if (t && !self[0x91]) {
    u8 *h = holder();
    (*(v2_t **)h)[0x4c / 4](h, t, rd(self + 0x32));
    wr(self + 0x3a, 0);
    wr(self + 0x32, 0);
  }
}
PCREG(4f0c10, fn4f0c10);

extern "C" u8 THISCALL ext_5184f0(void *self, void *s);  // ret 4
extern "C" void THISCALL ext_5274f0(void *self, void *s);  // ret 4
extern "C" void THISCALL ext_513f50(void *self, void *s);  // ret 4

// 0x51f880, thiscall(s) ret 4, returns bool: when 0x5184f0(this, s) is zero returns 0. Else s->slot 0x3c(this[0x1654]), 0x64(this[0x1658]), 0x3c(this[0x165c]),
// 0x68(this+0x1660, +0x166c, +0x1678), 0x5274f0(this+0x1684, s), s->slot 0x44(this[0x16d5] unaligned), 0x68(this+0x16d9), 0x513f50(this+0x16e5, s); returns 1.
static u8 THISCALL fn51f880(u8 *self, u8 *s) {
  if (!ext_5184f0(self, s)) return 0;
  (*(v1_t **)s)[0x3c / 4](s, rd(self + 0x1654));
  (*(v1_t **)s)[0x64 / 4](s, rd(self + 0x1658));
  (*(v1_t **)s)[0x3c / 4](s, rd(self + 0x165c));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(self + 0x1660));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(self + 0x166c));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(self + 0x1678));
  ext_5274f0(self + 0x1684, s);
  (*(v1_t **)s)[0x44 / 4](s, rd(self + 0x16d5));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(self + 0x16d9));
  ext_513f50(self + 0x16e5, s);
  return 1;
}
PCREG(51f880, fn51f880);
