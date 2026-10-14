// u69_39.cpp - area 69, group 39 (slice 8). Leftovers from the coordinator's list: a ctor that calls another area's ctor (0x656de0, GUESS stub), a byte getter, and a stdcall wrapper whose register-argument callee (0x6043c0) has an SEH frame that is not reproduced (GUESS stub).
#include "ff.h"

extern "C" u32 THISCALL ext_656de0(void *self, u32 a);                 // other area, thiscall one arg, ret 4 (stubbed in the spec: GUESS)
extern "C" u32 __attribute__((fastcall)) ext_6043c0(u32 a, u32 b);     // fastcall (ecx, edx), ret 0; SEH frame not reproduced (stubbed in the spec: GUESS)

// 0x607c80, thiscall one stack arg (ret 4). Calls 0x656de0(self, arg), stores the vtable 0x6b9fc4 at self, returns self.
static u8 *THISCALL ctorVt6b9fc4(u8 *self, u32 a) {
  ext_656de0(self, a);
  *(u32 *)self = 0x6b9fc4;
  return self;
}
PCREG(607c80, ctorVt6b9fc4);

// 0x432540, thiscall no args (ret). Returns the byte at self+0xfd; only al is defined by the original (the spec compares al only).
static u8 THISCALL byteAtFd432540(u8 *self) {
  return self[0xfd];
}
PCREG(432540, byteAtFd432540);

// 0x601ec0, stdcall two args (ret 8). Loads the first arg into ECX and the second into EDX, calls 0x6043c0 (fastcall, ret 0) and returns its eax. The SEH frame inside 0x6043c0 is not reproduced here; the callee is a GUESS stub.
static u32 STDCALL wrapper601ec0(u32 a1, u32 a2) {
  return ext_6043c0(a1, a2);
}
PCREG(601ec0, wrapper601ec0);
