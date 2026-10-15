// batch67568.cpp - cascade s6 batch 67568: 0x615ae0.
#include "ff.h"

extern "C" void FASTCALL ext_60ff30(u32 a, u32 b, u32 c, u32 d);   // ret 8
extern "C" void FASTCALL ext_60feb0(u32 a, u32 b, u32 c, u32 d);   // ret 8
extern "C" u32 THISCALL ext_65c3e0(u8 *self, u32 v);               // ret 4, bool in al

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef void (__cdecl *log6_t)(u8 *, u32, u32, u32, u32, u32);
typedef u32 (STDCALL *com3_t)(u8 *, u32, u32);

// 0x615ae0, thiscall(v) ret 4, returns what 0x65c3e0(v) returns: refreshes the pad state of the device owner R = this[0x182a5]. After slot 0x140 R[0x115f] is 3, with bits 1 / 2 cleared when R[0x115b] |
// R[0x1157] has bits 0 / 1 set. The inverted two bits select two strings (0x6bdc14 or 0x6a9aa0) that are logged through sys slot 0x190's object (cdecl slot 0x184: (obj, 0, 1, 0x6bdc18, s0, s1)). With both
// bits set the render state tables are reset (0x60ff30 / 0x60feb0 (2, 3, 1)) and R[0x1377] slot 0xc8(8, 2) runs; a pending flag at 0x724948 is cleared with slot 0xc8(0x89, 0) on the device at 0x724a00.
static u32 THISCALL fn615ae0(u8 *self, u32 v) {
  u8 *R = *(u8 **)(self + 0x182a5);
  vcall<void>(R, 0x140);
  D32(R, 0x115f) = 3;
  R = *(u8 **)(self + 0x182a5);
  u32 cl = D32(R, 0x115b) | D32(R, 0x1157);
  if (cl & 1) D32(R, 0x115f) &= 0xfffffffeu;
  if (cl & 2) {
    R = *(u8 **)(self + 0x182a5);
    D32(R, 0x115f) &= 0xfffffffdu;
  }
  R = *(u8 **)(self + 0x182a5);
  u32 ebx = (~(D32(R, 0x115b) | D32(R, 0x1157)) & 3);
  u8 *x = vcall<u8 *>(*(u8 **)0x70039c, 0x190);
  u32 s1 = (ebx & 2) ? 0x6bdc14u : 0x6a9aa0u;
  u32 s0 = (ebx & 1) ? 0x6bdc14u : 0x6a9aa0u;
  (*(log6_t *)(*(u8 **)x + 0x184))(x, 0, 1, 0x6bdc18u, s0, s1);
  if (ebx == 0) {
    ext_60ff30(0, 2, 3, 1);
    ext_60feb0(0, 2, 3, 1);
    u8 *d = *(u8 **)(*(u8 **)(self + 0x182a5) + 0x1377);
    (*(com3_t *)(*(u8 **)d + 0xc8))(d, 8, 2);
  }
  if ((*(volatile u32 *)0x724948) != 0) {
    u8 *dev = *(u8 **)0x724a00;
    (*(volatile u32 *)0x724948) = 0;
    (*(com3_t *)(*(u8 **)dev + 0xc8))(dev, 0x89, 0);
  }
  return ext_65c3e0(self, v);
}
PCREG(615ae0, fn615ae0);
