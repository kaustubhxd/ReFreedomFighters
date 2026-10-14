// batch34122.cpp - cascade tier E, batch 34122: 0x4293e0 (notify three object lists, then tail), 0x432be0 (free and reset every item of a container).
#include "ff.h"

extern "C" void thunk4293e0(void);
asm(
    ".text\n"
    ".globl thunk4293e0\n"
    "thunk4293e0:\n"          // for the three object arrays (count [this+0xc] at +4, [this+0x1c] at +0x10, [this+0x60] at +0x20): obj->slot4([this+0x7c]); then tail jump through slot 0xc of this
    "  push %ebx\n"
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  push %edi\n"
    "  xor %edi, %edi\n"
    "  cmp %edi, 0xc(%esi)\n"
    "  jbe 2f\n"
    "  lea 4(%esi), %ebx\n"
    "1:\n"
    "  mov (%ebx), %ecx\n"
    "  push 0x7c(%esi)\n"
    "  mov (%ecx), %eax\n"
    "  call *4(%eax)\n"
    "  inc %edi\n"
    "  lea 4(%ebx), %ebx\n"
    "  cmp 0xc(%esi), %edi\n"
    "  jb 1b\n"
    "2:\n"
    "  xor %edi, %edi\n"
    "  cmp %edi, 0x1c(%esi)\n"
    "  jbe 4f\n"
    "  lea 0x10(%esi), %ebx\n"
    "3:\n"
    "  mov (%ebx), %ecx\n"
    "  push 0x7c(%esi)\n"
    "  mov (%ecx), %eax\n"
    "  call *4(%eax)\n"
    "  inc %edi\n"
    "  lea 4(%ebx), %ebx\n"
    "  cmp 0x1c(%esi), %edi\n"
    "  jb 3b\n"
    "4:\n"
    "  xor %edi, %edi\n"
    "  cmp %edi, 0x60(%esi)\n"
    "  jbe 6f\n"
    "  lea 0x20(%esi), %ebx\n"
    "5:\n"
    "  mov (%ebx), %ecx\n"
    "  push 0x7c(%esi)\n"
    "  mov (%ecx), %eax\n"
    "  call *4(%eax)\n"
    "  inc %edi\n"
    "  lea 4(%ebx), %ebx\n"
    "  cmp 0x60(%esi), %edi\n"
    "  jb 5b\n"
    "6:\n"
    "  mov (%esi), %eax\n"
    "  mov %esi, %ecx\n"
    "  pop %edi\n"
    "  pop %esi\n"
    "  pop %ebx\n"
    "  jmp *0xc(%eax)\n");
PCREG(4293e0, thunk4293e0);

extern "C" void ext_634273(void *p, u32 n);           // cdecl free
extern "C" u32 THISCALL ext_4cbec0(void *self);       // thiscall, plain ret

// 0x432be0, thiscall plain: m = this+0x84 (an embedded container): m->slot0x4c(&it); p = m->slot0x64(&it); while p: free the unaligned pointer [p+0xaf] (size 1) when set; ext_4cbec0(p); m->slot0x44(&it); p = m->slot0x64(&it).
static void THISCALL fn432be0(u8 *self) {
  u32 it[3];
  u8 *m = self + 0x84;
  vcall<void>(m, 0x4c, (u32)it);
  u8 *p = vcall<u8 *>(m, 0x64, (u32)it);
  while (p) {
    u32 q = p[0xaf] | p[0xb0] << 8 | p[0xb1] << 16 | (u32)p[0xb2] << 24;
    if (q) ext_634273((void *)q, 1);
    ext_4cbec0(p);
    vcall<void>(m, 0x44, (u32)it);
    p = vcall<u8 *>(m, 0x64, (u32)it);
  }
}
PCREG(432be0, fn432be0);
