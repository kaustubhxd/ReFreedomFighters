// batch218013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_5fed20_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5fed20");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_5ff140_stdcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5ff140");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 STDCALL ext_634123_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_634123");
extern "C" u32 THISCALL ext_4364e0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4364e0");
extern "C" u32 THISCALL ext_45f3c0_thiscall2(u32, u32) __asm__("ext_45f3c0");
extern "C" u32 THISCALL ext_4634f0_thiscall2(u32, u32) __asm__("ext_4634f0");
extern "C" u32 THISCALL ext_4957f0_thiscall3(u32, u32, u32) __asm__("ext_4957f0");
extern "C" u32 THISCALL ext_497750_thiscall2(u32, u32) __asm__("ext_497750");
extern "C" u32 THISCALL ext_497930_thiscall1(u32) __asm__("ext_497930");
extern "C" u32 THISCALL ext_4a85a0_thiscall2(u32, u32) __asm__("ext_4a85a0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc930_thiscall3(u32, u32, u32) __asm__("ext_4cc930");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cda40_thiscall3(u32, u32, u32) __asm__("ext_4cda40");
extern "C" u32 THISCALL ext_4cdd40_thiscall1(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4ce5b0_thiscall2(u32, u32) __asm__("ext_4ce5b0");
extern "C" u32 THISCALL ext_4d8ce0_thiscall2(u32, u32) __asm__("ext_4d8ce0");
extern "C" u32 THISCALL ext_4d93e0_thiscall1(u32) __asm__("ext_4d93e0");
extern "C" u32 THISCALL ext_4dcdf0_thiscall2(u32, u32) __asm__("ext_4dcdf0");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_5f5520_thiscall3(u32, u32, u32) __asm__("ext_5f5520");
extern "C" u32 THISCALL ext_5f55e0_thiscall1(u32) __asm__("ext_5f55e0");
extern "C" u32 THISCALL ext_5fa380_thiscall3(u32, u32, u32) __asm__("ext_5fa380");
extern "C" u32 THISCALL ext_5ff0a0_thiscall1(u32) __asm__("ext_5ff0a0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)



extern "C" u32 THISCALL lifted_5f95e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d168);  // @h_5f95e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5f95e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f95e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5f95e0
  ecx = 0;  // @3_5f95e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5f95e0
  edi = (u32)(4);  // @5_5f95e0
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @6_5f95e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @7_5f95e0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @8_5f95e0
  ecx = (0u - ecx);  // @9_5f95e0
  ecx = (ecx | eax);  // @10_5f95e0
  PV[0] = (u32)(ecx);  // @11_5f95e0
  eax = ext_41e290_cdecl1(PV[0]);  // @12_5f95e0
  ecx = edx = 0;  // @13_5f95e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_5f95e0
  ecx = 0;  // @15_5f95e0
  reg.state = (s32)((u32)(0));  // @16_5f95e0
  eax = (u32)(1000);  // @17_5f95e0
  { u32 v = (u32)((u32)(1000)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @18_5f95e0
  { u64 p_ = (u64)eax * (u64)(u32)(edi); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @19_5f95e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @20_5f95e0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @21_5f95e0
  ecx = (0u - ecx);  // @22_5f95e0
  ecx = (ecx | eax);  // @23_5f95e0
  PV[1] = (u32)(ecx);  // @24_5f95e0
  eax = ext_41e290_cdecl1(PV[1]);  // @25_5f95e0
  ecx = edx = 0;  // @26_5f95e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @27_5f95e0
  eax = esi;  // @28_5f95e0
  SEH_LEAVE();  // @29_5f95e0
  return eax;  // @30_5f95e0
}
PCREG(5f95e0, lifted_5f95e0);

extern "C" u32 lifted_5f27a0(void) {
  SEH_ENTER(0x66cfe7);  // @h_5f27a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ext_41e290_cdecl1((u32)(16));  // @0_5f27a0
  ecx = edx = 0;  // @1_5f27a0
  esi = eax;  // @2_5f27a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @3_5f27a0
  reg.state = (s32)((u32)(0));  // @4_5f27a0
  if ((esi & esi) == 0) goto L5f2829;  // @5_5f27a0
  ecx = 0;  // @6_5f27a0
  { u32 v = (u32)((u32)(7046360)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5f27a0
  eax = (u32)(20);  // @8_5f27a0
  reg.state = (s32)((u32)(1));  // @9_5f27a0
  edx = (u32)(4);  // @10_5f27a0
  { u32 v = (u32)((u32)(20)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @11_5f27a0
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @12_5f27a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @13_5f27a0
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @14_5f27a0
  ecx = (0u - ecx);  // @15_5f27a0
  ecx = (ecx | eax);  // @16_5f27a0
  PV[0] = (u32)(ecx);  // @17_5f27a0
  eax = ext_41e290_cdecl1(PV[0]);  // @18_5f27a0
  ecx = edx = 0;  // @19_5f27a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @20_5f27a0
  eax = esi;  // @21_5f27a0
  SEH_LEAVE();  // @22_5f27a0
  return eax;  // @23_5f27a0
  L5f2829:;
  eax = 0;  // @25_5f27a0
  SEH_LEAVE();  // @26_5f27a0
  return eax;  // @27_5f27a0
}
PCREG(5f27a0, lifted_5f27a0);






extern "C" u32 THISCALL lifted_5f0670(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);  // @h_5f0670
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5f0670
  { u32 v = (u32)((u32)(7045828)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_5f0670
  ecx = (u32)(esi + 124);  // @2_5f0670
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @3_5f0670
  eax = (u32)(715827883);  // @4_5f0670
  edx = (edx - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }));  // @5_5f0670
  { long long p_ = (long long)(s32)eax * (long long)(s32)(edx); eax = (u32)p_; edx = (u32)((u64)p_ >> 32); }  // @6_5f0670
  reg.state = (s32)((u32)(0));  // @7_5f0670
  edx = (u32)((s32)edx >> (u32)(1));  // @8_5f0670
  eax = edx;  // @9_5f0670
  eax = (eax >> (u32)(31));  // @10_5f0670
  eax = (eax + edx);  // @11_5f0670
  if (eax == 0) goto L5f06ca;  // @12_5f0670
  eax = (u32)(eax + eax*2);  // @13_5f0670
  eax = (eax << (u32)(2));  // @14_5f0670
  PV[0] = (u32)(eax);  // @15_5f0670
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5f0670
  eax = ext_54f870_stdcall2(PV[1], PV[0]);  // @17_5f0670
  ecx = edx = 0;  // @18_5f0670
  L5f06ca:;
  { u32 v = (u32)((u32)(7012828)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @20_5f0670
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L5f06e4;  // @21_5f0670
  PV[2] = (u32)(esi);  // @22_5f0670
  eax = ext_634273_cdecl2(PV[2], (u32)(144));  // @23_5f0670
  ecx = edx = 0;  // @24_5f0670
  L5f06e4:;
  eax = esi;  // @26_5f0670
  SEH_LEAVE();  // @27_5f0670
  return eax;  // @28_5f0670
}
PCREG(5f0670, lifted_5f0670);



