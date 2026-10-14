// batch34032.cpp - cascade tier E, batch 34032: 0x5c92a0 (re-resolve a target and notify), 0x5d4a70 (read five fields from a stream), 0x638cf0 (copy a rectangle
// of dwords out of a surface).
#include "ff.h"

extern "C" void THISCALL ext_5c9330(void *self, u32 a);   // thiscall ret 4
extern "C" u32 THISCALL ext_4e5e60(void *stream);         // thiscall, plain ret: next dword of the stream

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5c92a0, thiscall, no args: [this+0x80] = 0; s = engine table slot 0x58([this+0x70]); y = s->slot0x2f4(); 0x5c9330(this, 0); [this+0x44]->slot0x288(s, 0, 1);
// v = engine table slot 0x114(0x6a4e60, 0, 0x6b49b8, 0x1a6, 0, 0) (six stack args); y->slot0x128((u16)v).
static void THISCALL fn5c92a0(u8 *self) {
  u32 x = *(u32 *)(self + 0x70);
  *(u32 *)(self + 0x80) = 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *s = vcall<u8 *>(tbl, 0x58, x);
  u8 *y = vcall<u8 *>(s, 0x2f4);
  ext_5c9330(self, 0);
  vcall<void>(*(u8 **)(self + 0x44), 0x288, (u32)s, 0u, 1u);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x114, 0x6a4e60u, 0u, 0x6b49b8u, 0x1a6u, 0u, 0u);
  vcall<void>(y, 0x128, (u32)(u16)v);
}
PCREG(5c92a0, fn5c92a0);

// 0x5d4a70, thiscall(s) ret 4: a, b, c, d, e = five dwords read from s (0x4e5e60); [this+0x58] = c; [this+0x54] = e; [this+0x48] = engine table slot 0x58(b);
// [this+0x61] = d (unaligned); [this+0x4c] = [this+0x50] = a.
static void THISCALL fn5d4a70(u8 *self, u8 *s) {
  u32 a = ext_4e5e60(s);
  u32 b = ext_4e5e60(s);
  u32 c = ext_4e5e60(s);
  u32 d = ext_4e5e60(s);
  u32 e = ext_4e5e60(s);
  *(u32 *)(self + 0x58) = c;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 obj = vcall<u32>(tbl, 0x58, b);
  *(u32 *)(self + 0x54) = e;
  *(u32 *)(self + 0x48) = obj;
  wr32u(self + 0x61, d);
  *(u32 *)(self + 0x4c) = a;
  *(u32 *)(self + 0x50) = a;
}
PCREG(5d4a70, fn5d4a70);

// 0x638cf0, thiscall(dst, x, y, w, h, stride, id) ret 0x1c: o = this->slot0x38(id); src = [o+0x10] (dword pixels), pitch = [o+4]; for each of h rows (h > 0):
// copy w dwords from src[(y*pitch + x + row*pitch)] to dst, dst advances by stride BYTES per row.
static void THISCALL fn638cf0(u8 *self, u8 *dst, s32 x, s32 y, s32 w, s32 h, s32 stride, u32 id) {
  u8 *o = vcall<u8 *>(self, 0x38, id);
  s32 idx = *(s32 *)(o + 4) * y + x;
  u32 *src = *(u32 **)(o + 0x10);
  if (h <= 0) return;
  do {
    if (w > 0) {
      for (s32 i = 0; i < w; i++) ((u32 *)dst)[i] = src[idx + i];
    }
    dst += stride;
    idx += *(s32 *)(o + 4);
    h -= 1;
  } while (h != 0);
}
PCREG(638cf0, fn638cf0);
