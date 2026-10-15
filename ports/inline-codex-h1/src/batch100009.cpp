#include "ff.h"
extern "C" void ext_633654(void);
asm(
".text\n.globl f448f80\nf448f80:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $0x3c,%esp\n"
" movl 0x6f5630,%eax\n xorl %ebp,%eax\n movl %eax,-4(%ebp)\n"
" movl 0xc(%ebp),%eax\n pushl %ebx\n movl 0x10(%ebp),%ebx\n pushl %esi\n movl %ecx,%esi\n"
" movl %eax,-0x14(%ebp)\n movl 0x14(%ebp),%ecx\n pushl %edi\n movl 8(%ebp),%edi\n"
" movl 0x14(%esi),%eax\n movl %ecx,-0x18(%ebp)\n testb $1,%al\n je 1f\n"
" movl (%edi),%edx\n shrl $3,%eax\n andb $1,%al\n movzbl %al,%eax\n"
" pushl %eax\n pushl -0x14(%ebp)\n pushl %ecx\n pushl %ebx\n movl %edi,%ecx\n call *0xa8(%edx)\n"
" movl 0x70039c,%eax\n movl 0x1aa3(%eax),%eax\n movl 0x18(%eax),%ecx\n leal -0x3c(%ebp),%eax\n pushl %eax\n"
" movl 8(%esi),%eax\n movl (%ecx),%edx\n pushl 0x6c(%eax)\n call *0x80(%edx)\n"
" movss -0x20(%ebp),%xmm0\n leal -0x10(%ebp),%ecx\n movl (%edi),%eax\n movl -0x18(%ebp),%esi\n"
" pushl %ecx\n pushl %esi\n pushl %ebx\n movl %edi,%ecx\n"
" movss %xmm0,-0x10(%ebp)\n movss %xmm0,-0xc(%ebp)\n movss %xmm0,-8(%ebp)\n call *0xb0(%eax)\n"
" movss -0x24(%ebp),%xmm0\n leal -0x10(%ebp),%ecx\n movl (%edi),%eax\n"
" pushl %ecx\n pushl %esi\n pushl %ebx\n movl %edi,%ecx\n"
" movss %xmm0,-0x10(%ebp)\n movss %xmm0,-0xc(%ebp)\n movss %xmm0,-8(%ebp)\n call *0xac(%eax)\n"
"1: movl -4(%ebp),%ecx\n popl %edi\n popl %esi\n xorl %ebp,%ecx\n popl %ebx\n call ext_633654\n"
" movl %ebp,%esp\n popl %ebp\n ret $0x10\n");
extern "C" void f448f80(void);
PCREG(448f80,f448f80);
