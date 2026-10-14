// batch35072.cpp - cascade s5 batch 35072: 0x4fd510 (GUESS read six words from a stream, register the entry and look up a resource handle).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e40(u8 *stream);   // plain ret, word in AX
typedef u8 *(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *g4_t)(void *, u32, u32, u32, u32);

static inline void wr16(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; }

// 0x4fd510, thiscall(s) ret 4. Seven reads 0x4e5e40(s): words 1, 2, 4, 5, 6, 7 are stored (low 16 bits) at +0x54, +0x56, +0x58, +0x5a, +0x5c, +0x5e; the third is dropped. With tab = [engine+0x9b]: o = tab slot 0x138();
// id = tab slot 0x4c([this+0x44]); o slot 0x4c(0x688f80, id); [this+0x60] = low word of tab slot 0x114(0x691fdc, 0, 0x69c54c, 0x250).
static void THISCALL fn4fd510(u8 *self, u8 *s) {
  wr16(self + 0x54, ext_4e5e40(s));
  wr16(self + 0x56, ext_4e5e40(s));
  ext_4e5e40(s);
  wr16(self + 0x58, ext_4e5e40(s));
  wr16(self + 0x5a, ext_4e5e40(s));
  wr16(self + 0x5c, ext_4e5e40(s));
  wr16(self + 0x5e, ext_4e5e40(s));
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 f = (*(u32 **)o)[0x4c / 4];
  u32 id = (*(g1_t **)tab)[0x4c / 4](tab, *(u32 *)(self + 0x44));
  ((v2_t)f)(o, 0x688f80, id);
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u32 w = (*(g4_t **)tab)[0x114 / 4](tab, 0x691fdc, 0, 0x69c54c, 0x250);
  wr16(self + 0x60, w);
}
PCREG(4fd510, fn4fd510);
