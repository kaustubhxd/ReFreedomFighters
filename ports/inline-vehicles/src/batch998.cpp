// batch998.cpp - area 53 (residue 11 remainder), batch 998: ZCollisionBase::GetDynamicGeomsInBoxInRooms (0x4ecd30), STDCALL with ten stack
// arguments (ret 0x28; ECX is not used). A1 = list of X pointers (A4 = array of X), A3..A10 as in the listing; the count result is EBX.
// Frame struct L10c4 (address-taken; its member +0x64 is a counter that the helpers write). The helpers are GUESS stand-ins by address.
#include "ff.h"

#define STDCALL __attribute__((stdcall))
#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4e3180(void *s);                                  // GUESS: struct init (stood in)
extern "C" void THISCALL ext_4e2c60(void *a6);                                 // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *v); // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_43e8e0(void *ecx, void *edx, void *v); // GUESS (stood in)
extern "C" void THISCALL ext_4e4420(void *self, void *s, void *v28, void *v1c); // GUESS (stood in)
extern "C" void THISCALL ext_4ec6d0(void *s);                                  // GUESS (stood in)
extern "C" void THISCALL ext_4daf90(void *x, void *v);                         // GUESS (stood in)
extern "C" void THISCALL ext_4de7a0(void *v);                                  // exe vector init
extern "C" void THISCALL ext_4db600(void *x, void *v4c, void *v10);            // GUESS (stood in)
extern "C" u32 THISCALL ext_4df330(void *a6, void *a8, void *v4c, void *v10, void *xo40); // GUESS (stood in)

// 0x4ecd30 ZCollisionBase::GetDynamicGeomsInBoxInRooms(...).
static u32 STDCALL dynGeoms(u8 *list, u8 *a2, u32 a3, u32 *a4, u32 a5, u8 *a6, u8 *a7, u8 *a8, u32 a9, u32 a10) {
  (void)a2; (void)a3; (void)a9;
  u32 st[0x40];
  u8 *s = (u8 *)st;
  u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u8 *r = (u8 *)D(rm, 0xadc);
  u32 r0 = vcall<u32>(r, 0x314);
  if (!r0)
    return 0;
  ext_4e3180(s);
  u32 bx = 0;
  D(s, 0x64) = 0;
  D(s, 0x70) = 0;
  D(s, 4) = 0x4edd40u;
  if (a5 != 0) {
    u32 v10[3] = {D(a8, 0), D(a8, 4), D(a8, 8)};
    u32 v28[3];
    u32 v1c[3];
    ext_4e2c60(a6);
    ext_43e920(v28, a7, v10);
    ext_43e8e0(v1c, a7, v10);
    for (u32 k = 0; k < a5; k++) {
      D(s, 0x70) = a4[k];
      ext_4e4420((void *)r0, s, v28, v1c);
    }
    ext_4ec6d0(s);
    bx = D(s, 0x64);
  }
  if ((u8)a10 != 0 && bx != 0) {
    u32 v10[3];
    u32 v4c[4];
    u32 *lst = (u32 *)list;
    int last = (int)bx - 1;
    u32 idx = 0;
    // v10 is the vector written by the element helpers (see below); its initial value is not used before the first helper.
    do {
      u8 *x = (u8 *)lst[idx];
      ext_4daf90(x, v10);
      ext_4de7a0(v4c);
      ext_4db600(x, v4c, v10);
      u32 al = ext_4df330(a6, a8, v4c, v10, x + 0x40);
      if (!(u8)al) {
        lst[idx] = lst[last];
        bx--;
        last--;
        idx--;
      }
      idx++;
    } while (idx != bx);
  }
  return bx;
}
PCREG(4ecd30, dynGeoms);
