// batch1914.cpp - unclaimed-66 batch 14: GUESS FUN_004dd910, a forwarder: ECX = the stack argument (the destination vector),
// EDX = this (the source), then 0x441a60 (x87 vector transform, original code, fastcall). ret 4.
#include "ff.h"

extern "C" void FASTCALL ext_441a60(float *dst, const float *src);

// 0x4dd910, GUESS FUN_004dd910.
static void THISCALL vecTransformForward(u8 *self, float *dst) {
  ext_441a60(dst, (const float *)self);
}
PCREG(4dd910, vecTransformForward);
