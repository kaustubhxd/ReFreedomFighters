// batch37090.cpp - cascade s6 batch 37090: 0x63e680.
#include "ff.h"

extern "C" u32 THISCALL ext_4db9a0(u8 *self, u32 key);                   // ret 4, bool in al
extern "C" u32 THISCALL ext_658d50(u8 *self);                            // plain ret
extern "C" void *__attribute__((cdecl)) ext_634d22(void *dst, const void *src, u32 n);   // memcpy thunk
extern "C" void *__attribute__((cdecl)) ext_634d10(void *dst, u32 v, u32 n);             // memset thunk

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x63e680, thiscall(a) ret 4, returns bool: collects the entries of a's list (head offset at [a+0x38]+0x6c, entries at base + offset, base from the engine object at +0x1aa3 -> +0x20)
// that are active (word +0xe), not marked 0x800000 at +0x20 and of kind 0, 1, 3 or 4 into a stack table of up to 0x100 {0, entry} pairs, setting a+0x3c bit 0 when an entry has
// a value at +0x1c. The table is copied into a buffer allocated through slot 0x20 of this (a+0x40, count in a+0x3d; allocation failure returns false). When key 0x200006 is
// present on a+0x38 with a value at [[a+0x38]+0x54]+0x20, that byte goes to a+0x3f (a+0x3c bit 2 when its slot 0x2fc says so) and a zeroed buffer of 0x658d50(a) bytes is allocated
// at a+0x48 and registered through slot 0x58 (failure clears a+0x3f and returns false).
static u8 THISCALL fn63e680(u8 *self, u8 *a) {
  u32 buf[0x200];
  u32 n = 0;
  u32 base = D32(*(u8 **)(*(u8 **)0x70039c + 0x1aa3), 0x20);
  u32 off = D32(*(u8 **)(a + 0x38), 0x6c);
  while (off) {
    u8 *node = (u8 *)(off + base);
    u16 act = W16(node, 0xe);
    off = D32(node, 8);
    if (act == 0 || (D32(node, 0x20) & 0x800000)) continue;
    u16 k = W16(node, 2);
    if (k != 0 && k != 1 && k != 3 && k != 4) continue;
    buf[n * 2 + 1] = (u32)node;
    if (D32(node, 0x1c)) a[0x3c] |= 1;
    buf[n * 2] = 0;
    n++;
    if (n == 0x100) break;
  }
  a[0x3d] = (u8)n;
  if (n) {
    u32 sz = n * 8;
    D32(a, 0x40) = vcall<u32>(self, 0x20, sz);
    if (!D32(a, 0x40)) return 0;
    ext_634d22((void *)D32(a, 0x40), buf, sz);
  } else {
    D32(a, 0x40) = 0;
  }
  if ((u8)ext_4db9a0(*(u8 **)(a + 0x38), 0x200006)) {
    u8 *x = *(u8 **)(*(u8 **)(a + 0x38) + 0x54);
    if (D32(x, 0x20)) {
      a[0x3f] = x[0x20];
      if ((u8)vcall<u32>(x, 0x2fc)) a[0x3c] |= 4;
      u32 s1 = ext_658d50(a);
      D32(a, 0x48) = vcall<u32>(self, 0x20, s1);
      if (!D32(a, 0x48)) {
        a[0x3f] = 0;
        return 0;
      }
      u32 s2 = ext_658d50(a);
      ext_634d10((void *)D32(a, 0x48), 0, s2);
      vcall<void>(self, 0x58, (u32)a, 1u);
    }
  }
  return 1;
}
PCREG(63e680, fn63e680);
