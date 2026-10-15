#include "ff.h"
extern "C" void ext_633654(void), ext_633910(void);
asm(
".text\n.globl f4bf520\nf4bf520:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $8,%esp\n pushl %ebx\n pushl %edi\n movl %ecx,%edi\n movl $0,-8(%ebp)\n movl $0,-4(%ebp)\n xorl %ebx,%ebx\n pushl %esi\n"
"1: movl 0x70039c,%eax\n movl 0x6d(%edi),%ecx\n pushl %ebx\n movl 0x9b(%eax),%eax\n movl (%eax),%esi\n movl (%ecx),%eax\n call *0x30(%eax)\n"
" movl 0x70039c,%ecx\n pushl %eax\n movl 0x9b(%ecx),%ecx\n call *0x58(%esi)\n testl %eax,%eax\n je 2f\n"
" movss 0x20(%eax),%xmm0\n mulss 0x67da00,%xmm0\n movss %xmm0,0x75(%edi)\n divss 0x79(%edi),%xmm0\n call ext_633910\n"
" movl %eax,%ecx\n movl -4(%ebp),%eax\n movl %eax,0x95(%edi)\n addl %ecx,%eax\n movl %ecx,-8(%ebp)\n movl %eax,-4(%ebp)\n cmpl 0x8d(%edi),%eax\n jbe 3f\n"
" movss 0x67a6ac,%xmm1\n movl %ecx,%eax\n movd %ecx,%xmm0\n cvtdq2pd %xmm0,%xmm0\n shrl $31,%eax\n addsd 0x680aa0(,%eax,8),%xmm0\n cvtpd2ps %xmm0,%xmm0\n divss %xmm0,%xmm1\n"
" movss 0x79(%edi),%xmm0\n mulss 0x67a6ac,%xmm0\n movss %xmm1,0x7d(%edi)\n addss %xmm1,%xmm1\n movss %xmm0,0x99(%edi)\n movss %xmm1,0x81(%edi)\n jmp 4f\n"
"2: movl -8(%ebp),%ecx\n3: incl %ebx\n cmpl 0x91(%edi),%ebx\n jbe 1b\n xorl %ebx,%ebx\n"
"4: movl 0x69(%edi),%edx\n movl %ebx,%eax\n popl %esi\n cmpl %edx,%ecx\n jae 5f\n movl %ecx,0x85(%edi)\n popl %edi\n popl %ebx\n movl %ebp,%esp\n popl %ebp\n ret $4\n"
"5: subl 0x85(%edi),%edx\n movl %edx,0x85(%edi)\n popl %edi\n popl %ebx\n movl %ebp,%esp\n popl %ebp\n ret $4\n");
extern "C" void f4bf520(void);
PCREG(4bf520,f4bf520);
