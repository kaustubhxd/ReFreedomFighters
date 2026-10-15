// batch67571.cpp - cascade s6 batch 67571: 0x6490b0.
#include "ff.h"

extern "C" void THISCALL ext_63e850(u8 *mgr, u8 *obj);                          // ret 4
extern "C" void THISCALL ext_64c090(u8 *self, u8 *s);                           // ret 4
extern "C" u8 *THISCALL ext_64d030(u8 *self, u8 *owner, u8 *rec, u32 a, u32 b); // ret 0x10

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x6490b0, thiscall(bits, objs, n, owner) ret 0x10, returns bits + (((2n + 0x7f) >> 5) & ~3) * 4: attaches n records to the owner. `bits` holds two bits per record (16 per dword); records with bit 1
// set are skipped. For each other record the slot table (this[0x10071], key = word rec[0x5a] & 0xfff) is consulted: a missing slot is created through 0x64d030(owner, rec, 0, 0); an existing slot whose
// flag (+5 & 1) is clear is registered (0x63e850 on its object unless flagged, 0x64c090) and every existing slot is stamped with sys[0x3c] (+0x10) and linked into the owner's list (+0x18).
static u8 *THISCALL fn6490b0(u8 *self, u32 *bits, u8 **objs, int n, u8 *owner) {
  u8 *ret = (u8 *)bits + ((((2 * n + 0x7f) >> 5) & 0xfffffffc) * 4);
  u32 stamp = D32(*(u8 **)0x70039c, 0x3c);
  if (n <= 0) return ret;
  do {
    u32 w = *bits++;
    int cnt = n < 16 ? n : 16;
    n -= 16;
    for (; cnt; cnt--, objs++, w >>= 2) {
      if (w & 2) continue;
      u8 *o = *objs;
      u8 *s = *(u8 **)(*(u8 **)(self + 0x10071) + (*(u16 *)(o + 0x5a) & 0xfff) * 4);
      if (!s) {
        ext_64d030(self, owner, o, 0, 0);
      } else {
        if (!(s[5] & 1)) {
          u8 *e = *(u8 **)(s + 8);
          if (!(e[5] & 1)) ext_63e850(*(u8 **)(self + 0x1005d), e);
          ext_64c090(self, s);
        }
        D32(s, 0x10) = stamp;
        D32(s, 0x18) = D32(owner, 0x18);
        D32(owner, 0x18) = (u32)s;
      }
    }
  } while (n > 0);
  return ret;
}
PCREG(6490b0, fn6490b0);
