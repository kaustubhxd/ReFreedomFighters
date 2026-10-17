// batch218015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4cc780_fastcall2(u32, u32) __asm__("ext_4cc780");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634047_cdecl0(void) __asm__("ext_634047");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_42c170(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664ce2);  // @h_42c170
  u8 F[0x460] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x360);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x360 + 8, &a0, 4);
  __builtin_memcpy(F + 0x360 + 12, &a1, 4);
  ebx = ecx;  // @0_42c170
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_42c170
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_42c170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 788), &v, sizeof v); }  // @3_42c170
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) != (u32)(0)) goto L42c1c6;  // @4_42c170
  ecx = esi;  // @5_42c170
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6781786));  // @6_42c170
  ecx = edx = 0;  // @7_42c170
  goto L42c2c3;  // @8_42c170
  L42c1c6:;
  PV[0] = (u32)(edi);  // @10_42c170
  ecx = (u32)(EBP - 144);  // @11_42c170
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @12_42c170
  ecx = edx = 0;  // @13_42c170
  ecx = (u32)(EBP - 144);  // @14_42c170
  reg.state = (s32)((u32)(0));  // @15_42c170
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_42c170
  ecx = edx = 0;  // @17_42c170
  PV[1] = (u32)(eax);  // @18_42c170
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676254))(PV[1], (u32)(58));  // @19_42c170
  ecx = edx = 0;  // @20_42c170
  if ((eax & eax) != 0) goto L42c2aa;  // @21_42c170
  PV[2] = (u32)(edi);  // @22_42c170
  ecx = (u32)(EBP - 400);  // @23_42c170
  eax = ext_4cbe80_thiscall2(ecx, PV[2]);  // @24_42c170
  ecx = edx = 0;  // @25_42c170
  ecx = (u32)(EBP - 272);  // @26_42c170
  reg.state = (s32)((u32)(1));  // @27_42c170
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @28_42c170
  ecx = edx = 0;  // @29_42c170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @30_42c170
  ecx = (u32)(EBP - 784);  // @31_42c170
  PV[3] = (u32)(ecx);  // @32_42c170
  ecx = ebx;  // @33_42c170
  reg.state = (s32)((u32)(2));  // @34_42c170
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 296)))(ecx, PV[3]);  // @35_42c170
  ecx = edx = 0;  // @36_42c170
  ecx = (u32)(EBP - 272);  // @37_42c170
  reg.state = (s32)((u32)(3));  // @38_42c170
  PV[4] = (u32)(ecx);  // @39_42c170
  ecx = (u32)(EBP - 656);  // @40_42c170
  PV[5] = (u32)(ecx);  // @41_42c170
  ecx = eax;  // @42_42c170
  eax = ext_4cc1e0_thiscall3(ecx, PV[5], PV[4]);  // @43_42c170
  ecx = edx = 0;  // @44_42c170
  ecx = (u32)(EBP - 400);  // @45_42c170
  reg.state = (s32)((u32)(4));  // @46_42c170
  PV[6] = (u32)(ecx);  // @47_42c170
  ecx = (u32)(EBP - 528);  // @48_42c170
  PV[7] = (u32)(ecx);  // @49_42c170
  ecx = eax;  // @50_42c170
  eax = ext_4cc1e0_thiscall3(ecx, PV[7], PV[6]);  // @51_42c170
  ecx = edx = 0;  // @52_42c170
  PV[8] = (u32)(eax);  // @53_42c170
  ecx = (u32)(EBP - 144);  // @54_42c170
  reg.state = (s32)((u32)(5));  // @55_42c170
  eax = ext_4cbee0_thiscall2(ecx, PV[8]);  // @56_42c170
  ecx = edx = 0;  // @57_42c170
  ecx = (u32)(EBP - 528);  // @58_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @59_42c170
  ecx = edx = 0;  // @60_42c170
  ecx = (u32)(EBP - 656);  // @61_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @62_42c170
  ecx = edx = 0;  // @63_42c170
  ecx = (u32)(EBP - 784);  // @64_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @65_42c170
  ecx = edx = 0;  // @66_42c170
  ecx = (u32)(EBP - 272);  // @67_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @68_42c170
  ecx = edx = 0;  // @69_42c170
  ecx = (u32)(EBP - 400);  // @70_42c170
  reg.state = (s32)((u32)(0));  // @71_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @72_42c170
  ecx = edx = 0;  // @73_42c170
  L42c2aa:;
  eax = (u32)(EBP - 144);  // @75_42c170
  ecx = esi;  // @76_42c170
  PV[9] = (u32)(eax);  // @77_42c170
  eax = ext_4cbe50_thiscall2(ecx, PV[9]);  // @78_42c170
  ecx = edx = 0;  // @79_42c170
  ecx = (u32)(EBP - 144);  // @80_42c170
  eax = ext_4cbec0_thiscall1(ecx);  // @81_42c170
  ecx = edx = 0;  // @82_42c170
  L42c2c3:;
  eax = esi;  // @84_42c170
  SEH_LEAVE();  // @85_42c170
  ext_633654(G(u32, 0x6f5630));  // @86_42c170
  return eax;  // @87_42c170
}
PCREG(42c170, lifted_42c170);






