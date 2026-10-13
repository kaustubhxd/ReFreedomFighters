// batch4024.cpp - area 70 (slice 4/5), batch 4024: 0x4cecd0 and 0x5fa050 (names GUESS). Both log through the logger global
// 0x700390: slot 0x20 (thiscall, two arguments) returns a stream S; slot 0x2c of S is a cdecl function taking (S, fmt, value)
// (the caller cleans the three arguments with add esp, 0xc). 0x5fa050 then calls the function pointer at 0x7003b0 (cdecl, no
// arguments) and returns 0.
#include "ff.h"

typedef void (*CdeclLog)(void *, u32, u32);   // S, a format or tag, a value (cdecl: the caller cleans)

static void *logStream(u32 a1, u32 a2) {
  return vcall<void *>(G(void *, 0x700390), 0x20, a1, a2);
}

// 0x4cecd0 (name GUESS): thiscall (ECX = this), one stack argument flag, ret 4. If slot 0x40 of this (thiscall, one
// argument) returns zero, logs flag through the stream as tag 0x695ba4 (tag 0x695b7c, 0x117 opens the stream).
static void THISCALL logIfFalse4cecd0(u8 *self, u32 flag) {
  if (vcall<u8>(self, 0x40, flag)) return;
  void *S = logStream(0x695b7cu, 0x117u);
  CdeclLog f = (CdeclLog)((*(void ***)S)[0x2c / 4]);
  f(S, 0x695ba4u, flag);
}
PCREG(4cecd0, logIfFalse4cecd0);

// 0x5fa050 (name GUESS): thiscall, no arguments, plain ret (ECX unused). Logs through the stream opened with (0x6b9148, 0x26),
// slot 0x2c with (0x69c6b0, 0x6b917c), then calls the function pointer at 0x7003b0 if it is set, and returns 0.
static u32 THISCALL logTwo5fa050(void) {
  void *S = logStream(0x6b9148u, 0x26u);
  CdeclLog f = (CdeclLog)((*(void ***)S)[0x2c / 4]);
  f(S, 0x69c6b0u, 0x6b917cu);
  void (*hook)(void) = (void (*)(void))G(void *, 0x7003b0);
  if (hook) hook();
  return 0;
}
PCREG(5fa050, logTwo5fa050);
