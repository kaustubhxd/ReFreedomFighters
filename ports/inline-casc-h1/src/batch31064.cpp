// batch31064.cpp - message handlers, pool allocator, table lookups, search, two asm tail-call functions.
#include "ff.h"

extern "C" void ext_597a70(void);
extern "C" THISCALL u8 rest597a20(u8 *self, int arg);

asm(
    ".text\n"
    ".globl thunk597a20\nthunk597a20:\n  movl 0x70039c, %eax\n  cmpl $1, 0x1b5d(%eax)\n  jne rest597a20\n  jmp ext_597a70\n"
    ".globl thunk4dcd10\nthunk4dcd10:\n"
    "  movl %ecx, %edx\n  movl 4(%esp), %ecx\n  movl 0x24(%edx), %eax\n  cmpl (%ecx), %eax\n  jne 1f\n"
    "  movl 0x28(%edx), %eax\n  cmpl 4(%ecx), %eax\n  jne 1f\n  movl 0x2c(%edx), %eax\n  cmpl 8(%ecx), %eax\n  je 2f\n"
    "1:\n  movl (%ecx), %eax\n  movl %eax, 0x24(%edx)\n  movl 4(%ecx), %eax\n  movl %eax, 0x28(%edx)\n  movl 8(%ecx), %eax\n  movl %eax, 0x2c(%edx)\n"
    "  orl $0x100000, 0x3c(%edx)\n  movl 0x70039c, %eax\n  movl 0x9b(%eax), %eax\n  movl 0x5d31(%eax), %ecx\n  movl (%ecx), %eax\n"
    "  movl %edx, 4(%esp)\n  jmp *(%eax)\n2:\n  ret $4\n");
extern "C" void thunk597a20(void);
extern "C" void thunk4dcd10(void);
PCREG(597a20, thunk597a20);
PCREG(4dcd10, thunk4dcd10);

// 0x597a20 (past the global-flag tail call): linear search of the dword array at this+0x1dae (count at +0x1fae) for arg.
extern "C" THISCALL u8 rest597a20(u8 *self, int arg) {
  int n = *(int *)(self + 0x1fae);
  u32 *a = (u32 *)(self + 0x1dae);
  for (int i = 0; i < n; i++)
    if (a[i] == (u32)arg) return 1;
  return 0;
}

// Message handlers, cdecl (obj, code).
extern "C" int fn62d7f0(u32 *obj, int code) {
  if (code == 0xf) return 0;
  if (code == 0x12) { obj[0] = 0x62da60; return 9; }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return -1;
}
PCREG(62d7f0, fn62d7f0);
extern "C" int fn62da10(u32 *obj, int code) {
  if (code == 0xf) return 0;
  if (code == 0x12) { obj[0] = 0x62cf90; return 0xe; }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return -1;
}
PCREG(62da10, fn62da10);
extern "C" int fn62ddb0(u32 *obj, int code) {
  if (code == 0xf) return 0;
  if (code == 0x12) { obj[0] = 0x62de00; return 0xf; }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return -1;
}
PCREG(62ddb0, fn62ddb0);

// 0x6487a0 thiscall: pool free-list pop with 0x24-byte entries (head u16 at +2).
THISCALL u8 *fn6487a0(u8 *self) {
  u16 h = *(u16 *)(self + 2);
  if (h == 0xffff) return 0;
  u8 *e = self + h * 0x24;
  *(u16 *)(self + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x2e) = 0;
  *(u32 *)(e + 0x30) = 0;
  *(u32 *)(e + 0x10) = 0;
  *(u32 *)(e + 0x14) = 0xffff1202;
  *(u32 *)(e + 0x18) = 0;
  *(u32 *)(e + 0x1c) = 0;
  *(u32 *)(e + 0x20) = 0;
  *(u32 *)(e + 0x24) = 0;
  *(u32 *)(e + 0x28) = 0;
  self[0]++;
  return e + 0x10;
}
PCREG(6487a0, fn6487a0);

// 0x6244e0 cdecl (unused, p): three-byte version of the 0x624490 table bit lookup.
extern "C" u32 fn6244e0(u32, u8 *p) {
  u32 b0 = p[0], b1 = p[1], b2 = p[2];
  u32 t = *(u8 *)(0x6bfd20 + ((b1 >> 2) & 0xf) + (b0 & 0xf) * 16);
  u32 idx = ((b2 >> 5) & 1) + ((b1 & 3) + t * 4) * 2;
  return *(u32 *)(0x6bf720 + idx * 4) & (1u << (b2 & 0x1f));
}
PCREG(6244e0, fn6244e0);

// 0x62ad10 cdecl (unused, start, end, out): -1 if fewer than 6 bytes; else compare with the 6-byte tag at 0x6c0148,
// *out = position reached, return 8 on full match, 0 on mismatch.
extern "C" int fn62ad10(u32, u8 *start, u8 *end, u8 **out) {
  if (end - start < 6) return -1;
  int i = 0;
  do {
    if (*start != *(u8 *)(0x6c0148 + i)) { *out = start; return 0; }
    i++; start++;
  } while (i < 6);
  *out = start;
  return 8;
}
PCREG(62ad10, fn62ad10);
