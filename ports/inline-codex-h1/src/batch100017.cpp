#include "ff.h"
asm(
".text\n.globl f4a9250\nf4a9250:\n"
" pushl %ebp\n movl %esp,%ebp\n pushl %esi\n movl 8(%ebp),%esi\n pushl %edi\n movl %ecx,%edi\n movl %esi,%ecx\n andl $0xffffffbf,4(%edi)\n movl (%esi),%eax\n pushl 0x4a(%edi)\n call *0x44(%eax)\n"
" movl (%esi),%edx\n movl %esi,%ecx\n movzbl 0x5a(%edi),%eax\n pushl %eax\n call *0x60(%edx)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0x5b(%edi)\n call *0x44(%eax)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0x5f(%edi)\n call *0x44(%eax)\n"
" movl (%esi),%eax\n movss 0x63(%edi),%xmm0\n pushl %ecx\n movl %esi,%ecx\n movss %xmm0,(%esp)\n call *0x4c(%eax)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0x75(%edi)\n call *0x44(%eax)\n"
" movl (%esi),%edx\n leal 0x7d(%edi),%eax\n pushl %eax\n movl %esi,%ecx\n call *0x68(%edx)\n"
" movl (%esi),%edx\n leal 0x8b(%edi),%eax\n pushl %eax\n movl %esi,%ecx\n call *0x68(%edx)\n"
" movl (%esi),%edx\n leal 0x97(%edi),%eax\n pushl %eax\n movl %esi,%ecx\n call *0x68(%edx)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0xbb(%edi)\n call *0x3c(%eax)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0xbf(%edi)\n call *0x3c(%eax)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0xc3(%edi)\n call *0x3c(%eax)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0xc9(%edi)\n call *0x3c(%eax)\n"
" movl (%esi),%edx\n movl %esi,%ecx\n movzbl 0xd1(%edi),%eax\n pushl %eax\n call *0x60(%edx)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0xd2(%edi)\n call *0x44(%eax)\n"
" movl (%esi),%eax\n movl %esi,%ecx\n pushl 0x52(%edi)\n call *0x3c(%eax)\n"
" popl %edi\n movb $1,%al\n popl %esi\n popl %ebp\n ret $4\n");
extern "C" void f4a9250(void);
PCREG(4a9250,f4a9250);
