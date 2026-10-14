// batch38065.cpp - cascade s8 batch 38065: 0x6031e0 (serialize a node map into a stream, then md5 the tail of the stream).
#include "ff.h"

extern "C" void THISCALL ext_6061f0(u8 *ctx);              // md5 init
extern "C" void THISCALL ext_606940(u8 *ctx, u32 p, u32 n); // md5 update, ret 8 (the original passes the caller's EDI as 2nd arg)
extern "C" void THISCALL ext_606120(u8 *ctx, u8 *out);     // md5 final, ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

// in-order successor in the (packed) tree: +1 parent, +5 left, +9 right; absent children are null, the header's parent/left/right = root/leftmost/rightmost
static u8 *next_node(u8 *esi) {
  u8 *eax = (u8 *)UN32(esi, 9);
  if (eax) {
    esi = eax;
    while ((eax = (u8 *)UN32(esi, 5)) != 0) esi = eax;
    return esi;
  }
  eax = (u8 *)UN32(esi, 1);
  if (esi == (u8 *)UN32(eax, 9)) {
    do {
      esi = eax;
      eax = (u8 *)UN32(eax, 1);
    } while (esi == (u8 *)UN32(eax, 9));
  }
  if ((u8 *)UN32(esi, 9) != eax) esi = eax;
  return esi;
}

// self: +1 header node, +5 dword, +0xa md5 output buffer. ediIn is the caller's EDI, which the original passes (through a stray stack slot) as the md5 length.
extern "C" u32 ff_inner_6031e0(u8 *self, u8 *s, u32 ediIn) {
  SLOT(s, 8, v1_t)(s, 0x10);
  SLOT(s, 0x2c, v1_t)(s, UN32(self, 5));
  u8 *head = (u8 *)UN32(self, 1);
  for (u8 *n = (u8 *)UN32(head, 5); n != head; n = next_node(n)) {
    u8 *v = (u8 *)UN32(n, 0x19);
    SLOT(s, 0x40, v1_t)(s, (u32)(v + 4));
    SLOT(s, 0x30, v1_t)(s, UN32(v, 0x10));
    SLOT(s, 0x30, v1_t)(s, UN32(v, 0x14));
    SLOT(s, 0x2c, v1_t)(s, UN32(v, 0x18));
    SLOT(s, 0x2c, v1_t)(s, UN32(v, 0x20));
    SLOT(s, 0x30, v1_t)(s, UN32(v, 0x24) != 0);
    u8 *sub = (u8 *)UN32(v, 0x24);
    if (sub) {
      SLOT(s, 0x40, v1_t)(s, (u32)sub);
      SLOT(s, 0x40, v1_t)(s, (u32)(sub + 0xc));
      SLOT(s, 0x40, v1_t)(s, (u32)(sub + 0x18));
      SLOT(s, 0x40, v1_t)(s, (u32)(sub + 0x24));
    }
  }
  head = (u8 *)UN32(self, 1);
  for (u8 *n = (u8 *)UN32(head, 5); n != head; n = next_node(n)) {
    u8 *v = (u8 *)UN32(n, 0x19);
    u8 *o = (u8 *)UN32(v, 0x1c);
    if (o) {
      SLOT(s, 0x2c, v1_t)(s, 1);
      SLOT(o, 0xc, v2_t)(o, UN32(v, 4), (u32)s);
    } else {
      SLOT(s, 0x2c, v1_t)(s, 0);
    }
  }
  u8 ctx[0x58];
  ext_6061f0(ctx);
  u32 sz = SLOT(s, 0x1c, v0_t)(s);
  u32 p = SLOT(s, 0x10, v1_t)(s, sz - 0x10);
  ext_606940(ctx, p + 0x10, ediIn);
  u8 *out = self + 0xa;
  ext_606120(ctx, out);
  u32 keep = SLOT(s, 0x1c, v0_t)(s);
  SLOT(s, 0x74, v1_t)(s, 0);
  SLOT(s, 0x48, v2_t)(s, (u32)out, 0x10);
  return SLOT(s, 0x74, v1_t)(s, keep);
}
// The original calls md5 update (ret 8) with only one pushed argument, so the call eats the saved-EDI slot and its epilogue pops are shifted by one: it returns with EBX = this,
// ESI = entry EBX, EDI = entry ESI. The wrapper passes the entry EDI as the length and reproduces those registers.
__attribute__((naked)) static u32 THISCALL fn6031e0(u8 *self, u8 *stream) {
  asm volatile(
      "push %ebx\n"
      "push %ecx\n"
      "push %esi\n"
      "push %edi\n"
      "push %edi\n"
      "pushl 24(%esp)\n"
      "push %ecx\n"
      "call ff_inner_6031e0\n"
      "add $12, %esp\n"
      "add $4, %esp\n"
      "pop %edi\n"
      "pop %ebx\n"
      "pop %esi\n"
      "ret $4\n");
}
PCREG(6031e0, fn6031e0);
