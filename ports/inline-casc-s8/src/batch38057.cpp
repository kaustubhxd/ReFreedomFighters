// batch38057.cpp - cascade s8 batch 38057: 0x637a30 (upload an image to a texture, with or without its mip chain).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);          // allocator, cdecl
extern "C" void ext_634273(void *p, u32 n);   // free(p, size), cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *v7_t)(void *, u32, u32, u32, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

static u32 bytes_for(u32 w, u32 h) {
  u32 n = h * w;
  u64 prod = (u64)n * 4;
  return (prod >> 32) ? 0xffffffffu : (u32)prod;
}

// 0x637a30, thiscall(src, genMips) ret 8. Copies the size of the source image (slots 0x1c / 0x20 of src) into this (slots 0x74 / 0x78); with genMips the level count is 1 + the bit length of
// max(width, height) / 2 (this's own size), otherwise 1; this slot 0x5c(levels). When the source holds exactly the requested mip chain (src slot 0x34 > 1 and == levels) every level is read with
// src slot 0x10(buf, 0, 0, w, h, 4 * w, level) and stored with this slot 0x70(level, w, h, buf) (sizes halved rounding up); otherwise level 0 is read once and stored with slot 0x6c(0, w, h, buf).
// The scratch buffer comes from 0x41e290 and is freed with 0x634273(buf, 4).
static void THISCALL fn637a30(u8 *self, u8 *src, u32 gen) {
  SLOT(self, 0x74, v1_t)(self, SLOT(src, 0x1c, v0_t)(src));
  SLOT(self, 0x78, v1_t)(self, SLOT(src, 0x20, v0_t)(src));
  u32 levels = 1;
  if ((u8)gen) {
    s32 w2 = (s32)SLOT(self, 0x1c, v0_t)(self) >> 1;
    s32 h2 = (s32)SLOT(self, 0x20, v0_t)(self);
    for (;;) {
      h2 >>= 1;
      if (w2 != 0) {
        levels++;
        w2 >>= 1;
        continue;
      }
      if (h2 == 0) break;
      levels++;
    }
  }
  SLOT(self, 0x5c, v1_t)(self, levels);
  if (levels > 1 && SLOT(src, 0x34, v0_t)(src) > 1 && SLOT(src, 0x34, v0_t)(src) == levels) {
    u32 w = SLOT(self, 0x1c, v0_t)(self);
    u32 h = SLOT(self, 0x20, v0_t)(self);
    u8 *buf = ext_41e290(bytes_for(w, h));
    for (u32 k = 0; k < levels; k++) {
      SLOT(src, 0x10, v7_t)(src, (u32)buf, 0, 0, w, h, w * 4, k);
      SLOT(self, 0x70, v4_t)(self, k, w, h, (u32)buf);
      w = (w + 1) >> 1;
      h = (h + 1) >> 1;
    }
    ext_634273(buf, 4);
    return;
  }
  u32 h = SLOT(self, 0x20, v0_t)(self);
  u32 w = SLOT(self, 0x1c, v0_t)(self);
  u8 *buf = ext_41e290(bytes_for(w, h));
  u32 w0 = SLOT(self, 0x1c, v0_t)(self);
  u32 h0 = SLOT(self, 0x20, v0_t)(self);
  u32 w1 = SLOT(self, 0x1c, v0_t)(self);
  SLOT(src, 0x10, v7_t)(src, (u32)buf, 0, 0, w1, h0, w0 * 4, 0);
  u32 h2 = SLOT(self, 0x20, v0_t)(self);
  u32 w2 = SLOT(self, 0x1c, v0_t)(self);
  SLOT(self, 0x6c, v4_t)(self, 0, w2, h2, (u32)buf);
  ext_634273(buf, 4);
}
PCREG(637a30, fn637a30);
