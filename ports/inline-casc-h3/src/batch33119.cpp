// batch33119.cpp - h3 (Sonnet) batch 33119: tier H float/SSE functions
#include "ff.h"

static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u8 THISCALL ext_4fa630(u8 *self, u8 *s);                      // ret 4, bool
extern "C" void THISCALL ext_516360(u8 *self, u32 *p);                   // ret 4

// 0x4f8240: thiscall(s) ret 4, bool: !0x4fa630(this, s) -> false; s->slot 0x44([0x8f],[0x93],[0x97]); slot 0x4c([0x9b],[0x9f],[0xa3]); slot 0x44([0xa7]); slot 0x3c([0xab],[0xaf]); slot 0x6c(this+0xb3); slot 0x4c([0xcf]); true
static u8 THISCALL fn4f8240(u8 *self, u8 *s) {
  if (!ext_4fa630(self, s)) return 0;
  vcall<u32>(s, 0x44, R32(self + 0x8f));
  vcall<u32>(s, 0x44, R32(self + 0x93));
  vcall<u32>(s, 0x44, R32(self + 0x97));
  vcall<u32>(s, 0x4c, R32(self + 0x9b));
  vcall<u32>(s, 0x4c, R32(self + 0x9f));
  vcall<u32>(s, 0x4c, R32(self + 0xa3));
  vcall<u32>(s, 0x44, R32(self + 0xa7));
  vcall<u32>(s, 0x3c, R32(self + 0xab));
  vcall<u32>(s, 0x3c, R32(self + 0xaf));
  vcall<u32>(s, 0x6c, (u32)(self + 0xb3));
  vcall<u32>(s, 0x4c, R32(self + 0xcf));
  return 1;
}
PCREG(4f8240, fn4f8240);

// 0x527f80: thiscall no args: for i < [0x8d]: l = 3 dwords at this+0xe99+0x133*i-8; [this+0x89]->slot 0x84(l); 0x516360(this+0x95+0xde*i, l); same for i < [0x91] with this+0x1831+0x133*i and this+0x785+0xde*i
static void THISCALL fn527f80(u8 *self) {
  s32 i = 0;
  if (*(s32 *)(self + 0x8d) > 0) {
    u8 *ent = self + 0x95;
    u8 *src = self + 0xe99;
    do {
      u32 l[3];
      l[0] = R32(src - 8);
      l[1] = R32(src - 4);
      l[2] = R32(src);
      vcall<u32>(*(u8 **)(self + 0x89), 0x84, (u32)l);
      ext_516360(ent, l);
      ent += 0xde;
      src += 0x133;
      i++;
    } while (i < *(s32 *)(self + 0x8d));
  }
  i = 0;
  if (*(s32 *)(self + 0x91) > 0) {
    u8 *ent = self + 0x785;
    u8 *src = self + 0x1831;
    do {
      u32 l[3];
      l[0] = R32(src - 8);
      l[1] = R32(src - 4);
      l[2] = R32(src);
      vcall<u32>(*(u8 **)(self + 0x89), 0x84, (u32)l);
      ext_516360(ent, l);
      ent += 0xde;
      src += 0x133;
      i++;
    } while (i < *(s32 *)(self + 0x91));
  }
}
PCREG(527f80, fn527f80);
