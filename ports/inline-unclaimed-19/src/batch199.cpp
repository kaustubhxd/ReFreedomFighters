// batch199.cpp - unclaimed area 19 (docs/20-unclaimed-19.md), slice floor(addr/16) mod 20 == 18.
#include "ff.h"

// Exe helper 0x523b10 (thiscall, three float stack arguments, ret 0xc). Writes three floats into the object at +0x57..
// and calls a vtable slot. Runs as original code. Its slice residue is 17, so it is not claimed here.
extern "C" void THISCALL ext_523b10(u8 *self, float a, float b, float c);

// 0x5143a0: forwards three floats to the helper on the object at [this+0x5c], then stores the fourth float (the
// last stack argument) at this+0xc0 (ret 0x10). GUESS: a float setter with a helper call.
static void THISCALL setFloats_5143a0(u8 *self, float a, float b, float c, float d) {
    u8 *obj = *(u8 **)(self + 0x5c);
    ext_523b10(obj, a, b, c);
    *(float *)(self + 0xc0) = d;
}
PCREG(5143a0, setFloats_5143a0);
