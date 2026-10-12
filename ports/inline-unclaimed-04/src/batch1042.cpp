// batch1042.cpp - unclaimed-04 batch 42 (docs/20-unclaimed-04.md): 0x5f3ff0, thiscall, one stack argument a (ret 4).
#include "ff.h"

typedef u32(THISCALL *f3_t)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *f2_t)(void *self, u32 a, u32 b);

extern "C" u32 THISCALL ext_5ffb70(void *self, u32 key);  // tree search (batch 40), original code
extern "C" void *__attribute__((cdecl)) ext_5fa630(void);  // claimed elsewhere; hooked by address in the spec (GUESS)

// 0x5f3ff0: b = tree search(a) on the tree at this+0x96; b == 0 returns 0. Else y = X->vt[0x48](this, a, b+8) with X = 0x5fa630();
// y != 0 calls y->vt[0x48](b, this); returns y.
static u32 THISCALL unk5f3ff0(u8 *self, u32 a) {
  u8 *tree = *(u8 **)(self + 0x96);
  u32 b = ext_5ffb70(tree, a);
  if (b == 0) return 0;
  u8 *x = (u8 *)ext_5fa630();
  u32 y = ((f3_t)(*(u32 *)(*(u32 *)x + 0x48)))(x, (u32)self, a, *(u32 *)(b + 8));
  if (y != 0) ((f2_t)(*(u32 *)(*(u32 *)y + 0x48)))((void *)y, b, (u32)self);
  return y;
}
PCREG(5f3ff0, unk5f3ff0);
