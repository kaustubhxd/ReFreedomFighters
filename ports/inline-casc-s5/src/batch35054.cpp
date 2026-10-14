// batch35054.cpp - cascade s5 batch 35054: 0x4a30c0 (GUESS react to a matching message id by building a record and storing the result).
#include "ff.h"

extern "C" u8 *THISCALL ext_4db3b0(u8 *self);                                              // plain ret
extern "C" u32 THISCALL ext_43ec00(u8 *self, u8 *a, u8 *b, u32 c, u32 d, u32 e, u32 f);    // ret 0x18
typedef void(THISCALL *v2_t)(void *, void *, void *);
typedef void(THISCALL *v1_t)(void *, u32);

static inline u32 rd16u(const u8 *p) { return p[0] | p[1] << 8; }

// 0x4a30c0, thiscall(id, unused) ret 8, returns 1 when the low word of id equals the unaligned word at +0x4d, else 0. On a match: s = 0x4db3b0([[this+0x44]+8]); [this+0x44] slot 0x80(l34, l10)
// fills a 0x24-byte and a 12-byte local; [this+0x50] = 0x43ec00(s, l34, l10, [this+0x48], 0, 0, 0); when byte +0x4f is set this slot 0x64(0x10).
static u32 THISCALL fn4a30c0(u8 *self, u32 id, u32 unused) {
  u8 l34[0x24];
  u8 l10[0xc];
  (void)unused;
  if ((u16)id != rd16u(self + 0x4d)) return 0;
  u8 *o = *(u8 **)(self + 0x44);
  u8 *s = ext_4db3b0(*(u8 **)(o + 8));
  o = *(u8 **)(self + 0x44);
  (*(v2_t **)o)[0x80 / 4](o, l34, l10);
  u32 r = ext_43ec00(s, l34, l10, *(u32 *)(self + 0x48), 0, 0, 0);
  *(u32 *)(self + 0x50) = r;
  if (self[0x4f]) (*(v1_t **)self)[0x64 / 4](self, 0x10);
  return 1;
}
PCREG(4a30c0, fn4a30c0);
