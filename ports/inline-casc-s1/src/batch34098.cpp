// batch34098.cpp - escalation batch 34098: 0x53b7f0 (record copy), 0x622fb0 (Latin-1 to UTF-8), 0x445750 / 0x533ba0 (asm), 0x532770, 0x600420, 0x4c3c90.
#include "ff.h"

extern "C" void thunk445750(void);
extern "C" void thunk533ba0(void);
// 0x445750: copies 18 dwords (offsets 0x171 .. 0x74) and byte 0x170 from the source argument to this, keeps the argument slot, tail jumps to 0x45d5b0 with ecx = this.
// 0x533ba0: calls 0x5390b0 (ecx passed through), sets al = 1.
asm(
    ".text\n"
    ".globl thunk445750\n"
    "thunk445750:\n"
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 8(%ebp), %edx\n"
    "  mov 0x171(%edx), %eax\n  mov %eax, 0x171(%ecx)\n"
    "  mov 0x175(%edx), %eax\n  mov %eax, 0x175(%ecx)\n"
    "  mov 0x179(%edx), %eax\n  mov %eax, 0x179(%ecx)\n"
    "  mov 0x17d(%edx), %eax\n  mov %eax, 0x17d(%ecx)\n"
    "  mov 0x181(%edx), %eax\n  mov %eax, 0x181(%ecx)\n"
    "  mov 0x5c(%edx), %eax\n  mov %eax, 0x5c(%ecx)\n"
    "  mov 0x60(%edx), %eax\n  mov %eax, 0x60(%ecx)\n"
    "  mov 0x6c(%edx), %eax\n  mov %eax, 0x6c(%ecx)\n"
    "  mov 0x30(%edx), %eax\n  mov %eax, 0x30(%ecx)\n"
    "  mov 0x34(%edx), %eax\n  mov %eax, 0x34(%ecx)\n"
    "  mov 0x38(%edx), %eax\n  mov %eax, 0x38(%ecx)\n"
    "  mov 0x1c(%edx), %eax\n  mov %eax, 0x1c(%ecx)\n"
    "  mov 0x4c(%edx), %eax\n  mov %eax, 0x4c(%ecx)\n"
    "  mov 0x48(%edx), %eax\n  mov %eax, 0x48(%ecx)\n"
    "  mov 0x64(%edx), %eax\n  mov %eax, 0x64(%ecx)\n"
    "  mov 0x68(%edx), %eax\n  mov %eax, 0x68(%ecx)\n"
    "  mov 0x70(%edx), %eax\n  mov %eax, 0x70(%ecx)\n"
    "  mov 0x74(%edx), %eax\n  mov %eax, 0x74(%ecx)\n"
    "  mov 0x170(%edx), %al\n  mov %al, 0x170(%ecx)\n"
    "  mov %edx, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp ext_45d5b0\n"
    ".globl thunk533ba0\n"
    "thunk533ba0:\n"
    "  call ext_5390b0\n"
    "  mov $1, %al\n"
    "  ret\n");
