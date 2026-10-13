// batch4106.cpp - unclaimed-41 batch 6 (slice 13): 0x42ac56 (cdecl wrapper) and 0x45d290 (thiscall wrapper).
#include "ff.h"

// 0x42abbd: five stack arguments, cdecl (the caller pops 0x14). Checksum stub in the spec (GUESS).
extern "C" u32 ext_42abbd(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
// 0x45d1e0: thiscall with two stack arguments (ret 8). Checksum stub in the spec (GUESS).
extern "C" void THISCALL ext_45d1e0(u8 *self, u32 a1, u32 a2);

// 0x42ac56 (high name not in the map; GUESS): cdecl, three arguments as the function reads them. Calls 0x42abbd(a1, a2, -1, 0,
// &a3) (the fifth is the address of this function's third argument), cdecl, and returns the callee's eax.
extern "C" u32 __attribute__((cdecl)) wrap42ac56(u32 a1, u32 a2, u32 *a3) {
  return ext_42abbd(a1, 0xffffffffu, a2, 0u, (u32)a3);   // the PC pushes &a3, 0, a2, -1, a1: callee args are (a1, -1, a2, 0, &a3)
}
PCREG(42ac56, wrap42ac56);

// 0x45d290 (GUESS name): thiscall, two stack arguments (ret 8), returns al = 0. Calls 0x45d1e0 with ecx = [this+8] and
// (a1 = the dword argument, a2 = the float argument as bits).
static u8 THISCALL wrap45d290(u8 *self, u32 a1, u32 a2) {
  u8 *obj = *(u8 **)(self + 8);
  ext_45d1e0(obj, a1, a2);
  return 0;
}
PCREG(45d290, wrap45d290);
