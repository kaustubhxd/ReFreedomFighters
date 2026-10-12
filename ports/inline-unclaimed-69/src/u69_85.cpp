// u69_85.cpp - area 69, gameplay-core residue-8 (docs/39 todo, residue-08 list). Naked asm so EAX and the stack match the exe exactly.
// 0x489340 ZMovementGuide::GotControl (vtable): `mov eax,[ecx+4]; or dword [eax+0x417],0x400000; ret` (thiscall, no args, returns the pointer).
// 0x47bd80 ZActor::SetDisableIdleAnimation(bool) (vtable): `mov al,[esp+4]; mov [ecx+0x771],al; ret 4`.
// 0x47c140 ZActor::SetStopDistance(float) (vtable): `movss xmm0,[esp+4]; movss [ecx+0x6b2],xmm0; ret 4`.
#include "ff.h"

extern "C" void fwd489340(void);
extern "C" void fwd47bd80(void);
extern "C" void fwd47c140(void);
__asm__(
    ".text\n"
    ".globl fwd489340\n"
    "fwd489340:\n"
    "  movl 4(%ecx), %eax\n"
    "  orl $0x400000, 0x417(%eax)\n"
    "  ret\n"
    ".globl fwd47bd80\n"
    "fwd47bd80:\n"
    "  movb 4(%esp), %al\n"
    "  movb %al, 0x771(%ecx)\n"
    "  ret $4\n"
    ".globl fwd47c140\n"
    "fwd47c140:\n"
    "  movss 4(%esp), %xmm0\n"
    "  movss %xmm0, 0x6b2(%ecx)\n"
    "  ret $4\n");
PCREG(489340, fwd489340);
PCREG(47bd80, fwd47bd80);
PCREG(47c140, fwd47c140);
