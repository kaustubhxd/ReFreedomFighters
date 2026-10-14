// batch38072.cpp - cascade s8 batch 38072: 0x56b460 (refresh the info panel texts of an entry: format text lines through the formatter object, parse the entry record into a stack context).
#include "ff.h"

extern "C" void THISCALL ext_5ad790(u8 *ctx);              // record parser context init
extern "C" void THISCALL ext_5ae450(u8 *ctx, u32 p);       // ret 4
extern "C" void THISCALL ext_5ae900(u8 *ctx, u32 p);       // ret 4
extern "C" u32 THISCALL ext_5adeb0(u8 *ctx, u32 p);        // ret 4 (tail jumps to 0x5b0b70)
extern "C" void THISCALL ext_563710(u8 *self, u32 a, u32 b);  // ret 8
extern "C" void THISCALL ext_5618b0(u8 *self, u32 a, u32 b);  // ret 8
extern "C" void THISCALL ext_56c780(u8 *self, u32 a);         // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32 (*fmt5_t)(void *, char *, u32, u32, u32);
typedef u32 (*fmt4_t)(void *, char *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static u8 *tb2() { return *(u8 **)(*(u8 **)(SYS + 0x9b) + 0xae4); }
static u32 text(u32 a, u32 b) { u8 *t = tb2(); return SLOT(t, 0, v2_t)(t, a, b); }
static u8 *formatter() { return (u8 *)SLOT(SYS, 0x190, v0_t)(SYS); }

// 0x56b460, thiscall(entry) void. this+0xcea = record table, +0xce6 / +0xce2 numbers, +0xcc2 / +0xcbe / +0xcb6 / +0xcba = label objects (slot 0x284(text)), +0xcae / +0xcd2 / +0xcce = other settings.
static void THISCALL fn56b460(u8 *self, u32 a) {
  if (UN32(self, 0xcea) == 0) return;
  if (UN32(self, 0xce6) == 0) return;
  char buf18c[0x400], buf58c[0x400], buf8c[0x80];
  u8 ctx[0x1570];
  u8 *f = formatter();
  u32 n = UN32(self, 0xce2) + 1;
  u32 t = text(0x6a67e8, 0x6a7afc);
  ((fmt5_t)SLOT(f, 0x198, u8 *))(f, buf18c, t, n, UN32(self, 0xce6));
  u8 *lab = (u8 *)UN32(self, 0xcc2);
  SLOT(lab, 0x284, v1_t)(lab, (u32)buf18c);
  ext_5ad790(ctx);
  u32 base = UN32(self, 0xcea);
  ext_5ae450(ctx, (a << 10) + 0x2100 + base);
  ext_5ae900(ctx, (a << 7) + base);
  UN32(ctx, 0x86) = *(u32 *)(base + a * 4 + 0x2000);
  u32 kind = UN32(ctx, 0x3ba);
  u32 name;
  switch (kind) {
    case 1: name = 0x6a7b84; break;
    case 2: name = 0x6a7b7c; break;
    case 3: name = 0x6a7b74; break;
    default: name = 0x6a7b8c; break;
  }
  u8 *l2 = (u8 *)UN32(self, 0xcbe);
  u32 tt = text(0x6a67e8, name);
  SLOT(l2, 0x284, v1_t)(l2, tt);
  u8 *s1 = ctx + 0x35a + 8;
  ext_563710(self, UN32(self, 0xcae), (u32)s1);
  ext_5618b0(self, UN32(self, 0xcae), UN32(self, 0xcd2));
  if (UN32(self, 0xcce) != 0) {
    if (ext_5adeb0(ctx, 0x6a7b98)) {
      ext_56c780(self, 1);
      return;
    }
  }
  ext_56c780(self, 0);
  u8 *s2 = ctx + 0x35a + 0x48;
  u32 arg;
  if (s2) {
    char tmp[0x100];
    char *d = tmp;
    const char *sp = (const char *)s2;
    char ch;
    do {
      ch = *sp++;
      *d++ = ch;
    } while (ch);
    tmp[3] = 0;   // the original stores the NUL byte at [ebp-9] after the copy (its 8-byte buffer is only meant for short strings)
    u8 *f2 = formatter();
    u32 x1 = text(0x6a7ba8, (u32)tmp);
    u32 x2 = text(0x6a7bc8, (u32)tmp);
    ((fmt5_t)SLOT(f2, 0x198, u8 *))(f2, buf58c, 0x6a7be8, x2, x1);
    arg = (u32)buf58c;
  } else {
    arg = 0x679e6c;
  }
  u8 *l3 = (u8 *)UN32(self, 0xcb6);
  SLOT(l3, 0x284, v1_t)(l3, arg);
  u8 *f3 = formatter();
  ((fmt4_t)SLOT(f3, 0x198, u8 *))(f3, buf8c, 0x69d384, UN32(ctx, 0x3c8));
  u8 *l4 = (u8 *)UN32(self, 0xcba);
  SLOT(l4, 0x284, v1_t)(l4, (u32)buf8c);
}
PCREG(56b460, fn56b460);
