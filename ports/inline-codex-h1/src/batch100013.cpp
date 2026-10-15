#include "ff.h"
extern "C" void ext_43e920(void), ext_4e0d00(void);
asm(
".text\n.globl f655cf0\nf655cf0:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $0x18,%esp\n pushl %esi\n movl %ecx,%esi\n movl 8(%ebp),%ecx\n testl %ecx,%ecx\n jne 1f\n"
" xorb %al,%al\n popl %esi\n movl %ebp,%esp\n popl %ebp\n ret $0xc\n"
"1: movl (%esi),%eax\n pushl %edi\n pushl %ecx\n movl %esi,%ecx\n call *0xc(%eax)\n movl %eax,%edi\n cmpw $6,2(%edi)\n jne 2f\n"
" pushl 0x10(%ebp)\n movl (%esi),%eax\n movl %esi,%ecx\n pushl 0xc(%ebp)\n pushl %edi\n movl 0x15c(%eax),%eax\n call *%eax\n popl %edi\n popl %esi\n movl %ebp,%esp\n popl %ebp\n ret $0xc\n"
"2: cmpl $0,0x10(%edi)\n jne 3f\n movl 0x7003b0,%eax\n testl %eax,%eax\n je 4f\n call *%eax\n jmp 3f\n4: int3\n"
"3: movl (%esi),%eax\n movl %esi,%ecx\n pushl 0x10(%edi)\n call *0xc(%eax)\n movl 0x10(%ebp),%esi\n leal -0xc(%ebp),%edx\n movl %esi,%ecx\n"
" movss 4(%eax),%xmm0\n movss %xmm0,-0xc(%ebp)\n movss 8(%eax),%xmm0\n movss %xmm0,-8(%ebp)\n movss 0xc(%eax),%xmm0\n movss %xmm0,-4(%ebp)\n"
" movss 0x30(%eax),%xmm0\n movss %xmm0,-0x18(%ebp)\n movss 0x34(%eax),%xmm0\n movss %xmm0,-0x14(%ebp)\n movss 0x38(%eax),%xmm0\n leal -0x18(%ebp),%eax\n pushl %eax\n movss %xmm0,-0x10(%ebp)\n call ext_43e920\n"
" pushl %ecx\n movl %esi,%ecx\n movl $0x3f000000,(%esp)\n call ext_4e0d00\n movl 0xc(%ebp),%ecx\n leal -0xc(%ebp),%edx\n pushl %esi\n call ext_43e920\n"
" popl %edi\n movb $1,%al\n popl %esi\n movl %ebp,%esp\n popl %ebp\n ret $0xc\n");
extern "C" void f655cf0(void);
PCREG(655cf0,f655cf0);
