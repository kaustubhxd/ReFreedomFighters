// batch947.cpp - vehicles thread, batch 947: ZMoveOnSpline::StopSounds, 0x5145e0 (thiscall, no args, returns void).
// It calls the vtable slot 0x33c, then tail-jumps through slot 0x340 (same arguments: this only).
// 0x515cf0 is a one-instruction jmp thunk to 0x5145e0, so it is registered as a call into the same function.
#include "ff.h"

// 0x5145e0 ZMoveOnSpline::StopSounds().
static void THISCALL moveStopSounds(u8 *s) {
  vcall<void>(s, 0x33c);
  vcall<void>(s, 0x340);
}
PCREG(5145e0, moveStopSounds);

// 0x515cf0 jmp 0x5145e0.
static void THISCALL moveStopSoundsThunk(u8 *s) {
  moveStopSounds(s);
}
PCREG(515cf0, moveStopSoundsThunk);
