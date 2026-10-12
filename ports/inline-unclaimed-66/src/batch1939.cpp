// batch1939.cpp - unclaimed-66 batch 40 (gap band, GUESS name). THISCALL(this), two stack args (u32, float), ret 8.
//   sys = ZSysInterface (*0x70039c); r = vtable +0x58 of [sys+0x9b] with the first argument (0 means return the constant at 0x67af2c).
//   tmp = {0, 0, 0}; r->vtable +0x84(&tmp). obj = [this+0x4b]; 0 means return 0.0f.
//   Else return 0x44ac00 (THISCALL on obj: args 0, &tmp, the float). 0x44ac00 is another area's helper (hooked by address in the spec).
#include "ff.h"

extern "C" float THISCALL ext_44ac00(u8 *self, u32 zero, u32 p, float f);  // stdcall-style args; ret 0xc (hooked in the spec)

// 0x5231c0, GUESS FUN_005231c0 (batch 40).
static float THISCALL gapQuery(u8 *self, u32 a1, float a2) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *r = (u8 *)vcall<u32>(child, 0x58, a1);
  if (!r) return *(float *)0x67af2c;
  u32 tmp[3] = {0, 0, 0};
  vcall<void>(r, 0x84, (u32)tmp);
  u8 *obj = *(u8 **)(self + 0x4b);
  if (!obj) return 0.0f;
  return ext_44ac00(obj, 0, (u32)tmp, a2);
}
PCREG(5231c0, gapQuery);
