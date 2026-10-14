// batch37089.cpp - cascade s6 batch 37089: 0x648a40.
#include "ff.h"

extern "C" void THISCALL ext_63ef90(u8 *self, u8 *n);      // ret 4
extern "C" void THISCALL ext_63da80(u8 *self, u8 *n);      // ret 4
extern "C" u8 *THISCALL ext_63f220(u8 *self, u8 *elem);    // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define P(o) (*(u8 **)(self + (o)))

// 0x648a40, thiscall(src) ret 4: src's slot 0x2b0 fills a stack list of {first, last} element ranges (0x70-byte elements). Every element without flags 0xc00 is mapped through
// the node table at +0x10071 (index = word at +0x5a & 0xfff): a missing node is created through the pool at +0x1016d (slot 8; released with slot 0xc when 0x63f220 cannot
// give it a target), an existing unflagged node first has its target settled (0x63ef90) and is queued (0x63da80, then slot 8 of the queue object at +0x10185 which also bumps the
// target's counter byte at +0x3c); finally the node's stamp (+0x10) takes the engine word at +0x3c and unflagged nodes are queued the same way.
static void THISCALL fn648a40(u8 *self, u8 *src) {
  u32 recs[0x200];
  u32 cookie;
  u32 tmp;
  u8 *end = (u8 *)vcall<u32>(src, 0x2b0, (u32)recs, (u32)&cookie);
  s32 n = (s32)((u8 *)end - (u8 *)recs) >> 3;
  u32 *rec = recs;
  for (; n != 0; n--, rec += 2) {
    u8 *p = (u8 *)rec[0];
    u8 *last = (u8 *)(rec[1] + 0x70);
    for (; p != last; p += 0x70) {
      if (D32(p, 0x3c) & 0xc00) continue;
      u32 idx = *(u16 *)(p + 0x5a) & 0xfff;
      u8 *esi = ((u8 **)P(0x10071))[idx];
      if (!esi) {
        esi = (u8 *)vcall<u32>(P(0x1016d), 0x8);
        if (!esi) continue;
        u8 *r = ext_63f220(P(0x1005d), p);
        if (!r) {
          vcall<void>(P(0x1016d), 0xc, (u32)esi);
          continue;
        }
        D32(esi, 8) = (u32)r;
        ((u8 **)P(0x10071))[*(u16 *)(p + 0x5a) & 0xfff] = esi;
      } else if (!(esi[5] & 1)) {
        u8 *m = *(u8 **)(esi + 8);
        if (!(m[5] & 1)) ext_63ef90(P(0x1005d), m);
        ext_63da80(P(0x1005d), esi);
        tmp = (u32)esi;
        vcall<void>(self + 0x10185, 8, (u32)&tmp);
        (*(u8 **)(((u8 *)tmp) + 8))[0x3c]++;
      }
      u8 flag = esi[5] & 1;
      D32(esi, 0x10) = D32(*(u8 **)0x70039c, 0x3c);
      if (flag) continue;
      ext_63da80(P(0x1005d), esi);
      tmp = (u32)esi;
      vcall<void>(self + 0x10185, 8, (u32)&tmp);
      (*(u8 **)(((u8 *)tmp) + 8))[0x3c]++;
    }
  }
}
PCREG(648a40, fn648a40);