PCREG(445750, thunk445750);
PCREG(533ba0, thunk533ba0);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static u32 rd16(u8 *p) { return p[0] | p[1] << 8; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static void cp32(u8 *d, u8 *s) { wr32(d, rd32(s)); }

// 0x53b7f0, stdcall(dst, src) ret 8: count dword +0x25, byte +0, dword +1 are copied; then for i < [src+0x25] (signed, re-read each round): dwords at 0x29+12i, 0x2d+12i, 0x31+12i and the dword at 5+4i (all unaligned).
static void STDCALL fn53b7f0(u8 *dst, u8 *src) {
  cp32(dst + 0x25, src + 0x25);
  dst[0] = src[0];
  cp32(dst + 1, src + 1);
  s32 i = 0;
  if ((s32)rd32(src + 0x25) <= 0) return;
  do {
    u8 *d = dst + 0x29 + 12 * i, *s = src + 0x29 + 12 * i;
    cp32(d, s);
    cp32(d + 4, s + 4);
    cp32(d + 8, s + 8);
    cp32(dst + 5 + 4 * i, src + 5 + 4 * i);
    i++;
  } while (i < (s32)rd32(src + 0x25));
}
PCREG(53b7f0, fn53b7f0);

// 0x622fb0, cdecl(a, psrc, srcend, pdst, dstend): Latin-1 to UTF-8: bytes with the high bit become two bytes (0xc0 | b >> 6, 0x80 | b & 0x3f) and need two bytes of room; stops at the end of the source or when the output is full.
static void fn622fb0(u32 a, u8 **psrc, u8 *srcend, u8 **pdst, u8 *dstend) {
  (void)a;
  if (*psrc == srcend) return;
  for (;;) {
    u8 b = **psrc;
    if (b & 0x80) {
      u8 *d = *pdst;
      if ((s32)(dstend - d) < 2) return;
      *d = (b >> 6) | 0xc0;
      (*pdst)++;
      b = (b & 0x3f) | 0x80;
    } else {
      if (*pdst == dstend) return;
    }
    **pdst = b;
    (*pdst)++;
    (*psrc)++;
    if (*psrc == srcend) return;
  }
}
PCREG(622fb0, fn622fb0);

// 0x532770, thiscall(a, b, c) ret 0xc (a unused), bool: with m = [this+0x38]: c == m: word [[this+0x5a] + 12*b + 2] == 0xffff; c == m - 1: word [[this+0x54] + 0x16 * word[[this+0x5a] + 12*b + 4] + 2] == 0xffff;
// otherwise: word [[this+0x54] + 0x16 * word[[this+0x54] + 0x16 * b + 4] + 2] == 0xffff (b is a 16-bit index).
static bool THISCALL fn532770(u8 *self, u32 a, u32 b, u32 c) {
  (void)a;
  u32 m = *(u32 *)(self + 0x38);
  u32 x = (u16)b;
  if (c == m) {
    u8 *e = (u8 *)rd32(self + 0x5a);
    return rd16(e + x * 12 + 2) == 0xffff;
  }
  if (c == m - 1) {
    u8 *e = (u8 *)rd32(self + 0x5a);
    u32 idx = rd16(e + x * 12 + 4);
    u8 *base = *(u8 **)(self + 0x54);
    return rd16(base + idx * 0x16 + 2) == 0xffff;
  }
  u8 *base = *(u8 **)(self + 0x54);
  u32 idx = rd16(base + x * 0x16 + 4);
  return rd16(base + idx * 0x16 + 2) == 0xffff;
}
PCREG(532770, fn532770);

// 0x600420, thiscall(src) ret 4, returns the last pointer: copies src[1..4] to this[0..3]; with n = this[1] lays out pointers into the payload at src+0x1c: this[5] = base, this[6] = base + 4n, this[7] = base + 8n, this[8] = base + 4*(this[3] + 2n),
// this[9] = this[8] + 8n, this[10] = + 2n, this[11] = + 2n, this[12] = + 2n, this[13] = + src[6] (byte offsets added as is).
static u32 THISCALL fn600420(u32 *self, u32 *src) {
  self[0] = src[1];
  self[1] = src[2];
  self[2] = src[3];
  self[3] = src[4];
  u32 n = self[1];
  u32 sz = src[6];
  u32 base = (u32)(src + 7);
  self[5] = base;
  self[6] = base + n * 4;
  self[7] = base + n * 8;
  u32 p = base + (self[3] + n * 2) * 4;
  self[8] = p;
  p += n * 8;
  self[9] = p;
  p += n * 2;
  self[10] = p;
  p += n * 2;
  self[11] = p;
  p += n * 2;
  self[12] = p;
  p += sz;
  self[13] = p;
  return p;
}
PCREG(600420, fn600420);

// 0x4c3c90, thiscall(src) ret 4, returns [src+0xa2]: copies bytes 0x48, 0x49, 0x78, 0x79, the word 0x76 and the dwords 0x4a 0x4e 0x5e 0x62 0x72 0x7a 0x52 0x56 0x5a 0x66 0x6a 0x6e 0x7e 0x82 0x86 0xa2 (unaligned) from src to this.
static u32 THISCALL fn4c3c90(u8 *self, u8 *src) {
  self[0x48] = src[0x48];
  self[0x49] = src[0x49];
  static const u8 offs[] = {0x4a, 0x4e, 0x5e, 0x62, 0x72};
  for (unsigned i = 0; i < sizeof offs; i++) cp32(self + offs[i], src + offs[i]);
  self[0x76] = src[0x76]; self[0x77] = src[0x77];
  self[0x78] = src[0x78];
  self[0x79] = src[0x79];
  static const u8 offs2[] = {0x7a, 0x52, 0x56, 0x5a, 0x66, 0x6a, 0x6e, 0x7e, 0x82, 0x86};
  for (unsigned i = 0; i < sizeof offs2; i++) cp32(self + offs2[i], src + offs2[i]);
  cp32(self + 0xa2, src + 0xa2);
  return rd32(src + 0xa2);
}
PCREG(4c3c90, fn4c3c90);
