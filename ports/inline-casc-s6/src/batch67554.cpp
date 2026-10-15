// batch67554.cpp - cascade s6 batch 67554: 0x5b0360.
#include "ff.h"

extern "C" void THISCALL ext_5aede0(u8 *a);                      // clears a[0], plain ret
extern "C" void THISCALL ext_5aee60(u8 *a, u32 v);               // ret 4
extern "C" void THISCALL ext_65e090(u32 *b);                     // clears 3 dwords, plain ret
extern "C" void THISCALL ext_5afbb0(u32 *b, u32 t, u8 *a);       // ret 8
extern "C" u32 THISCALL ext_5af350(u32 *b, u32 k);               // ret 4
extern "C" void THISCALL ext_5af2a0(u8 *t, u32 k, u32 v);        // ret 8
extern "C" void THISCALL ext_5af5b0(u32 *b, u8 *p, u8 *q, u32 f); // ret 0xc

#define SYS (*(u8 **)0x70039c)

// 0x5b0360, thiscall() plain ret (eax unused): initialises the object's table entries from two configuration records. It reads the string key 0x6a7374 through the table object's slot 0x138
// (slot 0x88 writes an id) into a local record via 0x5aee60, builds a second record from the key 0x681320 (slot 0x58 maps the id, 0x5afbb0 fills it from the first), then copies the entries for
// 0xd, 0xc, 0xe, 0x10 and 0xf (0x5af350 reads, 0x5af2a0 writes into this+0x18) and finishes with two 0x5af5b0 calls filling this+8/+0x10 (flag 1) and this+0xc/+0x14 (flag 0).
static void THISCALL fn5b0360(u8 *self) {
  u8 a[0x64];
  u32 b[4];
  u32 id = 0;
  ext_5aede0(a);
  u8 *o = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x138);
  vcall<void>(o, 0x88, 0x6a7374u, (u32)&id);
  ext_5aee60(a, id);
  ext_65e090(b);
  o = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x138);
  id = 0;
  vcall<void>(o, 0x88, 0x681320u, (u32)&id);
  u32 t = vcall<u32>(*(u8 **)(SYS + 0x9b), 0x58, id);
  ext_5afbb0(b, t, a);
  static const u32 keys[] = {0xd, 0xc, 0xe, 0x10, 0xf};
  for (u32 k : keys) ext_5af2a0(self + 0x18, k, ext_5af350(b, k));
  ext_5af5b0(b, self + 8, self + 0x10, 1);
  ext_5af5b0(b, self + 0xc, self + 0x14, 0);
}
PCREG(5b0360, fn5b0360);
