#include "ff.h"
extern "C" void ext_4e5e60(void), ext_4e5e80(void), ext_4a8d90(void), ext_4a9330(void), ext_633654(void);
asm(
".text\n.globl f4a8dd0\nf4a8dd0:\n"
" pushl %ebp\n movl %esp,%ebp\n pushl %ebx\n pushl %esi\n movl 0xc(%ebp),%esi\n movl %ecx,%ebx\n pushl %edi\n movl %esi,%ecx\n call ext_4e5e60\n movl %esi,%ecx\n movl %eax,0x52(%ebx)\n call ext_4e5e60\n movl %esi,%ecx\n movl %eax,%edi\n call ext_4e5e80\n movl %esi,%ecx\n fstps 0xc(%ebp)\n call ext_4e5e60\n movl %esi,%ecx\n movl %eax,0xbf(%ebx)\n call ext_4e5e60\n movl %eax,0xc3(%ebx)\n"
" movl %ebx,%ecx\n movl (%ebx),%eax\n call *0x84(%eax)\n movss 0xc(%ebp),%xmm0\n movl %ebx,%ecx\n movl $3,0x75(%ebx)\n movl $3,0x79(%ebx)\n movl %edi,0x5f(%ebx)\n movl $0,0xbb(%ebx)\n movl $0,0xd2(%ebx)\n mulss %xmm0,%xmm0\n movss %xmm0,0x63(%ebx)\n"
" movl $0,0x8b(%ebx)\n movl $0,0x8f(%ebx)\n movl $0,0x93(%ebx)\n movl $0,0x97(%ebx)\n movl $0,0x9b(%ebx)\n movl $0,0x9f(%ebx)\n movl $1,0x4a(%ebx)\n movb $1,0x5a(%ebx)\n movl $0,0x5b(%ebx)\n movl $0,0x69(%ebx)\n movl $0,0x6d(%ebx)\n movl $0,0x71(%ebx)\n call ext_4a8d90\n pushl 0xbf(%ebx)\n movl %ebx,%ecx\n call ext_4a9330\n cmpl $0,0x56(%ebx)\n movb $0,0xd1(%ebx)\n jne 1f\n"
" movl 0x700390,%ecx\n pushl $0x5b\n pushl $0x690354\n movl (%ecx),%eax\n call *0x20(%eax)\n pushl $0x6903b8\n pushl %eax\n movl (%eax),%ecx\n call *0x2c(%ecx)\n addl $8,%esp\n"
"1: movl 0x44(%ebx),%ecx\n pushl $0x10002e\n movl (%ecx),%eax\n movl 0x1e0(%eax),%eax\n call *%eax\n testb %al,%al\n je 2f\n movl 0x44(%ebx),%ecx\n pushl $0\n movl (%ecx),%eax\n call *0xbc(%eax)\n"
"2: popl %edi\n popl %esi\n popl %ebx\n popl %ebp\n ret $8\n");
extern "C" void f4a8dd0(void);
PCREG(4a8dd0,f4a8dd0);
