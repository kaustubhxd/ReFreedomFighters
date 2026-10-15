#include "ff.h"
asm(
".text\n.globl f65c530\nf65c530:\n"
" pushl %ebp\n movl %esp,%ebp\n pushl %esi\n pushl %edi\n movl %ecx,%edi\n movl 8(%ebp),%ecx\n pushl $0x8131c0\n movl (%ecx),%eax\n call *0x240(%eax)\n"
" movss 0x8131c0,%xmm6\n xorps %xmm0,%xmm0\n comiss %xmm6,%xmm0\n jbe 1f\n movaps %xmm0,%xmm6\n movss %xmm6,0x8131c0\n"
"1: movss 0x8131c4,%xmm3\n comiss %xmm3,%xmm0\n jbe 2f\n movaps %xmm0,%xmm3\n movss %xmm3,0x8131c4\n"
"2: movss 0x8131c8,%xmm4\n movss 0x678858,%xmm0\n comiss %xmm0,%xmm4\n jbe 3f\n movaps %xmm0,%xmm4\n movss %xmm4,0x8131c8\n"
"3: movss 0x8131cc,%xmm5\n comiss %xmm0,%xmm5\n jbe 4f\n movaps %xmm0,%xmm5\n movss %xmm5,0x8131cc\n"
"4: movl 0x10065(%edi),%ecx\n subl $0x10,%esp\n movl 0x1006d(%edi),%eax\n movl 0x10061(%edi),%edx\n subl %ecx,%eax\n movl 0x10051(%edi),%esi\n movd %eax,%xmm0\n cvtdq2pd %xmm0,%xmm0\n shrl $31,%eax\n addsd 0x680aa0(,%eax,8),%xmm0\n movl 0x10069(%edi),%eax\n subl %edx,%eax\n cvtpd2ps %xmm0,%xmm1\n movd %eax,%xmm0\n cvtdq2pd %xmm0,%xmm0\n shrl $31,%eax\n addsd 0x680aa0(,%eax,8),%xmm0\n"
" movl (%esi),%eax\n cvtpd2ps %xmm0,%xmm2\n movaps %xmm1,%xmm0\n mulss %xmm3,%xmm1\n mulss %xmm5,%xmm0\n movss %xmm0,0xc(%esp)\n movaps %xmm2,%xmm0\n mulss %xmm4,%xmm0\n mulss %xmm6,%xmm2\n movss %xmm0,8(%esp)\n movd %ecx,%xmm0\n cvtdq2pd %xmm0,%xmm0\n shrl $31,%ecx\n addsd 0x680aa0(,%ecx,8),%xmm0\n movl %esi,%ecx\n cvtpd2ps %xmm0,%xmm0\n addss %xmm0,%xmm1\n movd %edx,%xmm0\n cvtdq2pd %xmm0,%xmm0\n shrl $31,%edx\n movss %xmm1,4(%esp)\n addsd 0x680aa0(,%edx,8),%xmm0\n cvtpd2ps %xmm0,%xmm0\n addss %xmm0,%xmm2\n movss %xmm2,(%esp)\n call *0x134(%eax)\n"
" popl %edi\n movl $0x8131c0,%eax\n popl %esi\n popl %ebp\n ret $4\n");
extern "C" void f65c530(void);
PCREG(65c530,f65c530);
