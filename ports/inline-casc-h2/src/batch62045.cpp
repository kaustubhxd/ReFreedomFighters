#include "ff.h"

static u32 __attribute__((naked, cdecl)) fn504560(u8 *arg) {
  asm volatile(
      "push %ebp; mov %esp, %ebp; "
      "mov 8(%ebp), %eax; movzwl 0x10(%eax), %edx; "
      "cmp 0x700e70, %edx; jae 1f; "
      "mov 0x700e78(,%edx,4), %eax; pop %ebp; jmp *%eax; "
      "1: mov 0x700390, %ecx; push $0x9c; push $0x69ca10; "
      "mov (%ecx), %eax; call *0x20(%eax); "
      "push $0x69ca40; push $0x69c6b0; push %eax; "
      "mov (%eax), %ecx; call *0x2c(%ecx); "
      "mov 0x7003b0, %eax; add $0xc, %esp; test %eax, %eax; "
      "je 2f; call *%eax; pop %ebp; ret $4; "
      "2: int3");
}

PCREG(504560, fn504560);
