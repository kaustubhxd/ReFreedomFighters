// u69_44.cpp - area 69, group 44 (slice 8). Tail jump through a register: 0x48cf40 sets ECX = dword [self+8] and jumps to 0x496350, which reads one stack arg and ends in an indirect jmp eax. The first hop is a GUESS stub in the spec, with its arity (one stack arg, ret 4) taken as a GUESS, since the final callee is selected at run time.
#include "ff.h"

extern "C" u32 THISCALL ext_496350(void *self, u32 a);  // GUESS arity: one stack arg, ret 4 (other area; stubbed in the spec)

// 0x48cf40, thiscall, one stack arg (the arity of 0x496350). Passes ECX = dword [self+8] and the same argument on to 0x496350.
static u32 THISCALL chain48cf40(u8 *self, u32 a) {
  return ext_496350(*(void **)(self + 8), a);
}
PCREG(48cf40, chain48cf40);
