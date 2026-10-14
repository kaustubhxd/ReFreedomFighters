// batch197.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helper 0x45f960 (thiscall, one stack argument, ret 4): calls obj->vtbl[0x3c] twice (on the object argument),
// then returns true (mov al, 1). Runs as original code. Its slice residue is 14, so it is not claimed here.
extern "C" u8 THISCALL ext_45f960(u8 *self, u32 obj);

// 0x45c160: returns (0x45f960(this, obj) != 0) as a bool (push obj, call, test al, setne al, ret 4). GUESS: a
// call-through wrapper that reports the helper's result as a bool.
static u8 THISCALL boolWrap_45c160(u8 *self, u32 obj) {
    return ext_45f960(self, obj) != 0 ? 1 : 0;
}
PCREG(45c160, boolWrap_45c160);
