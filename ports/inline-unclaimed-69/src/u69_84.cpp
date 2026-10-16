// u69_84.cpp - area 69, residue-8 cleanup routines. Each is `push N; mov eax,[ebp+-disp]; push eax; call 0x634273; add esp,8; ret`:
// frees the pointer stored in a local (ebp-relative) with sized delete 0x634273 (cdecl, two args; logging GUESS stub in the spec). Plain ret, no frame.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);   // sized delete, cdecl, two args (GUESS stub)

extern "C" void cleanup663e42(void);
__asm__(
    ".text\n"
    ".globl cleanup663e42\n"
    "cleanup663e42:\n"
    "  pushl $0x50\n"
    "  movl -0x94(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(663e42, cleanup663e42);

extern "C" void cleanup6645c8(void);
__asm__(
    ".text\n"
    ".globl cleanup6645c8\n"
    "cleanup6645c8:\n"
    "  pushl $0x28\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(6645c8, cleanup6645c8);

extern "C" void cleanup6668c0(void);
__asm__(
    ".text\n"
    ".globl cleanup6668c0\n"
    "cleanup6668c0:\n"
    "  pushl $0x2c\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(6668c0, cleanup6668c0);

extern "C" void cleanup667186(void);
__asm__(
    ".text\n"
    ".globl cleanup667186\n"
    "cleanup667186:\n"
    "  pushl $0x1c\n"
    "  movl 0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(667186, cleanup667186);

extern "C" void cleanup6677c8(void);
__asm__(
    ".text\n"
    ".globl cleanup6677c8\n"
    "cleanup6677c8:\n"
    "  pushl $0x108\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(6677c8, cleanup6677c8);

extern "C" void cleanup6695c0(void);
__asm__(
    ".text\n"
    ".globl cleanup6695c0\n"
    "cleanup6695c0:\n"
    "  pushl $0x432\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(6695c0, cleanup6695c0);

extern "C" void cleanup669848(void);
__asm__(
    ".text\n"
    ".globl cleanup669848\n"
    "cleanup669848:\n"
    "  pushl $0xac\n"
    "  movl 0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(669848, cleanup669848);

extern "C" void cleanup669fc8(void);
__asm__(
    ".text\n"
    ".globl cleanup669fc8\n"
    "cleanup669fc8:\n"
    "  pushl $0x1c\n"
    "  movl 0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(669fc8, cleanup669fc8);

extern "C" void cleanup66a748(void);
__asm__(
    ".text\n"
    ".globl cleanup66a748\n"
    "cleanup66a748:\n"
    "  pushl $0x108\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66a748, cleanup66a748);

extern "C" void cleanup66a880(void);
__asm__(
    ".text\n"
    ".globl cleanup66a880\n"
    "cleanup66a880:\n"
    "  pushl $0x120a\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66a880, cleanup66a880);

extern "C" void cleanup66ad80(void);
__asm__(
    ".text\n"
    ".globl cleanup66ad80\n"
    "cleanup66ad80:\n"
    "  pushl $0xf4\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66ad80, cleanup66ad80);

extern "C" void cleanup66b14c(void);
__asm__(
    ".text\n"
    ".globl cleanup66b14c\n"
    "cleanup66b14c:\n"
    "  pushl $0x108\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66b14c, cleanup66b14c);

extern "C" void cleanup66bb44(void);
__asm__(
    ".text\n"
    ".globl cleanup66bb44\n"
    "cleanup66bb44:\n"
    "  pushl $0x108\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66bb44, cleanup66bb44);

extern "C" void cleanup66c684(void);
__asm__(
    ".text\n"
    ".globl cleanup66c684\n"
    "cleanup66c684:\n"
    "  pushl $0x1c\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66c684, cleanup66c684);

extern "C" void cleanup66ca4d(void);
__asm__(
    ".text\n"
    ".globl cleanup66ca4d\n"
    "cleanup66ca4d:\n"
    "  pushl $0x29\n"
    "  movl -0x14(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66ca4d, cleanup66ca4d);

extern "C" void cleanup66d1c0(void);
__asm__(
    ".text\n"
    ".globl cleanup66d1c0\n"
    "cleanup66d1c0:\n"
    "  pushl $0x48\n"
    "  movl -0x18(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66d1c0, cleanup66d1c0);

extern "C" void cleanup66d589(void);
__asm__(
    ".text\n"
    ".globl cleanup66d589\n"
    "cleanup66d589:\n"
    "  pushl $0x17e\n"
    "  movl -0xc0(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66d589, cleanup66d589);

extern "C" void cleanup66e980(void);
__asm__(
    ".text\n"
    ".globl cleanup66e980\n"
    "cleanup66e980:\n"
    "  pushl $0x65\n"
    "  movl -0x18(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66e980, cleanup66e980);

extern "C" void cleanup66eac0(void);
__asm__(
    ".text\n"
    ".globl cleanup66eac0\n"
    "cleanup66eac0:\n"
    "  pushl $0x14\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66eac0, cleanup66eac0);

extern "C" void cleanup66eacf(void);
__asm__(
    ".text\n"
    ".globl cleanup66eacf\n"
    "cleanup66eacf:\n"
    "  pushl $0x14\n"
    "  movl -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66eacf, cleanup66eacf);

extern "C" void cleanup66ed48(void);
__asm__(
    ".text\n"
    ".globl cleanup66ed48\n"
    "cleanup66ed48:\n"
    "  pushl $0x108\n"
    "  movl 0xc(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  ret\n");
PCREG(66ed48, cleanup66ed48);

