// batch35118.cpp - cascade s5 batch 35118: 0x4f0ce0 (GUESS write four unaligned fields to a stream, one of them resolved through the engine table).
#include "ff.h"

extern "C" u8 THISCALL ext_4f0d70(u8 *self, u8 *s);   // thiscall, ret 4, bool in AL
typedef u32(THISCALL *g1_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4f0ce0, thiscall(s) ret 4, returns bool. When 0x4f0d70(this, s) is true (else false): x = [engine+0x9b] slot 0x4c(unaligned dword [this+0x9f]); s slot 0x44([+0x93]); s slot 0x3c(x); s slot 0x44([+0xa3]);
// s slot 0x5c(p) with p = [+0x97], or the default 0x677b5a when p is zero; true.
static u8 THISCALL fn4f0ce0(u8 *self, u8 *s) {
  if (!ext_4f0d70(self, s)) return 0;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u32 x = (*(g1_t **)tab)[0x4c / 4](tab, rd32u(self + 0x9f));
  (*(v1_t **)s)[0x44 / 4](s, rd32u(self + 0x93));
  (*(v1_t **)s)[0x3c / 4](s, x);
  (*(v1_t **)s)[0x44 / 4](s, rd32u(self + 0xa3));
  u32 p = rd32u(self + 0x97);
  (*(v1_t **)s)[0x5c / 4](s, p ? p : 0x677b5a);
  return 1;
}
PCREG(4f0ce0, fn4f0ce0);
