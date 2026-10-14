// batch31063.cpp - constructor, table lookup, bit tests, message handlers, pool alloc, copies.
#include "ff.h"

// 0x6362d0 thiscall constructor: magic 'NPAL' at +4, vtable 0x6c1fec, rest zero; returns this.
THISCALL u8 *fn6362d0(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x50414c4e;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)self = 0x6c1fec;
  *(u32 *)(self + 0x2d) = 0;
  self[0x31] = 0;
  return self;
}
PCREG(6362d0, fn6362d0);

// 0x624490 cdecl (arg0 unused, arg1 = pointer to two bytes): two-level table bit lookup.
extern "C" u32 fn624490(u32, u8 *p) {
  u32 b0 = p[0], b1 = p[1];
  u32 t = *(u8 *)(0x6bfd20 + ((b0 >> 2) & 7));
  u32 idx = ((b1 >> 5) & 1) + ((b0 & 3) + t * 4) * 2;
  return *(u32 *)(0x6bf720 + idx * 4) & (1u << (b1 & 0x1f));
}
PCREG(624490, fn624490);

// 0x532730 stdcall ret 4, bool: true unless bit 15 is set or (bit 14 set and (a & 0xfff) == 2).
STDCALL u8 fn532730(u32 a) {
  u8 bit15 = (a >> 15) & 1;
  u8 two = ((a & 0x4000) && (a & 0xfff) == 2) ? 1 : 0;
  return (!bit15 && !two) ? 1 : 0;
}
PCREG(532730, fn532730);

// 0x62cc50 / 0x62cf40 cdecl (obj, code) message handlers.
extern "C" int fn62cc50(u32 *obj, int code) {
  if (code == 0xf) return 0;
  if (code == 0x17) { obj[0] = 0x62cc90; return 0; }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return -1;
}
PCREG(62cc50, fn62cc50);

extern "C" int fn62cf40(u32 *obj, int code) {
  if (code == 0xf) return 0;
  if (code == 0x19) { obj[0] = 0x62dbb0; return 0x33; }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return -1;
}
PCREG(62cf40, fn62cf40);

// 0x545d10 thiscall ret 0x10: copy fields of the 0x34-byte record idx from the table at this+0xf into three outputs.
THISCALL void fn545d10(u8 *self, int idx, u32 *o1, u32 *o2, u32 *o3) {
  u8 *e = *(u8 **)(self + 0xf) + idx * 0x34;
  o1[0] = *(u32 *)(e + 0xc); o1[1] = *(u32 *)(e + 0x10); o1[2] = *(u32 *)(e + 0x14);
  o2[0] = *(u32 *)(e + 0x24); o2[1] = *(u32 *)(e + 0x28); o2[2] = *(u32 *)(e + 0x2c);
  *o3 = *(u32 *)(e + 0x30);
}
PCREG(545d10, fn545d10);

// 0x623010 cdecl (unused, u8 **src, u8 *srcEnd, u16 **dst, u16 *dstEnd): widen bytes to words until either end is reached.
extern "C" void fn623010(u32, u8 **src, u8 *srcEnd, u8 **dst, u8 *dstEnd) {
  if (*src == srcEnd) return;
  do {
    u8 *d = *dst;
    if (d == dstEnd) break;
    *(u16 *)d = **src;
    *dst += 2;
    ++*src;
  } while (*src != srcEnd);
}
PCREG(623010, fn623010);

// 0x615560 thiscall: pop an entry (0x30 bytes, index in u16 at +2) off the pool free list, initialise it, count it in byte 0, return entry+0x10 (0 when empty).
THISCALL u8 *fn615560(u8 *self) {
  u16 h = *(u16 *)(self + 2);
  if (h == 0xffff) return 0;
  u8 *e = self + h * 0x30;
  *(u16 *)(self + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x22) = 0xffff;
  *(u32 *)(e + 0x10) = 0;
  *(u32 *)(e + 0x14) = 0xffff1206;
  *(u32 *)(e + 0x18) = 0;
  *(u32 *)(e + 0x1c) = 0;
  *(u32 *)(e + 0x24) = 0;
  *(u32 *)(e + 0x2c) = 0;
  *(u32 *)(e + 0x28) = 0;
  e[0x20] = 0;
  self[0]++;
  return e + 0x10;
}
PCREG(615560, fn615560);
