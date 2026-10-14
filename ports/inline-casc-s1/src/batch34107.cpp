// batch34107.cpp - escalation batch 34107: 0x4f8c20, 0x549380, 0x5af230, 0x5fef70, 0x4487f0, 0x4ee210, 0x5227c0 (asm).
#include "ff.h"

extern "C" void thunk5227c0(void);
asm(
    ".text\n"
    ".globl thunk5227c0\n"
    "thunk5227c0:\n"          // cell = ext_5003d0([a+4], 0); arg = (*cell != 0); tail jump through slot 0x380 of the object at [this+0x1c]
    "  push %ebp\n  mov %esp, %ebp\n"
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 8(%ebp), %ecx\n"
    "  push $0\n"
    "  mov 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  mov 0x1c(%esi), %ecx\n"
    "  pop %esi\n"
    "  cmpl $0, (%eax)\n"
    "  mov (%ecx), %edx\n"
    "  setne %al\n"
    "  movzbl %al, %eax\n"
    "  mov %eax, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp *0x380(%edx)\n");
PCREG(5227c0, thunk5227c0);

extern "C" u32 THISCALL ext_4f9c60(void *self, void *a);          // thiscall ret 4
extern "C" void ext_634273(void *p, u32 n);                       // cdecl free
extern "C" u32 THISCALL ext_5af040(void *self, u32 a);            // thiscall ret 4
extern "C" u32 THISCALL ext_5fe560(void *self, void *a);          // thiscall ret 4
extern "C" u32 ext_41e2c0(u32 a);                                 // cdecl
extern "C" u32 THISCALL ext_45d5b0(void *self, void *a);          // forwards through slot 0x48 (ret 4)
extern "C" u32 THISCALL ext_43e990(void *self, u32 a, u32 b, u32 c);   // thiscall ret 0xc
extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);              // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4f8c20, thiscall(a) ret 4: ext_4f9c60(this, a); unaligned dwords [this+0x1c3] and [this+0x1c7] = those of a; returns the last one.
static u32 THISCALL fn4f8c20(u8 *self, u8 *a) {
  ext_4f9c60(self, a);
  wr32(self + 0x1c3, rd32(a + 0x1c3));
  u32 v = rd32(a + 0x1c7);
  wr32(self + 0x1c7, v);
  return v;
}
PCREG(4f8c20, fn4f8c20);

// 0x549380, thiscall(flags) ret 4, returns this: unaligned dword [this+0x40b1] = 0x6a3298; [this] = 0x6a3234; frees the object (size 0x63db) when bit 0 of flags is set.
static u32 THISCALL fn549380(u8 *self, u32 flags) {
  wr32(self + 0x40b1, 0x6a3298);
  *(u32 *)self = 0x6a3234;
  if (flags & 1) ext_634273(self, 0x63db);
  return (u32)self;
}
PCREG(549380, fn549380);

// 0x5af230, thiscall(a) ret 4: i = ext_5af040(this, a); 0 when i == 8, else [this + 4*i].
static u32 THISCALL fn5af230(u8 *self, u32 a) {
  u32 i = ext_5af040(self, a);
  if (i == 8) return 0;
  return *(u32 *)(self + i * 4);
}
PCREG(5af230, fn5af230);

// 0x5fef70, thiscall(a) ret 4: ext_5fe560(this, a); ext_41e2c0(unaligned [a+0x9e]); [this+4] -= 1; returns the second call's eax.
static u32 THISCALL fn5fef70(u8 *self, u8 *a) {
  ext_5fe560(self, a);
  u32 v = ext_41e2c0(rd32(a + 0x9e));
  *(u32 *)(self + 4) -= 1;
  return v;
}
PCREG(5fef70, fn5fef70);

// 0x4487f0, thiscall(a) ret 4: [this+0x18] = [a+0x18]; ext_45d5b0(this, a); when byte [[[0x70039c]+0x9b]+0xbad] is set: [this+0x14] |= 1.
static void THISCALL fn4487f0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x18) = *(u32 *)(a + 0x18);
  ext_45d5b0(self, a);
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  if (o[0xbad]) *(u32 *)(self + 0x14) |= 1;
}
PCREG(4487f0, fn4487f0);

// 0x4ee210, thiscall(a, b, c) ret 0xc, returns this: ext_43e990(this, a, b, c); [this] = 0x697bc0; [this+0x5c] = 0.
static u32 THISCALL fn4ee210(u8 *self, u32 a, u32 b, u32 c) {
  ext_43e990(self, a, b, c);
  *(u32 *)self = 0x697bc0;
  *(u32 *)(self + 0x5c) = 0;
  return (u32)self;
}
PCREG(4ee210, fn4ee210);
