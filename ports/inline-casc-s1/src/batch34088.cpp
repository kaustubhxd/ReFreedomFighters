// batch34088.cpp - escalation batch 34088: small call wrappers (0x57db40 / 0x511930 asm thunks, 0x5e4680, 0x517030, 0x5d4750).
#include "ff.h"

extern "C" void thunk57db40(void);
extern "C" void thunk511930(void);
asm(
    ".text\n"
    ".globl thunk57db40\n"
    "thunk57db40:\n"          // ext_5626c0(this); tail jump to 0x57dd10 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_5626c0\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_57dd10\n"
    ".globl thunk511930\n"
    "thunk511930:\n"          // ext_4690b0(this+0xe6); tail jump to 0x4690b0 with ecx = this+0x6d
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  lea 0xe6(%esi), %ecx\n"
    "  call ext_4690b0\n"
    "  lea 0x6d(%esi), %ecx\n"
    "  pop %esi\n"
    "  jmp ext_4690b0\n");
PCREG(57db40, thunk57db40);
PCREG(511930, thunk511930);

extern "C" void THISCALL ext_5e3e90(void *self);                    // thiscall, plain ret
extern "C" u32 THISCALL ext_516b60(void *self, u32 a, u32 b, u32 c);   // thiscall ret 0xc
extern "C" u32 THISCALL ext_589c20(void *self, u32 a);              // thiscall ret 4

// 0x5e4680, thiscall, plain ret: ext_5e3e90(this); then the unaligned word [this+0x371] = 0x101.
static void THISCALL fn5e4680(u8 *self) {
  ext_5e3e90(self);
  self[0x371] = 1;
  self[0x372] = 1;
}
PCREG(5e4680, fn5e4680);

// 0x517030, thiscall(a, b) ret 8: ext_516b60(this, a, b, unaligned dword [this+0x29]).
static u32 THISCALL fn517030(u8 *self, u32 a, u32 b) {
  u32 c = self[0x29] | self[0x2a] << 8 | self[0x2b] << 16 | (u32)self[0x2c] << 24;
  return ext_516b60(self, a, b, c);
}
PCREG(517030, fn517030);

// 0x5d4750, thiscall, returns eax: v = ext_589c20([0x7003b8], 0); unaligned dword [this+0x5f] = v.
static u32 THISCALL fn5d4750(u8 *self) {
  u32 v = ext_589c20(G(void *, 0x7003b8), 0);
  self[0x5f] = v; self[0x60] = v >> 8; self[0x61] = v >> 16; self[0x62] = v >> 24;
  return v;
}
PCREG(5d4750, fn5d4750);
