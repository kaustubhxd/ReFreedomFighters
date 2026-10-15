// batch67532.cpp - cascade s6 batch 67532: 0x461790.
#include "ff.h"

extern "C" u32 FASTCALL ext_4dc110(u8 *e);              // name pointer of e's +0x54 record (default 0x67c8e8), plain ret
extern "C" u8 *FASTCALL ext_4db520(u8 *e);              // next record in the table, plain ret
extern "C" void FASTCALL ext_4690b0(u8 *e);             // empty

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef u32 (__cdecl *cmp67532_t)(u32, u32);
typedef void (__cdecl *log67532_t)(u8 *, ...);

// 0x461790, thiscall(rec) ret 4, returns bool: when rec exists and its type word ([rec+0xc]+0x23) has bit 0x100000 it scans the chain from rec[0x54] (next via 0x4db520) skipping records whose type
// has that bit, comparing each record's name (0x4dc110) with the string at 0x6858e0 through the function pointer at 0x676414; on the first equal one it calls slot 0x2d0 with the record's
// +0x54, stores the name of the +0x50 holder in this[0x58], calls 0x4690b0 on this[8] and logs it (slot 0x2c of the logger's slot-0x20 object). Returns 1 in every case but a missing /
// untyped rec, where it logs both records' names (rec[4], this[4], this slot 0x20's [4], default 0x67c8e8) and returns 0.
static u32 THISCALL fn461790(u8 *self, u8 *rec) {
  if (rec && (D32(*(u8 **)(rec + 0xc), 0x23) & 0x100000)) {
    u8 *esi = *(u8 **)(rec + 0x54);
    cmp67532_t cmp = *(cmp67532_t *)0x676414;
    while (esi) {
      u8 *sub = *(u8 **)(esi + 0x54);
      u32 t = sub ? D32(*(u8 **)(sub + 0xc), 0x23) : 0x200002u;
      if (t & 0x100000) break;
      if (cmp(ext_4dc110(esi), 0x6858e0)) {
        esi = ext_4db520(esi);
        continue;
      }
      vcall<void>(self, 0x2d0, (u32)*(u8 **)(esi + 0x54));
      D32(self, 0x58) = ext_4dc110(*(u8 **)(esi + 0x50));
      ext_4690b0(*(u8 **)(self + 8));
      u8 *lg = *(u8 **)0x700390;
      u8 *x = vcall<u8 *>(lg, 0x20, 0x685834u, 0x24cu);
      (*(log67532_t *)(*(u8 **)x + 0x2c))(x, 0x6858e8u, D32(self, 0x58));
      break;
    }
    return 1;
  }
  u8 *lg = *(u8 **)0x700390;
  u8 *x = vcall<u8 *>(lg, 0x20, 0x685834u, 0x251u);
  u32 r4 = *(volatile u32 *)(rec + 4);
  u32 a = r4 ? r4 : 0x67c8e8u;
  u8 *r = vcall<u8 *>(self, 0x20);
  u32 b = D32(r, 4) ? D32(r, 4) : 0x67c8e8u;
  u32 c = D32(self, 4) ? D32(self, 4) : 0x67c8e8u;
  (*(log67532_t *)(*(u8 **)x + 0x2c))(x, 0x6858b0u, c, b, a);
  return 0;
}
PCREG(461790, fn461790);
