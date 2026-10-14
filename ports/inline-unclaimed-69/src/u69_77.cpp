// u69_77.cpp - area 69, group 77 (slice 8). A ring push into the ring at [self+0x1005d]+0x268 (as ZDrawBase::Leave), then a walk over a chain of records
// (+0x1c links) that calls 0x64d5f0 for each record. Callees 0x63ea00 (thiscall, one stack arg, ret 4) and 0x64d5f0 (thiscall, one stack arg, ret 4) are GUESS stubs.
#include "ff.h"

extern "C" void THISCALL ext_63ea00(void *self, u32 a);   // ret 4 (GUESS stub in the spec)
extern "C" void THISCALL ext_64d5f0(void *self, u32 a);   // ret 4 (GUESS stub in the spec)

// 0x64c240, thiscall one stack arg (record pointer esi; ret 4). Clears bit 0 of esi[5]; stores *esi = the dword at 0x70039c -> +0x3c; the ring at
// P0 + 0x268 (P0 = the dword at self+0x1005d) gets esi at its write slot (advancing by 4, wrapping at +0x8008); esi[6] = slot index as a word.
// Then: the record at esi[8] has its byte at +0x3e decremented; when that gives zero, 0x63ea00(P0, record) is called. Then for each record in the
// chain esi -> [esi+0x1c] -> ... (after the first), 0x64d5f0(self, record) is called.
static void THISCALL geomLeave64c240(u8 *self, u8 *esi) {
  esi[5] &= 0xfe;
  *(u32 *)esi = *(u32 *)(*(u8 **)0x70039c + 0x3c);
  u8 *P0 = *(u8 **)(self + 0x1005d);
  u32 edx = (u32)P0 + 0x268;
  *(u32 *)esi = *(u32 *)(*(u8 **)0x70039c + 0x3c);
  u32 ecx = *(u32 *)edx;
  u32 eax = ecx - edx - 8;
  u16 bx = (u16)((s32)eax >> 2);
  eax = edx + 0x8008;
  *(u32 *)ecx = (u32)esi;
  *(u32 *)edx += 4;
  if (*(u32 *)edx == eax)
    *(u32 *)edx = edx + 8;
  eax = *(u32 *)(esi + 8);
  *(u16 *)(esi + 6) = bx;
  u8 *X = (u8 *)eax;
  X[0x3e] = (u8)(X[0x3e] - 1);
  if (X[0x3e] == 0)
    ext_63ea00(*(void **)(self + 0x1005d), eax);
  u8 *cur = *(u8 **)(esi + 0x1c);
  while (cur != 0) {
    ext_64d5f0(self, (u32)cur);
    cur = *(u8 **)(cur + 0x1c);
  }
}
PCREG(64c240, geomLeave64c240);
