#include "ff.h"
extern "C" void ext_634dca(void);
asm(
".text\n.globl f404ed0\nf404ed0:\n"
" flds 4(%esp)\n fabs\n flds 8(%esp)\n fabs\n fcompp\n"
" flds 4(%esp)\n fmuls 0x10(%esp)\n fnstsw %ax\n fadds 0x6bdffc\n testb $1,%ah\n je 1f\n"
" subl $8,%esp\n fstpl (%esp)\n call ext_634dca\n fmuls 0x14(%esp)\n fstps 0xc(%esp)\n"
" flds 0x10(%esp)\n fmuls 0x18(%esp)\n fadds 0x6bdffc\n fstpl (%esp)\n call ext_634dca\n"
" fmuls 0x14(%esp)\n flds 0xc(%esp)\n movl 0x1c(%esp),%ecx\n addl $8,%esp\n fstps (%ecx)\n"
" flds 4(%esp)\n fcomps 0x6bdfd4\n fnstsw %ax\n testb $0x41,%ah\n jne 2f\n fsubrs 4(%esp)\n jmp 3f\n"
"1: subl $8,%esp\n fstpl (%esp)\n call ext_634dca\n fmuls 0x14(%esp)\n fstps 0xc(%esp)\n"
" flds 0x10(%esp)\n fmuls 0x18(%esp)\n fadds 0x6bdffc\n fstpl (%esp)\n call ext_634dca\n"
" fmuls 0x14(%esp)\n movl 0x1c(%esp),%ecx\n addl $8,%esp\n fstps (%ecx)\n flds (%ecx)\n"
" fcoms 0x6bdfd4\n fnstsw %ax\n testb $0x41,%ah\n jne 2f\n fsubrs 4(%esp)\n jmp 3f\n"
"2: fsubs 4(%esp)\n"
"3: movl 0x18(%esp),%edx\n movl 0x1c(%esp),%eax\n testl %eax,%eax\n fstps (%edx)\n je 4f\n"
" flds (%ecx)\n fabs\n flds (%edx)\n fld %st(1)\n fmull 0x6be0a8\n fcompp\n fnstsw %ax\n testb $1,%ah\n je 5f\n"
" fmull 0x6be0a0\n fstps (%edx)\n flds (%ecx)\n fchs\n fstps (%ecx)\n ret\n"
"5: fstp %st(0)\n4: ret\n");
extern "C" void f404ed0(void);
PCREG(404ed0,f404ed0);
