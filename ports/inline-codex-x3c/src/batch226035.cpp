// batch226035.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_602260_thiscall2(u32, u32) __asm__("ext_602260");
extern "C" u32 THISCALL ext_603110_thiscall1(u32) __asm__("ext_603110");
extern "C" u32 THISCALL ext_6031e0_thiscall2(u32, u32) __asm__("ext_6031e0");
extern "C" u32 THISCALL ext_604650_thiscall1(u32) __asm__("ext_604650");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_5f3050(u32 a0, u32 a1) {
  SEH_ENTER(0x66d04f);  // @h_5f3050
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ext_41e290_cdecl1((u32)(18));  // @0_5f3050
  ecx = edx = 0;  // @1_5f3050
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @2_5f3050
  reg.state = (s32)((u32)(0));  // @3_5f3050
  if ((eax & eax) == 0) goto L5f3097;  // @4_5f3050
  ecx = eax;  // @5_5f3050
  eax = ext_604650_thiscall1(ecx);  // @6_5f3050
  ecx = edx = 0;  // @7_5f3050
  esi = eax;  // @8_5f3050
  goto L5f3099;  // @9_5f3050
  L5f3097:;
  esi = 0;  // @11_5f3050
  L5f3099:;
  reg.state = (s32)((u32)(4294967295));  // @13_5f3050
  if ((esi & esi) == 0) goto L5f30b3;  // @14_5f3050
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_5f3050
  if ((ecx & ecx) == 0) goto L5f30b3;  // @16_5f3050
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_5f3050
  PS[0] = ecx;  // @18_5f3050
  ecx = esi;  // @19_5f3050
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(PS[0]));  // @20_5f3050
  ecx = edx = 0;  // @21_5f3050
  L5f30b3:;
  eax = esi;  // @23_5f3050
  SEH_LEAVE();  // @24_5f3050
  return eax;  // @25_5f3050
}
PCREG(5f3050, lifted_5f3050);

extern "C" u32 THISCALL lifted_602bc0(u32 ecx_in) {
  SEH_ENTER(0x66dbd8);  // @h_602bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_602bc0
  eax = ext_603110_thiscall1(ecx);  // @1_602bc0
  ecx = edx = 0;  // @2_602bc0
  { u32 v = (u32)((u32)(7046408)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @3_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @4_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @5_602bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @6_602bc0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @7_602bc0
  PS[0] = eax;  // @8_602bc0
  ecx = (u32)(EBP - 36);  // @9_602bc0
  reg.state = (s32)((u32)(0));  // @10_602bc0
  eax = ext_602260_thiscall2(ecx, (u32)(PS[0]));  // @11_602bc0
  ecx = edx = 0;  // @12_602bc0
  eax = (u32)(EBP - 36);  // @13_602bc0
  ecx = esi;  // @14_602bc0
  PS[0] = eax;  // @15_602bc0
  eax = ext_6031e0_thiscall2(ecx, (u32)(PS[0]));  // @16_602bc0
  ecx = edx = 0;  // @17_602bc0
  ecx = (u32)(EBP - 36);  // @18_602bc0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @19_602bc0
  eax = ext_602240_thiscall1(ecx);  // @20_602bc0
  ecx = edx = 0;  // @21_602bc0
  SEH_LEAVE();  // @22_602bc0
  return eax;  // @23_602bc0
}
PCREG(602bc0, lifted_602bc0);

