// u69_34.cpp - area 69, group 34 (slice 8). Tail-jump thunks: each loads or stores a field and then runs another function with the same stack args. The targets are other areas' functions (stubbed in the spec: GUESS).
#include "ff.h"

extern "C" u32 THISCALL ext_4dbd10(void *self);
extern "C" u32 THISCALL ext_6402b0(void *self, u32 a);
extern "C" u32 THISCALL ext_4d0d20(void *self, u32 a);
extern "C" u32 THISCALL ext_4cdb20(void *self);

// 0x45f400, thiscall no args: jumps to 0x4dbd10 with ECX = dword [self+8].
static u32 THISCALL thunk45f400(u8 *self) { return ext_4dbd10(*(void **)(self + 8)); }
PCREG(45f400, thunk45f400);

// 0x615380, thiscall one stack arg (ret 4): jumps to 0x6402b0 with the same ECX and argument.
static u32 THISCALL thunk615380(u8 *self, u32 a) { return ext_6402b0(self, a); }
PCREG(615380, thunk615380);

// 0x41f1c0, thiscall one stack arg (ret 4): jumps to 0x4d0d20 with ECX = dword [self+0x31] and the same argument.
static u32 THISCALL thunk41f1c0(u8 *self, u32 a) { return ext_4d0d20(*(void **)(self + 0x31), a); }
PCREG(41f1c0, thunk41f1c0);

// 0x4cdb80, thiscall no args: stores 0 at self+0x28, then jumps to 0x4cdb20 with the same ECX.
static u32 THISCALL thunk4cdb80(u8 *self) {
  *(u32 *)(self + 0x28) = 0;
  return ext_4cdb20(self);
}
PCREG(4cdb80, thunk4cdb80);
