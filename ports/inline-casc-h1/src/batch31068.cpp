// batch31068.cpp - call-through thunks (asm so the stack is exact) and two field-logic functions.
#include "ff.h"

#define P32(p) (*(u32 *)(p))

extern "C" void ext_604d30(void);
extern "C" void ext_6038e0(void);
extern "C" void ext_4bb550(void);
extern "C" void ext_5dbc30(void);
extern "C" void ext_4c0a90(void);
extern "C" void ext_41e290(void);
extern "C" void ext_564b10(void);
extern "C" void ext_56bd90(void);
extern "C" void ext_562260(void);
extern "C" void ext_578aa0(void);

asm(
    ".text\n"
    ".globl thunk5f28d0\nthunk5f28d0:\n  call ext_604d30\n  jmp ext_6038e0\n"
    ".globl thunk4bb600\nthunk4bb600:\n  andl $0xffffffbf, 4(%ecx)\n  call ext_4bb550\n  movb $1, %al\n  ret $4\n"
    ".globl thunk5dbc20\nthunk5dbc20:\n  andl $0xffffffbf, 4(%ecx)\n  call ext_5dbc30\n  movb $1, %al\n  ret $4\n"
    ".globl thunk4c1e20\nthunk4c1e20:\n  pushl 8(%esp)\n  call ext_4c0a90\n  ret $8\n"
    ".globl thunk4ce850\nthunk4ce850:\n  movl 0x10(%ecx), %eax\n  leal 0x10(,%eax,4), %eax\n  pushl %eax\n  call ext_41e290\n  addl $4, %esp\n  ret\n"
    ".globl thunk56ba00\nthunk56ba00:\n  pushl %esi\n  movl %ecx, %esi\n  call ext_564b10\n  movl %esi, %ecx\n  popl %esi\n  jmp ext_56bd90\n"
    ".globl thunk578d20\nthunk578d20:\n  pushl %esi\n  movl %ecx, %esi\n  call ext_562260\n  movl %esi, %ecx\n  popl %esi\n  jmp ext_578aa0\n");
extern "C" void thunk5f28d0(void);
extern "C" void thunk4bb600(void);
extern "C" void thunk5dbc20(void);
extern "C" void thunk4c1e20(void);
extern "C" void thunk4ce850(void);
extern "C" void thunk56ba00(void);
extern "C" void thunk578d20(void);
PCREG(5f28d0, thunk5f28d0);
PCREG(4bb600, thunk4bb600);
PCREG(5dbc20, thunk5dbc20);
PCREG(4c1e20, thunk4c1e20);
PCREG(4ce850, thunk4ce850);
PCREG(56ba00, thunk56ba00);
PCREG(578d20, thunk578d20);

// 0x4625c0 thiscall ret 8 (idx, on): maintain flag bit 3 of the 0x18-byte record idx (array at this+0x1c, count at +0x20); record 0's bit 3
// means "some record has it". Returns the old bit of record idx.
THISCALL u8 fn4625c0(u8 *self, u32 idx, u32 on) {
  u8 *base = *(u8 **)(self + 0x1c);
  u8 *e = base + idx * 0x18;
  u32 fl = P32(e + 4);
  u8 bl = (fl >> 3) & 1;
  u8 cl = (u8)on;
  if (cl == bl) return bl;
  if (cl) {
    P32(base + 4) |= 8;
    P32(e + 4) |= 8;
    return bl;
  }
  P32(e + 4) = fl & 0xfffffff7;
  u32 n = P32(self + 0x20);
  u32 i = 1;
  if (n != 1) {
    u8 *p = base + 0x1c;
    for (;;) {
      if (*p & 8) break;
      i++;
      p += 0x18;
      if (i == n) break;
    }
  }
  if (i == n) P32(*(u8 **)(self + 0x1c) + 4) &= 0xfffffff7;
  return bl;
}
PCREG(4625c0, fn4625c0);

// 0x478640 thiscall: take the next queued entry out of the list at this->[0x695] into this+0x6ce.. state.
THISCALL void fn478640(u8 *self) {
  if (P32(self + 0x6ce) != 0 && P32(self + 0x64c) == 10) return;
  u8 *list = *(u8 **)(self + 0x695);
  *(u16 *)(self + 0x6d2) = 0;
  if (!list) return;
  if (P32(list + 0x10) == 0) return;
  int n = (int)P32(list + 8) - 1;
  if (n <= 0) return;
  u32 *arr = *(u32 **)(list + 0x14);
  int i = 0;
  while (arr[i] == 0) {
    i++;
    if (!(i < n)) return;
  }
  u8 *q = (u8 *)arr[i];
  P32(self + 0x6d6) = P32(*(u8 **)(list + 0xc) + i * 16 - 0x10);
  *(u16 *)(self + 0x6d2) = (u16)i;
  *(u16 *)(self + 0x6d4) = (u16)(*(u16 *)(q + 2) & 0xfff);
  P32(self + 0x6ce) = P32(((u8 **)*(u8 **)(list + 0x14))[i] + 0x1c);
  ((u32 *)*(u8 **)(list + 0x14))[i] = 0;
  u32 *arr2 = *(u32 **)(*(u8 **)(self + 0x695) + 0x14);
  arr2[i + 1] = 0;
}
PCREG(478640, fn478640);
