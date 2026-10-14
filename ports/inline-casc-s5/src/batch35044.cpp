// batch35044.cpp - cascade s5 batch 35044: 0x603900 (GUESS pop and release every entry of a tagged stack).
#include "ff.h"

typedef u32 (*hook_t)();
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v0_t)(void *);

// 0x603900, thiscall, no arguments. While [this+0x14] (count n) is non-zero: n == 0 inside the loop calls the assert hook 0x7003b0 (int3 when null); otherwise n--, e = [this+0xc] + 8 * n
// (dword value, kind byte at +4). Unless e is the function's own 12-byte stack local: kind 4 gives edi = value slot 0x24() (value is an object), any other kind edi = value; k = kind. Then, for
// kind 4, value slot 0x28(); kind byte = 0; and when k == 4, edi slot 0x28().
static void THISCALL fn603900(u8 *self) {
  u8 loc[12];
  while (*(u32 *)(self + 0x14) != 0) {
    u8 *edi = 0;
    u8 k = 0;
    u32 n = *(u32 *)(self + 0x14);
    if (n == 0) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    } else {
      n--;
      *(u32 *)(self + 0x14) = n;
      u8 *e = *(u8 **)(self + 0xc) + n * 8;
      if (e != loc) {
        if (e[4] == 4) {
          u8 *o = *(u8 **)e;
          edi = (u8 *)(*(g0_t **)o)[0x24 / 4](o);
        } else {
          edi = *(u8 **)e;
        }
        k = e[4];
      }
      if (e[4] == 4) {
        u8 *o = *(u8 **)e;
        (*(v0_t **)o)[0x28 / 4](o);
      }
      e[4] = 0;
      if (k == 4) (*(v0_t **)edi)[0x28 / 4](edi);
    }
  }
}
PCREG(603900, fn603900);
