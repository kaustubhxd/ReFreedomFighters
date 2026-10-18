// batch218029.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_42adc0_fastcall2(u32, u32) __asm__("ext_42adc0");
extern "C" u32 FASTCALL ext_42ae00_fastcall3(u32, u32, u32) __asm__("ext_42ae00");
extern "C" u32 FASTCALL ext_5f1050_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5f1050");
extern "C" u32 FASTCALL ext_4309b0_fastcall3(u32, u32, u32) __asm__("ext_4309b0");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_42b290_thiscall2(u32, u32) __asm__("ext_42b290");
extern "C" u32 THISCALL ext_42b390_thiscall3(u32, u32, u32) __asm__("ext_42b390");
extern "C" u32 THISCALL ext_42ba10_thiscall1(u32) __asm__("ext_42ba10");
extern "C" u32 THISCALL ext_42bdf0_thiscall2(u32, u32) __asm__("ext_42bdf0");
extern "C" u32 THISCALL ext_42be20_thiscall2(u32, u32) __asm__("ext_42be20");
extern "C" u32 THISCALL ext_430cd0_thiscall3(u32, u32, u32) __asm__("ext_430cd0");
extern "C" u32 THISCALL ext_4311f0_thiscall2(u32, u32) __asm__("ext_4311f0");
extern "C" u32 THISCALL ext_4312f0_thiscall4(u32, u32, u32, u32) __asm__("ext_4312f0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5f2c60_thiscall3(u32, u32, u32) __asm__("ext_5f2c60");
extern "C" u32 THISCALL ext_5f2d60_thiscall3(u32, u32, u32) __asm__("ext_5f2d60");
extern "C" u32 THISCALL ext_5fb530_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5fb530");
extern "C" u32 THISCALL ext_5fd170_thiscall1(u32) __asm__("ext_5fd170");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_5f1f00(u32 a0, u32 a1) {
  SEH_ENTER(0x66cf4c);  // @h_5f1f00
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = (u32)(EBP - 13);  // @0_5f1f00
  PV[0] = (u32)(eax);  // @1_5f1f00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5f1f00
  ecx = (u32)(EBP - 32);  // @3_5f1f00
  eax = ext_42b390_thiscall3(ecx, PV[1], PV[0]);  // @4_5f1f00
  ecx = edx = 0;  // @5_5f1f00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @6_5f1f00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @7_5f1f00
  eax = (eax - edx);  // @8_5f1f00
  FL[3] = eax;  // @9_5f1f00
  reg.state = (s32)((u32)(0));  // @10_5f1f00
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @11_5f1f00
  FL[0] = eax; FL[1] = (u32)(1);  // @12_5f1f00
  if (FL[0] < FL[1]) goto L5f1f8c;  // @13_5f1f00
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_5f1f00
  eax = (eax - 1);  // @15_5f1f00
  FL[3] = eax;  // @16_5f1f00
  ecx = (u32)(EBP + 8);  // @17_5f1f00
  FL[0] = eax; FL[1] = (u32)(-1);  // @18_5f1f00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @19_5f1f00
  esi = (u32)(EBP - 20);  // @20_5f1f00
  if (FL[0] <= FL[1]) ecx = esi;  // @21_5f1f00
  PV[3] = (u32)(edx);  // @22_5f1f00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_5f1f00
  ecx = (u32)(EBP + 8);  // @24_5f1f00
  eax = (eax + 1);  // @25_5f1f00
  FL[3] = eax;  // @26_5f1f00
  eax = (eax + edx);  // @27_5f1f00
  FL[3] = eax;  // @28_5f1f00
  edx = (u32)(6795696);  // @29_5f1f00
  PV[4] = (u32)(eax);  // @30_5f1f00
  eax = ext_5f1050_fastcall6(ecx, edx, PV[4], PV[3], (u32)(6795697), PV[2]);  // @31_5f1f00
  ecx = edx = 0;  // @32_5f1f00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_5f1f00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @34_5f1f00
  FL[0] = eax; FL[1] = ecx;  // @35_5f1f00
  if (FL[0] == FL[1]) goto L5f1f8c;  // @36_5f1f00
  eax = (eax - ecx);  // @37_5f1f00
  FL[3] = eax;  // @38_5f1f00
  eax = (eax - 1);  // @39_5f1f00
  FL[3] = eax;  // @40_5f1f00
  goto L5f1f8f;  // @41_5f1f00
  L5f1f8c:;
  eax = (eax | (u32)(4294967295));  // @43_5f1f00
  FL[3] = eax;  // @44_5f1f00
  L5f1f8f:;
  PV[5] = (u32)(eax);  // @46_5f1f00
  eax = (u32)(EBP - 44);  // @47_5f1f00
  PV[6] = (u32)(eax);  // @48_5f1f00
  ecx = (u32)(EBP - 32);  // @49_5f1f00
  eax = ext_4312f0_thiscall4(ecx, PV[6], (u32)(0), PV[5]);  // @50_5f1f00
  ecx = edx = 0;  // @51_5f1f00
  ecx = (u32)(EBP - 32);  // @52_5f1f00
  reg.state = (s32)((u32)(1));  // @53_5f1f00
  FL[0] = eax; FL[1] = ecx;  // @54_5f1f00
  if (FL[0] == FL[1]) goto L5f1fb3;  // @55_5f1f00
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @56_5f1f00
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_5f1f00
  eax = ext_5f2d60_thiscall3(ecx, PV[8], PV[7]);  // @58_5f1f00
  ecx = edx = 0;  // @59_5f1f00
  L5f1fb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @61_5f1f00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @62_5f1f00
  eax = (eax - ecx);  // @63_5f1f00
  FL[3] = eax;  // @64_5f1f00
  reg.state = (s32)((u32)(2));  // @65_5f1f00
  FL[2] = (ecx & ecx);  // @66_5f1f00
  if (FL[2] == 0) goto L5f1fd1;  // @67_5f1f00
  FL[2] = (eax & eax);  // @68_5f1f00
  if (FL[2] == 0) goto L5f1fd1;  // @69_5f1f00
  PV[9] = (u32)(eax);  // @70_5f1f00
  PV[10] = (u32)(ecx);  // @71_5f1f00
  ecx = (u32)(EBP - 44);  // @72_5f1f00
  eax = ext_54f870_stdcall2(PV[10], PV[9]);  // @73_5f1f00
  ecx = edx = 0;  // @74_5f1f00
  L5f1fd1:;
  ecx = (u32)(EBP - 32);  // @76_5f1f00
  reg.state = (s32)((u32)(0));  // @77_5f1f00
  eax = ext_5f2c60_thiscall3(ecx, (u32)(7047180), (u32)(7047184));  // @78_5f1f00
  ecx = edx = 0;  // @79_5f1f00
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @80_5f1f00
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7422904), &v, sizeof v); }  // @81_5f1f00
  eax = ((u32( *)(u32, u32))(*(u32 *)0x6763b0))(PV[11], (u32)(6786252));  // @82_5f1f00
  ecx = edx = 0;  // @83_5f1f00
  ebx = eax;  // @84_5f1f00
  FL[2] = (ebx & ebx);  // @85_5f1f00
  if (FL[2] == 0) goto L5f2088;  // @86_5f1f00
  PV[12] = (u32)(ebx);  // @87_5f1f00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[12], (u32)(0), (u32)(2));  // @88_5f1f00
  ecx = edx = 0;  // @89_5f1f00
  PV[13] = (u32)(ebx);  // @90_5f1f00
  eax = ((u32( *)(u32))(*(u32 *)0x6763f4))(PV[13]);  // @91_5f1f00
  ecx = edx = 0;  // @92_5f1f00
  esi = eax;  // @93_5f1f00
  PV[14] = (u32)(esi);  // @94_5f1f00
  eax = ext_41e290_cdecl1(PV[14]);  // @95_5f1f00
  ecx = edx = 0;  // @96_5f1f00
  PV[15] = (u32)(ebx);  // @97_5f1f00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @98_5f1f00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)0x6763e8))(PV[15], (u32)(0), (u32)(0));  // @99_5f1f00
  ecx = edx = 0;  // @100_5f1f00
  PV[16] = (u32)(ebx);  // @101_5f1f00
  PV[17] = (u32)(esi);  // @102_5f1f00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @103_5f1f00
  PV[18] = (u32)(esi);  // @104_5f1f00
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)0x6763f8))(PV[18], (u32)(1), PV[17], PV[16]);  // @105_5f1f00
  ecx = edx = 0;  // @106_5f1f00
  PV[19] = (u32)(ebx);  // @107_5f1f00
  eax = ((u32( *)(u32))(*(u32 *)0x6763ac))(PV[19]);  // @108_5f1f00
  ecx = edx = 0;  // @109_5f1f00
  ecx = esi;  // @110_5f1f00
  edx = (u32)(ecx + 1);  // @111_5f1f00
  L5f2050:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @113_5f1f00
  ecx = (ecx + 1);  // @114_5f1f00
  FL[3] = ecx;  // @115_5f1f00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @116_5f1f00
  if (FL[2] != 0) goto L5f2050;  // @117_5f1f00
  ecx = (ecx - edx);  // @118_5f1f00
  FL[3] = ecx;  // @119_5f1f00
  FL[0] = ecx; FL[1] = (u32)(65000);  // @120_5f1f00
  if (FL[0] < FL[1]) goto L5f2062;  // @121_5f1f00
  __builtin_trap();  // @122_5f1f00
  L5f2062:;
  edx = (u32)(7422904);  // @124_5f1f00
  ecx = esi;  // @125_5f1f00
  edx = (edx - esi);  // @126_5f1f00
  FL[3] = edx;  // @127_5f1f00
  L5f2070:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @129_5f1f00
  ecx = (u32)(ecx + 1);  // @130_5f1f00
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @131_5f1f00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @132_5f1f00
  if (FL[2] != 0) goto L5f2070;  // @133_5f1f00
  PV[20] = (u32)(esi);  // @134_5f1f00
  eax = ext_634273_cdecl2(PV[20], (u32)(1));  // @135_5f1f00
  ecx = edx = 0;  // @136_5f1f00
  L5f2088:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @138_5f1f00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @139_5f1f00
  eax = (eax - ecx);  // @140_5f1f00
  FL[3] = eax;  // @141_5f1f00
  reg.state = (s32)((u32)(3));  // @142_5f1f00
  FL[2] = (ecx & ecx);  // @143_5f1f00
  if (FL[2] == 0) goto L5f20a9;  // @144_5f1f00
  FL[2] = (eax & eax);  // @145_5f1f00
  if (FL[2] == 0) goto L5f20a9;  // @146_5f1f00
  PV[21] = (u32)(eax);  // @147_5f1f00
  PV[22] = (u32)(ecx);  // @148_5f1f00
  ecx = (u32)(EBP - 32);  // @149_5f1f00
  eax = ext_54f870_stdcall2(PV[22], PV[21]);  // @150_5f1f00
  ecx = edx = 0;  // @151_5f1f00
  L5f20a9:;
  eax = (u32)(7422904);  // @153_5f1f00
  SEH_LEAVE();  // @154_5f1f00
  return eax;  // @155_5f1f00
}
PCREG(5f1f00, lifted_5f1f00);

