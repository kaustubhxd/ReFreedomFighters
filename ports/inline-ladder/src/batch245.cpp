// batch245.cpp - ZFFHERO::PlayCommandAnim (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x593f40 ZFFHERO::PlayCommandAnim(COMMANDANIM cmd) [, high], thiscall, ret 4.
// Nothing when the input word +0x417 has flag 0x8000000. Throttled: the last time (dword +0x94f) plus 0x200 ticks must
// have passed (signed compare with the engine tick [engine+0x40]). Then, unless slot 0x3f0() is true (busy), cmd 0, 1, 2
// start action 0x1a, 0x1b, 0x1c: slot 0x3d8(slot 0x3ec(action id)). Other values start nothing. The time is then
// stored (+0x94f = tick), also when nothing was started (GUESS: the throttle covers attempts, not only starts).
static void THISCALL heroPlayCommandAnim(u8 *self, u32 cmd) {
  if (U32(self, 0x417) & 0x8000000)
    return;
  u8 *eng = (u8 *)G(u32, 0x70039c);
  u32 stamp = U32(self, 0x94f);
  if ((s32)U32(eng, 0x40) < (s32)(stamp + 0x200))
    return;
  if (!vcall<u32>(self, 0x3f0)) {
    u32 id = cmd == 0 ? 0x1au : cmd == 1 ? 0x1bu : cmd == 2 ? 0x1cu : 0u;
    if (id) {
      u32 act = vcall<u32>(self, 0x3ec, id);
      vcall<void>(self, 0x3d8, act);
    }
  }
  if (self + 0x94f != eng + 0x40)
    U32(self, 0x94f) = U32(eng, 0x40);
}
PCREG(593f40, heroPlayCommandAnim);
