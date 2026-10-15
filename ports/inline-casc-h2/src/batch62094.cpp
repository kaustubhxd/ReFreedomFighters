#include "ff.h"
static u8 __attribute__((naked)) fn5f0c70(void) {
  asm volatile(
    "pushl %ebp; movl %esp,%ebp; pushl %ecx; pushl %esi; pushl %edi; pushl %ecx;"
    "movl 0x70039c,%eax; movb $0, -1(%ebp); movl 0x9b(%eax),%ecx;"
    "movl (%ecx),%eax; call *0x58(%eax); movl 0x70039c,%ecx; movl %eax,%esi;"
    "leal -1(%ebp),%eax; pushl %eax; pushl $0x2b; movl 0x9b(%ecx),%ecx;"
    "movl (%esi),%edi; pushl $0x6b82f4; pushl $0; movl (%ecx),%edx;"
    "pushl $0x6a66b8; call *0x114(%edx); movzwl %ax,%eax; movl %esi,%ecx;"
    "pushl %eax; pushl %esi; call *0x130(%edi); movb -1(%ebp),%al;"
    "popl %edi; popl %esi; movl %ebp,%esp; popl %ebp; retl;");
}
PCREG(5f0c70, fn5f0c70);
