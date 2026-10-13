// batch402.cpp - 0x420200 (gap band, parked row). stdcall, one argument vk, ret 4. Calls the import GetAsyncKeyState (USER32)
// through IAT slot 0x6761a0 with vk and returns bit 15 of the result's low word (shr ax, 15; and al, 1).
#include "ff.h"

typedef u32(STDCALL *GetAsyncKeyStateFn)(u32 vk);

static u8 STDCALL keyDownBit(u32 vk) {
  GetAsyncKeyStateFn fn = (GetAsyncKeyStateFn)(unsigned long)(*(u32 *)0x6761a0u);
  u16 ax = (u16)fn(vk);
  return (u8)((ax >> 15) & 1);
}
PCREG(420200, keyDownBit);
