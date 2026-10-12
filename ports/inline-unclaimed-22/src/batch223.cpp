// batch223.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. Three functions: five calls
// to one vtable slot on an argument object (the last result, with al = 1); a binary-search insertion into an array of
// 9-byte {float key; byte flag} records (no calls); and a getter that fills a field through two vtable slots and then
// calls a trivial original (0x4e3330 is xor eax, eax; ret 0x10).
#include "ff.h"

extern "C" u32 THISCALL ext_4e3330(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4);   // original: xor eax, eax; ret 0x10

typedef u32(THISCALL *Slot1)(u8 *, u32);
typedef u32(THISCALL *Slot4)(u8 *, u32, u32, u32, u32);

// 0x524410, thiscall(a): a->vt[0x50](this), a->vt[0x50](this+4), (this+8), (this+0xc), (this+0x10); return the last result
// with its low byte cleared and bit 0 set (mov al, 1). Name GUESS.
static u32 THISCALL slot50Five_524410(u8 *self, u8 *a) {
  vcall<u32>(a, 0x50, (u32)self);
  vcall<u32>(a, 0x50, (u32)(self + 4));
  vcall<u32>(a, 0x50, (u32)(self + 8));
  vcall<u32>(a, 0x50, (u32)(self + 0xc));
  u32 r = vcall<u32>(a, 0x50, (u32)(self + 0x10));
  return (r & ~0xffu) | 1u;
}
PCREG(524410, slot50Five_524410);

// 0x4e3190, fastcall(arr = ecx, n = edx, key): binary-search insert of the 9-byte record key into arr[0..n), moving
// larger records up. Element i is at arr + 9 * i. Name GUESS.
static void copy9(u8 *dst, const u8 *src) {
  *(u32 *)dst = *(const u32 *)src;
  *(u32 *)(dst + 4) = *(const u32 *)(src + 4);
  dst[8] = src[8];
}

static void FASTCALL binInsert9_4e3190(u8 *arr, s32 n, u8 *key) {
  s32 i = n;
  if (i > 0) {
    do {
      s32 m = i >> 1;
      u8 *e = arr + 9 * m;
      if (!(*(float *)e > *(float *)key)) break;   // comiss + jbe: also taken when unordered
      copy9(arr + 9 * i, e);
      i = m;
    } while (i > 0);
  }
  copy9(arr + 9 * i, key);
}
PCREG(4e3190, binInsert9_4e3190);

// 0x43ee10, stdcall(a1..a4): o = [[0x70039c] + 0x9b]; esi = o->vt[0x58](o->[+0x14]). If esi is null: esi =
// [o->[+0xadc]]->vt[0x294](0x67c7fc, 0x67cd24, 1, 1), and o->[+0x14] = o->vt[0x4c](esi) (the second read of o). Then
// return 0x4e3330(esi, a1, a2, a3, a4). Name GUESS.
static u32 STDCALL vtGetFill_43ee10(u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 *o = *(u8 **)(*(u8 **)0x70039cu + 0x9b);
  u32 esi = vcall<u32>(o, 0x58, *(u32 *)(o + 0x14));
  if (!esi) {
    u8 *o2 = *(u8 **)(*(u8 **)(*(u8 **)0x70039cu + 0x9b) + 0xadc);
    esi = vcall<u32>(o2, 0x294, 0x67c7fc, 0x67cd24, 1u, 1u);
    u8 *o3 = *(u8 **)(*(u8 **)0x70039cu + 0x9b);
    u32 r = vcall<u32>(o3, 0x4c, esi);
    *(u32 *)(*(u8 **)(*(u8 **)0x70039cu + 0x9b) + 0x14) = r;
  }
  return ext_4e3330((u8 *)esi, a1, a2, a3, a4);
}
PCREG(43ee10, vtGetFill_43ee10);
