// batch35134.cpp - cascade s5 batch 35134: 0x463430 (GUESS allocate and clear the entry table sized by the engine, then register this node).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                       // cdecl alloc
extern "C" void ext_634d10(void *dst, u32 v, u32 n);    // cdecl memset
typedef u32(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x463430, thiscall, no arguments. X = unaligned dword [engine+0x1aa3], O = [X+0x18]: n = O slot 0xb0([[this+8]+0x6c]) is stored at +0x20; [this+0x6c] = X slot 0x8c(n). [this+0x1c] = alloc(n * 24, saturating to -1 on overflow);
// the block is cleared with memset(buf, 0, n * 24). r = [this+0x6c] slot 0x58(this); this slot 0x284(r, this slot 0x2cc()) (the vtable of this is read after the 0x58 call).
static void THISCALL fn463430(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *X = (u8 *)rd32u(eng + 0x1aa3);
  u8 *O = *(u8 **)(X + 0x18);
  u32 n = (*(g1_t **)O)[0xb0 / 4](O, *(u32 *)(*(u8 **)(self + 8) + 0x6c));
  *(u32 *)(self + 0x20) = n;
  eng = G(u8 *, 0x70039c);
  X = (u8 *)rd32u(eng + 0x1aa3);
  *(u32 *)(self + 0x6c) = (*(g1_t **)X)[0x8c / 4](X, n);
  u64 p = (u64)*(u32 *)(self + 0x20) * 0x18;
  u8 *buf = ext_41e290((p >> 32) ? 0xffffffffu : (u32)p);
  *(u8 **)(self + 0x1c) = buf;
  ext_634d10(buf, 0, *(u32 *)(self + 0x20) * 24);
  u8 *m = *(u8 **)(self + 0x6c);
  u32 r = (*(g1_t **)m)[0x58 / 4](m, (u32)self);
  u32 f = (*(u32 **)self)[0x284 / 4];
  u32 w = (*(g0_t **)self)[0x2cc / 4](self);
  ((v2_t)f)(self, r, w);
}
PCREG(463430, fn463430);
