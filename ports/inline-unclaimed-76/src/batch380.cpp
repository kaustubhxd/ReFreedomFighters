// batch380.cpp - area 76, residue 17 (out/functions.jsonl): 0x634817 (cdecl, no arguments, plain ret; GUESS).
// Calls the import InitializeSListHead (KERNEL32, through the IAT slot 0x676054; stdcall, one argument) with 0x725800.
#include "ff.h"

static void __attribute__((cdecl)) f634817(void) {
    ((void(__attribute__((stdcall)) *)(u32))(*(u32 *)0x676054u))(0x725800u);
}
PCREG(634817, f634817);
