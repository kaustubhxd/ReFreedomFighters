// batch37115.cpp - cascade s6 batch 37089: 0x648890.
#include "ff.h"

extern "C" void THISCALL ext_63ef90(u8 *self, u8 *n);      // ret 4
extern "C" void THISCALL ext_63da80(u8 *self, u8 *n);      // ret 4
extern "C" u8 *THISCALL ext_63f220(u8 *self, u8 *elem);    // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define P(o) (*(u8 **)(self + (o)))

// 0x648890, thiscall(src) ret 4, returns the number of elements processed: sibling of 0x648a40 whose element list is an array of element pointers (src+8 -> +0x3c object, slot
// 0x380 fills a stack array and returns its end). Elements flagged 0xc00 at +0x3c are skipped (not counted); every other element is mapped to a node through the table at +0x10071
// (index = word at +0x5a & 0xfff), created from the pool at +0x1016d (slot 8, released with slot 0xc when 0x63f220 finds no target), settled (0x63ef90), queued (0x63da80 and
// slot 8 of the queue object at +0x10185, bumping the target's counter byte at +0x3c) and stamped with the engine word at +0x3c, and counted.
static void processOne(u8 *self, u8 *p) {
  u32 tmp;
  u32 idx = *(u16 *)(p + 0x5a) & 0xfff;
  u8 *esi = ((u8 **)P(0x10071))[idx];
  if (!esi) {
    esi = (u8 *)vcall<u32>(P(0x1016d), 0x8);
    if (!esi) return;
    u8 *r = ext_63f220(P(0x1005d), p);
    if (!r) {
      vcall<void>(P(0x1016d), 0xc, (u32)esi);
      return;
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
  if (flag) return;
  ext_63da80(P(0x1005d), esi);
  tmp = (u32)esi;
  vcall<void>(self + 0x10185, 8, (u32)&tmp);
  (*(u8 **)(((u8 *)tmp) + 8))[0x3c]++;
}

static u32 THISCALL fn648890(u8 *self, u8 *a) {
  u32 list[0x200];
  u32 cookie;
  u8 *obj = *(u8 **)(*(u8 **)(a + 8) + 0x3c);
  u8 *end = (u8 *)vcall<u32>(obj, 0x380, (u32)list, (u32)&cookie);
  s32 n = (s32)((u8 *)end - (u8 *)list) >> 2;
  u32 count = 0;
  for (s32 i = 0; i < n; i++) {
    u8 *p = (u8 *)list[i];
    if (D32(p, 0x3c) & 0xc00) continue;
    processOne(self, p);
    count++;
  }
  return count;
}
PCREG(648890, fn648890);
