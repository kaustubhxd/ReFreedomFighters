// batch34073.cpp - escalation batch 34073: 0x466400 and 0x4c1e00 (asm tail thunks), 0x4db2a0 (36-byte copy wrapper), 0x466340 (two calls).
#include "ff.h"

extern "C" void thunk466400(void);
extern "C" void thunk4c1e00(void);
asm(
    ".text\n"
    ".globl thunk466400\n"
    "thunk466400:\n"          // m = [[this+0x1ce]+4] (unaligned); null: return 0; else tail jump through m's slot 4
    "  mov 0x1ce(%ecx), %eax\n"
    "  mov 4(%eax), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 1f\n"
    "  mov (%ecx), %eax\n"
    "  jmp *4(%eax)\n"
    "1:\n"
    "  xor %eax, %eax\n"
    "  ret\n"
    ".globl thunk4c1e00\n"
    "thunk4c1e00:\n"          // flag bit 10 of [[[this+0x44]+8]+0x3c] clear: tail jump to 0x4c3070 (eax = the shifted/inverted value as in the original)
    "  mov 0x44(%ecx), %eax\n"
    "  mov 8(%eax), %eax\n"
    "  mov 0x3c(%eax), %eax\n"
    "  shr $10, %eax\n"
    "  not %al\n"
    "  test $1, %al\n"
    "  jne ext_4c3070\n"
    "  ret\n");
PCREG(466400, thunk466400);
PCREG(4c1e00, thunk4c1e00);

extern "C" void THISCALL ext_462040(void *self, void *a);   // thiscall ret 4
extern "C" u32 THISCALL ext_4e1b30(void *self);             // thiscall, plain ret

// 0x4db2a0, thiscall(a) ret 4: copies 0x24 bytes from this to a (0x4de420 with edx = this, ecx = a); returns the dword at this+0x20.
static u32 THISCALL fn4db2a0(u8 *self, u8 *a) {
  for (int i = 0; i < 0x24; i++) a[i] = self[i];
  return *(u32 *)(self + 0x20);
}
PCREG(4db2a0, fn4db2a0);

// 0x466340, thiscall(a) ret 4: ext_462040(this, a); then ext_4e1b30(a); returns its result.
static u32 THISCALL fn466340(u8 *self, u8 *a) {
  ext_462040(self, a);
  return ext_4e1b30(a);
}
PCREG(466340, fn466340);
