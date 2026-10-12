// batch6369.cpp - unclaimed-63 batch 69: 0x4a2ba0 ZParamAnim::Save(ZSaveGame*) (GUESS name; area 23 skipped it), thiscall, one stack
//   argument s, ret 4, returns true (al = 1). this[+4] &= ~0x40; s->vtbl[+0x60](byte this[+0x48]); s->vtbl[+0x40](word this[+0x11a]);
//   s->vtbl[+0x54](dword this[+0x49]); s->vtbl[+0x54](dword this[+0x4d]); s->vtbl[+0x4c](float this[+0x51]); s->vtbl[+0x4c](float this[+0x55]);
//   s->vtbl[+0x60](byte this[+0x11d]); s->vtbl[+0x4c](float this[+0x11e]); the embedded object at this+0x59: its vtbl[+0x18](&this[+0x59], s).
#include "ff.h"

typedef void(THISCALL * u1_fn)(void *, u32);
typedef void(THISCALL * f1_fn)(void *, float);
typedef void(THISCALL * emb_fn)(void *, u32);

// 0x4a2ba0 (GUESS name ZParamAnim::Save).
static u8 THISCALL unnamed4a2ba0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 vs = *(u32 *)s;
  ((u1_fn)(*(u32 *)(vs + 0x60)))((void *)s, (u32)*(u8 *)(self + 0x48));
  ((u1_fn)(*(u32 *)(vs + 0x40)))((void *)s, (u32)*(u16 *)(self + 0x11a));
  ((u1_fn)(*(u32 *)(vs + 0x54)))((void *)s, *(u32 *)(self + 0x49));
  ((u1_fn)(*(u32 *)(vs + 0x54)))((void *)s, *(u32 *)(self + 0x4d));
  ((f1_fn)(*(u32 *)(vs + 0x4c)))((void *)s, *(float *)(self + 0x51));
  ((f1_fn)(*(u32 *)(vs + 0x4c)))((void *)s, *(float *)(self + 0x55));
  ((u1_fn)(*(u32 *)(vs + 0x60)))((void *)s, (u32)*(u8 *)(self + 0x11d));
  ((f1_fn)(*(u32 *)(vs + 0x4c)))((void *)s, *(float *)(self + 0x11e));
  u8 *mem = self + 0x59;
  ((emb_fn)(*(u32 *)(*(u32 *)mem + 0x18)))((void *)mem, (u32)s);
  return 1;
}
PCREG(4a2ba0, unnamed4a2ba0);
