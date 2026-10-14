// batch35100.cpp - cascade s5 batch 35100: 0x491a80 (GUESS reset a screen: make sure a setting is 2, clear flags, tell the engine, rebuild).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef void(THISCALL *v2p_t)(void *, u32, u32 *);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *c4_t)(void *, u32, u32, u32, u32);
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x491a80, thiscall(a) ret 4. With tab = [engine+0x9b]: o = tab slot 0x134(); v = 0; o slot 0x88(0x68e208, &v); when v != 2: tab slot 0x134() slot 0x5c(0x68e208, 1, 2). Bytes +0xbc0 and +0xbb2 = 0;
// unaligned dword [engine+0x1aab] = 0; the engine object's slot 0xc with four zero stack args (ECX = the engine object); this slot 0xa8(); this slot 0xa0(0x68d900); this slot 0x18c(a).
static void THISCALL fn491a80(u8 *self, u32 a) {
  u32 v;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x134 / 4](tab);
  v = 0;
  (*(v2p_t **)o)[0x88 / 4](o, 0x68e208, &v);
  if (v != 2) {
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    o = (*(g0_t **)tab)[0x134 / 4](tab);
    (*(v3_t **)o)[0x5c / 4](o, 0x68e208, 1, 2);
  }
  self[0xbc0] = 0;
  self[0xbb2] = 0;
  eng = G(u8 *, 0x70039c);
  wr32u(eng + 0x1aab, 0);
  eng = G(u8 *, 0x70039c);
  (*(c4_t **)eng)[0xc / 4](eng, 0, 0, 0, 0);
  (*(v0_t **)self)[0xa8 / 4](self);
  (*(v1_t **)self)[0xa0 / 4](self, 0x68d900);
  (*(v1_t **)self)[0x18c / 4](self, a);
}
PCREG(491a80, fn491a80);
