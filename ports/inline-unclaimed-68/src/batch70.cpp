// batch70.cpp - unclaimed-68 batch 70 (slice 7): small leaves (names GUESS, FUN_addr).
#include "ff.h"

// 0x46b6f0: mov al,[ecx+0xc5]; ret  (returns the byte)
static u8 THISCALL g46b6f0(u8 *self) { return self[0xc5]; }
PCREG(46b6f0, g46b6f0);

// 0x446030: mov eax,[ecx+0x48]; shr eax,5; and eax,1; ret
static u32 THISCALL g446030(u8 *self) { return (*(u32 *)(self + 0x48) >> 5) & 1u; }
PCREG(446030, g446030);

// 0x4cbeb0: lea eax,[ecx+4]; mov [ecx],eax; mov byte [eax],0; mov eax,ecx; ret  (sets the first dword to this+4, clears its byte)
static u32 THISCALL g4cbeb0(u8 *self) {
  *(u8 **)self = self + 4;
  self[4] = 0;
  return (u32)self;
}
PCREG(4cbeb0, g4cbeb0);
