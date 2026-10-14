// batch34010.cpp - cascade escalation batch 34010: engine-pointer-gated functions, an indexed read and a two-argument setter.
#include "ff.h"

extern "C" void thunk48f460(void);

asm(
    ".text\n"
    ".globl thunk48f460\n"
    "thunk48f460:\n"          // ecx = [engine+0x1a9f]; when non-null tail-jump to its vtable slot 0x94, else ret
    "  movl 0x70039c, %eax\n"
    "  movl 0x1a9f(%eax), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x94(%eax)\n"
    "1:\n"
    "  ret\n");
PCREG(48f460, thunk48f460);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x512f80, thiscall: when the engine pointer at +0x1a9f is non-null, return the unaligned dword [this+0x12f], else 0.
static u32 THISCALL fn512f80(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (rd32u(eng + 0x1a9f) != 0) return rd32u(self + 0x12f);
  return 0;
}
PCREG(512f80, fn512f80);

// 0x537090, thiscall(idx) ret 4: unaligned dword at this + idx*9 + 0x515e.
static u32 THISCALL fn537090(u8 *self, u32 idx) { return rd32u(self + idx * 9 + 0x515e); }
PCREG(537090, fn537090);

// 0x4646f0, thiscall(a, b) ret 8: [+0x68] = b, [+0x60] = a.
static void THISCALL fn4646f0(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 0x68) = b;
  *(u32 *)(self + 0x60) = a;
}
PCREG(4646f0, fn4646f0);
