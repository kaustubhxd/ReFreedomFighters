// batch34133.cpp - cascade tier E, batch 34133: 0x63a770 (aligned realloc-copy).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);                  // cdecl alloc
extern "C" void ext_634273(u32 p, u32 flag);          // cdecl free
typedef void *(*memmove_t)(void *, const void *, u32);

// 0x63a770, cdecl(old, newsize): a = [0x70038c]->slot0x48(0x80ff80), b = same call again (both thiscall, 1 arg); p = ext_41e290(newsize + 0x10); r = (p + 0x10) & ~0xf; [r-4] = p;
// engine->slot0x48(b); engine->slot0x48(a) (restoring the two values); memmove(r, old, [old-8] & 0x1fffffff) (import [0x676278]); ext_634273([old-4], 1); returns r.
static u32 fn63a770(u8 *old, u32 newsize) {
  u8 *eng = G(u8 *, 0x70038c);
  u32 a = vcall<u32>(eng, 0x48, 0x80ff80u);
  eng = G(u8 *, 0x70038c);
  u32 b = vcall<u32>(eng, 0x48, 0x80ff80u);
  u32 p = ext_41e290(newsize + 0x10);
  u32 r = (p + 0x10) & 0xfffffff0;
  *(u32 *)(r - 4) = p;
  eng = G(u8 *, 0x70038c);
  vcall<u32>(eng, 0x48, b);
  eng = G(u8 *, 0x70038c);
  vcall<u32>(eng, 0x48, a);
  G(memmove_t, 0x676278)((void *)r, old, *(u32 *)(old - 8) & 0x1fffffff);
  ext_634273(*(u32 *)(old - 4), 1);
  return r;
}
PCREG(63a770, fn63a770);
