// batch35084.cpp - cascade s5 batch 35084: 0x63fce0 (GUESS remove an object from a registry and destroy it).
#include "ff.h"

extern "C" void THISCALL ext_64b070(u8 *self);            // plain ret
extern "C" void THISCALL ext_648280(u8 *self);            // plain ret
extern "C" void ext_634273(void *p, u32 n);               // CRT free-style, cdecl
typedef void(THISCALL *v0_t)(void *);

// 0x63fce0, thiscall(obj) ret 4, returns bool. this slot 0x64() first. [this+0xec] = count n of the entries at +0xf0: obj not among them: this slot 0x64() again and false. Found at i: n--, entry i = the last entry,
// obj slot 0x10(), this slot 0x64(), 0x64b070(obj), [this + 4 * [obj+0x10055] + 0x6c] = 0, 0x648280(obj), free(obj, 0x182a1), this slot 0x60(), true.
static u8 THISCALL fn63fce0(u8 *self, u8 *obj) {
  (*(v0_t **)self)[0x64 / 4](self);
  u32 n = *(u32 *)(self + 0xec);
  u32 i = 0;
  if (n) {
    u32 *p = (u32 *)(self + 0xf0);
    for (;;) {
      if (*p == (u32)obj) break;
      i++;
      p++;
      if (i == n) goto notfound;
    }
    *(u32 *)(self + 0xec) -= 1;
    *(u32 *)(self + i * 4 + 0xf0) = *(u32 *)(self + *(u32 *)(self + 0xec) * 4 + 0xf0);
    (*(v0_t **)obj)[0x10 / 4](obj);
    (*(v0_t **)self)[0x64 / 4](self);
    ext_64b070(obj);
    *(u32 *)(self + *(u32 *)(obj + 0x10055) * 4 + 0x6c) = 0;
    ext_648280(obj);
    ext_634273(obj, 0x182a1);
    (*(v0_t **)self)[0x60 / 4](self);
    return 1;
  }
notfound:
  (*(v0_t **)self)[0x64 / 4](self);
  return 0;
}
PCREG(63fce0, fn63fce0);
