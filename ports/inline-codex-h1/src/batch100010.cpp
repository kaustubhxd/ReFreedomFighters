#include "ff.h"
extern "C" unsigned int ext_514600(void), ext_633654(void), ext_4e0830(void);
asm(
".text\n.globl f51fad0\nf51fad0:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $0x20,%esp\n movl 0x6f5630,%eax\n xorl %ebp,%eax\n movl %eax,-4(%ebp)\n"
" pushl %esi\n pushl %edi\n movl 8(%ebp),%edi\n movl %ecx,%esi\n pushl %edi\n call ext_514600\n testb %al,%al\n jne 1f\n"
" popl %edi\n xorb %al,%al\n popl %esi\n movl -4(%ebp),%ecx\n xorl %ebp,%ecx\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret $4\n"
"1: movl 0x70039c,%eax\n pushl %edi\n movl 0x9b(%eax),%ecx\n movl (%ecx),%eax\n movl 0x58(%eax),%eax\n call *%eax\n"
" movl $0,-0x1c(%ebp)\n leal -0x1c(%ebp),%ecx\n movl $0x43160000,-0x18(%ebp)\n movl $0,-0x14(%ebp)\n"
" movl (%eax),%edx\n pushl %ecx\n movl %eax,%ecx\n call *0x84(%edx)\n"
" movss 0x1660(%esi),%xmm0\n leal -0x10(%ebp),%ecx\n movl (%esi),%eax\n movss %xmm0,-0x10(%ebp)\n"
" movss 0x1664(%esi),%xmm0\n movss %xmm0,-0xc(%ebp)\n movss 0x1668(%esi),%xmm0\n pushl %ecx\n movl %esi,%ecx\n movss %xmm0,-8(%ebp)\n call *0x84(%eax)\n"
" movss -0x18(%ebp),%xmm1\n movaps %xmm1,%xmm0\n subss 0x64(%esi),%xmm0\n cvtps2pd %xmm0,%xmm0\n andps 0x67cd50,%xmm0\n comisd 0x69ff70,%xmm0\n ja 2f\n"
" leal -0x10(%ebp),%edx\n movss %xmm1,-0xc(%ebp)\n leal -0x1c(%ebp),%ecx\n call ext_4e0830\n"
" movss 0x69ff78,%xmm0\n fstps -0x20(%ebp)\n movss -0x20(%ebp),%xmm1\n comiss %xmm1,%xmm0\n ja 2f\n"
" comiss 0x69ff7c,%xmm1\n movl -4(%ebp),%ecx\n popl %edi\n popl %esi\n setbe %al\n xorl %ebp,%ecx\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret $4\n"
"2: xorb %al,%al\n movl -4(%ebp),%ecx\n popl %edi\n popl %esi\n xorl %ebp,%ecx\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret $4\n");
extern "C" void f51fad0(void);
PCREG(51fad0,f51fad0);
