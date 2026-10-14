// batch38008.cpp - cascade s8 batch 38008: 0x4205f0 (teardown of a game object's owned sub-objects).
#include "ff.h"

extern "C" void THISCALL ext_4317a0(void *p);
extern "C" void THISCALL ext_423440(void *p);
extern "C" void ext_634273(void *p, u32 n);   // cdecl free(p, size)
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define F32(off) (*(u32 *)(self + (off)))   /* unaligned field */
#define ENG G(u8 *, 0x70039c)

// Releases a held object: when the field is set, call its slot 0x10, then the owner's slot 0x4c with the field and clear it.
#define RELEASE(ptr)                       \
  do {                                     \
    u32 h_ = (ptr);                        \
    if (h_) {                              \
      SLOT(h_, 0x10, v0_t)((void *)h_);    \
      SLOT(self, 0x4c, v1_t)(self, (ptr)); \
      (ptr) = 0;                           \
    }                                      \
  } while (0)

// 0x4205f0, thiscall, no args, plain ret: tears down a game object. Walks the list at +0x190f (slot 0x2c on each node, next at +8), passes five held pointers to slot 0x1d0,
// frees the buffer at +0x1b4d, releases the held objects (+0x1a9f, +0x1aa7, globals 0x7003a8 / 0x7003a4, +0x1aa3, +0x223d), calls the engine and owner hooks, logs one line,
// and finally drains the embedded container at +0x2191 (slot 0x14 = more, slot 0x30 = take) handing each item to slot 0x4c.
static void THISCALL fn4205f0(u8 *self) {
  for (u32 n = F32(0x190f); n; n = *(u32 *)(n + 8)) SLOT(n, 0x2c, v0_t)((void *)n);
  SLOT(self, 0x1d0, v1_t)(self, F32(0x1aa7));
  SLOT(self, 0x1d0, v1_t)(self, F32(0x1a9f));
  SLOT(self, 0x1d0, v1_t)(self, G(u32, 0x7003a8));
  SLOT(self, 0x1d0, v1_t)(self, G(u32, 0x7003a4));
  SLOT(self, 0x1d0, v1_t)(self, F32(0x1aa3));
  u32 buf = F32(0x1b4d);
  if (buf) {
    ext_4317a0((void *)buf);
    ext_634273((void *)buf, 0x102);
  }
  F32(0x1b4d) = 0;
  SLOT(ENG, 0x14, v0_t)(ENG);
  RELEASE(F32(0x1a9f));
  SLOT(ENG, 0x10, v0_t)(ENG);
  self[0x60] = 1;
  u8 *lg = G(u8 *, 0x700390);
  void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x677fb4, 0x6c8);
  (*(log2_t **)st)[0x2c / 4](st, 0x6e4098);
  u32 p = F32(0x9b);
  if (p) SLOT(p, 0x128, v0_t)((void *)p);
  SLOT(self, 0x3c, v0_t)(self);
  p = F32(0x223d);
  if (p) SLOT(p, 0x10, v0_t)((void *)p);
  SLOT(self, 0x20, v1_t)(self, 1);
  ext_423440(self);
  RELEASE(F32(0x1aa7));
  RELEASE(G(u32, 0x7003a8));
  RELEASE(G(u32, 0x7003a4));
  RELEASE(F32(0x1aa3));
  SLOT(self, 0x4c, v1_t)(self, F32(0x223d));
  u8 *sub = self + 0x2191;
  F32(0x223d) = 0;
  if (SLOT(sub, 0x14, v0_t)(sub)) {
    do {
      u32 x = SLOT(sub, 0x30, v1_t)(sub, 0);
      SLOT(self, 0x4c, v1_t)(self, x);
    } while (SLOT(sub, 0x14, v0_t)(sub));
  }
}
PCREG(4205f0, fn4205f0);