extern "C" u32 THISCALL lifted_5f1c20(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66cf07);  // @h_5f1c20
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_5f1c20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5f1c20
  eax = (u32)(EBP - 13);  // @2_5f1c20
  PV[0] = (u32)(eax);  // @3_5f1c20
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_5f1c20
  ecx = (u32)(EBP - 40);  // @5_5f1c20
  eax = ext_42b390_thiscall3(ecx, PV[1], PV[0]);  // @6_5f1c20
  ecx = edx = 0;  // @7_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @8_5f1c20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @9_5f1c20
  eax = (eax - edx);  // @10_5f1c20
  FL[3] = eax;  // @11_5f1c20
  reg.state = (s32)((u32)(0));  // @12_5f1c20
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @13_5f1c20
  FL[0] = eax; FL[1] = (u32)(1);  // @14_5f1c20
  if (FL[0] < FL[1]) goto L5f1cb7;  // @15_5f1c20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @16_5f1c20
  eax = (eax - 1);  // @17_5f1c20
  FL[3] = eax;  // @18_5f1c20
  ecx = (u32)(EBP + 8);  // @19_5f1c20
  FL[0] = eax; FL[1] = (u32)(-1);  // @20_5f1c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @21_5f1c20
  esi = (u32)(EBP - 20);  // @22_5f1c20
  if (FL[0] <= FL[1]) ecx = esi;  // @23_5f1c20
  PV[3] = (u32)(edx);  // @24_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_5f1c20
  ecx = (u32)(EBP + 8);  // @26_5f1c20
  eax = (eax + 1);  // @27_5f1c20
  FL[3] = eax;  // @28_5f1c20
  eax = (eax + edx);  // @29_5f1c20
  FL[3] = eax;  // @30_5f1c20
  edx = (u32)(6795696);  // @31_5f1c20
  PV[4] = (u32)(eax);  // @32_5f1c20
  eax = ext_5f1050_fastcall6(ecx, edx, PV[4], PV[3], (u32)(6795697), PV[2]);  // @33_5f1c20
  ecx = edx = 0;  // @34_5f1c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @35_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @36_5f1c20
  FL[0] = esi; FL[1] = eax;  // @37_5f1c20
  if (FL[0] == FL[1]) goto L5f1cb7;  // @38_5f1c20
  esi = (esi - eax);  // @39_5f1c20
  FL[3] = esi;  // @40_5f1c20
  esi = (esi - 1);  // @41_5f1c20
  FL[3] = esi;  // @42_5f1c20
  FL[0] = esi; FL[1] = (u32)(-1);  // @43_5f1c20
  if (FL[0] != FL[1]) goto L5f1cc8;  // @44_5f1c20
  goto L5f1cba;  // @45_5f1c20
  L5f1cb7:;
  esi = (esi | (u32)(4294967295));  // @47_5f1c20
  FL[3] = esi;  // @48_5f1c20
  L5f1cba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @50_5f1c20
  FL[2] = (eax & eax);  // @51_5f1c20
  if (FL[2] == 0) goto L5f1cc7;  // @52_5f1c20
  eax = ((u32(STDCALL *)(void))(eax))();  // @53_5f1c20
  ecx = edx = 0;  // @54_5f1c20
  goto L5f1cc8;  // @55_5f1c20
  L5f1cc7:;
  __builtin_trap();  // @57_5f1c20
  L5f1cc8:;
  PV[5] = (u32)(esi);  // @59_5f1c20
  eax = (u32)(EBP - 64);  // @60_5f1c20
  PV[6] = (u32)(eax);  // @61_5f1c20
  ecx = (u32)(EBP - 40);  // @62_5f1c20
  eax = ext_4312f0_thiscall4(ecx, PV[6], (u32)(0), PV[5]);  // @63_5f1c20
  ecx = edx = 0;  // @64_5f1c20
  edx = eax;  // @65_5f1c20
  reg.state = (s32)((u32)(1));  // @66_5f1c20
  ecx = (u32)(EBP - 52);  // @67_5f1c20
  eax = ext_42ae00_fastcall3(ecx, edx, (u32)(7047180));  // @68_5f1c20
  ecx = edx = 0;  // @69_5f1c20
  ecx = (u32)(EBP - 40);  // @70_5f1c20
  reg.state = (s32)((u32)(2));  // @71_5f1c20
  FL[0] = eax; FL[1] = ecx;  // @72_5f1c20
  if (FL[0] == FL[1]) goto L5f1cff;  // @73_5f1c20
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @74_5f1c20
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_5f1c20
  eax = ext_5f2d60_thiscall3(ecx, PV[8], PV[7]);  // @76_5f1c20
  ecx = edx = 0;  // @77_5f1c20
  L5f1cff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @79_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @80_5f1c20
  eax = (eax - ecx);  // @81_5f1c20
  FL[3] = eax;  // @82_5f1c20
  reg.state = (s32)((u32)(3));  // @83_5f1c20
  FL[2] = (ecx & ecx);  // @84_5f1c20
  if (FL[2] == 0) goto L5f1d1d;  // @85_5f1c20
  FL[2] = (eax & eax);  // @86_5f1c20
  if (FL[2] == 0) goto L5f1d1d;  // @87_5f1c20
  PV[9] = (u32)(eax);  // @88_5f1c20
  PV[10] = (u32)(ecx);  // @89_5f1c20
  ecx = (u32)(EBP - 52);  // @90_5f1c20
  eax = ext_54f870_stdcall2(PV[10], PV[9]);  // @91_5f1c20
  ecx = edx = 0;  // @92_5f1c20
  L5f1d1d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @94_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @95_5f1c20
  eax = (eax - ecx);  // @96_5f1c20
  FL[3] = eax;  // @97_5f1c20
  reg.state = (s32)((u32)(4));  // @98_5f1c20
  FL[2] = (ecx & ecx);  // @99_5f1c20
  if (FL[2] == 0) goto L5f1d3b;  // @100_5f1c20
  FL[2] = (eax & eax);  // @101_5f1c20
  if (FL[2] == 0) goto L5f1d3b;  // @102_5f1c20
  PV[11] = (u32)(eax);  // @103_5f1c20
  PV[12] = (u32)(ecx);  // @104_5f1c20
  ecx = (u32)(EBP - 64);  // @105_5f1c20
  eax = ext_54f870_stdcall2(PV[12], PV[11]);  // @106_5f1c20
  ecx = edx = 0;  // @107_5f1c20
  L5f1d3b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @109_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @110_5f1c20
  PV[13] = (u32)(ebx);  // @111_5f1c20
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @112_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @113_5f1c20
  reg.state = (s32)((u32)(0));  // @114_5f1c20
  eax = ext_5fb530_thiscall5(ecx, PV[14], (u32)(0), (u32)(1), PV[13]);  // @115_5f1c20
  ecx = edx = 0;  // @116_5f1c20
  FL[2] = (eax & eax);  // @117_5f1c20
  if (FL[2] == 0) goto L5f1ea0;  // @118_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_5f1c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @120_5f1c20
  FL[0] = esi; FL[1] = eax;  // @121_5f1c20
  if (FL[0] == FL[1]) goto L5f1e51;  // @122_5f1c20
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @123_5f1c20
  L5f1d70:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @125_5f1c20
  ebx = (u32)(esi + 8);  // @126_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @127_5f1c20
  ecx = (ecx - eax);  // @128_5f1c20
  FL[3] = ecx;  // @129_5f1c20
  FL[0] = ecx; FL[1] = (u32)(1);  // @130_5f1c20
  if (FL[0] < FL[1]) goto L5f1dbe;  // @131_5f1c20
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @132_5f1c20
  ecx = (ecx - 1);  // @133_5f1c20
  FL[3] = ecx;  // @134_5f1c20
  edx = (u32)(EBP + 8);  // @135_5f1c20
  FL[0] = ecx; FL[1] = (u32)(-1);  // @136_5f1c20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @137_5f1c20
  edi = (u32)(EBP - 20);  // @138_5f1c20
  if (FL[0] <= FL[1]) edx = edi;  // @139_5f1c20
  PV[16] = (u32)(eax);  // @140_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @141_5f1c20
  edx = (u32)(6795696);  // @142_5f1c20
  ecx = (ecx + 1);  // @143_5f1c20
  FL[3] = ecx;  // @144_5f1c20
  ecx = (ecx + eax);  // @145_5f1c20
  FL[3] = ecx;  // @146_5f1c20
  PV[17] = (u32)(ecx);  // @147_5f1c20
  ecx = (u32)(EBP - 24);  // @148_5f1c20
  eax = ext_5f1050_fastcall6(ecx, edx, PV[17], PV[16], (u32)(6795697), PV[15]);  // @149_5f1c20
  ecx = edx = 0;  // @150_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @151_5f1c20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @152_5f1c20
  FL[0] = edi; FL[1] = eax;  // @153_5f1c20
  if (FL[0] == FL[1]) goto L5f1dbe;  // @154_5f1c20
  edi = (edi - eax);  // @155_5f1c20
  FL[3] = edi;  // @156_5f1c20
  edi = (edi - 1);  // @157_5f1c20
  FL[3] = edi;  // @158_5f1c20
  FL[0] = edi; FL[1] = (u32)(-1);  // @159_5f1c20
  if (FL[0] != FL[1]) goto L5f1dcf;  // @160_5f1c20
  goto L5f1dc1;  // @161_5f1c20
  L5f1dbe:;
  edi = (edi | (u32)(4294967295));  // @163_5f1c20
  FL[3] = edi;  // @164_5f1c20
  L5f1dc1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @166_5f1c20
  FL[2] = (eax & eax);  // @167_5f1c20
  if (FL[2] == 0) goto L5f1dce;  // @168_5f1c20
  eax = ((u32(STDCALL *)(void))(eax))();  // @169_5f1c20
  ecx = edx = 0;  // @170_5f1c20
  goto L5f1dcf;  // @171_5f1c20
  L5f1dce:;
  __builtin_trap();  // @173_5f1c20
  L5f1dcf:;
  PV[18] = (u32)(edi);  // @175_5f1c20
  eax = (u32)(EBP - 52);  // @176_5f1c20
  ecx = ebx;  // @177_5f1c20
  PV[19] = (u32)(eax);  // @178_5f1c20
  eax = ext_4312f0_thiscall4(ecx, PV[19], (u32)(0), PV[18]);  // @179_5f1c20
  ecx = edx = 0;  // @180_5f1c20
  edx = eax;  // @181_5f1c20
  reg.state = (s32)((u32)(5));  // @182_5f1c20
  ecx = (u32)(EBP - 64);  // @183_5f1c20
  eax = ext_42ae00_fastcall3(ecx, edx, (u32)(7047180));  // @184_5f1c20
  ecx = edx = 0;  // @185_5f1c20
  reg.state = (s32)((u32)(6));  // @186_5f1c20
  FL[0] = eax; FL[1] = ebx;  // @187_5f1c20
  if (FL[0] == FL[1]) goto L5f1e04;  // @188_5f1c20
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @189_5f1c20
  ecx = ebx;  // @190_5f1c20
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @191_5f1c20
  eax = ext_5f2d60_thiscall3(ecx, PV[21], PV[20]);  // @192_5f1c20
  ecx = edx = 0;  // @193_5f1c20
  L5f1e04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; });  // @195_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 64), sizeof v); (u32)v; });  // @196_5f1c20
  eax = (eax - ecx);  // @197_5f1c20
  FL[3] = eax;  // @198_5f1c20
  reg.state = (s32)((u32)(7));  // @199_5f1c20
  FL[2] = (ecx & ecx);  // @200_5f1c20
  if (FL[2] == 0) goto L5f1e22;  // @201_5f1c20
  FL[2] = (eax & eax);  // @202_5f1c20
  if (FL[2] == 0) goto L5f1e22;  // @203_5f1c20
  PV[22] = (u32)(eax);  // @204_5f1c20
  PV[23] = (u32)(ecx);  // @205_5f1c20
  ecx = (u32)(EBP - 64);  // @206_5f1c20
  eax = ext_54f870_stdcall2(PV[23], PV[22]);  // @207_5f1c20
  ecx = edx = 0;  // @208_5f1c20
  L5f1e22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @210_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @211_5f1c20
  eax = (eax - ecx);  // @212_5f1c20
  FL[3] = eax;  // @213_5f1c20
  reg.state = (s32)((u32)(8));  // @214_5f1c20
  FL[2] = (ecx & ecx);  // @215_5f1c20
  if (FL[2] == 0) goto L5f1e40;  // @216_5f1c20
  FL[2] = (eax & eax);  // @217_5f1c20
  if (FL[2] == 0) goto L5f1e40;  // @218_5f1c20
  PV[24] = (u32)(eax);  // @219_5f1c20
  PV[25] = (u32)(ecx);  // @220_5f1c20
  ecx = (u32)(EBP - 52);  // @221_5f1c20
  eax = ext_54f870_stdcall2(PV[25], PV[24]);  // @222_5f1c20
  ecx = edx = 0;  // @223_5f1c20
  L5f1e40:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @225_5f1c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @226_5f1c20
  reg.state = (s32)((u32)(0));  // @227_5f1c20
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @228_5f1c20
  if (FL[0] != FL[1]) goto L5f1d70;  // @229_5f1c20
  L5f1e51:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @231_5f1c20
  ecx = ebx;  // @232_5f1c20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @233_5f1c20
  eax = ext_6014a0_stdcall1((u32)(20));  // @234_5f1c20
  ecx = edx = 0;  // @235_5f1c20
  edi = eax;  // @236_5f1c20
  ecx = (u32)(edi + 8);  // @237_5f1c20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @238_5f1c20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @239_5f1c20
  reg.state = (s32)((u32)(9));  // @240_5f1c20
  FL[2] = (ecx & ecx);  // @241_5f1c20
  if (FL[2] == 0) goto L5f1e7a;  // @242_5f1c20
  eax = (u32)(EBP - 40);  // @243_5f1c20
  PV[26] = (u32)(eax);  // @244_5f1c20
  eax = ext_5f10c0_thiscall2(ecx, PV[26]);  // @245_5f1c20
  ecx = edx = 0;  // @246_5f1c20
  L5f1e7a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @248_5f1c20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @249_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @250_5f1c20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @251_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @252_5f1c20
  reg.state = (s32)((u32)(0));  // @253_5f1c20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @254_5f1c20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @255_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @256_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @257_5f1c20
  eax = ext_5fd170_thiscall1(ecx);  // @258_5f1c20
  ecx = edx = 0;  // @259_5f1c20
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @260_5f1c20
  goto L5f1ebb;  // @261_5f1c20
  L5f1ea0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @263_5f1c20
  FL[2] = (eax & eax);  // @264_5f1c20
  if (FL[2] == 0) goto L5f1ead;  // @265_5f1c20
  eax = ((u32(STDCALL *)(void))(eax))();  // @266_5f1c20
  ecx = edx = 0;  // @267_5f1c20
  goto L5f1eae;  // @268_5f1c20
  L5f1ead:;
  __builtin_trap();  // @270_5f1c20
  L5f1eae:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @272_5f1c20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @273_5f1c20
  eax = ext_5fd170_thiscall1(ecx);  // @274_5f1c20
  ecx = edx = 0;  // @275_5f1c20
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @276_5f1c20
  FL[3] = (ebx & 0xff);  // @277_5f1c20
  L5f1ebb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @279_5f1c20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @280_5f1c20
  ecx = (ecx - eax);  // @281_5f1c20
  FL[3] = ecx;  // @282_5f1c20
  reg.state = (s32)((u32)(10));  // @283_5f1c20
  FL[2] = (eax & eax);  // @284_5f1c20
  if (FL[2] == 0) goto L5f1edc;  // @285_5f1c20
  FL[2] = (ecx & ecx);  // @286_5f1c20
  if (FL[2] == 0) goto L5f1edc;  // @287_5f1c20
  PV[27] = (u32)(ecx);  // @288_5f1c20
  PV[28] = (u32)(eax);  // @289_5f1c20
  ecx = (u32)(EBP - 40);  // @290_5f1c20
  eax = ext_54f870_stdcall2(PV[28], PV[27]);  // @291_5f1c20
  ecx = edx = 0;  // @292_5f1c20
  L5f1edc:;
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @294_5f1c20
  SEH_LEAVE();  // @295_5f1c20
  return eax;  // @296_5f1c20
}
PCREG(5f1c20, lifted_5f1c20);

