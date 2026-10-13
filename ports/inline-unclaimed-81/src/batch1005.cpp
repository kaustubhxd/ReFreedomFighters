// batch1005.cpp - area 81 (residue 0), batch 1005: ZKillBox::RemoveWeapons(), 0x5b1f80, thiscall, no arguments, plain ret.
// Cookie check not reproduced (no SEH frame). GUESS helper 0x4db7c0 (thiscall, one argument, stood in). The frame is kept as one buffer
// (fr + 0x258 plays ebp), so the list at ebp-0x254 and the array at ebp-0x1d0 overlap in the same way as in the exe.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4db7c0(void *self, u32 arg);   // GUESS (stood in)

// 0x5b1f80 ZKillBox::RemoveWeapons().
static void THISCALL killBoxRemoveWeapons(u8 *self) {
  if (!*(u8 *)(self + 0x8c))
    return;
  u8 *sys = *(u8 **)0x70039c;
  u8 *rm = (u8 *)D(sys, 0x9b);
  u8 *o = (u8 *)vcall<u32>(rm, 0x58, D(self, 0x4e));
  u8 fr[0x260];
  u8 *v40 = fr + 0x218;   // [ebp-0x40]
  u8 *v1c = fr + 0x23c;   // [ebp-0x1c]
  u8 *v10 = fr + 0x248;   // [ebp-0x10]
  u32 *cnt = (u32 *)fr;   // [ebp-0x258]
  u32 *lst = (u32 *)(fr + 4);    // [ebp-0x254]
  u32 *arr = (u32 *)(fr + 0x88); // [ebp-0x1d0]
  *cnt = 0;
  vcall<void>(o, 0x80, (u32)v40, (u32)v1c);
  ext_4db7c0((void *)D(o, 8), (u32)v10);
  u8 *rm2 = (u8 *)D(sys, 0x1aa3);
  u32 n = vcall<u32>((void *)D(rm2, 0x1c), 0x38, (u32)arr, (u32)v40, 0u, (u32)v40, (u32)v1c, (u32)v10, (u32)-1, 0u, 1u, 1u);
  for (u32 i = 0; i < n; ++i) {
    u8 *o1 = (u8 *)vcall<u32>((void *)D(arr[i], 0x54), 0x20);
    if ((u8)vcall<u32>(o1, 0x1e0, 0x1007d2u)) {
      u32 o2 = vcall<u32>((void *)D(arr[i], 0x54), 0x20);
      u32 k = 0;
      while (k < *cnt && lst[k] != o2)
        ++k;
      if (k == *cnt) {
        lst[k] = o2;
        ++*cnt;
      }
    }
  }
  for (u32 k = 0; k < *cnt; ++k) {
    u8 *x = (u8 *)lst[k];
    if (!vcall<u32>(x, 0x2f4))
      vcall<void>(x, 0x320);
  }
}
PCREG(5b1f80, killBoxRemoveWeapons);
