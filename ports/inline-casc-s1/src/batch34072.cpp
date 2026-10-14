// batch34072.cpp - escalation batch 34072: 0x466c30, 0x54c300 (tail thunk), 0x5d4210, 0x537790, 0x433350 (tail thunk that rewrites its second stack argument).
#include "ff.h"

extern "C" void thunk54c300(void);
extern "C" void thunk433350(void);
asm(
    ".text\n"
    ".globl thunk54c300\n"
    "thunk54c300:\n"          // this = [this+0x50]; null: ret 4; else slot 0x18 (stack untouched)
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 0x50(%ecx), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 1f\n"
    "  mov (%ecx), %eax\n"
    "  pop %ebp\n"
    "  jmp *0x18(%eax)\n"
    "1:\n"
    "  pop %ebp\n"
    "  ret $4\n"
    ".globl thunk433350\n"
    "thunk433350:\n"          // second stack arg = (byte != 0), then tail jump to 0x431410
    "  push %ebp\n  mov %esp, %ebp\n"
    "  xor %eax, %eax\n"
    "  cmpb %al, 0xc(%ebp)\n"
    "  setne %al\n"
    "  mov %eax, 0xc(%ebp)\n"
    "  pop %ebp\n"
    "  jmp ext_431410\n");
PCREG(54c300, thunk54c300);
PCREG(433350, thunk433350);

// 0x466c30, stdcall(a, b, c, d) ret 0x10: 2 when a == 0x465708 and b, c, d are all zero, else 0.
static u32 STDCALL fn466c30(u32 a, u32 b, u32 c, u32 d) {
  if (a != 0x465708) return 0;
  if (a == 0 || (b == 0 && c == 0 && d == 0)) return 2;
  return 0;
}
PCREG(466c30, fn466c30);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5d4210, thiscall(src) ret 4: copies unaligned fields from src to this: dword +0x56, byte +0x5a, dwords +0x5b, +0x5f, +0x63, +0x67, +0x6b.
static void THISCALL fn5d4210(u8 *self, u8 *src) {
  wr32(self + 0x56, rd32(src + 0x56));
  self[0x5a] = src[0x5a];
  wr32(self + 0x5b, rd32(src + 0x5b));
  wr32(self + 0x5f, rd32(src + 0x5f));
  wr32(self + 0x63, rd32(src + 0x63));
  wr32(self + 0x67, rd32(src + 0x67));
  wr32(self + 0x6b, rd32(src + 0x6b));
}
PCREG(5d4210, fn5d4210);

// 0x537790, thiscall(a) ret 4: base = unaligned dword [this+0x5302]; 0 when base or a is null; a itself when [a] == 1; when [a] == 2: [a+8] + base unless [a+8] is 0; else 0.
static u32 THISCALL fn537790(u8 *self, u8 *a) {
  u32 base = rd32(self + 0x5302);
  if (base == 0) return 0;
  if (!a) return 0;
  u32 k = *(u32 *)a - 1;
  if (k == 0) return (u32)a;
  if (k != 1) return 0;
  u32 o = *(u32 *)(a + 8);
  if (o == 0) return 0;
  return o + base;
}
PCREG(537790, fn537790);
