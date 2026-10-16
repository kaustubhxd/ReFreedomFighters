// batch353.cpp - area 76 (docs/20-unclaimed-76.md, parked row 0x6053c0): stdcall, one stack argument (obj), ret 4; reads ECX.
// Index w = word [obj+0x10]. If w < [0x724698] (unsigned): return the stdcall entry [0x7246a0 + 4w](obj), called with the same ECX.
// Else: [obj+0x10] = w - count (16-bit), then the exe tail-jumps to 0x5fa270 with the same ECX and the argument slot = obj; the
// callee pops that argument, so the port calls it with the stack argument and returns its value (the callee's pop leaves the
// same stack as the jump did). ECX is an input the port reads through the fastcall first parameter (the fixture passes it as ECX).
#include "ff.h"

// Calls a stdcall target with ECX preserved and one stack word; the callee pops the word. Returns eax.
static u32 callStdEcx(u32 ecx, u32 target, u32 arg) {
    u32 out;
    __asm__ volatile(
        "pushl %%edi\n\t"
        "calll *%%esi\n\t"
        : "=&a"(out)
        : "c"(ecx), "D"(arg), "S"(target)
        : "edx", "memory", "cc");
    return out;
}

// Fastcall: ECX = ecxIn (the value the exe leaves for its callee), EDX unused, obj is the third parameter on the stack (callee pops 4).
static u32 __attribute__((fastcall)) index6053c0(u32 ecxIn, u32 edxIn, u32 obj) {
    (void)edxIn;
    u32 w = *(u16 *)(obj + 0x10u);
    u32 count = G(u32, 0x724768u);
    if (w < count) return callStdEcx(ecxIn, *(u32 *)(0x724770u + 4u * w), obj);
    *(u16 *)(obj + 0x10u) = (u16)(w - count);
    return callStdEcx(ecxIn, 0x5fa270u, obj);
}
PCREG(6053c0, index6053c0);
