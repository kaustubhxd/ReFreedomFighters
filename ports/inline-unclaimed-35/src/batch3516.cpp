#include "ff.h"
// batch3516.cpp - area 35 claim 16 (docs/20-unclaimed-35.md): four wrappers in slice 14. Names are GUESS (no GC name).
// Stubbed in the harness: 0x4d24e0 (stdcall, four args), 0x4e6880 (fastcall: ecx, edx, one stack arg), 0x4ef0e0 (thiscall, no
// args), 0x61c3d0 (cdecl, one arg); the vtable slot +0xbc of the object at 0x4f5aa0 (logged, one arg).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

extern "C" u32 STDCALL ext_4d24e0(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 FASTCALL ext_4e6880(u32 a0, u32 a1, u32 a2);
extern "C" void THISCALL ext_4ef0e0(u8 *self);
extern "C" void ext_61c3d0(u32 a0);

// 0x4d39a0, GUESS FUN_4d39a0 (stdcall, two args): calls 0x4d24e0 with (a1, 2, a2, 0). The exe pushes 0 first, so the callee
// takes four arguments (ret 0x10).
static void STDCALL guessWrap4d(u32 a1, u32 a2) {
  ext_4d24e0(a1, 2, a2, 0);
}
PCREG(4d39a0, guessWrap4d);

// 0x491e60, GUESS FUN_491e60 (stdcall, three args): a1 in ecx, a2 in edx, a3 on the stack, to 0x4e6880; returns its eax.
static u32 STDCALL guessWrap91(u32 a1, u32 a2, u32 a3) {
  return ext_4e6880(a1, a2, a3);
}
PCREG(491e60, guessWrap91);

// 0x4f5aa0, GUESS FUN_4f5aa0 (thiscall): calls 0x4ef0e0 with this, then vtable slot +0xbc of this with one argument (1).
static void THISCALL guessWrapBC(u8 *self) {
  ext_4ef0e0(self);
  ((Slot1)*(u32 *)(*(u32 *)self + 0xbc))(self, 1);
}
PCREG(4f5aa0, guessWrapBC);

// 0x61ba60, GUESS FUN_61ba60 (thiscall): reads this+4, sets the vtable 0x6be264, calls 0x61c3d0 with the read value if non-null.
static void THISCALL guessInitVt(u8 *self) {
  u32 p = *(u32 *)(self + 4);
  *(u32 *)self = 0x6be264;
  if (p)
    ext_61c3d0(p);
}
PCREG(61ba60, guessInitVt);
