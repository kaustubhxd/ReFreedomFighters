// batch35015.cpp - cascade s5 batch 35015: 0x57d160 (GUESS release the buffer at +0x32c and every entry the embedded list at +0x23c yields).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);          // CRT free-style, cdecl
extern "C" void THISCALL ext_4cbec0(u8 *self);       // plain ret
typedef void(THISCALL *v1_t)(void *, void *);
typedef u32(THISCALL *g1_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);

// 0x57d160, thiscall, no arguments. [this+0x32c] (when set) is freed (size 1) and cleared. The list object embedded at this+0x23c (vtable at its start): slot 0x4c(&it) starts the
// iteration, e = slot 0x5c(&it); while it[0] != 0: s = slot 0xcc(e) of the object at 0x70038c; when non-null 0x4cbec0(s + 0x2c) and free(s, 0xe1); then slot 0x44(&it) and the next e.
static void THISCALL fn57d160(u8 *self) {
  u32 it[3];
  void *p = *(void **)(self + 0x32c);
  if (p) ext_634273(p, 1);
  *(u32 *)(self + 0x32c) = 0;
  u8 *c = self + 0x23c;
  (*(v1_t **)c)[0x4c / 4](c, it);
  u32 e = (*(g1_t **)c)[0x5c / 4](c, it);
  if (it[0] == 0) return;
  do {
    u8 *eng = G(u8 *, 0x70038c);
    u8 *s = (*(e1_t **)eng)[0xcc / 4](eng, e);
    if (s) {
      ext_4cbec0(s + 0x2c);
      ext_634273(s, 0xe1);
    }
    (*(v1_t **)c)[0x44 / 4](c, it);
    e = (*(g1_t **)c)[0x5c / 4](c, it);
  } while (it[0] != 0);
}
PCREG(57d160, fn57d160);
