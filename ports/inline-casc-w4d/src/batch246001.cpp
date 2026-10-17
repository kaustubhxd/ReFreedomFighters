// batch246001.cpp - Sonnet-w4d, tier 6/7 hand ports (continued).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

// 0x496350: thiscall(flags) ret 4, bool. 0 -> 0; flags & 0x40000000 -> 1; else tail-jumps to vslot 0x14 of the object at this[8]
// (this = that object, same stack argument).
extern "C" u32 THISCALL GUESS_496350(u8 *self, u32 flags) {
  if (flags == 0) return 0;
  if (flags & 0x40000000u) return 1;
  u32 o = *(u32 *)(self + 8);
  u32 fn = *(u32 *)(*(u32 *)o + 0x14);
  return ((u32 THISCALL(*)(u32, u32))fn)(o, flags);
}
PCREG(496350, GUESS_496350);

extern "C" u32 THISCALL ext_4cbe80_s1(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cc690_s0(u32) __asm__("ext_4cc690");
extern "C" u32 THISCALL ext_4d9190_s2(u32, u32, u32) __asm__("ext_4d9190");
extern "C" u32 THISCALL ext_4cbec0_s0(u32) __asm__("ext_4cbec0");

// 0x4d9230: thiscall(cstr) ret 4 (SEH 0x66697b, state 0 after the temp string ctor). Builds a 0x80-byte temp string from cstr
// (0x4cbe80), lowercases it in place (0x4cc690), calls this->0x4d9190(temp data, strlen(cstr)), destroys the temp (0x4cbec0).
extern "C" void THISCALL GUESS_4d9230(u32 self, const u8 *cstr) {
  SEH_ENTER(0x66697b);
  u8 Tb[0x84] __attribute__((aligned(4)));
  u32 T = (u32)Tb;
  u32 len = 0;
  while (cstr[len]) len++;
  ext_4cbe80_s1(T, (u32)cstr);
  reg.state = 0;
  ext_4cc690_s0(T);
  u32 p = *(u32 *)T;
  ext_4d9190_s2(self, p, len);
  ext_4cbec0_s0(T);
  SEH_LEAVE();
}
PCREG(4d9230, GUESS_4d9230);
