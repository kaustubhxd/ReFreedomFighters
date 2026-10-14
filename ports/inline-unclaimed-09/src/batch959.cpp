// batch959.cpp - area 56 claim A21 (0x645af0). thiscall, args (A, v, base), ret 0xc, returns a bool. Helpers are original exe code,
// declared with the caller's pushes (area 21 ports them separately): ecx/edx register arguments plus the stack arguments the caller pushes.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(u8 *ecx, u8 *edx, u32 s);
extern "C" void FASTCALL ext_4856d0(u8 *ecx);
extern "C" void FASTCALL ext_441a60(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_43e960(u8 *ecx, u8 *edx);
extern "C" void FASTCALL ext_43e8e0(u8 *ecx, u8 *edx, u32 s);

static u8 THISCALL searchBox645af0(u8 *self, u8 *a, u32 v12, u8 *base) {
  // One frame so that l1 = l3 + 0x18 as in the exe (ebp-0xc vs ebp-0x24), which the tie-planting hook relies on.
  u8 frame[0x24];
  u8 *l3 = frame;         // exe ebp-0x24
  u8 *l2 = frame + 0xc;   // exe ebp-0x18: 5.0 three times
  u8 *l1 = frame + 0x18;  // exe ebp-0xc: x, y, z
  ext_43e920(l1, a, (u32)(self + 0x281));
  ext_4856d0(l1);
  if (*(float *)(l1 + 0) > *(float *)(self + 0x275)) return 0;
  if (*(float *)(l1 + 4) > *(float *)(self + 0x279)) return 0;
  if (*(float *)(l1 + 8) > *(float *)(self + 0x27d)) return 0;
  for (int i = 0; i < 3; i++) *(u32 *)(l2 + 4 * i) = 0x40a00000u;
  if (*(u32 *)(self + 0x11) == 0) return 0;
  u32 v = v12 - (u32)base;
  u8 *esi = base;
  u32 edi = 0;
  for (;;) {
    ext_43e920(l1, a, v + 0x24u + (u32)esi);
    ext_441a60(l1, (u8 *)(v + (u32)esi));
    ext_43e960(l1, esi);
    ext_4856d0(l1);
    ext_43e8e0(l3, esi + 0x10, (u32)l2);
    if (*(float *)(l3 + 0) > *(float *)(l1 + 0)) {
      if (*(float *)(l3 + 4) > *(float *)(l1 + 4)) {
        if (*(float *)(l3 + 8) > *(float *)(l1 + 8)) return 1;
      }
    }
    edi++;
    esi += 0x30;
    if (edi == *(u32 *)(self + 0x11)) return 0;
  }
}
PCREG(645af0, searchBox645af0);
