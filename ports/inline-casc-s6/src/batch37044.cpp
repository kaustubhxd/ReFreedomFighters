// batch37044.cpp - cascade s6 batch 37044: 0x48fae0.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);                // free, cdecl
extern "C" void THISCALL ext_49b680(u8 *s);              // plain ret
typedef u32(THISCALL *v0_t)(void *);
typedef void(THISCALL *dt_t)(void *, u32);
#define F32(o) (*(u32 *)(self + (o)))
#define ENG (*(u8 **)0x70039c)
#define CALL0(o, off) ((*(v0_t **)(o))[(off) / 4]((o)))

static void freeField(u8 *self, u32 off, u32 n, bool clearAfter = true) {
  u8 *p = (u8 *)F32(off);
  if (p) {
    ext_634273(p, n);
    if (clearAfter) F32(off) = 0;
  }
}

// 0x48fae0, thiscall, no args: shutdown of the game state object. Notifies the engine (slots 0x14 / 0x28 / 0xc8 / 0x10), runs its own virtuals (0x198, 0xe8, 0xdc, 0x194,
// 0x6c, 0x48, 0x3c), releases the manager at [[engine+0x1aa3]+0x1c], frees the buffers at +0xbb7 / +0xbbb / +0xaf4 / +0x5d35 (after 0x49b680) / +0x1c5d / +0x44, clears the list
// at +0x1c61, walks the engine's object chain at [engine+0x190f] (slots 0x94 / 0x3c, next at +8), destroys the object at +0xc (slot 0, 1), tells the allocator at 0x70038c
// (slot 0x38) and finally calls slot 1 of the object at 0x7003b4 (tail call).
static void THISCALL fn48fae0(u8 *self) {
  u8 *e = ENG;
  CALL0(e, 0x14);
  CALL0(self, 0x198);
  u8 *m = *(u8 **)(*(u8 **)(ENG + 0x1aa3) + 0x1c);
  if (m) CALL0(m, 0x10);
  freeField(self, 0xbb7, 1);
  freeField(self, 0xbbb, 1);
  freeField(self, 0xaf4, 0);
  CALL0(self, 0xe8);
  CALL0(self, 0xdc);
  e = ENG;
  CALL0(e, 0x28);
  u8 *o = *(u8 **)(*(u8 **)(ENG + 0x9b) + 0x5d31);
  CALL0(o, 8);
  u8 *s = (u8 *)F32(0x5d35);
  if (s) {
    ext_49b680(s);
    ext_634273(s, 0x41);
    F32(0x5d35) = 0;
  }
  u8 *l = self + 0x1c61;
  CALL0(l, 0xc);
  u8 *p = (u8 *)F32(0x1c5d);
  if (p) {
    F32(0x1c5d) = 0;
    ext_634273(p, 0);
  }
  freeField(self, 0x44, 0x18);
  u8 *n = *(u8 **)(ENG + 0x190f);
  while (n) {
    CALL0(n, 0x94);
    CALL0(n, 0x3c);
    n = *(u8 **)(n + 8);
  }
  e = ENG;
  CALL0(e, 0xc8);
  CALL0(self, 0x194);
  CALL0(self, 0x6c);
  u8 *d = (u8 *)F32(0xc);
  if (d) {
    (*(dt_t **)d)[0](d, 1);
    F32(0xc) = 0;
  }
  CALL0(self, 0x48);
  u8 *g = *(u8 **)0x70038c;
  if (g) CALL0(g, 0x38);
  CALL0(self, 0x3c);
  e = ENG;
  CALL0(e, 0x10);
  u8 *h = *(u8 **)0x7003b4;
  if (h) CALL0(h, 4);
}
PCREG(48fae0, fn48fae0);
