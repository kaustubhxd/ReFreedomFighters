#include "ff.h"
// Fatal diagnostic: logger(file, line)->sink; sink(sink, message); exit(1).
// No return exists; keep the stack at the exit boundary identical to the exe.
extern "C" __attribute__((naked)) void fatal42461c() {
 asm volatile(
 "movl 0x700390, %ecx\n\t"
 "pushl $0x712\n\tpushl $0x677fb4\n\t"
 "movl (%ecx), %eax\n\tcall *0x20(%eax)\n\t"
 "pushl $0x678184\n\tpushl %eax\n\t"
 "movl (%eax), %ecx\n\tcall *0x2c(%ecx)\n\t"
 "addl $8, %esp\n\tpushl $1\n\tcall *0x676394\n\tud2\n\t");
}
PCREG(42461c, fatal42461c);
