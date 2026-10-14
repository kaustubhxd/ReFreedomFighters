// batch35141.cpp - cascade s5 batch 35141: 0x5b7660 (GUESS fetch a position, pass it to two objects and trigger the owner when the second accepts it).
#include "ff.h"

extern "C" void THISCALL ext_4daf90(u32 self, u32 *out);          // thiscall, ret 4: fills a 12-byte vector
extern "C" void THISCALL ext_597fc0(u32 self, u32 a, u32 b);      // thiscall, ret 8
typedef void(THISCALL *v1p_t)(void *, u32 *);
typedef u8(THISCALL *b2_t)(void *, u32 *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5b7660, thiscall, no arguments. v (12 bytes) = 0x4daf90([[this+0x50]+8]); [this+0x50] slot 0x84(&v); [this+0x44] slot 0x8c(&v); then [this+0x44] slot 0x180(&v, -10.0f) (AL): when true
// 0x597fc0(unaligned dword [[this+0x50]+0x852], [this+0x4c], 1) and this slot 0x68(0x10, 0).
static void THISCALL fn5b7660(u8 *self) {
  u32 v[3];
  u8 *p = *(u8 **)(self + 0x50);
  ext_4daf90(*(u32 *)(p + 8), v);
  (*(v1p_t **)p)[0x84 / 4](p, v);
  u8 *q = *(u8 **)(self + 0x44);
  (*(v1p_t **)q)[0x8c / 4](q, v);
  q = *(u8 **)(self + 0x44);
  if ((*(b2_t **)q)[0x180 / 4](q, v, 0xc1200000)) {
    ext_597fc0(rd32u(*(u8 **)(self + 0x50) + 0x852), *(u32 *)(self + 0x4c), 1);
    (*(v2_t **)self)[0x68 / 4](self, 0x10, 0);
  }
}
PCREG(5b7660, fn5b7660);
