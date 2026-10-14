// batch38076.cpp - cascade s8 batch 38076: 0x597fc0 (mark an option bit as seen in a persistent flag text and show its name).
#include "ff.h"

extern "C" u32 THISCALL ext_5adeb0(u8 *ctx, char *buf);               // ret 4 (tail jumps to 0x5b0b70)
extern "C" void THISCALL ext_5ae930(u8 *ctx, char *buf, u32 mask);    // ret 8
extern "C" void THISCALL ext_5a8510(u8 *obj, u32 text, u32 flag);     // ret 8
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);
typedef u32 (*fmt4_t)(void *, char *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

// key -> name string address, in the original's table order (a sentinel entry 0x28 ends the search; key 0x28 itself is never found)
static const u32 TAB[40][2] = {
  {0, 0x6ad054}, {1, 0x6ad388}, {2, 0x6aaa08}, {3, 0x6ad390}, {4, 0x6ad398}, {5, 0x6ad3a0}, {6, 0x6ad3a4}, {9, 0x6ad3ac}, {8, 0x6ad3bc}, {0xa, 0x6ad3cc},
  {0xb, 0x6ad3dc}, {0xc, 0x6ad3e8}, {0xd, 0x6ad3f8}, {0xe, 0x6ad408}, {0xf, 0x6ad418}, {0x10, 0x6ad080}, {0x11, 0x6ad428}, {0x12, 0x6ad434}, {0x13, 0x6ad450}, {0x14, 0x6ad470},
  {7, 0x6aa9e8}, {0x15, 0x6ad480}, {0x16, 0x6ad490}, {0x17, 0x6ad49c}, {0x18, 0x6ad4ac}, {0x19, 0x6ad4bc}, {0x1a, 0x6ad4d0}, {0x1b, 0x6ad4e4}, {0x1c, 0x6ad4f4}, {0x1d, 0x6ad504},
  {0x1e, 0x6ad514}, {0x1f, 0x6ad528}, {0x20, 0x6ad53c}, {0x21, 0x6a815c}, {0x22, 0x6ad548}, {0x23, 0x6ad550}, {0x24, 0x6ad55c}, {0x25, 0x6ad564}, {0x26, 0x6ad570}, {0x27, 0x6ad584}};

// 0x597fc0, thiscall(a, b) ret 8, void. this+0x44 = object (slot 0x12c), this+0x1d0f (unaligned) = notice object.
static void THISCALL fn597fc0(u8 *self, int a, u32 b) {
  u32 l170 = 0, l174 = 0;
  u8 *tbl = *(u8 **)(SYS + 0x9b);
  u8 *Z = (u8 *)SLOT(tbl, 0x138, v0_t)(tbl);
  l174 = 0;
  SLOT(Z, 0x88, v2_t)(Z, 0x6a5c48, (u32)&l174);
  u8 *o44 = (u8 *)UN32(self, 0x44);
  u8 *vt = *(u8 **)o44;
  tbl = *(u8 **)(SYS + 0x9b);
  u32 r = SLOT(tbl, 0x114, v5_t)(tbl, 0x6ad354, 0, 0x6ad320, 0x12, (u32)&l170);
  o44 = (u8 *)UN32(self, 0x44);
  ((v2_t) * (u8 **)(vt + 0x12c))(o44, l174, r & 0xffff);
  if (UN32(self, 0x1d0f) == 0) return;
  u8 *F = (u8 *)SLOT(SYS, 0x190, v0_t)(SYS);
  char buf[0x20];
  ((fmt4_t)SLOT(F, 0x198, u8 *))(F, buf, 0x6ad370, (u32)(a / 8));
  u32 bit = 1u << (((u32)(a % 8)) & 31);
  u32 mask = ext_5adeb0((u8 *)l170, buf);
  if ((u8)b != 0 && (bit & mask)) return;
  ext_5ae930((u8 *)l170, buf, mask | bit);
  for (int i = 0; i < 40; i++) {
    if ((int)TAB[i][0] == a) {
      u8 *t2 = *(u8 **)(*(u8 **)(SYS + 0x9b) + 0xae4);
      u32 text = SLOT(t2, 0, v2_t)(t2, 0x6ad37c, TAB[i][1]);
      ext_5a8510((u8 *)UN32(self, 0x1d0f), text, b);
      return;
    }
  }
}
PCREG(597fc0, fn597fc0);