extern "C" u32 THISCALL lifted_42f320(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66519e);  // @h_42f320
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_42f320
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42f320
  ecx = (u32)(EBP - 156);  // @2_42f320
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @3_42f320
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @4_42f320
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @5_42f320
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @6_42f320
  eax = ext_6014a0_stdcall1((u32)(8));  // @7_42f320
  ecx = edx = 0;  // @8_42f320
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @9_42f320
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @10_42f320
  ecx = (u32)(eax + 8);  // @11_42f320
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @12_42f320
  FL[2] = (eax & eax);  // @13_42f320
  if (FL[2] == 0) goto L42f3a0;  // @14_42f320
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @15_42f320
  L42f3a0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @17_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_42f320
  ecx = (u32)(EBP - 156);  // @19_42f320
  PV[0] = (u32)(ecx);  // @20_42f320
  PV[1] = (u32)(ebx);  // @21_42f320
  ecx = edi;  // @22_42f320
  reg.state = (s32)((u32)(0));  // @23_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[1], PV[0]);  // @24_42f320
  ecx = edx = 0;  // @25_42f320
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @26_42f320
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @27_42f320
  FL[0] = esi; FL[1] = ebx;  // @28_42f320
  if (FL[0] == FL[1]) goto L42f68f;  // @29_42f320
  ebx = (ebx - esi);  // @30_42f320
  FL[3] = ebx;  // @31_42f320
  FL[0] = ebx; FL[1] = (u32)(2);  // @32_42f320
  if (FL[0] != FL[1]) goto L42f410;  // @33_42f320
  PV[2] = (u32)(ebx);  // @34_42f320
  edx = (u32)(6790724);  // @35_42f320
  ecx = esi;  // @36_42f320
  eax = ext_4309b0_fastcall3(ecx, edx, PV[2]);  // @37_42f320
  ecx = edx = 0;  // @38_42f320
  FL[2] = (eax & eax);  // @39_42f320
  if (FL[2] != 0) goto L42f410;  // @40_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_42f320
  ecx = (u32)(EBP - 156);  // @42_42f320
  PV[3] = (u32)(ecx);  // @43_42f320
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @44_42f320
  ecx = edi;  // @45_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[4], PV[3]);  // @46_42f320
  ecx = edx = 0;  // @47_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7017), sizeof v); (u32)v; });  // @48_42f320
  eax = (u32)(EBP - 156);  // @49_42f320
  PV[5] = (u32)(eax);  // @50_42f320
  eax = ext_4311f0_thiscall2(ecx, PV[5]);  // @51_42f320
  ecx = edx = 0;  // @52_42f320
  goto L42f689;  // @53_42f320
  L42f410:;
  FL[0] = ebx; FL[1] = (u32)(8);  // @55_42f320
  if (FL[0] != FL[1]) goto L42f42a;  // @56_42f320
  PV[6] = (u32)(ebx);  // @57_42f320
  edx = (u32)(6790472);  // @58_42f320
  ecx = esi;  // @59_42f320
  eax = ext_4309b0_fastcall3(ecx, edx, PV[6]);  // @60_42f320
  ecx = edx = 0;  // @61_42f320
  FL[2] = (eax & eax);  // @62_42f320
  if (FL[2] == 0) goto L42f68f;  // @63_42f320
  L42f42a:;
  FL[0] = ebx; FL[1] = (u32)(2);  // @65_42f320
  if (FL[0] != FL[1]) goto L42f48b;  // @66_42f320
  PV[7] = (u32)(ebx);  // @67_42f320
  edx = (u32)(6790728);  // @68_42f320
  ecx = esi;  // @69_42f320
  eax = ext_4309b0_fastcall3(ecx, edx, PV[7]);  // @70_42f320
  ecx = edx = 0;  // @71_42f320
  FL[2] = (eax & eax);  // @72_42f320
  if (FL[2] != 0) goto L42f48b;  // @73_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_42f320
  ecx = (u32)(EBP - 156);  // @75_42f320
  PV[8] = (u32)(ecx);  // @76_42f320
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @77_42f320
  ecx = edi;  // @78_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[9], PV[8]);  // @79_42f320
  ecx = edx = 0;  // @80_42f320
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @81_42f320
  ecx = (u32)(EBP - 144);  // @82_42f320
  eax = ext_4cbe80_thiscall2(ecx, PV[10]);  // @83_42f320
  ecx = edx = 0;  // @84_42f320
  eax = (u32)(EBP - 144);  // @85_42f320
  reg.state = (s32)((u32)(1));  // @86_42f320
  PV[11] = (u32)(eax);  // @87_42f320
  ecx = (u32)(edi + 6679);  // @88_42f320
  eax = ext_4cbee0_thiscall2(ecx, PV[11]);  // @89_42f320
  ecx = edx = 0;  // @90_42f320
  ecx = (u32)(EBP - 144);  // @91_42f320
  eax = ext_4cbec0_thiscall1(ecx);  // @92_42f320
  ecx = edx = 0;  // @93_42f320
  goto L42f689;  // @94_42f320
  L42f48b:;
  edx = (u32)(6790732);  // @96_42f320
  ecx = (u32)(EBP - 156);  // @97_42f320
  eax = ext_42adc0_fastcall2(ecx, edx);  // @98_42f320
  ecx = edx = 0;  // @99_42f320
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @100_42f320
  if (FL[2] != 0) goto L42f543;  // @101_42f320
  edx = (u32)(6790736);  // @102_42f320
  ecx = (u32)(EBP - 156);  // @103_42f320
  eax = ext_42adc0_fastcall2(ecx, edx);  // @104_42f320
  ecx = edx = 0;  // @105_42f320
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @106_42f320
  if (FL[2] != 0) goto L42f543;  // @107_42f320
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }); FL[1] = (u32)(64);  // @108_42f320
  if (FL[0] != FL[1]) goto L42f515;  // @109_42f320
  eax = (u32)(ebx - 1);  // @110_42f320
  PV[12] = (u32)(eax);  // @111_42f320
  eax = (u32)(EBP - 188);  // @112_42f320
  PV[13] = (u32)(eax);  // @113_42f320
  ecx = (u32)(EBP - 156);  // @114_42f320
  eax = ext_4312f0_thiscall4(ecx, PV[13], (u32)(1), PV[12]);  // @115_42f320
  ecx = edx = 0;  // @116_42f320
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @117_42f320
  ecx = (u32)(EBP - 144);  // @118_42f320
  reg.state = (s32)((u32)(6));  // @119_42f320
  eax = ext_4cbe80_thiscall2(ecx, PV[14]);  // @120_42f320
  ecx = edx = 0;  // @121_42f320
  eax = (u32)(EBP - 144);  // @122_42f320
  reg.state = (s32)((u32)(7));  // @123_42f320
  PV[15] = (u32)(eax);  // @124_42f320
  ecx = (u32)(edi + 6679);  // @125_42f320
  eax = ext_4cbee0_thiscall2(ecx, PV[15]);  // @126_42f320
  ecx = edx = 0;  // @127_42f320
  ecx = (u32)(EBP - 144);  // @128_42f320
  eax = ext_4cbec0_thiscall1(ecx);  // @129_42f320
  ecx = edx = 0;  // @130_42f320
  ecx = (u32)(EBP - 188);  // @131_42f320
  goto L42f684;  // @132_42f320
  L42f515:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @134_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6789548), (u32)(1091));  // @136_42f320
  ecx = edx = 0;  // @137_42f320
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @138_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @139_42f320
  PV[17] = (u32)(eax);  // @140_42f320
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[17], (u32)(6790744), PV[16]);  // @141_42f320
  ecx = edx = 0;  // @142_42f320
  goto L42f689;  // @143_42f320
  L42f543:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @145_42f320
  ecx = (u32)(EBP - 156);  // @146_42f320
  PV[18] = (u32)(ecx);  // @147_42f320
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @148_42f320
  ecx = edi;  // @149_42f320
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 120)))(ecx, PV[19], PV[18]);  // @150_42f320
  ecx = edx = 0;  // @151_42f320
  ecx = (u32)(EBP - 156);  // @152_42f320
  eax = ext_430cd0_thiscall3(ecx, (u32)(61), (u32)(0));  // @153_42f320
  ecx = edx = 0;  // @154_42f320
  esi = eax;  // @155_42f320
  FL[0] = esi; FL[1] = (u32)(-1);  // @156_42f320
  if (FL[0] != FL[1]) goto L42f590;  // @157_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @158_42f320
  eax = (u32)(EBP - 156);  // @159_42f320
  PV[20] = (u32)(eax);  // @160_42f320
  eax = ext_42be20_thiscall2(ecx, PV[20]);  // @161_42f320
  ecx = edx = 0;  // @162_42f320
  ecx = eax;  // @163_42f320
  eax = ext_42bdf0_thiscall2(ecx, (u32)(6790740));  // @164_42f320
  ecx = edx = 0;  // @165_42f320
  goto L42f689;  // @166_42f320
  L42f590:;
  eax = (u32)(EBP - 157);  // @168_42f320
  PV[21] = (u32)(eax);  // @169_42f320
  ecx = (u32)(EBP - 200);  // @170_42f320
  eax = ext_42b290_thiscall2(ecx, PV[21]);  // @171_42f320
  ecx = edx = 0;  // @172_42f320
  eax = (u32)(EBP - 157);  // @173_42f320
  reg.state = (s32)((u32)(2));  // @174_42f320
  PV[22] = (u32)(eax);  // @175_42f320
  ecx = (u32)(EBP - 176);  // @176_42f320
  eax = ext_42b290_thiscall2(ecx, PV[22]);  // @177_42f320
  ecx = edx = 0;  // @178_42f320
  PV[23] = (u32)(esi);  // @179_42f320
  eax = (u32)(EBP - 188);  // @180_42f320
  reg.state = (s32)((u32)(3));  // @181_42f320
  PV[24] = (u32)(eax);  // @182_42f320
  ecx = (u32)(EBP - 156);  // @183_42f320
  eax = ext_4312f0_thiscall4(ecx, PV[24], (u32)(0), PV[23]);  // @184_42f320
  ecx = edx = 0;  // @185_42f320
  ecx = (u32)(EBP - 200);  // @186_42f320
  reg.state = (s32)((u32)(4));  // @187_42f320
  FL[0] = eax; FL[1] = ecx;  // @188_42f320
  if (FL[0] == FL[1]) goto L42f5e9;  // @189_42f320
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @190_42f320
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @191_42f320
  eax = ext_5f2d60_thiscall3(ecx, PV[26], PV[25]);  // @192_42f320
  ecx = edx = 0;  // @193_42f320
  L42f5e9:;
  ecx = (u32)(EBP - 188);  // @195_42f320
  reg.state = (s32)((u32)(3));  // @196_42f320
  eax = ext_42ba10_thiscall1(ecx);  // @197_42f320
  ecx = edx = 0;  // @198_42f320
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @199_42f320
  ecx = (u32)(EBP - 156);  // @200_42f320
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; }));  // @201_42f320
  FL[3] = eax;  // @202_42f320
  eax = (eax - esi);  // @203_42f320
  FL[3] = eax;  // @204_42f320
  PV[27] = (u32)(eax);  // @205_42f320
  eax = (u32)(esi + 1);  // @206_42f320
  PV[28] = (u32)(eax);  // @207_42f320
  eax = (u32)(EBP - 188);  // @208_42f320
  PV[29] = (u32)(eax);  // @209_42f320
  eax = ext_4312f0_thiscall4(ecx, PV[29], PV[28], PV[27]);  // @210_42f320
  ecx = edx = 0;  // @211_42f320
  ecx = (u32)(EBP - 176);  // @212_42f320
  reg.state = (s32)((u32)(5));  // @213_42f320
  FL[0] = eax; FL[1] = ecx;  // @214_42f320
  if (FL[0] == FL[1]) goto L42f635;  // @215_42f320
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @216_42f320
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @217_42f320
  eax = ext_5f2d60_thiscall3(ecx, PV[31], PV[30]);  // @218_42f320
  ecx = edx = 0;  // @219_42f320
  L42f635:;
  ecx = (u32)(EBP - 188);  // @221_42f320
  reg.state = (s32)((u32)(3));  // @222_42f320
  eax = ext_42ba10_thiscall1(ecx);  // @223_42f320
  ecx = edx = 0;  // @224_42f320
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7013), sizeof v); (u32)v; });  // @225_42f320
  eax = (u32)(EBP - 200);  // @226_42f320
  PV[32] = (u32)(eax);  // @227_42f320
  eax = ext_42be20_thiscall2(ecx, PV[32]);  // @228_42f320
  ecx = edx = 0;  // @229_42f320
  ecx = (u32)(EBP - 176);  // @230_42f320
  FL[0] = ecx; FL[1] = eax;  // @231_42f320
  if (FL[0] == FL[1]) goto L42f673;  // @232_42f320
  PV[33] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @233_42f320
  ecx = eax;  // @234_42f320
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @235_42f320
  eax = ext_5f2d60_thiscall3(ecx, PV[34], PV[33]);  // @236_42f320
  ecx = edx = 0;  // @237_42f320
  L42f673:;
  ecx = (u32)(EBP - 176);  // @239_42f320
  eax = ext_42ba10_thiscall1(ecx);  // @240_42f320
  ecx = edx = 0;  // @241_42f320
  ecx = (u32)(EBP - 200);  // @242_42f320
  L42f684:;
  eax = ext_42ba10_thiscall1(ecx);  // @244_42f320
  ecx = edx = 0;  // @245_42f320
  L42f689:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @247_42f320
  L42f68f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @249_42f320
  eax = (eax - esi);  // @250_42f320
  FL[3] = eax;  // @251_42f320
  reg.state = (s32)((u32)(8));  // @252_42f320
  FL[2] = (esi & esi);  // @253_42f320
  if (FL[2] == 0) goto L42f6b3;  // @254_42f320
  FL[2] = (eax & eax);  // @255_42f320
  if (FL[2] == 0) goto L42f6b3;  // @256_42f320
  PV[35] = (u32)(eax);  // @257_42f320
  PV[36] = (u32)(esi);  // @258_42f320
  ecx = (u32)(EBP - 156);  // @259_42f320
  eax = ext_54f870_stdcall2(PV[36], PV[35]);  // @260_42f320
  ecx = edx = 0;  // @261_42f320
  L42f6b3:;
  SEH_LEAVE();  // @263_42f320
  ext_633654(G(u32, 0x6f5630));  // @264_42f320
  return eax;  // @265_42f320
}
PCREG(42f320, lifted_42f320);

