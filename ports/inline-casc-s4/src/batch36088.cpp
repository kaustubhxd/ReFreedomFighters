// batch36088.cpp - cascade s4 batch 36088: 0x529d70 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_516d10(void *self, u32 s);   // ret 4

// 0x529d70, thiscall(s) ret 4, returns al = 1 (this = t): reads from the stream s: slot 0x6c -> t+4; slot 0x18(t+0x10, 4); slot 0x50 -> t+0x14; slot 0x40(&id), t[0x18] = sys[0x9b]->slot 0x58(id);
// slot 0x6c -> t+0x1c; slot 0x68 -> t+0x28; slot 0x50 -> t+0x29, 0x2d, 0x31, 0x35, 0x39; 0x516d10(t+0x3d, s); 0x516d10(t+0xb6, s).
static u8 THISCALL fn529d70(u8 *t, u8 *s) {
  u32 id;
  (*(v1_t **)s)[0x6c / 4](s, (u32)(t + 4));
  (*(v2_t **)s)[0x18 / 4](s, (u32)(t + 0x10), 4);
  (*(v1_t **)s)[0x50 / 4](s, (u32)(t + 0x14));
  (*(v1_t **)s)[0x40 / 4](s, (u32)&id);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(t + 0x18, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  (*(v1_t **)s)[0x6c / 4](s, (u32)(t + 0x1c));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(t + 0x28));
  static const u8 offs[5] = {0x29, 0x2d, 0x31, 0x35, 0x39};
  for (int i = 0; i < 5; i++) (*(v1_t **)s)[0x50 / 4](s, (u32)(t + offs[i]));
  ext_516d10(t + 0x3d, (u32)s);
  ext_516d10(t + 0xb6, (u32)s);
  return 1;
}
PCREG(529d70, fn529d70);
