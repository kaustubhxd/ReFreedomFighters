// batch32125.cpp - cascade h2 (Sonnet): one tier H function (stream reader).
#include "ff.h"

extern "C" void THISCALL ext_4f9c90(u8 *self, u32 a);                 // thiscall ret 4
extern "C" void THISCALL ext_4e11e0(u8 *self, u8 *dst, u32 n);        // thiscall ret 8 (stream read into dst)
extern "C" u32 THISCALL ext_4e1600(u8 *self);                         // thiscall, plain ret, result in AL
extern "C" void THISCALL ext_4e0fd0(u8 *self, u8 *dst);               // thiscall ret 4
extern "C" void THISCALL ext_4e1b30(u8 *self);                        // thiscall, plain ret

// 0x4f7e00, thiscall(s) ret 4: 0x4f9c90(this, s); the stream s reads 1 item into this+0x8f, this+0x93, this+0x97 (0x4e11e0(s, dst, 1)); then into the argument slot itself (value v);
// 0x4e1600(s) == 9 (AL) -> 0x4e0fd0(s, this+0xb3); 0x4e1b30(s); [this+0xa3] = (float)(unsigned)v (unaligned store).
static void THISCALL fn4f7e00(u8 *self, u32 s) {
  u32 v = s;
  ext_4f9c90(self, s);
  ext_4e11e0((u8 *)s, self + 0x8f, 1);
  ext_4e11e0((u8 *)s, self + 0x93, 1);
  ext_4e11e0((u8 *)s, self + 0x97, 1);
  ext_4e11e0((u8 *)s, (u8 *)&v, 1);
  if ((u8)ext_4e1600((u8 *)s) == 9) ext_4e0fd0((u8 *)s, self + 0xb3);
  ext_4e1b30((u8 *)s);
  float f = (float)((double)(s32)v + G(double, 0x680aa0 + 8 * (v >> 31)));
  u32 fb; __builtin_memcpy(&fb, &f, 4);
  self[0xa3] = fb; self[0xa4] = fb >> 8; self[0xa5] = fb >> 16; self[0xa6] = fb >> 24;
}
PCREG(4f7e00, fn4f7e00);
