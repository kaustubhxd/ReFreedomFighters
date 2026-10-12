// batch1020.cpp - unclaimed-04 batch 21 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(void *self);  // reader, original code (hooked by address in the spec)

// 0x5827b0: thiscall, one stack argument: this+0x48 = reader(argument), where the reader's object is the argument.
static void THISCALL unk5827b0ReadTo48(u8 *self, u32 arg) {
  *(u32 *)(self + 0x48) = ext_4e5e60((void *)arg);
}
PCREG(5827b0, unk5827b0ReadTo48);

typedef u32(__attribute__((stdcall)) *wait_t)(u32 handle, u32 millis);
#define CRT_WAIT (*(wait_t *)0x676144)

// 0x5332f0: al = (WaitForSingleObject(*0x713d28, 0) == 0), no arguments.
static u8 __attribute__((cdecl)) unk5332f0WaitIsZero(void) {
  u32 r = CRT_WAIT(*(u32 *)0x713d28, 0);
  return r == 0 ? 1 : 0;
}
PCREG(5332f0, unk5332f0WaitIsZero);
