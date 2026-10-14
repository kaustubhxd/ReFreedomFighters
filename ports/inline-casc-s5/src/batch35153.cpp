// batch35153.cpp - cascade s5 batch 35153: 0x43fba0 (GUESS dispatch by engine mode: resolve through table slot 0x158 or through the sub-table).
#include "ff.h"

typedef u8(THISCALL *b0_t)(void *);
typedef u32 *(THISCALL *p1_t)(void *, u32);
typedef u32(THISCALL *g4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *g3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *s3_t)(void *, u32, u32, u32);

// 0x43fba0, thiscall(a, b, c, d, e) ret 0x14. tab = engine[+0x9b]; when tab slot 0x10() (al) is true: p = tab slot 0x158(c); returns this slot 0x294(a, *p, d, e). Otherwise
// edi = (tab[8]) slot 0x1c(a, b, c); null returns 0; else this slot 0x28c(edi, d, e) and returns [edi + 0x54].
static u32 THISCALL fn43fba0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 ok = (*(b0_t **)tab)[0x10 / 4](tab);
  eng = G(u8 *, 0x70039c);
  if (ok) {
    tab = *(u8 **)(eng + 0x9b);
    u32 *p = (*(p1_t **)tab)[0x158 / 4](tab, c);
    return (*(g4_t **)self)[0x294 / 4](self, a, *p, d, e);
  }
  tab = *(u8 **)(eng + 0x9b);
  u8 *sub = *(u8 **)(tab + 8);
  u8 *edi = (*(s3_t **)sub)[0x1c / 4](sub, a, b, c);
  if (!edi) return 0;
  (*(g3_t **)self)[0x28c / 4](self, (u32)edi, d, e);
  return *(u32 *)(edi + 0x54);
}
PCREG(43fba0, fn43fba0);
