// batch34089.cpp - escalation batch 34089: small wrappers 0x64f910, 0x4d3cd0, 0x4e66a0, 0x5f3410 (asm), 0x473fc0, 0x537880 (asm).
#include "ff.h"

extern "C" void thunk5f3410(void);
extern "C" void thunk537880(void);
asm(
    ".text\n"
    ".globl thunk5f3410\n"
    "thunk5f3410:\n"          // p = ext_41e290(0x1014) (cdecl); null: return 0; else tail jump to 0x5f12d0 with ecx = p
    "  push $0x1014\n"
    "  call ext_41e290\n"
    "  add $4, %esp\n"
    "  test %eax, %eax\n"
    "  je 1f\n"
    "  mov %eax, %ecx\n"
    "  jmp ext_5f12d0\n"
    "1:\n"
    "  xor %eax, %eax\n"
    "  ret\n"
    ".globl thunk537880\n"
    "thunk537880:\n"          // p = unaligned [this+0x52fa]; when set ext_4690b0 with ecx = p; then tail jump through slot 0x194 of this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 0x52fa(%esi), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 2f\n"
    "  call ext_4690b0\n"
    "2:\n"
    "  mov (%esi), %eax\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp *0x194(%eax)\n");
PCREG(5f3410, thunk5f3410);
PCREG(537880, thunk537880);

extern "C" void THISCALL ext_63fd80(void *self, void *a);                 // thiscall ret 4
extern "C" u32 THISCALL ext_4d24e0(void *self, u32 a, u32 b, u32 c, u32 d);   // thiscall ret 0x10
extern "C" void ext_634273(void *p, u32 n);                               // cdecl free
extern "C" u32 THISCALL ext_4666d0(void *self);                           // thiscall, plain ret

// 0x64f910, thiscall, plain ret: ext_63fd80(unaligned pointer [this+0xbd], this); byte [this+0x33] = 0.
static void THISCALL fn64f910(u8 *self) {
  u8 *m = (u8 *)(self[0xbd] | self[0xbe] << 8 | self[0xbf] << 16 | (u32)self[0xc0] << 24);
  ext_63fd80(m, self);
  self[0x33] = 0;
}
PCREG(64f910, fn64f910);

// 0x4d3cd0, thiscall(a, b) ret 8: ext_4d24e0(this, a, 4, b, 0) (ecx = this passed through).
static u32 THISCALL fn4d3cd0(u8 *self, u32 a, u32 b) {
  return ext_4d24e0(self, a, 4, b, 0);
}
PCREG(4d3cd0, fn4d3cd0);

// 0x4e66a0, thiscall, plain ret: p = [this+4]; [this] = 0x6974d0; when p is set ext_634273(p, 1).
static void THISCALL fn4e66a0(u8 *self) {
  u8 *p = *(u8 **)(self + 4);
  *(u32 *)self = 0x6974d0;
  if (p) ext_634273(p, 1);
}
PCREG(4e66a0, fn4e66a0);

// 0x473fc0, thiscall(a) ret 4, bool: v = ext_4666d0(this+0x26a); [a] = v; v != 0.
static bool THISCALL fn473fc0(u8 *self, u32 *a) {
  u32 v = ext_4666d0(self + 0x26a);
  *a = v;
  return v != 0;
}
PCREG(473fc0, fn473fc0);
