// batch34052.cpp - cascade tier E, batch 34052: 0x56f220 (read eleven fields from a stream), 0x576120 (read three ids and resolve them), 0x5b2300 (read a record from a stream
// when the base reader accepts).
#include "ff.h"

extern "C" void THISCALL ext_610100(void *self, void *s);   // thiscall ret 4 (an empty stub in the exe: runs for real)
extern "C" u32 THISCALL ext_4e5e60(void *stream);           // thiscall, plain ret: next dword of the stream
extern "C" bool THISCALL ext_446040(void *self, void *s);   // thiscall ret 4, bool in al

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x56f220, thiscall(s) ret 4: 0x610100(this, s), then eleven dwords read from s (0x4e5e60) stored (unaligned) at +0x19d, +0x1a1, +0x1a9, +0x199, +0x1a5, +0x1ad, +0x1b1, +0x1b5, +0x1b9, +0x1bd, +0x1c5 in
// that order.
static void THISCALL fn56f220(u8 *self, u8 *s) {
  ext_610100(self, s);
  static const u32 offs[11] = {0x19d, 0x1a1, 0x1a9, 0x199, 0x1a5, 0x1ad, 0x1b1, 0x1b5, 0x1b9, 0x1bd, 0x1c5};
  for (int i = 0; i < 11; i++) wr32u(self + offs[i], ext_4e5e60(s));
}
PCREG(56f220, fn56f220);

// 0x576120, thiscall(s) ret 4: 0x610100(this, s); a, b, c = three dwords from s; [this+0x1dc] = engine table slot 0x58(a), [this+0x221] = slot 0x58(b), [this+0x225] = slot 0x58(c) (the last two
// unaligned).
static void THISCALL fn576120(u8 *self, u8 *s) {
  ext_610100(self, s);
  u32 a = ext_4e5e60(s);
  u32 b = ext_4e5e60(s);
  u32 c = ext_4e5e60(s);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x1dc) = vcall<u32>(tbl, 0x58, a);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr32u(self + 0x221, vcall<u32>(tbl, 0x58, b));
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr32u(self + 0x225, vcall<u32>(tbl, 0x58, c));
}
PCREG(576120, fn576120);

// 0x5b2300, thiscall(s) ret 4, returns bool: false when 0x446040(this, s) rejects; otherwise s slot 0x68(this+0x197), s slot 0x40(&id), [this+0x198] = engine table slot 0x58(id), s slot 0x74(this+0x19c),
// s slot 0x6c(this+0x1c0); true.
static bool THISCALL fn5b2300(u8 *self, u8 *s) {
  if (!ext_446040(self, s)) return false;
  vcall<void>(s, 0x68, (u32)(self + 0x197));
  u32 id;
  vcall<void>(s, 0x40, (u32)&id);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr32u(self + 0x198, vcall<u32>(tbl, 0x58, id));
  vcall<void>(s, 0x74, (u32)(self + 0x19c));
  vcall<void>(s, 0x6c, (u32)(self + 0x1c0));
  return true;
}
PCREG(5b2300, fn5b2300);
