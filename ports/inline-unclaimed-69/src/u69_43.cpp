// u69_43.cpp - area 69, group 43 (slice 8). Pointer chain with a tail jump: follows self+0x10 -> +0x1c -> +4 -> +4 and jumps to 0x5f4170 with that ECX (no args). Null links return the first pointer. 0x5f4170 is a GUESS stub in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_5f4170(void *self);  // thiscall, no args, ret 0 (other area, 528 bytes; stubbed in the spec: GUESS)

// 0x478400, thiscall no args (ret). eax holds the pointer at self+0x10; each null link returns eax as it is; otherwise jump to 0x5f4170 with ECX = the last link.
static u32 THISCALL chain478400(u8 *self) {
  u32 eax = *(u32 *)(self + 0x10);
  u32 ecx = *(u32 *)(eax + 0x1c);
  if (!ecx)
    return eax;
  ecx = *(u32 *)(ecx + 4);
  if (!ecx)
    return eax;
  ecx = *(u32 *)(ecx + 4);
  return ext_5f4170((void *)ecx);
}
PCREG(478400, chain478400);
