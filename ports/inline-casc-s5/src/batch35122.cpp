// batch35122.cpp - cascade s5 batch 35122: 0x656e80 (GUESS resolve a handle through the owner, optionally duplicating its record's buffer).
#include "ff.h"

typedef u32 (*hook_t)();
typedef u8 *(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *h1_t)(void *, u32);
typedef u32(THISCALL *h2_t)(void *, u32, u32);

// 0x656e80, thiscall(a, flags) ret 8, returns z. x = this slot 0xc(a); y = this slot 0x5c(x); z = this slot 0x50(x, y). When the low nibble of flags is zero, z is returned. Otherwise r = this slot 0xc(z); a non-zero word [r+2] calls the
// assert hook 0x7003b0 (int3 when null); n = 36 * word [r+0xe] * dword [r+0x50]; [r+0x14] = this slot 0x50(this slot 0xc([r+0x14]), n); returns z.
static u32 THISCALL fn656e80(u8 *self, u32 a, u32 flags) {
  void **vt = *(void ***)self;
  u32 x = ((h1_t)vt[0xc / 4])(self, a);
  u32 y = ((h1_t)vt[0x5c / 4])(self, x);
  u32 z = ((h2_t)vt[0x50 / 4])(self, x, y);
  if (!(flags & 0xf)) return z;
  u8 *r = (u8 *)((h1_t)(*(void ***)self)[0xc / 4])(self, z);
  if (*(u16 *)(r + 2)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 n = (u32)*(u16 *)(r + 0xe) * *(u32 *)(r + 0x50);
  n = n * 9 * 4;
  void **vt2 = *(void ***)self;
  u32 v = ((h1_t)vt2[0xc / 4])(self, *(u32 *)(r + 0x14));
  *(u32 *)(r + 0x14) = ((h2_t)vt2[0x50 / 4])(self, v, n);
  return z;
}
PCREG(656e80, fn656e80);
