// batch292.cpp - unclaimed area 67: 0x5fc260 (stdcall, one argument p). Inline asm for the caller-cleaned slot calls and the
// ext 0x5f49e0 call, whose three pushed arguments stay on the stack until the final add esp.
#include "ff.h"

extern "C" u32 ext_5fa630(void);     // getter for the global at 0x724270, original code (plain ret)
extern "C" void ext_5f49e0(void);    // helper, original code (plain ret; ECX = this, three stack arguments left to the caller)

typedef u32 (THISCALL *F0)(u8 *self);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// Static slots: inline asm operands must not be esp-relative, because the asm pushes arguments.
static volatile u32 s_r24, s_L4, s_tbl, s_p, s_g, s_vtg;

// 0x5fc260, stdcall (ret 4). See docs/20-unclaimed-67.md batch 292.
static u32 STDCALL callChain5fc260(u8 *pP) {
  u32 p = (u32)(unsigned long)pP;
  u32 L4 = (((u32)*(u8 *)(unsigned long)(p + 0xac)) & 0xf) == 4 ? rdw(p, 0x16) : 0x677b5au;
  u32 g = ext_5fa630();
  u32 idx = ((u32)*(u16 *)(unsigned long)(p + 0xac)) & 0xf;
  u32 tbl = rdw(0x6efbe4, 4 * idx);
  u32 vtg = rdw(g, 0);
  u32 r24 = ((F0)(unsigned long)rdw(rdw(p, 0), 0x24))(pP);
  s_r24 = r24;
  s_L4 = L4;
  s_tbl = tbl;
  s_p = p;
  s_g = g;
  s_vtg = vtg;
  asm volatile(
      "pushl %[r24]\n\t"
      "pushl %[L4]\n\t"
      "pushl %[tbl]\n\t"
      "movl %[p], %%ecx\n\t"
      "call ext_5f49e0\n\t"
      "pushl %%eax\n\t"
      "movl %[p], %%ecx\n\t"
      "movl %[p], %%edx\n\t"
      "movl (%%edx), %%edx\n\t"
      "call *0x28(%%edx)\n\t"
      "pushl %%eax\n\t"
      "movl %[p], %%eax\n\t"
      "pushl 0xac2(%%eax)\n\t"
      "pushl 0x6efbfc\n\t"
      "pushl $0x724280\n\t"
      "pushl %[g]\n\t"
      "movl %[vtg], %%edx\n\t"
      "call *0x14(%%edx)\n\t"
      "addl $0x24, %%esp\n\t"
      "movl $0x724280, %%eax\n\t"
      :
      : [r24] "m"(s_r24), [L4] "m"(s_L4), [tbl] "m"(s_tbl), [p] "m"(s_p), [g] "m"(s_g), [vtg] "m"(s_vtg)
      : "eax", "ecx", "edx", "memory", "cc");
  return 0x724280u;
}
PCREG(5fc260, callChain5fc260);
