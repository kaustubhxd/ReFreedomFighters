// batch403.cpp - gap band parked rows 0x41f540 and 0x41f690 (cdecl, no arguments). Each pushes the address 0x6fd228 (a critical
// section) and calls an import through its IAT slot: 0x41f540 calls EnterCriticalSection (IAT 0x6760c4), 0x41f690 calls
// LeaveCriticalSection (IAT 0x6760c8). Both imports are stdcall with one argument.
#include "ff.h"

static void enterCritical(void) {
  ((void(STDCALL *)(void *))(unsigned long)(*(u32 *)0x6760c4u))((void *)0x6fd228u);
}

static void leaveCritical(void) {
  ((void(STDCALL *)(void *))(unsigned long)(*(u32 *)0x6760c8u))((void *)0x6fd228u);
}

PCREG(41f540, enterCritical);
PCREG(41f690, leaveCritical);
