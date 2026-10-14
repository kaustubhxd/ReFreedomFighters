// batch34103.cpp - escalation batch 34103: wrappers 0x4d3a40, 0x4d3d70, 0x549820 (asm), 0x4b1ab0, 0x5dd690, 0x64fe60, 0x55b0f0.
#include "ff.h"

extern "C" void thunk549820(void);
asm(
    ".text\n"
    ".globl thunk549820\n"
    "thunk549820:\n"          // ext_54cec0(this); when byte [this+0xa26d] is set tail jump through slot 0x9c of this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_54cec0\n"
    "  cmpb $0, 0xa26d(%esi)\n"
    "  je 1f\n"
    "  mov (%esi), %eax\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp *0x9c(%eax)\n"
    "1:\n"
    "  pop %esi\n"
    "  ret\n");
PCREG(549820, thunk549820);

extern "C" u32 THISCALL ext_4d2700(void *self, u32 a, u32 b, u32 c, u32 *d, u32 e);   // thiscall ret 0x14
extern "C" u32 THISCALL ext_4d24e0(void *self, u32 a, u32 b, u32 c, u32 d);           // thiscall ret 0x10
extern "C" u32 THISCALL ext_4b1130(void *self, u32 a);                                // thiscall ret 4
extern "C" u32 THISCALL ext_4e5e60(void *self);                                       // thiscall, plain ret
extern "C" u32 THISCALL ext_47bde0(void *self, u32 a);                                // thiscall ret 4
extern "C" void ext_634273(void *p, u32 n);                                           // cdecl free
extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);                                  // thiscall ret 4
extern "C" u32 THISCALL ext_5002f0(void *m, u32 v);                                   // thiscall ret 4

// 0x4d3a40, thiscall(a, b, c) ret 0xc: ext_4d2700(this, a, 2, c, &b, 0) (address of the parameter slot b); returns its eax.
static u32 THISCALL fn4d3a40(u8 *self, u32 a, u32 b, u32 c) {
  u32 bb = b;
  return ext_4d2700(self, a, 2, c, &bb, 0);
}
PCREG(4d3a40, fn4d3a40);

// 0x4d3d70, thiscall(a, b, c) ret 0xc: ext_4d24e0(this, a, 2, b, c * 4); returns its eax.
static u32 THISCALL fn4d3d70(u8 *self, u32 a, u32 b, u32 c) {
  return ext_4d24e0(self, a, 2, b, c << 2);
}
PCREG(4d3d70, fn4d3d70);

// 0x4b1ab0, thiscall(a) ret 4: ext_4b1130(this, a); v = ext_4e5e60(a); unaligned dword [this+0xda] = v; returns v.
static u32 THISCALL fn4b1ab0(u8 *self, u8 *a) {
  ext_4b1130(self, (u32)a);
  u32 v = ext_4e5e60(a);
  self[0xda] = v; self[0xdb] = v >> 8; self[0xdc] = v >> 16; self[0xdd] = v >> 24;
  return v;
}
PCREG(4b1ab0, fn4b1ab0);

// 0x5dd690, thiscall(a) ret 4: v = ext_4e5e60(a); ext_47bde0([this+0x44], v); returns its eax.
static u32 THISCALL fn5dd690(u8 *self, u8 *a) {
  u32 v = ext_4e5e60(a);
  return ext_47bde0(*(u8 **)(self + 0x44), v);
}
PCREG(5dd690, fn5dd690);

// 0x64fe60, thiscall plain: frees [this+0x2c] (size 1) when set and clears it.
static void THISCALL fn64fe60(u8 *self) {
  u8 *p = *(u8 **)(self + 0x2c);
  if (p) ext_634273(p, 1);
  *(u32 *)(self + 0x2c) = 0;
}
PCREG(64fe60, fn64fe60);

// 0x55b0f0, thiscall(a) ret 4: ext_5002f0(ext_5003d0([a+8], 0), [[[this+0x1c]+0x54]+4]); returns its eax.
static u32 THISCALL fn55b0f0(u8 *self, u8 *a) {
  u8 *o = *(u8 **)(*(u8 **)(self + 0x1c) + 0x54);
  u32 v = *(u32 *)(o + 4);
  u32 *cell = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0(cell, v);
}
PCREG(55b0f0, fn55b0f0);
