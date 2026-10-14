// batch34026 - cascade tier E, batch 34026: 0x57e2e0 (reset a view and release its focus), 0x5cdab0 (re-initialise a screen in one of two modes),
// 0x5d4250 (read three ids from a stream and resolve two of them).
#include "ff.h"

extern "C" void THISCALL ext_562e90(void *self, u32 a, u32 b);   // thiscall ret 8
extern "C" u32 THISCALL ext_4e5e60(void *stream);                // thiscall, plain ret: next dword of the stream
extern "C" void THISCALL ext_5d0c90(void *self);
extern "C" void THISCALL ext_5d0f10(void *self);
extern "C" void THISCALL ext_5d2eb0(void *self);
extern "C" void THISCALL ext_5d2ab0(void *self);
extern "C" void THISCALL ext_5d1530(void *self);
extern "C" void THISCALL ext_5d2280(void *self);
extern "C" void THISCALL ext_5cd890(void *self);
extern "C" void THISCALL ext_5d2080(void *self);
extern "C" void THISCALL ext_5cdc60(void *self);
extern "C" void THISCALL ext_5ce0b0(void *self);

// 0x57e2e0, thiscall(a, b) ret 8: 0x562e90(this, a, b); when the engine object at +0x1907 exists its slot 0x14(0x6aad90); [this+0x320] = 0;
// slot 0xbc(1) of the members at +0x314 and +0x310; o = this->slot0x84(); o->slot0x350(0x100000, 0, [this+0x44]); slot 0xbc(0) of the member at +0x50; returns false.
static bool THISCALL fn57e2e0(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *w = *(u8 **)(eng + 0x1907);
  if (w) vcall<void>(w, 0x14, 0x6aad90u);
  u8 *m1 = *(u8 **)(self + 0x314);
  *(u32 *)(self + 0x320) = 0;
  vcall<void>(m1, 0xbc, 1u);
  vcall<void>(*(u8 **)(self + 0x310), 0xbc, 1u);
  u8 *o = vcall<u8 *>(self, 0x84);
  vcall<void>(o, 0x350, 0x100000u, 0u, *(u32 *)(self + 0x44));
  vcall<void>(*(u8 **)(self + 0x50), 0xbc, 0u);
  return false;
}
PCREG(57e2e0, fn57e2e0);

// 0x5cdab0, thiscall, no args: [this+0xb46] = 0; mode A when byte [+0xb45] == 0 and dword [+0xad5] != 5: [+0xa4c] = 0, [+0xafd] = 0, [+0xaf9] = 0, helpers
// 5d0c90, 5d2eb0, 5d2ab0, 5d1530, 5d2280, 5cd890, then 5cdc60. Otherwise mode B: [+0xa4c] = 2, helpers 5d0f10, 5d2eb0, 5d2ab0, 5d1530, 5d2080, 5d2280, 5cd890, then 5ce0b0.
static void THISCALL fn5cdab0(u8 *self) {
  bool a = self[0xb45] == 0;
  self[0xb46] = 0;
  if (a && *(u32 *)(self + 0xad5) != 5) {
    *(u32 *)(self + 0xa4c) = 0;
    *(u32 *)(self + 0xafd) = 0;
    *(u32 *)(self + 0xaf9) = 0;
    ext_5d0c90(self);
    ext_5d2eb0(self);
    ext_5d2ab0(self);
    ext_5d1530(self);
    ext_5d2280(self);
    ext_5cd890(self);
    ext_5cdc60(self);
  } else {
    *(u32 *)(self + 0xa4c) = 2;
    ext_5d0f10(self);
    ext_5d2eb0(self);
    ext_5d2ab0(self);
    ext_5d1530(self);
    ext_5d2080(self);
    ext_5d2280(self);
    ext_5cd890(self);
    ext_5ce0b0(self);
  }
}
PCREG(5cdab0, fn5cdab0);

static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5d4250, thiscall(s) ret 4: [this+0x63] = [this+0x6b] = 0 (unaligned); a, b, c = three dwords read from s (0x4e5e60); [this+0x67] = c;
// [this+0x63] = table->slot0x58(b) when b; [this+0x6b] = table->slot0x58(a) when a; byte [this+0x5a] = 1; dword [this+0x5b] = 0.
static void THISCALL fn5d4250(u8 *self, u8 *s) {
  wr32u(self + 0x63, 0);
  wr32u(self + 0x6b, 0);
  u32 a = ext_4e5e60(s);
  u32 b = ext_4e5e60(s);
  u32 c = ext_4e5e60(s);
  wr32u(self + 0x67, c);
  if (b) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    wr32u(self + 0x63, vcall<u32>(tbl, 0x58, b));
  }
  if (a) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    wr32u(self + 0x6b, vcall<u32>(tbl, 0x58, a));
  }
  self[0x5a] = 1;
  wr32u(self + 0x5b, 0);
}
PCREG(5d4250, fn5d4250);
