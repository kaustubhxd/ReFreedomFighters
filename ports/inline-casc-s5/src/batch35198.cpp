// batch35198.cpp - cascade s5 batch 35198 (tier H): 0x561720 (GUESS centre a row of text items: measure the visible span and move the container).
#include "ff.h"
#include <xmmintrin.h>

extern "C" void THISCALL ext_4db500(u8 *self, float *out);          // copies the three dwords at self+0x24, ret 4
extern "C" u8 *THISCALL ext_4db520(u8 *self);                         // next sibling, plain ret
extern "C" void THISCALL ext_5618b0(u8 *self, u8 *a, u8 *b);          // ret 8
typedef u8(THISCALL *b1_t)(void *, u32);
typedef s32(THISCALL *l1_t)(void *, u32);
typedef void(THISCALL *p1_t)(void *, float *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline s32 cvtt(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

// 0x561720, thiscall(a, flag) ret 8, no return value (stack cookie not reproduced). Walks the list at [a+0x50] (next at +0x60); for each node's item X = node[0x54] with bit 10 of [X[8]+0x3c] clear: the first one gives firstVal = (int)float [X[8]+0x24] (0x4db500); each later one calls 0x5618b0(this, previous, X);
// the last such item is L. Without one nothing else happens. Then the width w of L's last element: Y = L[0x54]; loop: Z = Y[0x54]; flags = Z ? unaligned dword [[Z+0xc]+0x23] : 0x200002; flags & 0x100000 -> w = 0; Z slot 0x1e0(0x20002d) false -> Y = 0x4db520(Y), repeat;
// true: str = unaligned dword [Z+0x97] (null: w = 0), w = (int)((float)Z slot 0x290(strlen(str)) + float [Z[8]+0x24]); Y null -> w = 0. Then span = (int)((float)w + float [L[8]+0x24] - (float)firstVal); base = (flag byte) ? 0x280 : unaligned dword [engine+0x6f];
// V3 = a[8] block's floats (0x4db500), V3[0] = (float)((base - span) / 2); a slot 0x70(V3).
static void THISCALL fn561720(u8 *self, u8 *a, u32 flag) {
  u8 first = 1;
  s32 firstVal = 0;
  u8 *last = 0;
  u8 *node = *(u8 **)(a + 0x50);
  if (!node) return;
  float v1[3], v2[3], v3[3];
  do {
    u8 *X = *(u8 **)(node + 0x54);
    u8 *blk = *(u8 **)(X + 8);
    if (!((*(u32 *)(blk + 0x3c) >> 10) & 1)) {
      if (first) {
        ext_4db500(blk, v1);
        firstVal = cvtt(v1[0]);
        first = 0;
        last = X;
      } else {
        ext_5618b0(self, last, X);
        last = X;
      }
    }
    node = *(u8 **)(node + 0x60);
  } while (node);
  if (!last) return;
  s32 w = 0;
  u8 *Y = *(u8 **)(last + 0x54);
  for (;;) {
    if (!Y) break;
    u8 *Z = *(u8 **)(Y + 0x54);
    u32 flags = Z ? rd32u(*(u8 **)(Z + 0xc) + 0x23) : 0x200002;
    if (flags & 0x100000) break;
    if (!(*(b1_t **)Z)[0x1e0 / 4](Z, 0x20002d)) {
      Y = ext_4db520(Y);
      continue;
    }
    u8 *str = (u8 *)rd32u(Z + 0x97);
    if (!str) break;
    ext_4db500(*(u8 **)(Z + 8), v1);
    u32 len = 0;
    while (str[len]) len++;
    s32 r = (*(l1_t **)Z)[0x290 / 4](Z, len);
    w = cvtt((float)r + v1[0]);
    break;
  }
  ext_4db500(*(u8 **)(last + 8), v2);
  float x1 = (float)w + v2[0];
  ext_4db500(*(u8 **)(a + 8), v3);
  float x0 = (float)firstVal;
  x1 = x1 - x0;
  s32 span = cvtt(x1);
  s32 base = ((u8)flag) ? 0x280 : (s32)rd32u(G(u8 *, 0x70039c) + 0x6f);
  s32 e = base - span;
  e = e / 2;
  v3[0] = (float)e;
  (*(p1_t **)a)[0x70 / 4](a, v3);
}
PCREG(561720, fn561720);
