// batch33094.cpp - h3 () batch 33094: tier H float/SSE functions
#include "ff.h"

#define LOGOBJ (*(u8 **)0x700390)

typedef void (*log2_t)(u8 *, u32);

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x545e60: thiscall(s32 i, u32 *p, u32 *q, float t) ret 0x10: i >= [this+0x28] (signed): log chain (0x6a2e20, 0xbf0)/(r, 0x6a2f28); else e = [this+0xf] + 0x34*i: e[0xc..)=p[0..2]; e[0x18..)=p[0..2]; e[0x24..)=q[0..2]; e[0x30]=t
static void THISCALL fn545e60(u8 *self, s32 i, u32 *p, u32 *q, u32 t) {
  if (!(i < *(s32 *)(self + 0x28))) {
    u8 *r = vcall<u8 *>(LOGOBJ, 0x20, 0x6a2e20u, 0xbf0u);
    (*(log2_t *)(*(u8 **)r + 0x2c))(r, 0x6a2f28);
    return;
  }
  u8 *e = (u8 *)(R32(self + 0xf) + (u32)i * 0x34u);
  W32(e + 0xc, p[0]);
  W32(e + 0x10, p[1]);
  W32(e + 0x14, p[2]);
  W32(e + 0x18, p[0]);
  W32(e + 0x1c, p[1]);
  W32(e + 0x20, p[2]);
  W32(e + 0x24, q[0]);
  W32(e + 0x28, q[1]);
  W32(e + 0x2c, q[2]);
  W32(e + 0x30, t);
}
PCREG(545e60, fn545e60);
