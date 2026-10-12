// batch325.cpp - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md): the two guard forwarders, now with their else paths (cdecl,
// four arguments a, x1, x2, x3; GUESS). Both: if [a+0x18] != 0, call 0x42abee (cdecl, three arguments) and return its result (0x602120
// passes &x3). Else:
// 0x602200: r = [0x70039c].vtbl[0x190]() (thiscall, no arguments); the stack's first argument slot is overwritten by r and the code
//   tail-jumps to r's vtable slot 0x194 with ECX = the vtable pointer of r. The port calls that target as a thiscall with the four
//   arguments (r, x1, x2, x3), which pops them as the jump would leave them for the original caller; the result is returned.
// 0x602120: r = [0x724270] (0x5fa630 returns it); return r.vtbl[0x10](r, x1, x2, &x3) (cdecl, four arguments).
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_42abee(u32 p1, u32 p2, u32 p3);
typedef u32(__attribute__((cdecl)) * slot10_t)(u32, u32, u32, u32);

// The jump leaves the four arguments on the stack for the original caller (plain ret, no pops). A call with the same ECX and the same
// stack words, then the caller-side removal, leaves the stack as the jump would: this keeps the pop count of the port equal to the exe's.
static u32 tailJump_602200(u32 *w) {
    // w[0] = r, w[1] = x1, w[2] = x2, w[3] = x3, w[4] = vtable pointer of r (ECX), w[5] = the target
    u32 out;
    __asm__ volatile(
        "pushl 12(%[w])\n\t"
        "pushl 8(%[w])\n\t"
        "pushl 4(%[w])\n\t"
        "pushl 0(%[w])\n\t"
        "movl 16(%[w]), %%ecx\n\t"
        "calll *20(%[w])\n\t"
        "addl $16, %%esp\n\t"
        : "=a"(out)
        : [w] "r"(w)
        : "ecx", "edx", "memory", "cc");
    return out;
}

static u32 __attribute__((cdecl)) guard_602200(u32 a, u32 x1, u32 x2, u32 x3) {
    if (*(u8 *)(a + 0x18u) != 0u) return ext_42abee(x1, x2, x3);
    u32 g = G(u32, 0x70039cu);
    u32 r = ((u32(THISCALL *)(u32))(*(u32 *)(*(u32 *)g + 0x190u)))(g);
    u32 vt = *(u32 *)r;
    u32 w[6] = {r, x1, x2, x3, vt, *(u32 *)(vt + 0x194u)};
    return tailJump_602200(w);
}
PCREG(602200, guard_602200);

static u32 __attribute__((cdecl)) guard_602120(u32 a, u32 x1, u32 x2, u32 x3) {
    if (*(u8 *)(a + 0x18u) != 0u) return ext_42abee(x1, x2, (u32)&x3);
    u32 r = G(u32, 0x724270u);
    return ((slot10_t)*(u32 *)(*(u32 *)r + 0x10u))(r, x1, x2, (u32)&x3);
}
PCREG(602120, guard_602120);
