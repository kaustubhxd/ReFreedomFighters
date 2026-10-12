// batch2306.cpp - unclaimed-23 batch 6 (docs/20-unclaimed-23.md): ZRepositionCharacter::Init() at 0x5c41a0. Name from the GC
// name map (high). R = o->vtbl[+0x138]() with o = [[0x70039c]+0x9b]. Then, with this = ESI:
//   * if this is 0, or M = [0x70038c] has vtbl[+0x20](this) != 0: v = 0;
//   * else if M[+8] != 0 and not (M[+0xc] > this) and not (this >= M[+0x10]) (unsigned): v = M[+8](ECX = this);
//   * else: if [this-4] == 0 then M->vtbl[+0xac](this); v = [this-4].
//   then R->vtbl[+0x60](0x6b20cc, v, 0x10) (thiscall, three stack arguments, callee pops 12).
// Callee pops 0 (ret).
#include "ff.h"

typedef u32(THISCALL * call0_fn)(void *);
typedef u32(THISCALL * call1_fn)(void *, u32);
typedef void(THISCALL * call3_fn)(void *, u32, u32, u32);

// 0x5c41a0 (high).
static void THISCALL repositionCharacterInit(u8 *self) {
  u32 o = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 r = ((call0_fn)(*(u32 *)(*(u32 *)o + 0x138)))((void *)o);
  u32 v = 0;
  u32 me = (u32)self;
  if (me != 0) {
    u32 m = G(u32, 0x70038c);
    if (((call1_fn)(*(u32 *)(*(u32 *)m + 0x20)))((void *)m, me) == 0) {
      u32 fn = *(u32 *)(m + 8);
      if (fn != 0 && !(*(u32 *)(m + 0xc) > me) && !(me >= *(u32 *)(m + 0x10))) {
        v = ((call0_fn)fn)((void *)me);
      } else {
        if (*(u32 *)(me - 4) == 0)
          ((call1_fn)(*(u32 *)(*(u32 *)m + 0xac)))((void *)m, me);
        v = *(u32 *)(me - 4);
      }
    }
  }
  ((call3_fn)(*(u32 *)(*(u32 *)r + 0x60)))((void *)r, 0x6b20cc, v, 0x10);
}
PCREG(5c41a0, repositionCharacterInit);
