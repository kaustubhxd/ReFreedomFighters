// batch4104.cpp - unclaimed-41 batch 4 (slice 13, leaves): four small functions.
#include "ff.h"

// 0x4d8c10: lea eax,[ecx+0x84]; ret. A getter that returns the address of the field at +0x84 (thiscall, no arguments).
static u32 THISCALL getAddr84(u8 *self) {
  return (u32)(self + 0x84);
}
PCREG(4d8c10, getAddr84);

// 0x5f0490: mov dword ptr [ecx], 0x6b8284; ret. Stores a vtable pointer at +0 (a constructor's first step; thiscall).
static void THISCALL storeVtable5f0490(u8 *self) {
  *(u32 *)self = 0x6b8284u;
}
PCREG(5f0490, storeVtable5f0490);

// 0x5ab110: if dword[+0x300] != 0x10000000 then inc dword[+0x8b7]; ret (thiscall, no arguments).
static void THISCALL condIncCounter5ab110(u8 *self) {
  if (*(u32 *)(self + 0x300) != 0x10000000u)
    (*(u32 *)(self + 0x8b7))++;
}
PCREG(5ab110, condIncCounter5ab110);

// 0x438c10: push ebp; mov ebp,esp; mov eax,[ecx]; pop ebp; jmp [eax+0x10]. A tail-jump through vtable slot +0x10 with ecx = this.
// The callee's arguments are the caller's (this function has none), so the port forwards with no arguments and returns eax.
static u32 THISCALL forwardVt10_438c10(u8 *self) {
  typedef u32(THISCALL * f_t)(u8 *);
  return ((f_t)(*(u32 *)(*(u32 *)self + 0x10)))(self);
}
PCREG(438c10, forwardVt10_438c10);
