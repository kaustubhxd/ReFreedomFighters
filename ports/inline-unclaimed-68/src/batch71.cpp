// batch71.cpp - unclaimed-68 batch 71 (slice 7): one-argument setters and virtual forwarders (names GUESS, FUN_addr).
#include "ff.h"

typedef u32(THISCALL *VSlot84)(u8 *self, u32 a);
typedef u32(THISCALL *VSlot3c)(u8 *self, u32 a);

// 0x4d7530: mov eax,[esp+4]; mov [ecx+0xd],eax; ret 4
static void THISCALL g4d7530(u8 *self, u32 a) { *(u32 *)(self + 0xd) = a; }
PCREG(4d7530, g4d7530);

// 0x5eeb30: mov [ecx+0x56],arg; ret 4
static void THISCALL g5eeb30(u8 *self, u32 a) { *(u32 *)(self + 0x56) = a; }
PCREG(5eeb30, g5eeb30);

// 0x650fb0: mov al,[esp+4]; mov [ecx+0x82],al; ret 4
static void THISCALL g650fb0(u8 *self, u32 a) { self[0x82] = (u8)a; }
PCREG(650fb0, g650fb0);

// 0x64a6b0: mov eax,[0x70039c]; mov eax,[eax+0x3c]; mov [ecx+0x1829d],eax; ret 4 (the argument is unused)
static void THISCALL g64a6b0(u8 *self, u32 a) {
  (void)a;
  *(u32 *)(self + 0x1829d) = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
}
PCREG(64a6b0, g64a6b0);

// 0x4aff30: mov eax,[ecx]; push [esp+0xc]; call [eax+0x84]; ret 8 (returns the virtual call's EAX)
static u32 THISCALL g4aff30(u8 *self, u32 a, u32 b) {
  (void)a;
  return ((VSlot84)*(u32 *)(*(u8 **)self + 0x84))(self, b);
}
PCREG(4aff30, g4aff30);

// 0x4d1db0: mov eax,[ecx]; push [esp+4]; call [eax+0x3c]; fld qword [eax]; ret 4 (returns the double at the pointer)
static double THISCALL g4d1db0(u8 *self, u32 a) {
  u32 p = ((VSlot3c)*(u32 *)(*(u8 **)self + 0x3c))(self, a);
  return *(double *)(u8 *)p;
}
PCREG(4d1db0, g4d1db0);
