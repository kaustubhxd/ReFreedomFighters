// batch34094.cpp - escalation batch 34094: 0x636330 (constructor), 0x54cd70 (deleting destructor), 0x55c8b0 (asm), 0x596d30, 0x489da0, 0x623050 (byte copy), 0x62cc90 (event filter).
#include "ff.h"

extern "C" void thunk55c8b0(void);
asm(
    ".text\n"
    ".globl thunk55c8b0\n"
    "thunk55c8b0:\n"          // cell = ext_5003d0([a+4], 0); arg = low word of *cell; tail jump through slot 0x6a0 of [this+0x1c] with ecx = that object
    "  push %ebp\n  mov %esp, %ebp\n"
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 8(%ebp), %ecx\n"
    "  push $0\n"
    "  mov 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  mov 0x1c(%esi), %ecx\n"
    "  pop %esi\n"
    "  movzwl (%eax), %eax\n"
    "  mov (%ecx), %edx\n"
    "  mov %eax, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp *0x6a0(%edx)\n");
PCREG(55c8b0, thunk55c8b0);

extern "C" void ext_634273(void *p, u32 n);                 // cdecl free
extern "C" u32 THISCALL ext_5a5e90(void *self, u32 a);      // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x636330, thiscall plain, returns this: constructor with magic 0x50414c4f at +4, vtable 0x6c2080, zeroed fields (unaligned at +0x29, +0x2d, +0x36), bytes +0x28 / +0x31 / +0x3a = 0.
static u32 THISCALL fn636330(u8 *self) {
  wr32(self + 0x1c, 0);
  wr32(self + 4, 0x50414c4f);
  wr32(self + 8, 0);
  wr32(self + 0xc, 0);
  wr32(self + 0x10, 0);
  wr32(self + 0x14, 0);
  wr32(self + 0x18, 0);
  self[0x28] = 0;
  wr32(self + 0x29, 0);
  wr32(self + 0x2d, 0);
  self[0x31] = 0;
  wr32(self, 0x6c2080);
  wr32(self + 0x36, 0);
  self[0x3a] = 0;
  return (u32)self;
}
PCREG(636330, fn636330);

// 0x54cd70, thiscall(flags) ret 4, returns this: [this] = 0x6a3e14; frees the object (size 0xa269) when bit 0 of flags is set.
static u32 THISCALL fn54cd70(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a3e14;
  if (flags & 1) ext_634273(self, 0xa269);
  return (u32)self;
}
PCREG(54cd70, fn54cd70);

// 0x596d30, thiscall(a) ret 4: v = min(a, unaligned [this+0x1fbe]) (signed); unaligned [this+0x1fba] = v; when m = unaligned [this+0x1d0f] is set: ext_5a5e90(m, unaligned [this+0x1fb6]).
static void THISCALL fn596d30(u8 *self, s32 a) {
  s32 mx = (s32)rd32(self + 0x1fbe);
  s32 v = a > mx ? mx : a;
  u8 *m = (u8 *)rd32(self + 0x1d0f);
  wr32(self + 0x1fba, v);
  if (m) ext_5a5e90(m, rd32(self + 0x1fb6));
}
PCREG(596d30, fn596d30);

// 0x489da0, thiscall(a, b, c) ret 0xc, bool: when [[this+4]+0x417] has any of 0x7b: unaligned [this+0x1d] = [[0x70039c]+0x40] + 0x66, returns true. Else true when [this+0x1d] > [[0x70039c]+0x40] (signed).
static bool THISCALL fn489da0(u8 *self, u32 a, u32 b, u32 c) {
  (void)a; (void)b; (void)c;
  if (*(u32 *)(*(u8 **)(self + 4) + 0x417) & 0x7b) {
    wr32(self + 0x1d, *(u32 *)(G(u8 *, 0x70039c) + 0x40) + 0x66);
    return true;
  }
  return (s32)rd32(self + 0x1d) > *(s32 *)(G(u8 *, 0x70039c) + 0x40);
}
PCREG(489da0, fn489da0);

// 0x623050, cdecl(a, psrc, srcend, pdst, dstend): copies bytes from *psrc towards srcend into *pdst up to dstend, advancing both cursors.
static void fn623050(u32 a, u8 **psrc, u8 *srcend, u8 **pdst, u8 *dstend) {
  (void)a;
  if (*psrc == srcend) return;
  for (;;) {
    u8 *d = *pdst;
    if (d == dstend) return;
    *d = **psrc;
    (*pdst)++;
    (*psrc)++;
    if (*psrc == srcend) return;
  }
}
PCREG(623050, fn623050);

// 0x62cc90, cdecl(a, id): id 0xf returns 0; 0x12 sets [a] = 0x62cce0 and returns 0x1d; else when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62cc90(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x12) { a[0] = 0x62cce0; return 0x1d; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62cc90, fn62cc90);
