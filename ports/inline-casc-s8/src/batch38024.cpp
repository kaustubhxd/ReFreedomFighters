// batch38024.cpp - cascade s8 batch 38024: 0x4991c0 (write an object table to a stream).
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define PUT(ptr, len) SLOT(w, 0x10, v2_t)(w, (u32)(ptr), (len))   /* stream write of len bytes */

// 0x4991c0, thiscall(writer) ret 4. Writes the owner's (this+8) header dwords (+0xc / +0x10 / +0x14), an iterator-driven id list (slots 0x1c / 0x20 / 0x14 / 0x4c / 0x5c of the owner), a
// 0x2000-dword block, the tag 'LOR3' (slot 0x28), then the pointer table at this+0xc: its entries are turned into object indexes ((p - base) / 0x70, -1 for null; base = [this+0x14]+4),
// written, and turned back into pointers (index * 0x70 + base, 0 for -1).
static void THISCALL fn4991c0(u8 *self, u8 *w) {
  SLOT(w, 8, v1_t)(w, 9);
  u8 *a = *(u8 **)(self + 8);
  PUT(a + 0xc, 4);
  a = *(u8 **)(self + 8);
  PUT(a + 0x10, 4);
  a = *(u8 **)(self + 8);
  PUT(a + 0x14, 4);
  a = *(u8 **)(self + 8);
  u8 *it = (u8 *)SLOT(a, 0x1c, v0_t)(a);
  a = *(u8 **)(self + 8);
  u32 buf = SLOT(a, 0x20, v0_t)(a);
  u32 l10 = SLOT(it, 0x14, v0_t)(it);
  PUT(&l10, 4);
  u32 cur[2];
  u32 l4;
  SLOT(it, 0x4c, v1_t)(it, (u32)cur);
  l4 = SLOT(it, 0x5c, v1_t)(it, (u32)cur);
  while (cur[0] != 0) {
    PUT(&l4, 4);
    l4 = SLOT(it, 0x5c, v1_t)(it, (u32)cur);
  }
  u32 l8 = 0x2000;
  PUT(&l8, 4);
  PUT(buf, l8 << 2);
  SLOT(w, 0x28, v1_t)(w, 0x4c4f5233);
  u32 base = *(u32 *)(*(u8 **)(self + 0x14) + 4);
  s32 edi = 0;
  a = *(u8 **)(self + 8);
  if (*(s32 *)(a + 0x10) != -1) {
    do {
      s32 *t = (s32 *)(*(u8 **)(self + 0xc) + edi * 4);
      s32 v = *t;
      if (v != 0) *t = (s32)((u32)v - base) / 112;
      else *t = -1;
      edi++;
      a = *(u8 **)(self + 8);
    } while (edi != *(s32 *)(a + 0x10) + 1);
  }
  a = *(u8 **)(self + 8);
  PUT(*(u8 **)(self + 0xc), *(u32 *)(a + 0x10) * 4 + 4);
  a = *(u8 **)(self + 8);
  s32 ecx = 0;
  if (*(s32 *)(a + 0x10) != -1) {
    do {
      s32 *t = (s32 *)(*(u8 **)(self + 0xc) + ecx * 4);
      s32 v = *t;
      if (v != -1) *t = (s32)((u32)v * 0x70 + base);
      else *t = 0;
      ecx++;
      a = *(u8 **)(self + 8);
    } while (ecx != *(s32 *)(a + 0x10) + 1);
  }
}
PCREG(4991c0, fn4991c0);
