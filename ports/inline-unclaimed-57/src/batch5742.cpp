// batch5742.cpp - unclaimed-57, band batch 42 (name GUESS): 0x5d5820, fastcall (p1 in ECX, p2 in EDX, stack a and b), ret 8, returns eax.
// If b != 0: return 0x5d5680(ECX = b, EDX = a, stack p1, p2) (fastcall helper; unverified, hooked and logged in the spec).
// Else: o = 0x45c4b0(0x36) (cdecl allocator; unverified, hooked in the spec); if o is null return 0; 0x43de40(o, a, p1, p2) (thiscall, three
// arguments, callee pops 12; unverified, hooked and logged); vtable 0x6b5610 at o; byte o+0x18 = 0; dword o+0x19 = 0; dword o+0x25 = 0;
// dword o+0x29 = 0; dword o+0x2d = 0; byte o+0x31 = 0; dword o+0x32 = 0; return o.
// SEH-TAG: the original installs an exception frame on fs:[0] with a security cookie and a state byte. Nothing in the harness raises an
// exception, and those writes are not observed, so the frame setup is NOT reproduced; only the observable behaviour is ported.
#include "ff.h"

extern "C" u32 FASTCALL ext_5d5680(u32 b, u32 a, u32 p1, u32 p2);   // unverified, original code (hooked and logged in the spec)
extern "C" u8 *ext_45c4b0(u32 size);                                // unverified allocator, cdecl, original code (hooked in the spec)
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);  // unverified, original code (hooked and logged in the spec)

static u32 FASTCALL unnamed5d5820(u32 p1, u32 p2, u32 a, u32 b) {
  if (b != 0) return ext_5d5680(b, a, p1, p2);
  u8 *o = ext_45c4b0(0x36);
  if (o == 0) return 0;
  ext_43de40(o, a, p1, p2);
  *(u32 *)o = 0x6b5610;
  o[0x18] = 0;
  *(u32 *)(o + 0x19) = 0;
  *(u32 *)(o + 0x25) = 0;
  *(u32 *)(o + 0x29) = 0;
  *(u32 *)(o + 0x2d) = 0;
  o[0x31] = 0;
  *(u32 *)(o + 0x32) = 0;
  return (u32)(unsigned long)o;
}
PCREG(5d5820, unnamed5d5820);
