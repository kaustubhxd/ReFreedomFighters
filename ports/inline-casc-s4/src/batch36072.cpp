// batch36072.cpp - cascade s4 batch 36072: 0x44ab20 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void ext_634273(u32 a, u32 b);                                    // cdecl
extern "C" void *ext_41e290(u32 n);                                          // cdecl
extern "C" void THISCALL ext_4609f0(void *self, u32 a, u32 b, u32 c, u32 d);  // ret 0x10
extern "C" void THISCALL ext_460bb0(void *self);                             // plain ret

// 0x44ab20, thiscall() plain ret (this = d): d[0x18] -> 0x634273(d[0x18], 0x38), d[0x18] = 0. x = d[8][0x6c]; x == 0 -> return. G = [0x70039c][0x1aa3][0x18]; r = G->slot 0x40 (0x100)(x); n = *r; n == 0 -> return. n--; mem = malloc(n * 0x38, saturating);
// mem: n entries of 0x38 bytes each with {0x67f86c at +0, -1.0f at +0x34}. d[0x18] = mem (0 on failure). r3 = G->slot 0x3f (0xfc)(d[8][0x6c]); 0x4609f0(d + 0x1c, d[0x18], r3, n, 0.1f); 0x460bb0(d + 0x1c).
static void THISCALL fn44ab20(u8 *d) {
  u32 p = rd(d + 0x18);
  if (p) {
    ext_634273(p, 0x38);
    wr(d + 0x18, 0);
  }
  u32 x = rd(*(u8 **)(d + 8) + 0x6c);
  if (x == 0) return;
  u8 *G = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  u8 *r = (*(v1o_t **)G)[0x100 / 4](G, x);
  u32 n = rd(r);
  if (n == 0) return;
  n--;
  u64 prod = (u64)n * 0x38u;
  u8 *mem = (u8 *)ext_41e290((prod >> 32) ? 0xffffffffu : (u32)prod);
  if (mem) {
    u8 *q = mem;
    for (u32 k = n; k != 0; k--) {
      wr(q, 0x67f86c);
      q += 0x38;
      wr(q - 4, 0xbf800000);
    }
  }
  wr(d + 0x18, (u32)mem);
  u32 y = rd(*(u8 **)(d + 8) + 0x6c);
  u8 *G2 = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
  u8 *r3 = (*(v1o_t **)G2)[0xfc / 4](G2, y);
  ext_4609f0(d + 0x1c, rd(d + 0x18), (u32)r3, n, 0x3dcccccd);
  ext_460bb0(d + 0x1c);
}
PCREG(44ab20, fn44ab20);
