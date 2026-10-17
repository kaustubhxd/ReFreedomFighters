// batch346.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): 0x612170 (cdecl, no arguments, plain ret, bool in al; GUESS).
// Returns whether CPUID leaf 1 has EDX bit 23 (MMX). The port runs the same cpuid instruction the exe runs, so the harness's emulated
// CPUID gives the same answer to both sides.
#include "ff.h"

static u8 __attribute__((cdecl)) mmx_612170(void) {
    u32 eax = 1u, ebx, ecx, edx;
    __asm__ volatile("cpuid" : "+a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx));
    return (edx & 0x800000u) != 0u ? 1u : 0u;
}
PCREG(612170, mmx_612170);
