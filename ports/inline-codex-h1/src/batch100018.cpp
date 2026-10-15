#include "ff.h"
extern "C" void ext_4e0d40(void), ext_451890(void), ext_43e8e0(void), ext_44fde0(void), ext_633654(void);
asm(
".text\n.globl f44f8b0\nf44f8b0:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $0x44,%esp\n movl 0x6f5630,%eax\n xorl %ebp,%eax\n movl %eax,-4(%ebp)\n pushl %esi\n movl 0xc(%ebp),%esi\n pushl %edi\n movl 8(%ebp),%edi\n pushl %ecx\n movl %ecx,-0x20(%ebp)\n addl $0xc,%edi\n movl %edi,%edx\n movl $0x43340000,(%esp)\n leal -0x10(%ebp),%ecx\n call ext_4e0d40\n"
" movss (%esi),%xmm0\n movl %edi,%edx\n movss %xmm0,-0x34(%ebp)\n movss 4(%esi),%xmm0\n movss %xmm0,-0x30(%ebp)\n movss 8(%esi),%xmm0\n movss %xmm0,-0x2c(%ebp)\n movss 0x10(%ebp),%xmm0\n addss 0x679544,%xmm0\n pushl %ecx\n leal -0x34(%ebp),%ecx\n movss %xmm0,(%esp)\n call ext_451890\n"
" leal -0x10(%ebp),%eax\n movl %esi,%edx\n pushl %eax\n leal -0x40(%ebp),%ecx\n call ext_43e8e0\n"
" movss 0x10(%ebp),%xmm0\n movl %edi,%edx\n xorps 0x67af40,%xmm0\n pushl %ecx\n leal -0x40(%ebp),%ecx\n movss %xmm0,(%esp)\n call ext_451890\n"
" movl -0x20(%ebp),%ecx\n xorl %edi,%edi\n movl 0x7c(%ecx),%eax\n movl (%eax),%esi\n cmpl %edi,0x44(%ecx)\n jbe 2f\n movss 0x10(%ebp),%xmm0\n movss %xmm0,-0x24(%ebp)\n"
"1: leal -0x1c(%ebp),%eax\n movl %esi,%ecx\n pushl %eax\n leal -0x28(%ebp),%eax\n pushl %eax\n leal -0x24(%ebp),%eax\n pushl %eax\n leal -0x44(%ebp),%eax\n pushl %eax\n leal -0x34(%ebp),%eax\n pushl %eax\n leal -0x40(%ebp),%edx\n call ext_44fde0\n testb %al,%al\n je 3f\n"
" movss 0x10(%ebp),%xmm0\n leal -0x1c(%ebp),%edx\n subss -0x28(%ebp),%xmm0\n pushl %ecx\n movl %esi,%ecx\n movss %xmm0,(%esp)\n call ext_451890\n"
"3: movl -0x20(%ebp),%eax\n incl %edi\n addl $0xc,%esi\n cmpl 0x44(%eax),%edi\n jb 1b\n"
"2: movl -4(%ebp),%ecx\n popl %edi\n xorl %ebp,%ecx\n popl %esi\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret $0xc\n");
extern "C" void f44f8b0(void);
PCREG(44f8b0,f44f8b0);
