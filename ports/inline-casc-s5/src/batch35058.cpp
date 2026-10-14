// batch35058.cpp - cascade s5 batch 35058: 0x468420 (GUESS copy another object's state and notify the owner).
#include "ff.h"

extern "C" void THISCALL ext_4cbee0(u8 *self, u8 *src);   // thiscall, ret 4
typedef u8 *(THISCALL *g0_t)(void *);
typedef u8(THISCALL *b1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v0_t)(void *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x468420, thiscall(src) ret 4. Copies from src: dwords +0x4e, +0x53, +0x57, +0x5b, +0xe1 (unaligned), bytes +0x52, +0x5f, +0x60, +0xe5 and, with 0x4cbee0(this + 0x61, src + 0x61), the part at +0x61.
// Then w = [this+0x44] slot 0x20(); when w slot 0x1e0(0x1007d3) (AL) is true: [this+0x44] slot 0x20() again, then slot 0x2dc([this+0x44], [this+0x4e]) on its result; otherwise this slot 0x58().
static void THISCALL fn468420(u8 *self, u8 *src) {
  wr32u(self + 0x4e, rd32u(src + 0x4e));
  self[0x52] = src[0x52];
  wr32u(self + 0x53, rd32u(src + 0x53));
  wr32u(self + 0x57, rd32u(src + 0x57));
  wr32u(self + 0x5b, rd32u(src + 0x5b));
  self[0x5f] = src[0x5f];
  self[0x60] = src[0x60];
  ext_4cbee0(self + 0x61, src + 0x61);
  u32 v = rd32u(src + 0xe1);
  u8 *own = *(u8 **)(self + 0x44);
  wr32u(self + 0xe1, v);
  self[0xe5] = src[0xe5];
  u8 *w = (*(g0_t **)own)[0x20 / 4](own);
  if ((*(b1_t **)w)[0x1e0 / 4](w, 0x1007d3)) {
    own = *(u8 **)(self + 0x44);
    w = (*(g0_t **)own)[0x20 / 4](own);
    (*(v2_t **)w)[0x2dc / 4](w, (u32)*(u8 **)(self + 0x44), rd32u(self + 0x4e));
    return;
  }
  (*(v0_t **)self)[0x58 / 4](self);
}
PCREG(468420, fn468420);
