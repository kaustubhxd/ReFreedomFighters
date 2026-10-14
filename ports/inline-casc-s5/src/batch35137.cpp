// batch35137.cpp - cascade s5 batch 35137: 0x655ab0 (GUESS append n bytes to the engine's scratch buffer and return the offset).
#include "ff.h"

extern "C" void ext_42ab62(u32 fmt, u32 a, u32 b, u32 c);        // cdecl, printf-style report (four args)
extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x655ab0, stdcall(src, n) ret 8, returns EAX. X = unaligned dword [engine+0x1aa3]; base = [X+0x20]. base == 0: the assert hook and return (EAX is the hook's). Otherwise p = [X+0x28], [X+0x28] = p + n; when the new cursor is above [X+0x24]
// the report 0x42ab62(0x6c3d48, n, cursor, limit) and the assert hook run; memcpy(p, src, n); returns p - base.
static u32 STDCALL fn655ab0(const u8 *src, u32 n) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *X = (u8 *)rd32u(eng + 0x1aa3);
  u32 base = *(u32 *)(X + 0x20);
  if (!base) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    return h();
  }
  u32 p = *(u32 *)(X + 0x28);
  *(u32 *)(X + 0x28) = p + n;
  eng = G(u8 *, 0x70039c);
  X = (u8 *)rd32u(eng + 0x1aa3);
  u32 cur = *(u32 *)(X + 0x28);
  u32 lim = *(u32 *)(X + 0x24);
  if (cur > lim) {
    ext_42ab62(0x6c3d48, n, cur, lim);
    assert_hook();
  }
  ext_634d22((void *)p, src, n);
  return p - base;
}
PCREG(655ab0, fn655ab0);
