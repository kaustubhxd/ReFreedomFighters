// batch35027.cpp - cascade s5 batch 35027: 0x41f720 (GUESS make a shared counted string unique before writing to it).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
extern "C" void THISCALL ext_41f190(u8 *self, u8 *data);         // thiscall, ret 4
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x41f720, thiscall(pp, b, c) ret 0xc. d = *pp (string data: refcount at d-0xc, length|flags at d-8). pool = unaligned dword [[engine+0x9b]+0x1c5d]: when it is non-null and
// pool <= d < pool + (pool[-8] & 0x1fffffff) the assert hook 0x7003b0 is called (int3 when null). When the refcount is not 1: x = this slot 0xa8(this slot 0xb0(len, b, c)) with len =
// d[-8] & 0x1fffffff, memcpy(x, d, len), *pp = x, refcount--, 0x41f190(this, d).
static void THISCALL fn41f720(u8 *self, u32 **pp, u32 b, u32 c) {
  u8 *d = *(u8 **)pp;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *pool = (u8 *)rd32u(*(u8 **)(eng + 0x9b) + 0x1c5d);
  if (d >= pool && pool) {
    if (d < pool + (*(u32 *)(pool - 8) & 0x1fffffff)) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
  }
  if (*(s32 *)(d - 0xc) == 1) return;
  u32 len = *(u32 *)(d - 8) & 0x1fffffff;
  u32 r = vcall<u32>(self, 0xb0, len, b, c);
  u8 *x = (u8 *)vcall<u32>(self, 0xa8, r);
  ext_634d22(x, d, *(u32 *)(d - 8) & 0x1fffffff);
  *(u8 **)pp = x;
  *(s32 *)(d - 0xc) -= 1;
  ext_41f190(self, d);
}
PCREG(41f720, fn41f720);
