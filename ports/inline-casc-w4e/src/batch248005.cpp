// batch248005.cpp - Sonnet-w4e, hand-written port of 0x663a40 (the lifter rejects its interleaved cookie epilogue).
#include "ff.h"
extern "C" u32 THISCALL ext_5ae5a0_thiscall3(u32, u32, u32) __asm__("ext_5ae5a0");
extern "C" u32 THISCALL ext_5adea0_thiscall1(u32) __asm__("ext_5adea0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline u32 rd32(u32 a) { u32 v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline void wr32(u32 a, u32 v) { __builtin_memcpy((void *)a, &v, 4); }

extern "C" u32 THISCALL lifted_663a40(u32 ecx_in, u32 a0) {
  u8 F[0x490] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x488);
  u32 big = EBP - 0x484, s = EBP - 0x84;
  u32 esi = ecx_in, ebx = a0, eax = 0, ecx = 0, edx = 0, h = 0;
  ext_5ae5a0_thiscall3(rd32(esi + 0x12104), big, 1);  // @0_663a40
  eax = esi + 0x121b4;  // @1_663a40
  for (;;) { u8 b = *(u8 *)eax; eax++; *(u8 *)(s + (eax - (esi + 0x121b4)) - 1) = b; if (b == 0) break; }  // @2_663a40
  eax = ext_5adea0_thiscall1(rd32(esi + 0x12104));  // @3_663a40
  edx = eax; u32 n = 0; while (*(u8 *)edx) { edx++; n++; } n++; // @4_663a40
  u32 e = s; while (*(u8 *)e) e++;  // @5_663a40
  for (u32 i = 0; i < n; i++) *(u8 *)(e + i) = *(u8 *)(eax + i);  // @6_663a40
  ecx = rd32(0x700394);  // @7_663a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(rd32(ecx) + 0x14)))(ecx, s);  // @8_663a40
  h = eax;  // @9_663a40
  if (h != 0) {  // @10_663a40
    ecx = rd32(0x700394);  // @11_663a40
    eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(rd32(ecx) + 0x38)))(ecx, h, big, 0x400);  // @12_663a40
    if ((eax & 0xff) != 0) {  // @13_663a40
      ecx = rd32(0x700394);  // @14_663a40
      eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(rd32(ecx) + 0x1c)))(ecx, h);  // @15_663a40
      eax = (eax & 0xffffff00u) | 1;  // @16_663a40
      ext_633654(G(u32, 0x6f5630));
      return eax;  // @17_663a40
    }
  }
  wr32(ebx, 9);  // @18_663a40
  eax = eax & 0xffffff00u;  // @19_663a40
  ext_633654(G(u32, 0x6f5630));
  return eax;  // @20_663a40
}
PCREG(663a40, lifted_663a40);
