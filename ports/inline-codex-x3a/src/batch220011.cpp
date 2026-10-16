// batch220011.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_53fd10_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_53fd10");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_545d60_thiscall4(u32, u32, u32, u32) __asm__("ext_545d60");
extern "C" u32 THISCALL ext_545e60_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_545e60");
extern "C" u32 THISCALL ext_5476e0_thiscall2(u32, u32) __asm__("ext_5476e0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_53f770(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[39];
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296560), sizeof v); (u32)v; });  // @0_53f770
  eax = (eax ^ EBP);  // @1_53f770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @2_53f770
  eax = (u32)(EBP - 65);  // @3_53f770
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_53f770
  STK[0] = eax;  // @5_53f770
  edi = ecx;  // @6_53f770
  { u32 v = (u32)((u32)(3248704672)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @7_53f770
  eax = (u32)(EBP - 40);  // @8_53f770
  { u32 v = (u32)((u32)(3253137579)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @9_53f770
  STK[1] = eax;  // @10_53f770
  eax = (u32)(EBP - 28);  // @11_53f770
  { u32 v = (u32)((u32)(3259498496)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @12_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @13_53f770
  edx = (u32)(EBP - 16);  // @14_53f770
  STK[2] = eax;  // @15_53f770
  { u32 v = (u32)((u32)(3248704672)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @16_53f770
  { u32 v = (u32)((u32)(3253137579)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @17_53f770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @18_53f770
  { u32 v = (u32)((u32)(3248704672)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @19_53f770
  { u32 v = (u32)((u32)(1114042539)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @20_53f770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @21_53f770
  { u32 v = (u32)((u32)(1114960625)); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @22_53f770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @23_53f770
  eax = ext_53fd10_fastcall5(ecx, edx, STK[2], STK[1], STK[0]);  // @24_53f770
  ecx = edx = 0;  // @25_53f770
  ecx = (u32)(EBP - 100);  // @26_53f770
  eax = ext_4de7a0_thiscall1(ecx);  // @27_53f770
  ecx = edx = 0;  // @28_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @29_53f770
  edx = (u32)(EBP - 100);  // @30_53f770
  STK[3] = edx;  // @31_53f770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_53f770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, STK[3]);  // @33_53f770
  ecx = edx = 0;  // @34_53f770
  edx = (u32)(EBP - 100);  // @35_53f770
  ecx = (u32)(EBP - 16);  // @36_53f770
  eax = ext_4419f0_fastcall2(ecx, edx);  // @37_53f770
  ecx = edx = 0;  // @38_53f770
  edx = (u32)(EBP - 100);  // @39_53f770
  ecx = (u32)(EBP - 28);  // @40_53f770
  eax = ext_4419f0_fastcall2(ecx, edx);  // @41_53f770
  ecx = edx = 0;  // @42_53f770
  edx = (u32)(EBP - 100);  // @43_53f770
  ecx = (u32)(EBP - 40);  // @44_53f770
  eax = ext_4419f0_fastcall2(ecx, edx);  // @45_53f770
  ecx = edx = 0;  // @46_53f770
  edx = (u32)(EBP - 100);  // @47_53f770
  ecx = (u32)(EBP - 64);  // @48_53f770
  eax = ext_4419f0_fastcall2(ecx, edx);  // @49_53f770
  ecx = edx = 0;  // @50_53f770
  edx = (u32)(edi + 273);  // @51_53f770
  ecx = (u32)(EBP - 16);  // @52_53f770
  eax = ext_441940_fastcall2(ecx, edx);  // @53_53f770
  ecx = edx = 0;  // @54_53f770
  edx = (u32)(edi + 273);  // @55_53f770
  ecx = (u32)(EBP - 28);  // @56_53f770
  eax = ext_441940_fastcall2(ecx, edx);  // @57_53f770
  ecx = edx = 0;  // @58_53f770
  edx = (u32)(edi + 273);  // @59_53f770
  ecx = (u32)(EBP - 40);  // @60_53f770
  eax = ext_441940_fastcall2(ecx, edx);  // @61_53f770
  ecx = edx = 0;  // @62_53f770
  edx = (u32)(edi + 273);  // @63_53f770
  ecx = (u32)(EBP - 64);  // @64_53f770
  eax = ext_441940_fastcall2(ecx, edx);  // @65_53f770
  ecx = edx = 0;  // @66_53f770
  STK[4] = ecx;  // @67_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @68_53f770
  eax = (u32)(EBP - 52);  // @69_53f770
  STK[4] = (u32)(1065353216);  // @70_53f770
  STK[5] = eax;  // @71_53f770
  eax = (u32)(EBP - 16);  // @72_53f770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @73_53f770
  STK[6] = eax;  // @74_53f770
  STK[7] = (u32)(1);  // @75_53f770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @76_53f770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @77_53f770
  eax = ext_545e60_thiscall5(ecx, STK[7], STK[6], STK[5], STK[4]);  // @78_53f770
  ecx = edx = 0;  // @79_53f770
  STK[8] = ecx;  // @80_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @81_53f770
  eax = (u32)(EBP - 52);  // @82_53f770
  STK[8] = (u32)(1065353216);  // @83_53f770
  STK[9] = eax;  // @84_53f770
  eax = (u32)(EBP - 28);  // @85_53f770
  STK[10] = eax;  // @86_53f770
  STK[11] = (u32)(2);  // @87_53f770
  eax = ext_545e60_thiscall5(ecx, STK[11], STK[10], STK[9], STK[8]);  // @88_53f770
  ecx = edx = 0;  // @89_53f770
  STK[12] = ecx;  // @90_53f770
  eax = (u32)(EBP - 52);  // @91_53f770
  STK[12] = (u32)(1065353216);  // @92_53f770
  STK[13] = eax;  // @93_53f770
  eax = (u32)(EBP - 40);  // @94_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @95_53f770
  STK[14] = eax;  // @96_53f770
  STK[15] = (u32)(3);  // @97_53f770
  eax = ext_545e60_thiscall5(ecx, STK[15], STK[14], STK[13], STK[12]);  // @98_53f770
  ecx = edx = 0;  // @99_53f770
  STK[16] = ecx;  // @100_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @101_53f770
  eax = (u32)(EBP - 52);  // @102_53f770
  STK[16] = (u32)(1065353216);  // @103_53f770
  STK[17] = eax;  // @104_53f770
  eax = (u32)(EBP - 64);  // @105_53f770
  STK[18] = eax;  // @106_53f770
  STK[19] = (u32)(4);  // @107_53f770
  eax = ext_545e60_thiscall5(ecx, STK[19], STK[18], STK[17], STK[16]);  // @108_53f770
  ecx = edx = 0;  // @109_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @110_53f770
  STK[20] = (u32)(1);  // @111_53f770
  STK[21] = (u32)(4);  // @112_53f770
  STK[22] = (u32)(0);  // @113_53f770
  eax = ext_545d60_thiscall4(ecx, STK[22], STK[21], STK[20]);  // @114_53f770
  ecx = edx = 0;  // @115_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @116_53f770
  STK[23] = (u32)(2);  // @117_53f770
  STK[24] = (u32)(4);  // @118_53f770
  STK[25] = (u32)(1);  // @119_53f770
  eax = ext_545d60_thiscall4(ecx, STK[25], STK[24], STK[23]);  // @120_53f770
  ecx = edx = 0;  // @121_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @122_53f770
  STK[26] = (u32)(3);  // @123_53f770
  STK[27] = (u32)(4);  // @124_53f770
  STK[28] = (u32)(2);  // @125_53f770
  eax = ext_545d60_thiscall4(ecx, STK[28], STK[27], STK[26]);  // @126_53f770
  ecx = edx = 0;  // @127_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @128_53f770
  STK[29] = (u32)(2);  // @129_53f770
  STK[30] = (u32)(1);  // @130_53f770
  STK[31] = (u32)(3);  // @131_53f770
  eax = ext_545d60_thiscall4(ecx, STK[31], STK[30], STK[29]);  // @132_53f770
  ecx = edx = 0;  // @133_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @134_53f770
  STK[32] = (u32)(3);  // @135_53f770
  STK[33] = (u32)(1);  // @136_53f770
  STK[34] = (u32)(4);  // @137_53f770
  eax = ext_545d60_thiscall4(ecx, STK[34], STK[33], STK[32]);  // @138_53f770
  ecx = edx = 0;  // @139_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @140_53f770
  STK[35] = (u32)(3);  // @141_53f770
  STK[36] = (u32)(2);  // @142_53f770
  STK[37] = (u32)(5);  // @143_53f770
  eax = ext_545d60_thiscall4(ecx, STK[37], STK[36], STK[35]);  // @144_53f770
  ecx = edx = 0;  // @145_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @146_53f770
  STK[38] = (u32)(6);  // @147_53f770
  eax = ext_5476e0_thiscall2(ecx, STK[38]);  // @148_53f770
  ecx = edx = 0;  // @149_53f770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @150_53f770
  ecx = (ecx ^ EBP);  // @151_53f770
  ext_633654(ecx);  // @152_53f770
  return eax;  // @153_53f770
}
PCREG(53f770, lifted_53f770);

