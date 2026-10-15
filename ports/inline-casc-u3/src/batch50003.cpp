// batch50003.cpp - cascade u3, tier H, batch 50003: 0x4427c0 (query hits in a box around two points and let each hit react).
#include "ff.h"

extern "C" void THISCALL ext_4e3180(u8 *st);                                       // st[0] = 1.0f
extern "C" void THISCALL ext_4e4520(u8 *query, u8 *st, u8 *v1, u8 *box);           // ret 0xc
extern "C" void FASTCALL ext_43e8e0(u8 *out, u8 *a, u8 *b);                        // ret 4: out = a + b (vec3)
extern "C" u8 FASTCALL ext_442420(u32 a, u32 hit, u32 c, u32 d, u32 f, u32 g, u32 e);   // ret 0x14
extern "C" void FASTCALL ext_633654(u32 cookie);                                   // /GS check

// 0x4427c0, thiscall(a, b, c, d, e, f, g) ret 0x1c, /GS, returns al: [[this+8]+0x3c] bit 10 set -> false. bl = 0; q = slot 0x314() of this; q != 0:
// v1 = vec3 *c, v2 = vec3 *d, slot 0x8c(&v1), slot 0x90(&v2), sum = v1 + v2 (ext_43e8e0); st (0x6c bytes: st[0] = 1.0f via ext_4e3180, +4 = callback 0x4e32e0, +0x5c = result buffer
// (0x800 dwords), +0x60 = &sum, +0x64 = count, +0x68 = f); ext_4e4520(q, &st, &v1, &sum) fills buffer and count; bl |= ext_442420(a, buf[i], c, d, f, g, e) for each of the count entries.
// Then the unaligned pointer this[0x7b]: when set and its word +2 is nonzero, for i from 0 (until the re-read word equals i) bl |= (*(obj at p + 0x404 + 4*i)) slot 0x2e8(a, b, c, d, e, f, g).
static u8 THISCALL fn4427c0(u8 *self, u32 a, u32 b, u8 *c, u8 *d, u32 e, u32 f, u32 g) {
  if ((*(u32 *)(*(u8 **)(self + 8) + 0x3c) >> 10) & 1) {
    ext_633654(0);
    return 0;
  }
  u8 bl = 0;
  u8 *q = vcall<u8 *>(self, 0x314);
  if (q) {
    u32 v1[3] = {*(u32 *)c, *(u32 *)(c + 4), *(u32 *)(c + 8)};
    u32 v2[3] = {*(u32 *)d, *(u32 *)(d + 4), *(u32 *)(d + 8)};
    vcall<void>(self, 0x8c, (u32)v1);
    vcall<void>(self, 0x90, (u32)v2);
    u32 sum[3];
    ext_43e8e0((u8 *)sum, (u8 *)v1, (u8 *)v2);
    u32 st[27];
    u32 buf[0x800];
    ext_4e3180((u8 *)st);
    st[1] = 0x4e32e0;
    st[0x17] = (u32)buf;
    st[0x18] = (u32)sum;
    st[0x19] = 0;
    st[0x1a] = f;
    ext_4e4520(q, (u8 *)st, (u8 *)v1, (u8 *)sum);
    if (st[0x19] != 0) {
      u32 i = 0;
      do {
        bl |= ext_442420(a, buf[i], (u32)c, (u32)d, f, g, e);
        i++;
      } while (i != st[0x19]);
    }
  }
  if (*(u32 *)(self + 0x7b)) {
    if (*(u16 *)(*(u8 **)(self + 0x7b) + 2) != 0) {
      u32 i = 0;
      u32 off = 0x404;
      do {
        u8 *o = *(u8 **)(*(u8 **)(self + 0x7b) + off);
        bl |= vcall<u8>(o, 0x2e8, a, b, (u32)c, (u32)d, e, f, g);
        off += 4;
        i++;
      } while (i != *(u16 *)(*(u8 **)(self + 0x7b) + 2));
    }
  }
  ext_633654(0);
  return bl;
}
PCREG(4427c0, fn4427c0);
