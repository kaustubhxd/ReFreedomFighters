// batch630.cpp - band 0x421000-0x441000, batch 630: two functions.
//   0x42adc0 (fastcall: this in ecx, string in edx; returns bool): len = strlen(s); if (dword [this+4] - dword [this]) != len
//     return false; else return ext 0x4309b0(len) == 0 (exe, stdcall, one argument).
//   0x42b9c0 (thiscall, no args): b = dword [this]; size = dword [this+8] - b; if b and size: ext 0x54f870(b, size) (exe, stdcall,
//     two arguments). The SEH frame is not reproduced (no effect on the result).
#include "ff.h"

extern "C" u32 STDCALL ext_4309b0(u32 len);             // exe (stdcall, one argument; ret 4): returns eax
extern "C" void STDCALL ext_54f870(void *p, u32 size);  // exe (stdcall, two arguments; ret 8)

static bool FASTCALL compareSpan(u8 *self, const char *s) {
  u32 len = 0;
  while (s[len])
    len++;
  u32 begin = *(u32 *)self;
  u32 end = *(u32 *)(self + 4);
  if (end - begin != len)
    return false;
  return ext_4309b0(len) == 0;
}
PCREG(42adc0, compareSpan);

static void THISCALL releaseSpan(u8 *self) {
  u32 b = *(u32 *)self;
  u32 size = *(u32 *)(self + 8) - b;
  if (b && size)
    ext_54f870((void *)b, size);
}
PCREG(42b9c0, releaseSpan);
