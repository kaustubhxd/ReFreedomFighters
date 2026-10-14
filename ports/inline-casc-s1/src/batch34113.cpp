// batch34113.cpp - cascade tier E, batch 34113: 0x42cc60 (checked block release), 0x43ab30 (iterate and mask flags), 0x445d50 (pick current item).
#include "ff.h"

extern "C" u32 THISCALL ext_4ce1c0(void *self, u32 a, u32 b);   // thiscall ret 8

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

static void assert_hook() {
  typedef void (*hf)(void);
  hf h = G(hf, 0x7003b0);
  if (!h) { asm volatile("int3"); return; }
  h();
}

// 0x42cc60, thiscall(p) ret 4: B = unaligned [this+0x1b55] (the assert hook runs when it is null). s = p - 2; size = word [s]; the assert hook runs when s < B or s + size > B + 0xa000 (unsigned) and when
// the byte at s + size - 1 is not 0x5a; then ext_4ce1c0(unaligned [this+0x1b51], s - B, size).
static void THISCALL fn42cc60(u8 *self, u8 *p) {
  if (rd32(self + 0x1b55) == 0) assert_hook();
  u8 *s = p - 2;
  u32 B = rd32(self + 0x1b55);
  u32 size = s[0] | s[1] << 8;
  bool ok = !((u32)s < B) && (u32)s + size <= B + 0xa000;
  if (!ok) assert_hook();
  if (s[size - 1] != 0x5a) assert_hook();
  ext_4ce1c0((void *)rd32(self + 0x1b51), (u32)s - rd32(self + 0x1b55), size);
}
PCREG(42cc60, fn42cc60);

// 0x43ab30, thiscall plain: walks the items of the container at unaligned [this+0x19] (slot 0x4c fills an iterator, slot 0x5c returns the next item and updates it); for each item r != 0 with [r] == 0 (obj = r - 4):
// the dword at obj+0x2d = 0, byte [obj+0x32] &= 0x2f, byte [obj+0x33] &= 1; the walk ends when the iterator's first dword is 0.
static void THISCALL fn43ab30(u8 *self) {
  u32 it[4];
  u32 loc;
  u8 *m = (u8 *)rd32(self + 0x19);
  if (!m) return;
  vcall<void>(m, 0x4c, (u32)it);
  u8 *r = vcall<u8 *>((u8 *)rd32(self + 0x19), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    if (r && *(u32 *)r == 0) {
      u8 *obj = r - 4;
      if (obj + 0x2d != (u8 *)&loc) wr32(obj + 0x2d, 0);
      obj[0x32] &= 0x2f;
      obj[0x33] &= 1;
    }
    r = vcall<u8 *>((u8 *)rd32(self + 0x19), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(43ab30, fn43ab30);

// 0x445d50, thiscall(arr, n) ret 8: n == 1: [this+0x18] = arr[0]. Else x = this->slot0x288(); when x is non-zero and one of arr[0..n) equals it, [this+0x18] = x; otherwise keep [this+0x18] when it is non-zero and in arr, else [this+0x18] = arr[0] (n > 0).
static void THISCALL fn445d50(u8 *self, u32 *arr, u32 n) {
  if (n == 1) {
    *(u32 *)(self + 0x18) = arr[0];
    return;
  }
  u32 x = vcall<u32>(self, 0x288);
  if (x != 0 && n != 0) {
    for (u32 i = 0; i != n; i++)
      if (arr[i] == x) {
        *(u32 *)(self + 0x18) = x;
        return;
      }
  }
  u32 cur = *(u32 *)(self + 0x18);
  if (cur != 0) {
    if (n == 0) return;
    for (u32 i = 0; i != n; i++)
      if (arr[i] == cur) return;
  }
  if (n == 0) return;
  *(u32 *)(self + 0x18) = arr[0];
}
PCREG(445d50, fn445d50);
