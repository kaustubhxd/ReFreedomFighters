#include "ff.h"
extern "C" void ext_562280(void), ext_43ec00(void), ext_633654(void);
asm(
".text\n.globl f5772c0\nf5772c0:\n"
" pushl %ebp\n movl %esp,%ebp\n subl $0x2c,%esp\n movl 0x6f5630,%eax\n xorl %ebp,%eax\n movl %eax,-4(%ebp)\n pushl %edi\n movl %ecx,%edi\n cmpb $0,0x20f(%edi)\n je 8f\n"
" movss 0x211(%edi),%xmm0\n addss 0x67a6ac,%xmm0\n movl 0x70039c,%eax\n mulss 0x678620,%xmm0\n cvttss2si %xmm0,%ecx\n cmpl %ecx,0x30(%eax)\n jle 8f\n"
" movups 0x6a9574,%xmm0\n movw 0x6a9584,%ax\n movl %edi,%ecx\n movw %ax,-0x1c(%ebp)\n movl 0x6a9598,%eax\n movups %xmm0,-0x2c(%ebp)\n movl %eax,-8(%ebp)\n"
" movups 0x6a9588,%xmm0\n movb 0x208(%edi),%al\n movb %al,-0x2a(%ebp)\n movups %xmm0,-0x18(%ebp)\n movb %al,-0x16(%ebp)\n movzbl 0x209(%edi),%eax\n movb %al,-0x15(%ebp)\n"
" leal -0x18(%ebp),%eax\n pushl %ebx\n pushl %eax\n leal -0x2c(%ebp),%eax\n pushl %eax\n call ext_562280\n movl %eax,%ebx\n testl %ebx,%ebx\n je 7f\n"
" movl 0x90(%edi),%ecx\n pushl %esi\n pushl $0\n pushl $0\n movl 8(%ecx),%esi\n movl (%ecx),%eax\n pushl $0\n pushl %ebx\n leal 0x24(%esi),%edx\n pushl %edx\n pushl %esi\n call *0x20(%eax)\n movl %eax,%ecx\n call ext_43ec00\n movl %eax,0x21d(%edi)\n"
" movl 0x70039c,%ecx\n pushl %eax\n movl 0x9b(%ecx),%ecx\n movl (%ecx),%edx\n call *0x60(%edx)\n popl %esi\n testl %eax,%eax\n je 6f\n"
" orl $0x80,0x40(%eax)\n movl $0x42700000,0x88(%eax)\n movl $2,0x2c(%eax)\n"
"6: movl 0x70039c,%eax\n pushl %ebx\n movl 0x1a9f(%eax),%ecx\n movl (%ecx),%eax\n movl 0x74(%eax),%eax\n call *%eax\n fstp %st(0)\n"
"7: movb $0,0x20f(%edi)\n popl %ebx\n"
"8: movl -4(%ebp),%ecx\n xorl %ebp,%ecx\n popl %edi\n call ext_633654\n movl %ebp,%esp\n popl %ebp\n ret\n");
extern "C" void f5772c0(void);
PCREG(5772c0,f5772c0);
