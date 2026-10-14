// batch5839.cpp - residue 9, 0x5db910 (ZDamageBox2::CopyData(ZEventBase*), gc name map), thiscall, one stack argument (src), ret 4.
// s48 = src+0x48: if s48: v = 0; s48->vt[+0x4c](&v); r = s48->vt[+0x5c](&v); if v: do { this+0x48->vt[+4](r); r = s48->vt[+0x5c](&v); } while (v).
// Then copies: +0x4c, +0x50 (dwords), +0x54 (byte), +0x55 (word), +0x87, +0x8b, +0x8f, +0x93, +0x97, +0x9b (dwords) from src. Then x = this+0x4c:
// x == 0: this+0x63 = 1; x == 1: this+0x63 = 0.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);

// 0x5db910, thiscall, one stack argument (ZDamageBox2::CopyData)
static void THISCALL unnamed5db910(u8 *self, u8 *src) {
  u8 *s48 = *(u8 **)(src + 0x48);
  if (s48 != 0) {
    u32 v = 0;
    ((SlotA)VT(s48)[0x4c / 4])(s48, (u32)(unsigned long)&v);
    u32 r = ((SlotA)VT(s48)[0x5c / 4])(s48, (u32)(unsigned long)&v);
    if (v != 0) {
      do {
        u8 *d = *(u8 **)(self + 0x48);
        ((SlotA)VT(d)[0x4 / 4])(d, r);
        s48 = *(u8 **)(src + 0x48);
        r = ((SlotA)VT(s48)[0x5c / 4])(s48, (u32)(unsigned long)&v);
      } while (v != 0);
    }
  }
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x50) = *(u32 *)(src + 0x50);
  *(u8 *)(self + 0x54) = *(u8 *)(src + 0x54);
  *(u16 *)(self + 0x55) = *(u16 *)(src + 0x55);
  *(u32 *)(self + 0x87) = *(u32 *)(src + 0x87);
  *(u32 *)(self + 0x8b) = *(u32 *)(src + 0x8b);
  *(u32 *)(self + 0x8f) = *(u32 *)(src + 0x8f);
  *(u32 *)(self + 0x93) = *(u32 *)(src + 0x93);
  *(u32 *)(self + 0x97) = *(u32 *)(src + 0x97);
  *(u32 *)(self + 0x9b) = *(u32 *)(src + 0x9b);
  u32 x = *(u32 *)(self + 0x4c);
  if (x == 0) *(u32 *)(self + 0x63) = 1;
  else if (x == 1) *(u32 *)(self + 0x63) = 0;
}
PCREG(5db910, unnamed5db910);
