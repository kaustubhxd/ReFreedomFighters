#include "ff.h"
extern "C" void ext_633654(void);
asm(
".text\n.globl f4f27c0\nf4f27c0:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $0x358,%esp\n movl 0x6f5630,%eax\n xorl %ebp,%eax\n movl %eax,-4(%ebp)\n pushl %ebx\n movl 8(%ebp),%ebx\n pushl %esi\n pushl %edi\n xorl %edi,%edi\n movl %ecx,-0x348(%ebp)\n leal 0x9f(%ecx),%esi\n movl %edi,-0x34c(%ebp)\n testl %esi,%esi\n je 8f\n"
"1: movl (%esi),%eax\n leal -0x358(%ebp),%ecx\n pushl %ecx\n movl %esi,%ecx\n call *0x4c(%eax)\n movl (%esi),%eax\n leal -0x358(%ebp),%ecx\n pushl %ecx\n movl %esi,%ecx\n call *0x64(%eax)\n testl %eax,%eax\n je 7f\n"
" leal -0x344(%ebp),%esi\n2: movl 8(%eax),%ecx\n testl %ecx,4(%ebx)\n je 4f\n cmpb $0,0x10(%eax)\n je 3f\n movl 0xc(%eax),%ecx\n cmpl 8(%ebx),%ecx\n jne 4f\n"
"3: movq 4(%eax),%xmm0\n incl %edi\n movl 0xc(%eax),%ecx\n movb 0x10(%eax),%al\n movq %xmm0,(%esi)\n movl %ecx,8(%esi)\n movb %al,0xc(%esi)\n addl $0xd,%esi\n"
"4: movl -0x348(%ebp),%ecx\n leal -0x358(%ebp),%edx\n addl $0x9f,%ecx\n pushl %edx\n movl (%ecx),%eax\n call *0x64(%eax)\n testl %eax,%eax\n jne 2b\n movl %edi,-0x34c(%ebp)\n"
"7: movl -0x348(%ebp),%ecx\n xorl %esi,%esi\n testl %edi,%edi\n jle 6f\n leal -0x344(%ebp),%edi\n"
"5: movl (%ecx),%eax\n pushl %ebx\n pushl $0x8000\n pushl (%edi)\n call *0x12c(%eax)\n cmpb $0,0x10(%ebx)\n jne 9f\n"
" movl -0x348(%ebp),%ecx\n incl %esi\n addl $0xd,%edi\n cmpl -0x34c(%ebp),%esi\n jl 5b\n"
"6: popl %edi\n popl %esi\n xorb %al,%al\n popl %ebx\n movl -4(%ebp),%ecx\n xorl %ebp,%ecx\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret $4\n"
"9: movl -4(%ebp),%ecx\n movb $1,%al\n popl %edi\n popl %esi\n xorl %ebp,%ecx\n popl %ebx\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret $4\n"
"8: jmp 6b\n");
extern "C" void f4f27c0(void);
PCREG(4f27c0,f4f27c0);
